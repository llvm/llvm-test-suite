#!/bin/sh
#
# NAME
#     DiffOutput.sh
#
# SYNOPSIS
#     DiffOutput.sh <testtype> <testname> [<goodoutput>]
#
# DESCRIPTION
#     DiffOutput.sh looks for a file named Output/<testname>.out-<testtype>
#     and uses GNU diff to compare it against the file
#     Output/<testname>.out-<goodoutput>.  This script is used to verify the
#     results of programs run in the LLVM test suite. By default,
#     <goodoutput> is "nat"; that is, test results are compared with output
#     from the program compiled with the native compiler.
#     If the files differ, DiffOutput.sh prints a portion of the
#     differences.
#
# EXIT STATUS
#     DiffOutput.sh always exits with a zero (successful) exit code.
#

# Command line parameters:
WHICHOUTPUT=$1
PROG=$2
GOODOUTPUT=${3-nat}
# Output filename:
DIFFOUTPUT=Output/${PROG}.diff-${WHICHOUTPUT}
# Input filenames:
TESTOUTPUT=Output/${PROG}.out-${WHICHOUTPUT}
GOODOUTPUT=Output/${PROG}.out-${GOODOUTPUT}

# Find gnu diff
DIFF=diff
if which gdiff > /dev/null 2>&1
then
  where=`which gdiff 2>&1`
  if [ -x "$where" ]
  then
    DIFF=gdiff
  fi
fi

# Diff the two files.
$DIFF -u $GOODOUTPUT $TESTOUTPUT > $DIFFOUTPUT || (
  # They are different!
  echo "******************** TEST '$PROG' FAILED! ********************"
  echo "Execution Context Diff:"
  head -n 200 $DIFFOUTPUT | cat -v
  rm $DIFFOUTPUT
  echo "******************** TEST '$PROG' FAILED! ********************"
)
