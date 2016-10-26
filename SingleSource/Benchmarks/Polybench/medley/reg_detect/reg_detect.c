/**
 * reg_detect.c: This file is part of the PolyBench/C 3.2 test suite.
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
/* Default data type is int, default size is 50. */
#include "reg_detect.h"


/* Array initialization. */
static
void init_array(int maxgrid,
		DATA_TYPE POLYBENCH_2D(sum_tang,MAXGRID,MAXGRID,maxgrid,maxgrid),
		DATA_TYPE POLYBENCH_2D(mean,MAXGRID,MAXGRID,maxgrid,maxgrid),
		DATA_TYPE POLYBENCH_2D(path,MAXGRID,MAXGRID,maxgrid,maxgrid))
{  
#pragma STDC FP_CONTRACT OFF
  int i, j;

  for (i = 0; i < maxgrid; i++)
    for (j = 0; j < maxgrid; j++) {
      sum_tang[i][j] = (DATA_TYPE)((i+1)*(j+1));
      mean[i][j] = ((DATA_TYPE) i-j) / maxgrid;
      path[i][j] = ((DATA_TYPE) i*(j-1)) / maxgrid;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
/* FIXME: This print_array method wasn't converted to use the
   faster print_element method like the others because it's
   not bit identical across multiple runs on ARM64. It should be. */
static
void print_array(int maxgrid,
		 DATA_TYPE POLYBENCH_2D(path,MAXGRID,MAXGRID,maxgrid,maxgrid))
{
  int i, j;

  for (i = 0; i < maxgrid; i++)
    for (j = 0; j < maxgrid; j++) {
      fprintf (stderr, DATA_PRINTF_MODIFIER, path[i][j]);
      if ((i * maxgrid + j) % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
/* Source (modified): http://www.cs.uic.edu/~iluican/reg_detect.c */
static
void kernel_reg_detect(int niter, int maxgrid, int length,
		       DATA_TYPE POLYBENCH_2D(sum_tang,MAXGRID,MAXGRID,maxgrid,maxgrid),
		       DATA_TYPE POLYBENCH_2D(mean,MAXGRID,MAXGRID,maxgrid,maxgrid),
		       DATA_TYPE POLYBENCH_2D(path,MAXGRID,MAXGRID,maxgrid,maxgrid),
		       DATA_TYPE POLYBENCH_3D(diff,MAXGRID,MAXGRID,LENGTH,maxgrid,maxgrid,length),
		       DATA_TYPE POLYBENCH_3D(sum_diff,MAXGRID,MAXGRID,LENGTH,maxgrid,maxgrid,length))
{
  int t, i, j, cnt;

#pragma scop
  for (t = 0; t < _PB_NITER; t++)
    {
      for (j = 0; j <= _PB_MAXGRID - 1; j++)
	for (i = j; i <= _PB_MAXGRID - 1; i++)
	  for (cnt = 0; cnt <= _PB_LENGTH - 1; cnt++)
	    diff[j][i][cnt] = sum_tang[j][i];

      for (j = 0; j <= _PB_MAXGRID - 1; j++)
        {
	  for (i = j; i <= _PB_MAXGRID - 1; i++)
            {
	      sum_diff[j][i][0] = diff[j][i][0];
	      for (cnt = 1; cnt <= _PB_LENGTH - 1; cnt++)
		sum_diff[j][i][cnt] = sum_diff[j][i][cnt - 1] + diff[j][i][cnt];
	      mean[j][i] = sum_diff[j][i][_PB_LENGTH - 1];
            }
        }

      for (i = 0; i <= _PB_MAXGRID - 1; i++)
	path[0][i] = mean[0][i];

      for (j = 1; j <= _PB_MAXGRID - 1; j++)
	for (i = j; i <= _PB_MAXGRID - 1; i++)
	  path[j][i] = path[j - 1][i - 1] + mean[j][i];
    }
#pragma endscop

}

static void
kernel_reg_detect_StrictFP(int niter, int maxgrid, int length,
                           DATA_TYPE POLYBENCH_2D(sum_tang,MAXGRID,MAXGRID,maxgrid,maxgrid),
                           DATA_TYPE POLYBENCH_2D(mean,MAXGRID,MAXGRID,maxgrid,maxgrid),
                           DATA_TYPE POLYBENCH_2D(path,MAXGRID,MAXGRID,maxgrid,maxgrid),
                           DATA_TYPE POLYBENCH_3D(diff,MAXGRID,MAXGRID,LENGTH,maxgrid,maxgrid,length),
                           DATA_TYPE POLYBENCH_3D(sum_diff,MAXGRID,MAXGRID,LENGTH,maxgrid,maxgrid,length))
{
#pragma STDC FP_CONTRACT OFF
  int t, i, j, cnt;

  for (t = 0; t < _PB_NITER; t++)
    {
      for (j = 0; j <= _PB_MAXGRID - 1; j++)
	for (i = j; i <= _PB_MAXGRID - 1; i++)
	  for (cnt = 0; cnt <= _PB_LENGTH - 1; cnt++)
	    diff[j][i][cnt] = sum_tang[j][i];

      for (j = 0; j <= _PB_MAXGRID - 1; j++)
        {
	  for (i = j; i <= _PB_MAXGRID - 1; i++)
            {
	      sum_diff[j][i][0] = diff[j][i][0];
	      for (cnt = 1; cnt <= _PB_LENGTH - 1; cnt++)
		sum_diff[j][i][cnt] = sum_diff[j][i][cnt - 1] + diff[j][i][cnt];
	      mean[j][i] = sum_diff[j][i][_PB_LENGTH - 1];
            }
        }

      for (i = 0; i <= _PB_MAXGRID - 1; i++)
	path[0][i] = mean[0][i];

      for (j = 1; j <= _PB_MAXGRID - 1; j++)
	for (i = j; i <= _PB_MAXGRID - 1; i++)
	  path[j][i] = path[j - 1][i - 1] + mean[j][i];
    }
}

/* Return 0 when one of the elements of arrays A and B do not match within the
   allowed FP_ABSTOLERANCE.  Return 1 when all elements match.  */
static inline int
check_FP(int maxgrid,
         DATA_TYPE POLYBENCH_2D(A,MAXGRID,MAXGRID,maxgrid,maxgrid),
         DATA_TYPE POLYBENCH_2D(B,MAXGRID,MAXGRID,maxgrid,maxgrid)) {
  int i, j;
  double AbsTolerance = FP_ABSTOLERANCE;
  for (i = 0; i < _PB_MAXGRID; i++)
    for (j = 0; j < _PB_MAXGRID; j++)
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
  int niter = NITER;
  int maxgrid = MAXGRID;
  int length = LENGTH;

  /* Variable declaration/allocation. */
  POLYBENCH_2D_ARRAY_DECL(sum_tang, DATA_TYPE, MAXGRID, MAXGRID, maxgrid, maxgrid);
  POLYBENCH_2D_ARRAY_DECL(mean, DATA_TYPE, MAXGRID, MAXGRID, maxgrid, maxgrid);
  POLYBENCH_2D_ARRAY_DECL(path, DATA_TYPE, MAXGRID, MAXGRID, maxgrid, maxgrid);
  POLYBENCH_2D_ARRAY_DECL(path_StrictFP, DATA_TYPE, MAXGRID, MAXGRID, maxgrid, maxgrid);
  POLYBENCH_3D_ARRAY_DECL(diff, DATA_TYPE, MAXGRID, MAXGRID, LENGTH, maxgrid, maxgrid, length);
  POLYBENCH_3D_ARRAY_DECL(sum_diff, DATA_TYPE, MAXGRID, MAXGRID, LENGTH, maxgrid, maxgrid, length);

  /* Initialize array(s). */
  init_array (maxgrid,
	      POLYBENCH_ARRAY(sum_tang),
	      POLYBENCH_ARRAY(mean),
	      POLYBENCH_ARRAY(path));

  /* Start timer. */
  polybench_start_instruments;

  /* Run kernel. */
  kernel_reg_detect (niter, maxgrid, length,
		     POLYBENCH_ARRAY(sum_tang),
		     POLYBENCH_ARRAY(mean),
		     POLYBENCH_ARRAY(path),
		     POLYBENCH_ARRAY(diff),
		     POLYBENCH_ARRAY(sum_diff));

  /* Stop and print timer. */
  polybench_stop_instruments;
  polybench_print_instruments;

  init_array (maxgrid,
	      POLYBENCH_ARRAY(sum_tang),
	      POLYBENCH_ARRAY(mean),
	      POLYBENCH_ARRAY(path_StrictFP));
  kernel_reg_detect_StrictFP(niter, maxgrid, length,
                             POLYBENCH_ARRAY(sum_tang),
                             POLYBENCH_ARRAY(mean),
                             POLYBENCH_ARRAY(path_StrictFP),
                             POLYBENCH_ARRAY(diff),
                             POLYBENCH_ARRAY(sum_diff));
  if (!check_FP(maxgrid, POLYBENCH_ARRAY(path), POLYBENCH_ARRAY(path_StrictFP)))
    return 1;

  /* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  polybench_prevent_dce(print_array(maxgrid, POLYBENCH_ARRAY(path_StrictFP)));

  /* Be clean. */
  POLYBENCH_FREE_ARRAY(sum_tang);
  POLYBENCH_FREE_ARRAY(mean);
  POLYBENCH_FREE_ARRAY(path);
  POLYBENCH_FREE_ARRAY(path_StrictFP);
  POLYBENCH_FREE_ARRAY(diff);
  POLYBENCH_FREE_ARRAY(sum_diff);

  return 0;
}
