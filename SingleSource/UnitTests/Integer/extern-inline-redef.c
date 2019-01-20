//===--- extern_inline_redef.c --- Test Cases for Bit Accurate Types ------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// this is used to test redefining inline function.  
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(61))) int61;

extern __inline int61
  __strtol_l (int a)
{
  return 0;
}

int61
  __strtol_l (int a)
{
  return 0;
}

int main()
{
  return 0;
}
