//===--- check-helper.h - Helper stuff for tests ------------------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file contains helper macros for making tests for floating point
// operations.
//
//===----------------------------------------------------------------------===//
#ifndef _CHECK_HELPER_H_
#define _CHECK_HELPER_H_

#define DimOf(x) (sizeof(x) / sizeof(x[0]))

// Checks if condition 'cond' is true for the 'value'.
//
// Requires the following macros to be defined:
//
//     VAL_FORMAT - printf format specifier without %, like "d" or "llx", which
//                  should be used to print 'value'.
//
#define CHECK_VALUE(cond, value)                                               \
    do {                                                                       \
      if (!(cond)) {                                                           \
        printf("Check '%s' in file '%s' at line %d "                           \
               "failed for the value '%" VAL_FORMAT "'\n",                     \
               #cond, __FILE__, __LINE__, (value));                            \
        exit(-1);                                                              \
      }                                                                        \
    } while(0)

// Checks if floating point 'value' is equal to the value 'expected' which is an
// integer that represents bits of floating point number.
//
// Requires the following macros to be defined:
//
//     INT_FORMAT   - printf format specifier without %, like "d" or "llx",
//                    which should be used to print 'expected'.
//     FLOAT_FORMAT - printf format specifier without % to print 'value'.
//     INT_TYPE     - type of 'expected'.
//     FLOAT_TYPE   - type of 'value'.
//
#define CHECK_EQ(value, expected)                                              \
    do {                                                                       \
      union {                                                                  \
        INT_TYPE i;                                                            \
        FLOAT_TYPE f;                                                          \
      } u;                                                                     \
      u.i = (value);                                                           \
      if (u.f != (expected)) {                                                 \
         printf("Check in file '%s' at line %d failed: "                       \
                "'%" INT_FORMAT "' != '%" FLOAT_FORMAT "'\n",                  \
                __FILE__, __LINE__, (INT_TYPE)(value), (expected));            \
        exit(-1);                                                              \
      }                                                                        \
    } while(0)
#endif
