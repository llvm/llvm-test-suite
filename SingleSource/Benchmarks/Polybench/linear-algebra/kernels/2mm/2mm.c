/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* 2mm.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
/* Default data type is double, default size is 4000. */
#include "2mm.h"


/* Array initialization. */
void init_array(int ni, int nj, int nk, int nl,
		DATA_TYPE *alpha,
		DATA_TYPE *beta,
		DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
		DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
		DATA_TYPE POLYBENCH_2D(C,NJ,NL,nj,nl),
		DATA_TYPE POLYBENCH_2D(D,NI,NL,ni,nl)
#if !FMA_DISABLED
                , DATA_TYPE POLYBENCH_2D(D_StrictFP,NI,NL,ni,nl)
#endif
		)
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  *alpha = 1.5;
  *beta = 1.2;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = (DATA_TYPE) ((i*j+1) % ni) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = (DATA_TYPE) (i*(j+1) % nj) / nj;
  for (i = 0; i < nj; i++)
    for (j = 0; j < nl; j++)
      C[i][j] = (DATA_TYPE) ((i*(j+3)+1) % nl) / nl;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
#if !FMA_DISABLED
      D_StrictFP[i][j] =
#endif
        D[i][j] = (DATA_TYPE) (i*(j+2) % nk) / nk;
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int ni, int nl,
		 DATA_TYPE POLYBENCH_2D(D,NI,NL,ni,nl))
{
  int i, j;
  char *printmat = malloc(nl*16 + 1); printmat[nl*16] = 0;

  for (i = 0; i < ni; i++) {
    for (j = 0; j < nl; j++)
      print_element(D[i][j], j*16, printmat);
    fputs(printmat, stderr);
  }
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_2mm(int ni, int nj, int nk, int nl,
		DATA_TYPE alpha,
		DATA_TYPE beta,
		DATA_TYPE POLYBENCH_2D(tmp,NI,NJ,ni,nj),
		DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
		DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
		DATA_TYPE POLYBENCH_2D(C,NJ,NL,nj,nl),
		DATA_TYPE POLYBENCH_2D(D,NI,NL,ni,nl))
{
  int i, j, k;

#pragma scop
  /* D := alpha*A*B*C + beta*D */
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NJ; j++)
      {
	tmp[i][j] = SCALAR_VAL(0.0);
	for (k = 0; k < _PB_NK; ++k)
	  tmp[i][j] += alpha * A[i][k] * B[k][j];
      }
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NL; j++)
      {
	D[i][j] *= beta;
	for (k = 0; k < _PB_NJ; ++k)
	  D[i][j] += tmp[i][k] * C[k][j];
      }
#pragma endscop

}

#if !FMA_DISABLED
// NOTE: FMA_DISABLED is true for targets where FMA contraction causes
// discrepancies which cause the accuracy checks to fail.
// In this case, the test runs with the option -ffp-contract=off
static void
kernel_2mm_StrictFP(int ni, int nj, int nk, int nl,
                         DATA_TYPE alpha,
                         DATA_TYPE beta,
                         DATA_TYPE POLYBENCH_2D(tmp,NI,NJ,ni,nj),
                         DATA_TYPE POLYBENCH_2D(A,NI,NK,ni,nk),
                         DATA_TYPE POLYBENCH_2D(B,NK,NJ,nk,nj),
                         DATA_TYPE POLYBENCH_2D(C,NJ,NL,nj,nl),
                         DATA_TYPE POLYBENCH_2D(D,NI,NL,ni,nl))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, k;

  /* D := alpha*A*B*C + beta*D */
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NJ; j++)
      {
	tmp[i][j] = SCALAR_VAL(0.0);
	for (k = 0; k < _PB_NK; ++k)
	  tmp[i][j] += alpha * A[i][k] * B[k][j];
      }
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NL; j++)
      {
	D[i][j] *= beta;
	for (k = 0; k < _PB_NJ; ++k)
	  D[i][j] += tmp[i][k] * C[k][j];
      }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int ni, int nl,
         DATA_TYPE POLYBENCH_2D(A,NI,NL,ni,nl),
         DATA_TYPE POLYBENCH_2D(B,NI,NL,ni,nl)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NL; j++)
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
#endif

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int ni = NI;
  int nj = NJ;
  int nk = NK;
  int nl = NL;

  /* Variable declaration/allocation. */
  DATA_TYPE alpha;
  DATA_TYPE beta;
  POLYBENCH_2D_ARRAY_DECL(tmp,DATA_TYPE,NI,NJ,ni,nj);
  POLYBENCH_2D_ARRAY_DECL(A,DATA_TYPE,NI,NK,ni,nk);
  POLYBENCH_2D_ARRAY_DECL(B,DATA_TYPE,NK,NJ,nk,nj);
  POLYBENCH_2D_ARRAY_DECL(C,DATA_TYPE,NJ,NL,nj,nl);
  POLYBENCH_2D_ARRAY_DECL(D,DATA_TYPE,NI,NL,ni,nl);
#if !FMA_DISABLED
  POLYBENCH_2D_ARRAY_DECL(D_StrictFP,DATA_TYPE,NI,NL,ni,nl);
#endif

  /* Initialize array(s). */
  init_array (ni, nj, nk, nl, &alpha, &beta,
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(B),
	      POLYBENCH_ARRAY(C),
	      POLYBENCH_ARRAY(D)
#if !FMA_DISABLED
              , POLYBENCH_ARRAY(D_StrictFP)
#endif
	      );

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_2mm (ni, nj, nk, nl,
	      alpha, beta,
	      POLYBENCH_ARRAY(tmp),
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(B),
	      POLYBENCH_ARRAY(C),
	      POLYBENCH_ARRAY(D));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

#if FMA_DISABLED
  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(ni, nl, POLYBENCH_ARRAY(D)));
#else
  kernel_2mm_StrictFP(ni, nj, nk, nl,
                      alpha, beta,
                      POLYBENCH_ARRAY(tmp),
                      POLYBENCH_ARRAY(A),
                      POLYBENCH_ARRAY(B),
                      POLYBENCH_ARRAY(C),
                      POLYBENCH_ARRAY(D_StrictFP));

  if (!check_FP(ni, nl, POLYBENCH_ARRAY(D), POLYBENCH_ARRAY(D_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(ni, nl, POLYBENCH_ARRAY(D_StrictFP)));
#endif

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(tmp);
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(B);
  POLYBENCH_FREE_ARRAY(C);
  POLYBENCH_FREE_ARRAY(D);
#if !FMA_DISABLED
  POLYBENCH_FREE_ARRAY(D_StrictFP);
#endif

  return 0;
}
