//===--- part_select.c --- Test The bit_select builtin --------------------===//
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
#include <stdint.h>
#include "bits.h"

#ifdef ENABLE_LARGE_INTEGERS
typedef uint256 BitType;
const BitType X = 0xAAAAAAAAAAAAAAAAULL;
#else
typedef uint47 BitType;
const BitType X = 0xAAAAAAAAAAAAAAAAULL;
#endif

int main(int argc, char** argv)
{

#ifdef ENABLE_LARGE_INTEGERS
  BitType Y = X * X;
#else
  BitType Y = X;
#endif

  srand(0);

  unsigned i, j;

  for (i = 0; i < bitwidthof(BitType); ++i) {
    BitType high = rand() % bitwidthof(BitType);
    BitType low = i;
    printf("part_select(Y, %3u, %3u) = ", (unsigned)low, (unsigned)high);
    BitType Z = part_select(Y, low, high );
    printBits(Z);
    uint64_t val = Z;
    printf(" (%llx)", val);
    printf("\n");
  }

  BitType Z = part_select(Y, 0, bitwidthof(Y)-1);
  if (Z == Y)
    printf(" True: ");
  else
    printf("False: ");
  printBits(Z);
  printf(" == ");
  printBits(Y);
  printf("\n");


  return 0;
}
