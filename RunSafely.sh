#!/bin/sh
#
# Program:  RunSafely.sh
#
# Synopsis: This script simply runs another program.  If the program works
#           correctly, this script has no effect, otherwise it will do things
#           like print a stack trace of a core dump.  It always returns
#           "successful" so that tests will continue to be run.
#
#           This script funnels stdout and stderr from the program into the
#           first argument specified, and outputs a <outputfile>.time file which
#           contains a timing of the program.
#
# Syntax:  ./RunSafely.sh <ulimit> <outputfile> <program> <arguments>
#
ULIMIT=$1
shift
OUTFILE=$1
shift
PROGRAM=$1
shift

ulimit -t $ULIMIT
rm -f core core.*
ulimit -c unlimited
(time -p $PROGRAM $* > $OUTFILE) 2> $OUTFILE.time
if ls | egrep "^core" > /dev/null
then
    corefile=`ls core* | head -1`
    echo "where" > StackTrace.$$
    gdb -q -batch --command=StackTrace.$$ --core=$corefile $PROGRAM < /dev/null
    rm -f StackTrace.$$ $corefile
fi

exit 0