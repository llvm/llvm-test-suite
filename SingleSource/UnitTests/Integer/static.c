//===--- static.c --- Test Cases for Bit Accurate Types -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for static data with non-regular integral data.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(31))) int31;

int31 test(int31 y, int31* z)
{
  static int31 x = 0;
  *z =  x;
  x = y;
  return x;
}

int main()
{
  int31 a, b;
  a = test(1, &b);
  if(b != 0 || a != 1)
    printf("error\n");
  a = test(-1, &b);
  if(b != 1 || a != -1)
    printf("error\n");
  return 0;
    
}
