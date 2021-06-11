/**
 * cholesky.c: This file is part of the PolyBench/C 3.2 test suite.
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
#include "cholesky.h"


/* Array initialization. */
static
void init_array(int n,
		DATA_TYPE POLYBENCH_1D(p,N,n),
		DATA_TYPE POLYBENCH_2D(A,N,N,n,n),
                DATA_TYPE POLYBENCH_2D(A_StrictFP,N,N,n,n))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;
  /*
  LLVM: This change ensures we do not calculate nan values, which are
        formatted differently on different platforms and which may also
        be optimized unexpectedly.
  Original code:
  for (i = 0; i < n; i++)
    {
      p[i] = 1.0 / n;
      for (j = 0; j < n; j++)
        A[i][j] = 1.0 / n;
     }
  */
  for (i = 0; i < n; i++)
    {
      p[i] = i + n;
      for (j = 0; j < n; j++)
        A_StrictFP[i][j] = A[i][j] = j + n;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 DATA_TYPE POLYBENCH_2D(A,N,N,n,n))

{
  int i, j;
  char *printmat = malloc(n*16 + 1); printmat[n*16] = 0;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      print_element(A[i][j], j*16, printmat);
    fputs(printmat, stderr);
  }
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_cholesky(int n,
		     DATA_TYPE POLYBENCH_1D(p,N,n),
		     DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
  int i, j, k;

  DATA_TYPE x;

#pragma scop
for (i = 0; i < _PB_N; ++i)
  {
   /*
      LLVM: This change ensures we do not calculate nan values, which are
            formatted differently on different platforms and which may also
            be optimized unexpectedly.    
      Original line:      
            x = A[i][i];      
    */      
    x = A[i][i] * n;
    for (j = 0; j <= i - 1; ++j)
      x = x - A[i][j] * A[i][j];
    p[i] = 1.0 / sqrt(x);
    for (j = i + 1; j < _PB_N; ++j)
      {
	x = A[i][j];
	for (k = 0; k <= i - 1; ++k)
	  x = x - A[j][k] * A[i][k];
	A[j][i] = x * p[i];
      }
  }
#pragma endscop

}

static
void kernel_cholesky_StrictFP(int n,
                              DATA_TYPE POLYBENCH_1D(p,N,n),
                              DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, k;

  DATA_TYPE x;

for (i = 0; i < _PB_N; ++i)
  {
   /*
      LLVM: This change ensures we do not calculate nan values, which are
            formatted differently on different platforms and which may also
            be optimized unexpectedly.    
      Original line:      
            x = A[i][i];      
    */      
    x = A[i][i] * n;
    for (j = 0; j <= i - 1; ++j)
      x = x - A[i][j] * A[i][j];
    p[i] = 1.0 / sqrt(x);
    for (j = i + 1; j < _PB_N; ++j)
      {
	x = A[i][j];
	for (k = 0; k <= i - 1; ++k)
	  x = x - A[j][k] * A[i][k];
	A[j][i] = x * p[i];
      }
  }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int n,
         DATA_TYPE POLYBENCH_2D(A,N,N,n,n),
         DATA_TYPE POLYBENCH_2D(B,N,N,n,n)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_N; j++)
      {
        double V1 = A[i][j];
        double V2 = B[i][j];
        double Diff = fabs(V1 - V2);
        if (Diff > AbsTolerance) {
          fprintf(stderr, "A[%d][%d] = %lf and B[%d][%d] = %lf differ more than"
                  " FP_ABSTOLERANCE = %lf\n", i, j, V1, i, j, V2, AbsTolerance);
          return 0;
        }
      }

  return 1;
}

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int n = N;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(A, DATA_TYPE, N, N, n, n);
  POLYBENCH_1D_ARRAY_DECL(p, DATA_TYPE, N, n);
  POLYBENCH_2D_ARRAY_DECL(A_StrictFP, DATA_TYPE, N, N, n, n);


  /* Initialize array(s). */
  init_array (n, POLYBENCH_ARRAY(p), POLYBENCH_ARRAY(A),
              POLYBENCH_ARRAY(A_StrictFP));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_cholesky (n, POLYBENCH_ARRAY(p), POLYBENCH_ARRAY(A));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  kernel_cholesky_StrictFP(n, POLYBENCH_ARRAY(p), POLYBENCH_ARRAY(A_StrictFP));
  if (!check_FP(n, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(A_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(n, POLYBENCH_ARRAY(A_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(A_StrictFP);
  POLYBENCH_FREE_ARRAY(p);

  return 0;
}
