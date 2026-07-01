// This program tests the performance impact of vectorization in loops with
// small trip counts. These cases exercise the LoopVectorize path that accepts
// trip counts one larger than the vectorization factor.

#include <array>
#include <cstddef>
#include <cstdint>

#include "benchmark/benchmark.h"

#define NOINLINE __attribute__((noinline))
#define LOOP_VECTORIZE_ENABLE                                                  \
  _Pragma("clang loop vectorize(enable) unroll(disable)")
#define LOOP_VECTORIZE_DISABLE                                                 \
  _Pragma("clang loop vectorize(disable) interleave(disable) unroll(disable)")
#define LOOP_INTERLEAVE_COUNT_2                                                \
  _Pragma("clang loop vectorize(enable) interleave_count(2) unroll(disable)")

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

template <typename Ty>
NOINLINE void loopTc5I64InterleaveCount2Vector(const Ty *__restrict A,
                                               Ty *__restrict B) {
  LOOP_INTERLEAVE_COUNT_2
  for (uint64_t I = 0; I != 5; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

template <typename Ty>
NOINLINE void loopTc5ScalarizedDivVector(const Ty *__restrict A,
                                         Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (uint64_t I = 0; I != 5; ++I) {
    Ty Den = (A[I] & static_cast<Ty>(15)) + static_cast<Ty>(1);
    B[I] = (A[I] * static_cast<Ty>(13)) / Den;
  }
}

template <typename Ty>
NOINLINE void loopTc5ScalarizedDivScalar(const Ty *__restrict A,
                                         Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (uint64_t I = 0; I != 5; ++I) {
    Ty Den = (A[I] & static_cast<Ty>(15)) + static_cast<Ty>(1);
    B[I] = (A[I] * static_cast<Ty>(13)) / Den;
  }
}

template <typename Ty>
NOINLINE void loopTc3Vector(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (uint64_t I = 0; I != 3; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

template <typename Ty>
NOINLINE void loopTc3Scalar(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (uint64_t I = 0; I != 3; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

template <typename Ty>
NOINLINE void loopTc3I64InterleaveCount2Vector(const Ty *__restrict A,
                                               Ty *__restrict B) {
  LOOP_INTERLEAVE_COUNT_2
  for (uint64_t I = 0; I != 3; ++I)
    B[I] = A[I] + static_cast<Ty>(1);
}

template <typename Ty>
NOINLINE void loopTc3SelectionVector(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (int i = 0; i < 3; i++) {
    B[i] = B[i] < A[i] ? B[i] : A[i];
  }
}

template <typename Ty>
NOINLINE void loopTc3SelectionScalar(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (int i = 0; i < 3; i++) {
    B[i] = B[i] < A[i] ? B[i] : A[i];
  }
}

template <typename Ty>
NOINLINE void loopTc5PowerVector(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (int i = 0; i < 5; i++) {
    B[i] ^= A[i];
  }
}

template <typename Ty>
NOINLINE void loopTc5PowerScalar(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (int i = 0; i < 5; i++) {
    B[i] ^= A[i];
  }
}

template <typename Ty>
NOINLINE void loopTc5ModulusVector(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_ENABLE
  for (int i = 0; i < 5; i++) {
    B[i] %= (A[i] | 1);
  }
}

template <typename Ty>
NOINLINE void loopTc5ModulusScalar(const Ty *__restrict A, Ty *__restrict B) {
  LOOP_VECTORIZE_DISABLE
  for (int i = 0; i < 5; i++) {
    B[i] %= (A[i] | 1);
  }
}

template <typename Ty> using KernelFn = void (*)(const Ty *, Ty *);

template <typename Ty> static void initData(std::array<Ty, 16> &A) {
  for (size_t I = 0; I != A.size(); ++I)
    A[I] = static_cast<Ty>(0x0102030405060708ULL + I);
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
}

template <typename Ty> void benchTc5Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5Vector<Ty>);
}

template <typename Ty> void benchTc5Scalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5Scalar<Ty>);
}

template <typename Ty>
void benchTc5I64InterleaveCount2Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State,
                                    loopTc5I64InterleaveCount2Vector<Ty>);
}

template <typename Ty>
void benchTc5ScalarizedDivVector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5ScalarizedDivVector<Ty>);
}

template <typename Ty>
void benchTc5ScalarizedDivScalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5ScalarizedDivScalar<Ty>);
}

template <typename Ty> void benchTc3Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc3Vector<Ty>);
}

template <typename Ty> void benchTc3Scalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc3Scalar<Ty>);
}

template <typename Ty>
void benchTc3I64InterleaveCount2Vector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State,
                                    loopTc3I64InterleaveCount2Vector<Ty>);
}

template <typename Ty>
void benchloopTc3SelectionVector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc3SelectionVector<Ty>);
}

template <typename Ty>
void benchloopTc3SelectionScalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc3SelectionScalar<Ty>);
}

template <typename Ty> void benchloopTC5PowerVector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5PowerVector<Ty>);
}

template <typename Ty> void benchloopTC5PowerScalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5PowerScalar<Ty>);
}

template <typename Ty> void benchloopTc5ModulusVector(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5ModulusVector<Ty>);
}

template <typename Ty> void benchloopTc5ModulusScalar(benchmark::State &State) {
  runBenchForSmallLoopTripCount<Ty>(State, loopTc5ModulusScalar<Ty>);
}

BENCHMARK_TEMPLATE(benchTc5Vector, uint8_t)->Name("tc5/i8/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint8_t)->Name("tc5/i8/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint16_t)->Name("tc5/i16/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint16_t)->Name("tc5/i16/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint32_t)->Name("tc5/i32/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint32_t)->Name("tc5/i32/scalar");
BENCHMARK_TEMPLATE(benchTc5Vector, uint64_t)->Name("tc5/i64/vector");
BENCHMARK_TEMPLATE(benchTc5Scalar, uint64_t)->Name("tc5/i64/scalar");
BENCHMARK_TEMPLATE(benchTc5I64InterleaveCount2Vector, uint64_t)
    ->Name("tc5/i64/ic2/vector");
BENCHMARK_TEMPLATE(benchTc5ScalarizedDivVector, uint64_t)
    ->Name("tc5/i64/scalarized-div/vector");
BENCHMARK_TEMPLATE(benchTc5ScalarizedDivScalar, uint64_t)
    ->Name("tc5/i64/scalarized-div/scalar");

BENCHMARK_TEMPLATE(benchTc3Vector, uint8_t)->Name("tc3/i8/vector");
BENCHMARK_TEMPLATE(benchTc3Scalar, uint8_t)->Name("tc3/i8/scalar");
BENCHMARK_TEMPLATE(benchTc3Vector, uint16_t)->Name("tc3/i16/vector");
BENCHMARK_TEMPLATE(benchTc3Scalar, uint16_t)->Name("tc3/i16/scalar");
BENCHMARK_TEMPLATE(benchTc3Vector, uint32_t)->Name("tc3/i32/vector");
BENCHMARK_TEMPLATE(benchTc3Scalar, uint32_t)->Name("tc3/i32/scalar");
BENCHMARK_TEMPLATE(benchTc3Vector, uint64_t)->Name("tc3/i64/vector");
BENCHMARK_TEMPLATE(benchTc3Scalar, uint64_t)->Name("tc3/i64/scalar");
BENCHMARK_TEMPLATE(benchTc3I64InterleaveCount2Vector, uint64_t)
    ->Name("tc3/i64/ic2/vector");
BENCHMARK_TEMPLATE(benchloopTc3SelectionVector, int8_t)
    ->Name("tc3Selection/i8/vector");
BENCHMARK_TEMPLATE(benchloopTc3SelectionScalar, int8_t)
    ->Name("tc3Selection/i8/scalar");
BENCHMARK_TEMPLATE(benchloopTc3SelectionVector, int16_t)
    ->Name("tc3Selection/i16/vector");
BENCHMARK_TEMPLATE(benchloopTc3SelectionScalar, int16_t)
    ->Name("tc3Selection/i16/scalar");
BENCHMARK_TEMPLATE(benchloopTC5PowerVector, int8_t)->Name("tc5Power/i8/vector");
BENCHMARK_TEMPLATE(benchloopTC5PowerScalar, int8_t)->Name("tc5Power/i8/scalar");
BENCHMARK_TEMPLATE(benchloopTC5PowerVector, int16_t)
    ->Name("tc5Power/i16/vector");
BENCHMARK_TEMPLATE(benchloopTC5PowerScalar, int16_t)
    ->Name("tc5Power/i16/scalar");
BENCHMARK_TEMPLATE(benchloopTc5ModulusVector, int32_t)
    ->Name("tc5Modulus/i32/vector");
BENCHMARK_TEMPLATE(benchloopTc5ModulusScalar, int32_t)
    ->Name("tc5Modulus/i32/scalar");
