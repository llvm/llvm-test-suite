#!/bin/sh
#
# Program:  Sandbox.sh
#
# Synopsis: This script is used to provide a sandbox for SPEC programs to
#           execute in.  It provides an isolated environment, the input files
#           necessary, and then finally runs the program.
#
# Syntax:  ./Sandbox.sh <uid> <output_file> <ref input>   <program> <arguments>
#

TEST_UID=$1
OUTPUT_FILE=$2
INPUT_DIR=$3
shift;shift;shift

mkdir Output/$TEST_UID 2> /dev/null
cd Output/$TEST_UID
rm -rf *

# Copy all of the test input files into the current directory...
cp -r $INPUT_DIR/* .

# If there is an "all" input directory, take it as well...
cp -r $INPUT_DIR/../../all/input/* . > /dev/null 2>&1 

# Run the program now...
echo Running: $*
$*

# This script is always successful...
exit 0

