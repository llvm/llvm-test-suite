/**
  Source: github -> https://github.com/brianwu02/ImageProcessing.git
  Modified by Pankaj Kukreja (github.com/proton0001)
  Indian Institute of Technology Hyderabad
*/
#include "dither.h"
#include <math.h> // pow

#define GAMMA 0.5

void orderedDitherKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                         int outputImage[height][width],
                         int temp[height][width], int n, int m) {
  int scale;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      temp[i][j] =
          (int)(pow((double)inputImage[i][j] / 255.0, (1.0 / GAMMA)) * 255.0);
    }
  }

  scale = 256 / n;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      outputImage[i][j] = (int)(scale * (temp[i][j] / scale)) / scale;
    }
  }

  if (m == 2) {
    int dither[2][2] = {{0, 2}, {3, 1}};
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        int i = x % m;
        int j = y % m;
        outputImage[y][x] = ((outputImage[y][x] > dither[i][j]) ? 255 : 0);
      }
    }
  } else if (m == 3) {
    int dither[3][3] = {{6, 8, 4}, {1, 0, 3}, {5, 2, 7}};
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        int i = x % m;
        int j = y % m;
        outputImage[y][x] = ((outputImage[y][x] > dither[i][j]) ? 255 : 0);
      }
    }
  } else if (m == 4) {
    int dither[4][4] = {
        {0, 8, 2, 10}, {12, 4, 14, 6}, {3, 11, 1, 9}, {15, 7, 13, 5}};
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        int i = x % m;
        int j = y % m;
        outputImage[y][x] = ((outputImage[y][x] > dither[i][j]) ? 255 : 0);
      }
    }
  } else if (m == 8) {
    int dither[8][8] = {
        {0, 48, 12, 60, 3, 51, 15, 63}, {32, 16, 44, 28, 35, 19, 47, 31},
        {8, 56, 4, 52, 11, 59, 7, 55},  {40, 24, 36, 20, 43, 27, 39, 23},
        {2, 50, 14, 62, 1, 49, 13, 61}, {34, 18, 46, 30, 33, 17, 45, 29},
        {10, 58, 6, 54, 9, 57, 5, 53},  {42, 26, 38, 22, 41, 25, 37, 21}};
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        int i = x % m;
        int j = y % m;
        outputImage[y][x] = ((outputImage[y][x] > dither[i][j]) ? 255 : 0);
      }
    }
  }
}
