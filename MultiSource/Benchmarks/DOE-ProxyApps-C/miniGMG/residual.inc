//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
void residual(domain_type * domain, int level,  int res_id, int phi_id, int rhs_id, double a, double b){
  // exchange the boundary for x in prep for Ax...
  // for 7-point stencil, only needs to be a 1-deep ghost zone & faces only
  exchange_boundary(domain,level,phi_id,1,0,0); 

  // now do residual/restriction proper...
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
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double h2inv = 1.0/(domain->h[level]*domain->h[level]);
    double * __restrict__ phi    = domain->subdomains[box].levels[level].grids[  phi_id] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double * __restrict__ rhs    = domain->subdomains[box].levels[level].grids[  rhs_id] + ghosts*(1+pencil+plane);
    double * __restrict__ alpha  = domain->subdomains[box].levels[level].grids[__alpha ] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_i = domain->subdomains[box].levels[level].grids[__beta_i] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_j = domain->subdomains[box].levels[level].grids[__beta_j] + ghosts*(1+pencil+plane);
    double * __restrict__ beta_k = domain->subdomains[box].levels[level].grids[__beta_k] + ghosts*(1+pencil+plane);
    double * __restrict__ res    = domain->subdomains[box].levels[level].grids[  res_id] + ghosts*(1+pencil+plane);

    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      double helmholtz =  a*alpha[ijk]*phi[ijk]
                         -b*h2inv*(
                            beta_i[ijk+1     ]*( phi[ijk+1     ]-phi[ijk       ] )
                           -beta_i[ijk       ]*( phi[ijk       ]-phi[ijk-1     ] )
                           +beta_j[ijk+pencil]*( phi[ijk+pencil]-phi[ijk       ] )
                           -beta_j[ijk       ]*( phi[ijk       ]-phi[ijk-pencil] )
                           +beta_k[ijk+plane ]*( phi[ijk+plane ]-phi[ijk       ] )
                           -beta_k[ijk       ]*( phi[ijk       ]-phi[ijk-plane ] )
                          );
      res[ijk] = rhs[ijk]-helmholtz;
    }}}
  }
#endif
  domain->cycles.residual[level] += (uint64_t)(CycleTime()-_timeStart);
}

#if 1
//------------------------------------------------------------------------------------------------------------------------------
// This version maximizes parallelism by parallelizing over the resultant coarse grid.  
// Thus, 
//  one parallelizes over the list of 2x2 fine-grid bars,
//  initializes a coarse grid pencil to zero, 
//  additively restricts each pencil in the 2x2 fine-grid bar to the coarse grid pencil
//------------------------------------------------------------------------------------------------------------------------------
void residual_and_restriction(domain_type *domain, int level_f, int phi_id, int rhs_id, int level_c, int res_id, double a, double b){
  // exchange the boundary for x in prep for Ax...
  // for 7-point stencil, only needs to be a 1-deep ghost zone & faces only
  exchange_boundary(domain,level_f,phi_id,1,0,0); 

  // now do residual/restriction proper...
  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_f].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_f].dim.i >= CollaborativeThreadingBoxSize);
  int box;
#ifdef OMP
  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int kk,jj;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int  dim_k_c = domain->subdomains[box].levels[level_c].dim.k;
    int  dim_j_c = domain->subdomains[box].levels[level_c].dim.j;
    int  dim_i_c = domain->subdomains[box].levels[level_c].dim.i;

    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int  dim_k_f = domain->subdomains[box].levels[level_f].dim.k;
    int  dim_j_f = domain->subdomains[box].levels[level_f].dim.j;
    int  dim_i_f = domain->subdomains[box].levels[level_f].dim.i;

    double h2inv = 1.0/(domain->h[level_f]*domain->h[level_f]);
    double * __restrict__ phi    = domain->subdomains[box].levels[level_f].grids[  phi_id] + ghosts_f*(1+pencil_f+plane_f); // i.e. [0] = first non ghost zone point
    double * __restrict__ rhs    = domain->subdomains[box].levels[level_f].grids[  rhs_id] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ alpha  = domain->subdomains[box].levels[level_f].grids[__alpha ] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_i = domain->subdomains[box].levels[level_f].grids[__beta_i] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_j = domain->subdomains[box].levels[level_f].grids[__beta_j] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_k = domain->subdomains[box].levels[level_f].grids[__beta_k] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ res    = domain->subdomains[box].levels[level_c].grids[  res_id] + ghosts_c*(1+pencil_c+plane_c);

    #pragma omp parallel for private(kk,jj) if(omp_within_a_box) collapse(2)
    for(kk=0;kk<dim_k_f;kk+=2){
    for(jj=0;jj<dim_j_f;jj+=2){
      int i,j,k;
      for(i=0;i<dim_i_c;i++){
        int ijk_c = (i) + (jj>>1)*pencil_c + (kk>>1)*plane_c;
        res[ijk_c] = 0.0;
      }
      for(k=kk;k<kk+2;k++){
      for(j=jj;j<jj+2;j++){
      for(i=0;i<dim_i_f;i++){
        int ijk_f = (i   ) + (j   )*pencil_f + (k   )*plane_f;
        int ijk_c = (i>>1) + (j>>1)*pencil_c + (k>>1)*plane_c;
        double helmholtz =  a*alpha[ijk_f]*phi[ijk_f]
                           -b*h2inv*(
                              beta_i[ijk_f+1       ]*( phi[ijk_f+1       ]-phi[ijk_f         ] )
                             -beta_i[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-1       ] )
                             +beta_j[ijk_f+pencil_f]*( phi[ijk_f+pencil_f]-phi[ijk_f         ] )
                             -beta_j[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-pencil_f] )
                             +beta_k[ijk_f+plane_f ]*( phi[ijk_f+plane_f ]-phi[ijk_f         ] )
                             -beta_k[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-plane_f ] )
                            );
        res[ijk_c] += (rhs[ijk_f]-helmholtz)*0.125;
      }
    }}}}
  }
#endif
  domain->cycles.residual[level_f] += (uint64_t)(CycleTime()-_timeStart);
}
#else
//------------------------------------------------------------------------------------------------------------------------------
// This version performs a 1D parallelization over the coarse-grid k-dimension (every two fine-grid planes)
// It first zeros the coarse grid plane, then increments with restrictions from the fine grid
//------------------------------------------------------------------------------------------------------------------------------
void residual_and_restriction(domain_type *domain, int level_f, int phi_id, int rhs_id, int level_c, int res_id, double a, double b){
  // exchange the boundary for x in prep for Ax...
  // for 7-point stencil, only needs to be a 1-deep ghost zone & faces only
  exchange_boundary(domain,level_f,phi_id,1,0,0); 

  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_f].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_f].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int  dim_k_c = domain->subdomains[box].levels[level_c].dim.k;
    int  dim_j_c = domain->subdomains[box].levels[level_c].dim.j;
    int  dim_i_c = domain->subdomains[box].levels[level_c].dim.i;

    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int  dim_k_f = domain->subdomains[box].levels[level_f].dim.k;
    int  dim_j_f = domain->subdomains[box].levels[level_f].dim.j;
    int  dim_i_f = domain->subdomains[box].levels[level_f].dim.i;

    double h2inv = 1.0/(domain->h[level_f]*domain->h[level_f]);
    double * __restrict__ phi    = domain->subdomains[box].levels[level_f].grids[  phi_id] + ghosts_f*(1+pencil_f+plane_f); // i.e. [0] = first non ghost zone point
    double * __restrict__ rhs    = domain->subdomains[box].levels[level_f].grids[  rhs_id] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ alpha  = domain->subdomains[box].levels[level_f].grids[__alpha ] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_i = domain->subdomains[box].levels[level_f].grids[__beta_i] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_j = domain->subdomains[box].levels[level_f].grids[__beta_j] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ beta_k = domain->subdomains[box].levels[level_f].grids[__beta_k] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ res    = domain->subdomains[box].levels[level_c].grids[  res_id] + ghosts_c*(1+pencil_c+plane_c);

    int kk;
    #pragma omp parallel for private(kk) if(omp_within_a_box)
    for(kk=0;kk<dim_k_f;kk+=2){
      int i,j,k; 
      // zero out the next coarse grid plane
      for(j=0;j<dim_j_c;j++){
      for(i=0;i<dim_i_c;i++){
          int ijk_c = (i) + (j)*pencil_c + (kk>>1)*plane_c;
          res[ijk_c] = 0.0;
      }}
      // restrict two fine grid planes into one coarse grid plane
      for(k=kk;k<kk+2;k++){
      for(j=0;j<dim_j_f;j++){
      for(i=0;i<dim_i_f;i++){
        int ijk_f = (i   ) + (j   )*pencil_f + (k   )*plane_f;
        int ijk_c = (i>>1) + (j>>1)*pencil_c + (k>>1)*plane_c;
        double helmholtz =  a*alpha[ijk_f]*phi[ijk_f]
                           -b*h2inv*(
                              beta_i[ijk_f+1       ]*( phi[ijk_f+1       ]-phi[ijk_f         ] )
                             -beta_i[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-1       ] )
                             +beta_j[ijk_f+pencil_f]*( phi[ijk_f+pencil_f]-phi[ijk_f         ] )
                             -beta_j[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-pencil_f] )
                             +beta_k[ijk_f+plane_f ]*( phi[ijk_f+plane_f ]-phi[ijk_f         ] )
                             -beta_k[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-plane_f ] )
                            );
        res[ijk_c] += (rhs[ijk_f]-helmholtz)*0.125;
      }}}
    }
  }
  domain->cycles.residual[level_f] += (uint64_t)(CycleTime()-_timeStart);
}
#endif
//------------------------------------------------------------------------------------------------------------------------------
