#!/bin/sh
#
if [ -e .input_generated ]; then
	exit
fi

geninput() {
	input1=$1
	input10=""
	input50=""
	for c in 1 2 3 4 5 6 7 8 9 10; do
		input10="$input10 $input1"
	done
	for c in 1 2 3 4 5; do
		input50="$input50 $input10"
	done
	declare -i count=$2
	output=${1/.txt/${3}.txt}
	echo "gen. input file: '$output'"
	rm -f $output
	while (($count > 50)); do
		let count=$((count - 50))
		cat $input50 >>$output
	done
	while (($count > 10)); do
		let count=$((count - 10))
		cat $input10 >>$output
	done
	while (($count > 0)); do
		let count=$((count - 1))
		cat $input1 >>$output
	done
}

geninput "input/moments-input.txt" 800 400000
geninput "input/regexmatch-input.txt" 2000 2000
geninput "input/reversefile-input.txt" 50 50
geninput "input/spellcheck-input.txt" 30 30
geninput "input/sumcol-input.txt" 2000 2000
geninput "input/wc-input.txt" 3000 3000
geninput "input/wordfreq-input.txt" 20 20

touch .input_generated
