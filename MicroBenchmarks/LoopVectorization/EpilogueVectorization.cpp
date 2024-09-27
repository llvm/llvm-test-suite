// This program tests performance impact of Epilogue Vectorization
// with varying epilogue lengths, and vector widths.
#include <cstdint>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

static std::mt19937 rng;
uint64_t g_sum = 0;

// Initialize array A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<Ty> distrib(std::numeric_limits<Ty>::min(),
                                            std::numeric_limits<Ty>::max());
  for (unsigned I = 0; I < N; I++)
    A[I] = distrib(rng);
}

template <typename Ty>
static void __attribute__((always_inline))
runBenchForEpilogueVectorization(benchmark::State &state,
                                 uint64_t (*Fn)(Ty *, Ty *, Ty *, int)) {
  auto Iterations = state.range(0);
  std::unique_ptr<Ty[]> A(new Ty[Iterations]);
  std::unique_ptr<Ty[]> B(new Ty[Iterations]);
  std::unique_ptr<Ty[]> C(new Ty[Iterations]);
  init_data(A, Iterations);
  init_data(B, Iterations);
  init_data(C, Iterations);
  for (auto _ : state) {
    benchmark::DoNotOptimize(A);
    benchmark::DoNotOptimize(B);
    benchmark::DoNotOptimize(C);
    benchmark::ClobberMemory();
    g_sum += Fn(&A[0], &B[0], &C[0], Iterations);
  }
}

template <typename Ty>
static uint64_t __attribute__((noinline))
loopAutoVec(Ty *A, Ty *B, Ty *C, int Iterations) {
  for (int J = 0; J < Iterations; J++) {
    A[J] = B[J] + C[J];
  }
  return 0;
}

template <typename Ty>
static uint64_t __attribute__((noinline))
loopWithReductionAutoVec(Ty *A, Ty *B, Ty *C, int Iterations) {
  uint64_t sum = 0;
  for (int J = 0; J < Iterations; J++) {
    sum += A[J];
  }
  return sum;
}

template <typename Ty> void benchAutoVec(benchmark::State &state) {
  runBenchForEpilogueVectorization<Ty>(state, &loopAutoVec<Ty>);
}

template <typename Ty> void benchReductionAutoVec(benchmark::State &state) {
  runBenchForEpilogueVectorization<Ty>(state, &loopWithReductionAutoVec<Ty>);
}

#ifdef ALL_LOOP_EPILOGUE_TESTS
BENCHMARK_TEMPLATE(benchAutoVec, uint8_t)->DenseRange(65, 127, 1);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint8_t)->DenseRange(65, 127, 1);
BENCHMARK_TEMPLATE(benchAutoVec, uint16_t)->DenseRange(65, 127, 1);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint16_t)->DenseRange(65, 127, 1);
BENCHMARK_TEMPLATE(benchAutoVec, uint32_t)->DenseRange(65, 127, 1);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint32_t)->DenseRange(65, 127, 1);
#else
BENCHMARK_TEMPLATE(benchAutoVec, uint8_t)->Range(65, 127);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint8_t)->Range(65, 127);
BENCHMARK_TEMPLATE(benchAutoVec, uint16_t)->Range(65, 127);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint16_t)->Range(65, 127);
BENCHMARK_TEMPLATE(benchAutoVec, uint32_t)->Range(65, 127);
BENCHMARK_TEMPLATE(benchReductionAutoVec, uint32_t)->Range(65, 127);
#endif
