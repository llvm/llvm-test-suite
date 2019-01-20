//===--- trunc.c --- Test Cases for Bit Accurate Types --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is used to test trunc and sext instructions.
//
//===----------------------------------------------------------------------===//

#include <stdio.h>

typedef int __attribute__ ((bitwidth(24))) int24;

int
test(int24 v)
{
  int y;

  y = v * (-1);
  printf("test() y = %d\n", y);

  return 0;
}

int
main ( int argc, char** argv)
{
  int num;
  int24 x;
  
  if (argc > 1)
    num = atoi(argv[1]);

  test(num);
  
  num = num - 0xdf5e75; //0x10001

  x = num;

  printf("x=%x\n", x);

  if(x != 1)
    printf("error\n");

  test(x);
  
  return 0;
}
