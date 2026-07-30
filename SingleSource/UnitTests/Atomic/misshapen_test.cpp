//===--- misshapen.cc -- Testing non-power-of-2 byte objects ------ C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests atomic operations on oddly sized objects with aligned
// memory addresses.
//
// The types tested are: 3 byte up to 15 byte objects (skipping 4 & 8).
// The ops tested are: xchg, cmpxchg.
//
// Please read the README before contributing.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include <thread>
#include <vector>

#include "util.h"

#ifdef SMALL_PROBLEM_SIZE
static constexpr int kIterations = 100'000;
#else
static constexpr int kIterations = 1'000'000;
#endif
static constexpr int kExpected = kThreads * kIterations;

template<int N>
struct misshapen {
  unsigned char v[N];
};

// See int_aligned_test.cc for an explanation of xchg tests.
template <int N>
void looper_misshapen_xchg(misshapen<N> *amis, int model) {
  unsigned char error[N] = {};
  misshapen<N> next, result;
  __atomic_load(amis, &next, model);
  for (int k = 0; k < N; ++k)
    next.v[k]++;
  for (int n = 0; n < kIterations; ++n) {
    __atomic_exchange(amis, &next, &result, model);
    for (int k = 0; k < N; ++k) {
      error[k] += next.v[k] - (result.v[k] + 1);
      next.v[k] = result.v[k] + 1;
    }
  }
  // We can't use atomic_sub here; combining atomic operations on array members
  // and the array as a whole is undefined.
  misshapen<N> desired, expected;
  __atomic_load(amis, &expected, model);
  do {
    desired = expected;
    for (int k = 0; k < N; ++k)
      desired.v[k] -= error[k];
  } while (!__atomic_compare_exchange(amis, &expected, &desired, true,
                                      model, model));
}

template <int N>
void test_misshapen_xchg() {
  std::vector<std::thread> pool;
  for (int model : atomic_exchange_models) {
    misshapen<N> amis = {};
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_misshapen_xchg<N>, &amis, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    for (int n = 0; n < N; ++n)
      if (amis.v[n] != kExpected % (1 << (8 * sizeof(amis.v[0]))))
        fail();
  }
}

// See int_aligned_test.cc for an explanation of cmpxchg tests.
template <int N>
void looper_misshapen_cmpxchg(misshapen<N> *amis, int success_model,
                              int fail_model) {
  for (int n = 0; n < kIterations; ++n) {
    misshapen<N> desired, expected = {};
    do {
      desired = expected;
      for (int k = 0; k < N; ++k)
        desired.v[k]++;
    } while (!__atomic_compare_exchange(amis, &expected, &desired, true,
                                        success_model, fail_model));
  }
}

template <int N>
void test_misshapen_cmpxchg() {
  std::vector<std::thread> pool;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      misshapen<N> amis = {};
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_misshapen_cmpxchg<N>, &amis, success_model,
                          fail_model);
      for (int n = 0; n < kThreads; ++n)
        pool[n].join();
      pool.clear();
      for (int n = 0; n < N; ++n)
        if (amis.v[n] != kExpected % (1 << (8 * sizeof(amis.v[0]))))
          fail();
    }
  }
}

void test_misshapen() {
  std::cout << "Testing misshapen 3 byte\n";
  test_misshapen_xchg<3>();
  test_misshapen_cmpxchg<3>();
  // Skip 4.
  std::cout << "Testing misshapen 5 byte\n";
  test_misshapen_xchg<5>();
  test_misshapen_cmpxchg<5>();
  std::cout << "Testing misshapen 6 byte\n";
  test_misshapen_xchg<6>();
  test_misshapen_cmpxchg<6>();
  std::cout << "Testing misshapen 7 byte\n";
  test_misshapen_xchg<7>();
  test_misshapen_cmpxchg<7>();
  // Skip 8.
  std::cout << "Testing misshapen 9 byte\n";
  test_misshapen_xchg<9>();
  test_misshapen_cmpxchg<9>();
  std::cout << "Testing misshapen 10 byte\n";
  test_misshapen_xchg<10>();
  test_misshapen_cmpxchg<10>();
  std::cout << "Testing misshapen 11 byte\n";
  test_misshapen_xchg<11>();
  test_misshapen_cmpxchg<11>();
  std::cout << "Testing misshapen 12 byte\n";
  test_misshapen_xchg<12>();
  test_misshapen_cmpxchg<12>();
  std::cout << "Testing misshapen 13 byte\n";
  test_misshapen_xchg<13>();
  test_misshapen_cmpxchg<13>();
  std::cout << "Testing misshapen 14 byte\n";
  test_misshapen_xchg<14>();
  test_misshapen_cmpxchg<14>();
  std::cout << "Testing misshapen 15 byte\n";
  test_misshapen_xchg<15>();
  test_misshapen_cmpxchg<15>();
}

int main() {
  test_misshapen();
  std::cout << "PASSED\n";
}
