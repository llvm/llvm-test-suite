//===--- bitlogic.c --- Test Cases for Bit Accurate Types -----------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a general test for logical operations.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/APInt.h"
#include <stdio.h>

using namespace llvm;

int my_test()
{
  APInt x(0x1, 1);
  APInt y(0, 1);
  APInt z(0x1ff, 9);
  APInt uz(0x1ff, 9);
  APInt temp(0, 9);
  y = x;
  y -= 1;
  if (!y)
    printf("ok\n");
  else 
    printf("fail\n");
  
  if (y > x)
    printf("fail\n");
  else 
    printf("ok\n");
  
  if (z != uz)
    printf("ok\n");
  else 
    printf("fail\n");
  
  temp = z;
  if (temp <= uz)
    printf("ok\n");
  else 
    printf("fail\n");
  
  return 0;

}

int main()
{
  my_test();
  return 0;
}

