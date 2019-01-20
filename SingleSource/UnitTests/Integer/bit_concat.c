//===--- bit_concat.c --- Test The bit_concat builtin --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_part_select builtin function llvm-gcc.
// bit_select selects one bit out of a larger 
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <stdlib.h>
#include "bits.h"


int main(int argc, char** argv)
{
  uint17 X = 0;
  uint19 Y = 0;
  uint36 Z = 0;
  int i, j;
  int count = (argc > 1 ? atoi(argv[1]) % 128 : 128);

  srand(count);

  for (i = 0; i < count; i++) {
    Y = X = 0;
    for (j = 0; j < bitwidthof(uint17); j++) {
      X <<= 1;
      X += (rand() % 2 == 0 ? 0 : 1);
    }
    for (j = 0; j < bitwidthof(uint19); j++) {
      Y <<= 1;
      Y += (rand() % 2 == 0 ? 0 : 1);
    }
    Z = bit_concat(X, Y);
    printf("bit_concat(");
    printBits(X);
    printf(",");
    printBits(Y);
    printf(") = ");
    printBits(Z);
    printf("\n");
  }
  return 0;
}
