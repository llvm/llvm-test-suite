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

void print(const APInt& X, bool wantSigned = false, bool withNL = true) {
  std::string decstr = X.toString(10,wantSigned);
  std::string hexstr = X.toString(16,false);
  printf("%s (%s)", decstr.c_str(), hexstr.c_str());
  if (withNL)
    printf("\n");
}

APInt randomAPInt(unsigned bits) {
  APInt val(bits, 0u);
  for (unsigned i = 0; i < bits; ++i) {
    unsigned bit = rand() % 2;
    val = val.shl(1);
    val |= APInt(bits, bit);
  }
  return val;
}

void test_interface(const APInt &val) {
  printf("INTERFACE TEST: val = "); print(val);
  unsigned bitwidth = val.getBitWidth();
  unsigned pos = rand() % bitwidth;
  printf("val[%u] = %d\n", pos, val[pos]);
  APInt smax(APInt::getMaxValue(bitwidth, true));
  APInt umax(APInt::getMaxValue(bitwidth, false));
  APInt smin(APInt::getMinValue(bitwidth, true));
  APInt umin(APInt::getMinValue(bitwidth, false));
  printf("APInt::getMinValue(%d, true)  = ", bitwidth); print(smin,true);
  printf("APInt::getMaxValue(%d, true)  = ", bitwidth); print(smax,true);
  printf("APInt::getMinValue(%d, false) = ", bitwidth); print(umin);
  printf("APInt::getMaxValue(%d, false) = ", bitwidth); print(umax);
  APInt null = APInt::getNullValue(bitwidth);
  APInt allone = APInt::getAllOnesValue(bitwidth);
  printf("APInt::getNullValue(%d) = ", bitwidth); print(null);
  printf("APInt::getAllOnesValue(%d) = ", bitwidth); print(allone);
  APInt x(val);
  x.set(pos);
  printf("val.set(%d) = ", pos);  print(x);
  x.set();
  printf("val.set() = "); print(x);
  x = val;
  x.clear(pos);
  printf("val.clear(%d) = ", pos);  print(x);
  x.clear();
  printf("val.clear() = "); print(x);
  x = val;
  x.flip(pos);
  printf("val.flip(%d) = ", pos); print(x);
  x = val;
  x.flip();
  printf("val.flip() = "); print(x);
  unsigned bitsize = bitwidth / 2;
  printf("val.getHiBits(%d) = ", bitsize); print(val.getHiBits(bitsize));
  printf("val.getLoBits(%d) = ", bitsize); print(val.getLoBits(bitsize));
  printf("val.isIntN(%d) = %d\n", bitwidth, val.isIntN(bitwidth));
}

void test_unops(const APInt &val) {
  printf("UNARY OPERATORS TEST: val = "); print(val);
  APInt x(val);
  x++;
  printf("val++ = "); print(x);
  x = val;
  ++x;
  printf("++val = "); print(x);
  x = val;
  x--;
  printf("val-- = "); print(x);
  x = val;
  --x;
  printf("--val = "); print(x);
  x = -val;
  printf("-val = "); print(x);
  x = ~val;
  printf("~val = "); print(x);
  printf("!val = %d\n", !val);
  printf("val.isPowerOf2() = %d\n", val.isPowerOf2());
  printf("val.logBase2() = %d\n", val.logBase2());
  printf("val.countLeadingZeros() = %d\n", val.countLeadingZeros());
  printf("val.countTrailingZeros() = %d\n", val.countTrailingZeros());
  printf("val.countPopulation() = %d\n", val.countPopulation());
  printf("val.getBitWidth() = %d\n", val.getBitWidth());
  if (val.getBitWidth() >= 16 && val.getBitWidth() % 16 == 0) {
    x = val.byteSwap();
    printf("val.byteSwap() = "); print(x);
  }
  printf("val.roundToDouble(false) = %f\n", val.roundToDouble(false));
  printf("val.roundToDouble(true)  = %f\n", val.roundToDouble(true));
  printf("val.getValue() = ");
  if (val.getBitWidth() > 64)
    printf("too wide\n");
  else
    printf("%lu\n", val.getValue());
}

void test_binops(const APInt &v1, const APInt &v2) {
  printf("BINARY OPERATORS TEST: \n      vl: "); print(v1,false,false);
  printf("\n      v2: "); print(v2);
  APInt result(v1);
  result &= v2;
  printf("v1 &= v2: "); print(result);
  result = v1;
  result |= v2;
  printf("v1 |= v2: "); print(result);
  result = v1;
  result ^= v2;
  printf("v1 ^= v2: "); print(result);
  result = v1;
  result *= v2;
  printf("v1 *= v2: "); print(result);
  result = v1;
  result += v2;
  printf("v1 += v2: "); print(result);
  result = v1;
  result -= v2;
  printf("v1 -= v2: "); print(result);
  result = v1 & v2;
  printf("v1 &  v2: "); print(result);
  result = v1 | v2;
  printf("v1 |  v2: "); print(result);
  result = v1 ^ v2;
  printf("v1 ^  v2: "); print(result);
  result = v1 * v2;
  printf("v1 *  v2: "); print(result);
  result = v1 + v2;
  printf("v1 +  v2: "); print(result);
  result = v1 - v2;
  printf("v1 -  v2: "); print(result);
  printf("v1 == v2: %d\n", v1 == v2);
  printf("v1 != v2: %d\n", v1 != v2);
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
    printf("ashr(v1,%d) = ", shiftAmt); print(result);
    result = lshr(v1,shiftAmt);
    printf("lshr(v1,%d) = ", shiftAmt); print(result);
    result = shl(v1,shiftAmt);
    printf("shl(v1,%d) = ", shiftAmt); print(result);
    if (v2 == APInt(v2.getBitWidth(), 0))
      printf("sdiv/udiv/srem/urem not tested, v2 == 0\n");
    else {
      result = sdiv(v1,v2);
      printf("sdiv(v1,v2) = "); print(result);
      result = udiv(v1,v2);
      printf("udiv(v1,v2) = "); print(result);
      result = srem(v1,v2);
      printf("srem(v1,v2) = "); print(result);
      result = urem(v1,v2);
      printf("urem(v1,v2) = "); print(result);
    }
  }
}

void test_multiple() {
  srand(0);
  for (unsigned bits = 1; bits <= 256; ++bits) {
    printf("\nTEST CASE: %d BITS\n\n", bits);
    APInt zero(bits,0);
    APInt one(bits,1);
    if (bits == 1) {
      test_interface(zero);
      test_interface(one);
      test_unops(zero);
      test_unops(one);
      test_binops(zero,one);
      test_binops(one,zero);
      continue;
    }
    APInt two(bits,1);
    APInt three(bits,1);
    APInt min = APInt::getMinValue(bits, true);
    APInt max = APInt::getMaxValue(bits, true);
    APInt mid = APIntOps::lshr(max, bits/2);
    APInt r1 = randomAPInt(bits);
    APInt r2 = randomAPInt(bits);
    APInt *list[9];
    list[0] = &zero;
    list[1] = &one;
    list[2] = &two;
    list[3] = &three;
    list[4] = &min;
    list[5] = &r1;
    list[6] = &mid;
    list[7] = &r2;
    list[8] = &max;
    for (unsigned i = 0; i < 9; ++i) {
      test_interface(*(list[i]));
      test_unops(*(list[i]));
    }
    for (unsigned i = 0; i < 9; ++i) {
      for (unsigned j = 0; j < 9; ++j) {
        test_binops(*(list[i]), *(list[j]));
      }
    }
  }
}

int main()
{
  APInt X(48, 100);
  APInt Y(48, 10);
  APInt Q(1,0);
  APInt R(1,0);
  APInt::divide(X, 1, Y, 1, &Q, &R);
  test_multiple();
  return 0;
}

