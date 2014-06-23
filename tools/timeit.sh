#! /bin/bash
# A wrapper over perf to provide similar functionality to timeit.c

DEPENDS="perf"

# Fallback to ctimeit if dependencies are not met
for cmd in ${DEPENDS} ; do
	if ! command -v ${cmd} &> /dev/null ; then
		$(dirname $0)/ctimeit $@
		exit $?
	fi
done

REPORT=/dev/stderr
INPUT=/dev/stdin
OUTPUT=/dev/stdout

while [[ $1 = -* ]]; do
	if [ $1 = "--summary" ]; then
		REPORT=$2
	elif [ $1 = "--redirect-input" ]; then
		INPUT=$2
	elif [ $1 = "--redirect-output" ]; then
		OUTPUT=$2
	fi
	shift 2
done

perf stat -o stats $@ < $INPUT > $OUTPUT

EXITCODE=$?

echo exit $EXITCODE > $REPORT
awk -F' ' '{if ($2 == "task-clock") print "user",$1/1000; else if($2 =="seconds") print "real",$1;}' stats >> $REPORT

rm stats

exit $EXITCODE
