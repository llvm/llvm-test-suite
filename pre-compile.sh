#!/bin/sh

#set -x
set -e

./llvm-valida/build/bin/clang -c -target delendum ./llvm-valida/DelendumEntryPoint.c -o ./llvm-valida/build/DelendumEntryPoint.o

