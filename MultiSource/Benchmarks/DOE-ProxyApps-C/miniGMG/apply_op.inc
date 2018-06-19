//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include "timer.h"
#include "mg.h"
#include "box.h"

void apply_op(domain_type * domain, int level, int Ax_id, int x_id, double a, double b){  // y=Ax or y=D^{-1}Ax = lambda[]Ax
  // exchange the boundary of x in preparation for Ax
  // note, Ax (one power) with a 7-point stencil requires only the faces
  exchange_boundary(domain,level,x_id,1,0,0);

  // now do Ax proper...
  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);
  int box;

#ifdef OMP
  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k,s;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double h2inv = 1.0/(domain->h[level]*domain->h[level]);
    double * __restrict__ x      = domain->subdomains[box].levels[level].grids[     x_id] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double * __restrict__ Ax     = domain->subdomains[box].levels[level].grids[    Ax_id] + ghosts*(1+pencil+plane); 
    double * __restrict__ alpha  = domain->subdomains[box].levels[level].grids[ __alpha ] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_i = domain->subdomains[box].levels[level].grids[ __beta_i] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_j = domain->subdomains[box].levels[level].grids[ __beta_j] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_k = domain->subdomains[box].levels[level].grids[ __beta_k] + ghosts*(1+pencil+plane);
    double * __restrict__ lambda = domain->subdomains[box].levels[level].grids[ __lambda] + ghosts*(1+pencil+plane);

    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      double helmholtz =  a*alpha[ijk]*x[ijk] - b*h2inv*(
                             beta_i[ijk+1     ]*( x[ijk+1     ]-x[ijk       ] )
                            -beta_i[ijk       ]*( x[ijk       ]-x[ijk-1     ] )
                            +beta_j[ijk+pencil]*( x[ijk+pencil]-x[ijk       ] )
                            -beta_j[ijk       ]*( x[ijk       ]-x[ijk-pencil] )
                            +beta_k[ijk+plane ]*( x[ijk+plane ]-x[ijk       ] )
                            -beta_k[ijk       ]*( x[ijk       ]-x[ijk-plane ] )
                          );
      Ax[ijk] = helmholtz;
    }}}
  }
#endif
  domain->cycles.apply_op[level] += (uint64_t)(CycleTime()-_timeStart);
}
//------------------------------------------------------------------------------------------------------------------------------
