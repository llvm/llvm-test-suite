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
                                 uint64_t (*Fn)(Ty *, Ty *, Ty *, int),
                                 int Iterations) {
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

#define STRINGIFY(a) #a

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

#define ADD_BENCHMARK(Ty, Itr)                                                 \
  void benchAutoVecFor##Ty##ForLoopTC##Itr(benchmark::State &state) {          \
    runBenchForEpilogueVectorization<Ty>(state, &loopAutoVec<Ty>, Itr);        \
  }                                                                            \
  BENCHMARK(benchAutoVecFor##Ty##ForLoopTC##Itr);                              \
  void benchReductionAutoVecFor##Ty##ForLoopTC##Itr(benchmark::State &state) { \
    runBenchForEpilogueVectorization<Ty>(state, &loopWithReductionAutoVec<Ty>, \
                                         Itr);                                 \
  }                                                                            \
  BENCHMARK(benchReductionAutoVecFor##Ty##ForLoopTC##Itr);

ADD_BENCHMARK(uint8_t, 65)
ADD_BENCHMARK(uint8_t, 80)
ADD_BENCHMARK(uint8_t, 96)
ADD_BENCHMARK(uint8_t, 104)
ADD_BENCHMARK(uint8_t, 127)

ADD_BENCHMARK(uint16_t, 65)
ADD_BENCHMARK(uint16_t, 80)
ADD_BENCHMARK(uint16_t, 96)
ADD_BENCHMARK(uint16_t, 104)
ADD_BENCHMARK(uint16_t, 127)

ADD_BENCHMARK(uint32_t, 65)
ADD_BENCHMARK(uint32_t, 80)
ADD_BENCHMARK(uint32_t, 96)
ADD_BENCHMARK(uint32_t, 104)
ADD_BENCHMARK(uint32_t, 127)
