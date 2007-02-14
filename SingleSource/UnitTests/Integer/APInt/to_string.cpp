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
  for (unsigned i = 1; i < 128; i += 3) {
    APInt x(0, i);
    APInt y(1, i);
    unsigned randval = rand();
    APInt z(randval, i);
    std::string x_str = x.to_string();
    std::string y_str = y.to_string();
    std::string z_str = z.to_string();
    printf("APInt(0, %d) = %s\n", i, x_str.c_str());
    printf("APInt(1, %d) = %s\n", i, y_str.c_str());
    printf("APInt(%d, %d) = %s\n", randval, i, z_str.c_str());
  }
}
