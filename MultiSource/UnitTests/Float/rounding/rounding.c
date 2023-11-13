//===--- rounding.c --Tests for changing rounding mode ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Checks setting/getting rounding mode using builtin functions
// __builtin_flt_rounds and __builtin_set_flt_rounds.
//
//===----------------------------------------------------------------------===//

#include "rounding.h"
#include <stdio.h>

#ifdef FLOAT_AVAILABLE
// The "base" even values. They can be represented exactly and the lest
// significant bit of the significand is zero.
float PosEvenF = 0x1p+0F;
float NegEvenF = -0x1p+0F;

// The "base" odd values. They can be represented exactly and the lest
// significant bit of the significand is one.
float PosOddF = 0x1.000002p+0F;
float NegOddF = -0x1.000002p+0F;

// The values closest to the base ones with higher magnitude.
float NextToPosEvenF = 0x1.000002p+0F;
float NextToNegEvenF = -0x1.000002p+0F;
float NextToPosOddF = 0x1.000004p+0F;
float NextToNegOddF = -0x1.000004p+0F;

// Value that is half of the lest significant bit of the "base" value.
float PosDeltaF = 0x1.0p-24F;
float NegDeltaF = -0x1.0p-24F;
#endif

#ifdef DOUBLE_AVAILABLE
double PosEvenD = 0x1p+0;
double NegEvenD = -0x1p+0;

double PosOddD = 0x1.0000000000001p+0;
double NegOddD = -0x1.0000000000001p+0;

double NextToPosEvenD = 0x1.0000000000001p+0;
double NextToNegEvenD = -0x1.0000000000001p+0;
double NextToPosOddD = 0x1.0000000000002p+0;
double NextToNegOddD = -0x1.0000000000002p+0;

double PosDeltaD = 0x1.0p-52;
double NegDeltaD = -0x1.0p-52;
#endif

// Check macros. They may be overriden to implement different reaction on
// broken condition, rather that printing a message.

#ifndef REPORT_STAGE
#define REPORT_STAGE(x)   printf(x)
#endif

#ifndef CHECK_INT_EQ
#define CHECK_INT_EQ(VExp, VAct)                                               \
    if (VExp != VAct) {                                                        \
      printf("Failure on line %i -  expected: %d, actual: %d\n",               \
             __LINE__, VExp, VAct);                                            \
    }
#endif

#ifdef FLOAT_AVAILABLE
#ifndef CHECK_FLT_EQ
#define CHECK_FLT_EQ(VExp, VAct)                                               \
    if (VExp != VAct) {                                                        \
      printf("Failure on line %i -  expected: %a, actual: %a\n",               \
             __LINE__, VExp, VAct);                                            \
    }
#endif    
#endif

#ifdef DOUBLE_AVAILABLE
#ifndef CHECK_DBL_EQ
#define CHECK_DBL_EQ(VExp, VAct)                                               \
    if (VExp != VAct) {                                                        \
      printf("Failure on line %i -  expected: %la, actual: %la\n",             \
             __LINE__, VExp, VAct);                                            \
    }
#endif    
#endif

#ifdef FLOAT_AVAILABLE
static void check_float_toward_zero() {
  float Res;

  Res = PosEvenF + PosDeltaF;         // Rounds down
  CHECK_FLT_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Rounsd up
  CHECK_FLT_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd down
  CHECK_FLT_EQ(PosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounsd up
  CHECK_FLT_EQ(NegOddF, Res);
}

static void check_float_toward_nearest() {
  float Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd down
  CHECK_FLT_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds up
  CHECK_FLT_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd up
  CHECK_FLT_EQ(NextToPosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds down
  CHECK_FLT_EQ(NextToNegOddF, Res);
}

static void check_float_upward() {
  float Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd up
  CHECK_FLT_EQ(NextToPosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds up
  CHECK_FLT_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd up
  CHECK_FLT_EQ(NextToPosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds up
  CHECK_FLT_EQ(NegOddF, Res);
}

static void check_float_downward() {
  float Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd down
  CHECK_FLT_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds down
  CHECK_FLT_EQ(NextToNegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd down
  CHECK_FLT_EQ(PosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds down
  CHECK_FLT_EQ(NextToNegOddF, Res);
}

static void check_float() {
  #pragma STDC FENV_ACCESS ON

  REPORT_STAGE("Checking float\n");
  float Res;
  int RM;

  REPORT_STAGE("  towardzero\n");
  __builtin_set_flt_rounds(ROUNDING_TOWARDZERO);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TOWARDZERO, RM);
  check_float_toward_zero();
  
  REPORT_STAGE("  tonearest\n");
  __builtin_set_flt_rounds(ROUNDING_TONEAREST);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TONEAREST, RM);
  check_float_toward_nearest();
  
  REPORT_STAGE("  upward\n");
  __builtin_set_flt_rounds(ROUNDING_UPWARD);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_UPWARD, RM);
  check_float_upward();
 
  REPORT_STAGE("  downward\n");
  __builtin_set_flt_rounds(ROUNDING_DOWNWARD);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_DOWNWARD, RM);
  check_float_downward();

  REPORT_STAGE("  towardzero (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_TOWARDZERO);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TOWARDZERO, RM);
  check_float_toward_zero();
  
  REPORT_STAGE("  tonearest (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_TONEAREST);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TONEAREST, RM);
  check_float_toward_nearest();
  
  REPORT_STAGE("  upward (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_UPWARD);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_UPWARD, RM);
  check_float_upward();
 
  REPORT_STAGE("  downward (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_DOWNWARD);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_DOWNWARD, RM);
  check_float_downward();
}
#else
static void check_float() {}
#endif    

#ifdef DOUBLE_AVAILABLE
static void check_double_toward_zero() {
  double Res;

  Res = PosEvenF + PosDeltaF;         // Rounds down
  CHECK_DBL_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Rounsd up
  CHECK_DBL_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd down
  CHECK_DBL_EQ(PosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounsd up
  CHECK_DBL_EQ(NegOddF, Res);
}

static void check_double_toward_nearest() {
  double Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd down
  CHECK_DBL_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds up
  CHECK_DBL_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd up
  CHECK_DBL_EQ(NextToPosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds down
  CHECK_DBL_EQ(NextToNegOddF, Res);
}

static void check_double_upward() {
  double Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd up
  CHECK_DBL_EQ(NextToPosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds up
  CHECK_DBL_EQ(NegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd up
  CHECK_DBL_EQ(NextToPosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds up
  CHECK_DBL_EQ(NegOddF, Res);
}

static void check_double_downward() {
  double Res;

  Res = PosEvenF + PosDeltaF;         // Rounsd down
  CHECK_DBL_EQ(PosEvenF, Res);
  Res = NegEvenF + NegDeltaF;         // Pounds down
  CHECK_DBL_EQ(NextToNegEvenF, Res);

  Res = PosOddF + PosDeltaF;          // Rounsd down
  CHECK_DBL_EQ(PosOddF, Res);
  Res = NegOddF + NegDeltaF;          // Rounds down
  CHECK_DBL_EQ(NextToNegOddF, Res);
}

static void check_double() {
  #pragma STDC FENV_ACCESS ON

  REPORT_STAGE("Checking double\n");
  double Res;
  int RM;

  REPORT_STAGE("  towardzero\n");
  __builtin_set_flt_rounds(ROUNDING_TOWARDZERO);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TOWARDZERO, RM);
  check_double_toward_zero();
  
  REPORT_STAGE("  tonearest\n");
  __builtin_set_flt_rounds(ROUNDING_TONEAREST);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TONEAREST, RM);
  check_double_toward_nearest();
  
  REPORT_STAGE("  upward\n");
  __builtin_set_flt_rounds(ROUNDING_UPWARD);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_UPWARD, RM);
  check_double_upward();
 
  REPORT_STAGE("  downward\n");
  __builtin_set_flt_rounds(ROUNDING_DOWNWARD);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_DOWNWARD, RM);
  check_double_downward();

  REPORT_STAGE("  towardzero (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_TOWARDZERO);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TOWARDZERO, RM);
  check_double_toward_zero();
  
  REPORT_STAGE("  tonearest (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_TONEAREST);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_TONEAREST, RM);
  check_double_toward_nearest();
  
  REPORT_STAGE("  upward (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_UPWARD);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_UPWARD, RM);
  check_double_upward();
 
  REPORT_STAGE("  downward (dynamic)\n");
  RM = get_rounding_mode(ROUNDING_DOWNWARD);
  __builtin_set_flt_rounds(RM);
  RM = __builtin_flt_rounds();
  CHECK_INT_EQ(ROUNDING_DOWNWARD, RM);
  check_double_downward();
}
#else
static void check_double() {}
#endif    

int main(int argc, char *argv[]) {
  REPORT_STAGE("Checking rounding\n");
  check_float();
  check_double();
}
