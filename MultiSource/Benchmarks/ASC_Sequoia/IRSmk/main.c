/*BHEADER****************************************************************
 * (c) 2006   The Regents of the University of California               *
 *                                                                      *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright       *
 * notice and disclaimer.                                               *
 *                                                                      *
 *EHEADER****************************************************************/


//--------------
//  A micro kernel based on IRS
//    http://www.llnl.gov/asci/purple/benchmarks/limited/irs/
//--------------


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "irsmk.h"


void allocMem(RadiationData_t *);
void init(Domain_t *, RadiationData_t *, double *, double *);
void readInput();
void rmatmult3(Domain_t *, RadiationData_t *, double *, double *);


int main()
{
  Domain_t domain;
  Domain_t *domain_ptr = &domain;

  RadiationData_t rblk;
  RadiationData_t *rblk_ptr = &rblk;

  struct timeval  t0, t1;
  clock_t t0_cpu = 0,
          t1_cpu = 0;

  double del_wtime = 0.0;
  double *x;
  double *b;

  int i = 0;
  const int noIter = 5000;

  printf ("\nSequoia Benchmark Version 1.0\n\n");

  // 
  readInput();

  b = (double *)malloc(i_ub*sizeof(double));
  x = (double *)malloc(x_size*sizeof(double));
  
  allocMem(rblk_ptr);

  init(domain_ptr, rblk_ptr, x, b);

  gettimeofday(&t0, ((void *)0));
  t0_cpu = clock();
  for (i=0; i<noIter; ++i) {
     rmatmult3(domain_ptr, rblk_ptr, x, b);
  }
  gettimeofday(&t1, ((void *)0)); 
  t1_cpu = clock();

  printf("***** results \n");  
  for (i=0; i<i_ub; i+=i_ub/5) {
    printf("i = %10d      b[i] = %e \n", i, b[i]);
  }

  del_wtime = (double)(t1.tv_sec - t0.tv_sec) +
              (double)(t1.tv_usec - t0.tv_usec)/1000000.0;

}
