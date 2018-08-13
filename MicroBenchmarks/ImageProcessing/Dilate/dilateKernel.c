/**
  Source:
  https://github.com/mompes/CUDA-dilation-and-erosion-filters/blob/master/erosionCPU.cpp
  Modified by Pankaj Kukreja (github.com/proton0001)
  Indian Institute of Technology Hyderabad
*/
#include "dilate.h"
#define MAX(a, b) (a > b) ? a : b;

void dilateKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                  int outputImage[height][width], int temp[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = 0;
      for (int k = -1; k <= 1; k++) {
        if ((j + k) > 0 && (j + k) < width) {
          value = MAX(inputImage[i][j + k], value);
        }
      }
      temp[i][j] = value;
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = 0;
      for (int k = -1; k <= 1; k++) {
        if ((i + k) > 0 && (i + k) < height) {
          value = MAX(temp[i + k][j], value);
        }
      }
      outputImage[i][j] = value;
    }
  }
}
