/**
 * atax.c: This file is part of the PolyBench/C 3.2 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
/* Default data type is double, default size is 4000. */
#include "atax.h"


/* Array initialization. */
static
void init_array (int nx, int ny,
		 DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
		 DATA_TYPE POLYBENCH_1D(x,NY,ny))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < ny; i++)
      x[i] = i * M_PI;
  for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j++)
      A[i][j] = ((DATA_TYPE) i*(j+1)) / nx;
}

/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int nx,
		 DATA_TYPE POLYBENCH_1D(y,NX,nx))

{
  int i;
  char *printmat = malloc(nx*16 + 1); printmat[nx*16] = 0;

  for (i = 0; i < nx; i++)
    print_element(y[i], i*16, printmat);
  fputs(printmat, stderr);
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_atax(int nx, int ny,
		 DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
		 DATA_TYPE POLYBENCH_1D(x,NY,ny),
		 DATA_TYPE POLYBENCH_1D(y,NY,ny),
		 DATA_TYPE POLYBENCH_1D(tmp,NX,nx))
{
  int i, j;

#pragma scop
  for (i = 0; i < _PB_NY; i++)
    y[i] = 0;
  for (i = 0; i < _PB_NX; i++)
    {
      tmp[i] = 0;
      for (j = 0; j < _PB_NY; j++)
	tmp[i] = tmp[i] + A[i][j] * x[j];
      for (j = 0; j < _PB_NY; j++)
	y[j] = y[j] + A[i][j] * tmp[i];
    }
#pragma endscop

}

static void
kernel_atax_StrictFP(int nx, int ny,
                          DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
                          DATA_TYPE POLYBENCH_1D(x,NY,ny),
                          DATA_TYPE POLYBENCH_1D(y,NY,ny),
                          DATA_TYPE POLYBENCH_1D(tmp,NX,nx))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < _PB_NY; i++)
    y[i] = 0;
  for (i = 0; i < _PB_NX; i++)
    {
      tmp[i] = 0;
      for (j = 0; j < _PB_NY; j++)
	tmp[i] = tmp[i] + A[i][j] * x[j];
      for (j = 0; j < _PB_NY; j++)
	y[j] = y[j] + A[i][j] * tmp[i];
    }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static int
check_FP(int ny,
         DATA_TYPE POLYBENCH_1D(A,NY,ny),
         DATA_TYPE POLYBENCH_1D(B,NY,ny)) {
  int i;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_NY; i++)
    {
      double V1 = A[i];
      double V2 = B[i];
      double Diff = fabs(V1 - V2);
      if (Diff > AbsTolerance) {
        fprintf(stderr, "A[%d] = %lf and B[%d] = %lf differ more than"
                " FP_ABSTOLERANCE = %lf\n", i, V1, i, V2, AbsTolerance);
        return 0;
      }
    }

  return 1;
}

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int nx = NX;
  int ny = NY;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(A, DATA_TYPE, NX, NY, nx, ny);
  POLYBENCH_1D_ARRAY_DECL(x, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(y, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(y_StrictFP, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(tmp, DATA_TYPE, NX, nx);

  /* Initialize array(s). */
  init_array (nx, ny, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(x));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_atax (nx, ny,
	       POLYBENCH_ARRAY(A),
	       POLYBENCH_ARRAY(x),
	       POLYBENCH_ARRAY(y),
	       POLYBENCH_ARRAY(tmp));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  kernel_atax_StrictFP (nx, ny,
                        POLYBENCH_ARRAY(A),
                        POLYBENCH_ARRAY(x),
                        POLYBENCH_ARRAY(y_StrictFP),
                        POLYBENCH_ARRAY(tmp));
  if (!check_FP(ny, POLYBENCH_ARRAY(y), POLYBENCH_ARRAY(y_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(nx, POLYBENCH_ARRAY(y_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(x);
  POLYBENCH_FREE_ARRAY(y);
  POLYBENCH_FREE_ARRAY(y_StrictFP);
  POLYBENCH_FREE_ARRAY(tmp);

  return 0;
}
