//===--- struct2.c --- Test Cases for Bit Accurate Types ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for struct data structure. We test the nested structure
// and pointer to structure.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;
typedef int __attribute__ ((bitwidth(9))) int9;

typedef struct min_info {
  int33 offset;
  int9 file_attr;
} min_info;

typedef struct Globals {
  char answerbuf;
  min_info info[1];
  min_info *pInfo;
} Uz_Globs;

Uz_Globs G;

int assign() {  
  G.pInfo = G.info;
}

int main()
{
  assign();
  if(G.pInfo != G.info)
    printf("error\n");

  return 0;
}
