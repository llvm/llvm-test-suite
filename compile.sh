#!/bin/sh

# build a file in $PWD/llvm-test-suite/ folder, and link it with valida_test.ld script and send to $PWD/buildValidaTests folder

set -e
#set -x

$PWD/llvm-valida/build/bin/clang -c -target delendum $1 -o $2
$PWD/llvm-valida/build/bin/ld.lld --script=$PWD/llvm-valida/valida.ld -o $2.out $2
