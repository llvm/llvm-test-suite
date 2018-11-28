#include <iostream>
#include <cstdlib>
#include <fstream>

#include "benchmark/benchmark.h"


#define N 1024
unsigned A[N][N];

void init() {
  for (unsigned i = 0; i < N; i++)
    for (unsigned j = 0; j < N; j++)
      A[i][j] = i + j;
}

unsigned y = 0;

static unsigned test1() {
  for (unsigned i = 0; i < N; i++) {
    y = 0;
    for (unsigned j = 0; j < N; j++) {
      A[i][j] += 1;
      y += A[i][j];
    }
  }
  return y;
}

int main(int argc, char *argv[]) {
  benchmark::Initialize(&argc, argv);

  init();

  // Run kernels once, to test functionality.
  std::ofstream myfile ("LoopInterchange.txt");
  if (myfile.is_open())   {
    unsigned y = test1();
    myfile << "test1: " << y << "\n";
    myfile.close();
  } else
    return EXIT_FAILURE;

  benchmark::RunSpecifiedBenchmarks();
  return EXIT_SUCCESS;
}

void BENCHMARK_LI1(benchmark::State &state) {
  unsigned x = 0;
  for (auto _ : state)
    benchmark::DoNotOptimize(x += test1());
}

BENCHMARK(BENCHMARK_LI1)->Unit(benchmark::kMicrosecond);
