//===--- union-init.c --- Test Cases for Bit Accurate Types ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for union initialization.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;

struct Foo {
  int33 a;
  int33 b;
  int33 c;
};

struct Bar {
  union {
    void **a;
    struct Foo b;
  }u;
};

struct Bar test = {0};

int main()
{
  if(test.u.b.a != 0)
    printf("error: a = %d\n", test.u.b.a);
  if(test.u.b.b != 0)
    printf("error: a = %d\n", test.u.b.b);
  if(test.u.b.c != 0)
    printf("error: a = %d\n", test.u.b.c);
  printf("%p\n", test.u.a);
    
  return 0;
}
