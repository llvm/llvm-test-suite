//===--- classify-fp80.h - Tests for x86 extended double ----------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains tests of classification functions for x86 80-bit
// 'long double' type.
//
//===----------------------------------------------------------------------===//
#ifndef _CLASSIFY_F80_H_
#define _CLASSIFY_F80_H_

#if defined(__LDBL_MANT_DIG__) && (__LDBL_MANT_DIG__ == 64)
#define USE_X86_FP80_TYPE
#endif

#ifdef USE_X86_FP80_TYPE

#include "check-helper.h"
#include "fformat.h"
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef long double fp80;

// Values in the tables for this type are actually 128-bit integers, stored as
// pairs of 64-bit values.
#define VAL_FORMAT "%08" PRIx64 " %016" PRIx64
#define GET_VALUE(p) ((uint64_t *)(p))[1], ((uint64_t *)(p))[0]

uint64_t ExtendedDoubleSNaNValues[] = {
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT | 0x2000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT | 0x1000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT | 0x02ULL),
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT | 0x01ULL)};

uint64_t ExtendedDoubleQNaNValues[] = {
    F80_MAKE(0, F80_EXP_MASK,
             F80_INTEGER_BIT | F80_QNAN_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(1, F80_EXP_MASK,
             F80_INTEGER_BIT | F80_QNAN_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT | F80_QNAN_BIT),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT | F80_QNAN_BIT),
    F80_MAKE(0, F80_EXP_MASK,
             F80_INTEGER_BIT | F80_QNAN_BIT | 0x2000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK,
             F80_INTEGER_BIT | F80_QNAN_BIT | 0x1000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT | F80_QNAN_BIT | 0x02ULL),
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT | F80_QNAN_BIT | 0x01ULL)};

uint64_t ExtendedDoubleInfValues[] = {
    F80_MAKE(0, F80_EXP_MASK, F80_INTEGER_BIT),
    F80_MAKE(1, F80_EXP_MASK, F80_INTEGER_BIT)};

uint64_t ExtendedDoubleZeroValues[] = {F80_MAKE(0, 0, 0), F80_MAKE(1, 0, 0)};

uint64_t ExtendedDoubleDenormValues[] = {
    F80_MAKE(0, 0, 1),                   // smallest positive denornal
    F80_MAKE(1, 0, 1),                   // smallest negative denornal
    F80_MAKE(0, 0, F80_FRACTIONAL_MASK), // largest positive denormal
    F80_MAKE(1, 0, F80_FRACTIONAL_MASK)  // largest negative denormal
};

uint64_t ExtendedDoubleNormValues[] = {
    F80_NORMAL(0, F80_EXP_MIN, 0),                   // smallest positive normal
    F80_NORMAL(1, F80_EXP_MIN, 0),                   // smallest negative normal
    F80_NORMAL(0, F80_EXP_MAX, F80_FRACTIONAL_MASK), // largest positive normal
    F80_NORMAL(1, F80_EXP_MAX, F80_FRACTIONAL_MASK), // largest negative normal

    F80_NORMAL(0, 0, 0),                     // +1
    F80_NORMAL(0, -1, F80_FRACTIONAL_MASK),  // largest number less than 1
    F80_NORMAL(0, 0, 1),                     // smallest number larger than 1
    F80_NORMAL(0, 0, F80_MANTISSA(1, 0, 0)), // +1.5
    F80_NORMAL(0, 0, F80_MANTISSA(0, 1, 0)), // +1.25
    F80_NORMAL(0, 0, F80_MANTISSA(0, 0, 1)), // +1.125
    F80_NORMAL(0, -1, 0),                    // +0.5
    F80_NORMAL(0, -2, 0),                    // +0.25
    F80_NORMAL(0, -3, 0),                    // +0.125

    F80_NORMAL(1, 0, 0), // -1
    F80_NORMAL(1, -1, F80_FRACTIONAL_MASK),
    F80_NORMAL(1, 0, 1),
    F80_NORMAL(1, 0, F80_MANTISSA(1, 0, 0)), // -1.5
    F80_NORMAL(1, 0, F80_MANTISSA(0, 1, 0)), // -1.25
    F80_NORMAL(1, 0, F80_MANTISSA(0, 0, 1)), // -1.125
    F80_NORMAL(1, -1, 0),                    // -0.5
    F80_NORMAL(1, -2, 0),                    // -0.25
    F80_NORMAL(1, -3, 0),                    // -0.125

    F80_NORMAL(0, 1, 0),                     // 2
    F80_NORMAL(0, 1, F80_MANTISSA(1, 0, 0)), // 3
    F80_NORMAL(1, 1, 0),                     // -2
    F80_NORMAL(1, 1, F80_MANTISSA(1, 0, 0))  // -3
};

uint64_t ExtendedDoubleUnsupportedValues[] = {
    // Pseudo-NaNs.
    F80_MAKE(0, F80_EXP_MASK, F80_PAYLOAD_MASK),
    F80_MAKE(1, F80_EXP_MASK, F80_PAYLOAD_MASK),
    F80_MAKE(0, F80_EXP_MASK, 0x2000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, 0x1000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, 0x02ULL),
    F80_MAKE(0, F80_EXP_MASK, 0x01ULL),
    F80_MAKE(0, F80_EXP_MASK, F80_QNAN_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(1, F80_EXP_MASK, F80_QNAN_BIT | F80_PAYLOAD_MASK),
    F80_MAKE(0, F80_EXP_MASK, F80_QNAN_BIT),
    F80_MAKE(1, F80_EXP_MASK, F80_QNAN_BIT),
    F80_MAKE(0, F80_EXP_MASK, F80_QNAN_BIT | 0x2000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, F80_QNAN_BIT | 0x1000000000000000ULL),
    F80_MAKE(1, F80_EXP_MASK, F80_QNAN_BIT | 0x02ULL),
    F80_MAKE(0, F80_EXP_MASK, F80_QNAN_BIT | 0x01ULL),
    // Pseudo-infinities.
    F80_MAKE(0, F80_EXP_MASK, 0),
    F80_MAKE(1, F80_EXP_MASK, 0),
    // Unnormals.
    F80_MAKE(0, 1, 0),
    F80_MAKE(1, 1, 0),
    F80_MAKE(0, 0x7FFE, 0),
    F80_MAKE(1, 0x7FFE, 0),
};

uint64_t ExtendedDoublePseudoDenormalValues[] = {
    // Pseudo-denormals.
    F80_MAKE(0, 0, F80_INTEGER_BIT),
    F80_MAKE(1, 0, F80_INTEGER_BIT),
    F80_MAKE(0, 0, F80_INTEGER_BIT | 1),
    F80_MAKE(1, 0, F80_INTEGER_BIT | 1),
    F80_MAKE(0, 0, F80_INTEGER_BIT | F80_FRACTIONAL_MASK),
    F80_MAKE(1, 0, F80_INTEGER_BIT | F80_FRACTIONAL_MASK),
};

int test_fp80() {
  for (unsigned i = 0; i < DimOf(ExtendedDoubleQNaNValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleQNaNValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(!__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleSNaNValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleSNaNValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(__builtin_isnan(X), P);
    CHECK_VALUE(__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(!__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleInfValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleInfValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(!__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(__builtin_isinf(X), P);
    CHECK_VALUE(!__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleZeroValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleZeroValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(!__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleDenormValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleDenormValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(!__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleNormValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleNormValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(!__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(__builtin_isfinite(X), P);
    CHECK_VALUE(__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 2, P);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleUnsupportedValues); i += 2) {
    uint64_t *P = (uint64_t *)(ExtendedDoubleUnsupportedValues + i);
    long double X = *(long double *)P;
    CHECK_VALUE(__builtin_isnan(X), P);
    CHECK_VALUE(!__builtin_issignaling(X), P);
    CHECK_VALUE(!__builtin_isinf(X), P);
    CHECK_VALUE(!__builtin_isfinite(X), P);
    CHECK_VALUE(!__builtin_isnormal(X), P);
    CHECK_VALUE(!__builtin_issubnormal(X), P);
    CHECK_VALUE(!__builtin_iszero(X), P);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, P);
  }

  return 0;
}

#define FLOAT_TYPE fp80
#include "gen_isfpclass_funcs.h"

void test_isfpclass_fp80() {
  for (unsigned i = 0; i < DimOf(ExtendedDoubleZeroValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleZeroValues + i);
    if (__builtin_signbit(X))
      test_fcNegZero_fp80(X);
    else
      test_fcPosZero_fp80(X);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleDenormValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleDenormValues + i);
    if (X < 0)
      test_fcNegSubnormal_fp80(X);
    else
      test_fcPosSubnormal_fp80(X);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleNormValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleNormValues + i);
    if (X < 0)
      test_fcNegNormal_fp80(X);
    else
      test_fcPosNormal_fp80(X);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleInfValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleInfValues + i);
    if (X > 0)
      test_fcPosInf_fp80(X);
    else
      test_fcNegInf_fp80(X);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleQNaNValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleQNaNValues + i);
    test_fcQNan_fp80(X);
  }
  for (unsigned i = 0; i < DimOf(ExtendedDoubleSNaNValues); i += 2) {
    long double X = *(long double *)(ExtendedDoubleSNaNValues + i);
    test_fcSNan_fp80(X);
  }
}

#undef VAL_FORMAT
#undef GET_VALUE
#undef FLOAT_TYPE

#endif // #ifdef USE_X86_FP80_TYPE
#endif // #ifndef _CLASSIFY_F80_H_
