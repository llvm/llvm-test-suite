/**
  Pankaj Kukreja
  github.com/proton0001
  Indian Institute of Technology Hyderabad
*/

#include "ImageHelper.h"
#include "diffusion.h"
#include <cstdlib>
#include <iostream> // std::cerr

#define BENCHMARK_LIB
#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

int *inputImage;
extern "C" void anisotropicDiffusionKernel(int height, int width, int *source,
                                           int *destination, int num_iteration);
int main(int argc, char *argv[]) {

#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
#endif

  const char *anisotropicDiffusionOutputFileName =
      (const char *)"./anisotropicDiffusionOutput.txt";

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

  anisotropicDiffusionKernel(HEIGHT, WIDTH, inputImage, outputImage, ITERATION);

  for (int j = 0; j < WIDTH; j++) {
    outputImage[0 + j] = 0;
    outputImage[1 * WIDTH + j] = 0;
    outputImage[(HEIGHT - 1) * WIDTH + j] = 0;
    outputImage[(HEIGHT - 2) * WIDTH + j] = 0;
  }

  for (int i = 0; i < HEIGHT; i++) {
    outputImage[i * WIDTH + 0] = 0;
    outputImage[i * WIDTH + 1] = 0;
    outputImage[i * WIDTH + (WIDTH - 1)] = 0;
    outputImage[i * WIDTH + (WIDTH - 2)] = 0;
  }

  saveImage(outputImage, anisotropicDiffusionOutputFileName, HEIGHT, WIDTH);

  free(outputImage);
  free(inputImage);

  return EXIT_SUCCESS;
}

#ifdef BENCHMARK_LIB
void BENCHMARK_ANISTROPIC_DIFFUSION(benchmark::State &state) {

  int height = state.range(0);
  int width = state.range(0);

  int *outputImage = (int *)malloc(sizeof(int) * (height) * (width));
  if (outputImage == NULL) {
    std::cerr << "Insufficient memory\n";
    exit(EXIT_FAILURE);
  }
  /* first call made to warm up cache */
  anisotropicDiffusionKernel(height, width, inputImage, outputImage, ITERATION);

  while (state.KeepRunning()) {
    anisotropicDiffusionKernel(height, width, inputImage, outputImage,
                               ITERATION);
  }
  /* Since we are not passing state.range as 20 this if case will always be
   * false.
   * This call is to make compiler think that outputImage may be used
   * later so that above kernel calls will not get optimize out */
  if (state.range(0) == 20) {
    saveImage(outputImage, (const char *)"testFailed.txt", height, width);
  }

  free(outputImage);
}

BENCHMARK(BENCHMARK_ANISTROPIC_DIFFUSION)
    ->Arg(32)
    ->Arg(64)
    ->Arg(128)
    ->Arg(256)
    ->Unit(benchmark::kMicrosecond);
#endif
