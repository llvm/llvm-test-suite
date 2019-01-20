//===--- SSAtest.c --- Test Cases for Bit Accurate Types ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Adopted the test from previous test-cases. Changed it with
// non-regular int data type.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(4))) int4;

int4 bar()
{
    return 0xf;
}

int4 foo()
{
  int4 a,b,c;
  b = 0;
  c = 0;
  a = b + c;
  b = bar();
  c = bar();
  printf("result = %d\n", a + b + c);
}


int main()
{
  foo();
  return 0;
}
