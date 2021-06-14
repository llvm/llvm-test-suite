/**
 * trmm.c: This file is part of the PolyBench/C 3.2 test suite.
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
#include "trmm.h"


/* Array initialization. */
static
void init_array(int ni,
		DATA_TYPE *alpha,
		DATA_TYPE POLYBENCH_2D(A,NI,NI,ni,ni),
		DATA_TYPE POLYBENCH_2D(B,NI,NI,ni,ni),
                DATA_TYPE POLYBENCH_2D(B_StrictFP,NI,NI,ni,ni))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  *alpha = 32412;
  for (i = 0; i < ni; i++)
    for (j = 0; j < ni; j++) {
      A[i][j] = ((DATA_TYPE) i*j) / ni;
      B_StrictFP[i][j] = B[i][j] = ((DATA_TYPE) i*j) / ni;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int ni,
		 DATA_TYPE POLYBENCH_2D(B,NI,NI,ni,ni))
{
  int i, j;
  char *printmat = malloc(ni*16 + 1); printmat[ni*16] = 0;

  for (i = 0; i < ni; i++) {
    for (j = 0; j < ni; j++)
      print_element(B[i][j], j*16, printmat);
    fputs(printmat, stderr);
  }
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_trmm(int ni,
		 DATA_TYPE alpha,
		 DATA_TYPE POLYBENCH_2D(A,NI,NI,ni,ni),
		 DATA_TYPE POLYBENCH_2D(B,NI,NI,ni,ni))
{
  int i, j, k;

#pragma scop
  /*  B := alpha*A'*B, A triangular */
  for (i = 1; i < _PB_NI; i++)
    for (j = 0; j < _PB_NI; j++)
      for (k = 0; k < i; k++)
        B[i][j] += alpha * A[i][k] * B[j][k];
#pragma endscop

}

static void
kernel_trmm_StrictFP(int ni,
                     DATA_TYPE alpha,
                     DATA_TYPE POLYBENCH_2D(A,NI,NI,ni,ni),
                     DATA_TYPE POLYBENCH_2D(B,NI,NI,ni,ni))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, k;

  /*  B := alpha*A'*B, A triangular */
  for (i = 1; i < _PB_NI; i++)
    for (j = 0; j < _PB_NI; j++)
      for (k = 0; k < i; k++)
        B[i][j] += alpha * A[i][k] * B[j][k];
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int ni,
         DATA_TYPE POLYBENCH_2D(A,NI,NI,ni,ni),
         DATA_TYPE POLYBENCH_2D(B,NI,NI,ni,ni)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NI; j++)
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

  /* All elements are within the allowed FP_ABSTOLERANCE error margin.  */
  return 1;
}

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int ni = NI;

  /* Variable declaration/allocation. */
  DATA_TYPE alpha;
  POLYBENCH_2D_ARRAY_DECL(A,DATA_TYPE,NI,NI,ni,ni);
  POLYBENCH_2D_ARRAY_DECL(B,DATA_TYPE,NI,NI,ni,ni);
  POLYBENCH_2D_ARRAY_DECL(B_StrictFP,DATA_TYPE,NI,NI,ni,ni);

  /* Initialize array(s). */
  init_array (ni, &alpha, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(B),
              POLYBENCH_ARRAY(B_StrictFP));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_trmm (ni, alpha, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(B));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  kernel_trmm_StrictFP(ni, alpha, POLYBENCH_ARRAY(A),
                       POLYBENCH_ARRAY(B_StrictFP));

  if (!check_FP(ni, POLYBENCH_ARRAY(B), POLYBENCH_ARRAY(B_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(ni, POLYBENCH_ARRAY(B_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(B);

  return 0;
}
