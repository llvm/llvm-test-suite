//===--- arith.c --- Test Cases for Bit Accurate Types --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a general test for arithmetic operations.
//
//===----------------------------------------------------------------------===//

#include "bits.h"
#include <stdio.h>


int21 x = 0x1fffff;

int21 y = 0x0fffff;



int my_test()
{
  uint10 i = 0;
  int10 j;
  int10 k;
  int10 l;
  int21 result;
  short temp;
  int i_temp;
  unsigned int ui_x;
  unsigned int ui_y;
  j = i;
  j -= 1;
  temp = j;
  printf( "temp = %hd\n", temp);
  k = i;
  k += 1;
  temp = k;
  printf( "temp = %hd\n", temp);
  k = j * k;
  temp = k;
  printf( "temp = %hd\n", temp);
  j *= 120;
  l = j / k;
  temp = l;
  printf( "temp = %hd\n", temp);
  j *= (-176); // after truncation, the value should be -384
  l = j / k;
  temp = l;
  printf( "temp = %hd\n", temp);
  l = 120;
  l = (j * l);
  l %= 4;
  temp = l;
  printf( "temp = %hd\n", temp);
  l = -217;
  l = (j * l);
  l = l / (++i);
  temp = l;
  printf( "temp = %hd\n", temp);
  result = ++x;
  
  i_temp = result;
  printf( "i_temp = %x\n", i_temp);
  x--;
 
  result = x + y;
  i_temp = result;
  printf("i_temp = %x\n", i_temp);
  ui_x = x;
  ui_y = y;
  i_temp = ui_x - ui_y;
  printf("i_temp = %x\n", i_temp);

  return 0;

}

int main()
{
  my_test();
  return 0;
}

