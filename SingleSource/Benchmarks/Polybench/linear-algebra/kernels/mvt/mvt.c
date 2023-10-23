/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* mvt.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
/* Default data type is double, default size is 4000. */
#include "mvt.h"


/* Array initialization. */
static
void init_array(int n,
		DATA_TYPE POLYBENCH_1D(x1,N,n),
		DATA_TYPE POLYBENCH_1D(x2,N,n),
#if !FMA_DISABLED
		DATA_TYPE POLYBENCH_1D(x1_StrictFP,N,n),
		DATA_TYPE POLYBENCH_1D(x2_StrictFP,N,n),
#endif
		DATA_TYPE POLYBENCH_1D(y_1,N,n),
		DATA_TYPE POLYBENCH_1D(y_2,N,n),
		DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < n; i++)
    {
#if !FMA_DISABLED
      x1_StrictFP[i] =
#endif
	      x1[i] = (DATA_TYPE) (i % n) / n;
#if !FMA_DISABLED
      x2_StrictFP[i] =
#endif
	      x2[i] = (DATA_TYPE) ((i + 1) % n) / n;
      y_1[i] = (DATA_TYPE) ((i + 3) % n) / n;
      y_2[i] = (DATA_TYPE) ((i + 4) % n) / n;
      for (j = 0; j < n; j++)
	A[i][j] = (DATA_TYPE) (i*j % n) / n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 DATA_TYPE POLYBENCH_1D(x1,N,n),
		 DATA_TYPE POLYBENCH_1D(x2,N,n))

{
  int i;
  char *printmat = malloc(n*16 + 1); printmat[n*16] = 0;

  for (i = 0; i < n; i++)
    print_element(x1[i], i*16, printmat);
  fputs(printmat, stderr);
  for (i = 0; i < n; i++)
    print_element(x2[i], i*16, printmat);
  fputs(printmat, stderr);
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_mvt(int n,
		DATA_TYPE POLYBENCH_1D(x1,N,n),
		DATA_TYPE POLYBENCH_1D(x2,N,n),
		DATA_TYPE POLYBENCH_1D(y_1,N,n),
		DATA_TYPE POLYBENCH_1D(y_2,N,n),
		DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
  int i, j;

#pragma scop
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_N; j++)
      x1[i] = x1[i] + A[i][j] * y_1[j];
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_N; j++)
      x2[i] = x2[i] + A[j][i] * y_2[j];
#pragma endscop

}

#if !FMA_DISABLED
// NOTE: FMA_DISABLED is true for targets where FMA contraction causes
// discrepancies which cause the accuracy checks to fail.
// In this case, the test runs with the option -ffp-contract=off
static
void kernel_mvt_StrictFP(int n,
                         DATA_TYPE POLYBENCH_1D(x1,N,n),
                         DATA_TYPE POLYBENCH_1D(x2,N,n),
                         DATA_TYPE POLYBENCH_1D(y_1,N,n),
                         DATA_TYPE POLYBENCH_1D(y_2,N,n),
                         DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_N; j++)
      x1[i] = x1[i] + A[i][j] * y_1[j];
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_N; j++)
      x2[i] = x2[i] + A[j][i] * y_2[j];
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static int
check_FP(int n,
         DATA_TYPE POLYBENCH_1D(A,N,n),
         DATA_TYPE POLYBENCH_1D(B,N,n)) {
  int i;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_N; i++)
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
#endif

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(A, DATA_TYPE, N, N, n, n);
  POLYBENCH_1D_ARRAY_DECL(x1, DATA_TYPE, N, n);
  POLYBENCH_1D_ARRAY_DECL(x2, DATA_TYPE, N, n);
#if !FMA_DISABLED
  POLYBENCH_1D_ARRAY_DECL(x1_StrictFP, DATA_TYPE, N, n);
  POLYBENCH_1D_ARRAY_DECL(x2_StrictFP, DATA_TYPE, N, n);
#endif
  POLYBENCH_1D_ARRAY_DECL(y_1, DATA_TYPE, N, n);
  POLYBENCH_1D_ARRAY_DECL(y_2, DATA_TYPE, N, n);


  /* Initialize array(s). */
  init_array (n,
	      POLYBENCH_ARRAY(x1),
	      POLYBENCH_ARRAY(x2),
#if !FMA_DISABLED
	      POLYBENCH_ARRAY(x1_StrictFP),
	      POLYBENCH_ARRAY(x2_StrictFP),
#endif
	      POLYBENCH_ARRAY(y_1),
	      POLYBENCH_ARRAY(y_2),
	      POLYBENCH_ARRAY(A));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_mvt (n,
	      POLYBENCH_ARRAY(x1),
	      POLYBENCH_ARRAY(x2),
	      POLYBENCH_ARRAY(y_1),
	      POLYBENCH_ARRAY(y_2),
	      POLYBENCH_ARRAY(A));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

#if FMA_DISABLED
  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(x1),
                                    POLYBENCH_ARRAY(x2)));
#else
  kernel_mvt_StrictFP(n,
                      POLYBENCH_ARRAY(x1_StrictFP),
                      POLYBENCH_ARRAY(x2_StrictFP),
                      POLYBENCH_ARRAY(y_1),
                      POLYBENCH_ARRAY(y_2),
                      POLYBENCH_ARRAY(A));

  if (!check_FP(n, POLYBENCH_ARRAY(x1), POLYBENCH_ARRAY(x1_StrictFP)))
    return 1;
  if (!check_FP(n, POLYBENCH_ARRAY(x2), POLYBENCH_ARRAY(x2_StrictFP)))
    return 1;
  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(x1_StrictFP),
                                    POLYBENCH_ARRAY(x2_StrictFP)));
#endif

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(x1);
  POLYBENCH_FREE_ARRAY(x2);
#if !FMA_DISABLED
  POLYBENCH_FREE_ARRAY(x1_StrictFP);
  POLYBENCH_FREE_ARRAY(x2_StrictFP);
#endif
  POLYBENCH_FREE_ARRAY(y_1);
  POLYBENCH_FREE_ARRAY(y_2);

  return 0;
}
