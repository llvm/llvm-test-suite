//===--- union2.c --- Test Cases for Bit Accurate Types -------------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a test for union type. By assigning values to different
// fields, we can check whether the assignment is correctly performed.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(9))) int9;
typedef int __attribute__ ((bitwidth(31))) int31;
typedef union {short i; int9 i9; int31 i31;} myUnion;
typedef struct myStruct {int9* ptr; short i;} myStruct;

myStruct test(myUnion u)
{
  myStruct x;

  u.i31 = 0;
  u.i = 0xffff;
  int9* ptr = &(u.i9);
  *ptr= 0x00;

  x.ptr = ptr;
  x.i = u.i;

  return x;   
}

static myUnion uu;

int main()
{
  myStruct s = test(uu);
  if(s.i == 0x0)
    printf("error: s.i=%x\n", s.i);
  return 0;
}
