/**
  Pankaj Kukreja
  github.com/proton0001
  Indian Institute of Technology Hyderabad
*/
#include "ImageHelper.h"
#include "dilate.h"
#include <iostream>
#include <cstdlib>

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

int *inputImage;
extern "C" void dilateKernel(int height, int width, int *inputImage,
                             int *outputImage, int *temporary);

int main(int argc, char *argv[]) {
#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *dilateOutputFileName = (const char *)"./dilateOutput.txt";

  inputImage = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);

  if (inputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }

  initializeRandomImage(inputImage, HEIGHT, WIDTH);

#ifdef BENCHMARK_LIB
  ::benchmark::RunSpecifiedBenchmarks();
#endif
  int *outputImage = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);
  int *temp = (int *)malloc(sizeof(int) * HEIGHT * WIDTH);

  if (outputImage == NULL || temp == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }

  dilateKernel(HEIGHT, WIDTH, inputImage, outputImage, temp);

  for (int j = 0; j < WIDTH; j++) {
    outputImage[0 * WIDTH + j] = 0;
    outputImage[(HEIGHT - 1) * WIDTH + j] = 0;
  }

  for (int i = 0; i < HEIGHT; i++) {
    outputImage[i * WIDTH + 0] = 0;
    outputImage[i * WIDTH + (WIDTH - 1)] = 0;
  }

  saveImage(outputImage, dilateOutputFileName, HEIGHT, WIDTH);
  free(temp);
  free(outputImage);
  free(inputImage);
  return (EXIT_SUCCESS);
}

#ifdef BENCHMARK_LIB
void BENCHMARK_DILATE(benchmark::State &state) {
  /* taking height = width */
  int height = state.range(0);
  int width = state.range(0);

  int *outputImage = (int *)malloc(sizeof(int) * height * width);
  int *temp = (int *)malloc(sizeof(int) * height * width);
  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }

  /* This call is to warm up the cache */
  dilateKernel(height, width, inputImage, outputImage, temp);

  while (state.KeepRunning()) {
    dilateKernel(height, width, inputImage, outputImage, temp);
  }

  /* Since we are not passing state.range as 20 this if case will always be
   * false. This call is to make compiler think that outputImage may be used
   * later so that above kernel calls will not optimize out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"testFailed.txt", height, width);
  }
  free(temp);
  free(outputImage);
}

#define MINIMUM_DIM (HEIGHT > WIDTH) ? WIDTH : HEIGHT
#if MINIMUM_DIM > 512
BENCHMARK(BENCHMARK_DILATE)
    ->RangeMultiplier(2)
    ->Range(128, MINIMUM_DIM)
    ->Unit(benchmark::kMicrosecond);
#else
BENCHMARK(BENCHMARK_DILATE)
    ->RangeMultiplier(2)
    ->Range(1, MINIMUM_DIM)
    ->Unit(benchmark::kMicrosecond);
#endif
#endif
