#===------------------------------------------------------------------------===#
#
# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#
#===------------------------------------------------------------------------===#

# Run the compiler and save the compiler diagnostics to file. The diagnostics
# are simply the messages printed to stdout and stderr. This is intended to be
# used for the "compile" tests in this test. The "compile" tests exercise the
# compiler's parser and semantic analyzer as well as the diagnostics.

# Required parameters
#
#     COMPILER: STRING            Path to the compiler.
#     COMPILER_FLAGS: STRING      Compiler flags.
#     INPUT_FILES: STRING         Space separated list of files to compile.
#     OUTPUT_FILE: STRING         The output diagnostics file.
#     OBJECT_FILE: STRING         The object file produced by the compiler. This
#                                 will be deleted before this script exits.
#
# Optional parameters
#
#     ALWAYS_SAVE_DIAGS: BOOLEAN  If true, diagnostics will be saved even if no
#                                 error occured when compiling. Otherwise,
#                                 diagnostics will only be saved if compilation
#                                 failed for any reason.
#

execute_process(COMMAND ${COMPILER} ${COMPILER_FLAGS} ${INPUT_FILES} -o ${OBJECT_FILE}
  RESULT_VARIABLE RETVAR
  OUTPUT_VARIABLE OUTVAR
  ERROR_VARIABLE ERRVAR
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_STRIP_TRAILING_WHITESPACE)

file(WRITE "${OUTPUT_FILE}" "")
if (ALWAYS_SAVE_DIAGS OR NOT "${RETVAR}" EQUAL "0")
  file(APPEND "${OUTPUT_FILE}" "${ERRVAR}")
  file(APPEND "${OUTPUT_FILE}" "")
  file(APPEND "${OUTPUT_FILE}" "${OUTVAR}")
endif()

file(REMOVE ${OBJECT_FILE})
