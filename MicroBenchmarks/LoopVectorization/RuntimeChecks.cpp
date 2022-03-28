#include <memory>
#include <random>
#include <stdint.h>

#include "benchmark/benchmark.h"

static std::mt19937 rng;

// Initialize array A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<uint64_t> distrib(
      std::numeric_limits<Ty>::min(), std::numeric_limits<Ty>::max());
  for (unsigned i = 0; i < N; i++)
    A[i] = static_cast<Ty>(distrib(rng));
}

static void vecWithRuntimeChecks4Pointers(uint32_t *A, uint32_t *B, uint32_t *C,
                                          uint32_t *D, unsigned TC,
                                          unsigned Step) {
  // Prevent the unroller from interfering.
#pragma clang loop unroll(disable)
  for (unsigned I = 0; I < 1000; I++) {
    // Make sure the inner loop cannot be optimized out.
    benchmark::ClobberMemory();

#pragma clang loop interleave_count(1)
#pragma clang loop unroll(disable)
    for (unsigned J = 0; J < TC; ++J) {
      A[J] = B[J] + C[J] + D[J];
    }

    // Make sure the runtime checks cannot be hoisted out of the outer loop.
    A += Step;
    B++;
    C++;
    D++;
  }
}

/// Helper to block optimizing \p F based on its arguments.
template <typename F, typename... Args>
__attribute__((optnone)) static void callThroughOptnone(F &&f, Args &&...args) {
  f(std::forward<Args>(args)...);
}

// Benchmark for when runtime checks are passing.
void benchVecWithRuntimeChecks4PointersAllDisjointIncreasing(
    benchmark::State &state) {
  unsigned TC = state.range(0);
  unsigned Size = 4 * TC + 1000;
  std::unique_ptr<uint32_t[]> A(new uint32_t[Size]);

  init_data(A, Size);
  for (auto _ : state) {
    callThroughOptnone(vecWithRuntimeChecks4Pointers, &A[0], &A[TC], &A[2 * TC],
                       &A[3 * TC], TC, 1);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(benchVecWithRuntimeChecks4PointersAllDisjointIncreasing)
    ->Arg(32)
    ->Arg(1000);

void benchVecWithRuntimeChecks4PointersAllDisjointDecreasing(
    benchmark::State &state) {
  unsigned TC = state.range(0);
  unsigned Size = 4 * TC + 1000;
  std::unique_ptr<uint32_t[]> A(new uint32_t[Size]);
  init_data(A, Size);

  for (auto _ : state) {
    callThroughOptnone(vecWithRuntimeChecks4Pointers, &A[3 * TC], &A[2 * TC],
                       &A[1 * TC], &A[0], TC, 1);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(benchVecWithRuntimeChecks4PointersAllDisjointDecreasing)
    ->Arg(32)
    ->Arg(1000);

void benchVecWithRuntimeChecks4PointersDEqualsA(benchmark::State &state) {
  unsigned TC = state.range(0);
  unsigned Size = 4 * TC + 1000;
  std::unique_ptr<uint32_t[]> A(new uint32_t[Size]);
  init_data(A, Size);

  for (auto _ : state) {
    callThroughOptnone(vecWithRuntimeChecks4Pointers, &A[0], &A[TC], &A[2 * TC],
                       &A[0], TC, 1);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(benchVecWithRuntimeChecks4PointersDEqualsA)->Arg(32)->Arg(1000);

// Benchmark for when runtime checks are failing.
void benchVecWithRuntimeChecks4PointersDBeforeA(benchmark::State &state) {
  unsigned TC = state.range(0);
  unsigned Size = 4 * TC + 1000;
  std::unique_ptr<uint32_t[]> A(new uint32_t[Size]);
  init_data(A, Size);

  for (auto _ : state) {
    callThroughOptnone(vecWithRuntimeChecks4Pointers, &A[2], &A[2 * TC],
                       &A[3 * TC], &A[0], TC, 1);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(benchVecWithRuntimeChecks4PointersDBeforeA)->Arg(32)->Arg(1000);

void benchVecWithRuntimeChecks4PointersDAfterA(benchmark::State &state) {
  unsigned TC = state.range(0);
  unsigned Size = 4 * TC + 1000;
  std::unique_ptr<uint32_t[]> A(new uint32_t[Size]);
  init_data(A, Size);

  for (auto _ : state) {
    callThroughOptnone(vecWithRuntimeChecks4Pointers, &A[0], &A[2 * TC],
                       &A[3 * TC], &A[2], TC, 1);
    benchmark::DoNotOptimize(A);
    benchmark::ClobberMemory();
  }
}
BENCHMARK(benchVecWithRuntimeChecks4PointersDAfterA)->Arg(32)->Arg(1000);
