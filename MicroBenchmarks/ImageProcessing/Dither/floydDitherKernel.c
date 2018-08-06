/**
  Source: https://imagej.net/Dithering
  Modified by Pankaj Kukreja (github.com/proton0001)
  Indian Institute of Technology Hyderabad
*/
#include "dither.h"
void floydDitherKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                       int outputImage[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      outputImage[i][j] = inputImage[i][j];
    }
  }

  int err;
  int a, b, c, d;

  for (int i = 1; i < height - 1; i++) {
    for (int j = 1; j < width - 1; j++) {
      if (outputImage[i][j] > 127) {
        err = outputImage[i][j] - 255;
        outputImage[i][j] = 255;
      } else {
        err = outputImage[i][j] - 0;
        outputImage[i][j] = 0;
      }
      a = (err * 7) / 16;
      b = (err * 1) / 16;
      c = (err * 5) / 16;
      d = (err * 3) / 16;

      int temp1 = (outputImage[i][j + 1] + a);
      if (temp1 > 255) {
        outputImage[i][j + 1] = 255;
      } else if (temp1 < 0) {
        outputImage[i][j + 1] = 0;
      } else {
        outputImage[i][j + 1] = temp1;
      }

      int temp2 = (outputImage[i + 1][j + 1] + b);
      if (temp2 > 255) {
        outputImage[i + 1][j + 1] = 255;
      } else if (temp2 < 0) {
        outputImage[i + 1][j + 1] = 0;
      } else {
        outputImage[i + 1][j + 1] = temp2;
      }

      int temp3 = outputImage[i + 1][j + 0] + c;
      if (temp3 > 255) {
        outputImage[i + 1][j + 0] = 255;
      } else if (temp3 < 0) {
        outputImage[i + 1][j + 0] = 0;
      } else {
        outputImage[i + 1][j + 0] = temp3;
      }

      int temp4 = outputImage[i + 1][j - 1] + d;
      if (temp4 > 255) {
        outputImage[i + 1][j - 1] = 255;
      } else if (temp4 < 0) {
        outputImage[i + 1][j - 1] = 0;
      } else {
        outputImage[i + 1][j - 1] = temp4;
      }
    }
  }
}
