/*
  Source:
  https://cboard.cprogramming.com/c-programming/164080-anisotropic-diffusion-implementation-c.html
  Modified by Pankaj Kukreja (github.com/proton0001)
  Indian Institute of Technology Hyderabad
*/
#include "diffusion.h"
#include <math.h>

#define TIME_STEP (1.0 / 8)
#define DIFFUSION_CONST 0.5
void anisotropicDiffusionKernel(int height, int width,
                                int inputImage[HEIGHT][WIDTH],
                                int outputImage[height][width],
                                int no_iteration) {
  int i, j, k;
  for (k = 0; k < no_iteration; k++) {
    for (i = 2; i < height - 2; i++) {
      for (j = 2; j < width - 2; j++) {
        int gradient_x, gradient_y, grad_final;
        float result;
        float ne, nw, nn, ns;
        gradient_x = inputImage[i][j + 2] - inputImage[i][j];
        gradient_y = inputImage[i + 1][j + 1] - inputImage[i - 1][j + 1];
        grad_final = gradient_x + gradient_y;
        ne = exp(-(grad_final * grad_final) / DIFFUSION_CONST *
                 DIFFUSION_CONST) *
             (inputImage[i][j + 1] - inputImage[i][j]);

        gradient_x = inputImage[i][j] - inputImage[i][j - 2];
        gradient_y = inputImage[i + 1][j - 1] - inputImage[i - 1][j - 1];
        grad_final = gradient_x + gradient_y;
        nw = exp(-(grad_final * grad_final) / DIFFUSION_CONST *
                 DIFFUSION_CONST) *
             (inputImage[i][j - 1] - inputImage[i][j]);

        gradient_x = inputImage[i - 1][j + 1] - inputImage[i - 1][j - 1];
        gradient_y = inputImage[i][j] - inputImage[i - 2][j];
        grad_final = gradient_x + gradient_y;
        nn = exp(-(grad_final * grad_final) / DIFFUSION_CONST *
                 DIFFUSION_CONST) *
             (inputImage[i - 1][j] - inputImage[i][j]);

        gradient_x = inputImage[i + 1][j + 1] - inputImage[i + 1][j - 1];
        gradient_y = inputImage[i + 2][j] - inputImage[i][j];
        grad_final = gradient_x + gradient_y;
        ns = exp(-(grad_final * grad_final) / DIFFUSION_CONST *
                 DIFFUSION_CONST) *
             (inputImage[i + 1][j] - inputImage[i][j]);

        outputImage[i][j] = inputImage[i][j] + TIME_STEP * (ne + nw + nn + ns);
      }
    }
  }
}
