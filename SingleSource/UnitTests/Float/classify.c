//===--- classify.cpp - Tess for FP classification intrinsics ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a general test for floating point classification intrinsic.
//
//===----------------------------------------------------------------------===//

#include "classify-f32.h"
#include "classify-f64.h"
#include "classify-ldouble.h"


int main()
{
  test_float();
  test_double();
  prepare_ldouble_tables();
  test_ldouble();
  return 0;
}

