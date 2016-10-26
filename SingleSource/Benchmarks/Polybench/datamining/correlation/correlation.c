/**
 * correlation.c: This file is part of the PolyBench/C 3.2 test suite.
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
#include "../../utilities/polybench.h"

/* Include benchmark-specific header. */
/* Default data type is double, default size is 4000. */
#include "correlation.h"


/* Array initialization. */
static
void init_array (int m,
		 int n,
		 DATA_TYPE *float_n,
		 DATA_TYPE POLYBENCH_2D(data,M,N,m,n))
{
#pragma STDC FP_CONTRACT OFF
  int i, j;

  *float_n = 1.2;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      data[i][j] = ((DATA_TYPE) i*j) / M;
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int m,
		 DATA_TYPE POLYBENCH_2D(symmat,M,M,m,m))

{
  int i, j;
  char *printmat = malloc(m*16 + 1); printmat[m*16] = 0;

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      print_element(symmat[i][j], j*16, printmat);
    }
    fputs(printmat, stderr);
  }
  free(printmat);
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_correlation(int m, int n,
			DATA_TYPE float_n,
			DATA_TYPE POLYBENCH_2D(data,M,N,m,n),
			DATA_TYPE POLYBENCH_2D(symmat,M,M,m,m),
			DATA_TYPE POLYBENCH_1D(mean,M,m),
			DATA_TYPE POLYBENCH_1D(stddev,M,m))
{
  int i, j, j1, j2;

  DATA_TYPE eps = 0.1f;

#define sqrt_of_array_cell(x,j) sqrt(x[j])

#pragma scop
  /* Determine mean of column vectors of input data matrix */
  for (j = 0; j < _PB_M; j++)
    {
      mean[j] = 0.0;
      for (i = 0; i < _PB_N; i++)
	mean[j] += data[i][j];
      mean[j] /= float_n;
    }

  /* Determine standard deviations of column vectors of data matrix. */
  for (j = 0; j < _PB_M; j++)
    {
      stddev[j] = 0.0;
      for (i = 0; i < _PB_N; i++)
	stddev[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
      stddev[j] /= float_n;
      stddev[j] = sqrt_of_array_cell(stddev, j);
      /* The following in an inelegant but usual way to handle
	 near-zero std. dev. values, which below would cause a zero-
	 divide. */
      stddev[j] = stddev[j] <= eps ? 1.0 : stddev[j];
    }

  /* Center and reduce the column vectors. */
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_M; j++)
      {
	data[i][j] -= mean[j];
	data[i][j] /= sqrt(float_n) * stddev[j];
      }

  /* Calculate the m * m correlation matrix. */
  for (j1 = 0; j1 < _PB_M-1; j1++)
    {
      symmat[j1][j1] = 1.0;
      for (j2 = j1+1; j2 < _PB_M; j2++)
	{
	  symmat[j1][j2] = 0.0;
	  for (i = 0; i < _PB_N; i++)
	    symmat[j1][j2] += (data[i][j1] * data[i][j2]);
	  symmat[j2][j1] = symmat[j1][j2];
	}
    }
  symmat[_PB_M-1][_PB_M-1] = 1.0;
#pragma endscop

}

static void
kernel_correlation_StrictFP(int m, int n,
                            DATA_TYPE float_n,
                            DATA_TYPE POLYBENCH_2D(data,M,N,m,n),
                            DATA_TYPE POLYBENCH_2D(symmat,M,M,m,m),
                            DATA_TYPE POLYBENCH_1D(mean,M,m),
                            DATA_TYPE POLYBENCH_1D(stddev,M,m))
{
#pragma STDC FP_CONTRACT OFF
  int i, j, j1, j2;

  DATA_TYPE eps = 0.1f;

#define sqrt_of_array_cell(x,j) sqrt(x[j])

  /* Determine mean of column vectors of input data matrix */
  for (j = 0; j < _PB_M; j++)
    {
      mean[j] = 0.0;
      for (i = 0; i < _PB_N; i++)
	mean[j] += data[i][j];
      mean[j] /= float_n;
    }

  /* Determine standard deviations of column vectors of data matrix. */
  for (j = 0; j < _PB_M; j++)
    {
      stddev[j] = 0.0;
      for (i = 0; i < _PB_N; i++)
	stddev[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
      stddev[j] /= float_n;
      stddev[j] = sqrt_of_array_cell(stddev, j);
      /* The following in an inelegant but usual way to handle
	 near-zero std. dev. values, which below would cause a zero-
	 divide. */
      stddev[j] = stddev[j] <= eps ? 1.0 : stddev[j];
    }

  /* Center and reduce the column vectors. */
  for (i = 0; i < _PB_N; i++)
    for (j = 0; j < _PB_M; j++)
      {
	data[i][j] -= mean[j];
	data[i][j] /= sqrt(float_n) * stddev[j];
      }

  /* Calculate the m * m correlation matrix. */
  for (j1 = 0; j1 < _PB_M-1; j1++)
    {
      symmat[j1][j1] = 1.0;
      for (j2 = j1+1; j2 < _PB_M; j2++)
	{
	  symmat[j1][j2] = 0.0;
	  for (i = 0; i < _PB_N; i++)
	    symmat[j1][j2] += (data[i][j1] * data[i][j2]);
	  symmat[j2][j1] = symmat[j1][j2];
	}
    }
  symmat[_PB_M-1][_PB_M-1] = 1.0;
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int m,
         DATA_TYPE POLYBENCH_2D(A,M,M,m,m),
         DATA_TYPE POLYBENCH_2D(B,M,M,m,m)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_M; i++)
    for (j = 0; j < _PB_M; j++)
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
  int n = N;
  int m = M;

  /* Variable declaration/allocation. */
  DATA_TYPE float_n;
  POLYBENCH_2D_ARRAY_DECL(data,DATA_TYPE,M,N,m,n);
  POLYBENCH_2D_ARRAY_DECL(symmat,DATA_TYPE,M,M,m,m);
  POLYBENCH_2D_ARRAY_DECL(symmat_StrictFP,DATA_TYPE,M,M,m,m);
  POLYBENCH_1D_ARRAY_DECL(mean,DATA_TYPE,M,m);
  POLYBENCH_1D_ARRAY_DECL(stddev,DATA_TYPE,M,m);

  /* Initialize array(s). */
  init_array (m, n, &float_n, POLYBENCH_ARRAY(data));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_correlation (m, n, float_n,
		      POLYBENCH_ARRAY(data),
		      POLYBENCH_ARRAY(symmat),
		      POLYBENCH_ARRAY(mean),
		      POLYBENCH_ARRAY(stddev));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  init_array (m, n, &float_n, POLYBENCH_ARRAY(data));
  kernel_correlation (m, n, float_n,
		      POLYBENCH_ARRAY(data),
		      POLYBENCH_ARRAY(symmat_StrictFP),
		      POLYBENCH_ARRAY(mean),
		      POLYBENCH_ARRAY(stddev));
  if (!check_FP(m, POLYBENCH_ARRAY(symmat), POLYBENCH_ARRAY(symmat_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(m, POLYBENCH_ARRAY(symmat_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(data);
  POLYBENCH_FREE_ARRAY(symmat);
  POLYBENCH_FREE_ARRAY(symmat_StrictFP);
  POLYBENCH_FREE_ARRAY(mean);
  POLYBENCH_FREE_ARRAY(stddev);

  return 0;
}
