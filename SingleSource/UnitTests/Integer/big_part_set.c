//===--- big_part_set.c --- Test The part_set builtin ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_part_set builtin function llvm-gcc.
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include "bits.h"

typedef uint169 BitType;
BitType X = 0;

int main(int argc, char** argv)
{
  int i;

  printf("0b0");
  printBits(X);
  printf("\n");
  for (i = bitwidthof(BitType); i > 0; --i) {
    X = part_set(X, 1, i-1, i-1);
    printf("0b0");
    printBits(X);
    printf("\n");
  }

  return 0;
}
