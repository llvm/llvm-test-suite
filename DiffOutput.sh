#!/bin/sh
#
# Program:  DiffOutput.sh
#
# Synopsis: Check two output files for program executions and make sure they
#           match.
#
# Syntax:  ./DiffOutput [lli|llc] <testname>
#

# DIFFOUTPUT - The output filename to make
DIFFOUTPUT=Output/$2.diff-$1

# Find gnu diff
if which gdiff > /dev/null 2>&1
then
  DIFF=gdiff
else
  DIFF=diff
fi

# Diff the two files.
$DIFF -u Output/$2.out-nat Output/$2.out-$1 > $DIFFOUTPUT || (
  # They are different!
  echo "******************** TEST '$2' FAILED! ********************"
  echo "Execution Context Diff:"
  head -n 200 $DIFFOUTPUT
  rm $DIFFOUTPUT
  echo "******************** TEST '$2' FAILED! ********************"
)
