#include "backprop.h"
#include "glibc_compat_rand.h"
#include <limits.h> // INT_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // malloc, free
float bpnn_train_kernel(int in, int hid, int out, float *input_units,
                        float *hidden_units, float *output_units,
                        float *hidden_delta, float *output_delta, float *target,
                        float *input_weights, float *hidden_weights,
                        float *input_prev_weights, float *hidden_prev_weights,
                        int iterations);

void bpnn_dump(int in, int hid, int out, float *input_weights,
               float *hidden_weights, float error);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////

int main() {
  glibc_compat_srand(SEED);
  float *input_weights =
      malloc(sizeof(float) * (1 + LAYERSIZE) * (1 + HIDDEN_SIZE));
  float *input_prev_weights =
      malloc(sizeof(float) * (1 + LAYERSIZE) * (1 + HIDDEN_SIZE));
  float *hidden_weights =
      malloc(sizeof(float) * (1 + HIDDEN_SIZE) * (1 + OUTPUT_SIZE));
  float *hidden_prev_weights =
      malloc(sizeof(float) * (1 + HIDDEN_SIZE) * (1 + OUTPUT_SIZE));
  float *input_units = malloc(sizeof(float) * (LAYERSIZE + 1));
  float *hidden_units = malloc(sizeof(float) * (HIDDEN_SIZE + 1));
  float *hidden_delta = malloc(sizeof(float) * (HIDDEN_SIZE + 1));
  float *output_units = malloc(sizeof(float) * (OUTPUT_SIZE + 1));
  float *output_delta = malloc(sizeof(float) * (OUTPUT_SIZE + 1));
  float *target = malloc(sizeof(float) * (OUTPUT_SIZE + 1));

  // Initializing input and hidden weights to random
  int i, j;
  for (i = 0; i <= LAYERSIZE; i++) {
    for (j = 0; j <= HIDDEN_SIZE; j++) {
      input_weights[i * (1 + HIDDEN_SIZE) + j] =
          (float)glibc_compat_rand() / INT_MAX;
    }
  }

  for (i = 0; i <= HIDDEN_SIZE; i++) {
    for (j = 0; j <= OUTPUT_SIZE; j++) {
      hidden_weights[i * (1 + OUTPUT_SIZE) + j] =
          (float)glibc_compat_rand() / INT_MAX;
    }
  }

  for (i = 0; i <= LAYERSIZE; i++) {
    for (j = 0; j <= HIDDEN_SIZE; j++) {
      input_prev_weights[i * (1 + HIDDEN_SIZE) + j] = 0.0;
    }
  }

  for (i = 0; i <= HIDDEN_SIZE; i++) {
    for (j = 0; j <= OUTPUT_SIZE; j++) {
      hidden_prev_weights[i * (1 + OUTPUT_SIZE) + j] = 0.0;
    }
  }

  for (i = 0; i <= OUTPUT_SIZE; i++) {
    target[i] = 0.1;
    output_units[i] = 0.0;
    output_delta[i] = 0.0;
  }

  // Random input
  input_units[0] = 0;
  for (int i = 0; i <= LAYERSIZE; i++) {
    input_units[i] = (float)glibc_compat_rand() / INT_MAX;
  }

  for (i = 0; i <= HIDDEN_SIZE; i++) {
    hidden_units[i] = 0.0;
    hidden_delta[i] = 0.0;
  }

  float error = 0.0;
  // entering the training kernel
  error = bpnn_train_kernel(
      LAYERSIZE, HIDDEN_SIZE, OUTPUT_SIZE, input_units, hidden_units,
      output_units, hidden_delta, output_delta, target, input_weights,
      hidden_weights, input_prev_weights, hidden_prev_weights, ITERATIONS);

  bpnn_dump(LAYERSIZE, HIDDEN_SIZE, OUTPUT_SIZE, input_weights, hidden_weights,
            error);

  free(input_weights);
  free(hidden_weights);
  free(input_prev_weights);
  free(hidden_prev_weights);
  free(input_units);
  free(hidden_units);
  free(output_units);
  free(hidden_delta);
  free(output_delta);
  free(target);
  return 0;
}

void bpnn_dump(int in, int hid, int out, float *input_weights,
               float *hidden_weights, float error) {
  int i, j;

  fflush(stdout);
  for (i = 0; i <= in; i++) {
    for (j = 0; j <= hid; j++) {
      if ((i * (1 + hid) + j) % GAP == 0) {
        printf("%.6f\n", input_weights[i * (1 + hid) + j]);
      }
    }
  }
  for (i = 0; i <= hid; i++) {
    for (j = 0; j <= out; j++) {
      if ((i * (out + 1) + j) % GAP == 0) {
        printf("%.6f\n", hidden_weights[i * (1 + out) + j]);
      }
    }
  }
  printf("%f\n", error);
}
