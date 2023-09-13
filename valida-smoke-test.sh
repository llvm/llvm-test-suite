#!/usr/bin/env sh
./clang-valida.sh ./SingleSource/UnitTests/2023-fibonacci.c ./build/fibonacci
./valida-runner.sh ./build/fibonacci
