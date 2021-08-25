##===- TestSuite.cmake ----------------------------------------------------===##
#
# Defines helper functions to create .test files that describe how to run a
# benchmark and optionally how to prepare before running, how to verify the
# results and how to extract metrics from the output.
#
##===----------------------------------------------------------------------===##

# Check that tests don't hardcode paths to CMAKE_BINARY_DIR or CMAKE_SOURCE_DIR
# so the resuling build is relocatable and will still work when the build
# directory is copied to a different path or machine without the sources
# available.
function(llvm_test_check_paths script_line)
  string(FIND "${script_line}" ${CMAKE_BINARY_DIR} binary_dir_pos)
  if (binary_dir_pos GREATER_EQUAL 0)
    message(AUTHOR_WARNING "'${CMAKE_BINARY_DIR}' path used!
      Test will stop working when build directory is moved. Use %S to specify
      paths relative to the test file.")
  endif()
  string(FIND "${script_line}" ${CMAKE_SOURCE_DIR} source_dir_pos)
  if (source_dir_pos GREATER_EQUAL 0)
    message(AUTHOR_WARNING "'${CMAKE_SOURCE_DIR}' path used!
      Tests must not depend on sources being available. Use llvm_test_data()
      to copy data from source to build directory.")
  endif()
endfunction()

# Specify a "RUN: " line to be put in a .test file. See also llvm_add_test().
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
  llvm_test_check_paths("${ARGS_EXECUTABLE}")
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  llvm_test_check_paths("${JOINED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}RUN: ${ARGS_EXECUTABLE} ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

# Specify a "VERIFY: " line to be put in a .test file. See also llvm_add_test().
macro(llvm_test_verify)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE;WORKDIR" "" ${ARGN})
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  if(DEFINED ARGS_WORKDIR)
    set(JOINED_ARGUMENTS "cd ${ARGS_WORKDIR} ; ${JOINED_ARGUMENTS}")
  endif()
  llvm_test_check_paths("${JOINED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}VERIFY: ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

# Specify a "PREPARE: " line to be put in a .test file. See also
# llvm_add_test().
macro(llvm_test_prepare)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE;WORKDIR" "" ${ARGN})
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  if(DEFINED ARGS_WORKDIR)
    set(JOINED_ARGUMENTS "cd ${ARGS_WORKDIR} ; ${JOINED_ARGUMENTS}")
  endif()
  llvm_test_check_paths("${JOINED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}PREPARE: ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

# Specify a "METRIC: " line to be put in a .test file. See also llvm_add_test().
macro(llvm_test_metric)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE;METRIC" "" ${ARGN})
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  llvm_test_check_paths("${JOINED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}METRIC: ${ARGS_METRIC}: ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

# Create a .test driver file suitable for LIT.
# The file contents come from previous llvm_test_XXX() calls.
function(llvm_add_test testfile executable)
  # Replace $EXECUTABLE$ placeholder.
  string(REPLACE "$EXECUTABLE$" "${executable}" TESTSCRIPT "${TESTSCRIPT}")

  # Produce .test file
  file(GENERATE OUTPUT ${testfile} CONTENT "${TESTSCRIPT}")
  # flush the test script
  set(TESTSCRIPT "" PARENT_SCOPE)
endfunction()

function(llvm_add_test_for_target target)
  llvm_add_test($<TARGET_FILE:${target}>.test %S/$<TARGET_FILE_NAME:${target}>)
  set(TESTSCRIPT "" PARENT_SCOPE)
endfunction()
