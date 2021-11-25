#include "glibc_compat_rand.h"
#include "srad.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _AIX
#define AIX_RAND_MAX 2147483647
#endif
void random_matrix(float I[ROWS][COLS]);
void srad_kernel(float dN[ROWS][COLS], float dS[ROWS][COLS],
                 float dW[ROWS][COLS], float dE[ROWS][COLS],
                 float I[ROWS][COLS], float J[ROWS][COLS], float c[ROWS][COLS]);

int main(int argc, char *argv[]) {
  int size_I;

  float(*c)[ROWS][COLS];
  float(*dN)[ROWS][COLS];
  float(*dS)[ROWS][COLS];
  float(*dW)[ROWS][COLS];
  float(*dE)[ROWS][COLS];
  float(*I)[ROWS][COLS];
  float(*J)[ROWS][COLS];

  if ((ROWS % 16 != 0) || (COLS % 16 != 0)) {
    fprintf(stderr, "ROWS and COLS must be multiples of 16\n");
    exit(1);
  }

  size_I = COLS * ROWS;

  I = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  J = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  c = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  dN = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  dS = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  dW = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);
  dE = (float(*)[ROWS][COLS])malloc(sizeof(float) * size_I);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      (*J)[i][j] = 0;
      (*I)[i][j] = 0;
      (*c)[i][j] = 0;
      (*dN)[i][j] = 0;
      (*dS)[i][j] = 0;
      (*dW)[i][j] = 0;
      (*dE)[i][j] = 0;
    }
  }

  random_matrix(*I);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      (*J)[i][j] = (float)exp((*I)[i][j]);
    }
  }

  srad_kernel(*dN, *dS, *dW, *dE, *I, *J, *c);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if ((i * COLS + j) % GAP == 0) {
        printf("%.5f\n", (*J)[i][j]);
      }
    }
  }

  free((void *)I);
  free((void *)J);
  free((void *)dN);
  free((void *)dS);
  free((void *)dW);
  free((void *)dE);
  free((void *)c);
  return 0;
}

void random_matrix(float I[ROWS][COLS]) {

  glibc_compat_srand(SEED);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      #ifdef _AIX
      I[i][j] = glibc_compat_rand() / (float)AIX_RAND_MAX;
      #else
      I[i][j] = glibc_compat_rand() / (float)RAND_MAX;
      #endif
    }
  }
}
