#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 100000

template <typename T>
using CSAFunc = T (*)(T *, T *, T *, T);

#define INIT_BLOCK
#define LOOP_BLOCK
#define EXIT_BLOCK

#define _Args(...) __VA_ARGS__
#define STRIP_PARENS(X) X
#define INIT_VARS(X) STRIP_PARENS(_Args X)

#define DEF_CSA_LOOP(name, init, body, result)                                 \
  template <typename T>                                                        \
  __attribute__((noinline)) static T run_##name##_autovec(T *A, T *B, T *C,    \
                                                          T Threshold) {       \
    INIT_VARS(init);                                                           \
    for (unsigned i = 0; i < ITERATIONS; i++)                                  \
      body;                                                                    \
    result;                                                                    \
  }                                                                            \
  template <typename T>                                                        \
  __attribute__((noinline)) static T run_##name##_novec(T *A, T *B, T *C,      \
                                                        T Threshold) {         \
    INIT_VARS(init);                                                           \
    _Pragma("clang loop vectorize(disable) interleave(disable)")               \
                                                                               \
        for (unsigned i = 0; i < ITERATIONS; i++) body;                        \
    result;                                                                    \
  }

#define DEF_SINGLE_CSA_LOOP(name, body)                                        \
  DEF_CSA_LOOP(name,                                                           \
               (/* Pick a default value that's out of range of the uniform     \
                 * distribution created for 'A' in init_data below. */         \
                T Result = 101;),                                              \
               body, ({ return Result; }));

// Find the last element in A above the given threshold.
DEF_SINGLE_CSA_LOOP(single_csa_only, LOOP_BLOCK({
                      if (A[i] > Threshold)
                        Result = A[i];
                    }));

// Find the last element in B where the corresponding value in A is above the
// given threshold.
DEF_SINGLE_CSA_LOOP(single_csa_cond_load, LOOP_BLOCK({
                      if (A[i] > Threshold)
                        Result = B[i];
                    }));

// Find the last element in B where the corresponding value in C is below the
// given threshold and the corresponding in A is above the threshold.
DEF_SINGLE_CSA_LOOP(single_csa_nested_cond_load, LOOP_BLOCK({
                      if (C[i] < Threshold)
                        if (A[i] > Threshold)
                          Result = B[i];
                    }));

// Find the last element in A above the given threshold, and use it to perform
// some arith (that may need masking).
DEF_SINGLE_CSA_LOOP(csa_with_cond_arith, LOOP_BLOCK({
                      if (A[i] > Threshold)
                        Result = (A[i] * 13) / B[i];
                    }));

// Find the last element in A above the given threshold (+ some arith).
DEF_SINGLE_CSA_LOOP(csa_with_arith, LOOP_BLOCK({
                      // Do some work to make the difference noticeable
                      C[i] = A[i] * 13 + B[i] * 5;
                      if (A[i] > Threshold)
                        Result = A[i];
                    }));

// Find the last elements in A, B, and C above the given threshold.
DEF_CSA_LOOP(
    multi_csa_only,
    INIT_BLOCK(
        // Pick a default value that's out of range of the uniform
        // distribution created for 'A', 'B', and 'C' in init_data below.
        T ResultA = 101; T ResultB = 101; T ResultC = 101;),
    LOOP_BLOCK({
      if (A[i] > Threshold)
        ResultA = A[i];
      if (B[i] > Threshold)
        ResultB = B[i];
      if (C[i] > Threshold)
        ResultC = C[i];
    }),
    EXIT_BLOCK({ return ResultA ^ ResultB ^ ResultC; }));

// Find the last elements in A, B, and C above the given threshold. Sets the
// result to `N / the element`, which is UB if the element is zero.
DEF_CSA_LOOP(
    multi_csa_with_cond_arith,
    INIT_BLOCK(
        // Pick a default value that's out of range of the uniform
        // distribution created for 'A', 'B', and 'C' in init_data below.
        T ResultA = 101; T ResultB = 101; T ResultC = 101;),
    LOOP_BLOCK({
      if (A[i] > Threshold)
        ResultA = 7 / A[i];
      if (B[i] > Threshold)
        ResultB = 4 / B[i];
      if (C[i] > Threshold)
        ResultC = 10 / C[i];
    }),
    EXIT_BLOCK({ return ResultA ^ ResultB ^ ResultC; }));

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
    T Res = VecFn(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::DoNotOptimize(Res);
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
    T Res = NoVecFn(&A[0], &B[0], &C[0], Threshold);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::DoNotOptimize(Res);
    benchmark::ClobberMemory();
  }
}

#define BENCHMARK_CASE(name, ty, threshold)                                    \
  void BENCHMARK_##name##_autovec_##ty##_(benchmark::State &state) {           \
    benchmark_csa_autovec<ty>(state, run_##name##_autovec, run_##name##_novec, \
                              threshold);                                      \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_autovec_##ty##_)->Unit(benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_##name##_novec_##ty##_(benchmark::State &state) {             \
    benchmark_csa_novec<ty>(state, run_##name##_novec, threshold);             \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_novec_##ty##_)->Unit(benchmark::kNanosecond);

// Add benchmarks with and without auto-vectorization
#define ADD_BENCHMARK(ty, threshold)                                           \
  BENCHMARK_CASE(single_csa_only, ty, threshold)                               \
  BENCHMARK_CASE(multi_csa_only, ty, threshold)                                \
  BENCHMARK_CASE(csa_with_arith, ty, threshold)                                \
  BENCHMARK_CASE(single_csa_cond_load, ty, threshold)                          \
  BENCHMARK_CASE(single_csa_nested_cond_load, ty, threshold)                   \
  BENCHMARK_CASE(csa_with_cond_arith, ty, threshold)                           \
  BENCHMARK_CASE(multi_csa_with_cond_arith, ty, threshold)

ADD_BENCHMARK(int32_t, 75)
ADD_BENCHMARK(uint8_t, 90)
ADD_BENCHMARK(int64_t, 60)
