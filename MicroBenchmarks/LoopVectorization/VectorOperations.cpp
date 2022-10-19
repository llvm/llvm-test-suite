#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 10000

static std::mt19937 rng;

// Initialize array A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<uint64_t> distrib(
      std::numeric_limits<Ty>::min(), std::numeric_limits<Ty>::max());
  for (unsigned i = 0; i < N; i++)
    A[i] = static_cast<Ty>(distrib(rng));
}

// Truncate/Zero-extend each vector element in a vectorized loop with vectorization width 8
template <typename Ty1, typename Ty2> static void truncOrZextVecInLoopWithVW8(const Ty1 *A, Ty2 *B, int iterations) {
#pragma clang loop vectorize_width(8) interleave_count(4)
  for (unsigned i = 0; i < iterations; i++) {
    B[i] = A[i];
  }
}

template <typename Ty1, typename Ty2> static void __attribute__((always_inline))
benchForTruncOrZextVecInLoopWithVW8(benchmark::State &state) {
  std::unique_ptr<Ty1[]> A(new Ty1[ITERATIONS]);
  std::unique_ptr<Ty2[]> B(new Ty2[ITERATIONS]);
  init_data(A, ITERATIONS);
  init_data(B, ITERATIONS);
  for (auto _ : state) {
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
    truncOrZextVecInLoopWithVW8(&A[0], &B[0], ITERATIONS);
  }
}

// Truncate/Zero-extend each vector element in a vectorized loop
template <typename Ty1, typename Ty2> static void truncOrZextVecInLoop(const Ty1 *A, Ty2 *B, int iterations) {
#pragma clang loop interleave_count(4)
  for (unsigned i = 0; i < iterations; i++) {
    B[i] = A[i];
  }
}

template <typename Ty1, typename Ty2> static void __attribute__((always_inline))
benchForTruncOrZextVecInLoop(benchmark::State &state) {
  std::unique_ptr<Ty1[]> A(new Ty1[ITERATIONS]);
  std::unique_ptr<Ty2[]> B(new Ty2[ITERATIONS]);
  init_data(A, ITERATIONS);
  init_data(B, ITERATIONS);
  for (auto _ : state) {
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
    truncOrZextVecInLoop(&A[0], &B[0], ITERATIONS);
  }
}

// Add vectorized truncate or zero-extend operation benchmarks for different element types
#define ADD_BENCHMARK(ty1, ty2)                                                  \
  void benchForTruncOrZextVecInLoopWithVW8From_##ty1##_To_##ty2##_(benchmark::State &state) {             \
    benchForTruncOrZextVecInLoopWithVW8<ty1, ty2>(state);                   \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecInLoopWithVW8From_##ty1##_To_##ty2##_); \
  void benchForTruncOrZextVecInLoopFrom_##ty1##_To_##ty2##_(benchmark::State &state) {             \
    benchForTruncOrZextVecInLoop<ty1, ty2>(state);                   \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecInLoopFrom_##ty1##_To_##ty2##_); \

/* Vectorized truncate operations */
ADD_BENCHMARK(uint64_t, uint8_t)
ADD_BENCHMARK(uint32_t, uint8_t)
ADD_BENCHMARK(uint16_t, uint8_t)


/* Vectorized zero extend operations */
ADD_BENCHMARK(uint8_t, uint32_t)
