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
const BitType X = 0xFFFFFFFFFFFFFFFFULL;
int numbits = 250;
#else
typedef int __attribute__((bitwidth(15))) BitType;
const BitType X = 0xFFFFFFFFFFFULL;
int numbits = 15;
#endif

void printBits(BitType val, int numbits ) {
  int j;
  for (j = numbits-1; j >= 0; --j) {
    if (__builtin_bit_select(val, j))
      printf("1");
    else
      printf("0");
  }
}

void showReduction(BitType Val) {
  printf("Value=");
  _Bool And  = __builtin_bit_and_reduce(Val);
  _Bool Nand = __builtin_bit_nand_reduce(Val);
  _Bool Or   = __builtin_bit_or_reduce(Val);
  _Bool Nor  = __builtin_bit_nor_reduce(Val);
  _Bool Xor  = __builtin_bit_xor_reduce(Val);
  _Bool Nxor = __builtin_bit_nxor_reduce(Val);
  printBits(Val, numbits);
  printf(", and=%d, nand=%d, or=%d, nor=%d, xor=%d, nxor=%d\n",
      And, Nand, Or, Nor, Xor, Nxor);
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

  showReduction(0);
  showReduction(1);
  showReduction(-1);

  for (i = 0; i < 128; i++) {
    unsigned long long num = rand();
    BitType Val = Y * num;
    showReduction(Val);
  }
  return 0;
}
