//===--- bit_select.c --- Test The bit_select builtin ---------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This test case tests the __builtin_bit_select builtin function llvm-gcc.
// bit_select selects one bit out of a larger 
//
//===----------------------------------------------------------------------===//

#include <stdio.h>
#include "bits.h"

#ifdef ENABLE_LARGE_INTEGERS
typedef uint250 BitType;
const BitType X = 0xAAAAAAAAAAAAAAAAULL;
#else
typedef uint47 BitType;
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

  printBits(Y);

  printf("\n");
  return 0;
}
