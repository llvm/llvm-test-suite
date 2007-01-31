//===--- convert.c --- Test Cases for Bit Accurate Types ------------------===//
//
// This file was developed by Reid Spencer and is distributed under the 
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
  APInt x(0,23);
  APInt y(0,23);
  int j = 32;

  x = y + 17;
  x += j;
  y = x - j;
  y += 17;

  // Should produce: 49 34
  printf("%d %d \n", (int)x.getValue(), (int)y.getValue());
}
