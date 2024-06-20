#!/bin/bash
# Sync a build directory to remote device for running.
set -eu
CLIENT="$1"
DEVICE="$2"
BUILDDIR="$3"

case $BUILDDIR in
    /*) ;;
    *)
        echo 1>&2 "Builddir path must be absolute!"
        exit 1
        ;;
esac

RSYNC_FLAGS=""
RSYNC_FLAGS+=" -a"
RSYNC_FLAGS+=" --delete --delete-excluded"
RSYNC_FLAGS+=" -e \"$CLIENT\""
# We cannot easily differentiate between intermediate build results and
# files necessary to run the benchmark, so for now we just exclude based on
# some file extensions...
RSYNC_FLAGS+=" --exclude=\"*.o\""
RSYNC_FLAGS+=" --exclude=\"*.a\""
RSYNC_FLAGS+=" --exclude=\"*.time\""
RSYNC_FLAGS+=" --exclude=\"*.cmake\""
RSYNC_FLAGS+=" --exclude=Output/"
RSYNC_FLAGS+=" --exclude=.ninja_deps"
RSYNC_FLAGS+=" --exclude=.ninja_log"
RSYNC_FLAGS+=" --exclude=build.ninja"
RSYNC_FLAGS+=" --exclude=rules.ninja"
RSYNC_FLAGS+=" --exclude=CMakeFiles/"

set -x
$CLIENT $DEVICE mkdir -p "$BUILDDIR"
eval rsync $RSYNC_FLAGS $BUILDDIR/ $DEVICE:$BUILDDIR/
