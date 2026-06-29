//===--- util.h -- Utility functions shared by tests -------------- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _UTIL_H_
#define _UTIL_H_

#include <cstdint>
#include <cstdlib>
#include <iostream>

#define TEST16 1

static constexpr uint64_t V = 0x4243444546474849;
static constexpr int kThreads = 10;

// TODO: When support for other models is added, be sure to use constant values,
// perhaps using template arguments.
constexpr int atomic_fetch_models[] = {
  // TODO: Figure out a way to test all of these in parallel.
  // __ATOMIC_RELAXED, __ATOMIC_CONSUME, __ATOMIC_ACQUIRE,
  // __ATOMIC_ACQ_REL, __ATOMIC_RELEASE,
  __ATOMIC_SEQ_CST,
};
constexpr int atomic_exchange_models[] = {
  // TODO: Figure out a way to test all of these in parallel.
  // __ATOMIC_RELAXED, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE,
  // __ATOMIC_ACQ_REL,
  __ATOMIC_SEQ_CST,
};
constexpr int atomic_compare_exchange_models[] = {
  // TODO: Figure out a way to test all of these in parallel.
  // __ATOMIC_RELAXED, __ATOMIC_CONSUME, __ATOMIC_ACQUIRE,
  // __ATOMIC_ACQ_REL, __ATOMIC_RELEASE,
  __ATOMIC_SEQ_CST,
};

inline void fail() {
  std::cout << "FAILED\n";
  exit(1);
}

template <typename T>
constexpr uint8_t right_shift() {
  switch (sizeof(T)) {
    case 16:
      return 0;
    case 8:
      return 24;
    case 4:
      return 32 + 24;
    default:
      return 62;
  }
}

#endif  // _UTIL_H_
