//===--- part_select.c --- Test The bit_select builtin --------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
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

#ifdef ENABLE_LARGE_INTEGERS
typedef unsigned __attribute__((bitwidth(256))) BitType;
const BitType X = 0xFEDCBA9876543210ULL;
unsigned numbits = 256;
#else
typedef unsigned __attribute__((bitwidth(47))) BitType;
const BitType X = 0xFEDCBA9876543210ULL;
unsigned numbits = 47;
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

  for (i = 0; i < numbits; ++i) {
    BitType left = rand() % numbits;
    BitType right = i;
    printf("part_select(Y, %3u, %3u) = ", (unsigned)left, (unsigned)right);
    BitType Z = __builtin_bit_part_select(Y, left, right);
    for (j = numbits; j > 0; --j) {
      if (__builtin_bit_select(Z, j-1))
        printf("1");
      else
        printf("0");
    }
    uint64_t val = Z;
    printf(" (%lx)", val);
    printf("\n");
  }

  return 0;
}
