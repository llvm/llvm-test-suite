#ifndef _SRAD_H_
#define _SRAD_H_

#define GAP 200

#define ROWS 2048
#define COLS 1024

#define Y1 0
#define Y2 127

#define X1 0
#define X2 127

#define LAMDBA 0.5
#define ITER 10
#define SEED 7

void random_matrix(float I[ROWS][COLS]);
void srad_kernel(float dN[ROWS][COLS], float dS[ROWS][COLS],
                 float dW[ROWS][COLS], float dE[ROWS][COLS],
                 float I[ROWS][COLS], float J[ROWS][COLS], float c[ROWS][COLS]);

#endif
