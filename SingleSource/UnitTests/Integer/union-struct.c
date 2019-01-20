//===--- union-struct.c --- Test Cases for Bit Accurate Types -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for struct with union inside. The purpose is to see
// whether the size of the structure is correct.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(31))) int31;

struct Blend_Map_Entry {
  union {
    float Colour[5];
    double Point_Slope[2];
    int31  weight[5];
  } Vals;
};



int main()
{
  if( sizeof(struct Blend_Map_Entry) != 5 * sizeof(int) )
    printf("error: %d\n", sizeof(struct Blend_Map_Entry));
  return 0;
}
