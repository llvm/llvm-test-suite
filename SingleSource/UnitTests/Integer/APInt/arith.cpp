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

APInt x(0x1fffff, 21);

APInt y(0x0fffff, 21);

int my_test()
{
  APInt i(uint64_t(0), 10);
  APInt j(0, 10);
  APInt k(0, 10);
  APInt l(0, 10);
  APInt result(0, 21);
  short temp;
  int i_temp;
  unsigned int ui_x;
  unsigned int ui_y;
  j = i;
  j -= 1;
  temp = (short)j.getValue();
  printf( "temp = %hd\n", temp);
  k = i;
  k += 1;
  temp = k.getValue();
  printf( "temp = %hd\n", temp);
  k = j * k;
  temp = k.getValue();
  printf( "temp = %hd\n", temp);
  j *= 120;
  l = APIntOps::sdiv(j, k);
  temp = l.getValue();
  printf( "temp = %hd\n", temp);
  j *= (-176); // after truncation, the value should be -384
  l = APIntOps::sdiv(j, k);
  temp = l.getValue();
  printf( "temp = %hd\n", temp);
  l = 120;
  l = (j * l);
  l = APIntOps::urem(l, 4);
  temp = l.getValue();
  printf( "temp = %hd\n", temp);
  l = -217;
  l = (j * l);
  l = APIntOps::sdiv(l, (++i));
  temp = l.getValue();
  printf( "temp = %hd\n", temp);
  result = ++x;
  
  i_temp = result.getValue();
  printf( "i_temp = %x\n", i_temp);
  x--;
 
  result = x + y;
  i_temp = result.getValue();
  printf("i_temp = %x\n", i_temp);
  ui_x = x.getValue();
  ui_y = y.getValue();
  i_temp = ui_x - ui_y;
  printf("i_temp = %x\n", i_temp);

  return 0;

}

int main()
{
  my_test();
  return 0;
}

