#include "srad.h"
void srad_kernel(float dN[ROWS][COLS], float dS[ROWS][COLS],
                 float dW[ROWS][COLS], float dE[ROWS][COLS],
                 float I[ROWS][COLS], float J[ROWS][COLS],
                 float c[ROWS][COLS]) {
  int size_R, iter;
  float q0sqr, sum, sum2, tmp, meanROI, varROI;
  float Jc, G2, L, num, den, qsqr;
  float cN, cS, cW, cE;
  float D;
  int i, j;

  size_R = (Y2 - Y1 + 1) * (X2 - X1 + 1);

  for (iter = 0; iter < ITER; iter++) {
    sum = 0;
    sum2 = 0;
    for (i = Y1; i <= Y2; i++) {
      for (j = X1; j <= X2; j++) {
        tmp = J[i][j];
        sum += tmp;
        sum2 += tmp * tmp;
      }
    }
    meanROI = sum / size_R;
    varROI = (sum2 / size_R) - meanROI * meanROI;
    q0sqr = varROI / (meanROI * meanROI);

    {
      int i = 0;
      int j = 0;
      Jc = J[i][j];

      // directional derivates
      dN[i][j] = J[0][j] - Jc;
      dS[i][j] = J[1][j] - Jc;
      dW[i][j] = J[i][0] - Jc;
      dE[i][j] = J[i][1] - Jc;

      G2 = (dN[i][j] * dN[i][j] + dS[i][j] * dS[i][j] + dW[i][j] * dW[i][j] +
            dE[i][j] * dE[i][j]) /
           (Jc * Jc);

      L = (dN[i][j] + dS[i][j] + dW[i][j] + dE[i][j]) / Jc;

      num = (0.5 * G2) - ((1.0 / 16.0) * (L * L));
      den = 1 + (.25 * L);
      qsqr = num / (den * den);

      // diffusion coefficent (equ 33)
      den = (qsqr - q0sqr) / (q0sqr * (1 + q0sqr));
      c[i][j] = 1.0 / (1.0 + den);

      // saturate diffusion coefficent
      if (c[i][j] < 0) {
        c[i][j] = 0;
      } else if (c[i][j] > 1) {
        c[i][j] = 1;
      }

      j = COLS - 1;

      Jc = J[i][j];
      // directional derivates
      dN[i][j] = J[0][j] - Jc;
      dS[i][j] = J[1][j] - Jc;
      dW[i][j] = J[i][COLS - 2] - Jc;
      dE[i][j] = J[i][COLS - 1] - Jc;

      G2 = (dN[i][j] * dN[i][j] + dS[i][j] * dS[i][j] + dW[i][j] * dW[i][j] +
            dE[i][j] * dE[i][j]) /
           (Jc * Jc);

      L = (dN[i][j] + dS[i][j] + dW[i][j] + dE[i][j]) / Jc;

      num = (0.5 * G2) - ((1.0 / 16.0) * (L * L));
      den = 1 + (.25 * L);
      qsqr = num / (den * den);

      // diffusion coefficent (equ 33)
      den = (qsqr - q0sqr) / (q0sqr * (1 + q0sqr));
      c[i][j] = 1.0 / (1.0 + den);

      // saturate diffusion coefficent
      if (c[i][j] < 0) {
        c[i][j] = 0;
      } else if (c[i][j] > 1) {
        c[i][j] = 1;
      }
    }
    {
      int i = ROWS - 1;
      int j = 0;
      Jc = J[i][j];

      // directional derivates
      dN[i][j] = J[ROWS - 2][j] - Jc;
      dS[i][j] = J[ROWS - 1][j] - Jc;
      dW[i][j] = J[i][0] - Jc;
      dE[i][j] = J[i][1] - Jc;

      G2 = (dN[i][j] * dN[i][j] + dS[i][j] * dS[i][j] + dW[i][j] * dW[i][j] +
            dE[i][j] * dE[i][j]) /
           (Jc * Jc);

      L = (dN[i][j] + dS[i][j] + dW[i][j] + dE[i][j]) / Jc;

      num = (0.5 * G2) - ((1.0 / 16.0) * (L * L));
      den = 1 + (.25 * L);
      qsqr = num / (den * den);

      // diffusion coefficent (equ 33)
      den = (qsqr - q0sqr) / (q0sqr * (1 + q0sqr));
      c[i][j] = 1.0 / (1.0 + den);

      // saturate diffusion coefficent
      if (c[i][j] < 0) {
        c[i][j] = 0;
      } else if (c[i][j] > 1) {
        c[i][j] = 1;
      }

      j = COLS - 1;

      Jc = J[i][j];
      // directional derivates
      dN[i][j] = J[ROWS - 2][j] - Jc;
      dS[i][j] = J[ROWS - 1][j] - Jc;
      dW[i][j] = J[i][COLS - 2] - Jc;
      dE[i][j] = J[i][COLS - 1] - Jc;

      G2 = (dN[i][j] * dN[i][j] + dS[i][j] * dS[i][j] + dW[i][j] * dW[i][j] +
            dE[i][j] * dE[i][j]) /
           (Jc * Jc);

      L = (dN[i][j] + dS[i][j] + dW[i][j] + dE[i][j]) / Jc;

      num = (0.5 * G2) - ((1.0 / 16.0) * (L * L));
      den = 1 + (.25 * L);
      qsqr = num / (den * den);

      // diffusion coefficent (equ 33)
      den = (qsqr - q0sqr) / (q0sqr * (1 + q0sqr));
      c[i][j] = 1.0 / (1.0 + den);

      // saturate diffusion coefficent
      if (c[i][j] < 0) {
        c[i][j] = 0;
      } else if (c[i][j] > 1) {
        c[i][j] = 1;
      }
    }

    for (int i = 1; i < ROWS - 1; i++) {
      for (int j = 1; j < COLS - 1; j++) {

        Jc = J[i][j];

        // directional derivates
        dN[i][j] = J[i - 1][j] - Jc;
        dS[i][j] = J[i + 1][j] - Jc;
        dW[i][j] = J[i][j - 1] - Jc;
        dE[i][j] = J[i][j + 1] - Jc;

        G2 = (dN[i][j] * dN[i][j] + dS[i][j] * dS[i][j] + dW[i][j] * dW[i][j] +
              dE[i][j] * dE[i][j]) /
             (Jc * Jc);

        L = (dN[i][j] + dS[i][j] + dW[i][j] + dE[i][j]) / Jc;

        num = (0.5 * G2) - ((1.0 / 16.0) * (L * L));
        den = 1 + (.25 * L);
        qsqr = num / (den * den);

        // diffusion coefficent (equ 33)
        den = (qsqr - q0sqr) / (q0sqr * (1 + q0sqr));
        c[i][j] = 1.0 / (1.0 + den);

        // saturate diffusion coefficent
        if (c[i][j] < 0) {
          c[i][j] = 0;
        } else if (c[i][j] > 1) {
          c[i][j] = 1;
        }
      }
    }

    {
      int i = ROWS - 1;
      for (int j = 0; j < COLS - 1; j++) {
        // diffusion coefficent
        cN = c[i][j];
        cS = c[i][j];
        cW = c[i][j];
        cE = c[i][j + 1];

        // divergence (equ 58)
        D = cN * dN[i][j] + cS * dS[i][j] + cW * dW[i][j] + cE * dE[i][j];

        // image update (equ 61)
        J[i][j] = J[i][j] + 0.25 * LAMDBA * D;
      }
      i = ROWS - 1;
      int j = COLS - 1;

      // diffusion coefficent
      cN = c[i][j];
      cS = c[i][j];
      cW = c[i][j];
      cE = c[i][j];

      // divergence (equ 58)
      D = cN * dN[i][j] + cS * dS[i][j] + cW * dW[i][j] + cE * dE[i][j];

      // image update (equ 61)
      J[i][j] = J[i][j] + 0.25 * LAMDBA * D;
    }

    for (int i = 0; i < ROWS - 1; i++) {
      for (int j = 0; j < COLS - 1; j++) {
        // diffusion coefficent
        cN = c[i][j];
        cS = c[i + 1][j];
        cW = c[i][j];
        cE = c[i][j + 1];

        // divergence (equ 58)
        D = cN * dN[i][j] + cS * dS[i][j] + cW * dW[i][j] + cE * dE[i][j];

        // image update (equ 61)
        J[i][j] = J[i][j] + 0.25 * LAMDBA * D;
      }
    }
  }
}