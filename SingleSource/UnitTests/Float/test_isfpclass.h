//===--- test_isfpclass.h -----------------------------------------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file contains definition of a function that tests a value of
// the specified floating point class for various combinations of the check
// made by `__builtin_isfpclass`. The function has a name and arguments like:
// `test_fcSNan_float(float x)`.
//
//===----------------------------------------------------------------------===//

// Requires the following macros to be defined:
//
//     VAL_FORMAT - printf format specifier for value(s) extracted by GET_VALUE.
//     GET_VALUE  - a macro that extracts value(s) for printing.
//     FPCLASS    - FP class of the test function argument.
//     FLOAT_TYPE - type of test function argument.

#define CONCAT(fpclass, fptype) test_##fpclass##_##fptype
#define TEST_FUNC(fpclass, fptype) CONCAT(fpclass, fptype)

#define CHECK_CLASS(cond, value)                                               \
  do {                                                                         \
    if (!(cond)) {                                                             \
      printf("Check '%s' failed for the value '" VAL_FORMAT "' "               \
             ", FPCLASS=0x%x\n",                                               \
             #cond, GET_VALUE(&value), FPCLASS);                               \
      exit(-1);                                                                \
    }                                                                          \
  } while (0)

#define CHECK(flags, value)                                                    \
  CHECK_CLASS(!!((flags)&FPCLASS) == !!__builtin_isfpclass((value), (flags)),  \
              (value))

void TEST_FUNC(FPCLASS, FLOAT_TYPE)(FLOAT_TYPE x) {
  CHECK(fcSNan, x);
  CHECK(fcQNan, x);
  CHECK(fcNan, x);
  CHECK(fcPosInf, x);
  CHECK(fcNegInf, x);
  CHECK(fcInf, x);
  CHECK(fcPosNormal, x);
  CHECK(fcNegNormal, x);
  CHECK(fcNormal, x);
  CHECK(fcPosSubnormal, x);
  CHECK(fcNegSubnormal, x);
  CHECK(fcSubnormal, x);
  CHECK(fcPosZero, x);
  CHECK(fcNegZero, x);
  CHECK(fcZero, x);
  CHECK(fcPosFinite, x);
  CHECK(fcNegFinite, x);
  CHECK(fcFinite, x);

  CHECK(fcQNan | fcInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcSNan | fcInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcNegInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcPosInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcNegNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcPosNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcNegSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcPosSubnormal | fcZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcSubnormal | fcNegZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcSubnormal | fcPosZero, x);
  CHECK(fcNan | fcInf | fcNormal | fcSubnormal, x);
  CHECK(fcNan | fcInf | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcNan | fcInf | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcNan | fcInf, x);

  CHECK(fcSNan | fcPosInf, x);
  CHECK(fcSNan | fcNegInf, x);
  CHECK(fcSNan | fcInf, x);
  CHECK(fcSNan | fcPosNormal, x);
  CHECK(fcSNan | fcNegNormal, x);
  CHECK(fcSNan | fcNormal, x);
  CHECK(fcSNan | fcPosSubnormal, x);
  CHECK(fcSNan | fcNegSubnormal, x);
  CHECK(fcSNan | fcSubnormal, x);
  CHECK(fcSNan | fcPosZero, x);
  CHECK(fcSNan | fcNegZero, x);
  CHECK(fcSNan | fcZero, x);
  CHECK(fcSNan | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcSNan | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcSNan | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcQNan | fcPosInf, x);
  CHECK(fcQNan | fcNegInf, x);
  CHECK(fcQNan | fcInf, x);
  CHECK(fcQNan | fcPosNormal, x);
  CHECK(fcQNan | fcNegNormal, x);
  CHECK(fcQNan | fcNormal, x);
  CHECK(fcQNan | fcPosSubnormal, x);
  CHECK(fcQNan | fcNegSubnormal, x);
  CHECK(fcQNan | fcSubnormal, x);
  CHECK(fcQNan | fcPosZero, x);
  CHECK(fcQNan | fcNegZero, x);
  CHECK(fcQNan | fcZero, x);
  CHECK(fcQNan | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcQNan | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcQNan | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNan | fcPosInf, x);
  CHECK(fcNan | fcNegInf, x);
  CHECK(fcNan | fcPosNormal, x);
  CHECK(fcNan | fcNegNormal, x);
  CHECK(fcNan | fcNormal, x);
  CHECK(fcNan | fcPosSubnormal, x);
  CHECK(fcNan | fcNegSubnormal, x);
  CHECK(fcNan | fcSubnormal, x);
  CHECK(fcNan | fcPosZero, x);
  CHECK(fcNan | fcNegZero, x);
  CHECK(fcNan | fcZero, x);
  CHECK(fcNan | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcNan | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcPosInf | fcPosNormal, x);
  CHECK(fcPosInf | fcNegNormal, x);
  CHECK(fcPosInf | fcNormal, x);
  CHECK(fcPosInf | fcPosSubnormal, x);
  CHECK(fcPosInf | fcNegSubnormal, x);
  CHECK(fcPosInf | fcSubnormal, x);
  CHECK(fcPosInf | fcPosZero, x);
  CHECK(fcPosInf | fcNegZero, x);
  CHECK(fcPosInf | fcZero, x);
  CHECK(fcPosInf | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcPosInf | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcPosInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcNegInf | fcPosNormal, x);
  CHECK(fcNegInf | fcNegNormal, x);
  CHECK(fcNegInf | fcNormal, x);
  CHECK(fcNegInf | fcPosSubnormal, x);
  CHECK(fcNegInf | fcNegSubnormal, x);
  CHECK(fcNegInf | fcSubnormal, x);
  CHECK(fcNegInf | fcPosZero, x);
  CHECK(fcNegInf | fcNegZero, x);
  CHECK(fcNegInf | fcZero, x);
  CHECK(fcNegInf | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcNegInf | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcNegInf | fcNormal | fcSubnormal | fcZero, x);
  CHECK(fcInf | fcPosNormal, x);
  CHECK(fcInf | fcNegNormal, x);
  CHECK(fcInf | fcNormal, x);
  CHECK(fcInf | fcPosSubnormal, x);
  CHECK(fcInf | fcNegSubnormal, x);
  CHECK(fcInf | fcSubnormal, x);
  CHECK(fcInf | fcPosZero, x);
  CHECK(fcInf | fcNegZero, x);
  CHECK(fcInf | fcZero, x);
  CHECK(fcInf | fcPosNormal | fcPosSubnormal | fcPosZero, x);
  CHECK(fcInf | fcNegNormal | fcNegSubnormal | fcNegZero, x);
  CHECK(fcPosNormal | fcPosSubnormal, x);
  CHECK(fcPosNormal | fcNegSubnormal, x);
  CHECK(fcPosNormal | fcSubnormal, x);
  CHECK(fcPosNormal | fcPosZero, x);
  CHECK(fcPosNormal | fcNegZero, x);
  CHECK(fcPosNormal | fcZero, x);
  CHECK(fcNegNormal | fcPosSubnormal, x);
  CHECK(fcNegNormal | fcNegSubnormal, x);
  CHECK(fcNegNormal | fcSubnormal, x);
  CHECK(fcNegNormal | fcPosZero, x);
  CHECK(fcNegNormal | fcNegZero, x);
  CHECK(fcNegNormal | fcZero, x);
  CHECK(fcNormal | fcPosSubnormal, x);
  CHECK(fcNormal | fcNegSubnormal, x);
  CHECK(fcNormal | fcSubnormal, x);
  CHECK(fcNormal | fcPosZero, x);
  CHECK(fcNormal | fcNegZero, x);
  CHECK(fcNormal | fcZero, x);
  CHECK(fcPosSubnormal | fcPosZero, x);
  CHECK(fcPosSubnormal | fcNegZero, x);
  CHECK(fcPosSubnormal | fcZero, x);
  CHECK(fcNegNormal | fcSubnormal | fcNegZero, x);
  CHECK(fcNegSubnormal | fcPosZero, x);
  CHECK(fcNegSubnormal | fcNegZero, x);
  CHECK(fcNegSubnormal | fcZero, x);
  CHECK(fcPosNormal | fcSubnormal | fcPosZero, x);
  CHECK(fcSubnormal | fcPosZero, x);
  CHECK(fcSubnormal | fcNegZero, x);
  CHECK(fcSubnormal | fcZero, x);
  CHECK(fcNegNormal | fcNegSubnormal | fcZero, x);
  CHECK(fcPosNormal | fcPosSubnormal | fcZero, x);
}

#undef CHECK
#undef CHECK_CLASS
#undef TEST_FUNC
#undef CONCAT
