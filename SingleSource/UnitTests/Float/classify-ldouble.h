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
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


// The type long double does not have definite representation, it may be mapped
// to various float types. So instead of preparing bit patterns, rely on builtin
// functions and macro definitions provided by the compiler.

long double LongDoubleSNaNValues[4];
long double LongDoubleQNaNValues[4];
#ifdef __LDBL_HAS_INFINITY__
long double LongDoubleInfValues[2];
#endif
long double LongDoubleZeroValues[] = { 0.0L, -0.0L };
#ifdef __LDBL_HAS_DENORM__
long double LongDoubleDenormValues[2];
#endif
long double LongDoubleNormalValues[6];

#define FLOAT_FORMAT "Lg"
#define VAL_FORMAT   FLOAT_FORMAT
#define FLOAT_TYPE   long double

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
  for (unsigned i = 0; i < DimOf(LongDoubleQNaNValues); i++) {
    long double X = LongDoubleQNaNValues[i];
    CHECK_VALUE(__builtin_isnan(X), X);
    CHECK_VALUE(!__builtin_isinf(X), X);
    CHECK_VALUE(!__builtin_isfinite(X), X);
    CHECK_VALUE(!__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, X);
  }
  for (unsigned i = 0; i < DimOf(LongDoubleSNaNValues); i++) {
    long double X = LongDoubleSNaNValues[i];
    CHECK_VALUE(__builtin_isnan(X), X);
    CHECK_VALUE(!__builtin_isinf(X), X);
    CHECK_VALUE(!__builtin_isfinite(X), X);
    CHECK_VALUE(!__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 0, X);
  }
#ifdef __LDBL_HAS_INFINITY__
  for (unsigned i = 0; i < DimOf(LongDoubleInfValues); i++) {
    long double X = LongDoubleInfValues[i];
    CHECK_VALUE(!__builtin_isnan(X), X);
    CHECK_VALUE(__builtin_isinf(X), X);
    CHECK_VALUE(!__builtin_isfinite(X), X);
    CHECK_VALUE(!__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 1, X);
  }
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleZeroValues); i++) {
    long double X = LongDoubleZeroValues[i];
    CHECK_VALUE(!__builtin_isnan(X), X);
    CHECK_VALUE(!__builtin_isinf(X), X);
    CHECK_VALUE(__builtin_isfinite(X), X);
    CHECK_VALUE(!__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 4, X);
  }
#ifdef __LDBL_HAS_DENORM__
  for (unsigned i = 0; i < DimOf(LongDoubleDenormValues); i++) {
     long double X = LongDoubleDenormValues[i];
    CHECK_VALUE(!__builtin_isnan(X), X);
    CHECK_VALUE(!__builtin_isinf(X), X);
    CHECK_VALUE(__builtin_isfinite(X), X);
    CHECK_VALUE(!__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 3, X);
  }
#endif
  for (unsigned i = 0; i < DimOf(LongDoubleNormalValues); i++) {
    long double X = LongDoubleNormalValues[i];
    CHECK_VALUE(!__builtin_isnan(X), X);
    CHECK_VALUE(!__builtin_isinf(X), X);
    CHECK_VALUE(__builtin_isfinite(X), X);
    CHECK_VALUE(__builtin_isnormal(X), X);
    CHECK_VALUE(__builtin_fpclassify(0, 1, 2, 3, 4, X) == 2, X);
  }

  return 0;
}

#undef FLOAT_FORMAT
#undef VAL_FORMAT
#undef FLOAT_TYPE

#endif
