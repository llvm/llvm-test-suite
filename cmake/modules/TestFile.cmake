##===- TestSuite.cmake ----------------------------------------------------===##
#
# Defines helper functions to create .test files that describe how to run a
# benchmark and optionally how to prepare before running, how to verify the
# results and how to extract metrics from the output.
#
##===----------------------------------------------------------------------===##

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
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
  if(NOT DEFINED ARGS_RUN_TYPE OR "${ARGS_RUN_TYPE}" STREQUAL "${TEST_SUITE_RUN_TYPE}")
    set(TESTSCRIPT "${TESTSCRIPT}RUN: ${ARGS_EXECUTABLE} ${JOINED_ARGUMENTS}\n")
  endif()
endmacro()

# Specify a "VERIFY: " line to be put in a .test file. See also llvm_add_test().
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

# Specify a "PREPARE: " line to be put in a .test file. See also
# llvm_add_test().
macro(llvm_test_prepare)
  CMAKE_PARSE_ARGUMENTS(ARGS "" "RUN_TYPE" "" ${ARGN})
  if(NOT DEFINED TESTSCRIPT)
    set(TESTSCRIPT "" PARENT_SCOPE)
  endif()
  # ARGS_UNPARSED_ARGUMENTS is a semicolon-separated list. Change it into a
  # whitespace-separated string.
  string(REPLACE ";" " " JOINED_ARGUMENTS "${ARGS_UNPARSED_ARGUMENTS}")
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
