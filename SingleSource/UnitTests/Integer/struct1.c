//===--- struct1.c --- Test Cases for Bit Accurate Types ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for struct data structure. If the data layout for
// non-regular bitwidth data is not correct, it may change the value of 
// another field.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;

struct foo A;
struct foo {
  int33 x;
  double D;
};

int main()
{
  A.D = -3.141593;
  A.x = -1;
  printf("%f\n", A.D);
    
  return 0;
}
