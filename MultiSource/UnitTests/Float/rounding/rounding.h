//===-- rounding.h - Descriptions of floating point formats -------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Helper entities for rounding mode testing. 
//
//===----------------------------------------------------------------------===//
#ifndef _ROUNDING_H_
#define _ROUNDING_H_

// Standard rounding modes returned by FLT_ROUNDS.
#define ROUNDING_TOWARDZERO         0
#define ROUNDING_TONEAREST          1
#define ROUNDING_UPWARD             2
#define ROUNDING_DOWNWARD           3
#define ROUNDING_TONEARESTFROMZERO  4

// Not all targets support getting/setting rounding mode using builtin
// functions.
#if defined(__x86_64__) || defined(__aarch64__) || defined(__arm__) || \
    defined(__riscv)
#define FLOAT_AVAILABLE 1
#define DOUBLE_AVAILABLE 1
#endif

// Function that "calculates" rounding mode. It is defined in a separate file to
// make rounding mode unknown in compile time.
int get_rounding_mode(int rm);

#endif // _ROUNDING_H_
