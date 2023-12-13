//===--- gen_isfpclass_funcs.h ------------------------------------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file contains definition of functions that test a value of the
// specified floating point type for each of the floating point classes.
//
//===----------------------------------------------------------------------===//

// Requires macros to be defined: same as used by "test_isfpclass.h".

#ifndef _GEN_ISFPCLASS_FUNCS_H_
#define _GEN_ISFPCLASS_FUNCS_H_

enum FPClassCheck {
  fcBad = 0,
  fcSNan = 0x0001,
  fcQNan = 0x0002,
  fcNegInf = 0x0004,
  fcNegNormal = 0x0008,
  fcNegSubnormal = 0x0010,
  fcNegZero = 0x0020,
  fcPosZero = 0x0040,
  fcPosSubnormal = 0x0080,
  fcPosNormal = 0x0100,
  fcPosInf = 0x0200,

  fcNan = fcSNan | fcQNan,
  fcInf = fcPosInf | fcNegInf,
  fcNormal = fcPosNormal | fcNegNormal,
  fcSubnormal = fcPosSubnormal | fcNegSubnormal,
  fcZero = fcPosZero | fcNegZero,
  fcPosFinite = fcPosNormal | fcPosSubnormal | fcPosZero,
  fcNegFinite = fcNegNormal | fcNegSubnormal | fcNegZero,
  fcFinite = fcPosFinite | fcNegFinite,
  fcAllFlags = fcNan | fcInf | fcFinite
};

#endif

#define FPCLASS fcSNan
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcQNan
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcPosInf
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcNegInf
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcPosNormal
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcNegNormal
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcPosSubnormal
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcNegSubnormal
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcPosZero
#include "test_isfpclass.h"
#undef FPCLASS

#define FPCLASS fcNegZero
#include "test_isfpclass.h"
#undef FPCLASS
