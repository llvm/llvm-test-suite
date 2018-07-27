#include "hotspot.h"

void hotspotKernel(double result[grid_rows][grid_cols],
                   double temp[grid_rows][grid_cols],
                   double power[grid_rows][grid_cols], double Cap, double Rx,
                   double Ry, double Rz, double step, double ambTemp) {
  for (int i = 0; i < num_iterations; i++) {
    double delta;
    int r, c;
    for (r = 1; r < grid_rows - 1; r++) {
      for (c = 1; c < grid_cols - 1; c++) {
        delta = (step / Cap) *
                (power[r][c] +
                 (temp[(r + 1)][c] + temp[(r - 1)][c] - 2.0 * temp[r][c]) / Ry +
                 (temp[r][c + 1] + temp[r][c - 1] - 2.0 * temp[r][c]) / Rx +
                 (ambTemp - temp[r][c]) / Rz);

        /*  Update Temperatures */
        result[r][c] = temp[r][c] + delta;
      }
    }

    /*  Corner 1  */
    delta = (step / Cap) *
            (power[0][0] + (temp[0][1] - temp[0][0]) / Rx +
             (temp[1][0] - temp[0][0]) / Ry + (ambTemp - temp[0][0]) / Rz);
    result[0][0] = temp[0][0] + delta;

    /*  Corner 2  */
    delta =
        (step / Cap) * (power[0][grid_cols - 1] +
                        (temp[0][c - 1] - temp[0][grid_cols - 1]) / Rx +
                        (temp[1][grid_cols - 1] - temp[0][grid_cols - 1]) / Ry +
                        (ambTemp - temp[0][grid_cols - 1]) / Rz);
    result[0][grid_cols - 1] = temp[0][grid_cols - 1] + delta;

    /*  Corner 3  */
    delta =
        (step / Cap) * (power[grid_rows - 1][grid_cols - 1] +
                        (temp[grid_rows - 1][grid_cols - 1 - 1] -
                         temp[grid_rows - 1][grid_cols - 1]) /
                            Rx +
                        (temp[(grid_rows - 2)][grid_cols - 1] -
                         temp[grid_rows - 1][grid_cols - 1]) /
                            Ry +
                        (ambTemp - temp[grid_rows - 1][grid_cols - 1]) / Rz);
    result[grid_rows - 1][grid_cols - 1] =
        temp[grid_rows - 1][grid_cols - 1] + delta;

    /*  Corner 4  */
    delta = (step / Cap) *
            (power[grid_rows - 1][0] +
             (temp[grid_rows - 1][1] - temp[grid_rows - 1][0]) / Rx +
             (temp[(grid_rows - 2)][0] - temp[grid_rows - 1][0]) / Ry +
             (ambTemp - temp[grid_rows - 1][0]) / Rz);
    result[grid_rows - 1][0] = temp[grid_rows - 1][0] + delta;

    // Top and Bottom Edge
    for (c = 1; c < grid_cols - 1; c++) {

      delta = (step / Cap) *
              (power[0][c] +
               (temp[0][c + 1] + temp[0][c - 1] - 2.0 * temp[0][c]) / Rx +
               (temp[1][c] - temp[0][c]) / Ry + (ambTemp - temp[0][c]) / Rz);
      result[0][c] = temp[0][c] + delta;

      delta = (step / Cap) *
              (power[grid_rows - 1][c] +
               (temp[grid_rows - 1][c + 1] + temp[grid_rows - 1][c - 1] -
                2.0 * temp[grid_rows - 1][c]) /
                   Rx +
               (temp[(grid_rows - 2)][c] - temp[grid_rows - 1][c]) / Ry +
               (ambTemp - temp[grid_rows - 1][c]) / Rz);
      result[grid_rows - 1][c] = temp[grid_rows - 1][c] + delta;
    }

    // Left and right Edge
    for (r = 1; r < grid_rows - 1; r++) {
      delta = (step / Cap) *
              (power[r][grid_cols - 1] +
               (temp[(r + 1)][grid_cols - 1] + temp[(r - 1)][grid_cols - 1] -
                2.0 * temp[r][grid_cols - 1]) /
                   Ry +
               (temp[r][grid_cols - 1 - 1] - temp[r][grid_cols - 1]) / Rx +
               (ambTemp - temp[r][grid_cols - 1]) / Rz);
      result[r][grid_cols - 1] = temp[r][grid_cols - 1] + delta;

      delta = (step / Cap) *
              (power[r][0] +
               (temp[(r + 1)][0] + temp[(r - 1)][0] - 2.0 * temp[r][0]) / Ry +
               (temp[r][1] - temp[r][0]) / Rx + (ambTemp - temp[r][0]) / Rz);
      result[r][0] = temp[r][0] + delta;
    }

    for (r = 0; r < grid_rows; r++) {
      for (c = 0; c < grid_cols; c++) {
        temp[r][c] = result[r][c];
      }
    }
  }
}
