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

typedef unsigned int __attribute__((bitwidth(17))) BitType1;
typedef unsigned int __attribute__((bitwidth(19))) BitType2;
typedef unsigned long long __attribute__((bitwidth(36))) ConcatType;
int numbits1 = 17;
int numbits2 = 19;

void printBits(ConcatType val, int numbits ) {
  int j;
  for (j = numbits; j > 0; --j) {
    if (__builtin_bit_select(val, j))
      printf("1");
    else
      printf("0");
  }
}

int main(int argc, char** argv)
{
  BitType1 X = 0;
  BitType2 Y = 0;
  ConcatType Z = 0;
  int i, j;
  int count = (argc > 1 ? atoi(argv[1]) % 128 : 128);

  srand(count);

  for (i = 0; i < count; i++) {
    Y = X = 0;
    for (j = 0; j < numbits1; j++) {
      X += (rand() % 2 == 0 ? 0 : 1);
      X <<= 1;
    }
    for (j = 0; j < numbits2; j++) {
      Y += (rand() % 2 == 0 ? 0 : 1);
      Y <<= 1;
    }
    Z = __builtin_bit_concat(X, Y);
    printf("bit_concat(");
    printBits(X, numbits1);
    printf(",");
    printBits(Y, numbits2);
    printf(") = ");
    printBits(Z, numbits1 + numbits2);
    printf("\n");
  }
  return 0;
}
