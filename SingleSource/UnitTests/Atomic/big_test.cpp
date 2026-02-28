//===--- big_test.cc -- Testing big (17+ byte) objects ------------ C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests atomic operations on big objects with aligned memory
// addresses.
//
// The types tested are: bigs.
// The ops tested are: cmpxchg.
// TODO: Test load/store, xchg.
//
// Please read the README before contributing.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include <thread>
#include <vector>

#include "util.h"

// V >> 56 = 66, so to prevent 32-bit overflow, kExpected must be less than
// 2^31 / 66 = 32 x 10^6.
#ifdef SMALL_PROBLEM_SIZE
static constexpr int kIterations = 1'000'000;
#else
static constexpr int kIterations = 3'000'000;
#endif
static constexpr int kExpected = kThreads * kIterations;
static constexpr int kBigSize = 10;
struct big_t {
  int v[kBigSize];
};

// The big struct cmpxchg test is identical to the numeric cmpxchg test, except
// each element of the underlying array is incremented.
void looper_big_cmpxchg(big_t *abig, int success_model, int fail_model) {
  for (int n = 0; n < kIterations; ++n) {
    big_t desired, expected = {};
    do {
      desired = expected;
      for (int k = 0; k < kBigSize; ++k)
        desired.v[k]++;
    } while (!__atomic_compare_exchange(abig, &expected, &desired, true,
                                        success_model, fail_model));
  }
}

void test_big_cmpxchg() {
  std::vector<std::thread> pool;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      big_t abig = {};
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_big_cmpxchg, &abig, success_model, fail_model);
      for (int n = 0; n < kThreads; ++n)
        pool[n].join();
      pool.clear();
      for (int n = 0; n < kBigSize; ++n)
        if (abig.v[n] != kExpected)
          fail();
    }
  }
}

void test_big() {
  std::cout << "Testing big\n";
  test_big_cmpxchg();
}

int main() {
  test_big();
  std::cout << "PASSED\n";
}
