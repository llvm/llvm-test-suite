#!/usr/bin/env bash
# set -x   # uncomment to see commands that are run printed
mkdir -p ./build
TESTS="2023-11-alloca 2023-11-gt 2023-11-lt 2023-12-and 2023-12-and-neg 2023-12-div 2023-12-div-neg 2023-12-eq 2023-12-eq-neg 2023-12-ishl 2023-12-ishl-neg 2023-12-ishr 2023-12-ishr-neg 2023-12-log-and 2023-12-log-and-neg 2023-12-log-not 2023-12-log-not-neg 2023-12-mul 2023-12-muli 2023-12-mul-neg 2023-12-muli-neg 2023-12-ne 2023-12-ne-neg 2023-12-not 2023-12-not-neg 2023-12-or 2023-12-or-neg 2023-12-shl 2023-12-shl-neg 2023-12-shr 2023-12-shri 2023-12-shri-neg 2023-12-shr-neg 2023-12-sra 2023-12-sra-neg 2023-12-sub 2023-12-subi 2023-12-subi-neg 2023-12-sub-neg 2023-12-xor 2023-12-xor-neg 2023-fibonacci 2023-12-divi 2023-12-divi-neg 2023-12-divi-signed 2023-12-divi-signed-neg 2024-1-gti 2024-1-gti-neg 2024-1-igt-neg 2024-1-lti 2024-1-lti-neg 2024-1-ilt 2024-1-ilt-neg 2024-1-or 2024-1-or-neg 2024-1-address-of-value-on-stack 2024-1-address-of-value-on-stack-neg"
for test in $TESTS
do
	echo $test
	./llvm-valida/build/bin/clang -c -target delendum ./llvm-test-suite/SingleSource/UnitTests/$test.c -o ./build/$test.o
	./llvm-valida/build/bin/ld.lld --script=./llvm-valida/valida.ld -o ./build/$test.out ./build/$test.o
	./llvm-valida/build/bin/llvm-objcopy -O binary ./build/$test.out ./build/$test.out.bin
	./valida-mc-fixer/result/bin/valida-mc-fixer ./build/$test.out.bin ./build/$test.out.bin.fix
	timeout 3 ./valida/target/release/valida ./build/$test.out.bin.fix
	echo $? # status 124 indicates non-termination; status 0 indicates successful termination
done
