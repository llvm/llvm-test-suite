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

APInt x(21, 0x1fffff);

APInt y(21, 0x0fffff);

static std::string temp_str;

const char* str(const APInt& X) {
  temp_str = X.toString();
  return temp_str.c_str(); 
}

void test_interface(const APInt &val) {
  printf("INTERFACE TEST: val = %s\n", str(val));
  unsigned bitwidth = val.getBitWidth();
  unsigned pos = rand() % bitwidth;
  printf("val[%u] = %d\n", pos, val[pos]);
  APInt smax(APInt::getMaxValue(bitwidth, true));
  APInt umax(APInt::getMaxValue(bitwidth, false));
  APInt smin(APInt::getMinValue(bitwidth, true));
  APInt umin(APInt::getMinValue(bitwidth, false));
  printf("APInt::getMaxValue(%d, true)  = %s\n", bitwidth, str(smax));
  printf("APInt::getMaxValue(%d, false) = %s\n", bitwidth, str(umax));
  printf("APInt::getMinValue(%d, true)  = %s\n", bitwidth, str(smin));
  printf("APInt::getMinValue(%d, false) = %s\n", bitwidth, str(umin));
  APInt null = APInt::getNullValue(bitwidth);
  APInt allone = APInt::getAllOnesValue(bitwidth);
  printf("APInt::getNullValue(%d) = %s\n", bitwidth, str(null));
  printf("APInt::getAllOnesValue(%d) = %s\n", bitwidth, str(allone));
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
  printf("val.getHiBits(%d) = %s\n", bitsize, str(val.getHiBits(bitsize)));
  printf("val.getLoBits(%d) = %s\n", bitsize, str(val.getLoBits(bitsize)));
  printf("val.isIntN(%d) = %d\n", bitwidth, val.isIntN(bitwidth));
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
  printf("val.logBase2() = %d\n", val.logBase2());
  printf("val.countLeadingZeros() = %d\n", val.countLeadingZeros());
  printf("val.countTrailingZeros() = %d\n", val.countTrailingZeros());
  printf("val.countPopulation() = %d\n", val.countPopulation());
  printf("val.getBitWidth() = %d\n", val.getBitWidth());
  if (val.getBitWidth() >= 16 && val.getBitWidth() % 16 == 0) {
    x = val.byteSwap();
    printf("val.byteSwap() = %d\n", str(x));
  }
  printf("val.roundToDouble(true) %d = %f\n", val.roundToDouble(true));
  printf("val.getValue() = ");
  if (val.getBitWidth() > 64)
    printf("too wide\n");
  else
    printf("%lu\n", val.getValue());
}

void test_binops(const APInt &v1, const APInt &v2) {
  printf("BINARY OPERATORS TEST: vl = %s, ", str(v1));
  printf("v2 = %s\n", str(v2));
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
  result = v1 * v2;
  printf("v1 *  v2: %s\n", str(result));
  result = v1 + v2;
  printf("v1 +  v2: %s\n", str(result));
  result = v1 - v2;
  printf("v1 -  v2: %s\n", str(result));
  printf("v1 == v2: %d\n", v1 == v2);
  printf("v1 != v2: %d\n", v1 == v2);
  printf("v1.eq(v2): %d\n", v1.eq(v2));
  printf("v1.ne(v2): %d\n", v1.ne(v2));
  printf("v1.ult(v2): %d\n", v1.ult(v2));
  printf("v1.slt(v2): %d\n", v1.slt(v2));
  printf("v1.ule(v2): %d\n", v1.ule(v2));
  printf("v1.sle(v2): %d\n", v1.sle(v2));
  printf("v1.ugt(v2): %d\n", v1.ugt(v2));
  printf("v1.sgt(v2): %d\n", v1.sgt(v2));
  printf("v1.uge(v2): %d\n", v1.uge(v2));
  printf("v1.sge(v2): %d\n", v1.sge(v2));
  {
    using namespace APIntOps;
    unsigned shiftAmt = rand() % v1.getBitWidth();
    result = ashr(v1,shiftAmt);
    printf("ashr(v1,%d) = %s\n", shiftAmt, str(result));
    result = lshr(v1,shiftAmt);
    printf("lshr(v1,%d) = %s\n", shiftAmt, str(result));
    result = shl(v1,shiftAmt);
    printf("shl(v1,%d) = %s\n", shiftAmt, str(result));
    if (v2 == 0)
      printf("sdiv/udiv/srem/urem not tested, v2 == 0\n");
    else {
      result = sdiv(v1,v2);
      printf("sdiv(v1,v2) = %s\n", str(result));
      result = udiv(v1,v2);
      printf("udiv(v1,v2) = %s\n", str(result));
      result = srem(v1,v2);
      printf("srem(v1,v2) = %s\n", str(result));
      result = urem(v1,v2);
      printf("urem(v1,v2) = %s\n", str(result));
    }
  }
}

void test_multiple() {
  srand(0);
  for (unsigned bits = 1; bits <= 1024; ++bits) {
    APInt v1(bits, 0u);
    APInt v2(bits, 0u);
    for (unsigned i = 0; i < bits; ++i) {
      unsigned bit = rand() % 2;
      v1 = v1.shl(1);
      v1 |= APInt(bits, bit);
    }
    for (unsigned i = 0; i < bits; ++i) {
      unsigned bit = rand() % 2;
      v2 = v2.shl(1);
      v2 |= APInt(bits, bit);
    }
    printf("\nTEST CASE: %d bits\n\n", bits);
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

