// This program measures vectorized reductions whose start value becomes
// available at different times.
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>

#include "benchmark/benchmark.h"

static constexpr int Rows = 8;
static constexpr int NumBufs = 16;

template <typename T> static void initData(T *A, unsigned N) {
  std::mt19937 Rng(12345);
  std::uniform_int_distribution<int> Dist(0, 15);
  for (unsigned I = 0; I < N; I++)
    A[I] = Dist(Rng);
}

template <typename T> static T refSum(const T *A, int N, T Start) {
  for (int I = 0; I < N; I++)
    Start += A[I];
  return Start;
}

template <typename T> static void verify(const char *Name, T Got, T Expected) {
  if (Got != Expected) {
    std::cerr << "ERROR: " << Name << ": vectorized result " << Got
              << " != scalar result " << Expected << "\n";
    exit(1);
  }
}

// Sum of a Rows x N array, one row at a time.
template <typename T>
static __attribute__((noinline)) T sumOuterCarriedStart(const T *A, int N) {
#pragma clang fp reassociate(on)
  T S = 0;
  for (int R = 0; R < Rows; R++, A += N)
    for (int I = 0; I < N; I++)
      S += A[I];
  return S;
}

// Sum of N elements, starting at zero.
template <typename T>
static __attribute__((noinline)) T sumConstantStart(const T *A, int N) {
#pragma clang fp reassociate(on)
  T S = 0;
  for (int I = 0; I < N; I++)
    S += A[I];
  return S;
}

// Sum of N elements, starting from a value loaded from memory.
template <typename T>
__attribute__((noinline)) T sumLoadedStart(const T *A, int N, const T *Start) {
#pragma clang fp reassociate(on)
  T S = *Start;
  for (int I = 0; I < N; I++)
    S += A[I];
  return S;
}

// Benchmark \p Kernel, which sums Len elements of a buffer starting from
// \p Start, on NumBufs buffers. Each result selects the next buffer, so each
// call depends on the previous one: this measures latency, not throughput.
template <typename T, typename F>
static void runBenchmark(benchmark::State &State, int Len, T Start, F Kernel) {
  std::unique_ptr<T[]> A(new T[NumBufs * Len]);
  initData(&A[0], NumBufs * Len);
#ifdef BENCH_AND_VERIFY
  verify(State.name().c_str(), Kernel(&A[0]), refSum(&A[0], Len, Start));
#endif
  unsigned Buf = 0;
  for (auto _ : State) {
    T R = Kernel(&A[Buf * Len]);
    benchmark::DoNotOptimize(R);
    Buf = (Buf + 1 + (static_cast<int64_t>(R) & 1)) % NumBufs;
  }
}

// Start value carried across the rows of an outer loop.
template <typename T>
static void benchReductionOuterCarriedStart(benchmark::State &State) {
  int N = State.range(0);
  runBenchmark(State, Rows * N, T(0),
               [N](const T *A) { return sumOuterCarriedStart(A, N); });
}

// Constant start value: available early for the main vector loop. The epilogue
// vector loop's start value is the main vector loop's result.
template <typename T>
static void benchReductionConstantStart(benchmark::State &State) {
  int N = State.range(0);
  runBenchmark(State, N, T(0),
               [N](const T *A) { return sumConstantStart(A, N); });
}

// Start value loaded from memory.
template <typename T>
static void benchReductionLoadedStart(benchmark::State &State) {
  int N = State.range(0);
  T Start = 3;
  runBenchmark(State, N, Start, [N, &Start](const T *A) {
    return sumLoadedStart(A, N, &Start);
  });
}

#ifdef ALL_REDUCTION_START_TESTS
#define TRIP_COUNTS DenseRange(4, 64, 4)->Arg(200)->Arg(1000)
#else
#define TRIP_COUNTS Arg(12)->Arg(32)->Arg(44)->Arg(200)
#endif

BENCHMARK_TEMPLATE(benchReductionOuterCarriedStart, uint32_t)->TRIP_COUNTS;
BENCHMARK_TEMPLATE(benchReductionOuterCarriedStart, float)->TRIP_COUNTS;
BENCHMARK_TEMPLATE(benchReductionConstantStart, float)->TRIP_COUNTS;
BENCHMARK_TEMPLATE(benchReductionLoadedStart, float)->TRIP_COUNTS;
