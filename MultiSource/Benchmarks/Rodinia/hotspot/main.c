#include "hotspot.h"
#include <glibc_compat_rand.h>
#include <stdio.h>
#include <stdlib.h>

/* instead of printing all the values, we only print a part of array (every
 100th value) */
#define PRINT_GAP 100

/* chip parameters  */
double t_chip = 0.0005;
double chip_height = 0.016;
double chip_width = 0.016;
double amb_temp = 80.0;

void hotspotKernel(double result[grid_rows][grid_cols],
                   double temp[grid_rows][grid_cols],
                   double power[grid_rows][grid_cols], double Cap, double Rx,
                   double Ry, double Rz, double step, double ambTemp);

/* Transient solver driver routine: simply converts the heat
 * transfer differential equations to difference equations
 * and solves the difference equations by iterating
 */
void compute_tran_temp(double result[grid_rows][grid_cols],
                       double temp[grid_rows][grid_cols],
                       double power[grid_rows][grid_cols]) {

  double grid_height = chip_height / grid_rows;
  double grid_width = chip_width / grid_cols;

  double Cap = FACTOR_CHIP * SPEC_HEAT_SI * t_chip * grid_width * grid_height;
  double Rx = grid_width / (2.0 * K_SI * t_chip * grid_height);
  double Ry = grid_height / (2.0 * K_SI * t_chip * grid_width);
  double Rz = t_chip / (K_SI * grid_height * grid_width);

  double max_slope = MAX_PD / (FACTOR_CHIP * t_chip * SPEC_HEAT_SI);
  double step = PRECISION / max_slope;

  hotspotKernel(result, temp, power, Cap, Rx, Ry, Rz, step, amb_temp);
}

int main(int argc, char **argv) {

  /* allocate memory for the temperature and power array */
  double(*temp)[grid_rows][grid_cols] =
      malloc(grid_rows * grid_cols * sizeof(double));
  double(*power)[grid_rows][grid_cols] =
      malloc(grid_rows * grid_cols * sizeof(double));
  double(*result)[grid_rows][grid_cols] =
      malloc(grid_rows * grid_cols * sizeof(double));

  if (!temp || !power || !result)
    fprintf(stderr, "Unable to allocate memory");

  glibc_compat_srand(SEED);

  /* read initial temperatures and input power	*/
  for (int i = 0; i < grid_rows; i++) {
    double x = ((glibc_compat_rand()) % 512);
    double y = ((glibc_compat_rand()) % 128) * 1e-6;
    for (int j = 0; j < grid_cols; j++) {
      (*temp)[i][j] = x + ((glibc_compat_rand()) % 128) * 1e-3;
      (*power)[i][j] = y;
      (*result)[i][j] = 0.0;
    }
  }

  compute_tran_temp(*result, *temp, *power);

  /* output results	*/
  for (int i = 0; i < grid_rows; i++) {
    for (int j = 0; j < grid_cols; j++) {
      if ((i * grid_cols + j) % PRINT_GAP == 0) {
        fprintf(stdout, "%g\n", (*result)[i][j]);
      }
    }
  }

  free(temp);
  free(power);
  return 0;
}
