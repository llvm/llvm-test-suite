//===--- int_misaligned_test.cc -- Testing unaligned integers ----- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file tests atomic operations on signed and unsigned integer types with
// unaligned memory addresses.
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
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include "util.h"

#ifdef SMALL_PROBLEM_SIZE
static constexpr int kIterations = 50'000;
#else
static constexpr int kIterations = 500'000;
#endif
static constexpr int kExpected = kThreads * kIterations;

template <typename T>
struct __attribute__((packed)) misaligned {
  char byte;
  T data;
  char pad[(31 - sizeof(T)) % 16];  // Pad struct to 16 or 32 bytes.
};

template <typename T>
void looper_int_misaligned_fetch_add(misaligned<T> &astruct, int model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_add(&astruct.data, val, model);
}

template <typename T>
void test_int_misaligned_fetch_add() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_fetch_models) {
    astruct.data = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_fetch_add<T>, std::ref(astruct),
                        model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (astruct.data != val * kExpected)
      fail();
  }
}

template <typename T>
void looper_int_misaligned_fetch_sub(misaligned<T> &astruct, int model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_sub(&astruct.data, val, model);
}

template <typename T>
void test_int_misaligned_fetch_sub() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_fetch_models) {
    astruct.data = val * kExpected;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_fetch_sub<T>, std::ref(astruct),
                        model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (astruct.data != 0)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of AND tests.
template <typename T>
void __attribute__((optnone)) looper_int_misaligned_fetch_and(
    const int id, misaligned<T> &astruct, T *acnt, int model) {
  T desired, expected = 0;
  for (int n = 0; n < kIterations; ++n) {
    const T mask = 1 << id;
    __atomic_fetch_and(&astruct.data, ~mask, model);
    if (~astruct.data & mask) {
      __atomic_fetch_add(acnt, 1, model);
      do {
        desired = expected | mask;
      } while (!__atomic_compare_exchange(&astruct.data, &expected, &desired,
                                          true, model, model));
    }
  }
}

template <typename T>
void test_int_misaligned_fetch_and() {
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_fetch_models) {
    T acnt = 0;
    astruct.data = ~0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_fetch_and<T>, n,
                        std::ref(astruct), &acnt, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (acnt != kExpected)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of OR tests.
template <typename T>
void __attribute__((optnone)) looper_int_misaligned_fetch_or(
    const int id, misaligned<T> &astruct, T *acnt, int model) {
  T desired, expected = 0;
  for (int n = 0; n < kIterations; ++n) {
    const T mask = 1 << id;
    __atomic_fetch_or(&astruct.data, mask, model);
    if (astruct.data & mask) {
      __atomic_fetch_add(acnt, 1, model);
      do {
        desired = expected & ~mask;
      } while (!__atomic_compare_exchange(&astruct.data, &expected, &desired,
                                          true, model, model));
    }
  }
}

template <typename T>
void test_int_misaligned_fetch_or() {
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_fetch_models) {
    T acnt = 0;
    astruct.data = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_fetch_or<T>, n,
                        std::ref(astruct), &acnt, model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (acnt != kExpected)
      fail();
  }
}

template <typename T>
void looper_int_misaligned_fetch_xor(misaligned<T> &astruct, int model) {
  for (int n = 0; n < kIterations; ++n)
    __atomic_fetch_xor(&astruct.data, n, model);
}

template <typename T>
void test_int_misaligned_fetch_xor() {
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_fetch_models) {
    astruct.data = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_fetch_xor<T>, std::ref(astruct),
                        model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (astruct.data != 0)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of xchg tests.
template <typename T>
void looper_int_misaligned_xchg(misaligned<T> &astruct, int model) {
  static constexpr T val = V >> right_shift<T>();
  __int128_t error = 0;
  T next = astruct.data + val;
  T result;
  for (int n = 0; n < kIterations; ++n) {
    __atomic_exchange(&astruct.data, &next, &result, model);
    error +=
        static_cast<__int128_t>(next) - static_cast<__int128_t>(result + val);
    next = result + val;
  }
  __atomic_fetch_sub(&astruct.data, static_cast<T>(error), model);
}

template <typename T>
void test_int_misaligned_xchg() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_exchange_models) {
    astruct.data = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_xchg<T>, std::ref(astruct),
                        model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (astruct.data != val * kExpected)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of xchg tests.
template <typename T>
void looper_int_misaligned_xchg_n(misaligned<T> &astruct, int model) {
  static constexpr T val = V >> right_shift<T>();
  __int128_t error = 0;
  T next = astruct.data + val;
  for (int n = 0; n < kIterations; ++n) {
    T result = __atomic_exchange_n(&astruct.data, next, model);
    error +=
        static_cast<__int128_t>(next) - static_cast<__int128_t>(result + val);
    next = result + val;
  }
  __atomic_fetch_sub(&astruct.data, static_cast<T>(error), model);
}

template <typename T>
void test_int_misaligned_xchg_n() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int model : atomic_exchange_models) {
    astruct.data = 0;
    for (int n = 0; n < kThreads; ++n)
      pool.emplace_back(looper_int_misaligned_xchg_n<T>, std::ref(astruct),
                        model);
    for (int n = 0; n < kThreads; ++n)
      pool[n].join();
    pool.clear();
    if (astruct.data != val * kExpected)
      fail();
  }
}

// See int_aligned_test.cc for an explanation of cmpxchg tests.
template <typename T>
void looper_int_misaligned_cmpxchg(misaligned<T> &astruct, int success_model,
                                   int fail_model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n) {
    T desired, expected = 0;
    do {
      desired = expected + val;
    } while (!__atomic_compare_exchange(&astruct.data, &expected, &desired,
                                        true, success_model, fail_model));
  }
}

template <typename T>
void test_int_misaligned_cmpxchg() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      astruct.data = 0;
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_int_misaligned_cmpxchg<T>, std::ref(astruct),
                          success_model, fail_model);
      for (int n = 0; n < kThreads; ++n)
        pool[n].join();
      pool.clear();
      if (astruct.data != static_cast<T>(val) * kExpected)
        fail();
    }
  }
}

// See int_aligned_test.cc for an explanation of cmpxchg tests.
template <typename T>
void looper_int_misaligned_cmpxchg_n(misaligned<T> &astruct, int success_model,
                                     int fail_model) {
  static constexpr T val = V >> right_shift<T>();
  for (int n = 0; n < kIterations; ++n) {
    T desired, expected = 0;
    do {
      desired = expected + val;
    } while (!__atomic_compare_exchange_n(&astruct.data, &expected, desired,
                                          true, success_model, fail_model));
  }
}

template <typename T>
void test_int_misaligned_cmpxchg_n() {
  static constexpr T val = V >> right_shift<T>();
  std::vector<std::thread> pool;
  misaligned<T> astruct;
  for (int success_model : atomic_compare_exchange_models) {
    for (int fail_model : atomic_compare_exchange_models) {
      astruct.data = 0;
      for (int n = 0; n < kThreads; ++n)
        pool.emplace_back(looper_int_misaligned_cmpxchg_n<T>, std::ref(astruct),
                          success_model, fail_model);
      for (int n = 0; n < kThreads; ++n)
        pool[n].join();
      pool.clear();
      if (astruct.data != static_cast<T>(val) * kExpected)
        fail();
    }
  }
}

void test_misaligned_int() {
#define INT_SUITE(type)                            \
  {                                                \
    std::cout << "Testing misaligned " #type "\n"; \
    test_int_misaligned_fetch_add<type>();         \
    test_int_misaligned_fetch_sub<type>();         \
    test_int_misaligned_fetch_and<type>();         \
    test_int_misaligned_fetch_or<type>();          \
    test_int_misaligned_fetch_xor<type>();         \
    test_int_misaligned_xchg<type>();              \
    test_int_misaligned_xchg_n<type>();            \
    test_int_misaligned_cmpxchg<type>();           \
    test_int_misaligned_cmpxchg_n<type>();         \
  }
  INT_SUITE(uint32_t);
  INT_SUITE(uint64_t);
  INT_SUITE(int32_t);
  INT_SUITE(int64_t);
#undef INT_SUITE

#if TEST16
#define INT_SUITE(type)                            \
  {                                                \
    std::cout << "Testing misaligned " #type "\n"; \
    test_int_misaligned_xchg<type>();              \
    test_int_misaligned_xchg_n<type>();            \
    test_int_misaligned_cmpxchg<type>();           \
    test_int_misaligned_cmpxchg_n<type>();         \
  }
  INT_SUITE(__uint128_t);
  INT_SUITE(__int128_t);
#undef INT_SUITE
#endif
}

int main() {
  test_misaligned_int();
  std::cout << "PASSED\n";
}
