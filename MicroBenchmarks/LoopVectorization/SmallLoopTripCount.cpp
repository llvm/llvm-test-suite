// This program tests the performance impact of vectorization in loops with
// small trip counts. These cases exercise the LoopVectorize path that accepts
// trip counts one larger than the vectorization factor.

#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>

#include "benchmark/benchmark.h"

#define NOINLINE __attribute__((noinline))
#define LOOP_VECTORIZE_ENABLE                                                  \
  _Pragma("clang loop vectorize(enable) unroll(disable)")
#define LOOP_VECTORIZE_DISABLE                                                 \
  _Pragma("clang loop vectorize(disable) interleave(disable) unroll(disable)")
#define LOOP_INTERLEAVE_COUNT_2                                                \
  _Pragma("clang loop vectorize(enable) interleave_count(2) unroll(disable)")

static uint64_t g_small_loop_trip_count_sum = 0;

template <typename Ty>
NOINLINE void loopTc5Vector(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (uint64_t I = 0; I != 5; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

template <typename Ty>
NOINLINE void loopTc5Scalar(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (uint64_t I = 0; I != 5; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

NOINLINE void loopTc5I64InterleaveCount2Vector(const uint64_t *__restrict A,
                                               uint64_t *__restrict B) {
  LOOP_INTERLEAVE_COUNT_2
  for (uint64_t I = 0; I != 5; ++I)
    B[I] = A[I] + 1;
}

template <typename Ty> using KernelFn = void (*)(const Ty *, Ty *);

template <typename Ty> static void initData(std::array<Ty, 16> &A) {
  for (size_t I = 0; I != A.size(); ++I)
    A[I] = static_cast<Ty>(0x0102030405060708ULL + I);
}

template <typename Ty> static uint64_t checksum(const std::array<Ty, 16> &A) {
  uint64_t Sum = 0;
  for (size_t I = 0; I != 5; ++I) {
    auto Value = static_cast<uint64_t>(A[I]);
    for (size_t Byte = 0; Byte != sizeof(Ty); ++Byte) {
      Sum = Sum * 131 + (Value & std::numeric_limits<uint8_t>::max());
      Value >>= 8;
    }
  }
  return Sum;
}

template <typename Ty>
static void runBenchForSmallLoopTripCount(benchmark::State &State,
                                          KernelFn<Ty> Fn) {
  std::array<Ty, 16> A;
  std::array<Ty, 16> B = {};
  initData(A);

  for (auto _ : State) {
    benchmark::DoNotOptimize(A.data());
    benchmark::DoNotOptimize(B.data());
    Fn(A.data(), B.data());
    benchmark::ClobberMemory();
  }

  g_small_loop_trip_count_sum ^= checksum(B);
  benchmark::DoNotOptimize(g_small_loop_trip_count_sum);
  State.SetItemsProcessed(State.iterations() * 5);
}

template <typename Ty> void benchTc5Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5Vector<Ty>);
}

template <typename Ty> void benchTc5Scalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5Scalar<Ty>);
}

void benchTc5I64InterleaveCount2Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<uint64_t>(State,
                                          loopTc5I64InterleaveCount2Vector);
}

BENCHMARK_TEMPLATE(benchTc5Vector, uint8_t)->Name("tc5/i8/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint8_t)->Name("tc5/i8/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint16_t)->Name("tc5/i16/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint16_t)->Name("tc5/i16/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint32_t)->Name("tc5/i32/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint32_t)->Name("tc5/i32/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint64_t)->Name("tc5/i64/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint64_t)->Name("tc5/i64/scalar");
BENCHMARK(benchTc5I64InterleaveCount2Vector)->Name("tc5/i64/ic2/vector");
