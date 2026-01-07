// This program tests performance impact of Epilogue Vectorization
// with varying epilogue lengths, and vector widths.
#include <cstdint>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

static std::mt19937 rng;
uint64_t Sum = 0;

// Initialize array A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<Ty> distrib(std::numeric_limits<Ty>::min(),
                                            std::numeric_limits<Ty>::max());
  for (unsigned I = 0; I < N; I++)
    A[I] = 1;
}

// Helper to block optimizing \p F based on its arguments.
template <typename F, typename... Args>
__attribute__((optnone)) static uint64_t callThroughOptnone(F &&f,
                                                            Args &&...args) {
  return f(std::forward<Args>(args)...);
}

enum class EarlyExitPosition { None, First, Mid };

template <typename Ty>
static void __attribute__((always_inline))
runEarlyExitBenchmark(benchmark::State &state,
                      uint64_t (*Fn)(Ty *, Ty *, Ty *, int),
                      EarlyExitPosition ExitPos) {
  auto Iterations = state.range(0);
  std::unique_ptr<Ty[]> A(new Ty[Iterations]);
  std::unique_ptr<Ty[]> B(new Ty[Iterations]);
  std::unique_ptr<Ty[]> C(new Ty[Iterations]);
  init_data(A, Iterations);
  init_data(B, Iterations);
  init_data(C, Iterations);

  switch (ExitPos) {
  case EarlyExitPosition::None:
    break;
  case EarlyExitPosition::First:
    A[0] = 0;
    break;
  case EarlyExitPosition::Mid:
    A[Iterations * 0.5] = 0;
    break;
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::DoNotOptimize(Sum);
    benchmark::ClobberMemory();
    Sum += callThroughOptnone(Fn, &A[0], &B[0], &C[0], Iterations);
  }
}

template <typename Ty>
static uint64_t __attribute__((noinline))
singleEarlyExitWithSingleLoad(Ty *A, Ty *B, Ty *C, int Iterations) {
  auto AlignedA = static_cast<Ty *>(__builtin_assume_aligned(A, sizeof(Ty)));
  __builtin_assume_dereferenceable(AlignedA, Iterations * sizeof(Ty));
  for (int J = 0; J < Iterations; J++) {
    if (AlignedA[J] == 0)
      return J;
  }
  return 0;
}

template <typename Ty>
static uint64_t __attribute__((noinline))
singleEarlyExitWithTwoLoads(Ty *A, Ty *B, Ty *C, int Iterations) {
  auto AlignedA = static_cast<Ty *>(__builtin_assume_aligned(A, sizeof(Ty)));
  auto AlignedB = static_cast<Ty *>(__builtin_assume_aligned(B, sizeof(Ty)));
  __builtin_assume_dereferenceable(AlignedA, Iterations * sizeof(Ty));
  __builtin_assume_dereferenceable(AlignedB, Iterations * sizeof(Ty));
  for (int J = 0; J < Iterations; J++) {
    if (AlignedA[J] != AlignedB[J])
      return J;
  }
  return 0;
}

template <typename Ty>
static uint64_t __attribute__((noinline))
singleEarlyExitWithThreeLoadsAndCompute(Ty *A, Ty *B, Ty *C, int Iterations) {
  auto AlignedA = static_cast<Ty *>(__builtin_assume_aligned(A, sizeof(Ty)));
  auto AlignedB = static_cast<Ty *>(__builtin_assume_aligned(B, sizeof(Ty)));
  auto AlignedC = static_cast<Ty *>(__builtin_assume_aligned(C, sizeof(Ty)));
  __builtin_assume_dereferenceable(AlignedA, Iterations * sizeof(Ty));
  __builtin_assume_dereferenceable(AlignedB, Iterations * sizeof(Ty));
  __builtin_assume_dereferenceable(AlignedC, Iterations * sizeof(Ty));
  for (int J = 0; J < Iterations; J++) {
    // Exits when A[J] == 0: (0 + 1) * 1 == 1
    // Continues when A[J] == 1: (1 + 1) * 1 == 2
    if ((AlignedA[J] + AlignedB[J]) * AlignedC[J] == 1)
      return J;
  }
  return 0;
}

template <typename Ty>
void autovec_no_early_exit_single_load(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithSingleLoad<Ty>,
                            EarlyExitPosition::None);
}

template <typename Ty>
void autovec_no_early_exit_two_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithTwoLoads<Ty>,
                            EarlyExitPosition::None);
}

template <typename Ty>
void autovec_early_exit_taken_first_single_load(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithSingleLoad<Ty>,
                            EarlyExitPosition::First);
}

template <typename Ty>
void autovec_early_exit_taken_first_two_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithTwoLoads<Ty>,
                            EarlyExitPosition::First);
}

template <typename Ty>
void autovec_early_exit_taken_mid_two_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithTwoLoads<Ty>,
                            EarlyExitPosition::Mid);
}

template <typename Ty>
void autovec_no_early_exit_three_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithThreeLoadsAndCompute<Ty>,
                            EarlyExitPosition::None);
}

template <typename Ty>
void autovec_early_exit_taken_first_three_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithThreeLoadsAndCompute<Ty>,
                            EarlyExitPosition::First);
}

template <typename Ty>
void autovec_early_exit_taken_mid_three_loads(benchmark::State &state) {
  runEarlyExitBenchmark<Ty>(state, &singleEarlyExitWithThreeLoadsAndCompute<Ty>,
                            EarlyExitPosition::Mid);
}

#define BENCHMARK_ARGS ->Arg(10)->Arg(16)->Arg(28)->Arg(51)->Arg(256)->Arg(999)

#define REGISTER_BENCHMARK_FOR_TYPES(BenchFunc)                                \
  BENCHMARK_TEMPLATE(BenchFunc, uint8_t) BENCHMARK_ARGS;                       \
  BENCHMARK_TEMPLATE(BenchFunc, uint16_t) BENCHMARK_ARGS;                      \
  BENCHMARK_TEMPLATE(BenchFunc, uint32_t) BENCHMARK_ARGS;                      \
  BENCHMARK_TEMPLATE(BenchFunc, uint64_t) BENCHMARK_ARGS;

REGISTER_BENCHMARK_FOR_TYPES(autovec_no_early_exit_single_load)
REGISTER_BENCHMARK_FOR_TYPES(autovec_early_exit_taken_first_single_load)
REGISTER_BENCHMARK_FOR_TYPES(autovec_early_exit_taken_first_two_loads)
REGISTER_BENCHMARK_FOR_TYPES(autovec_early_exit_taken_mid_two_loads)
REGISTER_BENCHMARK_FOR_TYPES(autovec_no_early_exit_three_loads)
REGISTER_BENCHMARK_FOR_TYPES(autovec_early_exit_taken_first_three_loads)
REGISTER_BENCHMARK_FOR_TYPES(autovec_early_exit_taken_mid_three_loads)
