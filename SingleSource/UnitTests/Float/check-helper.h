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

// Prints bits of a floating-point value, specified by the parameter 'value'.
// 'value' may an integer or a pointer to integer, the exact meaning is
// determined by macros VAL_FORMAT and GET_VALUE.
//
// Requires the following macros to be defined:
//
//     VAL_FORMAT - printf format specifier, like "%d" or "%llx %llx", which
//                  should be used to print the value represented by the
//                  argument 'value'.
//     GET_VALUE  - a macro that extracts the value or values for printing
//                  the 'value'.
//
#define PRINT_VALUE(value) printf(VAL_FORMAT, GET_VALUE(value));

// Checks if condition 'cond' is true for the 'value'.
//
// The argument 'value' is a pointer to the bits representing the tested
// floating-point value. It does not participate in checks and is used only for
// printing the tested value in diagnostics. Actual value to print is obtained
// using macro 'GET_VALUE'.
//
// Macros required to be defined are same as for PRINT_VALUE.
//
#define CHECK_VALUE(cond, value)                                               \
  do {                                                                         \
    if (!(cond)) {                                                             \
      printf("Check '%s' in file '%s' at line %d failed for the value '",      \
             #cond, __FILE__, __LINE__);                                       \
      PRINT_VALUE(value);                                                      \
      printf("'\n");                                                           \
      exit(-1);                                                                \
    }                                                                          \
  } while (0)

#endif
