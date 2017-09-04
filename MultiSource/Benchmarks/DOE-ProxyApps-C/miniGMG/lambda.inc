//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include <stdio.h>
#include "timer.h"
#include "mg.h"
#include "defines.h"
//------------------------------------------------------------------------------------------------------------------------------
void rebuild_lambda(domain_type * domain, int level, double a, double b){
  uint64_t _timeStart = CycleTime();

  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  double dominant_eigenvalue = -1.0;
  #pragma omp parallel for private(box) if(omp_across_boxes) reduction(max:dominant_eigenvalue)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double h2inv = 1.0/(domain->h[level]*domain->h[level]);
    double * __restrict__ alpha  = domain->subdomains[box].levels[level].grids[__alpha ] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_i = domain->subdomains[box].levels[level].grids[__beta_i] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_j = domain->subdomains[box].levels[level].grids[__beta_j] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_k = domain->subdomains[box].levels[level].grids[__beta_k] + ghosts*(1+pencil+plane);
    double * __restrict__ lambda = domain->subdomains[box].levels[level].grids[__lambda] + ghosts*(1+pencil+plane);
    double box_eigenvalue = -1.0;
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2) reduction(max:box_eigenvalue)
    for(k=0;k<dim_k;k++){
     for(j=0;j<dim_j;j++){
      for(i=0;i<dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        // radius of Gershgorin disc is the sum of the absolute values of the off-diagonal elements...
        double sumAij = fabs(b*h2inv*beta_i[ijk]) + fabs(b*h2inv*beta_i[ijk+     1]) +
                        fabs(b*h2inv*beta_j[ijk]) + fabs(b*h2inv*beta_j[ijk+pencil]) +
                        fabs(b*h2inv*beta_k[ijk]) + fabs(b*h2inv*beta_k[ijk+ plane]);
        // centr of Gershgorin disc is the diagonal element...
        double    Aii = a*alpha[ijk] - b*h2inv*( -beta_i[ijk]-beta_i[ijk+     1] 
                                                 -beta_j[ijk]-beta_j[ijk+pencil] 
                                                 -beta_k[ijk]-beta_k[ijk+ plane] );
        lambda[ijk] = 1.0/Aii; // inverse of the diagonal Aii
        double Di = (Aii + sumAij)/Aii;if(Di>box_eigenvalue)box_eigenvalue=Di; // upper limit to Gershgorin disc == bound on dominant eigenvalue
    }}}
    if(box_eigenvalue>dominant_eigenvalue){dominant_eigenvalue = box_eigenvalue;}
  }
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);

  #ifdef __MPI
  uint64_t _timeStartAllReduce = CycleTime();
  double send = dominant_eigenvalue;
  MPI_Allreduce(&send,&dominant_eigenvalue,1,MPI_DOUBLE,MPI_MAX,MPI_COMM_WORLD);
  uint64_t _timeEndAllReduce = CycleTime();
  domain->cycles.collectives[level]   += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  domain->cycles.communication[level] += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  #endif

  if(domain->rank==0){if(level==0)printf("\n");printf("  level=%2d, eigenvalue_max ~= %e\n",level,dominant_eigenvalue);fflush(stdout);}
  domain->dominant_eigenvalue_of_DinvA[level] = dominant_eigenvalue;
}


