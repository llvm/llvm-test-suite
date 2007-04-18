//===--- constval.c - Test constant APInt values --------------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a general test parsing constant APInt values
//
//===----------------------------------------------------------------------===//

#include "bits.h"
#include <stdio.h>

void my_test()
{
  uint21 x = bitsFromString("123456", 21);
  uint16 y = bitsFromString("123456", 16);
  printf( "x = %d\n", int(x));
  printf( "y = %d\n", int(y));
}

int main(int argc, char** argv)
{
  my_test();
  return 0;
}

