/*
 ******************************************************************
 * HISTORY
 * 15-Oct-94  Jeff Shufelt (js), Carnegie Mellon University
 * Prepared for 15-681, Fall 1994.
 * Modified by Shuai Che
 * 28-May-2018: Modified by Pankaj Kukreja,
 * Indian Institute of Technology Hyderabad, India
 ******************************************************************
 */
#include "backprop.h"
#include <math.h>
#include <stdio.h>

float bpnn_train_kernel(
    int in, int hid, int out, float input_units[static const restrict in + 1],
    float hidden_units[static const restrict hid + 1],
    float output_units[static const restrict out + 1],
    float hidden_delta[static const restrict hid + 1],
    float output_delta[static const restrict out + 1],
    float target[static const restrict out + 1],
    float input_weights[static const restrict in + 1][1 + hid],
    float hidden_weights[static const restrict hid + 1][out + 1],
    float input_prev_weights[static const restrict in + 1][hid + 1],
    float hidden_prev_weights[static const restrict hid + 1][out + 1],
    int iterations) {

  float output_error = 0.0;

  for (int iteration = 0; iteration < iterations; iteration++) {
    double sum;
    int j, k;

    input_units[0] = 1.0;
    for (j = 1; j <= hid; j++) {
      sum = 0.0;
      for (k = 0; k <= in; k++) {
        sum += input_weights[k][j] * input_units[k];
      }
      hidden_units[j] = (1.0 / (1.0 + exp(-1 * sum)));
    }

    hidden_units[0] = 1.0;
    for (j = 1; j <= out; j++) {
      sum = 0.0;
      for (k = 0; k <= hid; k++) {
        sum += hidden_weights[k][j] * hidden_units[k];
      }
      output_units[j] = (1.0 / (1.0 + exp(-sum)));
    }

    float o, t;
    output_error = 0.0;
    for (j = 1; j <= out; j++) {
      o = output_units[j];
      t = target[j];
      output_delta[j] = o * (1.0 - o) * (t - o);
      output_error += fabs(output_delta[j]);
    }

    float new_dw;
    hidden_units[0] = 1.0;
    for (j = 1; j <= out; j++) {
      for (k = 0; k <= hid; k++) {
        new_dw = ((ETA * output_delta[j] * hidden_units[k]) +
                  (MOMENTUM * hidden_prev_weights[k][j]));
        hidden_weights[k][j] += new_dw;
        hidden_prev_weights[k][j] = new_dw;
      }
    }

    input_units[0] = 1.0;
    for (j = 1; j <= hid; j++) {
      for (k = 0; k <= in; k++) {
        new_dw = ((ETA * hidden_delta[j] * input_units[k]) +
                  (MOMENTUM * input_prev_weights[k][j]));
        input_weights[k][j] += new_dw;
        input_prev_weights[k][j] = new_dw;
      }
    }
  }
  return (output_error);
  printf("%f\n", output_error);
}
