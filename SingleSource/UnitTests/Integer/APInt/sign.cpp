//===--- sign.c --- Test Cases for Bit Accurate Types --------------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a general test for arithmetic operations with signed and
// unsigned operands.
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/APInt.h"
#include <stdio.h>

using namespace llvm;

int
main ( int argc, char** argv)
{
  int num, r;
  APInt x(0, 24, true), y(0, 24, true), z(0, 24, true);
  APInt ux(0, 24), uy(0, 24), uz(0, 24);

  r = rand();
  r = r - 1804289384; // -1

  y = r; // -1
  uy = r; // 0xffffff
  
  if (argc > 1)
    num = atoi(argv[1]);

  
  num = num - 0xdf5e75; //0x1000001

  x = num;
  ux = num;
  printf("x = %d, ux = %u, y=%d, uy = %u\n", int(x.getValue()), 
         (unsigned int)ux.getValue(), int(y.getValue()), 
         (unsigned int)uy.getValue());
    
  z = x * y;  // 0x1000001 * (-1)
  uz = ux * uy;
  printf("z=%d, uz=%u\n", int(z.getValue()), (unsigned int)uz.getValue());

  z = x % 314;
  uz = ux % 314;
  printf("z=%d, uz=%u\n", int(z.getValue()), (unsigned int)uz.getValue());

  z = x / 314;
  uz = ux / 314;
  printf("z=%d, uz=%u\n", int(z.getValue()), (unsigned int)uz.getValue());

  z = (x+0xf28) / 314;
  uz = (ux + 0xf28) / 314;
  printf("z=%d, uz=%u\n", int(z.getValue()), (unsigned int)uz.getValue());

  z = (x - 580) / 314;
  uz = (((ux - 580)) / 314);
  printf("z=%d, uz=%u\n", int(z.getValue()), (unsigned int)uz.getValue());

  return 0;
}
