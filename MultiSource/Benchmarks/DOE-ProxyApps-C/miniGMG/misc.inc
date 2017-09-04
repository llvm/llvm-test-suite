//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
void zero_grid(domain_type *domain, int level, int grid_id){
  // zero's the entire grid INCLUDING ghost zones...
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
    double * __restrict__ grid = domain->subdomains[box].levels[level].grids[grid_id] + ghosts*(1+pencil+plane);
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=-ghosts;k<dim_k+ghosts;k++){
     for(j=-ghosts;j<dim_j+ghosts;j++){
      for(i=-ghosts;i<dim_i+ghosts;i++){
        int ijk = i + j*pencil + k*plane;
        grid[ijk] = 0.0;
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}



//------------------------------------------------------------------------------------------------------------------------------
void initialize_grid_to_scalar(domain_type *domain, int level, int grid_id, double scalar){
  // initializes the grid to a scalar while zero'ing the ghost zones...
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
    double * __restrict__ grid = domain->subdomains[box].levels[level].grids[grid_id] + ghosts*(1+pencil+plane);
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=-ghosts;k<dim_k+ghosts;k++){
     for(j=-ghosts;j<dim_j+ghosts;j++){
      for(i=-ghosts;i<dim_i+ghosts;i++){
        int ijk = i + j*pencil + k*plane;
        int ghostZone = (i<0) || (j<0) || (k<0) || (i>=dim_i) || (j>=dim_j) || (k>=dim_k);
        grid[ijk] = ghostZone ? 0.0 : scalar;
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}


//------------------------------------------------------------------------------------------------------------------------------
void add_grids(domain_type *domain, int level, int id_c, double scale_a, int id_a, double scale_b, int id_b){ // c=scale_a*id_a + scale_b*id_b
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
    double * __restrict__ grid_c = domain->subdomains[box].levels[level].grids[id_c] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_b = domain->subdomains[box].levels[level].grids[id_b] + ghosts*(1+pencil+plane);
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
     for(j=0;j<dim_j;j++){
      for(i=0;i<dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        grid_c[ijk] = scale_a*grid_a[ijk] + scale_b*grid_b[ijk];
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}


//------------------------------------------------------------------------------------------------------------------------------
void mul_grids(domain_type *domain, int level, int id_c, double scale, int id_a, int id_b){ // id_c=scale*id_a*id_b
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
    double * __restrict__ grid_c = domain->subdomains[box].levels[level].grids[id_c] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_b = domain->subdomains[box].levels[level].grids[id_b] + ghosts*(1+pencil+plane);
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
     for(j=0;j<dim_j;j++){
      for(i=0;i<dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        grid_c[ijk] = scale*grid_a[ijk]*grid_b[ijk];
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}



//------------------------------------------------------------------------------------------------------------------------------
void scale_grid(domain_type *domain, int level, int id_c, double scale_a, int id_a){ // c[]=scale_a*a[]
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
    double * __restrict__ grid_c = domain->subdomains[box].levels[level].grids[id_c] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane);
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
     for(j=0;j<dim_j;j++){
      for(i=0;i<dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        grid_c[ijk] = scale_a*grid_a[ijk];
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}


//------------------------------------------------------------------------------------------------------------------------------
double dot(domain_type *domain, int level, int id_a, int id_b){
  uint64_t _timeStart = CycleTime();

  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);

  int box;
  double a_dot_b_domain =  0.0;
#ifdef OMP
  // FIX, schedule(static) is a stand in to guarantee reproducibility...
  #pragma omp parallel for private(box) if(omp_across_boxes) reduction(+:a_dot_b_domain) schedule(static)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double * __restrict__ grid_b = domain->subdomains[box].levels[level].grids[id_b] + ghosts*(1+pencil+plane);
    double a_dot_b_box = 0.0;
    #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2) reduction(+:a_dot_b_box) schedule(static)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      a_dot_b_box += grid_a[ijk]*grid_b[ijk];
    }}}
    a_dot_b_domain+=a_dot_b_box;
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);

  #ifdef __MPI
  uint64_t _timeStartAllReduce = CycleTime();
  double send = a_dot_b_domain;
  MPI_Allreduce(&send,&a_dot_b_domain,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
  uint64_t _timeEndAllReduce = CycleTime();
  domain->cycles.collectives[level]   += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  domain->cycles.communication[level] += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  #endif

  return(a_dot_b_domain);
}

//------------------------------------------------------------------------------------------------------------------------------
double norm(domain_type *domain, int level, int grid_id){ // implements the max norm
  uint64_t _timeStart = CycleTime();
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);

  int box;
  double max_norm =  0.0;
#ifdef OMP
  // FIX, schedule(static) is a stand in to guarantee reproducibility...
  #pragma omp parallel for private(box) if(omp_across_boxes) reduction(max:max_norm) schedule(static)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double * __restrict__ grid   = domain->subdomains[box].levels[level].grids[ grid_id] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double box_norm = 0.0;
    #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2) reduction(max:box_norm) schedule(static)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      double fabs_grid_ijk = fabs(grid[ijk]);
      if(fabs_grid_ijk>box_norm){box_norm=fabs_grid_ijk;} // max norm
    }}}
    if(box_norm>max_norm){max_norm = box_norm;}
  } // box list
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);

  #ifdef __MPI
  uint64_t _timeStartAllReduce = CycleTime();
  double send = max_norm;
  MPI_Allreduce(&send,&max_norm,1,MPI_DOUBLE,MPI_MAX,MPI_COMM_WORLD);
  uint64_t _timeEndAllReduce = CycleTime();
  domain->cycles.collectives[level]   += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  domain->cycles.communication[level] += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  #endif
  return(max_norm);
}


//------------------------------------------------------------------------------------------------------------------------------
double mean(domain_type *domain, int level, int id_a){
  uint64_t _timeStart = CycleTime();

  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);

  int box;
  double sum_domain =  0.0;
#ifdef OMP
  #pragma omp parallel for private(box) if(omp_across_boxes) reduction(+:sum_domain)
  for(box=0;box<domain->subdomains_per_rank;box++){
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double sum_box = 0.0;
    #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2) reduction(+:sum_box)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      sum_box += grid_a[ijk];
    }}}
    sum_domain+=sum_box;
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
  double ncells_domain = (double)domain->dim.i*(double)domain->dim.j*(double)domain->dim.k;

  #ifdef __MPI
  uint64_t _timeStartAllReduce = CycleTime();
  double send = sum_domain;
  MPI_Allreduce(&send,&sum_domain,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
  uint64_t _timeEndAllReduce = CycleTime();
  domain->cycles.collectives[level]   += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  domain->cycles.communication[level] += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  #endif

  double mean_domain = sum_domain / ncells_domain;
  return(mean_domain);
}


void shift_grid(domain_type *domain, int level, int id_c, int id_a, double shift_a){
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
    double * __restrict__ grid_c = domain->subdomains[box].levels[level].grids[id_c] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
    double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_a] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point

    #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      grid_c[ijk] = grid_a[ijk] + shift_a;
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}

//------------------------------------------------------------------------------------------------------------------------------
void project_cell_to_face(domain_type *domain, int level, int id_cell, int id_face, int dir){
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
    double * __restrict__ grid_cell = domain->subdomains[box].levels[level].grids[id_cell] + ghosts*(1+pencil+plane);
    double * __restrict__ grid_face = domain->subdomains[box].levels[level].grids[id_face] + ghosts*(1+pencil+plane);
    int stride;
    switch(dir){
      case 0: stride =      1;break;//i-direction
      case 1: stride = pencil;break;//j-direction
      case 2: stride =  plane;break;//k-direction
    }
    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<=dim_k;k++){ // <= to ensure you do low and high faces
     for(j=0;j<=dim_j;j++){
      for(i=0;i<=dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        grid_face[ijk] = 0.5*(grid_cell[ijk-stride] + grid_cell[ijk]); // simple linear interpolation
    }}}
  }
#endif
  domain->cycles.blas1[level] += (uint64_t)(CycleTime()-_timeStart);
}
