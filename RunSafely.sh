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
# Syntax:  ./RunSafely.sh <ulimit> <stdinfile> <stdoutfile> <program> <args...>
#
ULIMIT=$1
shift
INFILE=$1
shift
OUTFILE=$1
shift
PROGRAM=$1
shift

ulimit -t $ULIMIT
rm -f core core.*
ulimit -c unlimited
# To prevent infinite loops which fill up the disk, specify a limit on size of
# files being output by the tests. 10 MB should be enough for anybody. ;)
ulimit -f 10485760

#
# If we are on a sun4u machine (UltraSparc), then the code we're generating
# is 64 bit code.  In that case, use gdb-64 instead of gdb.
#
myarch=`uname -m`
if [ "$myarch" = "sun4u" ]
then
	GDB="gdb-64"
else
	GDB=gdb
fi

#
# Run the command, timing its execution.
# The standard output and standard error of $PROGRAM should go in $OUTFILE,
# and the standard error of time should go in $OUTFILE.time.
#
# Ah, the joys of shell programming!
# To get the time program and the specified program different output filenames,
# we tell time to launch a shell which in turn executes $PROGRAM with the
# necessary I/O redirection.
#
(time sh -c "$PROGRAM $* > $OUTFILE 2>&1 < $INFILE") > $OUTFILE.time 2>&1

if test $? -eq 0
then
  touch $OUTFILE.exitok
fi

if ls | egrep "^core" > /dev/null
then
    corefile=`ls core* | head -1`
    echo "where" > StackTrace.$$
    $GDB -q -batch --command=StackTrace.$$ --core=$corefile $PROGRAM < /dev/null
    rm -f StackTrace.$$ $corefile
fi

exit 0
