#include "glibc_compat_rand.h"
#include "pathfinder.h"
#include <stdio.h>
#include <stdlib.h>

void pathFinderKernel(int rows, int cols, int *data, int *result, int *src);
void initialize(int rows, int cols, int *result, int *data);
void printResult(int len, int *result);

int main() {

  int *data = (int *)malloc(sizeof(int) * ROWS * COLS);
  int *result = (int *)malloc(sizeof(int) * COLS);
  int *src = (int *)malloc(sizeof(int) * COLS);

  initialize(ROWS, COLS, result, data);

  pathFinderKernel(ROWS, COLS, data, result, src);

  printResult(COLS, result);

  return 0;
}

void initialize(int rows, int cols, int *result, int *data) {
  glibc_compat_srand(SEED);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      data[i * cols + j] = glibc_compat_rand() % 10;
    }
  }
  for (int j = 0; j < COLS; j++) {
    result[j] = data[j];
  }
}

void printResult(int len, int *result) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", result[i]);
  }
}
