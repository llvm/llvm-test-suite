#pragma once

#ifndef ITERATIONS
#error Define ITERATIONS before including!
#endif

#include "benchmark/benchmark.h"
#include <iostream>
#include <random>
#include <tuple>
#include <type_traits>

// This file contains some helpers for defining vectorizer benchmarks with a
// varying number of randomly initialized array parameters.

#define _Args(...) __VA_ARGS__
#define _STRIP_PARENS(X) X
#define STRIP_PARENS(X) _STRIP_PARENS(_Args X)

template <typename T> bool compare_array(T *A, T *B) {
  for (unsigned i = 0; i < ITERATIONS; i++) {
    if (A[i] != B[i]) {
      std::cout << "array mismatch at index " << i << '\n';
      return false;
    }
  }
  return true;
};

template <class Tuple, std::size_t... I>
bool compare_tuple_of_arrays(const Tuple &a, const Tuple &b,
                             std::index_sequence<I...>) {
  return (compare_array(std::get<I>(a), std::get<I>(b)) && ...);
}

template <typename Base, typename... ParamTys> class LoopBenchHelper {
  std::tuple<ParamTys...> Params;

public:
  LoopBenchHelper() {
    std::mt19937 rng(12345);
    // TODO: Come up with a range based on the array type (Ty below).
    std::uniform_int_distribution<int> dist(0, 100);
    // Allocate parameters and init to random (seeded) values.
    std::apply(
        [&](auto &...args) {
          (
              [&] {
                // TODO: Support scalar values (check the arg is a pointer).
                using Ty = std::remove_reference_t<decltype(*args)>;
                args = new Ty[ITERATIONS];
                // TODO: Handle random float values better than casting an int.
                for (unsigned i = 0; i < ITERATIONS; ++i)
                  args[i] = static_cast<Ty>(dist(rng));
              }(),
              ...);
        },
        Params);
  }

  // Mark all parameters with DoNotOptimize.
  __attribute__((always_inline)) void do_no_optimize() {
    std::apply([](auto &&...args) { ((benchmark::DoNotOptimize(args)), ...); },
               Params);
    benchmark::ClobberMemory();
  }

  // Run the vectorized loop.
  auto run_autovec() {
    do_no_optimize();
    return std::apply(Base::autovec, Params);
  }

  // Run the scalar loop.
  auto run_novec() {
    do_no_optimize();
    return std::apply(Base::novec, Params);
  }

  // Verify two instances of have the same results.
  static bool verify_same(const LoopBenchHelper &A, const LoopBenchHelper &B) {
    return compare_tuple_of_arrays(A.Params, B.Params,
                                   std::index_sequence_for<ParamTys...>{});
  }

  ~LoopBenchHelper() {
    std::apply([](auto &&...args) { ((delete[] args), ...); }, Params);
  }
};

// Benchmark (and verify) a loop.
template <typename Bench, bool EnableVec>
void __attribute__((always_inline)) benchmark_loop(benchmark::State &state) {
  Bench Loop;

#ifdef BENCH_AND_VERIFY
  // Verify the vectorized and un-vectorized versions produce the same results.
  if (EnableVec) {
    Bench NoVec;
    Loop.run_autovec();
    NoVec.run_novec();
    if (!Bench::verify_same(Loop, NoVec)) {
      std::cerr << "ERROR: autovec result different to scalar loop!\n";
      exit(1);
    }
  }
#endif

  for (auto _ : state) {
    if constexpr (EnableVec)
      Loop.run_autovec();
    else
      Loop.run_novec();
  }
}

#define BENCHMARK_CASE(name, ty)                                               \
  void BENCHMARK_##name##_autovec_##ty(benchmark::State &state) {              \
    benchmark_loop<name<ty>, /*EnableVec=*/true>(state);                       \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_autovec_##ty)->Unit(benchmark::kNanosecond);    \
                                                                               \
  void BENCHMARK_##name##_novec_##ty(benchmark::State &state) {                \
    benchmark_loop<name<ty>, /*EnableVec=*/false>(state);                      \
  }                                                                            \
  BENCHMARK(BENCHMARK_##name##_novec_##ty)->Unit(benchmark::kNanosecond);
