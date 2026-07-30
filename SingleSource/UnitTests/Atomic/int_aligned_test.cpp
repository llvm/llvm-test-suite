//===--- int_aligned_test.cc -- Testing aligned integers ---------- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests atomic operations on signed and unsigned integer types with
// aligned memory addresses.
//
// The types tested are: uint32, uint64, int32, int64, uint128, int128.
// The ops tested are: add, sub, and, or, xor, xchg, xchg_n, cmpxchg, cmpxchg_n.
// The ALU operations are not tested on 128-bit integers.
//
// Please read the README before contributing.
//
//===----------------------------------------------------------------------===//

#include <sys/stat.h>

#include <cstdint>
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

template <typename T>
void looper_int_fetch_add(T *aint, int model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_add(aint, val, model);
}

template <typename T>
void test_int_fetch_add() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int model : atomic_fetch_models) {
    T aint = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_fetch_add<T>, &aint, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (aint != val * kExpected)
      fail();
  }
}

template <typename T>
void looper_int_fetch_sub(T *aint, int model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_sub(aint, val, model);
}

template <typename T>
void test_int_fetch_sub() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int model : atomic_fetch_models) {
    T aint = val * kExpected;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_fetch_sub<T>, &aint, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (aint != 0)
      fail();
  }
}

// The AND + OR tests work as follows:
//
// Each of the 10 threads "owns" one bit of the shared member. Each thread
// attempts to flip the bit it owns, from 1 -> 0 when testing AND, and 0 -> 1
// when testing OR. If successful, the thread increments a counter, and a
// cmpxchg loop flips the bit back. Once complete, that counter should equal
// 10^7.
template <typename T>
void __attribute__((optnone)) looper_int_fetch_and(const int id, T *aint,
                                                   T *acnt, int model) {
  T desired, expected = 0;
  for (int n = 0; n < kIterations; ++n) {
    const T mask = 1 << id;
    __atomic_fetch_and(aint, ~mask, model);
    if (~*aint & mask) {
      __atomic_fetch_add(acnt, 1, model);
      do {
        desired = expected | mask;
      } while (!__atomic_compare_exchange(aint, &expected, &desired, true,
                                          model, model));
    }
  }
}

template <typename T>
void test_int_fetch_and() {
  std::vector<std::thread> pool;
  for (int model : atomic_fetch_models) {
    T acnt = 0;
    T aint = ~0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_fetch_and<T>, n, &aint, &acnt, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (acnt != kExpected)
      fail();
  }
}

template <typename T>
void __attribute__((optnone)) looper_int_fetch_or(const int id, T *aint,
                                                  T *acnt, int model) {
  T desired, expected = 0;
  for (int n = 0; n < kIterations; ++n) {
    const T mask = 1 << id;
    __atomic_fetch_or(aint, mask, model);
    if (*aint & mask) {
      __atomic_fetch_add(acnt, 1, model);
      do {
        desired = expected & ~mask;
      } while (!__atomic_compare_exchange(aint, &expected, &desired, true,
                                          model, model));
    }
  }
}

template <typename T>
void test_int_fetch_or() {
  std::vector<std::thread> pool;
  for (int model : atomic_fetch_models) {
    T acnt = 0;
    T aint = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_fetch_or<T>, n, &aint, &acnt, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (acnt != kExpected)
      fail();
  }
}

template <typename T>
void looper_int_fetch_xor(T *aint, int model) {
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_xor(aint, n, model);
}

template <typename T>
void test_int_fetch_xor() {
  std::vector<std::thread> pool;
  for (int model : atomic_fetch_models) {
    T aint = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_fetch_xor<T>, &aint, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (aint != 0)
      fail();
  }
}

// The xchg tests work as follows:
//
// Each thread increments a local copy of the shared variable, and exchanges it
// with the shared value. Most of the time, the value moved from shared -> local
// is one less than the value moved from local -> shared. Other times, the
// difference is much bigger (or smaller). When this occurs, the thread
// accumulates the difference in a local error variable. Upon completion, the
// thread subtracts the error from the shared value, all at once.
//
// Like many tests, this test increments by more than 1 -- specifically, a
// number that scales with the width of the type is picked.
//
template <typename T>
void looper_int_xchg(T *aint, int model) {
  static constexpr T val = V >> right_shift<T>();
  __int128_t error = 0;
  T next = *aint + val;
  T result;
  for (int n = 0; n < kIterations; ++n) {
    __atomic_exchange(aint, &next, &result, model);
    error +=
        static_cast<__int128_t>(next) - static_cast<__int128_t>(result + val);
    next = result + val;
  }
  __atomic_fetch_sub(aint, static_cast<T>(error), model);
}

template <typename T>
void test_int_xchg() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int model : atomic_exchange_models) {
    T aint = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_xchg<T>, &aint, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (aint != val * kExpected)
      fail();
  }
}

template <typename T>
void looper_int_xchg_n(T *aint, int model) {
  static constexpr T val = V >> right_shift<T>();
  __int128_t error = 0;
  T next = *aint + val;
  for (int n = 0; n < kIterations; ++n) {
    T result = __atomic_exchange_n(aint, next, model);
    error +=
        static_cast<__int128_t>(next) - static_cast<__int128_t>(result + val);
    next = result + val;
  }
  __atomic_fetch_sub(aint, static_cast<T>(error), model);
}

template <typename T>
void test_int_xchg_n() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int model : atomic_exchange_models) {
    T aint = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_xchg_n<T>, &aint, model);
    for (int n = 0; n < kThreads; ++n) pool[n].join();
    pool.clear();
    if (aint != val * kExpected)
      fail();
  }
}

// The cmpxchg tests act similar to fetch_add tests.
template <typename T>
void looper_int_cmpxchg(T *aint, int success_model, int fail_model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n) {
    T desired, expected = 0;
    do {
      desired = expected + val;
    } while (!__atomic_compare_exchange(aint, &expected, &desired, true,
                                        success_model, fail_model));
  }
}

template <typename T>
void test_int_cmpxchg() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      T aint = 0;
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_int_cmpxchg<T>, &aint, success_model,
                          fail_model);
      for (int n = 0; n < kThreads; ++n) pool[n].join();
      pool.clear();
      if (aint != static_cast<T>(val) * kExpected)
        fail();
    }
  }
}

template <typename T>
void looper_int_cmpxchg_n(T *aint, int success_model, int fail_model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n) {
    T desired, expected = 0;
    do {
      desired = expected + val;
    } while (!__atomic_compare_exchange_n(aint, &expected, desired, true,
                                          success_model, fail_model));
  }
}

template <typename T>
void test_int_cmpxchg_n() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      T aint = 0;
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_int_cmpxchg_n<T>, &aint, success_model,
                          fail_model);
      for (int n = 0; n < kThreads; ++n) pool[n].join();
      pool.clear();
      if (aint != static_cast<T>(val) * kExpected)
        fail();
    }
  }
}

void test_aligned_int() {
#define INT_SUITE(type)                         \
  {                                             \
    std::cout << "Testing aligned " #type "\n"; \
    test_int_fetch_add<type>();                 \
    test_int_fetch_sub<type>();                 \
    test_int_fetch_and<type>();                 \
    test_int_fetch_or<type>();                  \
    test_int_fetch_xor<type>();                 \
    test_int_xchg<type>();                      \
    test_int_xchg_n<type>();                    \
    test_int_cmpxchg<type>();                   \
    test_int_cmpxchg_n<type>();                 \
  }
  INT_SUITE(uint32_t);
  INT_SUITE(uint64_t);
  INT_SUITE(int32_t);
  INT_SUITE(int64_t);
#undef INT_SUITE

#if TEST16
#define INT_SUITE(type)                         \
  {                                             \
    std::cout << "Testing aligned " #type "\n"; \
    test_int_xchg<type>();                      \
    test_int_xchg_n<type>();                    \
    test_int_cmpxchg<type>();                   \
    test_int_cmpxchg_n<type>();                 \
  }
  INT_SUITE(__uint128_t);
  INT_SUITE(__int128_t);
#undef INT_SUITE
#endif
}

int main() {
  test_aligned_int();
  std::cout << "PASSED\n";
}
