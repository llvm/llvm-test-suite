/**
 * gramschmidt.c: This file is part of the PolyBench/C 3.2 test suite.
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
/* Default data type is double, default size is 512. */
#include "gramschmidt.h"


/* Array initialization. */
static
void init_array(int ni, int nj,
		DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
		DATA_TYPE POLYBENCH_2D(R,NJ,NJ,nj,nj),
		DATA_TYPE POLYBENCH_2D(Q,NI,NJ,ni,nj))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;
  /*
  LLVM: This change ensures we do not calculate nan values, which are
        formatted differently on different platforms and which may also
        be optimized unexpectedly.
  Original code:
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      A[i][j] = ((DATA_TYPE) i*j) / ni;
      Q[i][j] = ((DATA_TYPE) i*(j+1)) / nj;
    }
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++)
      R[i][j] = ((DATA_TYPE) i*(j+2)) / nj;
  */
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
      A[i][j] = ((DATA_TYPE) i*j+ni) / ni;
      Q[i][j] = ((DATA_TYPE) i*(j+1)+nj) / nj;
    }
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++)
      R[i][j] = ((DATA_TYPE) i*(j+2)+nj) / nj;
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
/* FIXME: This print_array method wasn't converted to use the
   faster print_element method like the others because it's
   not bit identical across multiple runs on ARM64. It should be. */
static
void print_array(int ni, int nj,
		 DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
		 DATA_TYPE POLYBENCH_2D(R,NJ,NJ,nj,nj),
		 DATA_TYPE POLYBENCH_2D(Q,NI,NJ,ni,nj))
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
       fprintf (stderr, DATA_PRINTF_MODIFIER, A[i][j]);
       if (i % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
  for (i = 0; i < nj; i++)
    for (j = 0; j < nj; j++) {
       fprintf (stderr, DATA_PRINTF_MODIFIER, R[i][j]);
       if (i % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
       fprintf (stderr, DATA_PRINTF_MODIFIER, Q[i][j]);
       if (i % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_gramschmidt(int ni, int nj,
			DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
			DATA_TYPE POLYBENCH_2D(R,NJ,NJ,nj,nj),
			DATA_TYPE POLYBENCH_2D(Q,NI,NJ,ni,nj))
{
  int i, j, k;

  DATA_TYPE nrm;

#pragma scop
  for (k = 0; k < _PB_NJ; k++)
    {
      nrm = 0;
      for (i = 0; i < _PB_NI; i++)
        nrm += A[i][k] * A[i][k];
      R[k][k] = sqrt(nrm);
      for (i = 0; i < _PB_NI; i++)
        Q[i][k] = A[i][k] / R[k][k];
      for (j = k + 1; j < _PB_NJ; j++)
	{
	  R[k][j] = 0;
	  for (i = 0; i < _PB_NI; i++)
	    R[k][j] += Q[i][k] * A[i][j];
	  for (i = 0; i < _PB_NI; i++)
	    A[i][j] = A[i][j] - Q[i][k] * R[k][j];
	}
    }
#pragma endscop

}

static void
kernel_gramschmidt_StrictFP(int ni, int nj,
                            DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
                            DATA_TYPE POLYBENCH_2D(R,NJ,NJ,nj,nj),
                            DATA_TYPE POLYBENCH_2D(Q,NI,NJ,ni,nj))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, k;

  DATA_TYPE nrm;

  for (k = 0; k < _PB_NJ; k++)
    {
      nrm = 0;
      for (i = 0; i < _PB_NI; i++)
        nrm += A[i][k] * A[i][k];
      R[k][k] = sqrt(nrm);
      for (i = 0; i < _PB_NI; i++)
        Q[i][k] = A[i][k] / R[k][k];
      for (j = k + 1; j < _PB_NJ; j++)
	{
	  R[k][j] = 0;
	  for (i = 0; i < _PB_NI; i++)
	    R[k][j] += Q[i][k] * A[i][j];
	  for (i = 0; i < _PB_NI; i++)
	    A[i][j] = A[i][j] - Q[i][k] * R[k][j];
	}
    }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int ni, int nj,
         DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
         DATA_TYPE POLYBENCH_2D(B,NI,NJ,ni,nj)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_NI; i++)
    for (j = 0; j < _PB_NJ; j++)
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
  int nj = NJ;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(A,DATA_TYPE,NI,NJ,ni,nj);
  POLYBENCH_2D_ARRAY_DECL(R,DATA_TYPE,NJ,NJ,nj,nj);
  POLYBENCH_2D_ARRAY_DECL(Q,DATA_TYPE,NI,NJ,ni,nj);
  POLYBENCH_2D_ARRAY_DECL(A_StrictFP,DATA_TYPE,NI,NJ,ni,nj);
  POLYBENCH_2D_ARRAY_DECL(R_StrictFP,DATA_TYPE,NJ,NJ,nj,nj);
  POLYBENCH_2D_ARRAY_DECL(Q_StrictFP,DATA_TYPE,NI,NJ,ni,nj);

  /* Initialize array(s). */
  init_array (ni, nj,
	      POLYBENCH_ARRAY(A),
	      POLYBENCH_ARRAY(R),
	      POLYBENCH_ARRAY(Q));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_gramschmidt (ni, nj,
		      POLYBENCH_ARRAY(A),
		      POLYBENCH_ARRAY(R),
		      POLYBENCH_ARRAY(Q));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  init_array (ni, nj,
	      POLYBENCH_ARRAY(A_StrictFP),
	      POLYBENCH_ARRAY(R_StrictFP),
	      POLYBENCH_ARRAY(Q_StrictFP));
  kernel_gramschmidt_StrictFP(ni, nj,
                              POLYBENCH_ARRAY(A_StrictFP),
                              POLYBENCH_ARRAY(R_StrictFP),
                              POLYBENCH_ARRAY(Q_StrictFP));

  if (!check_FP(ni, nj, POLYBENCH_ARRAY(A), POLYBENCH_ARRAY(A_StrictFP)))
    return 1;
  if (!check_FP(ni, nj, POLYBENCH_ARRAY(R), POLYBENCH_ARRAY(R_StrictFP)))
    return 1;
  if (!check_FP(ni, nj, POLYBENCH_ARRAY(Q), POLYBENCH_ARRAY(Q_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(ni, nj,
                                    POLYBENCH_ARRAY(A_StrictFP),
                                    POLYBENCH_ARRAY(R_StrictFP),
                                    POLYBENCH_ARRAY(Q_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(A);
  POLYBENCH_FREE_ARRAY(R);
  POLYBENCH_FREE_ARRAY(Q);
  POLYBENCH_FREE_ARRAY(A_StrictFP);
  POLYBENCH_FREE_ARRAY(R_StrictFP);
  POLYBENCH_FREE_ARRAY(Q_StrictFP);

  return 0;
}
