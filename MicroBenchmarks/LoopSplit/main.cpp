// Microbenchmark for #pragma omp split counts(...).
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "benchmark/benchmark.h"

// Large N for measurable runs; lit verification uses same kernel once.
#define N 200000000

// Kernel: sum 0..(N-1) with split into four segments.
static long run_split() {
  long sum = 0;
#pragma omp split counts(50000000, 50000000, 50000000, omp_fill)
  for (int i = 0; i < N; ++i)
    sum += i;
  return sum;
}

// Baseline: same loop without split (for comparison).
static long run_baseline() {
  long sum = 0;
  for (int i = 0; i < N; ++i)
    sum += i;
  return sum;
}

int main(int argc, char *argv[]) {
  benchmark::Initialize(&argc, argv);

  // Run kernel once and write result for lit verification.
  std::ofstream myfile("LoopSplit.txt");
  if (myfile.is_open()) {
    long y = run_split();
    myfile << "test1: " << y << "\n";
    myfile.close();
  } else {
    return EXIT_FAILURE;
  }

  benchmark::RunSpecifiedBenchmarks();
  return EXIT_SUCCESS;
}

static void BM_Split(benchmark::State &state) {
  long x = 0;
  for (auto _ : state)
    benchmark::DoNotOptimize(x += run_split());
}
BENCHMARK(BM_Split)->Unit(benchmark::kMicrosecond)->MinTime(2.0);

static void BM_Baseline(benchmark::State &state) {
  long x = 0;
  for (auto _ : state)
    benchmark::DoNotOptimize(x += run_baseline());
}
BENCHMARK(BM_Baseline)->Unit(benchmark::kMicrosecond)->MinTime(2.0);
