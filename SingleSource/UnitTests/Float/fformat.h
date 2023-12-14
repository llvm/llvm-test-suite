//===--- fformat.h - Descriptions of floating point formats -------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file contains some macro definitions useful for working with bit
// accurate floating point representations.
//
//===----------------------------------------------------------------------===//
#ifndef _FFORMAT_H_
#define _FFORMAT_H_

#define F32_SIGN_BIT        0x80000000U
#define F32_EXP_MASK        0x7F800000U
#define F32_MANTISSA_MASK   0x007FFFFFU
#define F32_MANTISSA_MSB    0x00400000U
#define F32_QNAN_BIT        F32_MANTISSA_MSB
#define F32_PAYLOAD_MASK    (F32_MANTISSA_MASK & ~F32_QNAN_BIT)
#define F32_SIGN_SHIFT      31
#define F32_EXP_SHIFT       23
#define F32_EXP_SIZE        (F32_SIGN_SHIFT - F32_EXP_SHIFT)
#define F32_MANTISSA_SIZE   F32_EXP_SHIFT
#define F32_EXP_BIAS        127
#define F32_EXP_MIN         (-126)
#define F32_EXP_MAX         127
#define F32_EXP(e)          (((e) + F32_EXP_BIAS) << F32_EXP_SHIFT)
#define F32_MANTISSA(b1, b2, b3)                                               \
    (((b1) ? F32_MANTISSA_MSB : 0) |                                           \
     ((b2) ? (F32_MANTISSA_MSB >> 1) : 0) |                                    \
     ((b3) ? (F32_MANTISSA_MSB >> 2) : 0))
#define F32_MAKE(s, e, m)                                                      \
    (((s) ? F32_SIGN_BIT : 0) |                                                \
     ((e) & F32_EXP_MASK) |                                                    \
     ((m) & F32_MANTISSA_MASK))
#define F32_NORMAL(s, e, m) F32_MAKE((s), F32_EXP(e), (m))


#define F64_SIGN_BIT        0x8000000000000000ULL
#define F64_EXP_MASK        0x7FF0000000000000ULL
#define F64_MANTISSA_MASK   0x000FFFFFFFFFFFFFULL
#define F64_MANTISSA_MSB    0x0008000000000000ULL
#define F64_QNAN_BIT        F64_MANTISSA_MSB
#define F64_PAYLOAD_MASK    (F64_MANTISSA_MASK & ~F64_QNAN_BIT)
#define F64_SIGN_SHIFT      63
#define F64_EXP_SHIFT       52
#define F64_EXP_SIZE        (F64_SIGN_SHIFT - F64_EXP_SHIFT)
#define F64_MANTISSA_SIZE   F64_EXP_SHIFT
#define F64_EXP_BIAS        1023
#define F64_EXP_MIN         (-1022)
#define F64_EXP_MAX         1023
#define F64_EXP(e)          (((uint64_t)(e) + F64_EXP_BIAS) << F64_EXP_SHIFT)
#define F64_MANTISSA(b1, b2, b3)                                               \
    (((b1) ? F64_MANTISSA_MSB : 0) |                                           \
     ((b2) ? (F64_MANTISSA_MSB >> 1) : 0) |                                    \
     ((b3) ? (F64_MANTISSA_MSB >> 2) : 0))
#define F64_MAKE(s, e, m)                                                      \
    (((s) ? F64_SIGN_BIT : 0) |                                                \
     ((e) & F64_EXP_MASK) |                                                    \
     ((m) & F64_MANTISSA_MASK))
#define F64_NORMAL(s, e, m) F64_MAKE((s), F64_EXP(e), (m))


#define F80_SIGN_BIT        0x0000000000008000ULL
#define F80_EXP_MASK        0x0000000000007FFFULL
#define F80_INTEGER_BIT     0x8000000000000000ULL
#define F80_FRACTIONAL_MASK 0x7FFFFFFFFFFFFFFFULL
#define F80_MANTISSA_MSB    0x4000000000000000ULL
#define F80_QNAN_BIT        F80_MANTISSA_MSB
#define F80_PAYLOAD_MASK    (F80_FRACTIONAL_MASK & ~F80_QNAN_BIT)
#define F80_SIGN_SHIFT      15
#define F80_EXP_BIAS        16383
#define F80_EXP_MIN         (-16382)
#define F80_EXP_MAX         16383
#define F80_EXP(e)          ((uint64_t)(e) + F80_EXP_BIAS)
#define F80_MANTISSA(b1, b2, b3)                                               \
    (((b1) ? F80_MANTISSA_MSB : 0) |                                           \
     ((b2) ? (F80_MANTISSA_MSB >> 1) : 0) |                                    \
     ((b3) ? (F80_MANTISSA_MSB >> 2) : 0))
#define F80_MAKE(s, e, m)   (m), (e) | ((s) ? F80_SIGN_BIT : 0)
#define F80_NORMAL(s, e, m) F80_MAKE((s), F80_EXP(e), F80_INTEGER_BIT | (m))

#endif
