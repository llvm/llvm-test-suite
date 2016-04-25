##===- SingleMultiSource.cmake --------------------------------------------===##
#
# Defines helpers to add executables and tests. The entry points to this
# file are:
#   `llvm_singlesource()` and
#   `llvm_multisource()`
#
# Each is a macro that uses the environment it was called in to determine
# what to build and how, and generates a test file that can be given to LIT.
# The test file is generated at configure time.
#
##===----------------------------------------------------------------------===##

include(TestFile)


# Set unique target prefix within caller's scope.
function(llvm_target_prefix prefix)
  if(prefix)
    set(TARGET_PREFIX "${prefix}-" PARENT_SCOPE)
  else()
    set(TARGET_PREFIX "" PARENT_SCOPE)
  endif()
endfunction()

# Given a source file name after which a test should be named, create a unique
# name for the test. Usually this is just the source file with the suffix
# stripped, and ${TARGET_PREFIX} prepended.
function(get_unique_exe_name new_name main_src)
  string(REGEX REPLACE ".[cp]+$" "" path ${main_src})
  get_filename_component(name ${path} NAME )

  set(${new_name} "${TARGET_PREFIX}${name}" PARENT_SCOPE)
endfunction()

# Add flags to a cmake target property.
macro(append_target_flags propertyname target)
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
endmacro()

macro(append_compile_flags target)
  append_target_flags(COMPILE_FLAGS ${target} ${ARGN})
endmacro()

macro(append_link_flags target)
  append_target_flags(LINK_LIBRARIES ${target} ${ARGN})
endmacro()

# Traditionally CMakeLists.txt files would set RUN_OPTIONS, STDIN_FILENAME,
# SMALL_PROBLEM_SIZE, HASH_PROGRAM_OUTPUT, etc.
# Create llvm_test_run() and llvm_test_verify() invocation for that.
function(llvm_test_traditional testfile executable name)
  if(DEFINED STDIN_FILENAME)
    list(APPEND RUN_OPTIONS "< ${STDIN_FILENAME}")
  endif()
  if(WORKDIR)
    list(APPEND RUN_OPTIONS WORKDIR ${WORKDIR})
  endif()
  llvm_test_run(${RUN_OPTIONS})

  # Hash if we've been asked to.
  if(HASH_PROGRAM_OUTPUT)
    llvm_test_verify("${CMAKE_SOURCE_DIR}/HashProgramOutput.sh %o")
  endif()

  if(NOT DEFINED PROGRAM_IS_NONDETERMINISTIC)
    # Find the reference output file key name.
    if(SMALL_PROBLEM_SIZE)
      set(KEY small)
    elseif(LARGE_PROBLEM_SIZE)
      set(KEY large)
    else()
      set(KEY)
    endif()

    # Pick the best reference output based on "programname.reference_output".
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian.${KEY})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${KEY})
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output.${ENDIAN}-endian)
    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
      set(REFERENCE_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.reference_output)
    else()
      message("-- No reference output found for test ${name}")
    endif()

    set(DIFFPROG ${CMAKE_BINARY_DIR}/tools/fpcmp)
    if(DEFINED FP_TOLERANCE)
      set(DIFFPROG "${DIFFPROG} -r ${FP_TOLERANCE}")
    endif()
    if(DEFINED FP_ABSTOLERANCE)
      set(DIFFPROG "${DIFFPROG} -a ${FP_ABSTOLERANCE}")
    endif()
    if(REFERENCE_OUTPUT)
      llvm_test_verify("${DIFFPROG} %o ${REFERENCE_OUTPUT}")
    endif()
  endif()
  llvm_add_test(${testfile} ${executable})
endfunction()

macro(test_suite_add_executable name mainsource)
  list(FIND PROGRAMS_TO_SKIP ${name} name_idx)
  # Should we skip this?
  if(${name_idx} EQUAL -1)
    get_unique_exe_name(executable ${mainsource})
    add_executable(${executable} ${ARGN})
    append_compile_flags(${executable} ${CFLAGS})
    append_compile_flags(${executable} ${CPPFLAGS})
    append_compile_flags(${executable} ${CXXFLAGS})
    # Note that we cannot use target_link_libraries() here because that one
    # only interprets inputs starting with '-' as flags.
    append_link_flags(${executable} ${LDFLAGS})
    set(executable_path ${CMAKE_CURRENT_BINARY_DIR}/${executable})
    if (TEST_SUITE_PROFILE_USE)
      append_compile_flags(${executable} -fprofile-instr-use=${executable_path}.profdata)
      append_link_flags(${executable} -fprofile-instr-use=${executable_path}.profdata)
    endif()

    set_property(GLOBAL APPEND PROPERTY TEST_SUITE_TARGETS ${executable})

    # Fall back to old style involving RUN_OPTIONS and STDIN_FILENAME if
    # llvm_test_run() was not called yet.
    if(NOT TESTSCRIPT)
      llvm_test_traditional(${executable_path}.test ${executable_path} ${name})
    else()
      llvm_add_test(${executable_path}.test ${executable_path})
    endif()
    if (NOT TEST_SUITE_USE_PERF)
      add_dependencies(${executable} timeit-target)
    endif()
    add_dependencies(${executable} timeit-host fpcmp-host)
  endif()
endmacro()

# Configure the current directory as a SingleSource subdirectory - i.e. every
# file in *.{c,cpp,cc} is treated as its own test.
macro(llvm_singlesource)
  file(GLOB sources *.c *.cpp *.cc)
  foreach(source ${sources})
    # Find the pure name of the test
    string(REGEX REPLACE ".[cp]+$" "" path ${source})
    string(REGEX REPLACE ".*/" "" name ${path})

    test_suite_add_executable(${name} ${source} ${source})
  endforeach()
endmacro()

# Configure the current directory as a MultiSource subdirectory - i.e. there is
# one test and it consists of all sources in the directory (or a curated list,
# if Source is defined).
macro(llvm_multisource)
  if(DEFINED Source)
    set(sources ${Source})
  else()
    file(GLOB sources *.c *.cpp *.cc)
  endif()
  list(LENGTH sources sources_len)

  if(sources_len GREATER 0 AND DEFINED PROG)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    test_suite_add_executable(${PROG} "${PROG}.c" ${sources})
  endif()
endmacro()
