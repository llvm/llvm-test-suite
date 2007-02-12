//===--- bit_reduce.c --- Test The bit_reduce builtins --------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_bit_*_reduce builtin functions. These
// builtins apply and/or/nor/xor/nxor operations to the bits of an integer type
// in succession until a single final bit is produced.
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include <stdlib.h>

#ifdef ENABLE_LARGE_INTEGERS
typedef int __attribute__((bitwidth(250))) BitType;
const BitType X = 0xAAAAAAAAAAAAAAAAULL;
int numbits = 250;
#else
typedef int __attribute__((bitwidth(47))) BitType;
const BitType X = 0xAAAAAAAAAAAAULL;
int numbits = 47;
#endif

printBits(BitType val, int numbits ) {
  int j;
  for (j = numbits-1; j >= 0; --j) {
    if (__builtin_bit_select(val, j))
      printf("1");
    else
      printf("0");
  }
}

int main(int argc, char** argv)
{

#ifdef ENABLE_LARGE_INTEGERS
  BitType Y = X * X;
#else
  BitType Y = X;
#endif
  int i, j;
  int seed = (argc > 1 ? atoi(argv[1]): 31415927);

  srand(seed);

  for (i = 0; i < 128; i++) {
    int num = rand();
    BitType Val = Y * num;
    {
      unsigned char And  = __builtin_bit_and_reduce(Val);
      unsigned char Nand = __builtin_bit_nand_reduce(Val);
      unsigned char Or   = __builtin_bit_or_reduce(Val);
      unsigned char Nor  = __builtin_bit_nor_reduce(Val);
      unsigned char Xor  = __builtin_bit_xor_reduce(Val);
      unsigned char Nxor = __builtin_bit_nxor_reduce(Val);
      printf("Value=");
      printBits(Val, numbits);
      printf(", and=%d, nand=%d, or=%d, nor=%d, xor=%d, nxor=%d\n",
          And, Nand, Or, Nor, Xor, Nxor);
    }
  }
  return 0;
}
