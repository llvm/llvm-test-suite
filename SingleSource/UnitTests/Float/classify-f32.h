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

#define VAL_FORMAT "%" PRIx32
#define GET_VALUE(x) (*(uint32_t *)x)

uint32_t FloatQNaNValues[] = {
    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | F32_PAYLOAD_MASK),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | F32_PAYLOAD_MASK),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | 0x00200000U),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | 0x00100000U),

    F32_MAKE(0, F32_EXP_MASK, F32_QNAN_BIT | 0x00000001U),
    F32_MAKE(1, F32_EXP_MASK, F32_QNAN_BIT | 0x00000002U)};

uint32_t FloatSNaNValues[] = {F32_MAKE(0, F32_EXP_MASK, F32_PAYLOAD_MASK),
                              F32_MAKE(1, F32_EXP_MASK, F32_PAYLOAD_MASK),

                              F32_MAKE(0, F32_EXP_MASK, 0x00200000U),
                              F32_MAKE(1, F32_EXP_MASK, 0x00100000U),

                              F32_MAKE(0, F32_EXP_MASK, 0x00000001U),
                              F32_MAKE(1, F32_EXP_MASK, 0x00000002U)};

uint32_t FloatInfValues[] = {
    F32_MAKE(0, F32_EXP_MASK, 0), // +Inf
    F32_MAKE(1, F32_EXP_MASK, 0)  // -Inf
};

uint32_t FloatZeroValues[] = {
    F32_MAKE(0, 0, 0), // +0.0
    F32_MAKE(1, 0, 0)  // -0.0
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
  for (unsigned i = 0; i < DimOf(FloatQNaNValues); i++) {
    uint32_t *IPtr = FloatQNaNValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IPtr);
  }
  for (unsigned i = 0; i < DimOf(FloatSNaNValues); i++) {
    uint32_t *IPtr = FloatSNaNValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IPtr);
    CHECK_VALUE(__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IPtr);
  }
  for (unsigned i = 0; i < DimOf(FloatInfValues); i++) {
    uint32_t *IPtr = FloatInfValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, IPtr);
  }
  for (unsigned i = 0; i < DimOf(FloatZeroValues); i++) {
    uint32_t *IPtr = FloatZeroValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, IPtr);
  }
  for (unsigned i = 0; i < DimOf(FloatDenormValues); i++) {
    uint32_t *IPtr = FloatDenormValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, IPtr);
  }
  for (unsigned i = 0; i < DimOf(FloatNormalValues); i++) {
    uint32_t *IPtr = FloatNormalValues + i;
    float X = *(float *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(__builtin_isfinite(X), IPtr);
    CHECK_VALUE(__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 2, IPtr);
  }

  return 0;
}

#define FLOAT_TYPE float
#include "gen_isfpclass_funcs.h"

void test_isfpclass_float() {
  for (unsigned i = 0; i < DimOf(FloatZeroValues); i++) {
    float X = *(float *)(FloatZeroValues + i);
    if (__builtin_signbit(X) == 0)
      test_fcPosZero_float(X);
    else
      test_fcNegZero_float(X);
  }
  for (unsigned i = 0; i < DimOf(FloatDenormValues); i++) {
    float X = *(float *)(FloatDenormValues + i);
    if (X < 0)
      test_fcNegSubnormal_float(X);
    else
      test_fcPosSubnormal_float(X);
  }
  for (unsigned i = 0; i < DimOf(FloatNormalValues); i++) {
    float X = *(float *)(FloatNormalValues + i);
    if (X < 0)
      test_fcNegNormal_float(X);
    else
      test_fcPosNormal_float(X);
  }
  for (unsigned i = 0; i < DimOf(FloatInfValues); i++) {
    float X = *(float *)(FloatInfValues + i);
    if (X > 0)
      test_fcPosInf_float(X);
    else
      test_fcNegInf_float(X);
  }
  for (unsigned i = 0; i < DimOf(FloatQNaNValues); i++) {
    float X = *(float *)(FloatQNaNValues + i);
    test_fcQNan_float(X);
  }
  for (unsigned i = 0; i < DimOf(FloatSNaNValues); i++) {
    float X = *(float *)(FloatSNaNValues + i);
    test_fcSNan_float(X);
  }
  test_fcPosInf_float(__builtin_inff());
  test_fcNegInf_float(-__builtin_inff());
  test_fcPosZero_float(0.0F);
  test_fcNegZero_float(-0.0F);
}

#undef VAL_FORMAT
#undef GET_VALUE
#undef FLOAT_TYPE

#endif
