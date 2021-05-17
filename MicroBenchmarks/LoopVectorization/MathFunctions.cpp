#include <iostream>
#include <math.h>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define N 10000

// Apply Fn(A[i]) + Fn(B[i]) in loop, with default loop vectorization settings.
template <typename T> static void run_fn_autovec(T *A, T *B, T *C, T (*Fn)(T)) {
  for (unsigned i = 0; i < N; i++) {
    C[i] = Fn(A[i]) + Fn(B[i]);
  }
}

// Apply Fn(A[i]) + Fn(B[i]) in loop, with loop vectorization disabled.
template <typename T> static void run_fn_novec(T *A, T *B, T *C, T (*Fn)(T)) {
#pragma clang loop vectorize(disable) interleave(disable)
  for (unsigned i = 0; i < N; i++) {
    C[i] = Fn(A[i]) + Fn(B[i]);
  }
}

// Initialize arrays A, B and T with random numbers.
template <typename T> static void init_data(T *A, T *B, T *C) {
  std::uniform_real_distribution<T> dist(-100, 100);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < N; i++) {
    A[i] = dist(rng);
    B[i] = dist(rng);
    C[i] = dist(rng);
  }
}

// Benchmark auto-vectorized version using Fn.
template <typename T>
static void __attribute__((always_inline))
benchmark_fn_autovec(benchmark::State &state, T (*Fn)(T)) {
  std::unique_ptr<T[]> A(new T[N]);
  std::unique_ptr<T[]> B(new T[N]);
  std::unique_ptr<T[]> C(new T[N]);
  init_data(&A[0], &B[0], &C[0]);

#ifdef BENCH_AND_VERIFY
  // Verify the vectorized and un-vectorized versions produce the same results.
  {
    std::unique_ptr<T[]> CNovec(new T[N]);
    for (unsigned i = 0; i < N; i++)
      CNovec[i] = C[i];

    run_fn_novec(&A[0], &B[0], &CNovec[0], Fn);
    run_fn_autovec(&A[0], &B[0], &C[0], Fn);
    for (unsigned i = 0; i < N; i++)
      // If there's a value mismatch, fall back to fpclassify.
      if (C[i] != CNovec[i] && fpclassify(C[i]) != fpclassify(CNovec[i])) {
        std::cerr << "ERROR: autovec result different to scalar result " << C[i]
                  << " != " << CNovec[i] << " at index " << i << "\n";
        exit(1);
      }
  }
#endif

  for (auto _ : state) {
    run_fn_autovec(&A[0], &B[0], &C[0], Fn);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

// Benchmark version using Fn with vectorization disabled.
template <typename T>
static void __attribute__((always_inline))
benchmark_fn_novec(benchmark::State &state, T (*Fn)(T)) {
  std::unique_ptr<T[]> A(new T[N]);
  std::unique_ptr<T[]> B(new T[N]);
  std::unique_ptr<T[]> C(new T[N]);
  init_data(&A[0], &B[0], &C[0]);

  for (auto _ : state) {
    run_fn_novec(&A[0], &B[0], &C[0], Fn);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
  }
}

// Add add auto-vectorized and disabled vectorization benchmarks for math
// function fn and type ty.
#define ADD_BENCHMARK(fn, ty)                                                  \
  void BENCHMARK_##fn##_autovec_##ty##_(benchmark::State &state) {             \
    benchmark_fn_autovec<ty>(state, fn);                                       \
  }                                                                            \
  BENCHMARK(BENCHMARK_##fn##_autovec_##ty##_)->Unit(benchmark::kMicrosecond);  \
                                                                               \
  void BENCHMARK_##fn##_novec_##ty##_(benchmark::State &state) {               \
    benchmark_fn_novec<ty>(state, fn);                                         \
  }                                                                            \
  BENCHMARK(BENCHMARK_##fn##_novec_##ty##_)->Unit(benchmark::kMicrosecond);

ADD_BENCHMARK(expf, float)
ADD_BENCHMARK(exp, double)

ADD_BENCHMARK(acosf, float)
ADD_BENCHMARK(acos, double)

ADD_BENCHMARK(asinf, float)
ADD_BENCHMARK(asin, double)

ADD_BENCHMARK(atanf, float)
ADD_BENCHMARK(atan, double)

ADD_BENCHMARK(cbrtf, float)
ADD_BENCHMARK(cbrt, double)

ADD_BENCHMARK(erff, float)
ADD_BENCHMARK(erf, double)

ADD_BENCHMARK(cosf, float)
ADD_BENCHMARK(cos, double)

ADD_BENCHMARK(sinf, float)
ADD_BENCHMARK(sin, double)

ADD_BENCHMARK(sinhf, float)
ADD_BENCHMARK(sinh, double)
