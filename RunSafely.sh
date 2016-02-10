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
#           If optional parameters -r <remote host> -l <remote user> are
#           specified, it execute the program remotely using rsh.
#
# Syntax:
#
#   RunSafely.sh [-d <workdir>] [-r <rhost>] [-l <ruser>] [-rc <client>]
#                [-rp <port>] [-u <under>] [--show-errors]
#                [-n [-o <stdoutfile>] [-e <stderrfile>]]
#                -t <timeit> <timeout> <infile> <outfile> <program> <args...>
#
#   where:
#     <workdir> is the directory where the program is executed
#     <rhost>   is the remote host to execute the program
#     <ruser>   is the username on the remote host
#     <client>  is the remote client used to execute the program
#     <port>    is the port used by the remote client
#     <under>   is a wrapper that the program is run under
#     <stdoutfile> file where standard output is written to
#     <stderrfile> file where standard error output is written to
#     <timeit>  is a wrapper that is used to collect timing data
#     <timeout> is the maximum number of seconds to let the <program> run
#     <infile>  is a file from which standard input is directed
#     <outfile> is a file to which standard output and error are directed.
#               If -n was specified this is just used as the basename for the
#               .time file.
#     <program> is the path to the program to run
#     <args...> are the arguments to pass to the program.
#
# If --show-errors is given, then the output file will be printed if the command
# fails (returns a non-zero exit code).
# The -n switch will enable "new-style" output. This means the exit status is
# not appended to the output anymore and stdout and stderr may be redirected
# separately.
# Without -n stdout and stderr will both be written to the <outfile> followed by
# "exit NN" with NN being the exit status number of the program.

if [ $# -lt 4 ]; then
  echo "./RunSafely.sh [-t <PATH>] <timeout> <infile> <outfile>" \
       "<program> <args...>"
  exit 1
fi

# Save a copy of the original arguments in a string before we
# clobber them with the shift command.
ORIG_ARGS="$*"

DIR=${0%%`basename $0`}

RHOST=
RFLAGS=""
RCLIENT=rsh
RUN_UNDER=
TIMEIT=
SHOW_ERRORS=0
NEW_MODE=0
STDOUT_FILE=""
STDERR_FILE=""
PWD=`pwd`
WORKDIR="$PWD"
if [ $1 = "-d" ]; then
  WORKDIR="$2"
  shift 2
fi
if [ $1 = "-r" ]; then
  RHOST=$2
  shift 2
fi
if [ $1 = "-l" ]; then
  RFLAGS="$RFLAGS -l $2"
  shift 2
fi
if [ $1 = "-rc" ]; then
  RCLIENT=$2
  shift 2
fi
if [ $1 = "-rp" ]; then
  RFLAGS="$RFLAGS -p $2"
  shift 2
fi
if [ $1 = "-u" ]; then
  RUN_UNDER=$2
  shift 2
fi
if [ $1 = "--show-errors" ]; then
  SHOW_ERRORS=1
  shift 1
fi
if [ $1 = "-n" ]; then
  NEW_MODE=1
  shift 1
  if [ $1 = "-o" ]; then
    STDOUT_FILE="$2"
    shift 2
  fi
  if [ $1 = "-e" ]; then
    STDERR_FILE="$2"
    shift 2
  fi
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
INFILE=$2
OUTFILE=$3
PROGRAM=$4
shift 4

PROG=${PROGRAM}
if [ `basename ${PROGRAM}` = "lli" ]; then
  PROG=`basename ${PROGRAM}`
fi

# Run the command, timing its execution and logging the status summary to
# $OUTFILE.time.
COMMAND="$RUN_UNDER $PROGRAM $*"

# Determine absolute paths of infiles/outfiles
INFILE="$(cd $(dirname $INFILE); pwd)/$(basename $INFILE)"
if [ "$STDOUT_FILE" != "" ]; then
  case "$STDOUT_FILE" in
    /*) STDOUT_FILE="$STDOUT_FILE";;
	*) STDOUT_FILE="$PWD/$STDOUT_FILE";;
  esac
fi
if [ "$STDERR_FILE" != "" ]; then
  case "$STDERR_FILE" in
    /*) STDERR_FILE="$STDERR_FILE";;
    *) STDERR_FILE="$PWD/$STDERR_FILE";;
  esac
fi
case "$OUTFILE" in
  /*) OUTFILE="$OUTFILE";;
  *) OUTFILE="$PWD/$OUTFILE";;
esac

# Use suffix for remotely created files.
REMOTE_SUFFIX=""
if [ "x$RHOST" != x ]; then
  REMOTE_SUFFIX=".remote"
fi

# Disable core file emission.
TIMEITFLAGS=""
TIMEITFLAGS="$TIMEITFLAGS --limit-core 0"

# Set the CPU limit. We watchdog the process, so this is mostly just for
# paranoia.
TIMEITFLAGS="$TIMEITFLAGS --limit-cpu $TIMELIMIT"

# To prevent infinite loops which fill up the disk, specify a limit on size
# of files being output by the tests.
#
# We set the limit at 100MB.
TIMEITFLAGS="$TIMEITFLAGS --limit-file-size 104857600"

# Set the virtual memory limit at 800MB.
TIMEITFLAGS="$TIMEITFLAGS --limit-rss-size 838860800"

TIMEITFLAGS="$TIMEITFLAGS --timeout $TIMELIMIT --chdir $WORKDIR"
TIMEITFLAGS="$TIMEITFLAGS --redirect-input ${INFILE}"
TIMEITFLAGS="$TIMEITFLAGS --summary ${OUTFILE}.time${REMOTE_SUFFIX}"
if [ "$NEW_MODE" = "0" ]; then
  TIMEITFLAGS="$TIMEITFLAGS --redirect-output ${OUTFILE}${REMOTE_SUFFIX}"
else
  if [ "$STDERR_FILE" != "" ]; then
    TIMEITFLAGS="$TIMEITFLAGS --redirect-stderr ${STDERR_FILE}${REMOTE_SUFFIX}"
  fi
  if [ "$STDOUT_FILE" != "" ]; then
    TIMEITFLAGS="$TIMEITFLAGS --redirect-stdout ${STDOUT_FILE}${REMOTE_SUFFIX}"
  fi
fi

# Run the command
rm -f "${OUTFILE}.time" "${OUTFILE}" "${STDOUT_FILE}" "${STDERR_FILE}"
if [ "x$RHOST" = x ] ; then
  $TIMEIT $TIMEITFLAGS $COMMAND
else
  rm -f "${OUTFILE}.time${REMOTE_SUFFIX}" "${OUTFILE}${REMOTE_SUFFIX}"
  rm -f "${STDOUT_FILE}${REMOTE_SUFFIX}" "${STDERR_FILE}${REMOTE_SUFFIX}"

  # Pass LLVM_PROFILE_FILE environment variable along
  PREFIX=""
  if [ "${LLVM_PROFILE_FILE}" != "" ]; then
     PREFIX="LLVM_PROFILE_FILE=\"$LLVM_PROFILE_FILE\" "
  fi

  # Create .command script
  COMMANDFILE="${OUTFILE}.command"
  rm -f "${COMMANDFILE}"
  echo "${PREFIX}${TIMEIT} $TIMEITFLAGS $COMMAND" > "${COMMANDFILE}"
  chmod +x "${COMMANDFILE}"

  ( $RCLIENT $RFLAGS $RHOST "ls ${COMMANDFILE}" ) > /dev/null 2>&1
  ( $RCLIENT $RFLAGS $RHOST "${COMMANDFILE}" )
  sleep 1

  # Copy remote files back
  cp -f "${OUTFILE}.time${REMOTE_SUFFIX}" "${OUTFILE}.time"
  rm -f "${OUTFILE}.time${REMOTE_SUFFIX}"
  if [ "$NEW_MODE" = "0" ]; then
    cp -f "${OUTFILE}${REMOTE_SUFFIX}" "${OUTFILE}"
    rm -f "${OUTFILE}${REMOTE_SUFFIX}"
  else
    if [ "$STDERR_FILE" != "" ]; then
      cp -f "${STDERR_FILE}${REMOTE_SUFFIX}" "${STDERR_FILE}"
      rm -f "${STDERR_FILE}${REMOTE_SUFFIX}"
    fi
    if [ "$STDOUT_FILE" != "" ]; then
      cp -f "${STDOUT_FILE}${REMOTE_SUFFIX}" "${STDOUT_FILE}"
      rm -f "${STDOUT_FILE}${REMOTE_SUFFIX}"
    fi
  fi
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
elif [ "$SHOW_ERRORS" -eq 1 -a "$exitval" -ne 0 ] ; then
  echo "TEST $PROGRAM FAILED: EXIT != 0"
else
  fail=no
fi
if [ "$NEW_MODE" = "0" ]; then
  echo "exit $exitval" >> $OUTFILE
fi

# If we detected a failure, print the name of the test executable to the
# output file. This will cause it to compare as different with other runs
# of the same test even if they fail in the same way, because they'll have
# different command names.
if [ "${fail}" != "no" ]; then
  echo "RunSafely.sh detected a failure with these command-line arguments: " \
       "$ORIG_ARGS" >> $OUTFILE
  if [ "$SHOW_ERRORS" = "1" ]; then
      echo "error: command failed while generating $OUTFILE"
      echo "---"
      cat $OUTFILE
      echo "---"
  fi
fi

# Always return "successful" so that tests will continue to be run.
exit 0
