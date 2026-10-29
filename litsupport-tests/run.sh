#!/bin/bash
set -u
TOP_OUTPUT="/tmp/litoutput"
rm -rf "$TOP_OUTPUT"
mkdir -p "$TOP_OUTPUT"

if [ -z "${1:-}" ]; then
	echo "Usage: $0 /path/to/lit [/path/to/FileCheck]"
	exit 1
fi
LIT="$1"
FILECHECK="${2:-FileCheck}"

cd "$(dirname "$0")"

FAILED=0
for i in */lit.site.cfg; do
	DIR="$(dirname $i)"
	# Each suite's lit.site.cfg refers to paths relative to its own directory.
	cd "$DIR"
	echo "===> $DIR"

	OUTPUT="$TOP_OUTPUT/$DIR"
	mkdir -p "$OUTPUT"

	LITFLAGS=""
	if [ -e litflags.txt ]; then
		LITFLAGS="$(cat litflags.txt)"
	fi
	# lit's exit status is ignored: some suites have tests that fail on purpose.
	CMD="$LIT . -j 1 $LITFLAGS -o \"$OUTPUT/result.json\" >& \"$OUTPUT/lit.out\""
	echo "  $CMD"
	eval $CMD
	for f in check/*; do
		BASE="$(basename "$f")"
		CMD="$FILECHECK \"$f\" < \"$OUTPUT/$BASE\""
		echo "  $CMD"
		eval $CMD || FAILED=1
	done

	cd ..
done
exit $FAILED
