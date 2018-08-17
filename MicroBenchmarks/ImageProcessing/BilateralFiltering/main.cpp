/**
  Pankaj Kukreja
  github.com/proton0001
  Indian Institute of Technology Hyderabad
*/

#include "ImageHelper.h"
#include "bilateralFiltering.h"
#include <iostream> // std::cerr
#include <cstdlib>

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

int *inputImage;
extern "C" void bilateralFilterKernel(int height, int width, int *inputImage,
                                      int *outputImage, int diameter);

int main(int argc, char *argv[]) {

#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *bilateralFilterOutputFileName =
      (const char *)"./bilateralFilterOutput.txt";

  inputImage = (int *)malloc(sizeof(int) * (HEIGHT) * (WIDTH));

  if (inputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }

  initializeRandomImage(inputImage, HEIGHT, WIDTH);

#ifdef BENCHMARK_LIB
  ::benchmark::RunSpecifiedBenchmarks();
#endif

  int *outputImage = (int *)malloc(sizeof(int) * (HEIGHT) * (WIDTH));
  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  bilateralFilterKernel(HEIGHT, WIDTH, inputImage, outputImage, DIAMETER);

  saveImage(outputImage, bilateralFilterOutputFileName, HEIGHT, WIDTH);

  free(outputImage);
  free(inputImage);
  return (EXIT_SUCCESS);
}

#ifdef BENCHMARK_LIB
void BENCHMARK_BILATERAL_FILTER(benchmark::State &state) {

  int height = state.range(0);
  int width = state.range(0);
  int diameter = state.range(1);

  int *outputImage = (int *)malloc(sizeof(int) * (height) * (width));
  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }
  /* first call made to warm up the cache*/
  bilateralFilterKernel(height, width, inputImage, outputImage, diameter);
  while (state.KeepRunning()) {
    bilateralFilterKernel(height, width, inputImage, outputImage, diameter);
  }

  /* Since we are not passing state.range as 20 this if case will always be
   * false. This check is to prevent above kernel calls from getting
   * optimized out
   */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"testFailed.txt", height, width);
  }

  free(outputImage);
}

#if (HEIGHT < WIDTH)
#define MINIMUM_DIM HEIGHT
#else
#define MINIMUM_DIM WIDTH
#endif
static void CustomArguments(benchmark::internal::Benchmark *b) {
  int limit = MINIMUM_DIM;
  int start = 16;
  if (start > limit) {
    start = 1;
  }
  for (int i = start; i < limit; i <<= 1) {
    b->ArgPair(i, 2);
    b->ArgPair(i, 4);
  }
}
BENCHMARK(BENCHMARK_BILATERAL_FILTER)
    ->Apply(CustomArguments)
    ->Unit(benchmark::kMicrosecond);
#endif
