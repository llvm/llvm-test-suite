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

#define VAL_FORMAT "%" PRIx64
#define GET_VALUE(x) (*(uint64_t *)x)

uint64_t DoubleQNaNValues[] = {
    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | F64_PAYLOAD_MASK),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | F64_PAYLOAD_MASK),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | 0x0004000000000000ULL),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | 0x0002000000000000ULL),

    F64_MAKE(0, F64_EXP_MASK, F64_QNAN_BIT | 0x0000000000000001ULL),
    F64_MAKE(1, F64_EXP_MASK, F64_QNAN_BIT | 0x0000000000000002ULL)};

uint64_t DoubleSNaNValues[] = {
    F64_MAKE(0, F64_EXP_MASK, F64_PAYLOAD_MASK),
    F64_MAKE(1, F64_EXP_MASK, F64_PAYLOAD_MASK),

    F64_MAKE(0, F64_EXP_MASK, 0x0004000000000000ULL),
    F64_MAKE(1, F64_EXP_MASK, 0x0002000000000000ULL),

    F64_MAKE(0, F64_EXP_MASK, 0x0000000000000001ULL),
    F64_MAKE(1, F64_EXP_MASK, 0x0000000000000002ULL)};

uint64_t DoubleInfValues[] = {
    F64_MAKE(0, F64_EXP_MASK, 0), // +Inf
    F64_MAKE(1, F64_EXP_MASK, 0)  // -Inf
};

uint64_t DoubleZeroValues[] = {
    F64_MAKE(0, 0, 0), // +0.0
    F64_MAKE(1, 0, 0)  // -0.0
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
  for (unsigned i = 0; i < DimOf(DoubleQNaNValues); i++) {
    uint64_t *IPtr = DoubleQNaNValues + i;
    double X = *(double *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IPtr);
  }
  for (unsigned i = 0; i < DimOf(DoubleSNaNValues); i++) {
    uint64_t *IPtr = DoubleSNaNValues + i;
    double X = *(double *)IPtr;
    CHECK_VALUE(__builtin_isnan(X), IPtr);
    CHECK_VALUE(__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, IPtr);
  }
  for (unsigned i = 0; i < DimOf(DoubleInfValues); i++) {
    uint64_t *IPtr = DoubleInfValues + i;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(__builtin_isinf(X), IPtr);
    CHECK_VALUE(!__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, IPtr);
  }
  for (unsigned i = 0; i < DimOf(DoubleZeroValues); i++) {
    uint64_t *IPtr = DoubleZeroValues + i;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(!__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, IPtr);
  }
  for (unsigned i = 0; i < DimOf(DoubleDenormValues); i++) {
    uint64_t *IPtr = DoubleDenormValues + i;
    double X = *(double *)IPtr;
    CHECK_VALUE(!__builtin_isnan(X), IPtr);
    CHECK_VALUE(!__builtin_issignaling(X), IPtr);
    CHECK_VALUE(!__builtin_isinf(X), IPtr);
    CHECK_VALUE(__builtin_isfinite(X), IPtr);
    CHECK_VALUE(!__builtin_isnormal(X), IPtr);
    CHECK_VALUE(__builtin_issubnormal(X), IPtr);
    CHECK_VALUE(!__builtin_iszero(X), IPtr);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, IPtr);
  }
  for (unsigned i = 0; i < DimOf(DoubleNormalValues); i++) {
    uint64_t *IPtr = DoubleNormalValues + i;
    double X = *(double *)IPtr;
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

#define FLOAT_TYPE double
#include "gen_isfpclass_funcs.h"

void test_isfpclass_double() {
  for (unsigned i = 0; i < DimOf(DoubleZeroValues); i++) {
    double X = *(double *)(DoubleZeroValues + i);
    if (__builtin_signbit(X) == 0)
      test_fcPosZero_double(X);
    else
      test_fcNegZero_double(X);
  }
  for (unsigned i = 0; i < DimOf(DoubleDenormValues); i++) {
    double X = *(double *)(DoubleDenormValues + i);
    if (X < 0)
      test_fcNegSubnormal_double(X);
    else
      test_fcPosSubnormal_double(X);
  }
  for (unsigned i = 0; i < DimOf(DoubleNormalValues); i++) {
    double X = *(double *)(DoubleNormalValues + i);
    if (X < 0)
      test_fcNegNormal_double(X);
    else
      test_fcPosNormal_double(X);
  }
  for (unsigned i = 0; i < DimOf(DoubleInfValues); i++) {
    double X = *(double *)(DoubleInfValues + i);
    if (X > 0)
      test_fcPosInf_double(X);
    else
      test_fcNegInf_double(X);
  }
  for (unsigned i = 0; i < DimOf(DoubleQNaNValues); i++) {
    double X = *(double *)(DoubleQNaNValues + i);
    test_fcQNan_double(X);
  }
  for (unsigned i = 0; i < DimOf(DoubleSNaNValues); i++) {
    double X = *(double *)(DoubleSNaNValues + i);
    test_fcSNan_double(X);
  }
  test_fcPosInf_double(__builtin_inf());
  test_fcNegInf_double(-__builtin_inf());
  test_fcPosZero_double(0.0);
  test_fcNegZero_double(-0.0);
}

#undef VAL_FORMAT
#undef GET_VALUE
#undef FLOAT_TYPE

#endif
