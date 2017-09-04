//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
void matmul_grids(domain_type * domain, int level, double *C, int * id_A, int * id_B, int rows, int cols, int A_equals_B_transpose){
  // *id_A = m grid_id's (conceptually pointers to the rows    of a m x domain->subdomains_per_rank*volume matrix)
  // *id_B = n grid_id's (conceptually pointers to the columns of a domain->subdomains_per_rank*volume matrix x n)
  // *C is a mxn matrix where C[rows][cols] = dot(id_A[rows],id_B[cols])

  // FIX, id_A and id_B are likely the same and thus C[][] will be symmetric (modulo missing row?)
  // if(A_equals_B_transpose && (cols>=rows)) then use id_B and only run for nn>=mm // common case for s-step Krylov methods
  // C_is_symmetric && cols< rows (use id_A)
  int omp_across_matrix = 1;
  int omp_within_a_box  = 0;
  int mm,nn;


  uint64_t _timeStart = CycleTime();
  #pragma omp parallel for private(mm,nn) if(omp_across_matrix) collapse(2) schedule(static,1)
  for(mm=0;mm<rows;mm++){
  for(nn=0;nn<cols;nn++){
  if(nn>=mm){ // upper triangular
    int box;
    double a_dot_b_domain =  0.0;
    for(box=0;box<domain->subdomains_per_rank;box++){
      int i,j,k;
      int pencil = domain->subdomains[box].levels[level].pencil;
      int  plane = domain->subdomains[box].levels[level].plane;
      int ghosts = domain->subdomains[box].levels[level].ghosts;
      int  dim_k = domain->subdomains[box].levels[level].dim.k;
      int  dim_j = domain->subdomains[box].levels[level].dim.j;
      int  dim_i = domain->subdomains[box].levels[level].dim.i;
      double * __restrict__ grid_a = domain->subdomains[box].levels[level].grids[id_A[mm]] + ghosts*(1+pencil+plane); // i.e. [0] = first non ghost zone point
      double * __restrict__ grid_b = domain->subdomains[box].levels[level].grids[id_B[nn]] + ghosts*(1+pencil+plane); 
      double a_dot_b_box = 0.0;
      #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2) reduction(+:a_dot_b_box)
      for(k=0;k<dim_k;k++){
      for(j=0;j<dim_j;j++){
      for(i=0;i<dim_i;i++){
        int ijk = i + j*pencil + k*plane;
        a_dot_b_box += grid_a[ijk]*grid_b[ijk];
      }}}
      a_dot_b_domain+=a_dot_b_box;
    }
                             C[mm*cols + nn] = a_dot_b_domain; // C[mm][nn]
    if((mm<cols)&&(nn<rows)){C[nn*cols + mm] = a_dot_b_domain;}// C[nn][mm] 
  }
  }}
  domain->cycles.blas3[level] += (uint64_t)(CycleTime()-_timeStart);

  #ifdef __MPI
  double *send_buffer = (double*)malloc(rows*cols*sizeof(double));
  for(mm=0;mm<rows;mm++){
  for(nn=0;nn<cols;nn++){
    send_buffer[mm*cols + nn] = C[mm*cols + nn];
  }}
  uint64_t _timeStartAllReduce = CycleTime();
  MPI_Allreduce(send_buffer,C,rows*cols,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
  uint64_t _timeEndAllReduce = CycleTime();
  domain->cycles.collectives[level]   += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  domain->cycles.communication[level] += (uint64_t)(_timeEndAllReduce-_timeStartAllReduce);
  free(send_buffer);
  #endif

}

