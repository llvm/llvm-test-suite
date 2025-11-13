#include <iostream>
#include <math.h>
#include <memory>
#include <optional>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 10000000

// Find the last element in A above the given threshold,
// with default loop vectorization settings.
template <typename T> static T run_csa_autovec(T *A, T *B, T *C, T Threshold) {
  // Pick out-of-range default value.
  T Result = 101;
  for (unsigned i = 0; i < ITERATIONS; i++) {
    // Do some work to make the difference noticeable
    C[i] = A[i] * 13 + B[i] * 5;
    if (A[i] > Threshold)
      Result = A[i];
  }

  return Result;
}

// Find the last element in A above the given threshold,
// with loop vectorization disabled.
template <typename T> static T run_csa_novec(T *A, T *B, T* C, T Threshold) {
  // Pick out-of-range default value.
  T Result = 101;
#pragma clang loop vectorize(disable) interleave(disable)
  for (unsigned i = 0; i < ITERATIONS; i++) {
    // Do some work to make the difference noticeable
    C[i] = A[i] * 13 + B[i] * 5;
    if (A[i] > Threshold)
      Result = A[i];
  }

  return Result;
}

// Initialize arrays A and B with random numbers, and zero array C
template <typename T> static void init_data(T *A, T* B, T *C) {
  std::uniform_int_distribution<T> dist(0, 100);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < ITERATIONS; i++) {
    A[i] = dist(rng);
    B[i] = dist(rng);
    C[i] = 0;
  }
}

// Benchmark auto-vectorized version using Fn.
template <typename T>
static void __attribute__((always_inline))
benchmark_csa_autovec(benchmark::State &state, T Threshold) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> B(new T[ITERATIONS]);
  std::unique_ptr<T[]> C(new T[ITERATIONS]);
  init_data(&A[0], &B[0], &C[0]);

#ifdef BENCH_AND_VERIFY
  // Verify the vectorized and un-vectorized versions produce the same results.
  {
    T VecRes = run_csa_novec(&A[0], &B[0], &C[0], Threshold);
    T NoVecRes = run_csa_autovec(&A[0], &B[0], &C[0], Threshold);
    // We're only interested in whether the conditional assignment results
    // were the same.
    if (VecRes != NoVecRes) {
      std::cerr << "ERROR: autovec result different to scalar result; "
                << VecRes << " != " << NoVecRes << "\n";
      exit(1);
    }
  }
#endif

  for (auto _ : state) {
    run_csa_autovec(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

// Benchmark version using Fn with vectorization disabled.
template <typename T>
static void __attribute__((always_inline))
benchmark_csa_novec(benchmark::State &state, T Threshold) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> B(new T[ITERATIONS]);
  std::unique_ptr<T[]> C(new T[ITERATIONS]);
  init_data(&A[0], &B[0], &C[0]);

  for (auto _ : state) {
    run_csa_novec(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
  }
}

// Add add auto-vectorized and disabled vectorization benchmarks for math
// function fn and type ty.
#define ADD_BENCHMARK(ty, Threshold)                                           \
  void BENCHMARK_csa_autovec_##ty##_(benchmark::State &state) {                \
    benchmark_csa_autovec<ty>(state, Threshold);                               \
  }                                                                            \
  BENCHMARK(BENCHMARK_csa_autovec_##ty##_)->Unit(benchmark::kMicrosecond);     \
                                                                               \
  void BENCHMARK_csa_novec_##ty##_(benchmark::State &state) {                  \
    benchmark_csa_novec<ty>(state, Threshold);                                 \
  }                                                                            \
  BENCHMARK(BENCHMARK_csa_novec_##ty##_)->Unit(benchmark::kMicrosecond);

ADD_BENCHMARK(int32_t, 75)
ADD_BENCHMARK(uint8_t, 90)
ADD_BENCHMARK(int64_t, 60)
