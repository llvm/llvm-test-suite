/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* doitgen.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Include polybench common header. */
#include <polybench.h>

/* Include benchmark-specific header. */
/* Default data type is double, default size is 4000. */
#include "doitgen.h"


/* Array initialization. */
static
void init_array(int nr, int nq, int np,
		DATA_TYPE POLYBENCH_3D(A,NR,NQ,NP,nr,nq,np)
#if !FMA_DISABLED
		, DATA_TYPE POLYBENCH_3D(A_StrictFP,NR,NQ,NP,nr,nq,np),
#endif
		DATA_TYPE POLYBENCH_2D(C4,NP,NP,np,np))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, k;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++)
#if !FMA_DISABLED
	A_StrictFP[i][j][k] =
#endif
	       	A[i][j][k] = (DATA_TYPE) ((i*j + k)%np) / np;
  for (i = 0; i < np; i++)
    for (j = 0; j < np; j++)
      C4[i][j] = (DATA_TYPE) (i*j % np) / np;
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int nr, int nq, int np,
		 DATA_TYPE POLYBENCH_3D(A,NR,NQ,NP,nr,nq,np))
{
  int i, j, k;
  char *printmat = malloc(np*16 + 1); printmat[np*16] = 0;

  for (i = 0; i < nr; i++) {
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++)
      print_element(A[i][j][k], k*16, printmat);
    fputs(printmat, stderr);
  }
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
void kernel_doitgen(int nr, int nq, int np,
		    DATA_TYPE POLYBENCH_3D(A,NR,NQ,NP,nr,nq,np),
		    DATA_TYPE POLYBENCH_2D(C4,NP,NP,np,np),
		    DATA_TYPE POLYBENCH_1D(sum,NP,np))
{
  int r, q, p, s;

#pragma scop
  for (r = 0; r < _PB_NR; r++)
    for (q = 0; q < _PB_NQ; q++)  {
      for (p = 0; p < _PB_NP; p++)  {
	sum[p] = SCALAR_VAL(0.0);
	for (s = 0; s < _PB_NP; s++)
	  sum[p] += A[r][q][s] * C4[s][p];
      }
      for (p = 0; p < _PB_NP; p++)
	A[r][q][p] = sum[p];
    }
#pragma endscop

}

#if !FMA_DISABLED
// NOTE: FMA_DISABLED is true for targets where FMA contraction causes
// discrepancies which cause the accuracy checks to fail.
// In this case, the test runs with the option -ffp-contract=off
void kernel_doitgen_StrictFP(int nr, int nq, int np,
		    DATA_TYPE POLYBENCH_3D(A,NR,NQ,NP,nr,nq,np),
		    DATA_TYPE POLYBENCH_2D(C4,NP,NP,np,np),
		    DATA_TYPE POLYBENCH_1D(sum,NP,np))
{
#pragma STDC FP_CONTRACT OFF
  int r, q, p, s;

  for (r = 0; r < _PB_NR; r++)
    for (q = 0; q < _PB_NQ; q++)  {
      for (p = 0; p < _PB_NP; p++)  {
	sum[p] = SCALAR_VAL(0.0);
	for (s = 0; s < _PB_NP; s++)
	  sum[p] += A[r][q][s] * C4[s][p];
      }
      for (p = 0; p < _PB_NP; p++)
	A[r][q][p] = sum[p];
    }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int nr, int nq, int np,
         DATA_TYPE POLYBENCH_3D(A,NR,NQ,NP,nr,nq,np),
         DATA_TYPE POLYBENCH_3D(B,NR,NQ,NP,nr,nq,np)) {
  double AbsTolerance = FP_ABSTOLERANCE;
  int r, q, p, s;

  for (r = 0; r < _PB_NR; r++)
    for (q = 0; q < _PB_NQ; q++)
      for (p = 0; p < _PB_NP; p++) {
        double V1 = A[r][q][p];
        double V2 = B[r][q][p];
        double Diff = fabs(V1 - V2);
        if (Diff > AbsTolerance) {
          fprintf(stderr, "A[%d][%d][%d] = %lf and B[%d][%d][%d] = %lf differ more than"
                  " FP_ABSTOLERANCE = %lf\n", r, q, p, V1, r, q, p, V2, AbsTolerance);
          return 0;
        }
      }

  return 1;
}
#endif

int main(int argc, char** argv)
{
  /* Retrieve problem size. */
  int nr = NR;
  int nq = NQ;
  int np = NP;

  /* Variable declaration/allocation. */
  POLYBENCH_3D_ARRAY_DECL(A,DATA_TYPE,NR,NQ,NP,nr,nq,np);
#if !FMA_DISABLED
  POLYBENCH_3D_ARRAY_DECL(A_StrictFP,DATA_TYPE,NR,NQ,NP,nr,nq,np);
#endif
  POLYBENCH_1D_ARRAY_DECL(sum,DATA_TYPE,NP,np);
  POLYBENCH_2D_ARRAY_DECL(C4,DATA_TYPE,NP,NP,np,np);

  /* Initialize array(s). */
  init_array (nr, nq, np,
	      POLYBENCH_ARRAY(A),
#if !FMA_DISABLED
	      POLYBENCH_ARRAY(A_StrictFP),
#endif
	      POLYBENCH_ARRAY(C4));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_doitgen (nr, nq, np,
		  POLYBENCH_ARRAY(A),
		  POLYBENCH_ARRAY(C4),
		  POLYBENCH_ARRAY(sum));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

#if FMA_DISABLED
  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(nr, nq, np, POLYBENCH_ARRAY(A)));
#else
  kernel_doitgen_StrictFP(nr, nq, np,
                          POLYBENCH_ARRAY(A_StrictFP),
                          POLYBENCH_ARRAY(C4),
                          POLYBENCH_ARRAY(sum));

  if (!check_FP(nr, nq, np, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(A_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(nr, nq, np, POLYBENCH_ARRAY(A_StrictFP)));
#endif

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
#if !FMA_DISABLED
  POLYBENCH_FREE_ARRAY(A_StrictFP);
#endif
  POLYBENCH_FREE_ARRAY(sum);
  POLYBENCH_FREE_ARRAY(C4);

  return 0;
}
