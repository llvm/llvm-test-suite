/**
 * bicg.c: This file is part of the PolyBench/C 3.2 test suite.
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
#include "bicg.h"


/* Array initialization. */
static
void init_array (int nx, int ny,
		 DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
		 DATA_TYPE POLYBENCH_1D(r,NX,nx),
		 DATA_TYPE POLYBENCH_1D(p,NY,ny))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < ny; i++)
    p[i] = i * M_PI;
  for (i = 0; i < nx; i++) {
    r[i] = i * M_PI;
    for (j = 0; j < ny; j++)
      A[i][j] = ((DATA_TYPE) i*(j+1))/nx;
  }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int nx, int ny,
		 DATA_TYPE POLYBENCH_1D(s,NY,ny),
		 DATA_TYPE POLYBENCH_1D(q,NX,nx))

{
  int i;
  int n = nx > ny ? nx : ny;
  char *printmat = malloc(n*16 + 1); printmat[n*16] = 0;

  for (i = 0; i < ny; i++)
    print_element(s[i], i*16, printmat);
  *(printmat+i) = 0;
  fputs(printmat, stderr);
  for (i = 0; i < nx; i++)
    print_element(q[i], i*16, printmat);
  *(printmat+i) = 0;
  fputs(printmat, stderr);
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_bicg(int nx, int ny,
		 DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
		 DATA_TYPE POLYBENCH_1D(s,NY,ny),
		 DATA_TYPE POLYBENCH_1D(q,NX,nx),
		 DATA_TYPE POLYBENCH_1D(p,NY,ny),
		 DATA_TYPE POLYBENCH_1D(r,NX,nx))
{
  int i, j;

#pragma scop
  for (i = 0; i < _PB_NY; i++)
    s[i] = 0;
  for (i = 0; i < _PB_NX; i++)
    {
      q[i] = 0;
      for (j = 0; j < _PB_NY; j++)
	{
	  s[j] = s[j] + r[i] * A[i][j];
	  q[i] = q[i] + A[i][j] * p[j];
	}
    }
#pragma endscop

}

static
void kernel_bicg_StrictFP(int nx, int ny,
                          DATA_TYPE POLYBENCH_2D(A,NX,NY,nx,ny),
                          DATA_TYPE POLYBENCH_1D(s,NY,ny),
                          DATA_TYPE POLYBENCH_1D(q,NX,nx),
                          DATA_TYPE POLYBENCH_1D(p,NY,ny),
                          DATA_TYPE POLYBENCH_1D(r,NX,nx))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < _PB_NY; i++)
    s[i] = 0;
  for (i = 0; i < _PB_NX; i++)
    {
      q[i] = 0;
      for (j = 0; j < _PB_NY; j++)
	{
	  s[j] = s[j] + r[i] * A[i][j];
	  q[i] = q[i] + A[i][j] * p[j];
	}
    }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static int
check_FP(int ny,
         DATA_TYPE POLYBENCH_1D(A,NY,ny),
         DATA_TYPE POLYBENCH_1D(B,NX,nx)) {
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

  /* All elements are within the allowed FP_ABSTOLERANCE error margin.  */
  return 1;
}

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int nx = NX;
  int ny = NY;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(A, DATA_TYPE, NX, NY, nx, ny);
  POLYBENCH_1D_ARRAY_DECL(s, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(q, DATA_TYPE, NX, nx);
  POLYBENCH_1D_ARRAY_DECL(p, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(r, DATA_TYPE, NX, nx);
  POLYBENCH_1D_ARRAY_DECL(s_StrictFP, DATA_TYPE, NY, ny);
  POLYBENCH_1D_ARRAY_DECL(q_StrictFP, DATA_TYPE, NX, nx);

  /* Initialize array(s). */
  init_array (nx, ny,
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(r),
	      POLYBENCH_ARRAY(p));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_bicg (nx, ny,
	       POLYBENCH_ARRAY(A),
	       POLYBENCH_ARRAY(s),
	       POLYBENCH_ARRAY(q),
	       POLYBENCH_ARRAY(p),
	       POLYBENCH_ARRAY(r));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  kernel_bicg_StrictFP(nx, ny,
                       POLYBENCH_ARRAY(A),
                       POLYBENCH_ARRAY(s_StrictFP),
                       POLYBENCH_ARRAY(q_StrictFP),
                       POLYBENCH_ARRAY(p),
                       POLYBENCH_ARRAY(r));

  if (!check_FP(ny, POLYBENCH_ARRAY(s), POLYBENCH_ARRAY(s_StrictFP)))
    return 1;
  if (!check_FP(ny, POLYBENCH_ARRAY(q), POLYBENCH_ARRAY(q_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(nx, ny, POLYBENCH_ARRAY(s_StrictFP),
                                    POLYBENCH_ARRAY(q_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(s);
  POLYBENCH_FREE_ARRAY(q);
  POLYBENCH_FREE_ARRAY(p);
  POLYBENCH_FREE_ARRAY(r);
  POLYBENCH_FREE_ARRAY(s_StrictFP);
  POLYBENCH_FREE_ARRAY(q_StrictFP);

  return 0;
}
