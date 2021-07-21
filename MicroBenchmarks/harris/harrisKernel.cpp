#include "harris.h"

// harris kernel from polymage_naive.cpp
void harrisKernel(int height, int width, float inputImg[4 + HEIGHT][4 + WIDTH],
                  float outputImg[HEIGHT][WIDTH],
                  float Ix[2 + HEIGHT][2 + WIDTH],
                  float Iy[2 + HEIGHT][2 + WIDTH],
                  float Ixx[2 + HEIGHT][2 + WIDTH],
                  float Ixy[2 + HEIGHT][2 + WIDTH],
                  float Iyy[2 + HEIGHT][2 + WIDTH], float Sxx[HEIGHT][WIDTH],
                  float Sxy[HEIGHT][WIDTH], float Syy[HEIGHT][WIDTH],
                  float det[HEIGHT][WIDTH], float trace[HEIGHT][WIDTH]) {
  for (int _i0 = 0; _i0 < height + 2; _i0++) {
    for (int _i1 = 0; _i1 < width + 2; _i1++) {
      Iy[_i0][_i1] = inputImg[_i0][_i1] * -0.0833333333333f +
                     inputImg[_i0][_i1 + 2] * 0.0833333333333f +
                     inputImg[_i0 + 1][_i1] * -0.166666666667f +
                     inputImg[_i0 + 1][_i1 + 2] * 0.166666666667f +
                     inputImg[_i0 + 2][_i1] * -0.0833333333333f +
                     inputImg[_i0 + 2][_i1 + 2] * 0.0833333333333f;
    }
  }

  for (int _i0 = 0; _i0 < height + 2; _i0++) {
    for (int _i1 = 0; _i1 < width + 2; _i1++) {
      Ix[_i0][_i1] = inputImg[_i0][_i1] * -0.0833333333333f +
                     inputImg[_i0 + 2][_i1] * 0.0833333333333f +
                     inputImg[_i0][_i1 + 1] * -0.166666666667f +
                     inputImg[_i0 + 2][_i1 + 1] * 0.166666666667f +
                     inputImg[_i0][_i1 + 2] * -0.0833333333333f +
                     inputImg[_i0 + 2][_i1 + 2] * 0.0833333333333f;
    }
  }

  for (int _i0 = 0; _i0 < height + 2; _i0++) {
    for (int _i1 = 0; _i1 < width + 2; _i1++) {
      Iyy[_i0][_i1] = Iy[_i0][_i1] * Iy[_i0][_i1];
    }
  }

  for (int _i0 = 0; _i0 < height + 2; _i0++) {
    for (int _i1 = 0; _i1 < width + 2; _i1++) {
      Ixy[_i0][_i1] = Ix[_i0][_i1] * Iy[_i0][_i1];
    }
  }

  for (int _i0 = 0; _i0 < height + 2; _i0++) {
    for (int _i1 = 0; _i1 < width + 2; _i1++) {
      Ixx[_i0][_i1] = Ix[_i0][_i1] * Ix[_i0][_i1];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      Syy[_i0][_i1] =
          Iyy[_i0 + 1][_i1] + Iyy[_i0][_i1 + 1] + Iyy[_i0][_i1 + 2] +
          Iyy[_i0 + 1][_i1] + Iyy[_i0 + 1][_i1 + 1] + Iyy[_i0 + 1][_i1 + 2] +
          Iyy[_i0 + 2][_i1] + Iyy[_i0 + 2][_i1 + 1] + Iyy[_i0 + 2][_i1 + 2];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      Sxy[_i0][_i1] = Ixy[_i0][_i1] + Ixy[_i0][_i1 + 1] + Ixy[_i0][_i1 + 2] +
                      Ixy[_i0 + 1][_i1] + Ixy[_i0 + 1][_i1 + 1] +
                      Ixy[_i0 + 1][_i1 + 2] + Ixy[_i0 + 2][_i1] +
                      Ixy[_i0 + 2][_i1 + 1] + Ixy[_i0 + 2][_i1 + 2];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      Sxx[_i0][_i1] = Ixx[_i0][_i1] + Ixx[_i0][_i1 + 1] + Ixx[_i0][_i1 + 2] +
                      Ixx[_i0 + 1][_i1] + Ixx[_i0 + 1][_i1 + 1] +
                      Ixx[_i0 + 1][_i1 + 2] + Ixx[_i0 + 2][_i1] +
                      Ixx[_i0 + 2][_i1 + 1] + Ixx[_i0 + 2][_i1 + 2];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      trace[_i0][_i1] = Sxx[_i0][_i1] + Syy[_i0][_i1];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      det[_i0][_i1] =
          Sxx[_i0][_i1] * Syy[_i0][_i1] - Sxy[_i0][_i1] * Sxy[_i0][_i1];
    }
  }

  for (int _i0 = 0; _i0 < height; _i0++) {
    for (int _i1 = 0; _i1 < width; _i1++) {
      outputImg[_i0][_i1] =
          det[_i0][_i1] - 0.04f * trace[_i0][_i1] * trace[_i0][_i1];
    }
  }
}
