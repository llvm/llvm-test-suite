// This program tests vectorized truncates & zero-extends for performance and
// correctness
#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

#define ITERATIONS 10000

static std::mt19937 rng;

// Initialize array A with random numbers.
template <typename Ty>
static void init_data(const std::unique_ptr<Ty[]> &A, unsigned N) {
  std::uniform_int_distribution<Ty> distrib(std::numeric_limits<Ty>::min(),
                                            std::numeric_limits<Ty>::max());
  for (unsigned I = 0; I < N; I++)
    A[I] = distrib(rng);
}

// Truncate/Zero-extend elements to create expected results with no
// vectorization
template <typename Ty1, typename Ty2>
static void truncOrZextWithNoVec(const Ty1 *A, Ty2 *B, int Iterations) {
#pragma clang loop vectorize(disable)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] = A[I];
  }
}

// Truncate/Zero-extend each vector element in a vectorized loop with vectorization width 8
template <typename Ty1, typename Ty2>
static void truncOrZextVecInLoopWithVW8(const Ty1 *A, Ty2 *B, int Iterations) {
#pragma clang loop vectorize_width(8) interleave_count(4)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] = A[I];
  }
}

// Truncate/Zero-extend each vector element in a vectorized loop with
// vectorization width 16
template <typename Ty1, typename Ty2>
static void truncOrZextVecInLoopWithVW16(const Ty1 *A, Ty2 *B, int Iterations) {
#pragma clang loop vectorize_width(16) interleave_count(4)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] = A[I];
  }
}

// Truncate/Zero-extend each vector element in a vectorized loop
template <typename Ty1, typename Ty2>
static void truncOrZextVecInLoop(const Ty1 *A, Ty2 *B, int Iterations) {
#pragma clang loop vectorize(enable)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] = A[I];
  }
}

// Truncate/Zero-extend each vector element while adding in a vectorized loop
// with vectorization width 8
template <typename Ty1, typename Ty2>
static void truncOrZextVecWithAddInLoopWithVW8(const Ty1 *A, Ty2 *B,
                                               int Iterations) {
#pragma clang loop vectorize_width(8) interleave_count(4)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] += A[I];
  }
}

// Truncate/Zero-extend each vector element while adding in a vectorized loop
// vectorization width 16
template <typename Ty1, typename Ty2>
static void truncOrZextVecWithAddInLoopWithVW16(const Ty1 *A, Ty2 *B,
                                                int Iterations) {
#pragma clang loop vectorize_width(16) interleave_count(4)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] += A[I];
  }
}

// Truncate/Zero-extend each vector element while adding in a vectorized loop
template <typename Ty1, typename Ty2>
static void truncOrZextVecWithAddInLoop(const Ty1 *A, Ty2 *B, int Iterations) {
#pragma clang loop vectorize(enable)
  for (unsigned I = 0; I < Iterations; I++) {
    B[I] += A[I];
  }
}

template <typename Ty1, typename Ty2>
static void __attribute__((always_inline))
benchForTruncOrZextVecInLoop(benchmark::State &state,
                             void (*Fn)(const Ty1 *, Ty2 *, int)) {
  std::unique_ptr<Ty1[]> A(new Ty1[ITERATIONS]);
  std::unique_ptr<Ty2[]> B(new Ty2[ITERATIONS]);
  std::unique_ptr<Ty2[]> C(new Ty2[ITERATIONS]);

  init_data(A, ITERATIONS);

  // Check for correctness
  truncOrZextWithNoVec(&A[0], &C[0], ITERATIONS);
  Fn(&A[0], &B[0], ITERATIONS);
  for (int I = 0; I < ITERATIONS; I++) {
    if (B[I] != C[I]) {
      std::cerr << "ERROR: Trunc or ZExt operation on " << A[I]
                << " is showing result " << B[I] << " instead of " << C[I]
                << "\n";
      exit(1);
    }
  }

  for (auto _ : state) {
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
    Fn(&A[0], &B[0], ITERATIONS);
  }
}

template <typename Ty1, typename Ty2>
static void __attribute__((always_inline))
benchForTruncOrZextVecWithAddInLoop(benchmark::State &state,
                                    void (*Fn)(const Ty1 *, Ty2 *, int)) {
  std::unique_ptr<Ty1[]> A(new Ty1[ITERATIONS]);
  std::unique_ptr<Ty2[]> B(new Ty2[ITERATIONS]);
  std::unique_ptr<Ty2[]> C(new Ty2[ITERATIONS]);
  init_data(A, ITERATIONS);
  init_data(B, ITERATIONS);
  for (auto _ : state) {
    benchmark::DoNotOptimize(B);
    benchmark::ClobberMemory();
    Fn(&A[0], &B[0], ITERATIONS);
  }
}

// Add vectorized truncate or zero-extend operation benchmarks for different element types
#define ADD_BENCHMARK(ty1, ty2)                                                \
  void benchForTruncOrZextVecInLoopWithVW8From_##ty1##_To_##ty2##_(            \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecInLoop<ty1, ty2>(state,                              \
                                           &truncOrZextVecInLoopWithVW8);      \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecInLoopWithVW8From_##ty1##_To_##ty2##_);      \
  void benchForTruncOrZextVecInLoopWithVW16From_##ty1##_To_##ty2##_(           \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecInLoop<ty1, ty2>(state,                              \
                                           &truncOrZextVecInLoopWithVW16);     \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecInLoopWithVW16From_##ty1##_To_##ty2##_);     \
  void benchForTruncOrZextVecInLoopFrom_##ty1##_To_##ty2##_(                   \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecInLoop<ty1, ty2>(state, &truncOrZextVecInLoop);      \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecInLoopFrom_##ty1##_To_##ty2##_);             \
  void benchForTruncOrZextVecWithAddInLoopWithVW8From_##ty1##_To_##ty2##_(     \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecWithAddInLoop<ty1, ty2>(                             \
        state, &truncOrZextVecWithAddInLoopWithVW8);                           \
  }                                                                            \
  BENCHMARK(                                                                   \
      benchForTruncOrZextVecWithAddInLoopWithVW8From_##ty1##_To_##ty2##_);     \
  void benchForTruncOrZextVecWithAddInLoopWithVW16From_##ty1##_To_##ty2##_(    \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecWithAddInLoop<ty1, ty2>(                             \
        state, &truncOrZextVecWithAddInLoopWithVW16);                          \
  }                                                                            \
  BENCHMARK(                                                                   \
      benchForTruncOrZextVecWithAddInLoopWithVW16From_##ty1##_To_##ty2##_);    \
  void benchForTruncOrZextVecWithAddInLoopFrom_##ty1##_To_##ty2##_(            \
      benchmark::State &state) {                                               \
    benchForTruncOrZextVecWithAddInLoop<ty1, ty2>(                             \
        state, &truncOrZextVecWithAddInLoop);                                  \
  }                                                                            \
  BENCHMARK(benchForTruncOrZextVecWithAddInLoopFrom_##ty1##_To_##ty2##_);

/* Vectorized truncate operations */
ADD_BENCHMARK(uint16_t, uint8_t)
ADD_BENCHMARK(uint32_t, uint8_t)
ADD_BENCHMARK(uint64_t, uint8_t)
ADD_BENCHMARK(uint32_t, uint16_t)
ADD_BENCHMARK(uint64_t, uint16_t)
ADD_BENCHMARK(uint64_t, uint32_t)

/* Vectorized zero extend operations */
ADD_BENCHMARK(uint8_t, uint16_t)
ADD_BENCHMARK(uint8_t, uint32_t)
ADD_BENCHMARK(uint8_t, uint64_t)
ADD_BENCHMARK(uint16_t, uint32_t)
ADD_BENCHMARK(uint16_t, uint64_t)
ADD_BENCHMARK(uint32_t, uint64_t)
