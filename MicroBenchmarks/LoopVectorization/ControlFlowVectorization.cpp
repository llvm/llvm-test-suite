#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 100000

template <typename T> using ControlFlowLoopFunc = void (*)(T *, unsigned);

// Define conditional loop with given branch taken frequency.
#define DEF_COND_LOOP(name, branch_every_N)                                    \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_autovec(T *A,             \
                                                             unsigned N) {     \
    for (unsigned i = 0; i < N; i++) {                                         \
      if (i % branch_every_N == 0) {                                           \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }                                                                            \
  template <typename T>                                                        \
  __attribute__((noinline)) static void run_##name##_novec(T *A, unsigned N) { \
    _Pragma("clang loop vectorize(disable) interleave(disable)")               \
    for (unsigned i =0; i < N; i++) {                                          \
      if (i % branch_every_N == 0) {                                           \
        A[i] = A[i] + 1;                                                       \
      }                                                                        \
    }                                                                          \
  }

// Define conditional loop with taken frequency by data equals to marker.
#define DEF_COND_VALUE_LOOP(name, marker)                                      \
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
__attribute__((noinline)) static void run_uncond_autovec(T *A, unsigned N) {
  for (unsigned i = 0; i < N; i++) {
    A[i] = A[i] + 1;
  }
}

template <typename T>
__attribute__((noinline)) static void run_uncond_novec(T *A, unsigned N) {
  _Pragma("clang loop vectorize(disable) interleave(disable)")
  for (unsigned i = 0; i < N; i++) {
    A[i] = A[i] + 1;
  }
}

DEF_COND_LOOP(cond_every_1_iter, 1)
DEF_COND_LOOP(cond_every_2_iter, 2)
DEF_COND_LOOP(cond_every_4_iter, 4)
DEF_COND_LOOP(cond_every_8_iter, 8)
DEF_COND_LOOP(cond_every_16_iter, 16)
DEF_COND_LOOP(cond_every_32_iter, 32)
DEF_COND_LOOP(cond_every_64_iter, 64)

// Branch taken by value
DEF_COND_VALUE_LOOP(cond_by_value, 100)

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
benchmark_control_flow_loop_autovec(benchmark::State &state,
                                   ControlFlowLoopFunc<T> VecFn,
                                   ControlFlowLoopFunc<T> NoVecFn) {
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
benchmark_control_flow_loop_novec(benchmark::State &state,
                                 ControlFlowLoopFunc<T> NoVecFn) {
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

#define BENCHMARK_CONTROL_FLOW_VEC_CASE(name, ty)                              \
  void BENCHMARK_##name##_autovec_##ty##_(benchmark::State &state) {           \
    benchmark_control_flow_loop_autovec<ty>(state, run_##name##_autovec,        \
                                           run_##name##_novec);                \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_autovec_##ty##_)->Unit(benchmark::kNanosecond); \
                                                                               \
  void BENCHMARK_##name##_novec_##ty##_(benchmark::State &state) {             \
    benchmark_control_flow_loop_novec<ty>(state, run_##name##_novec);           \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_novec_##ty##_)->Unit(benchmark::kNanosecond);

// Unconditional increment benchmark.
#define BENCHMARK_UNCOND_CASE(ty)                                              \
  void BENCHMARK_uncond_autovec_##ty##_(benchmark::State &state) {             \
    benchmark_control_flow_loop_autovec<ty>(state, run_uncond_autovec,          \
                                           run_uncond_novec);                  \
  }                                                                            \
  BENCHMARK(BENCHMARK_uncond_autovec_##ty##_)->Unit(benchmark::kNanosecond);   \
                                                                               \
  void BENCHMARK_uncond_novec_##ty##_(benchmark::State &state) {               \
    benchmark_control_flow_loop_novec<ty>(state, run_uncond_novec);             \
  }                                                                            \
  BENCHMARK(BENCHMARK_uncond_novec_##ty##_)->Unit(benchmark::kNanosecond);

// Add benchmarks for all branch frequency variants.
#define ADD_CONTROL_FLOW_VEC_BENCHMARKS(ty)                                    \
  BENCHMARK_UNCOND_CASE(ty)                                                    \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_1_iter, ty)                       \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_2_iter, ty)                       \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_4_iter, ty)                       \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_8_iter, ty)                       \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_16_iter, ty)                      \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_32_iter, ty)                      \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_every_64_iter, ty)                      \
  BENCHMARK_CONTROL_FLOW_VEC_CASE(cond_by_value, ty)

ADD_CONTROL_FLOW_VEC_BENCHMARKS(int64_t)
ADD_CONTROL_FLOW_VEC_BENCHMARKS(int32_t)
ADD_CONTROL_FLOW_VEC_BENCHMARKS(int16_t)
