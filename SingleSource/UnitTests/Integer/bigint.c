//===--- bigint.c --- Test Cases for Bit Accurate Types -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a general test for big integer type.
//
//===----------------------------------------------------------------------===//

#include "bits.h"
#include <stdio.h>

typedef enum bool{false=0, true=1} bool;

const uint10 bnd = 1023;


int500 x = -1;
int169 y = -0xabcdefdeULL;

int my_test()
{
  printf("Initially:\n");
  printf("int500 x = ");
  printBits(x);
  printf("\n");
  printf("int169 y = ");
  printBits(y);
  printf("\n");

  uint10 i = 0;
  int169 result;
  int32 l_result;
  long long rem;
  long long rem2;
  for ( i = 0 ; i < bnd ; ++i) {
    if (i % 2 == 0)
      x = x + 1;
    else 
      y = y - x;
  }

  printf("\nAfter modification:\n");
  printf("int500 x = ");
  printBits(x);
  printf("\n");
  printf("int169 y = ");
  printBits(y);
  printf("\n");

  printf("\nresult = x * y = ");
  result = x*y;
  printBits(result);
  printf("\n");

  l_result = result % 0x37015; 
  printf("\nresult %% 0x37015 = %d\n", l_result);

  l_result = result % -198721;
  printf("\nresult %% -198721 = %d\n", l_result);
  return 0;
}

int main()
{
  my_test();
  return 0;
}



