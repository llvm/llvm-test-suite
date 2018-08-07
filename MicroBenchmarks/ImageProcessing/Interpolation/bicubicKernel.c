/** This is a modified version of serial/bicubicInterpolation.cpp of
 * https://github.com/srijanmishra/parallel-bicubic-interpolation
 *
 * Modified by
 * Pankaj Kukreja (github.com/proton0001)
 * Indian Institute of Technology Hyderabad
 */
#include "interpolation.h"
void bicubicKernel(int height, int width, int inputImage[HEIGHT][WIDTH],
                   int outputImage[ZOOM * height][ZOOM * width]) {
  int f = ZOOM;
  int newheight = f * height;
  int newwidth = f * width;
  double arr[4][4];
  for (int i = 0; i < newheight - 3 * f; i++) {
    for (int j = 0; j < newwidth - 3 * f; j++) {
      // for row offset
      for (int l = 0; l < 4; l++) {
        // for column offset
        for (int k = 0; k < 4; k++) {
          arr[l][k] = inputImage[i / f + l][j / f + k];
        }
      }
      double x = (double)(i % f) / f;
      double y = (double)(j % f) / f;
      double arr2[4];
      arr2[0] = arr[0][1] + 0.5 * y *
                                (arr[0][2] - arr[0][0] +
                                 y * (2.0 * arr[0][0] - 5.0 * arr[0][1] +
                                      4.0 * arr[0][2] - arr[0][3] +
                                      y * (3.0 * (arr[0][1] - arr[0][2]) +
                                           arr[0][3] - arr[0][0])));
      arr2[1] = arr[1][1] + 0.5 * y *
                                (arr[1][2] - arr[1][0] +
                                 y * (2.0 * arr[1][0] - 5.0 * arr[1][1] +
                                      4.0 * arr[1][2] - arr[1][3] +
                                      y * (3.0 * (arr[1][1] - arr[1][2]) +
                                           arr[1][3] - arr[1][0])));
      arr2[2] = arr[2][1] + 0.5 * y *
                                (arr[2][2] - arr[2][0] +
                                 y * (2.0 * arr[2][0] - 5.0 * arr[2][1] +
                                      4.0 * arr[2][2] - arr[2][3] +
                                      y * (3.0 * (arr[2][1] - arr[2][2]) +
                                           arr[2][3] - arr[2][0])));
      arr2[3] = arr[3][1] + 0.5 * y *
                                (arr[3][2] - arr[3][0] +
                                 y * (2.0 * arr[3][0] - 5.0 * arr[3][1] +
                                      4.0 * arr[3][2] - arr[3][3] +
                                      y * (3.0 * (arr[3][1] - arr[3][2]) +
                                           arr[3][3] - arr[3][0])));
      outputImage[i][j] =
          arr2[1] +
          0.5 * x *
              (arr2[2] - arr2[0] +
               x * (2.0 * arr2[0] - 5.0 * arr2[1] + 4.0 * arr2[2] - arr2[3] +
                    x * (3.0 * (arr2[1] - arr2[2]) + arr2[3] - arr2[0])));
    }
  }
}
