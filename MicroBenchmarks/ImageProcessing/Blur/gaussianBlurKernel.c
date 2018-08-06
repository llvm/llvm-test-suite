/**
Gaussian Blur Kernel

Pankaj Kukreja
github.com/proton0001
Indian Institute of Technology Hyderabad
*/

#include "blur.h"
#include <math.h> // For M_PI and exp

void gaussianBlurKernel(int height, int width, int inputImage[height][width],
                        int outputImage[height][width]) {

  float sigma = 9;
  float s = 2.0 * sigma * sigma;
  int offset = (BOX_SIZE - 1) / 2;

  float sum = 0;
  float gaussianFilter[BOX_SIZE][BOX_SIZE] = {0};

  for (int x = -1 * offset; x <= offset; x++) {
    for (int y = -1 * offset; y <= offset; y++) {
      gaussianFilter[x + offset][y + offset] =
          (exp(-(x * x + y * y) / s)) / (M_PI * s);
      sum += gaussianFilter[x + offset][y + offset];
    }
  }

  float sum_in_current_frame = 0;
  for (int i = offset; i < height - offset; i++) {
    for (int j = offset; j < width - offset; j++) {
      /* Computing sum of (elements * corresponding gaussianFilter) in window
       * centered at i,j */
      sum_in_current_frame = 0;
      for (int k = -1 * offset; k <= offset; k++) {
        for (int l = -1 * offset; l <= offset; l++) {
          sum_in_current_frame += (inputImage[i + k][j + l] *
                                   gaussianFilter[k + offset][l + offset]);
        }
      }
      outputImage[i][j] = (sum_in_current_frame) / sum;
    }
  }
}
