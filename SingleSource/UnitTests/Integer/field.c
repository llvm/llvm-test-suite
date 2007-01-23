//===--- field.c --- Test Cases for Bit Accurate Types --------------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is used to test struct with field specifier. We suppose the
// data layout of the field should be the same as the corresponding
// struct using bit accurate types.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>


typedef int __attribute__ ((bitwidth(7))) int7;
typedef int __attribute__ ((bitwidth(17))) int17;
typedef int __attribute__ ((bitwidth(32))) int32;
typedef int __attribute__ ((bitwidth(8))) int8;

typedef long __attribute__ ((bitwidth(33))) long33;
typedef char __attribute__ ((bitwidth(7))) char7;
typedef short __attribute__ ((bitwidth(17))) short17;

typedef struct myStruct{int i; unsigned char c:7; int s:17; char c2;} myStruct;

typedef struct myStruct2{int32 i; int7 c;  int17 s; int8 c2;} myStruct2;

int main()
{
  myStruct x;
  myStruct2 y;

  void* ptr, *ptr1, *ptr2, *ptr3;
  unsigned int offset, offset1;

  ptr = &(x.i);
  ptr1 = &(x.c2);

  ptr2 = &(y.i);
  ptr3 = &(y.c2);

  offset = ptr1 - ptr;
  offset1 = ptr3 - ptr2;
    
  if(offset != offset1) 
    printf("error: offset=%x, offset1=%x\n", offset, offset1);
  if(sizeof(myStruct) != sizeof(myStruct2))
    printf("error2: sizeof myStruct = %d, sizeof myStruct2 = %d\n",
           sizeof(myStruct), sizeof(myStruct2));

  return 0;
}
