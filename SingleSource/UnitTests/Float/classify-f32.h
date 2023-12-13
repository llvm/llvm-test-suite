//===--- classify-f32.h - Tests for 'float' classification --------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains tests of classification functions for 'float' type.
//
//===----------------------------------------------------------------------===//
#ifndef _CLASSIFY_F32_H_
#define _CLASSIFY_F32_H_

#include "check-helper.h"
#include "fformat.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define INT_FORMAT   PRIx32
#define FLOAT_FORMAT "g"
#define VAL_FORMAT   INT_FORMAT
#define INT_TYPE     uint32_t
#define FLOAT_TYPE   float

uint32_t FloatQNaNValues[] = {
    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | F32_PAYLOAD_MASK),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | F32_PAYLOAD_MASK),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | 0x00200000U),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | 0x00100000U),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | 0x00000001U),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | 0x00000002U)
};

uint32_t FloatSNaNValues[] = {
    F32_MAKE(0, F32_EXP_MASK, F32_PAYLOAD_MASK),
    F32_MAKE(1, F32_EXP_MASK, F32_PAYLOAD_MASK),

    F32_MAKE(0, F32_EXP_MASK, 0x00200000U),
    F32_MAKE(1, F32_EXP_MASK, 0x00100000U),

    F32_MAKE(0, F32_EXP_MASK, 0x00000001U),
    F32_MAKE(1, F32_EXP_MASK, 0x00000002U)
};

uint32_t FloatInfValues[] = {
    F32_MAKE(0, F32_EXP_MASK, 0),    // +Inf
    F32_MAKE(1, F32_EXP_MASK, 0)     // -Inf
};

uint32_t FloatZeroValues[] = {
    F32_MAKE(0, 0, 0),    // +0.0
    F32_MAKE(1, 0, 0)     // -0.0
};

uint32_t FloatDenormValues[] = {
  F32_MAKE(0, 0, 1),                   // smallest positive denornal
  F32_MAKE(1, 0, 1),                   // smallest negative denornal
  F32_MAKE(0, 0, F32_MANTISSA_MASK),   // largest positive denormal
  F32_MAKE(1, 0, F32_MANTISSA_MASK)    // largest negative denormal
};

uint32_t FloatNormalValues[] = {
  F32_NORMAL(0, F32_EXP_MIN, 0),                  // smallest positive normal
  F32_NORMAL(1, F32_EXP_MIN, 0),                  // smallest negative normal
  F32_NORMAL(0, F32_EXP_MAX, F32_MANTISSA_MASK),  // largest positive normal
  F32_NORMAL(1, F32_EXP_MAX, F32_MANTISSA_MASK),  // largest negative normal

  F32_NORMAL(0,  0, 0),                         // +1
  F32_NORMAL(0, -1, F32_MANTISSA_MASK),         // largest number less than 1
  F32_NORMAL(0,  0, 1),                         // smallest number larger than 1
  F32_NORMAL(0,  0, F32_MANTISSA(1, 0, 0)),     // +1.5
  F32_NORMAL(0,  0, F32_MANTISSA(0, 1, 0)),     // +1.25
  F32_NORMAL(0,  0, F32_MANTISSA(0, 0, 1)),     // +1.125
  F32_NORMAL(0, -1, 0),                         // +0.5
  F32_NORMAL(0, -2, 0),                         // +0.25
  F32_NORMAL(0, -3, 0),                         // +0.125

  F32_NORMAL(1,  0, 0),                         // -1
  F32_NORMAL(1, -1, F32_MANTISSA_MASK),
  F32_NORMAL(1,  0, 1),
  F32_NORMAL(1,  0, F32_MANTISSA(1, 0, 0)),     // -1.5
  F32_NORMAL(1,  0, F32_MANTISSA(0, 1, 0)),     // -1.25
  F32_NORMAL(1,  0, F32_MANTISSA(0, 0, 1)),     // -1.125
  F32_NORMAL(1, -1, 0),                         // -0.5
  F32_NORMAL(1, -2, 0),                         // -0.25
  F32_NORMAL(1, -3, 0),                         // -0.125

  F32_NORMAL(0, 1, 0),                          // 2
  F32_NORMAL(0, 1, F32_MANTISSA(1, 0, 0)),      // 3
  F32_NORMAL(1, 1, 0),                          // -2
  F32_NORMAL(1, 1, F32_MANTISSA(1, 0, 0))       // -3
};

int test_float() {
  CHECK_EQ(F32_NORMAL(0,  0, 0), 1.0F);
  CHECK_EQ(F32_NORMAL(0,  0, F32_MANTISSA(1, 0, 0)), 1.5F);
  CHECK_EQ(F32_NORMAL(0,  0, F32_MANTISSA(0, 1, 0)), 1.25F);
  CHECK_EQ(F32_NORMAL(0,  0, F32_MANTISSA(0, 0, 1)), 1.125);
  CHECK_EQ(F32_NORMAL(0, -1, 0), 0.5F);
  CHECK_EQ(F32_NORMAL(0, -2, 0), 0.25);
  CHECK_EQ(F32_NORMAL(0, -3, 0), 0.125);
  CHECK_EQ(F32_NORMAL(0, 1, 0), 2.0F);
  CHECK_EQ(F32_NORMAL(0, 1, F32_MANTISSA(1, 0, 0)), 3.0F);

  CHECK_EQ(F32_NORMAL(1,  0, 0), -1.0F);
  CHECK_EQ(F32_NORMAL(1,  0, F32_MANTISSA(1, 0, 0)), -1.5F);
  CHECK_EQ(F32_NORMAL(1,  0, F32_MANTISSA(0, 1, 0)), -1.25F);
  CHECK_EQ(F32_NORMAL(1,  0, F32_MANTISSA(0, 0, 1)), -1.125);
  CHECK_EQ(F32_NORMAL(1, -1, 0), -0.5F);
  CHECK_EQ(F32_NORMAL(1, -2, 0), -0.25);
  CHECK_EQ(F32_NORMAL(1, -3, 0), -0.125);
  CHECK_EQ(F32_NORMAL(1, 1, 0), -2.0F);
  CHECK_EQ(F32_NORMAL(1, 1, F32_MANTISSA(1, 0, 0)), -3.0F);

  CHECK_EQ(F32_NORMAL(0, F32_EXP_MIN, 0), 1.1754943508e-38F);
  CHECK_EQ(F32_NORMAL(1, F32_EXP_MIN, 0), -1.1754943508e-38F);
  CHECK_EQ(F32_NORMAL(0, F32_EXP_MAX, F32_MANTISSA_MASK), 3.4028234664e38F);
  CHECK_EQ(F32_NORMAL(1, F32_EXP_MAX, F32_MANTISSA_MASK), -3.4028234664e38F);

  for (unsigned i = 0; i < DimOf(FloatQNaNValues); i++) {
    uint32_t *IPtr = FloatQNaNValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IX);
  }
  for (unsigned i = 0; i < DimOf(FloatSNaNValues); i++) {
    uint32_t *IPtr = FloatSNaNValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IX);
  }
  for (unsigned i = 0; i < DimOf(FloatInfValues); i++) {
    uint32_t *IPtr = FloatInfValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(__builtin_isinf(X), IX);
    CHECK_VALUE(!__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, IX);
  }
  for (unsigned i = 0; i < DimOf(FloatZeroValues); i++) {
    uint32_t *IPtr = FloatZeroValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, IX);
  }
  for (unsigned i = 0; i < DimOf(FloatDenormValues); i++) {
    uint32_t *IPtr = FloatDenormValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IX);
    CHECK_VALUE(!__builtin_isinf(X), IX);
    CHECK_VALUE(__builtin_isfinite(X), IX);
    CHECK_VALUE(!__builtin_isnormal(X), IX);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, IX);
  }
  for (unsigned i = 0; i < DimOf(FloatNormalValues); i++) {
    uint32_t *IPtr = FloatNormalValues + i;
    uint32_t IX = *IPtr;
    float X = *(float *)IPtr;
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
