/**
Blur an Image using box blur

Pankaj Kukreja
Indian Institute of Technology Hyderabad
*/

#include "blur.h"
void boxBlurKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                   int outputImage[height][width]) {
  int sum = 0;
  int offset = (BOX_SIZE - 1) / 2;
  int n = BOX_SIZE * BOX_SIZE;

  for (int i = offset; i < height - offset; i++) {
    for (int j = offset; j < width - offset; j++) {
      sum = 0;
      for (int k = -1 * offset; k < offset; k++) {
        for (int l = -1 * offset; l < offset; l++) {
          sum += inputImage[i + k][j + l];
        }
      }
      outputImage[i][j] = (sum) / (n);
    }
  }
}