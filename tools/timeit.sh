#! /bin/bash
# A wrapper over perf to provide similar functionality to timeit.c

REPORT=/dev/stderr
INPUT=/dev/stdin
OUTPUT=/dev/stdout
PERFSTAT=perfstats

while [[ $1 = -* ]]; do
	if [ $1 = "--summary" ]; then
		REPORT=$2
		PERFSTAT="$REPORT.perfstats"
	elif [ $1 = "--redirect-input" ]; then
		INPUT=$2
	elif [ $1 = "--redirect-output" ]; then
		OUTPUT=$2
	fi
	shift 2
done

perf stat -o $PERFSTAT $@ < $INPUT &> $OUTPUT

EXITCODE=$?

echo exit $EXITCODE > $REPORT
awk -F' ' '{if ($2 == "task-clock") print "user",$1/1000; else if($2 =="seconds") print "real",$1;}' $PERFSTAT >> $REPORT

exit $EXITCODE
