#include "pathfinder.h"
#include <stdio.h>
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
void pathFinderKernel(int row, int col, int data[row][col], int result[col],
                      int src[col]) {
  for (int t = 0; t < row - 1; t++) {
    for (int n = 0; n < col; n++) {
      src[n] = result[n];
    }
    for (int n = 0; n < col; n++) {
      if (n == 0) {
        result[n] = data[t + 1][n] + MIN(src[n], src[n + 1]);
      } else if (n == col - 1) {
        result[n] = data[t + 1][n] + MIN(src[n], src[col - 2]);
      } else {
        result[n] = data[t + 1][n] + MIN(src[n], MIN(src[n - 1], src[n + 1]));
      }
    }
  }
}
