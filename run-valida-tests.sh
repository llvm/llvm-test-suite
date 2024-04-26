#!/usr/bin/env bash
# set -x   # uncomment to see commands that are run printed
rm -rf ./buildValidaTests # reset the directory to make sure test results are current
mkdir ./buildValidaTests
./llvm-valida/build/bin/clang -c -target delendum ./llvm-valida/DelendumEntryPoint.c -o ./llvm-valida/build/DelendumEntryPoint.o

# TODO fix these tests: 2023-11-alloca

TERMTESTS="2023-fibonacci 2023-11-gt-neg 2023-11-lt-neg 2023-12-and-neg 2023-12-div-neg 2023-12-eq-neg 2023-12-ishl-neg 2023-12-ishr-neg 2023-12-log-and-neg 2023-12-log-not-neg 2023-12-mul-neg 2023-12-muli-neg 2023-12-ne-neg 2023-12-not-neg 2023-12-or-neg 2023-12-shl-neg 2023-12-shri-neg 2023-12-shr-neg 2023-12-sra-neg 2023-12-subi-neg 2023-12-sub-neg 2023-12-xor-neg 2023-12-divi-neg 2023-12-divi-signed-neg 2024-1-gti-neg 2024-1-igt-neg 2024-1-lti-neg 2024-1-ilt-neg 2024-1-or-neg 2024-1-address-of-value-on-stack-neg 2024-1-stop 2024-1-null 2024-1-write 2024-3-gte-neg 2024-3-gtei-neg 2024-3-igte-neg 2024-3-lte-neg 2024-3-ltei-neg 2024-3-ilte-neg load_byte storeu8 loadu8 2024-4-isge-a 2024-4-isgt-a 2024-4-isle-a 2024-4-sge-a 2024-4-sgei-a 2024-4-sgt-a 2024-4-sgt-b 2024-4-sgti-a 2024-4-sle-a 2024-4-slei-a 2024-4-slt-a 2024-4-slti-a 2024-4-sgt-br 2024-4-sge-b 2024-4-sge-c 2024-4-sge-d 2024-4-sge-e 2024-4-sgt-c 2024-4-sgt-d 2024-4-sgt-e 2024-4-sle-b 2024-4-sle-c 2024-4-sle-d 2024-4-sle-e 2024-4-slt-b 2024-4-slt-c 2024-4-slt-d 2024-4-slt-e"
for test in ${@:-${TERMTESTS[@]}}
do
    echo $test
    ./llvm-valida/build/bin/clang -c -target delendum ./llvm-test-suite/SingleSource/UnitTests/$test.c -o ./buildValidaTests/$test.o
    ./llvm-valida/build/bin/ld.lld --script=./llvm-valida/valida.ld -o ./buildValidaTests/$test.out ./buildValidaTests/$test.o
    ./valida/target/release/valida run ./buildValidaTests/$test.out ./buildValidaTests/$test.log
    ./valida/target/release/valida prove ./buildValidaTests/$test.out ./buildValidaTests/$test.proof
    ./valida/target/release/valida verify ./buildValidaTests/$test.out ./buildValidaTests/$test.proof
done

TESTS="2023-11-gt 2023-11-lt 2023-12-and 2023-12-div 2023-12-eq 2023-12-ishl 2023-12-ishr 2023-12-log-and 2023-12-log-not 2023-12-mul 2023-12-muli 2023-12-ne 2023-12-not 2023-12-or 2023-12-shl 2023-12-shr 2023-12-shri 2023-12-sra 2023-12-sub 2023-12-subi 2023-12-xor 2023-12-divi 2023-12-divi-signed 2024-1-gti 2024-1-lti 2024-1-ilt 2024-1-or 2024-1-address-of-value-on-stack 2024-3-gte 2024-3-gtei 2024-3-igte 2024-3-lte 2024-3-ltei 2024-3-ilte loadu8"
for test in ${@:-${TESTS[@]}}
do
	echo $test
	./llvm-valida/build/bin/clang -c -target delendum ./llvm-test-suite/SingleSource/UnitTests/$test.c -o ./buildValidaTests/$test.o
	./llvm-valida/build/bin/ld.lld --script=./llvm-valida/valida.ld -o ./buildValidaTests/$test.out ./buildValidaTests/$test.o
	timeout 3 ./valida/target/release/valida run ./buildValidaTests/$test.out ./buildValidaTests/$test.log
	echo $? # status 124 indicates non-termination; status 0 indicates successful termination
done

