/**
  Source: https://github.com/anlcnydn/bilateral
  Modified by
  Pankaj Kukreja
  Indian Institute of technology, Hyderabad
*/
#include "bilateralFiltering.h"
#include <math.h>

#define sigmaI 12.0
#define sigmaS 16.0

#define GAUSSIAN(x, sigma)                                                     \
  (exp(-(x * x) / (2 * sigma * sigma)) / (2 * M_PI * (sigma * sigma)))

void bilateralFilterKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                           int outputImage[height][width], int diameter) {
  int half = diameter / 2;
  for (int x = half; x < height - half; x++) {
    for (int y = half; y < width - half; y++) {
      double iFiltered = 0;
      double wP = 0;
      int neighbor_x = 0;
      int neighbor_y = 0;
      for (int i = 0; i < diameter; i++) {
        for (int j = 0; j < diameter; j++) {
          neighbor_x = x - (half - i);
          neighbor_y = y - (half - j);
          double gi = GAUSSIAN(
              inputImage[neighbor_x][neighbor_y] - inputImage[x][y], sigmaI);
          double gs =
              GAUSSIAN((float)(sqrt(((x - neighbor_x) * (x - neighbor_x)) +
                                    ((y - neighbor_y) * (y - neighbor_y)))),
                       sigmaS);
          double w = gi * gs;
          iFiltered = iFiltered + inputImage[neighbor_x][neighbor_y] * w;
          wP = wP + w;
        }
      }
      iFiltered = iFiltered / wP;
      outputImage[x][y] = iFiltered;
    }
  }
}