//===--- override.cpp --- Test Cases for Bit Accurate Types ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test of override test.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(31))) int31;
typedef int __attribute__ ((bitwidth(32))) int32;

void func(int32 i)
{
  printf("call func with int32: %d\n", (int)i);
}

void func(int31 s)
{
  printf("call func with int31: %d\n", (int)s);
}

int main()
{
  func( (int31) 1);
  func( (int32) 2);
  return 0;
}
