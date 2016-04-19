#!/bin/bash
TOP_OUTPUT="/tmp/litoutput"
rm -rf "$TOP_OUTPUT"
mkdir -p "$TOP_OUTPUT"

function run_tests {
	OUTPUT="$TOP_OUTPUT/$DIR"
	rm -rf "$OUTPUT"
	mkdir -p "$OUTPUT"

	echo "Running lit"
	LITFLAGS=""
	if [ -e litflags.txt ]; then
		LITFLAGS="$(cat litflags.txt)"
	fi
	$LIT . -j 1 $LITFLAGS -o "$OUTPUT/result.json" >& "$OUTPUT/lit.out"
	for f in check/*; do
		BASE="$(basename "$f")"
		echo "Checking litoutput/$BASE ($f)"
		cat $OUTPUT/$BASE | FileCheck "$f"
	done
}

for i in */lit.site.cfg; do
	DIR="$(dirname $i)"
	pushd "$DIR" > /dev/null

	echo "===> $DIR/python2.7"
	LIT="python2.7 $(which pullvm-lit)"
	run_tests

	echo "===> $DIR/python3"
	LIT="python3 $(which pullvm-lit)"
	run_tests

	popd > /dev/null
done
