//===--- pointer.c --- Test Cases for Bit Accurate Types ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for address calculation with non-regular integral type.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(3))) int3;
typedef int __attribute__ ((bitwidth(31))) int31;

int3 *test(int3* C)
{
  return C-1;   
}

int31 *test2(int31* I)
{
  return I-1;
}

int main()
{
  int3 i3;
  int31 i31;

  if(&i3 != (test(&i3) + 1))
    printf("error\n");
    
  if(&i31 != (test2(&i31)+1))
    printf("error2: &i31=%p, ret = %p\n", &i31, test2(&i31));

  return 0;
}
