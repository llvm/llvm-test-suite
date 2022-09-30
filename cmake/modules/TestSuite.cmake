##===- TestSuite.cmake ----------------------------------------------------===##
#
# Defines helper functions to build benchmarks and the corresponding .test files
#
##===----------------------------------------------------------------------===##
include(TestFile)
include(CopyDir)

set(_DEFAULT_TEST_SUITE_COPY_DATA OFF)
if(TEST_SUITE_REMOTE_HOST)
  set(_DEFAULT_TEST_SUITE_COPY_DATA ON)
endif()
option(TEST_SUITE_COPY_DATA "Always copy benchmark data to builddir"
       ${_DEFAULT_TEST_SUITE_COPY_DATA})
mark_as_advanced(TEST_SUITE_COPY_DATA)

# Copies files and directories to be used as benchmark input data to the
# directory of the benchmark executable.
# Paths are interepreted relative to CMAKE_CURRENT_SOURCE_DIR by default but
# this can be changed with the SOURCE_DIR argument.
# If DEST_SUFFIX is specified, it's appended to the destination file names.
function(llvm_test_data target)
  cmake_parse_arguments(_LTDARGS "MUST_COPY" "SOURCE_DIR;DEST_SUFFIX" "" ${ARGN})
  set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  if(_LTDARGS_SOURCE_DIR)
    set(SOURCE_DIR ${_LTDARGS_SOURCE_DIR})
  endif()
  set(SUFFIX ${_LTDARGS_DEST_SUFFIX})
  foreach(file ${_LTDARGS_UNPARSED_ARGUMENTS})
    set(full_path ${SOURCE_DIR}/${file})
    if(_LTDARGS_MUST_COPY OR TEST_SUITE_COPY_DATA)
      if(IS_DIRECTORY ${full_path})
        llvm_copy_dir(${target} $<TARGET_FILE_DIR:${target}>/${file}${SUFFIX} ${full_path})
      else()
        llvm_copy(${target} $<TARGET_FILE_DIR:${target}>/${file}${SUFFIX} ${full_path})
      endif()
    else()
      get_filename_component(file_subdir ${file} DIRECTORY)
      if(file_subdir)
        llvm_make_directory(${target} ${file_subdir})
      endif()
      llvm_create_symlink(${target} $<TARGET_FILE_DIR:${target}>/${file}${SUFFIX} ${full_path})
    endif()
  endforeach()
endfunction()

function(llvm_test_executable_no_test target)
  add_executable(${target} ${ARGN})
  append_target_flags(COMPILE_FLAGS ${target} ${CFLAGS})
  append_target_flags(COMPILE_FLAGS ${target} ${CPPFLAGS})
  append_target_flags(COMPILE_FLAGS ${target} ${CXXFLAGS})
  # Note that we cannot use target_link_libraries() here because that one
  # only interprets inputs starting with '-' as flags.
  append_target_flags(LINK_LIBRARIES ${target} ${LDFLAGS})
  set(target_path ${CMAKE_CURRENT_BINARY_DIR}/${target})
  if(TEST_SUITE_PROFILE_USE)
    append_target_flags(COMPILE_FLAGS ${target} -fprofile-instr-use=${target_path}.profdata)
    append_target_flags(LINK_LIBRARIES ${target} -fprofile-instr-use=${target_path}.profdata)
  endif()

  llvm_codesign(${target})
  set_property(GLOBAL APPEND PROPERTY TEST_SUITE_TARGETS ${target})
  test_suite_add_build_dependencies(${target})

  if(TEST_SUITE_LLVM_SIZE)
    add_custom_command(TARGET ${target} POST_BUILD
      COMMAND ${TEST_SUITE_LLVM_SIZE} --format=sysv $<TARGET_FILE:${target}>
      > $<TARGET_FILE:${target}>.size)
  endif()
endfunction()

# Creates a new executable build target. Use this instead of `add_executable`.
# It applies CFLAGS, CPPFLAGS, CXXFLAGS and LDFLAGS. Creates a .test file if
# necessary, registers the target with the TEST_SUITE_TARGETS list and makes
# sure we build the required dependencies for compiletime measurements
# and support the TEST_SUITE_PROFILE_USE mode.
function(llvm_test_executable target)
  llvm_test_executable_no_test(${target} ${ARGN})
  llvm_add_test_for_target(${target})
  set(TESTSCRIPT "" PARENT_SCOPE)
endfunction()

# Creates a new library build target. Use this instead of `add_library`.
# Behaves like `llvm_test_executable`, just produces a library instead of an
# executable.
function(llvm_test_library target)
  add_library(${target} ${ARGN})

  append_target_flags(COMPILE_FLAGS ${target} ${CFLAGS})
  append_target_flags(COMPILE_FLAGS ${target} ${CPPFLAGS})
  append_target_flags(COMPILE_FLAGS ${target} ${CXXFLAGS})
  # Note that we cannot use target_link_libraries() here because that one
  # only interprets inputs starting with '-' as flags.
  append_target_flags(LINK_LIBRARIES ${target} ${LDFLAGS})

  # TODO: How to support TEST_SUITE_PROFILE_USE properly?

  test_suite_add_build_dependencies(${target})
endfunction()

# Add dependencies required for compiletime measurements to a target. You
# usually do not need to call this directly when using `llvm_test_executable`
# or `llvm_test_library`.
function(test_suite_add_build_dependencies target)
  add_dependencies(${target}
    build-HashProgramOutput.sh
    build-timeit
    build-timeit-target
    build-fpcmp
    build-fpcmp-target
    build-litsupport
  )
endfunction()

# Internal function that transforms a list of flags to a string and appends
# it to a given property of a target.
function(append_target_flags propertyname target)
  if(NOT "${ARGN}" STREQUAL "")
    get_target_property(old_flags ${target} ${propertyname})
    if(${old_flags} STREQUAL "old_flags-NOTFOUND")
      set(old_flags)
    endif()
    # Transform ${ARGN} which is a cmake list into a series of commandline
    # arguments. This requires some shell quoting (the approach here isn't
    # perfect)
    string(REPLACE " " "\\ " quoted "${ARGN}")
    string(REPLACE "\"" "\\\"" quoted "${quoted}")
    string(REPLACE ";" " " quoted "${quoted}")
    # Ensure that there is no leading or trailing whitespace
    # This is especially important if old_flags is empty and the property
    # is LINK_LIBRARIES, as extra whitespace violates CMP0004
    string(STRIP "${old_flags} ${quoted}" new_flags)
    set_target_properties(${target} PROPERTIES ${propertyname} "${new_flags}")
  endif()
endfunction()

# Usage: llvm_codesign(name [FORCE] [ENTITLEMENTS file] [BUNDLE_PATH path])
function(llvm_codesign name)
  cmake_parse_arguments(ARG "FORCE" "ENTITLEMENTS;BUNDLE_PATH" "" ${ARGN})
  if(NOT LLVM_CODESIGNING_IDENTITY)
    return()
  endif()

  if(CMAKE_GENERATOR STREQUAL "Xcode")
    set_target_properties(${name} PROPERTIES
      XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${LLVM_CODESIGNING_IDENTITY}
    )
    if(DEFINED ARG_ENTITLEMENTS)
      set_target_properties(${name} PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_ENTITLEMENTS ${ARG_ENTITLEMENTS}
      )
    endif()
  elseif(APPLE AND CMAKE_HOST_SYSTEM_NAME MATCHES Darwin)
    if(NOT CMAKE_CODESIGN)
      set(CMAKE_CODESIGN xcrun codesign)
    endif()
    if(NOT CMAKE_CODESIGN_ALLOCATE)
      execute_process(
        COMMAND xcrun -f codesign_allocate
        OUTPUT_STRIP_TRAILING_WHITESPACE
        OUTPUT_VARIABLE CMAKE_CODESIGN_ALLOCATE
      )
    endif()
    if(DEFINED ARG_ENTITLEMENTS)
      set(pass_entitlements --entitlements ${ARG_ENTITLEMENTS})
    endif()

    if (NOT ARG_BUNDLE_PATH)
      set(ARG_BUNDLE_PATH $<TARGET_FILE:${name}>)
    endif()

    if(ARG_FORCE)
      set(force_flag "-f")
    endif()

    add_custom_command(
      TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E
              env CODESIGN_ALLOCATE=${CMAKE_CODESIGN_ALLOCATE}
              ${CMAKE_CODESIGN} -s ${LLVM_CODESIGNING_IDENTITY}
              ${pass_entitlements} ${force_flag} ${ARG_BUNDLE_PATH}
      COMMENT "Codesign ${name}"
    )
  endif()
endfunction()
