#! /bin/bash
# A wrapper over perf to provide similar functionality to timeit.c

REPORT=/dev/stderr
INPUT=/dev/stdin
OUTPUT=/dev/stdout
ERRPUT=/dev/stderr
PERFSTAT=perfstats
APPEND_STATUS=0

while [[ $1 = -* ]]; do
  if [ $1 = "--summary" ]; then
    REPORT=$2
    PERFSTAT="$REPORT.perfstats"
  elif [ $1 = "--redirect-input" ]; then
    INPUT=$2
  elif [ $1 = "--redirect-output" ]; then
    OUTPUT=$2
    ERRPUT=$2
  elif [ $1 = "--redirect-stdout" ]; then
    OUTPUT=$2
  elif [ $1 = "--chdir" ]; then
    cd $2
  elif [ $1 = "--append-exitstatus" ]; then
    APPEND_STATUS=1
    shift 1
    continue
  fi
  shift 2
done

if [ "$OUTPUT" = "$ERRPUT" ]; then
  # Use >& to ensure the streams are properly interleaved.
  perf stat -o $PERFSTAT $@ < $INPUT >& $OUTPUT
else
  perf stat -o $PERFSTAT $@ < $INPUT > $OUTPUT 2> $ERRPUT
fi

EXITCODE=$?
if [ "$APPEND_STATUS" = "1" ]; then
  echo "exit $EXITCODE" >> $OUTPUT
  # When --append-exitstatus is used, timeit will append the
  # exit status to the output file and return 0. Model this
  # behaviour here.
  EXITCODE=0
fi

echo exit $EXITCODE > $REPORT
awk -F' ' '{if ($2 == "task-clock") print "user",$1/1000; else if($2 =="seconds") print "real",$1;}' $PERFSTAT >> $REPORT

exit $EXITCODE
