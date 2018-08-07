/**
Pankaj Kukreja
github.com/proton0001
Indian Institute of Technology Hyderabad
*/

#include "ImageHelper.h"
#include "blur.h"
#include <cstdlib>
#include <iostream>

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif
extern "C" void boxBlurKernel(int height, int width, int *inpImage,
                              int *outpImage);
extern "C" void gaussianBlurKernel(int height, int width, int *inpImage,
                                   int *outpImage);
int *inputImage;
int main(int argc, char *argv[]) {

#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *boxBlurOutputFileName = (const char *)"./boxBlurOutput.txt";
  const char *gaussianBlurOutputFileName =
      (const char *)"./gaussianBlurOutput.txt";

  inputImage = (int *)malloc(sizeof(int) * (HEIGHT) * (WIDTH));

  if (inputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }

  initializeRandomImage(inputImage, HEIGHT, WIDTH);

// Run Kernels Using Benchmark Library
#ifdef BENCHMARK_LIB
  ::benchmark::RunSpecifiedBenchmarks();
#endif

  // Run Kernels once more and save output in a file for Verification
  int *outputImage;
  outputImage = (int *)malloc(sizeof(int) * (HEIGHT) * (WIDTH));

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }

  boxBlurKernel(HEIGHT, WIDTH, inputImage, outputImage);

  // Blur not applied on edges so we add a black border
  // Otherwise we may get garbage value which may create problem in output
  // verification

  int offset = (BOX_SIZE - 1) / 2;
  // Top Edge
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  // Bottom Edge
  for (int i = HEIGHT - offset; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  // Left Edge
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < offset; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }
  // Right Edge
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = WIDTH - offset; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  saveImage(outputImage, boxBlurOutputFileName, HEIGHT, WIDTH);

  gaussianBlurKernel(HEIGHT, WIDTH, inputImage, outputImage);

  // Top Edge
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  // Bottom Edge
  for (int i = HEIGHT - offset; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  // Left Edge
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < offset; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }
  // Right Edge
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = WIDTH - offset; j < WIDTH; j++) {
      outputImage[i * WIDTH + j] = 0;
    }
  }

  saveImage(outputImage, gaussianBlurOutputFileName, HEIGHT, WIDTH);

  free(outputImage);
  free(inputImage);
  return EXIT_SUCCESS;
}

#ifdef BENCHMARK_LIB
void BENCHMARK_boxBlurKernel(benchmark::State &state) {

  int height = state.range(0);
  int width = state.range(0);

  int *outputImage = (int *)malloc(sizeof(int) * (height) * (width));

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  boxBlurKernel(height, width, inputImage, outputImage);

  while (state.KeepRunning()) {
    boxBlurKernel(height, width, inputImage, outputImage);
  }
  /* Since we are not passing state.range as 20 this if case will always be
   * false. This if case is to prevent above kernel calls from getting optimized
   * out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"testFailed.txt", height, width);
  }

  free(outputImage);
}
BENCHMARK(BENCHMARK_boxBlurKernel)
    ->Arg(128)
    ->Arg(256)
    ->Arg(512)
    ->Arg(1024)
    ->Unit(benchmark::kMicrosecond);

void BENCHMARK_GAUSSIAN_BLUR(benchmark::State &state) {

  int height = state.range(0);
  int width = state.range(0);

  int *outputImage = (int *)malloc(sizeof(int) * (height) * (width));

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  gaussianBlurKernel(height, width, inputImage, outputImage);
  while (state.KeepRunning()) {
    gaussianBlurKernel(height, width, inputImage, outputImage);
  }
  /* Since we are not passing state.range as 20 this if case will always be
   * false. This if case is to prevent above kernel calls from getting optimized
   * out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"testFailed.txt", height, width);
  }

  free(outputImage);
}

BENCHMARK(BENCHMARK_GAUSSIAN_BLUR)
    ->Arg(128)
    ->Arg(256)
    ->Arg(512)
    ->Arg(1024)
    ->Unit(benchmark::kMicrosecond);
#endif
