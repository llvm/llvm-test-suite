/**
  Pankaj Kukreja
  github.com/proton0001
  Indian Institute of Technology Hyderabad
*/
#include "ImageHelper.h"
#include "dither.h"
#include <cmath>
#include <cstdlib>
#include <iostream> // std::cerr

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

int *inputImage;
extern "C" {
void orderedDitherKernel(int height, int width, int *inpImage, int *outImage,
                         int *temp, int n, int m);
void floydDitherKernel(int height, int width, int *inpImage, int *outImage);
}
int main(int argc, char **argv) {
#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *orderedOutputFilename = (char *)"./orderedOutput.txt";
  const char *floydOutputFilename = (char *)"./floydOutput.txt";
  inputImage = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);
  if (inputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  initializeRandomImage(inputImage, HEIGHT, WIDTH);

#ifdef BENCHMARK_LIB
  ::benchmark::RunSpecifiedBenchmarks();
#endif
  int *outputImage = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);
  int *temp = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);
  if (outputImage == NULL || temp == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  orderedDitherKernel(HEIGHT, WIDTH, inputImage, outputImage, temp, 16, 4);
  saveImage(outputImage, orderedOutputFilename, HEIGHT, WIDTH);
  floydDitherKernel(HEIGHT, WIDTH, inputImage, outputImage);

  for (int i = 0; i < HEIGHT; i++) {
    outputImage[(i)*WIDTH + 0] = 0;
    outputImage[(i)*WIDTH + WIDTH - 1] = 0;
  }

  for (int j = 0; j < WIDTH; j++) {
    outputImage[(0) * WIDTH + j] = 0;
    outputImage[(HEIGHT - 1) * WIDTH + j] = 0;
  }

  saveImage(outputImage, floydOutputFilename, HEIGHT, WIDTH);
  free(temp);
  free(outputImage);
  free(inputImage);
  return EXIT_SUCCESS;
}

#ifdef BENCHMARK_LIB
void BENCHMARK_ORDERED_DITHER(benchmark::State &state) {
  int height = state.range(0);
  int width = state.range(0);
  int m = state.range(1);
  int n = pow((double)m, 2);
  int *outputImage = (int *)malloc(sizeof(int) * height * width);
  int *temp = (int *)malloc(sizeof(int) * height * width);

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  orderedDitherKernel(height, width, inputImage, outputImage, temp, n, m);

  while (state.KeepRunning()) {
    orderedDitherKernel(height, width, inputImage, outputImage, temp, n, m);
  }
  /* Since we are not passing state.range as 20 this if case will always be
   * false. This call is to make compiler think that outputImage may be used
   * later so that above kernel calls will not optimize out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"failedCase.txt", height, width);
  }
  free(temp);
  free(outputImage);
}

#if (HEIGHT < WIDTH)
#define MINIMUM_DIM HEIGHT
#else
#define MINIMUM_DIM WIDTH
#endif

static void CustomArguments(benchmark::internal::Benchmark *b) {
  int limit = MINIMUM_DIM;
  int start = 1;
  if (limit > 128) {
    start = 128;
  }
  for (int i = start; i <= limit; i <<= 1) {
    b->ArgPair(i, 2);
    b->ArgPair(i, 3);
    b->ArgPair(i, 4);
    b->ArgPair(i, 8);
  }
}
BENCHMARK(BENCHMARK_ORDERED_DITHER)
    ->Apply(CustomArguments)
    ->Unit(benchmark::kMicrosecond);

void BENCHMARK_FLOYD_DITHER(benchmark::State &state) {

  int height = state.range(0);
  int width = state.range(0);

  int *outputImage = (int *)malloc(sizeof(int) * height * width);

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  floydDitherKernel(height, width, inputImage, outputImage);
  while (state.KeepRunning()) {
    floydDitherKernel(height, width, inputImage, outputImage);
  }
  /* Since we are not passing state.range as 20 this if case will always be
   * false. This call is to make compiler think that outputImage may be used
   * later so that above kernel calls will not optimize out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"failedCase.txt", height, width);
  }

  free(outputImage);
}

#if MINIMUM_DIM > 128
BENCHMARK(BENCHMARK_FLOYD_DITHER)
    ->RangeMultiplier(2)
    ->Range(128, MINIMUM_DIM)
    ->Unit(benchmark::kMicrosecond);
#else
BENCHMARK(BENCHMARK_FLOYD_DITHER)
    ->RangeMultiplier(2)
    ->Range(1, MINIMUM_DIM)
    ->Unit(benchmark::kMicrosecond);
#endif

#endif
