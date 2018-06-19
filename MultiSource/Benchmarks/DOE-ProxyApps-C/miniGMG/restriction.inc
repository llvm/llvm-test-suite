//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
// id_c^2h = R id_f^h
// restriction of cell-centered data...
//------------------------------------------------------------------------------------------------------------------------------
void restriction(domain_type *domain, int level_f, int id_c, int id_f){
  int level_c = level_f+1;
  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_c].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_c].dim.i >= CollaborativeThreadingBoxSize);
  int box;
#ifdef OMP
  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int  dim_i_c = domain->subdomains[box].levels[level_c].dim.i;
    int  dim_j_c = domain->subdomains[box].levels[level_c].dim.j;
    int  dim_k_c = domain->subdomains[box].levels[level_c].dim.k;
  
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
  
    double * __restrict__ grid_f = domain->subdomains[box].levels[level_f].grids[id_f] + ghosts_f*(1+pencil_f+plane_f);
    double * __restrict__ grid_c = domain->subdomains[box].levels[level_c].grids[id_c] + ghosts_c*(1+pencil_c+plane_c);
  
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_c;k++){
    for(j=0;j<dim_j_c;j++){
    for(i=0;i<dim_i_c;i++){
      int ijk_c = (i   ) + (j   )*pencil_c + (k   )*plane_c;
      int ijk_f = (i<<1) + (j<<1)*pencil_f + (k<<1)*plane_f;
      grid_c[ijk_c] = ( grid_f[ijk_f                   ]+grid_f[ijk_f+1                 ] +
                        grid_f[ijk_f  +pencil_f        ]+grid_f[ijk_f+1+pencil_f        ] +
                        grid_f[ijk_f           +plane_f]+grid_f[ijk_f+1         +plane_f] +
                        grid_f[ijk_f  +pencil_f+plane_f]+grid_f[ijk_f+1+pencil_f+plane_f] ) * 0.125;
    }}}
  }
#endif
  domain->cycles.restriction[level_f] += (uint64_t)(CycleTime()-_timeStart);
}



//------------------------------------------------------------------------------------------------------------------------------
// restriction of face-centered data...
//------------------------------------------------------------------------------------------------------------------------------
void restriction_betas(domain_type * domain, int level_f, int level_c){
  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_c].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_c].dim.i >= CollaborativeThreadingBoxSize);
  int box;

#ifdef OMP
  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int  dim_i_c = domain->subdomains[box].levels[level_c].dim.i;
    int  dim_j_c = domain->subdomains[box].levels[level_c].dim.j;
    int  dim_k_c = domain->subdomains[box].levels[level_c].dim.k;
  
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
  
    double * __restrict__ beta_f;
    double * __restrict__ beta_c;

    // restrict beta_i  (== face in jk)
    beta_f = domain->subdomains[box].levels[level_f].grids[__beta_i] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    beta_c = domain->subdomains[box].levels[level_c].grids[__beta_i] + ghosts_c*plane_c + ghosts_c*pencil_c + ghosts_c;
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_c;k++){
    for(j=0;j<dim_j_c;j++){
    for(i=0;i<dim_i_c;i++){
      int ijk_c = (i   ) + (j   )*pencil_c + (k   )*plane_c;
      int ijk_f = (i<<1) + (j<<1)*pencil_f + (k<<1)*plane_f;
      beta_c[ijk_c] = ( beta_f[ijk_f        ]+beta_f[ijk_f+pencil_f        ] +
                        beta_f[ijk_f+plane_f]+beta_f[ijk_f+pencil_f+plane_f] ) * 0.25;
    }}}

    // restrict beta_j (== face in ik)
    beta_f = domain->subdomains[box].levels[level_f].grids[__beta_j] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    beta_c = domain->subdomains[box].levels[level_c].grids[__beta_j] + ghosts_c*plane_c + ghosts_c*pencil_c + ghosts_c;
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_c;k++){
    for(j=0;j<dim_j_c;j++){
    for(i=0;i<dim_i_c;i++){
      int ijk_c = (i   ) + (j   )*pencil_c + (k   )*plane_c;
      int ijk_f = (i<<1) + (j<<1)*pencil_f + (k<<1)*plane_f;
      beta_c[ijk_c] = ( beta_f[ijk_f        ]+beta_f[ijk_f+1        ] +
                        beta_f[ijk_f+plane_f]+beta_f[ijk_f+1+plane_f] ) * 0.25;
    }}}

    // restrict beta_k (== face in ij)
    beta_f = domain->subdomains[box].levels[level_f].grids[__beta_k] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    beta_c = domain->subdomains[box].levels[level_c].grids[__beta_k] + ghosts_c*plane_c + ghosts_c*pencil_c + ghosts_c;
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k_c;k++){
    for(j=0;j<dim_j_c;j++){
    for(i=0;i<dim_i_c;i++){
      int ijk_c = (i   ) + (j   )*pencil_c + (k   )*plane_c;
      int ijk_f = (i<<1) + (j<<1)*pencil_f + (k<<1)*plane_f;
      beta_c[ijk_c] = ( beta_f[ijk_f         ]+beta_f[ijk_f+1         ] +
                        beta_f[ijk_f+pencil_f]+beta_f[ijk_f+1+pencil_f] ) * 0.25;
    }}}
  }
#endif
  domain->cycles.restriction[level_f] += (uint64_t)(CycleTime()-_timeStart);
}
