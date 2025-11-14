#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 100000

template <typename T>
using CSAFunc = T (*)(T *, T *, T *, T);

// Find the last element in A above the given threshold,
// with default loop vectorization settings.
template <typename T>
static T run_single_csa_only_autovec(T *A, T *B, T *C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A' in init_data below.
  T Result = 101;
  for (unsigned i = 0; i < ITERATIONS; i++)
    if (A[i] > Threshold)
      Result = A[i];

  return Result;
}

// Find the last element in A above the given threshold,
// with loop vectorization disabled.
template <typename T>
static T run_single_csa_only_novec(T *A, T *B, T *C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A' in init_data below.
  T Result = 101;
#pragma clang loop vectorize(disable) interleave(disable)
  for (unsigned i = 0; i < ITERATIONS; i++)
    if (A[i] > Threshold)
      Result = A[i];

  return Result;
}

// Find the last elements in A, B, and C above the given threshold,
// with default loop vectorization settings.
template <typename T>
static T run_multi_csa_only_autovec(T *A, T *B, T *C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A', 'B', and 'C' in init_data below.
  T ResultA = 101;
  T ResultB = 101;
  T ResultC = 101;
  for (unsigned i = 0; i < ITERATIONS; i++) {
    if (A[i] > Threshold)
      ResultA = A[i];
    if (B[i] > Threshold)
      ResultB = B[i];
    if (C[i] > Threshold)
      ResultC = C[i];
  }

  return ResultA ^ ResultB ^ ResultC;
}

// Find the last elements in A, B, and C above the given threshold,
// with loop vectorization disabled.
template <typename T>
static T run_multi_csa_only_novec(T *A, T *B, T *C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A', 'B', and 'C' in init_data below.
  T ResultA = 101;
  T ResultB = 101;
  T ResultC = 101;
#pragma clang loop vectorize(disable) interleave(disable)
  for (unsigned i = 0; i < ITERATIONS; i++) {
    if (A[i] > Threshold)
      ResultA = A[i];
    if (B[i] > Threshold)
      ResultB = B[i];
    if (C[i] > Threshold)
      ResultC = C[i];
  }

  return ResultA ^ ResultB ^ ResultC;
}

// Find the last element in A above the given threshold,
// with default loop vectorization settings.
template <typename T>
static T run_csa_with_arith_autovec(T *A, T *B, T *C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A' in init_data below.
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
template <typename T>
static T run_csa_with_arith_novec(T *A, T *B, T* C, T Threshold) {
  // Pick a default value that's out of range of the uniform distribution
  // created for 'A' in init_data below.
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

// Initialize arrays A, B, and C with random numbers
template <typename T> static void init_data(T *A, T* B, T *C) {
  std::uniform_int_distribution<T> dist(0, 100);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < ITERATIONS; i++) {
    A[i] = dist(rng);
    B[i] = dist(rng);
    C[i] = dist(rng);
  }
}

// Benchmark auto-vectorized version.
template <typename T>
static void __attribute__((always_inline))
benchmark_csa_autovec(benchmark::State &state, CSAFunc<T> VecFn,
                      CSAFunc<T> NoVecFn, T Threshold) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> B(new T[ITERATIONS]);
  std::unique_ptr<T[]> C(new T[ITERATIONS]);
  init_data(&A[0], &B[0], &C[0]);

#ifdef BENCH_AND_VERIFY
  // Verify the vectorized and un-vectorized versions produce the same results.
  {
    T VecRes = VecFn(&A[0], &B[0], &C[0], Threshold);
    T NoVecRes = NoVecFn(&A[0], &B[0], &C[0], Threshold);
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
    VecFn(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

// Benchmark version with vectorization disabled.
template <typename T>
static void __attribute__((always_inline))
benchmark_csa_novec(benchmark::State &state, CSAFunc<T> NoVecFn, T Threshold) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> B(new T[ITERATIONS]);
  std::unique_ptr<T[]> C(new T[ITERATIONS]);
  init_data(&A[0], &B[0], &C[0]);

  for (auto _ : state) {
    NoVecFn(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
  }
}

// Add benchmarks with and without auto-vectorization
#define ADD_BENCHMARK(ty, Threshold)                                           \
  void BENCHMARK_single_csa_only_autovec_##ty##_(benchmark::State &state) {    \
    benchmark_csa_autovec<ty>(state, run_single_csa_only_autovec,              \
                              run_single_csa_only_novec, Threshold);           \
  }                                                                            \
  BENCHMARK(BENCHMARK_single_csa_only_autovec_##ty##_)->Unit(                  \
                                                      benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_single_csa_only_novec_##ty##_(benchmark::State &state) {      \
    benchmark_csa_novec<ty>(state, run_single_csa_only_novec, Threshold);      \
  }                                                                            \
  BENCHMARK(BENCHMARK_single_csa_only_novec_##ty##_)->Unit(                    \
                                                      benchmark::kNanosecond); \
  void BENCHMARK_multi_csa_only_autovec_##ty##_(benchmark::State &state) {     \
    benchmark_csa_autovec<ty>(state, run_multi_csa_only_autovec,               \
                              run_multi_csa_only_novec, Threshold);            \
  }                                                                            \
  BENCHMARK(BENCHMARK_multi_csa_only_autovec_##ty##_)->Unit(                   \
                                                      benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_multi_csa_only_novec_##ty##_(benchmark::State &state) {       \
    benchmark_csa_novec<ty>(state, run_multi_csa_only_novec, Threshold);       \
  }                                                                            \
  BENCHMARK(BENCHMARK_multi_csa_only_novec_##ty##_)->Unit(                     \
                                                      benchmark::kNanosecond); \
  void BENCHMARK_csa_with_arith_autovec_##ty##_(benchmark::State &state) {     \
    benchmark_csa_autovec<ty>(state, run_csa_with_arith_autovec,               \
                              run_csa_with_arith_novec, Threshold);            \
  }                                                                            \
  BENCHMARK(BENCHMARK_csa_with_arith_autovec_##ty##_)->Unit(                   \
                                                      benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_csa_with_arith_novec_##ty##_(benchmark::State &state) {       \
    benchmark_csa_novec<ty>(state, run_csa_with_arith_novec, Threshold);       \
  }                                                                            \
  BENCHMARK(BENCHMARK_csa_with_arith_novec_##ty##_)->Unit(                     \
                                                        benchmark::kNanosecond);

ADD_BENCHMARK(int32_t, 75)
ADD_BENCHMARK(uint8_t, 90)
ADD_BENCHMARK(int64_t, 60)
