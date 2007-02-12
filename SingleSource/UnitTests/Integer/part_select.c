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

#ifdef ENABLE_LARGE_INTEGERS
typedef int __attribute__((bitwidth(256))) BitType;
const BitType X = 0xAAAAAAAAULL;
int numbits = 256;
#else
typedef int __attribute__((bitwidth(47))) BitType;
const BitType X = 0xAAAAAAAAULL;
int numbits = 47;
#endif

int main(int argc, char** argv)
{

#ifdef ENABLE_LARGE_INTEGERS
  BitType Y = X * X;
#else
  BitType Y = X;
#endif

  srand(0);

  int i, j;

  for (i = 1; i <= numbits; ++i) {
    BitType left = rand() % numbits;
    BitType right = i;
    BitType Z = __builtin_bit_part_select(Y, left, right);
    printf("part_select(Y, %3d, %3d) = ", (int)left, (int)right);
    for (j = numbits; j > 0; --j) {
      if (__builtin_bit_select(Z, j))
        printf("1");
      else
        printf("0");
    }
    printf("\n");
  }

  return 0;
}
