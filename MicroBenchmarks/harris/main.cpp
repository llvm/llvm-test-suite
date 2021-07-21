#include "harris.h"
int sum = 0;

#ifdef BENCHMARK_LIB
#include "benchmark/benchmark.h"
#endif

// This function initializes the input image to checkbox image
void initCheckboardImage(int height, int width,
                         float image[4 + HEIGHT][4 + WIDTH]) {
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
void printImage(int height, int width, float arr[HEIGHT][WIDTH],
                int dummy) {
  std::ofstream myfile;
  myfile.open("output.txt");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
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

  float(*image)[HEIGHT + 4][WIDTH + 4];
  image = (float(*)[HEIGHT + 4][WIDTH + 4])
      malloc(sizeof(float) * (4 + HEIGHT) * (4 + WIDTH));
  initCheckboardImage(HEIGHT + 4, WIDTH + 4, *image);

  float(*imageOutput)[HEIGHT][WIDTH];
  imageOutput = (float(*)[HEIGHT][WIDTH])
      malloc(sizeof(float) * HEIGHT * WIDTH);

  float(*Ix)[2 + HEIGHT][2 + WIDTH];
  float(*Iy)[2 + HEIGHT][2 + WIDTH];
  float(*Ixx)[2 + HEIGHT][2 + WIDTH];
  float(*Ixy)[2 + HEIGHT][2 + WIDTH];
  float(*Iyy)[2 + HEIGHT][2 + WIDTH];
  float(*Sxx)[HEIGHT][WIDTH];
  float(*Sxy)[HEIGHT][WIDTH];
  float(*Syy)[HEIGHT][WIDTH];
  float(*det)[HEIGHT][WIDTH];
  float(*trace)[HEIGHT][WIDTH];

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
  Sxx = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  Sxy = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  Syy = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  det = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  trace = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);

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

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      sum = (sum + 1) & (int)(*imageOutput)[i][j];
    }
  }

  state.SetBytesProcessed(sizeof(float) * height * width * state.iterations());

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
  float(*image)[HEIGHT + 4][WIDTH + 4];
  image = (float(*)[HEIGHT + 4][WIDTH + 4])
      malloc(sizeof(float) * (HEIGHT + 4) * (WIDTH + 4));
  initCheckboardImage(HEIGHT + 4, WIDTH + 4, *image);

  float(*imageOutput)[HEIGHT][WIDTH];
  imageOutput = (float(*)[HEIGHT][WIDTH])
      malloc(sizeof(float) * HEIGHT * WIDTH);

  float(*Ix)[2 + HEIGHT][2 + WIDTH];
  float(*Iy)[2 + HEIGHT][2 + WIDTH];
  float(*Ixx)[2 + HEIGHT][2 + WIDTH];
  float(*Ixy)[2 + HEIGHT][2 + WIDTH];
  float(*Iyy)[2 + HEIGHT][2 + WIDTH];
  float(*Sxx)[HEIGHT][WIDTH];
  float(*Sxy)[HEIGHT][WIDTH];
  float(*Syy)[HEIGHT][WIDTH];
  float(*det)[HEIGHT][WIDTH];
  float(*trace)[HEIGHT][WIDTH];

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
  Sxx = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  Sxy = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  Syy = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  det = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);
  trace = (float(*)[HEIGHT][WIDTH])malloc(sizeof(float) * HEIGHT * WIDTH);

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
    printImage(HEIGHT, WIDTH, *imageOutput, sum);
  } else {
    printImage(HEIGHT, WIDTH, *imageOutput, -1);
  }

  free((void *)image);
  free((void *)imageOutput);
  return 0;
}
