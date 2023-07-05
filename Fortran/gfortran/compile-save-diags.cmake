#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# Run the compiler and save the compiler diagnostics to file. The diagnostics
# are simply the messages printed to stdout and stderr. This is intended to be
# used for the "compile" tests in this suite.

# Required parameters
#
#     CMD: STRING                 Most of the compilation command. This excludes
#                                 the module directory flag (-J).
#
#     OUTPUT_FILE: STRING         The output file containing any compiler
#                                 diagnostics.
#
# Optional parameters
#
#     ALWAYS_SAVE_DIAGS: BOOLEAN  If true, diagnostics will be saved even if no
#                                 error occured when compiling. Otherwise,
#                                 diagnostics will only be saved if compilation
#                                 failed for any reason.
#

separate_arguments(COMMAND NATIVE_COMMAND "${CMD} -J${WORKING_DIRECTORY}")

# There are race conditions on .mod (due to different tests compiling modules
# having the same name). At the time of writing, there don't seem to be any
# multi-file "compile" tests, let alone any pairs of tests which might generate
# object files having the same name. In case any do show up, set the working
# directory to be the module directory. This ensures that any object files are
# written to the dedicated working directory for the test.
execute_process(COMMAND ${COMMAND}
  WORKING_DIRECTORY ${WORKING_DIRECTORY}
  RESULT_VARIABLE RETVAR
  OUTPUT_VARIABLE OUTVAR
  ERROR_VARIABLE ERRVAR
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_STRIP_TRAILING_WHITESPACE)

# An output file will always be written because one is expected to exists at
# test-time.
file(WRITE "${OUTPUT_FILE}" "")

# Only save diagnostics if the compilation return a non-zero (error) code unless
# instructed to always save diagnostics.
if (ALWAYS_SAVE_DIAGS OR NOT "${RETVAR}" EQUAL "0")
  file(APPEND "${OUTPUT_FILE}" "${ERRVAR}")
  file(APPEND "${OUTPUT_FILE}" "")
  file(APPEND "${OUTPUT_FILE}" "${OUTVAR}")
endif()
