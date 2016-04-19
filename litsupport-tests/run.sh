#!/bin/bash
set -u
TOP_OUTPUT="/tmp/litoutput"
rm -rf "$TOP_OUTPUT"
mkdir -p "$TOP_OUTPUT"

if [ -z "${1:-}" ]; then
	echo "Usage: $0 /path/to/lit"
	exit 1
fi
LIT="$1"

function run_tests {
	OUTPUT="$TOP_OUTPUT/$DIR"
	LIT_EXE="$1"
	rm -rf "$OUTPUT"
	mkdir -p "$OUTPUT"

	LITFLAGS=""
	if [ -e litflags.txt ]; then
		LITFLAGS="$(cat litflags.txt)"
	fi
	CMD="$LIT_EXE . -j 1 $LITFLAGS -o \"$OUTPUT/result.json\" >& \"$OUTPUT/lit.out\""
	echo "  $CMD"
	eval $CMD
	for f in check/*; do
		BASE="$(basename "$f")"
		CMD="cat $OUTPUT/$BASE | FileCheck \"$f\""
		echo "  $CMD"
		eval $CMD
	done
}

for i in */lit.site.cfg; do
	DIR="$(dirname $i)"
	pushd "$DIR" > /dev/null

	echo "===> $DIR/python2.7"
	run_tests "python2.7 $LIT"

	echo "===> $DIR/python3"
	run_tests "python3 $LIT"

	popd > /dev/null
done
