#include "harris.h"
int sum = 0;

#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

// This function initializes the input image to checkbox image
void initCheckboardImage(int height, int width,
                         float image[(2 + HEIGHT)][2 + WIDTH]) {
  int last_pixel_x = 0;
  int last_pixel_y = 0;
  for (int i = 0; i < height; i++) {
    if (i % BOX_SIZE == 0) {
      last_pixel_y = (last_pixel_y + 1) % 2;
    }
    last_pixel_x = last_pixel_y;
    for (int j = 0; j < width; j++) {
      if (j % BOX_SIZE == 0) {
        last_pixel_x = (last_pixel_x + 1) % 2;
      }
      if (last_pixel_x == 0) {
        image[i][j] = 255;
      } else {
        image[i][j] = 0;
      }
    }
  }
}

// Writes image matrix to a file.
void printImage(int height, int width, float arr[(2 + HEIGHT)][2 + WIDTH],
                int dummy) {
  std::ofstream myfile;
  myfile.open("output.txt");
  for (int i = 0; i < height - 2; i++) {
    for (int j = 0; j < width - 2; j++) {
      if (arr[i][j] < 0) {
        myfile << 0;
      } else if (arr[i][j] > 255) {
        myfile << 3;
      } else {
        myfile << (int)(arr[i][j]);
      }
    }
    myfile << "\n";
  }

  // Dummy code to make sure the allocated ImageOutput Array is not optimized
  // out
  if (dummy > 0) {
    myfile << sum;
  }
}

#ifdef BENCHMARK_LIB
void BENCHMARK_HARRIS(benchmark::State &state) {
  int height = state.range(0);
  int width = state.range(1);

  float(*image)[HEIGHT + 2][WIDTH + 2];
  image = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  initCheckboardImage((HEIGHT + 2), (WIDTH + 2), *image);

  float(*imageOutput)[2 + HEIGHT][2 + WIDTH];
  imageOutput = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));

  float(*Ix)[2 + HEIGHT][2 + WIDTH];
  float(*Iy)[2 + HEIGHT][2 + WIDTH];
  float(*Ixx)[2 + HEIGHT][2 + WIDTH];
  float(*Ixy)[2 + HEIGHT][2 + WIDTH];
  float(*Iyy)[2 + HEIGHT][2 + WIDTH];
  float(*Sxx)[2 + HEIGHT][2 + WIDTH];
  float(*Sxy)[2 + HEIGHT][2 + WIDTH];
  float(*Syy)[2 + HEIGHT][2 + WIDTH];
  float(*det)[2 + HEIGHT][2 + WIDTH];
  float(*trace)[2 + HEIGHT][2 + WIDTH];

  Ix = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Iy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Ixx = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Ixy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Iyy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Sxx = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Sxy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Syy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  det = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  trace = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));

  harrisKernel(height, width, *image, *imageOutput, *Ix, *Iy, *Ixx, *Ixy, *Iyy,
               *Sxx, *Sxy, *Syy, *det, *trace);

  for (auto _ : state) {
    harrisKernel(height, width, *image, *imageOutput, *Ix, *Iy, *Ixx, *Ixy,
                 *Iyy, *Sxx, *Sxy, *Syy, *det, *trace);
  }

  free((void *)Ix);
  free((void *)Iy);
  free((void *)Ixx);
  free((void *)Ixy);
  free((void *)Iyy);
  free((void *)Sxx);
  free((void *)Sxy);
  free((void *)Syy);
  free((void *)det);
  free((void *)trace);

  for (int i = 0; i < height + 2; i++) {
    for (int j = 0; j < width + 2; j++) {
      sum = (sum + 1) & (int)(*imageOutput)[i][j];
    }
  }

  state.SetBytesProcessed(sizeof(float) * (height + 2) * (width + 2) *
                          state.iterations());

  free((void *)imageOutput);
  free((void *)image);
}
BENCHMARK(BENCHMARK_HARRIS)
    ->Args({256, 256})
    ->Args({512, 512})
    ->Args({1024, 1024})
    ->Args({2048, 2048})
    ->Unit(benchmark::kMicrosecond);

#endif

int main(int argc, char *argv[]) {
  sum = 1;
#ifdef BENCHMARK_LIB
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;
  ::benchmark::RunSpecifiedBenchmarks();
#endif

  // Extra Call to verify output of kernel
  float(*image)[HEIGHT + 2][WIDTH + 2];
  image = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  initCheckboardImage((HEIGHT + 2), (WIDTH + 2), *image);

  float(*imageOutput)[2 + HEIGHT][2 + WIDTH];
  imageOutput = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));

  float(*Ix)[2 + HEIGHT][2 + WIDTH];
  float(*Iy)[2 + HEIGHT][2 + WIDTH];
  float(*Ixx)[2 + HEIGHT][2 + WIDTH];
  float(*Ixy)[2 + HEIGHT][2 + WIDTH];
  float(*Iyy)[2 + HEIGHT][2 + WIDTH];
  float(*Sxx)[2 + HEIGHT][2 + WIDTH];
  float(*Sxy)[2 + HEIGHT][2 + WIDTH];
  float(*Syy)[2 + HEIGHT][2 + WIDTH];
  float(*det)[2 + HEIGHT][2 + WIDTH];
  float(*trace)[2 + HEIGHT][2 + WIDTH];

  Ix = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Iy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Ixx = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Ixy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Iyy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Sxx = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Sxy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  Syy = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  det = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));
  trace = (float(*)[2 + HEIGHT][2 + WIDTH])
      malloc(sizeof(float) * (2 + HEIGHT) * (2 + WIDTH));

  harrisKernel(HEIGHT, WIDTH, *image, *imageOutput, *Ix, *Iy, *Ixx, *Ixy, *Iyy,
               *Sxx, *Sxy, *Syy, *det, *trace);

  free((void *)Ix);
  free((void *)Iy);
  free((void *)Ixx);
  free((void *)Ixy);
  free((void *)Iyy);
  free((void *)Sxx);
  free((void *)Sxy);
  free((void *)Syy);
  free((void *)det);
  free((void *)trace);

  if (argc == 2) {
    printImage(HEIGHT + 2, WIDTH + 2, *imageOutput, sum);
  } else {
    printImage(HEIGHT + 2, WIDTH + 2, *imageOutput, -1);
  }

  free((void *)image);
  free((void *)imageOutput);
  return 0;
}
