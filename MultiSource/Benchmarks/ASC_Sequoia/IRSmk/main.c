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

  for (i=0; i<noIter; ++i) {
     rmatmult3(domain_ptr, rblk_ptr, x, b);
  }

  printf("***** results \n");  
  for (i=0; i<i_ub; i+=i_ub/5) {
    printf("i = %10d      b[i] = %e \n", i, b[i]);
  }

  return(0);
}
