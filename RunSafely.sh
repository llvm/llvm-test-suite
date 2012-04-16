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
#           fourth argument specified, and outputs a <outfile>.time file which
#           contains a timing of the program and the program's exit code.
#
#           The <exitok> parameter specifies how the program's exit status
#           is interpreted.  If the <exitok> parameter is non-zero, any
#           non-zero exit status from the program is considered to indicate
#           a test failure.  If the <exitok> parameter is zero, only exit
#           statuses that indicates that the program could not be executed
#           normally or that the program was terminated as a signal are
#           considered to indicate a test failure.
#
#           If optional parameters -r <remote host> -l <remote user> are
#           specified, it execute the program remotely using rsh.
#
# Syntax:
#
#   RunSafely.sh [-r <rhost>] [-l <ruser>] [-rc <client>] [-rp <port>]
#                [-u <under>] -t <timeit>
#                <timeout> <exitok> <infile> <outfile> <program> <args...>
#
#   where:
#     <rhost>   is the remote host to execute the program
#     <ruser>   is the username on the remote host
#     <client>  is the remote client used to execute the program
#     <port>    is the port used by the remote client
#     <under>   is a wrapper that the program is run under
#     <timeit>  is a wrapper that is used to collect timing data
#     <timeout> is the maximum number of seconds to let the <program> run
#     <exitok>  is 1 if the program must exit with 0 return code
#     <infile>  is a file from which standard input is directed
#     <outfile> is a file to which standard output and error are directed
#     <program> is the path to the program to run
#     <args...> are the arguments to pass to the program.
#
if [ $# -lt 4 ]; then
  echo "./RunSafely.sh [-t <PATH>] <timeout> <exitok> <infile> <outfile>" \
       "<program> <args...>"
  exit 1
fi

# Save a copy of the original arguments in a string before we
# clobber them with the shift command.
ORIG_ARGS="$*"

DIR=${0%%`basename $0`}

RHOST=
RUSER=`id -un`
RCLIENT=rsh
RPORT=
RUN_UNDER=
TIMEIT=
if [ $1 = "-r" ]; then
  RHOST=$2
  shift 2
fi
if [ $1 = "-l" ]; then
  RUSER=$2
  shift 2
fi
if [ $1 = "-rc" ]; then
  RCLIENT=$2
  shift 2
fi
if [ $1 = "-rp" ]; then
  RPORT="-p $2"
  shift 2
fi
if [ $1 = "-u" ]; then
  RUN_UNDER=$2
  shift 2
fi
if [ $1 = "-t" ]; then
  TIMEIT=$2
  shift 2
fi

if [ "$TIMEIT" = "" ]; then
  echo "error: missing required argument -t for path to 'timeit'"
  exit 1
fi

TIMELIMIT=$1
EXITOK=$2
INFILE=$3
OUTFILE=$4
PROGRAM=$5
shift 5
SYSTEM=`uname -s`

PROG=${PROGRAM}
if [ `basename ${PROGRAM}` = "lli" ]; then
  PROG=`basename ${PROGRAM}`
fi

LIMITARGS=""
case $SYSTEM in
  CYGWIN*)
    ;;
  *)
    # Disable core file emission.
    LIMITARGS="$LIMITARGS --limit-core 0"

    # Set the CPU limit. We watchdog the process, so this is mostly just for
    # paranoia.
    LIMITARGS="$LIMITARGS --limit-cpu $TIMELIMIT"

    # To prevent infinite loops which fill up the disk, specify a limit on size
    # of files being output by the tests.
    #
    # We set the limit at 100MB.
    LIMITARGS="$LIMITARGS --limit-file-size 104857600"

    # Set the virtual memory limit at 800MB.
    LIMITARGS="$LIMITARGS --limit-rss-size 838860800"
esac

# Run the command, timing its execution and logging the status summary to
# $OUTFILE.time.
PWD=`pwd`
COMMAND="$RUN_UNDER $PROGRAM $*"

TIMEITCMD="$TIMEIT $LIMITARGS --timeout $TIMELIMIT --chdir $PWD"
if [ "x$RHOST" = x ] ; then
  rm -f "$OUTFILE.time"
  $TIMEITCMD \
      --summary $OUTFILE.time \
      --redirect-input $INFILE \
      --redirect-output $OUTFILE \
      $COMMAND
else
  # Get the absolute path to INFILE.
  ABSINFILE=$(cd $(dirname $INFILE); pwd)/$(basename $INFILE)
  rm -f "$PWD/${PROG}.command"
  rm -f "$PWD/${PROG}.remote"
  rm -f "$PWD/${OUTFILE}.remote.time"
  echo "$TIMEITCMD --summary $PWD/$OUTFILE.remote.time --redirect-input $ABSINFILE --redirect-output $PWD/${OUTFILE}.remote $COMMAND" > "$PWD/${PROG}.command"
  chmod +x "$PWD/${PROG}.command"

  ( $RCLIENT -l $RUSER $RHOST $RPORT "ls $PWD/${PROG}.command" ) > /dev/null 2>&1
  ( $RCLIENT -l $RUSER $RHOST $RPORT "$PWD/${PROG}.command" )
  cp $PWD/${OUTFILE}.remote.time $OUTFILE.time
  sleep 1
  cp -f $PWD/${OUTFILE}.remote ${OUTFILE}
  rm -f $PWD/${OUTFILE}.remote
  rm -f $PWD/${OUTFILE}.remote.time
fi

exitval=`grep '^exit ' $OUTFILE.time | sed -e 's/^exit //'`
fail=yes
if [ -z "$exitval" ] ; then
  exitval=99
  echo "TEST $PROGRAM FAILED: CAN'T GET EXIT CODE!"
elif test "$exitval" -eq 126 ; then
  echo "TEST $PROGRAM FAILED: command not executable (exit status 126)!"
elif test "$exitval" -eq 127 ; then
  echo "TEST $PROGRAM FAILED: command not found (exit status 127)!"
elif test "$exitval" -eq 128 ; then
  # Exit status 128 doesn't have a standard meaning, but it's unlikely
  # to be expected program behavior.
  echo "TEST $PROGRAM FAILED: exit status 128!"
elif test "$exitval" -gt 128 ; then
  echo "TEST $PROGRAM FAILED: process terminated by signal (exit status $exitval)!"
elif [ "$EXITOK" -ne 0 -a "$exitval" -ne 0 ] ; then
  echo "TEST $PROGRAM FAILED: EXIT != 0"
else
  fail=no
fi
echo "exit $exitval" >> $OUTFILE

# If we detected a failure, print the name of the test executable to the
# output file. This will cause it to compare as different with other runs
# of the same test even if they fail in the same way, because they'll have
# different command names.
if [ "${fail}" != "no" ]; then
  echo "RunSafely.sh detected a failure with these command-line arguments: " \
       "$ORIG_ARGS" >> $OUTFILE
fi

# Always return "successful" so that tests will continue to be run.
exit 0
