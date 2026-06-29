//===--- float_test.cc -- Testing aligned floating point numbers -- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests atomic operations on floating point types with aligned
// memory addresses.
//
// The types tested are: float, double, float128.
// The ops tested are: xchg, cmpxchg.
//
// Please read the README before contributing.
//
//===----------------------------------------------------------------------===//

#include <sys/stat.h>

#include <iostream>
#include <thread>
#include <vector>

#include "util.h"

// There are 23-bits in the mantissa of a single-precision float.
// Therefore, kExpected cannot exceed 2^24.
static constexpr int kIterations = 1'500'000;
static constexpr int kExpected = kThreads * kIterations;

// See int_aligned_test.cc for an explanation of xchg tests.
template <typename T>
void looper_float_scalar_xchg(T *afloat, int model) {
  __int128_t error = 0;
  T next = *afloat + 1;
  T result;
  for (int n = 0; n < kIterations; ++n) {
    __atomic_exchange(afloat, &next, &result, model);
    error +=
        static_cast<__int128_t>(next) - static_cast<__int128_t>(result + 1);
    next = result + 1;
  }
  __atomic_fetch_sub(afloat, static_cast<T>(error), model);
}

template <typename T>
void test_float_scalar_xchg() {
  std::vector<std::thread> pool;
  for (int model : atomic_exchange_models) {
    T afloat = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_float_scalar_xchg<T>, &afloat, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (afloat != kExpected)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of cmpxchg tests.
template <typename T>
void looper_float_scalar_cmpxchg(T *afloat, int success_model, int fail_model) {
  for (int n = 0; n < kIterations; ++n) {
    T desired, expected = 0;
    do {
      desired = expected + 1;
    } while (!__atomic_compare_exchange(afloat, &expected, &desired, true,
                                        success_model, fail_model));
  }
}

template <typename T>
void test_float_scalar_cmpxchg() {
  std::vector<std::thread> pool;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      T afloat = 0;
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_float_scalar_cmpxchg<T>, &afloat,
                          success_model, fail_model);
      for (int n = 0; n < kThreads; ++n)
        pool[n].join();
      pool.clear();
      if (afloat != kExpected)
        fail();
    }
  }
}

void test_floating_point() {
  std::cout << "Testing float\n";
  test_float_scalar_xchg<float>();
  test_float_scalar_cmpxchg<float>();

  std::cout << "Testing double\n";
  test_float_scalar_xchg<double>();
  test_float_scalar_cmpxchg<double>();

  std::cout << "Testing float128\n";
  test_float_scalar_xchg<__float128>();
  test_float_scalar_cmpxchg<__float128>();
}

int main() {
  test_floating_point();
  std::cout << "PASSED\n";
}
