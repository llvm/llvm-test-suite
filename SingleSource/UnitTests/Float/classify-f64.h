//===--- classify-f64.h - Tests for 'double' classification -------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains tests of classification functions for 'double' type.
//
//===----------------------------------------------------------------------===//
#ifndef _CLASSIFY_F64_H_
#define _CLASSIFY_F64_H_

#include "check-helper.h"
#include "fformat.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define INT_FORMAT   PRIx64
#define FLOAT_FORMAT "g"
#define VAL_FORMAT   INT_FORMAT
#define INT_TYPE     uint64_t
#define FLOAT_TYPE   double

uint64_t DoubleQNaNValues[] = {
    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | F64_PAYLOAD_MASK),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | F64_PAYLOAD_MASK),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | 0x0004000000000000ULL),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | 0x0002000000000000ULL),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | 0x0000000000000001ULL),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | 0x0000000000000002ULL)
};

uint64_t DoubleSNaNValues[] = {
    F64_MAKE(0, F64_EXP_MASK, F64_PAYLOAD_MASK),
    F64_MAKE(1, F64_EXP_MASK, F64_PAYLOAD_MASK),

    F64_MAKE(0, F64_EXP_MASK, 0x0004000000000000ULL),
    F64_MAKE(1, F64_EXP_MASK, 0x0002000000000000ULL),

    F64_MAKE(0, F64_EXP_MASK, 0x0000000000000001ULL),
    F64_MAKE(1, F64_EXP_MASK, 0x0000000000000002ULL)
};

uint64_t DoubleInfValues[] = {
    F64_MAKE(0, F64_EXP_MASK, 0),    // +Inf
    F64_MAKE(1, F64_EXP_MASK, 0)     // -Inf
};

uint64_t DoubleZeroValues[] = {
    F64_MAKE(0, 0, 0),    // +0.0
    F64_MAKE(1, 0, 0)     // -0.0
};

uint64_t DoubleDenormValues[] = {
  F64_MAKE(0, 0, 1),                   // smallest positive denornal
  F64_MAKE(1, 0, 1),                   // smallest negative denornal
  F64_MAKE(0, 0, F64_MANTISSA_MASK),   // largest positive denormal
  F64_MAKE(1, 0, F64_MANTISSA_MASK)    // largest negative denormal
};

uint64_t DoubleNormalValues[] = {
  F64_NORMAL(0, F64_EXP_MIN, 0),                  // smallest positive normal
  F64_NORMAL(1, F64_EXP_MIN, 0),                  // smallest negative normal
  F64_NORMAL(0, F64_EXP_MAX, F64_MANTISSA_MASK),  // largest positive normal
  F64_NORMAL(1, F64_EXP_MAX, F64_MANTISSA_MASK),  // largest negative normal

  F64_NORMAL(0,  0, 0),                         // +1
  F64_NORMAL(0, -1, F64_MANTISSA_MASK),         // largest number less than 1
  F64_NORMAL(0,  0, 1),                         // smallest number larger than 1
  F64_NORMAL(0,  0, F64_MANTISSA(1, 0, 0)),     // +1.5
  F64_NORMAL(0,  0, F64_MANTISSA(0, 1, 0)),     // +1.25
  F64_NORMAL(0,  0, F64_MANTISSA(0, 0, 1)),     // +1.125
  F64_NORMAL(0, -1, 0),                         // +0.5
  F64_NORMAL(0, -2, 0),                         // +0.25
  F64_NORMAL(0, -3, 0),                         // +0.125

  F64_NORMAL(1,  0, 0),                         // -1
  F64_NORMAL(1, -1, F64_MANTISSA_MASK),
  F64_NORMAL(1,  0, 1),
  F64_NORMAL(1,  0, F64_MANTISSA(1, 0, 0)),     // -1.5
  F64_NORMAL(1,  0, F64_MANTISSA(0, 1, 0)),     // -1.25
  F64_NORMAL(1,  0, F64_MANTISSA(0, 0, 1)),     // -1.125
  F64_NORMAL(1, -1, 0),                         // -0.5
  F64_NORMAL(1, -2, 0),                         // -0.25
  F64_NORMAL(1, -3, 0),                         // -0.125

  F64_NORMAL(0, 1, 0),                          // 2
  F64_NORMAL(0, 1, F64_MANTISSA(1, 0, 0)),      // 3
  F64_NORMAL(1, 1, 0),                          // -2
  F64_NORMAL(1, 1, F64_MANTISSA(1, 0, 0))       // -3
};

int test_double() {
  CHECK_EQ(F64_NORMAL(0,  0, 0), 1.0);
  CHECK_EQ(F64_NORMAL(0,  0, F64_MANTISSA(1, 0, 0)), 1.5);
  CHECK_EQ(F64_NORMAL(0,  0, F64_MANTISSA(0, 1, 0)), 1.25);
  CHECK_EQ(F64_NORMAL(0,  0, F64_MANTISSA(0, 0, 1)), 1.125);
  CHECK_EQ(F64_NORMAL(0, -1, 0), 0.5);
  CHECK_EQ(F64_NORMAL(0, -2, 0), 0.25);
  CHECK_EQ(F64_NORMAL(0, -3, 0), 0.125);
  CHECK_EQ(F64_NORMAL(0, 1, 0), 2.0);
  CHECK_EQ(F64_NORMAL(0, 1, F64_MANTISSA(1, 0, 0)), 3.0);

  CHECK_EQ(F64_NORMAL(1,  0, 0), -1.0);
  CHECK_EQ(F64_NORMAL(1,  0, F64_MANTISSA(1, 0, 0)), -1.5);
  CHECK_EQ(F64_NORMAL(1,  0, F64_MANTISSA(0, 1, 0)), -1.25);
  CHECK_EQ(F64_NORMAL(1,  0, F64_MANTISSA(0, 0, 1)), -1.125);
  CHECK_EQ(F64_NORMAL(1, -1, 0), -0.5);
  CHECK_EQ(F64_NORMAL(1, -2, 0), -0.25);
  CHECK_EQ(F64_NORMAL(1, -3, 0), -0.125);
  CHECK_EQ(F64_NORMAL(1, 1, 0), -2.0);
  CHECK_EQ(F64_NORMAL(1, 1, F64_MANTISSA(1, 0, 0)), -3.0);

  CHECK_EQ(F64_NORMAL(0, F64_EXP_MIN, 0), 2.2250738585072014e-308);
  CHECK_EQ(F64_NORMAL(1, F64_EXP_MIN, 0), -2.2250738585072014e-308);
  CHECK_EQ(F64_NORMAL(0, F64_EXP_MAX, F64_MANTISSA_MASK), 1.7976931348623157e+308);
  CHECK_EQ(F64_NORMAL(1, F64_EXP_MAX, F64_MANTISSA_MASK), -1.7976931348623157e+308);

  for (unsigned i = 0; i < DimOf(DoubleQNaNValues); i++) {
    uint64_t *IPtr = DoubleQNaNValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IX);
  }
  for (unsigned i = 0; i < DimOf(DoubleSNaNValues); i++) {
    uint64_t *IPtr = DoubleSNaNValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IX);
  }
  for (unsigned i = 0; i < DimOf(DoubleInfValues); i++) {
    uint64_t *IPtr = DoubleInfValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, IX);
  }
  for (unsigned i = 0; i < DimOf(DoubleZeroValues); i++) {
    uint64_t *IPtr = DoubleZeroValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, IX);
  }
  for (unsigned i = 0; i < DimOf(DoubleDenormValues); i++) {
    uint64_t *IPtr = DoubleDenormValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, IX);
  }
  for (unsigned i = 0; i < DimOf(DoubleNormalValues); i++) {
    uint64_t *IPtr = DoubleNormalValues + i;
    uint64_t IX = *IPtr;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(__builtin_isfinite(X), IX);
    CHECK_VALUE(__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 2, IX);
  }

  return 0;
}

#undef INT_FORMAT
#undef FLOAT_FORMAT
#undef VAL_FORMAT
#undef INT_TYPE
#undef FLOAT_TYPE

#endif
