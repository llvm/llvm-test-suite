#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 100000

template <typename T> using CFVFunc = void (*)(T *, unsigned);

// Define conditional increment loop with given stride.
#define DEF_COND_INC_LOOP(name, stride)                                        \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_autovec(T *A,             \
                                                             unsigned N) {     \
    for (unsigned i = 0; i < N; i++) {                                         \
      if (i % stride == 0) {                                                   \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }                                                                            \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_novec(T *A, unsigned N) { \
    _Pragma("clang loop vectorize(disable) interleave(disable)")               \
    for (unsigned i = 0; i < N; i++) {                                         \
      if (i % stride == 0) {                                                   \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }

// Define conditional increment by value loop.
#define DEF_COND_INC_VALUE_LOOP(name, marker)                                  \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_autovec(T *A,             \
                                                             unsigned N) {     \
    for (unsigned i = 0; i < N; i++) {                                         \
      if (A[i] == marker) {                                                    \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }                                                                            \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_novec(T *A, unsigned N) { \
    _Pragma("clang loop vectorize(disable) interleave(disable)")               \
    for (unsigned i = 0; i < N; i++) {                                         \
      if (A[i] == marker) {                                                    \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }

// Define unconditional increment loop.
template <typename T>
__attribute__((noinline)) static void run_uncond_inc_autovec(T *A, unsigned N) {
  for (unsigned i = 0; i < N; i++) {
    A[i] = A[i] + 1;
  }
}

template <typename T>
__attribute__((noinline)) static void run_uncond_inc_novec(T *A, unsigned N) {
  _Pragma("clang loop vectorize(disable) interleave(disable)")
  for (unsigned i = 0; i < N; i++) {
    A[i] = A[i] + 1;
  }
}

// Define loops with different strides.
// Stride 16 usually big enough to accross single vector which can test if
// control-flow-vectorization is profitable on these loops.
DEF_COND_INC_LOOP(cond_inc_stride_16, 16)
DEF_COND_INC_LOOP(cond_inc_stride_32, 32)
DEF_COND_INC_LOOP(cond_inc_stride_64, 64)
DEF_COND_INC_LOOP(cond_inc_stride_128, 128)

// Conditional increment by value.
DEF_COND_INC_VALUE_LOOP(cond_inc_by_value, 40)

// Initialize array with random numbers.
template <typename T> static void init_data(T *A) {
  std::uniform_int_distribution<T> dist(0, 100);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < ITERATIONS; i++) {
    A[i] = dist(rng);
  }
}

// Benchmark vectorized version.
template <typename T>
static void __attribute__((always_inline))
benchmark_cfv_autovec(benchmark::State &state, CFVFunc<T> VecFn,
                      CFVFunc<T> NoVecFn) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> A_vec(new T[ITERATIONS]);
  std::unique_ptr<T[]> A_novec(new T[ITERATIONS]);
  init_data(&A[0]);

#ifdef BENCH_AND_VERIFY
  // Verify the vectorized and scalar versions produce the same results.
  {
    std::copy(&A[0], &A[0] + ITERATIONS, &A_vec[0]);
    std::copy(&A[0], &A[0] + ITERATIONS, &A_novec[0]);
    VecFn(&A_vec[0], ITERATIONS);
    NoVecFn(&A_novec[0], ITERATIONS);
    for (unsigned i = 0; i < ITERATIONS; i++) {
      if (A_vec[i] != A_novec[i]) {
        std::cerr << "ERROR: vectorization result different at index " << i
                  << "; " << A_vec[i] << " != " << A_novec[i] << "\n";
        exit(1);
      }
    }
  }
#endif

  for (auto _ : state) {
    std::copy(&A[0], &A[0] + ITERATIONS, &A_vec[0]);
    VecFn(&A_vec[0], ITERATIONS);
    benchmark::DoNotOptimize(A_vec);
    benchmark::ClobberMemory();
  }
}

// Benchmark version with vectorization disabled.
template <typename T>
static void __attribute__((always_inline))
benchmark_cfv_novec(benchmark::State &state, CFVFunc<T> NoVecFn) {
  std::unique_ptr<T[]> A(new T[ITERATIONS]);
  std::unique_ptr<T[]> A_work(new T[ITERATIONS]);
  init_data(&A[0]);

  for (auto _ : state) {
    std::copy(&A[0], &A[0] + ITERATIONS, &A_work[0]);
    NoVecFn(&A_work[0], ITERATIONS);
    benchmark::DoNotOptimize(A_work);
    benchmark::ClobberMemory();
  }
}

#define BENCHMARK_CFV_CASE(name, ty)                                           \
  void BENCHMARK_##name##_autovec_##ty##_(benchmark::State &state) {           \
    benchmark_cfv_autovec<ty>(state, run_##name##_autovec, run_##name##_novec);\
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_autovec_##ty##_)->Unit(benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_##name##_novec_##ty##_(benchmark::State &state) {             \
    benchmark_cfv_novec<ty>(state, run_##name##_novec);                        \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_novec_##ty##_)->Unit(benchmark::kNanosecond);

// Unconditional increment benchmark.
#define BENCHMARK_UNCOND_CASE(ty)                                              \
  void BENCHMARK_uncond_inc_autovec_##ty##_(benchmark::State &state) {         \
    benchmark_cfv_autovec<ty>(state, run_uncond_inc_autovec,                   \
                              run_uncond_inc_novec);                           \
  }                                                                            \
  BENCHMARK(BENCHMARK_uncond_inc_autovec_##ty##_)                              \
      ->Unit(benchmark::kNanosecond);                                          \
                                                                               \
  void BENCHMARK_uncond_inc_novec_##ty##_(benchmark::State &state) {           \
    benchmark_cfv_novec<ty>(state, run_uncond_inc_novec);                      \
  }                                                                            \
  BENCHMARK(BENCHMARK_uncond_inc_novec_##ty##_)->Unit(benchmark::kNanosecond);

// Add benchmarks for all variants.
#define ADD_CFV_BENCHMARKS(ty)                                                 \
  BENCHMARK_UNCOND_CASE(ty)                                                    \
  BENCHMARK_CFV_CASE(cond_inc_stride_16, ty)                                   \
  BENCHMARK_CFV_CASE(cond_inc_stride_32, ty)                                   \
  BENCHMARK_CFV_CASE(cond_inc_stride_64, ty)                                   \
  BENCHMARK_CFV_CASE(cond_inc_stride_128, ty)                                  \
  BENCHMARK_CFV_CASE(cond_inc_by_value, ty)

ADD_CFV_BENCHMARKS(int64_t)
ADD_CFV_BENCHMARKS(int32_t)
ADD_CFV_BENCHMARKS(int16_t)

