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

#include "bits.h"
#include <stdio.h>

typedef enum bool{false=0, true=1} bool;

const uint10 bnd = 1023;


int169 x = 0xffffffffULL;
int169 y = -0xabcdefdeULL;

int my_test()
{
  uint10 i = 0;
  int169 result;
  int32 l_result;
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
  rem = l_result;
  printf("rem = %lld\n", rem);

  l_result = result % -198721;
  rem2 = l_result;
  printf("rem2 = %lld\n", rem2);
  return 0;
}

int main()
{
  my_test();
  return 0;
}



