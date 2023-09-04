/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* jacobi-1d.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
/* Default data type is double, default size is 100x10000. */
#include "jacobi-1d.h"


/* Array initialization. */
static
void init_array (int n,
		 DATA_TYPE POLYBENCH_1D(A,N,n),
		 DATA_TYPE POLYBENCH_1D(B,N,n))
{
#pragma STDC FP_CONTRACT OFF
  int i;

  for (i = 0; i < n; i++)
      {
	A[i] = ((DATA_TYPE) i+ 2) / n;
	B[i] = ((DATA_TYPE) i+ 3) / n;
      }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 DATA_TYPE POLYBENCH_1D(A,N,n))

{
  int i;
  char *printmat = malloc(n*16 + 1); printmat[n*16] = 0;

  for (i = 0; i < n; i++)
    print_element(A[i], i*16, printmat);
  fputs(printmat, stderr);
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_jacobi_1d(int tsteps,
			    int n,
			    DATA_TYPE POLYBENCH_1D(A,N,n),
			    DATA_TYPE POLYBENCH_1D(B,N,n))
{
  int t, i;

#pragma scop
  for (t = 0; t < _PB_TSTEPS; t++)
    {
      for (i = 1; i < _PB_N - 1; i++)
	B[i] = 0.33333 * (A[i-1] + A[i] + A[i + 1]);
      for (i = 1; i < _PB_N - 1; i++)
	A[i] = 0.33333 * (B[i-1] + B[i] + B[i + 1]);
    }
#pragma endscop

}

#if !FMA_DISABLED
// NOTE: FMA_DISABLED is true for targets where FMA contraction causes
// discrepancies which cause the accuracy checks to fail.
// In this case, the test runs with the option -ffp-contract=off
static void
kernel_jacobi_1d_StrictFP(int tsteps,
                                int n,
                                DATA_TYPE POLYBENCH_1D(A,N,n),
                                DATA_TYPE POLYBENCH_1D(B,N,n))
{
  #pragma STDC FP_CONTRACT OFF
  int t, i;

  for (t = 0; t < _PB_TSTEPS; t++)
    {
      for (i = 1; i < _PB_N - 1; i++)
	B[i] = 0.33333 * (A[i-1] + A[i] + A[i + 1]);
      for (i = 1; i < _PB_N - 1; i++)
	A[i] = 0.33333 * (B[i-1] + B[i] + B[i + 1]);
    }
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
  int tsteps = TSTEPS;

  /* Variable declaration/allocation. */
  POLYBENCH_1D_ARRAY_DECL(A, DATA_TYPE, N, n);
#if !FMA_DISABLED
  POLYBENCH_1D_ARRAY_DECL(A_StrictFP, DATA_TYPE, N, n);
#endif
  POLYBENCH_1D_ARRAY_DECL(B, DATA_TYPE, N, n);


  /* Initialize array(s). */
  init_array (n, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(B));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_jacobi_1d (tsteps, n, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(B));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

#if FMA_DISABLED
  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(A)));
#else
  init_array (n, POLYBENCH_ARRAY(A_StrictFP), POLYBENCH_ARRAY(B));
  kernel_jacobi_1d_StrictFP (tsteps, n, POLYBENCH_ARRAY(A_StrictFP),
                          POLYBENCH_ARRAY(B));
  if (!check_FP(n, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(A_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(A_StrictFP)));
#endif

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
#if !FMA_DISABLED
  POLYBENCH_FREE_ARRAY(A_StrictFP);
#endif
  POLYBENCH_FREE_ARRAY(B);

  return 0;
}
