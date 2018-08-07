/**
  Pankaj Kukreja
  github.com/proton0001
  Indian Institute of Technology Hyderabad
*/
#include "ImageHelper.h"
#include "interpolation.h"
#include <cstdlib>
#include <iostream> // std::cerr

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

extern "C" void bicubicKernel(int height, int width, int *inpImage,
                              int *outImage);
extern "C" void bilinearKernel(int height, int width, int *inpImage,
                               int *outImage);

int *inputImage;
int main(int argc, char **argv) {
#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *bicubicOutputFilename = (const char *)"./bicubicOutput.txt";
  const char *bilinearOutputFileName = (const char *)"./bilinearOutput.txt";

  inputImage = (int *)malloc(sizeof(int) * (HEIGHT) * (WIDTH));

  if (inputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }

  initializeRandomImage(inputImage, HEIGHT, WIDTH);

#ifdef BENCHMARK_LIB
  ::benchmark::RunSpecifiedBenchmarks();
#endif

  int outputHeight = ZOOM * HEIGHT;
  int outputWidth = ZOOM * HEIGHT;

  int *outputImage =
      (int *)malloc(sizeof(int) * (outputHeight) * (outputWidth));

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }

  for (int i = 0; i < outputHeight; i++) {
    for (int j = 0; j < outputWidth; j++) {
      outputImage[i * outputWidth + j] = 0;
    }
  }

  bicubicKernel(HEIGHT, WIDTH, inputImage, outputImage);
  saveImage(outputImage, bicubicOutputFilename, outputHeight, outputWidth);

  for (int i = 0; i < outputHeight; i++) {
    for (int j = 0; j < outputWidth; j++) {
      outputImage[i * outputWidth + j] = 0;
    }
  }

  bilinearKernel(HEIGHT, WIDTH, inputImage, outputImage);
  saveImage(outputImage, bilinearOutputFileName, outputHeight, outputWidth);

  free(inputImage);
  free(outputImage);
  return 0;
}

#ifdef BENCHMARK_LIB
void BENCHMARK_BICUBIC_INTERPOLATION(benchmark::State &state) {
  int inputHeight = state.range(0);
  int inputWidth = state.range(0);
  int outputHeight = ZOOM * inputHeight;
  int outputWidth = ZOOM * inputWidth;

  int *outputImage = (int *)malloc(sizeof(int) * outputHeight * outputWidth);

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  bicubicKernel(inputHeight, inputWidth, inputImage, outputImage);

  while (state.KeepRunning()) {
    bicubicKernel(inputHeight, inputWidth, inputImage, outputImage);
  }

  /* Since we are not passing state.range as 20 this if case will always be
   * false.
   * This call is to prevent above function calls from getting optimized out
   */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"failedCase.txt", outputHeight,
              outputWidth);
  }

  free(outputImage);
}
BENCHMARK(BENCHMARK_BICUBIC_INTERPOLATION)
    ->Arg(16)
    ->Arg(32)
    ->Arg(64)
    ->Arg(128)
    ->Arg(256)
    ->Unit(benchmark::kMicrosecond);

void BENCHMARK_BILINEAR_INTERPOLATION(benchmark::State &state) {
  int inputHeight = state.range(0);
  int inputWidth = state.range(0);
  int outputHeight = ZOOM * inputHeight;
  int outputWidth = ZOOM * inputWidth;
  int *outputImage = (int *)malloc(sizeof(int) * outputHeight * outputWidth);

  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(1);
  }
  /* This call is to warm up the cache */
  bilinearKernel(inputHeight, inputWidth, inputImage, outputImage);

  while (state.KeepRunning()) {
    bilinearKernel(inputHeight, inputWidth, inputImage, outputImage);
  }

  /* Since we are not passing state.range as 20 this if case will always be
   * false.
   * This call is to prevent above function calls from getting optimized out
   */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"failedCase.txt", outputHeight,
              outputWidth);
  }

  free(outputImage);
}
BENCHMARK(BENCHMARK_BILINEAR_INTERPOLATION)
    ->Arg(16)
    ->Arg(32)
    ->Arg(64)
    ->Arg(128)
    ->Arg(256)
    ->Unit(benchmark::kMicrosecond);

#endif