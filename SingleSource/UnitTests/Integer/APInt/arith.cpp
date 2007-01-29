//===--- arith.c --- Test Cases for Bit Accurate Types --------------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a general test for arithmetic operations.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/APInt.h"
#include <stdio.h>

using namespace llvm;

APInt x(21,0x1fffff);

APInt y(21,0x0fffff);

int my_test()
{
  APInt i(10,uint64_t(0));
  APInt j(10);
  APInt k(10);
  APInt l(10);
  APInt result(21);
  short temp;
  int i_temp;
  unsigned int ui_x;
  unsigned int ui_y;
  j = i;
  j -= 1;
  temp = (short)j;
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

