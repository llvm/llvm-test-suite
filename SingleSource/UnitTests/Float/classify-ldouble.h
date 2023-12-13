//===--- classify-ldouble.h - Tests for 'long double' -------------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains tests of classification functions for 'long double' type.
//
//===----------------------------------------------------------------------===//
#ifndef _CLASSIFY_LDOUBLE_H_
#define _CLASSIFY_LDOUBLE_H_

#include "check-helper.h"
#include "fformat.h"
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef long double ldouble;

#define VAL_FORMAT "%Lg"
#define GET_VALUE(x) (*(long double *)x)

// The type long double does not have definite representation, it may be mapped
// to various floating-point types. In general case value tables are build using
// builtin functions and macro definitions provided by the compiler.
#ifdef __LDBL_HAS_QUIET_NAN__
long double LongDoubleSNaNValues[4];
long double LongDoubleQNaNValues[4];
#endif
#ifdef __LDBL_HAS_INFINITY__
long double LongDoubleInfValues[2];
#endif
long double LongDoubleZeroValues[] = { 0.0L, -0.0L };
#ifdef __LDBL_HAS_DENORM__
long double LongDoubleDenormValues[2];
#endif
long double LongDoubleNormalValues[6];

void prepare_ldouble_tables() {
  LongDoubleQNaNValues[0] = __builtin_nanl("");
  LongDoubleQNaNValues[1] = -__builtin_nanl("");
  LongDoubleQNaNValues[2] = __builtin_nanl("0x01");
  LongDoubleQNaNValues[3] = -__builtin_nanl("0x01");

  LongDoubleSNaNValues[0] = __builtin_nansl("");
  LongDoubleSNaNValues[1] = -__builtin_nansl("");
  LongDoubleSNaNValues[2] = __builtin_nansl("0x01");
  LongDoubleSNaNValues[3] = -__builtin_nansl("0x01");

#ifdef __LDBL_HAS_INFINITY__
  LongDoubleInfValues[0] = __builtin_infl();
  LongDoubleInfValues[1] = -__builtin_infl();
#endif
#ifdef __LDBL_HAS_DENORM__
  LongDoubleDenormValues[0] = __LDBL_DENORM_MIN__;
  LongDoubleDenormValues[1] = -__LDBL_DENORM_MIN__;
#endif

  LongDoubleNormalValues[0] = 1.0L;
  LongDoubleNormalValues[1] = -1.0L;
  LongDoubleNormalValues[2] = __LDBL_MAX__;
  LongDoubleNormalValues[3] = -__LDBL_MAX__;
  LongDoubleNormalValues[4] = __LDBL_MIN__;
  LongDoubleNormalValues[5] = -__LDBL_MIN__;
}

int test_ldouble() {
#ifdef __LDBL_HAS_QUIET_NAN__
  for (unsigned i = 0; i < DimOf(LongDoubleQNaNValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleQNaNValues + i);
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
  for (unsigned i = 0; i < DimOf(LongDoubleSNaNValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleSNaNValues + i);
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
#endif
#ifdef __LDBL_HAS_INFINITY__
  for (unsigned i = 0; i < DimOf(LongDoubleInfValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleInfValues + i);
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
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleZeroValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleZeroValues + i);
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
#ifdef __LDBL_HAS_DENORM__
  for (unsigned i = 0; i < DimOf(LongDoubleDenormValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleDenormValues + i);
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
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleNormalValues); ++i) {
    uint64_t *P = (uint64_t *)(LongDoubleNormalValues + i);
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

  return 0;
}

#define FLOAT_TYPE ldouble
#include "gen_isfpclass_funcs.h"

void test_isfpclass_ldouble() {
  for (unsigned i = 0; i < DimOf(LongDoubleZeroValues); ++i) {
    long double X = *(long double *)(LongDoubleZeroValues + i);
    if (__builtin_signbit(X))
      test_fcNegZero_ldouble(X);
    else
      test_fcPosZero_ldouble(X);
  }
#ifdef __LDBL_HAS_DENORM__
  for (unsigned i = 0; i < DimOf(LongDoubleDenormValues); ++i) {
    long double X = *(long double *)(LongDoubleDenormValues + i);
    if (X < 0)
      test_fcNegSubnormal_ldouble(X);
    else
      test_fcPosSubnormal_ldouble(X);
  }
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleNormalValues); ++i) {
    long double X = *(long double *)(LongDoubleNormalValues + i);
    if (X < 0)
      test_fcNegNormal_ldouble(X);
    else
      test_fcPosNormal_ldouble(X);
  }
#ifdef __LDBL_HAS_INFINITY__
  for (unsigned i = 0; i < DimOf(LongDoubleInfValues); ++i) {
    long double X = *(long double *)(LongDoubleInfValues + i);
    if (X > 0)
      test_fcPosInf_ldouble(X);
    else
      test_fcNegInf_ldouble(X);
  }
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleQNaNValues); ++i) {
    long double X = *(long double *)(LongDoubleQNaNValues + i);
    test_fcQNan_ldouble(X);
  }
  for (unsigned i = 0; i < DimOf(LongDoubleSNaNValues); ++i) {
    long double X = *(long double *)(LongDoubleSNaNValues + i);
    test_fcSNan_ldouble(X);
  }
}

#undef VAL_FORMAT
#undef GET_VALUE
#undef FLOAT_TYPE

#endif
