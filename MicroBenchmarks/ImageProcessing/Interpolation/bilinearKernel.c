/**
  Source: github ->
  https://github.com/yglukhov/bicubic-interpolation-image-processing/blob/master/libimage.c

  Modifications by
  Pankaj Kukreja (github.com/proton0001)
  Indian Institute of Technology Hyderabad
*/
#include "interpolation.h"

void bilinearKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                    int outputImage[ZOOM * height][ZOOM * width]) {
  int x, y;

  float x_diff, y_diff;
  int i, j;

  int newheight = ZOOM * height;
  int newwidth = ZOOM * width;

  for (i = 0; i < newheight; i++) {
    for (j = 0; j < newwidth; j++) {
      x = j / ZOOM;
      y = i / ZOOM;

      x_diff = ((j / (float)ZOOM) - x);
      y_diff = ((i / (float)ZOOM) - y);
      if ((x + 1) < width && (y + 1) < height) {
        outputImage[i][j] = inputImage[y][x] * (1 - x_diff) * (1 - y_diff) +
                            inputImage[y][x + 1] * (1 - y_diff) * (x_diff) +
                            inputImage[y + 1][x] * (y_diff) * (1 - x_diff) +
                            inputImage[y + 1][x + 1] * (y_diff) * (x_diff);
      } else if ((x + 1) < width) {
        outputImage[i][j] = inputImage[y][x] * (1 - x_diff) * (1 - y_diff) +
                            inputImage[y][x + 1] * (1 - y_diff) * (x_diff);
      } else {
        outputImage[i][j] = inputImage[y][x] * (1 - x_diff) * (1 - y_diff);
      }
    }
  }
}
