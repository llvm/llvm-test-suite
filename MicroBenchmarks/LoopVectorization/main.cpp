#include "benchmark/benchmark.h"

int main(int argc, char *argv[]) {
  benchmark::Initialize(&argc, argv);

  benchmark::RunSpecifiedBenchmarks();
  return EXIT_SUCCESS;
}
