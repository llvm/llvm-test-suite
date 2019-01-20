//===--- offset.c --- Test Cases for Bit Accurate Types -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for data size calculation with non-regular integral type.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;

struct s { int33 field[0]; };

#define OFFS (((char *) &((struct s *) 0)->field[1]) - (char *) 0)

int foo[OFFS];

int main()
{
  printf("%d\n", OFFS);
  return 0;
}
