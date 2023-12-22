#!/usr/bin/env bash
../llvm-valida/build/bin/clang -c -target delendum $1 -o $2.o
../llvm-valida/build/bin/llvm-objcopy -O binary $2.o $2.bin
