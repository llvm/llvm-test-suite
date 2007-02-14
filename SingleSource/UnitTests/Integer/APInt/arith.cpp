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
#include <stdlib.h>

using namespace llvm;

APInt x(0x1fffff, 21);

APInt y(0x0fffff, 21);

static std::string temp_str;

const char* str(const APInt& X) {
  temp_str = X.to_string();
  return temp_str.c_str(); 
}

void test_interface(const APInt &val) {
  printf("INTERFACE TEST: val = %s\n", str(val));
  unsigned bitwidth = val.getNumBits();
  unsigned pos = rand() % bitwidth;
  printf("val[%u] = %d\n", pos, val[pos]);
  APInt smax = APInt::getMaxValue(bitwidth, true);
  APInt umax = APInt::getMaxValue(bitwidth, false);
  APInt smin = APInt::getMinValue(bitwidth, true);
  APInt umin = APInt::getMinValue(bitwidth, false);
  printf("APInt::getMaxValue(%d, true)  = %s\n", bitwidth, str(smax));
  printf("APInt::getMaxValue(%d, false) = %s\n", bitwidth, str(umax));
  printf("APInt::getMinValue(%d, true)  = %s\n", bitwidth, str(smin));
  printf("APInt::getMinValue(%d, false) = %s\n", bitwidth, str(umin));
  APInt null = APInt::getNullValue(bitwidth);
  APInt allone = APInt::getAllOnesValue(bitwidth);
  printf("APInt::getNullValue(%d) = %s\n", bitwidth, str(umin));
  printf("APInt::getAllOnesValue(%d) = %s\n", bitwidth, str(umin));
  APInt x(val);
  x.set(pos);
  printf("val.set(%d) = %s\n", pos, str(x));
  x.set();
  printf("val.set() = %s\n", str(x));
  x = val;
  x.clear(pos);
  printf("val.clear(%d) = %s\n", pos, str(x));
  x.clear();
  printf("val.clear() = %s\n", str(x));
  x = val;
  x.flip(pos);
  printf("val.flip(%d) = %s\n", pos, str(x));
  x = val;
  x.flip();
  printf("val.flip() = %s\n", str(x));
  unsigned bitsize = bitwidth / 2;
  printf("val.HiBits(%d) = %s\n", bitsize, str(val.HiBits(bitsize)));
  printf("val.LoBits(%d) = %s\n", bitsize, str(val.LoBits(bitsize)));
  printf("val.IsIntN(%d) = %d\n", bitsize, str(val.IsIntN(bitsize)));
}

void test_unops(const APInt &val) {
  printf("UNARY OPERATORS TEST: val = %s\n", str(val));
  APInt x(val);
  x++;
  printf("val++ = %s\n", str(x));
  x = val;
  ++x;
  printf("++val = %s\n", str(x));
  x = val;
  x--;
  printf("val-- = %s\n", str(x));
  x = val;
  --x;
  printf("--val = %s\n", str(x));
  x = -val;
  printf("-val = %s\n", str(x));
  x = ~val;
  printf("~val = %s\n", str(x));
  printf("!val = %d\n", !val);
  printf("val.isPowerOf2() = %d\n", val.isPowerOf2());
  printf("val.LogBase2() = %d\n", val.getNumBits());
  printf("val.CountLeadingZeros() = %d\n", val.CountLeadingZeros());
  printf("val.CountTrailingZeros() = %d\n", val.CountTrailingZeros());
  printf("val.CountPopulation() = %d\n", val.CountPopulation());
  printf("val.getNumBits() = %d\n", val.getNumBits());
  if (val.getNumBits() >= 16 && val.getNumBits() % 16 == 0) {
    // FIXME: ByteSwap crashes!
    // x = val.ByteSwap();
    printf("val.ByteSwap() = %d\n", str(x));
  }
  printf("val.RoundToDouble(true) %d = %f\n", val.RoundToDouble(true));
  printf("val.getValue() = ");
  if (val.getNumBits() > 64)
    printf("too wide\n");
  else
    printf("%ul\n", val.getValue());
}

void test_binops(const APInt &v1, const APInt &v2) {
  printf("BINARY OPERATORS TEST: vl = %s, v2 = %s\n", str(v1), str(v2));
  APInt result(v1);
  result &= v2;
  printf("v1 &= v2: %s\n", str(result));
  result = v1;
  result |= v2;
  printf("v1 |= v2: %s\n", str(result));
  result = v1;
  result ^= v2;
  printf("v1 ^= v2: %s\n", str(result));
  result = v1;
  result *= v2;
  printf("v1 *= v2: %s\n", str(result));
  result = v1;
  result += v2;
  printf("v1 += v2: %s\n", str(result));
  result = v1;
  result -= v2;
  printf("v1 -= v2: %s\n", str(result));
  result = v1 & v2;
  printf("v1 &  v2: %s\n", str(result));
  result = v1 | v2;
  printf("v1 |  v2: %s\n", str(result));
  result = v1 ^ v2;
  printf("v1 ^  v2: %s\n", str(result));
  result = v1 && v2;
  printf("v1 && v2: %s\n", str(result));
  result = v1 || v2;
  printf("v1 || v2: %s\n", str(result));
  result = v1 * v2;
  printf("v1 *  v2: %s\n", str(result));
  result = v1 + v2;
  printf("v1 +  v2: %s\n", str(result));
  result = v1 - v2;
  printf("v1 -  v2: %s\n", str(result));
  printf("v1 == v2: %d\n", v1 == v2);
  printf("v1 != v2: %d\n", v1 == v2);
  printf("v1 <  v2: %d\n", v1 == v2);
  printf("v1 <= v2: %d\n", v1 == v2);
  printf("v1 >  v2: %d\n", v1 == v2);
  printf("v1 >= v2: %d\n", v1 == v2);
  {
    using namespace APIntOps;
    unsigned shiftAmt = rand() % v1.getNumBits();
    result = AShr(v1,shiftAmt);
    printf("AShr(v1,%d) = %s\n", shiftAmt, str(result));
    result = LShr(v1,shiftAmt);
    printf("LShr(v1,%d) = %s\n", shiftAmt, str(result));
    result = Shl(v1,shiftAmt);
    printf("Shl(v1,%d) = %s\n", shiftAmt, str(result));
    if (v2 == 0)
      printf("SDiv/UDiv/SRem/URem not tested, v2 == 0\n");
    else {
      result = SDiv(v1,v2);
      printf("SDiv(v1,v2) = %s\n", str(result));
      result = UDiv(v1,v2);
      printf("UDiv(v1,v2) = %s\n", str(result));
      result = SRem(v1,v2);
      printf("SRem(v1,v2) = %s\n", str(result));
      result = URem(v1,v2);
      printf("URem(v1,v2) = %s\n", str(result));
    }
  }
}

void test_multiple() {
  srand(0);
  for (unsigned bits = 1; bits <= 1024; ++bits) {
    APInt v1(0u, bits);
    APInt v2(0u, bits);
    for (unsigned i = 0; i < bits; ++i) {
      unsigned bit = rand() % 2;
      v1.Shl(1);
      v1 |= bit;
    }
    for (unsigned i = 0; i < bits; ++i) {
      unsigned bit = rand() % 2;
      v2.Shl(1);
      v2 |= bit;
    }
    test_interface(v1);
    test_unops(v2);
    test_binops(v1,v2);
  }
}

int main()
{
  test_multiple();
  return 0;
}

