//===--- bigint.c --- Test Cases for Bit Accurate Types -------------------===//
//
// This file was developed by Guoling Han and is distributed under the 
// University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is a general test for big integer type.
//
//===----------------------------------------------------------------------===//
#include <llvm/ADT/APInt.h>
#include <stdio.h>

using namespace llvm;

const APInt bnd(1023, 10);


APInt x(0xffffffffULL, 169);
APInt y(-0xabcdefdeULL, 169);

int my_test()
{
  APInt i(uint64_t(0), 10);
  APInt result(0, 169);
  APInt l_result(0, 32);
  long long rem;
  long long rem2;
  {
    ;
    for ( ; ; ) {
      bool ssdm_tmp_1 = (i < bnd);
      if (!ssdm_tmp_1) break;
      if (i % 2 == 0)
        x = x + 1;
      else 
        y = y - x;
    
      ++i;
    }
  }
  result = x*y;
  l_result = result % 0x37015; 
  rem = l_result.getValue();
  printf("rem = %lld\n", rem);

  l_result = result % -198721;
  rem2 = l_result.getValue();
  printf("rem2 = %lld\n", rem2);
  return 0;
}

int main()
{
  my_test();
  return 0;
}



