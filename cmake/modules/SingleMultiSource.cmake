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

# get_unique_exe_name - Given a source file name after which a test should be
# named, create a unique name for the test. Usually this is just the source file
# with the suffix stripped, but in some cases this ends up causing duplicates
# so attempt to make each unique (by adding pathname segments until they become
# unique).
#
# FIXME: Swap this with a simpler procedure to just append a numeral
set_property(GLOBAL PROPERTY registered_executables)
function(get_unique_exe_name new_name main_src)
  get_property(registered_executables GLOBAL PROPERTY registered_executables)

  string(REGEX REPLACE ".[cp]+$" "" path ${main_src})
  string(REGEX REPLACE ".*/" "" name ${path})
  list(FIND registered_executables ${name} name_idx)

  if(${name_idx} EQUAL -1)
    set(${new_name} ${name} PARENT_SCOPE)
    set_property(GLOBAL APPEND PROPERTY registered_executables ${name})
    return()
  endif()

  # There is a clash. Rename the target. Each time around the loop pull in
  # a new path component.
  foreach(n RANGE 1 4)
    string(REGEX REPLACE ".*/([^/]+/${name})" "\\1" name ${path})
    string(REGEX REPLACE "/" "-" safe_name ${name})

    list(FIND registered_executables ${safe_name} name_idx)
    if(${name_idx} EQUAL -1)
      set(${new_name} ${safe_name} PARENT_SCOPE)
      set_property(GLOBAL APPEND PROPERTY registered_executables ${safe_name})
      return()
    endif()
  endforeach()
  message(FATAL_ERROR "Failed to uniquify executable name!")
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
    set_target_properties(${target} PROPERTIES ${propertyname} "${old_flags} ${quoted}")
  endif()
endmacro()

macro(append_compile_flags target)
  append_target_flags(COMPILE_FLAGS ${target} ${ARGN})
endmacro()

macro(append_link_flags target)
  append_target_flags(LINK_FLAGS ${target} ${ARGN})
endmacro()

# llvm_add_test - Create a .test driver file suitable for LIT.
#
# The test template lives in cmake/lit-test-template.in and is configured by this function.
function(llvm_add_test name exename)
  # Fall back to old style involving RUN_OPTIONS and STDIN_FILENAME if
  # llvm_test_run() was not called yet.
  if(NOT TESTSCRIPT)
    if(DEFINED STDIN_FILENAME)
      list(APPEND RUN_OPTIONS "< ${STDIN_FILENAME}")
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
  endif()

  # Replace $EXECUTABLE$ placeholder.
  string(REPLACE "$EXECUTABLE$" "${CMAKE_CURRENT_BINARY_DIR}/${exename}" TESTSCRIPT "${TESTSCRIPT}")

  # Produce .test file
  file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${exename}.test
    CONTENT "${TESTSCRIPT}")
endfunction()

macro(test_suite_add_executable name mainsource)
  list(FIND PROGRAMS_TO_SKIP ${name} name_idx)
  # Should we skip this?
  if(${name_idx} EQUAL -1)
    get_unique_exe_name(source_exename ${mainsource})
    add_executable(${source_exename} ${ARGN})
    append_compile_flags(${source_exename} ${CFLAGS})
    append_compile_flags(${source_exename} ${CPPFLAGS})
    append_compile_flags(${source_exename} ${CXXFLAGS})
    # Note that we cannot use target_link_libraries() here because that one
    # only interprets inputs starting with '-' as flags.
    append_link_flags(${source_exename} ${LDFLAGS})
    if (TEST_SUITE_PROFILE_USE)
      append_compile_flags(${source_exename} -fprofile-instr-use=${CMAKE_CURRENT_BINARY_DIR}/${source_exename}.profdata)
      append_link_flags(${source_exename} -fprofile-instr-use=${CMAKE_CURRENT_BINARY_DIR}/${source_exename}.profdata)
    endif()

    llvm_add_test(${name} ${source_exename})
    add_dependencies(${source_exename} timeit-host timeit-target fpcmp-host)
  endif()
endmacro()

# llvm_singlesource - configure the current directory as a SingleSource subdirectory -
# i.e. every file in *.{c,cpp,cc} is treated as its own test.
macro(llvm_singlesource)
  file(GLOB sources *.c *.cpp *.cc)
  foreach(source ${sources})
    # Find the pure name of the test
    string(REGEX REPLACE ".[cp]+$" "" path ${source})
    string(REGEX REPLACE ".*/" "" name ${path})

    test_suite_add_executable(${name} ${source} ${source})
  endforeach()
endmacro()

# llvm_multisource - configure the current directory as a MultiSource subdirectory -
# i.e. there is one test and it consists of all sources in the directory (or a curated
# list, if Source is defined).
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

macro(llvm_test_run)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE;EXECUTABLE;WORKDIR" "" ${ARGN})
  # If no executable is specified use $EXECUTABLE$ placeholder which will be
  # replaced later.
  if(NOT DEFINED ARGS_EXECUTABLE)
    set(ARGS_EXECUTABLE "$EXECUTABLE$")
  endif()
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  if(DEFINED ARGS_WORKDIR)
    set(ARGS_EXECUTABLE "cd ${ARGS_WORKDIR} ; ${ARGS_EXECUTABLE}")
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}RUN: ${ARGS_EXECUTABLE} ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

macro(llvm_test_verify)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE" "" ${ARGN})
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}VERIFY: ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()
