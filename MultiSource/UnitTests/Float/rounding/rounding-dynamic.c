//===--- rounding.c --Tests for changing rounding mode ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Helper function for rounding mode tests. It is intended for making a dynamic
// rounding mode, unknown at compile time, from a constant values. It is in a
// separate translation unit to prevent constant folding.
//
//===----------------------------------------------------------------------===//

#include "rounding.h"

int get_rounding_mode(int rm) {
  return rm;
}
