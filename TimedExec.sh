#!/bin/sh
#
# Program:  TimedExec.sh
#
# Synopsis: This script is a watchdog wrapper. It runs the specified program
# but times out if it does not complete in the allocated time frame.
# Syntax: ./TimedExec.sh <timeout> <program> <args...>
#

if [ $# -lt 2 ]; then
    echo "./TimedExec.sh <timeout> <program> <args...>"
    exit 1
fi

PARENT=""
if [ "$1" == "-p" ]; then
    PARENT=$2; shift; shift;
fi

TIMEOUT=$1
PROGRAM=$2
shift

if [ -z "$PARENT" ]; then
    # Start a watchdog process
    $0 -p $$ $TIMEOUT $PROGRAM $* &
    WATCHDOG="$!"
    exec "$@"
    # I am done first. kill the watch dog.
    kill $WATCHDOG && (sleep 2; kill -1 $WATCHDOG) && (sleep 2; kill -9 $WATCHDOG)
else
    # Sleep for a specified time then wake up to kill the parent process.
    exec > /dev/null 2>&1
    sleep $TIMEOUT
    kill $PARENT && (sleep 2; kill -1 $PARENT) && (sleep 2; kill -9 $PARENT)
fi 

exit 0
