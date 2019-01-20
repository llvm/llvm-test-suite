//===--- sign.c --- Test Cases for Bit Accurate Types --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a general test for arithmetic operations with signed and
// unsigned operands.
//
//===----------------------------------------------------------------------===//

#include <stdio.h>

typedef int __attribute__ ((bitwidth(24))) int24;
typedef unsigned int __attribute__ ((bitwidth(24))) uint24;


int
main ( int argc, char** argv)
{
  int num, r;
  int24 x, y, z;
  uint24 ux, uy, uz;

  r = rand();
  r = r - 1804289384; // -1

  y = r; // -1
  uy = r; // 0xffffff
  
  if (argc > 1)
    num = atoi(argv[1]);

  
  num = num - 0xdf5e75; //0x1000001

  x = num; // = 1
  ux = num; // = 1
  printf("x = %d, ux = %u, y=%d, uy = %u\n", x, ux, y, uy);
    
  z = x * y;     // 0x1000001 * -1
  uz = ux * uy;  // 1 * -1
  printf("z=%d, uz=%u\n", z, uz);

  z = x % 314;   // 0x1000001 % 314
  uz = ux % 314; // 1 % 314 == 1
  printf("z=%d, uz=%u\n", z, uz);

  z = x / 314;
  uz = ux / 314;
  printf("z=%d, uz=%u\n", z, uz);

  z = (x+0xf28) / 314;
  uz = (ux + 0xf28) / 314;
  printf("z=%d, uz=%u\n", z, uz);

  z = (x - 580) / 314;
  uz = (uint24)(((uint24)(ux - (uint24)580)) / (uint24)314);
  printf("z=%d, uz=%u\n", z, uz);

  return 0;
}
