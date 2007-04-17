//===--- bit_select.c --- Test The bit_select builtin ---------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_bit_select builtin function llvm-gcc.
// bit_select selects one bit out of a larger 
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <bits.h>

#ifdef ENABLE_LARGE_INTEGERS
typedef Int250 BitType;
const BitType X = 0xAAAAAAAAAAAAAAAAULL;
#else
typedef Int47 BitType;
const BitType X = 0xAAAAAAAAAAAAULL;
#endif

int main(int argc, char** argv)
{

#ifdef ENABLE_LARGE_INTEGERS
  BitType Y = X * X;
#else
  BitType Y = X;
#endif

  BitType i;

  for (i = bitwidthof(BitType); i > 0; --i) {
    if (bit_select(Y, i-1)) 
      printf("1");
    else
      printf("0");
  }

  printf("\n");
  return 0;
}
