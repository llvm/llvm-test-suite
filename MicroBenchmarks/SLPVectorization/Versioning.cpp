#include <iostream>
#include <math.h>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

// Initialize arrays A, B and T with random numbers.
template <typename T> static void init_data(T *A, unsigned N) {
  std::uniform_real_distribution<> dist(-100, 100);
  std::mt19937 rng(12345);
  for (unsigned i = 0; i < N; i++)
    A[i] = (T)dist(rng);
}

template <unsigned N, typename T>
__attribute__((noinline)) void do_xor(T *A, T *B) {
#pragma clang loop unroll(full)
  for (int i = 0; i < N; i++) {
    A[i] ^= B[i];
  }
}

template <unsigned N, typename T>
void benchmark_xor_runtime_checks_pass(benchmark::State &state) {
  T A[N];
  T B[N];
  init_data(&A[0], N);
  init_data(&B[0], N);

  for (auto _ : state) {
    do_xor<N>(&A[0], &B[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_xor_runtime_checks_fail(benchmark::State &state) {
  T A[2 * N];
  init_data(&A[0], 2 * N);

  for (auto _ : state) {
    do_xor<N>(&A[0], &A[3]);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_xor_no_runtime_checks_needed(benchmark::State &state) {
  T A[N];
  T B[N];
  init_data(&A[0], N);
  init_data(&B[0], N);

  for (auto _ : state) {
#pragma clang loop unroll(full)
    for (int i = 0; i < N; i++) {
      A[i] ^= B[i];
    }

    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
  }
}

BENCHMARK_TEMPLATE(benchmark_xor_runtime_checks_pass, 4, int);
BENCHMARK_TEMPLATE(benchmark_xor_runtime_checks_fail, 4, int);
BENCHMARK_TEMPLATE(benchmark_xor_no_runtime_checks_needed, 4, int);

BENCHMARK_TEMPLATE(benchmark_xor_runtime_checks_pass, 16, int);
BENCHMARK_TEMPLATE(benchmark_xor_runtime_checks_fail, 16, int);
BENCHMARK_TEMPLATE(benchmark_xor_no_runtime_checks_needed, 16, int);

template <unsigned N, typename T>
__attribute__((noinline)) void do_add_xor(T *A, T *B, T *C) {
#pragma clang loop unroll(full)
  for (int i = 0; i < N; i++) {
    A[i] ^= B[i] + C[i];
  }
}

template <unsigned N, typename T>
void benchmark_add_xor_runtime_checks_pass(benchmark::State &state) {
  T A[N];
  T B[N];
  T C[N];
  init_data(&A[0], N);
  init_data(&B[0], N);
  init_data(&C[0], N);

  for (auto _ : state) {
    do_add_xor<N>(&A[0], &B[0], &C[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_add_xor_runtime_checks_fail(benchmark::State &state) {
  T A[2 * N];
  T B[N];
  init_data(&A[0], 2 * N);
  init_data(&B[0], N);

  for (auto _ : state) {
    do_add_xor<N>(&A[0], &A[3], &B[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_add_xor_no_runtime_checks_needed(benchmark::State &state) {
  T A[N];
  T B[N];
  T C[N];
  init_data(&A[0], N);
  init_data(&B[0], N);
  init_data(&C[0], N);

  for (auto _ : state) {
#pragma clang loop unroll(full)
    for (int i = 0; i < N; i++) {
      A[i] ^= B[i] + C[i];
    }

    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
  }
}

BENCHMARK_TEMPLATE(benchmark_add_xor_runtime_checks_pass, 4, int);
BENCHMARK_TEMPLATE(benchmark_add_xor_runtime_checks_fail, 4, int);
BENCHMARK_TEMPLATE(benchmark_add_xor_no_runtime_checks_needed, 4, int);
BENCHMARK_TEMPLATE(benchmark_add_xor_runtime_checks_pass, 16, int);
BENCHMARK_TEMPLATE(benchmark_add_xor_runtime_checks_fail, 16, int);
BENCHMARK_TEMPLATE(benchmark_add_xor_no_runtime_checks_needed, 16, int);

template <unsigned N, typename T>
__attribute__((noinline)) void do_multiply_accumulate(T *A, T *B, T c) {
#pragma clang loop unroll(full)
  for (unsigned int i = 0; i < N; ++i) {
    A[i] += c * B[i];
  }
}

template <unsigned N, typename T>
void benchmark_multiply_accumulate_runtime_checks_pass(
    benchmark::State &state) {
  T A[N];
  T B[N];
  init_data(&A[0], N);
  init_data(&B[0], N);

  for (auto _ : state) {
    do_multiply_accumulate<N>(&A[0], &B[0], B[0]);
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_multiply_accumulate_runtime_checks_fail(
    benchmark::State &state) {
  T A[N];
  init_data(&A[0], N);

  for (auto _ : state) {
    do_multiply_accumulate<N>(&A[0], &A[1], A[0]);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}

template <unsigned N, typename T>
void benchmark_multiply_accumulate_no_runtime_checks_needed(
    benchmark::State &state) {
  T A[N];
  T B[N];
  init_data(&A[0], N);
  init_data(&B[0], N);

  for (auto _ : state) {
    T c = A[0];
#pragma clang loop unroll(full)
    for (unsigned int i = 0; i < N; ++i) {
      A[i] += c * B[i];
    }
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
  }
}

BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_pass, 2,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_fail, 2,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_no_runtime_checks_needed, 2,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_pass, 3,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_fail, 3,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_no_runtime_checks_needed, 3,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_pass, 4,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_runtime_checks_fail, 4,
                   double);
BENCHMARK_TEMPLATE(benchmark_multiply_accumulate_no_runtime_checks_needed, 4,
                   double);
