#!/bin/sh
#
# Program:  RunSafely.sh
#
# Synopsis: This script simply runs another program.  If the program works
#           correctly, this script has no effect, otherwise it will do things
#           like print a stack trace of a core dump.  It always returns
#           "successful" so that tests will continue to be run.
#
# Syntax:  ./RunSafely.sh <program> <arguments>
#

PROGRAM=$1
shift

rm -f core*
ulimit -c hard
$PROGRAM $*
if ls | egrep "^core" > /dev/null
then
    corefile=`ls core* | head -1`
    echo "where" > StackTrace.$$
    gdb -q -batch --command=StackTrace.$$ --core=$corefile $PROGRAM < /dev/null
    rm -f StackTrace.$$ $corefile
fi

exit 0