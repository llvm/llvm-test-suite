//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//------------------------------------------------------------------------------------------------------------------------------
#ifdef __MPI
#include <mpi.h>
#endif
//------------------------------------------------------------------------------------------------------------------------------
#include "timer.h"
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"
#include "solver.h"
//------------------------------------------------------------------------------------------------------------------------------
int create_subdomain(subdomain_type * box, int subdomain_low_i, int subdomain_low_j, int subdomain_low_k,  
                                       int subdomain_dim_i, int subdomain_dim_j, int subdomain_dim_k, 
                                       int numGrids, int ghosts, int numLevels){
  int level;
  uint64_t memory_allocated=0;
  box->numLevels=numLevels;
  box->ghosts=ghosts;
  box->low.i = subdomain_low_i;
  box->low.j = subdomain_low_j;
  box->low.k = subdomain_low_k;
  box->dim.i = subdomain_dim_i;
  box->dim.j = subdomain_dim_j;
  box->dim.k = subdomain_dim_k;
  posix_memalign((void**)&(box->levels),64,numLevels*sizeof(box_type));
  memory_allocated += numLevels*sizeof(box_type);
  for(level=0;level<numLevels;level++){
                          int numGridsActual = numGrids;
    if(level == (numLevels-1))numGridsActual+= IterativeSolver_NumGrids(); // the bottom solver may need a few auxillary grids...
    memory_allocated += create_box(&box->levels[level],numGridsActual,subdomain_low_i>>level,subdomain_low_j>>level,subdomain_low_k>>level,
                                                                      subdomain_dim_i>>level,subdomain_dim_j>>level,subdomain_dim_k>>level,ghosts);
  }
  return(memory_allocated);
}


void destroy_subdomain(subdomain_type * box){
  int level;
  for(level=0;level<box->numLevels;level++){
    destroy_box(&box->levels[level]);
  }
  free(box->levels);
}


//------------------------------------------------------------------------------------------------------------------------------
int calculate_neighboring_subdomain_index(domain_type *domain, int bi, int bj, int bk, int di, int dj, int dk){
  int ni,nj,nk;
  ni=(bi+domain->subdomains_per_rank_in.i+di)%domain->subdomains_per_rank_in.i;
  nj=(bj+domain->subdomains_per_rank_in.j+dj)%domain->subdomains_per_rank_in.j;
  nk=(bk+domain->subdomains_per_rank_in.k+dk)%domain->subdomains_per_rank_in.k;
  int index = ni + nj*domain->subdomains_per_rank_in.i + nk*domain->subdomains_per_rank_in.i*domain->subdomains_per_rank_in.j;
  return(index);
}

int calculate_neighboring_subdomain_rank(domain_type * domain, int bi, int bj, int bk, int di, int dj, int dk, int ri, int rj, int rk){
  if( domain->boundary_condition.i != __BOUNDARY_PERIODIC){
    if( ((domain->subdomains_per_rank_in.i*ri)+bi+di) <                        0 )return(-1);
    if( ((domain->subdomains_per_rank_in.i*ri)+bi+di) >= domain->subdomains_in.i )return(-1);
  }
  if( domain->boundary_condition.j != __BOUNDARY_PERIODIC){
    if( ((domain->subdomains_per_rank_in.j*rj)+bj+dj) <                        0 )return(-1);
    if( ((domain->subdomains_per_rank_in.j*rj)+bj+dj) >= domain->subdomains_in.j )return(-1);
  }
  if( domain->boundary_condition.k != __BOUNDARY_PERIODIC){
    if( ((domain->subdomains_per_rank_in.k*rk)+bk+dk) <                        0 )return(-1);
    if( ((domain->subdomains_per_rank_in.k*rk)+bk+dk) >= domain->subdomains_in.k )return(-1);
  }
  // if didn't walk off domain, calculate new rank for periodic boundaries...
  if((bi+di)<0)ri--;if((bi+di)>=domain->subdomains_per_rank_in.i)ri++;ri=(ri+domain->ranks_in.i)%domain->ranks_in.i;
  if((bj+dj)<0)rj--;if((bj+dj)>=domain->subdomains_per_rank_in.j)rj++;rj=(rj+domain->ranks_in.j)%domain->ranks_in.j;
  if((bk+dk)<0)rk--;if((bk+dk)>=domain->subdomains_per_rank_in.k)rk++;rk=(rk+domain->ranks_in.k)%domain->ranks_in.k;
  int rank = ri + rj*domain->ranks_in.i + rk*domain->ranks_in.i*domain->ranks_in.j;
  return(rank);
}


//------------------------------------------------------------------------------------------------------------------------------
int create_domain(domain_type * domain, 
              int subdomain_dim_i,  int subdomain_dim_j,  int subdomain_dim_k,  
              int subdomains_per_rank_in_i, int subdomains_per_rank_in_j, int subdomains_per_rank_in_k, 
              int ranks_in_i,      int ranks_in_j,      int ranks_in_k, 
              int rank,
              int *boundary_conditions,
              int numGrids, int ghosts, int numLevels
             ){
  int level;
  int  i, j, k;
  int di,dj,dk;
  // FIX ghosts = array (varies with level)
  domain->rank = rank;
  if(domain->rank==0){printf("creating domain...       ");fflush(stdout);}
  //FIX, limit ghosts based on coarsest problem size
  if(ghosts>(subdomain_dim_i>>(numLevels-1))){if(domain->rank==0)printf("#ghosts(%d)>bottom grid size(%d)\n",ghosts,subdomain_dim_i>>(numLevels-1));exit(0);}

  if( (subdomain_dim_i!=subdomain_dim_j)||(subdomain_dim_j!=subdomain_dim_k)||(subdomain_dim_i!=subdomain_dim_k) ){
  if(domain->rank==0)printf("subdomain_dim's must be equal\n");exit(0);
  }
  uint64_t memory_allocated =0;
  // processes are laid out in x, then y, then z
  //int ranks = ranks_in_i*ranks_in_j*ranks_in_k;
  int my_k_rank = (rank                                                              ) / (ranks_in_i*ranks_in_j);
  int my_j_rank = (rank - (ranks_in_i*ranks_in_j*my_k_rank)                          ) / (ranks_in_i           );
  int my_i_rank = (rank - (ranks_in_i*ranks_in_j*my_k_rank) - (ranks_in_i*my_j_rank) );
  //printf("%2d: (%2d,%2d,%2d)\n",domain->rank,my_k_rank,my_j_rank,my_i_rank);


  domain->ranks_in.i               = ranks_in_i;
  domain->ranks_in.j               = ranks_in_j;
  domain->ranks_in.k               = ranks_in_k;
  domain->subdomains_per_rank_in.i = subdomains_per_rank_in_i;
  domain->subdomains_per_rank_in.j = subdomains_per_rank_in_j;
  domain->subdomains_per_rank_in.k = subdomains_per_rank_in_k;
  domain->subdomains_in.i          = subdomains_per_rank_in_i*ranks_in_i;
  domain->subdomains_in.j          = subdomains_per_rank_in_j*ranks_in_j;
  domain->subdomains_in.k          = subdomains_per_rank_in_k*ranks_in_k;
  domain->subdomains_per_rank      = subdomains_per_rank_in_i*subdomains_per_rank_in_j*subdomains_per_rank_in_k;
  posix_memalign((void**)&(domain->subdomains),64,domain->subdomains_per_rank*sizeof(subdomain_type));
  memory_allocated+=domain->subdomains_per_rank*sizeof(subdomain_type);

  domain->dim.i                = domain->subdomains_in.i * subdomain_dim_i;
  domain->dim.j                = domain->subdomains_in.j * subdomain_dim_j;
  domain->dim.k                = domain->subdomains_in.k * subdomain_dim_k;
  domain->boundary_condition.i = boundary_conditions[0];
  domain->boundary_condition.j = boundary_conditions[1];
  domain->boundary_condition.k = boundary_conditions[2];
  domain->numLevels            = numLevels;
  domain->numGrids             = numGrids;
  domain->ghosts               = ghosts;
  for(level=0;level<domain->numLevels;level++){
                               domain->h[level] = -1;
    domain->dominant_eigenvalue_of_DinvA[level] = -1;
  }

  // calculate the neighbors of this process
  for(dk=-1;dk<=1;dk++){
  for(dj=-1;dj<=1;dj++){
  for(di=-1;di<=1;di++){
    int n = 13+di+3*dj+9*dk;
    int neighbor_rank_in_i = (my_i_rank+di+ranks_in_i)%ranks_in_i;
    int neighbor_rank_in_j = (my_j_rank+dj+ranks_in_j)%ranks_in_j;
    int neighbor_rank_in_k = (my_k_rank+dk+ranks_in_k)%ranks_in_k;
    domain->rank_of_neighbor[n] = neighbor_rank_in_i + ranks_in_i*neighbor_rank_in_j + ranks_in_i*ranks_in_j*neighbor_rank_in_k;
    if( domain->boundary_condition.i != __BOUNDARY_PERIODIC){
      if( (my_i_rank+di) <           0 )domain->rank_of_neighbor[n] = -1;
      if( (my_i_rank+di) >= ranks_in_i )domain->rank_of_neighbor[n] = -1;
    }
    if( domain->boundary_condition.j != __BOUNDARY_PERIODIC){
      if( (my_j_rank+dj) <           0 )domain->rank_of_neighbor[n] = -1;
      if( (my_j_rank+dj) >= ranks_in_j )domain->rank_of_neighbor[n] = -1;
    }
    if( domain->boundary_condition.k != __BOUNDARY_PERIODIC){
      if( (my_k_rank+dk) <           0 )domain->rank_of_neighbor[n] = -1;
      if( (my_k_rank+dk) >= ranks_in_k )domain->rank_of_neighbor[n] = -1;
    }
  }}}

  // subdomains within a process are laid out in i, then j, then k
  for(k=0;k<subdomains_per_rank_in_k;k++){
  for(j=0;j<subdomains_per_rank_in_j;j++){
  for(i=0;i<subdomains_per_rank_in_i;i++){
    int box = i + j*subdomains_per_rank_in_i + k*subdomains_per_rank_in_i*subdomains_per_rank_in_j;
    int low_i = subdomain_dim_i * (i + subdomains_per_rank_in_i*my_i_rank);
    int low_j = subdomain_dim_j * (j + subdomains_per_rank_in_j*my_j_rank);
    int low_k = subdomain_dim_k * (k + subdomains_per_rank_in_k*my_k_rank);
    memory_allocated += create_subdomain(&domain->subdomains[box],low_i,low_j,low_k,subdomain_dim_i,subdomain_dim_j,subdomain_dim_k,numGrids,ghosts,numLevels);
    for(dk=-1;dk<=1;dk++){
    for(dj=-1;dj<=1;dj++){
    for(di=-1;di<=1;di++){
      int n = 13+di+3*dj+9*dk;
      domain->subdomains[box].neighbors[n].rank        = calculate_neighboring_subdomain_rank(domain,i,j,k,di,dj,dk,my_i_rank,my_j_rank,my_k_rank);
      domain->subdomains[box].neighbors[n].local_index = calculate_neighboring_subdomain_index(domain,i,j,k,di,dj,dk);
      // FIX boundary conditions??
      //printf("rank=%2d, box[%2d].neighbors[%3d]=(%3d,%3d)\n",domain->rank,box,n,domain->subdomains[box].neighbors[n].rank,domain->subdomains[box].neighbors[n].local_index);
    }}}
  }}}


  int FacesEdgesCorners[27] = {4,10,12,14,16,22,   1,3,5,7,9,11,15,17,19,21,23,25,   0,2,6,8,18,20,24,26,   13};
  int    faces[27] = {0,0,0,0,1,0,0,0,0,  0,1,0,1,0,1,0,1,0,  0,0,0,0,1,0,0,0,0};
  int    edges[27] = {0,1,0,1,0,1,0,1,0,  1,0,1,0,0,0,1,0,1,  0,1,0,1,0,1,0,1,0};
  int  corners[27] = {1,0,1,0,0,0,1,0,1,  0,0,0,0,0,0,0,0,0,  1,0,1,0,0,0,1,0,1};

  #ifdef __MPI
  // allocate MPI send/recv buffers for the 26 neighbors....
  for(dk=-1;dk<=1;dk++){
  for(dj=-1;dj<=1;dj++){
  for(di=-1;di<=1;di++){
    int n = 13+di+3*dj+9*dk;if(n!=13){
    int bufSize = 1;
    if(di==0)bufSize*=domain->subdomains_per_rank_in.i*subdomain_dim_i;else bufSize*=ghosts;
    if(dj==0)bufSize*=domain->subdomains_per_rank_in.j*subdomain_dim_j;else bufSize*=ghosts;
    if(dk==0)bufSize*=domain->subdomains_per_rank_in.k*subdomain_dim_k;else bufSize*=ghosts;
    posix_memalign((void**)&(domain->send_buffer[n]),64,bufSize*sizeof(double));
    posix_memalign((void**)&(domain->recv_buffer[n]),64,bufSize*sizeof(double));
                        memset(domain->send_buffer[n],0,bufSize*sizeof(double));
                        memset(domain->recv_buffer[n],0,bufSize*sizeof(double));
                                      memory_allocated+=bufSize*sizeof(double);
                                      memory_allocated+=bufSize*sizeof(double);
  }}}}
  #endif


  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // now enumerate a list of data transfers to effect a ghost zone exchange (boundary conditions are skipped)
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  for(level=0;level<domain->numLevels;level++){
    int initialize;for(initialize=0;initialize<2;initialize++){ // initialize=0=count/malloc.  initialize=1=initialize
    int buffer=0;
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // Traverse list of boxes, and create MPI pack for faces, edges, and corners
    domain->bufferCopy_Pack_Start=buffer;
    int nn;
    #ifdef __MPI
    for(nn=0;nn<26;nn++){
      int n = FacesEdgesCorners[nn];
      int di = ((n/1)%3) - 1;
      int dj = ((n/3)%3) - 1;
      int dk = ((n/9)%3) - 1;

      // traverse all boxes in direction di/dj/dk... (e.g. all subdomains on the corresponding face)
      int sd_i_lo,sd_i_hi;
      int sd_j_lo,sd_j_hi;
      int sd_k_lo,sd_k_hi;
      switch(di){
        case -1:sd_i_lo=                         0;sd_i_hi=                       1;break;
        case  0:sd_i_lo=                         0;sd_i_hi=subdomains_per_rank_in_i;break;
        case  1:sd_i_lo=subdomains_per_rank_in_i-1;sd_i_hi=subdomains_per_rank_in_i;break;
      };
      switch(dj){
        case -1:sd_j_lo=                         0;sd_j_hi=                       1;break;
        case  0:sd_j_lo=                         0;sd_j_hi=subdomains_per_rank_in_j;break;
        case  1:sd_j_lo=subdomains_per_rank_in_j-1;sd_j_hi=subdomains_per_rank_in_j;break;
      };
      switch(dk){
        case -1:sd_k_lo=                         0;sd_k_hi=                       1;break;
        case  0:sd_k_lo=                         0;sd_k_hi=subdomains_per_rank_in_k;break;
        case  1:sd_k_lo=subdomains_per_rank_in_k-1;sd_k_hi=subdomains_per_rank_in_k;break;
      };
      for(k=sd_k_lo;k<sd_k_hi;k++){
      for(j=sd_j_lo;j<sd_j_hi;j++){
      for(i=sd_i_lo;i<sd_i_hi;i++){
        int off_node_exchange=1;
        if(calculate_neighboring_subdomain_rank(domain,i,j,k, di,dj,dk, my_i_rank,my_j_rank,my_k_rank) == domain->rank)off_node_exchange=0; // same process
        if(calculate_neighboring_subdomain_rank(domain,i,j,k, di,dj,dk, my_i_rank,my_j_rank,my_k_rank) ==           -1)off_node_exchange=0; // domain boundary
        if(off_node_exchange){
          int sendBox = i + j*subdomains_per_rank_in_i + k*subdomains_per_rank_in_i*subdomains_per_rank_in_j;
          int grid_i,grid_j,grid_k; // ijk in the source grid (relative to first ghost zone element)
          int  dim_i, dim_j, dim_k; // dimensions of face/edge/corner
          switch(di){
            case -1:grid_i=domain->subdomains[sendBox].levels[level].ghosts;dim_i=domain->subdomains[sendBox].levels[level].ghosts;break;
            case  0:grid_i=domain->subdomains[sendBox].levels[level].ghosts;dim_i=domain->subdomains[sendBox].levels[level].dim.i; break;
            case  1:grid_i=domain->subdomains[sendBox].levels[level].dim.i; dim_i=domain->subdomains[sendBox].levels[level].ghosts;break;
          };
          switch(dj){
            case -1:grid_j=domain->subdomains[sendBox].levels[level].ghosts;dim_j=domain->subdomains[sendBox].levels[level].ghosts;break;
            case  0:grid_j=domain->subdomains[sendBox].levels[level].ghosts;dim_j=domain->subdomains[sendBox].levels[level].dim.j; break;
            case  1:grid_j=domain->subdomains[sendBox].levels[level].dim.j; dim_j=domain->subdomains[sendBox].levels[level].ghosts;break;
          };
          switch(dk){
            case -1:grid_k=domain->subdomains[sendBox].levels[level].ghosts;dim_k=domain->subdomains[sendBox].levels[level].ghosts;break;
            case  0:grid_k=domain->subdomains[sendBox].levels[level].ghosts;dim_k=domain->subdomains[sendBox].levels[level].dim.k; break;
            case  1:grid_k=domain->subdomains[sendBox].levels[level].dim.k; dim_k=domain->subdomains[sendBox].levels[level].ghosts;break;
          };
          int buf_i = dim_i*(i-sd_i_lo); // ijk in the target buffer
          int buf_j = dim_j*(j-sd_j_lo);
          int buf_k = dim_k*(k-sd_k_lo);
          int buf_pencil = dim_i*(sd_i_hi-sd_i_lo);
          int buf_plane  = dim_j*(sd_j_hi-sd_j_lo)*buf_pencil;

          // FIX, could be broken into sub buffers for more parallelism (i.e. pencils)
          if(initialize==1){
            domain->bufferCopies[level][buffer].dim.i        = dim_i;
            domain->bufferCopies[level][buffer].dim.j        = dim_j;
            domain->bufferCopies[level][buffer].dim.k        = dim_k;
            domain->bufferCopies[level][buffer].read.box     = sendBox;
            domain->bufferCopies[level][buffer].read.ptr     = NULL;
            domain->bufferCopies[level][buffer].read.i       = grid_i;
            domain->bufferCopies[level][buffer].read.j       = grid_j;
            domain->bufferCopies[level][buffer].read.k       = grid_k;
            domain->bufferCopies[level][buffer].read.pencil  = domain->subdomains[sendBox].levels[level].pencil;
            domain->bufferCopies[level][buffer].read.plane   = domain->subdomains[sendBox].levels[level].plane;
            domain->bufferCopies[level][buffer].write.box    = -1;
            domain->bufferCopies[level][buffer].write.ptr    = domain->send_buffer[n];
            domain->bufferCopies[level][buffer].write.i      = buf_i;
            domain->bufferCopies[level][buffer].write.j      = buf_j;
            domain->bufferCopies[level][buffer].write.k      = buf_k;
            domain->bufferCopies[level][buffer].write.pencil = buf_pencil;
            domain->bufferCopies[level][buffer].write.plane  = buf_plane;
            domain->bufferCopies[level][buffer].isFace       =   faces[n];
            domain->bufferCopies[level][buffer].isEdge       =   edges[n];
            domain->bufferCopies[level][buffer].isCorner     = corners[n];
          }
          //else if(domain->rank==0)printf("level=%d, buffer=%3d, copy %3d x %3d x %3d at (%3d,%3d,%3d) from box=%3d to (%3d,%3d,%3d) in MPI[%2d,%2d,%2d] (%3d,%4d)\n",level,buffer,dim_i,dim_j,dim_k,grid_i,grid_j,grid_k,sendBox,buf_i,buf_j,buf_k,di,dj,dk,buf_pencil,buf_plane);
          buffer++;
        } // off-process neighbor
      }}} // subdomains
    } // directions
    #endif
    domain->bufferCopy_Pack_End=buffer;
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // Traverse list of boxes, and create local exchange/domain copies for faces, edges, and corners
    domain->bufferCopy_Local_Start=buffer;
    for(nn=0;nn<26;nn++){
      int n = FacesEdgesCorners[nn];
      int di = ((n/1)%3) - 1;
      int dj = ((n/3)%3) - 1;
      int dk = ((n/9)%3) - 1;
      for(k=0;k<subdomains_per_rank_in_k;k++){
      for(j=0;j<subdomains_per_rank_in_j;j++){
      for(i=0;i<subdomains_per_rank_in_i;i++){
        int sendBox = i + j*subdomains_per_rank_in_i + k*subdomains_per_rank_in_i*subdomains_per_rank_in_j;
        int on_node_exchange = 1;
        if(calculate_neighboring_subdomain_rank(domain,i,j,k, di,dj,dk, my_i_rank,my_j_rank,my_k_rank) != domain->rank)on_node_exchange=0; // if == -1, then domain boundary and thus not on_node
        if(on_node_exchange){
          int recvBox = calculate_neighboring_subdomain_index(domain,i,j,k,di,dj,dk);
          int send_i,send_j,send_k; // ijk in the source grid (relative to first ghost zone element)
          int recv_i,recv_j,recv_k; // ijk in the destination grid (relative to first ghost zone element)
          int  dim_i, dim_j, dim_k; // dimensions of face/edge/corner
          switch(di){
            case -1:send_i=domain->subdomains[sendBox].levels[level].ghosts;dim_i=domain->subdomains[sendBox].levels[level].ghosts;recv_i=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.i;break;
            case  0:send_i=domain->subdomains[sendBox].levels[level].ghosts;dim_i=domain->subdomains[sendBox].levels[level].dim.i; recv_i=domain->subdomains[recvBox].levels[level].ghosts;break;
            case  1:send_i=domain->subdomains[sendBox].levels[level].dim.i; dim_i=domain->subdomains[sendBox].levels[level].ghosts;recv_i=0;break;
          };
          switch(dj){
            case -1:send_j=domain->subdomains[sendBox].levels[level].ghosts;dim_j=domain->subdomains[sendBox].levels[level].ghosts;recv_j=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.j;break;
            case  0:send_j=domain->subdomains[sendBox].levels[level].ghosts;dim_j=domain->subdomains[sendBox].levels[level].dim.j; recv_j=domain->subdomains[recvBox].levels[level].ghosts;break;
            case  1:send_j=domain->subdomains[sendBox].levels[level].dim.j; dim_j=domain->subdomains[sendBox].levels[level].ghosts;recv_j=0;break;
          };
          switch(dk){
            case -1:send_k=domain->subdomains[sendBox].levels[level].ghosts;dim_k=domain->subdomains[sendBox].levels[level].ghosts;recv_k=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.k;break;
            case  0:send_k=domain->subdomains[sendBox].levels[level].ghosts;dim_k=domain->subdomains[sendBox].levels[level].dim.k; recv_k=domain->subdomains[recvBox].levels[level].ghosts;break;
            case  1:send_k=domain->subdomains[sendBox].levels[level].dim.k; dim_k=domain->subdomains[sendBox].levels[level].ghosts;recv_k=0;break;
          };
          // FIX, could be broken into sub buffers for more parallelism (i.e. pencils)
          if(initialize==1){
            domain->bufferCopies[level][buffer].dim.i        = dim_i;
            domain->bufferCopies[level][buffer].dim.j        = dim_j;
            domain->bufferCopies[level][buffer].dim.k        = dim_k;
            domain->bufferCopies[level][buffer].read.box     = sendBox;
            domain->bufferCopies[level][buffer].read.ptr     = NULL;
            domain->bufferCopies[level][buffer].read.i       = send_i;
            domain->bufferCopies[level][buffer].read.j       = send_j;
            domain->bufferCopies[level][buffer].read.k       = send_k;
            domain->bufferCopies[level][buffer].read.pencil  = domain->subdomains[sendBox].levels[level].pencil;
            domain->bufferCopies[level][buffer].read.plane   = domain->subdomains[sendBox].levels[level].plane;
            domain->bufferCopies[level][buffer].write.box    = recvBox;
            domain->bufferCopies[level][buffer].write.ptr    = NULL;
            domain->bufferCopies[level][buffer].write.i      = recv_i;
            domain->bufferCopies[level][buffer].write.j      = recv_j;
            domain->bufferCopies[level][buffer].write.k      = recv_k;
            domain->bufferCopies[level][buffer].write.pencil = domain->subdomains[recvBox].levels[level].pencil;
            domain->bufferCopies[level][buffer].write.plane  = domain->subdomains[recvBox].levels[level].plane;
            domain->bufferCopies[level][buffer].isFace       =   faces[n];
            domain->bufferCopies[level][buffer].isEdge       =   edges[n];
            domain->bufferCopies[level][buffer].isCorner     = corners[n];
          }
          //else if(domain->rank==0)printf("level=%d, buffer=%3d, copy %3d x %3d x %3d at (%3d,%3d,%3d) from box=%3d to (%3d,%3d,%3d) in box=%3d\n",level,buffer,dim_i,dim_j,dim_k,send_i,send_j,send_k,sendBox,recv_i,recv_j,recv_k,recvBox);
          buffer++;
        }
      }}} // all local subdomains
    } // directions
    domain->bufferCopy_Local_End=buffer;
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // Traverse list of boxes and their neighbors and gather data from buffers...
    // faces come from face buffers
    // edges can come from either edge buffers or face buffers
    // corners can come from either corner buffers, edge buffers or face buffers
    domain->bufferCopy_Unpack_Start=buffer;
    #ifdef __MPI
    for(nn=0;nn<26;nn++){
      int n = FacesEdgesCorners[nn];
      int di = ((n/1)%3) - 1;
      int dj = ((n/3)%3) - 1;
      int dk = ((n/9)%3) - 1;
      for(k=0;k<subdomains_per_rank_in_k;k++){
      for(j=0;j<subdomains_per_rank_in_j;j++){
      for(i=0;i<subdomains_per_rank_in_i;i++){
        int recvBox = i + j*subdomains_per_rank_in_i + k*subdomains_per_rank_in_i*subdomains_per_rank_in_j;
        int off_node_exchange = 1;
        if(calculate_neighboring_subdomain_rank(domain,i,j,k, di,dj,dk, my_i_rank,my_j_rank,my_k_rank) == domain->rank)off_node_exchange=0; // same node
        if(calculate_neighboring_subdomain_rank(domain,i,j,k, di,dj,dk, my_i_rank,my_j_rank,my_k_rank) ==           -1)off_node_exchange=0; // domain boundary
        if(off_node_exchange){
          int _di=0;
          int _dj=0;
          int _dk=0;
          if((i+di)<0){_di=-1;}else if((i+di)>=subdomains_per_rank_in_i){_di=1;}
          if((j+dj)<0){_dj=-1;}else if((j+dj)>=subdomains_per_rank_in_j){_dj=1;}
          if((k+dk)<0){_dk=-1;}else if((k+dk)>=subdomains_per_rank_in_k){_dk=1;}
          int _n = 13 + _di + 3*_dj + 9*_dk;
          int  dim_i, dim_j, dim_k; // dimensions of face/edge/corner
          int grid_i,grid_j,grid_k; // ijk in the destination grid (relative to first ghost zone element)
          int  buf_i, buf_j, buf_k; // ijk in the source buffer
          int buf_plane =1;
          int buf_pencil=1;
          switch(di){
            case -1:dim_i=domain->subdomains[recvBox].levels[level].ghosts;grid_i=0;                                                                                               break;
            case  0:dim_i=domain->subdomains[recvBox].levels[level].dim.i; grid_i=domain->subdomains[recvBox].levels[level].ghosts;                                                break;
            case  1:dim_i=domain->subdomains[recvBox].levels[level].ghosts;grid_i=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.i;break;
          };
          switch(dj){
            case -1:dim_j=domain->subdomains[recvBox].levels[level].ghosts;grid_j=0;                                                                                               break;
            case  0:dim_j=domain->subdomains[recvBox].levels[level].dim.j; grid_j=domain->subdomains[recvBox].levels[level].ghosts;                                                break;
            case  1:dim_j=domain->subdomains[recvBox].levels[level].ghosts;grid_j=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.j;break;
          };
          switch(dk){
            case -1:dim_k=domain->subdomains[recvBox].levels[level].ghosts;grid_k=0;                                                                                               break;
            case  0:dim_k=domain->subdomains[recvBox].levels[level].dim.k; grid_k=domain->subdomains[recvBox].levels[level].ghosts;                                                break;
            case  1:dim_k=domain->subdomains[recvBox].levels[level].ghosts;grid_k=domain->subdomains[recvBox].levels[level].ghosts+domain->subdomains[recvBox].levels[level].dim.k;break;
          };
          switch(_di){
            case -1:buf_i=0;                                                buf_plane*=                         domain->subdomains[recvBox].levels[level].ghosts;buf_pencil=                         domain->subdomains[recvBox].levels[level].ghosts;break;
            case  0:buf_i=i*domain->subdomains[recvBox].levels[level].dim.i;buf_plane*=subdomains_per_rank_in_i*domain->subdomains[recvBox].levels[level].dim.i; buf_pencil=subdomains_per_rank_in_i*domain->subdomains[recvBox].levels[level].dim.i; break;
            case  1:buf_i=0;                                                buf_plane*=                         domain->subdomains[recvBox].levels[level].ghosts;buf_pencil=                         domain->subdomains[recvBox].levels[level].ghosts;break;
          };
          switch(_dj){
            case -1:buf_j=0;                                                buf_plane*=                         domain->subdomains[recvBox].levels[level].ghosts;break;
            case  0:buf_j=j*domain->subdomains[recvBox].levels[level].dim.j;buf_plane*=subdomains_per_rank_in_j*domain->subdomains[recvBox].levels[level].dim.j; break;
            case  1:buf_j=0;                                                buf_plane*=                         domain->subdomains[recvBox].levels[level].ghosts;break;
          };
          switch(_dk){
            case -1:buf_k=0;                                                break;
            case  0:buf_k=k*domain->subdomains[recvBox].levels[level].dim.k;break;
            case  1:buf_k=0;                                                break;
          };
          if( (i+di>=0) && (i+di<subdomains_per_rank_in_i) ){if(di<0)buf_i-=domain->subdomains[recvBox].levels[level].ghosts;else if(di>0)buf_i+=domain->subdomains[recvBox].levels[level].dim.i;}// forward by dim.i or back by ghosts
          if( (j+dj>=0) && (j+dj<subdomains_per_rank_in_j) ){if(dj<0)buf_j-=domain->subdomains[recvBox].levels[level].ghosts;else if(dj>0)buf_j+=domain->subdomains[recvBox].levels[level].dim.j;}// forward by dim.j or back by ghosts
          if( (k+dk>=0) && (k+dk<subdomains_per_rank_in_k) ){if(dk<0)buf_k-=domain->subdomains[recvBox].levels[level].ghosts;else if(dk>0)buf_k+=domain->subdomains[recvBox].levels[level].dim.k;}// forward by dim.k or back by ghosts
          // FIX, could be broken into sub buffers for more parallelism (i.e. pencils)
          if(initialize==1){
            domain->bufferCopies[level][buffer].dim.i        = dim_i;
            domain->bufferCopies[level][buffer].dim.j        = dim_j;
            domain->bufferCopies[level][buffer].dim.k        = dim_k;
            domain->bufferCopies[level][buffer].read.box     = -1;
            domain->bufferCopies[level][buffer].read.ptr     = domain->recv_buffer[_n];
            domain->bufferCopies[level][buffer].read.i       = buf_i;
            domain->bufferCopies[level][buffer].read.j       = buf_j;
            domain->bufferCopies[level][buffer].read.k       = buf_k;
            domain->bufferCopies[level][buffer].read.pencil  = buf_pencil;
            domain->bufferCopies[level][buffer].read.plane   = buf_plane;
            domain->bufferCopies[level][buffer].write.box    = recvBox;
            domain->bufferCopies[level][buffer].write.ptr    = NULL;
            domain->bufferCopies[level][buffer].write.i      = grid_i;
            domain->bufferCopies[level][buffer].write.j      = grid_j;
            domain->bufferCopies[level][buffer].write.k      = grid_k;
            domain->bufferCopies[level][buffer].write.pencil = domain->subdomains[recvBox].levels[level].pencil;
            domain->bufferCopies[level][buffer].write.plane  = domain->subdomains[recvBox].levels[level].plane;
            domain->bufferCopies[level][buffer].isFace       =   faces[n];
            domain->bufferCopies[level][buffer].isEdge       =   edges[n];
            domain->bufferCopies[level][buffer].isCorner     = corners[n];
          }
          //else if(domain->rank==0)printf("level=%d, buffer=%3d, copy %3d x %3d x %3d at (%3d,%3d,%3d) from MPI[%2d,%2d,%2d] (%3d,%4d) to box=%3d at (%3d,%3d,%3d)\n",level,buffer,dim_i,dim_j,dim_k,buf_i,buf_j,buf_k,_di,_dj,_dk,buf_pencil,buf_plane,recvBox,grid_i,grid_j,grid_k);
          buffer++;
        }
      }}}
    }
    #endif
    domain->bufferCopy_Unpack_End=buffer;
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // At the end of initialize 0, malloc the buffers
    if(initialize==0){
      domain->bufferCopies[level] = (bufferCopy_type*)malloc(buffer*sizeof(bufferCopy_type));
      memory_allocated+=buffer*sizeof(bufferCopy_type);
    }
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  }}
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


  if(domain->rank==0){
  printf("done\n");fflush(stdout); 
  printf("  %d x %d x %d (per subdomain)\n",subdomain_dim_i,subdomain_dim_j,subdomain_dim_k);
  printf("  %d x %d x %d (per process)\n",subdomains_per_rank_in_i*subdomain_dim_i,subdomains_per_rank_in_j*subdomain_dim_j,subdomains_per_rank_in_k*subdomain_dim_k);
  printf("  %d x %d x %d (overall)\n",ranks_in_i*subdomains_per_rank_in_i*subdomain_dim_i,ranks_in_j*subdomains_per_rank_in_j*subdomain_dim_j,ranks_in_k*subdomains_per_rank_in_k*subdomain_dim_k);
  printf("  %d-deep ghost zones\n",ghosts);
  printf("  allocated %llu MB\n",memory_allocated>>20);
  fflush(stdout);
  }
  return(memory_allocated);
}


void destroy_domain(domain_type * domain){
  if(domain->rank==0){printf("deallocating domain...   ");fflush(stdout);}
  int box;for(box=0;box<domain->subdomains_per_rank;box++){
    destroy_subdomain(&domain->subdomains[box]);
  }
  free(domain->subdomains);
  // FIX, free buffer_copies, etc...
  if(domain->rank==0){printf("done\n");fflush(stdout);}
}


//------------------------------------------------------------------------------------------------------------------------------
void print_timing(domain_type *domain){
  #ifdef TIMING
  int level,numLevels = domain->numLevels;
  uint64_t _timeStart=CycleTime();sleep(1);uint64_t _timeEnd=CycleTime();
  double SecondsPerCycle = (double)1.0/(double)(_timeEnd-_timeStart);
         SecondsPerCycle = SecondsPerCycle/(double)domain->MGSolves_performed; // prints average performance per MGSolve

  if(domain->rank!=0)return;

  uint64_t total;
          printf("                       ");for(level=0;level<(numLevels  );level++){printf("%12d ",level);}printf("\n");
          printf("                       ");for(level=0;level<(numLevels  );level++){printf("%10d^3 ",domain->subdomains[0].levels[0].dim.i>>level);}printf("       total\n");
  total=0;printf("smooth                 ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)       domain->cycles.smooth[level]);total+=       domain->cycles.smooth[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("residual               ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)     domain->cycles.residual[level]);total+=     domain->cycles.residual[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("restriction            ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)  domain->cycles.restriction[level]);total+=  domain->cycles.restriction[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("interpolation          ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)domain->cycles.interpolation[level]);total+=domain->cycles.interpolation[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("applyOp                ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)     domain->cycles.apply_op[level]);total+=     domain->cycles.apply_op[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("BLAS1                  ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)        domain->cycles.blas1[level]);total+=        domain->cycles.blas1[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("BLAS3                  ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)        domain->cycles.blas3[level]);total+=        domain->cycles.blas3[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("communication          ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)domain->cycles.communication[level]);total+=domain->cycles.communication[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  local exchange       ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)    domain->cycles.grid2grid[level]);total+=    domain->cycles.grid2grid[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  #ifdef __MPI
  total=0;printf("  pack MPI buffers     ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)         domain->cycles.pack[level]);total+=         domain->cycles.pack[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  unpack MPI buffers   ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)       domain->cycles.unpack[level]);total+=       domain->cycles.unpack[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  MPI_Isend            ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)         domain->cycles.send[level]);total+=         domain->cycles.send[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  MPI_Irecv            ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)         domain->cycles.recv[level]);total+=         domain->cycles.recv[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  MPI_Waitall          ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)         domain->cycles.wait[level]);total+=         domain->cycles.wait[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  total=0;printf("  MPI_collectives      ");for(level=0;level<(numLevels  );level++){printf("%12.6f ",SecondsPerCycle*(double)  domain->cycles.collectives[level]);total+=  domain->cycles.collectives[level];}printf("%12.6f\n",SecondsPerCycle*(double)total);
  #endif
  total=0;printf("--------------         ");for(level=0;level<(numLevels+1);level++){printf("------------ ");}printf("\n");
  total=0;printf("Total by level         ");for(level=0;level<(numLevels  );level++){printf("%12.6f " ,SecondsPerCycle*(double)domain->cycles.Total[level]);total+=domain->cycles.Total[level];}
                                                                                     printf("%12.6f\n",SecondsPerCycle*(double)total);
  printf("\n");
  printf( "  Total time in MGBuild   %12.6f\n",SecondsPerCycle*(double)domain->cycles.MGBuild);
  printf( "  Total time in MGSolve   %12.6f\n",SecondsPerCycle*(double)domain->cycles.MGSolve);
  printf("              \" v-cycles  %12.6f\n",SecondsPerCycle*(double)domain->cycles.vcycles);
  printf( "      number of v-cycles  %12d\n"  ,domain->vcycles_performed/domain->MGSolves_performed);
  printf( "Bottom solver iterations  %12d\n"  ,domain->Krylov_iterations/domain->MGSolves_performed);
  #if defined(__USE_CABICGSTAB) || defined(__USE_CACG)
  printf( "     formations of G[][]  %12d\n"  ,domain->CAKrylov_formations_of_G/domain->MGSolves_performed);
  #endif
  printf("\n\n");fflush(stdout);
  #endif
}


//------------------------------------------------------------------------------------------------------------------------------
void MGResetTimers(domain_type * domain){
  int level;
  for(level=0;level<10;level++){
  domain->cycles.smooth[level]        = 0;
  domain->cycles.apply_op[level]      = 0;
  domain->cycles.residual[level]      = 0;
  domain->cycles.communication[level] = 0;
  domain->cycles.restriction[level]   = 0;
  domain->cycles.interpolation[level] = 0;
  domain->cycles.blas1[level]         = 0;
  domain->cycles.blas3[level]         = 0;
  domain->cycles.pack[level]          = 0;
  domain->cycles.unpack[level]        = 0;
  domain->cycles.grid2grid[level]     = 0;
  domain->cycles.recv[level]          = 0;
  domain->cycles.send[level]          = 0;
  domain->cycles.wait[level]          = 0;
  domain->cycles.collectives[level]   = 0;
  domain->cycles.Total[level]         = 0;
  }
  domain->cycles.vcycles              = 0;
  domain->cycles.MGSolve              = 0;
  domain->vcycles_performed           = 0;
  domain->MGSolves_performed          = 0;
  domain->Krylov_iterations           = 0;
  domain->CAKrylov_formations_of_G    = 0;
}
//------------------------------------------------------------------------------------------------------------------------------
void MGBuild(domain_type * domain, double a, double b, double h0){
  int box,level,numLevels = domain->numLevels;

  if(domain->rank==0){printf("MGBuild...                      ");fflush(stdout);}

  // initialize timers...
  MGResetTimers(domain);
  domain->cycles.MGBuild = 0;

  uint64_t _timeStartMGBuild = CycleTime();


  // calculate hLevel for all levels/boxes
  for(level=0;level<numLevels;level++){
    double hLevel = h0 * (double)(1<<level);
    domain->h[level] = hLevel;
    for(box=0;box<domain->subdomains_per_rank;box++){
      domain->subdomains[box].levels[level].h = hLevel;
  }}

  // alias all red/black masks to box0's - performance tweak to avoid having a single global list of RedBlack masks as a function of box size
  //for(level=0;level<numLevels-1;level++){
  for(level=0;level<numLevels;level++){
    for(box=1;box<domain->subdomains_per_rank;box++){
      domain->subdomains[box].levels[level].RedBlack_64bMask = domain->subdomains[0].levels[level].RedBlack_64bMask;
      domain->subdomains[box].levels[level].RedBlack_FP[0]   = domain->subdomains[0].levels[level].RedBlack_FP[0];
      domain->subdomains[box].levels[level].RedBlack_FP[1]   = domain->subdomains[0].levels[level].RedBlack_FP[1];
  }}


  // form all restrictions of alpha[] for all boxes...
  for(level=0;level<numLevels-1;level++){      restriction(domain,level,__alpha,__alpha);}
  for(level=0;level<numLevels  ;level++){exchange_boundary(domain,level,__alpha ,1,1,1);} // FIX, only necessary if CA version


  // form all restrictions of beta_*[] for all boxes...
  #if 0
  #warning cell centered beta's are first restricted then projected for faces
  for(level=0;level<numLevels-1;level++){restriction(domain,level,__beta,__beta);}
  for(level=0;level<numLevels;level++){
    exchange_boundary(domain,level,__beta,1,1,1);
    project_cell_to_face(domain,level,__beta,__beta_i,0);
    project_cell_to_face(domain,level,__beta,__beta_j,1);
    project_cell_to_face(domain,level,__beta,__beta_k,2);
  }
  #else
  #warning cell centered beta's are first projected to faces, then restricted to coarsest grid
     exchange_boundary(domain,0,__beta,1,1,1);
  project_cell_to_face(domain,0,__beta,__beta_i,0);
  project_cell_to_face(domain,0,__beta,__beta_j,1);
  project_cell_to_face(domain,0,__beta,__beta_k,2);
  for(level=0;level<numLevels;level++){
                         exchange_boundary(domain,level,__beta_i,1,1,1); // must communicate betas before precomputing lambda (i.e. need high values of beta from next subdomain)
                         exchange_boundary(domain,level,__beta_j,1,1,1);
                         exchange_boundary(domain,level,__beta_k,1,1,1);
    if(level<numLevels-1)restriction_betas(domain,level,level+1);
  }
  #endif


  // form all restrictions of lambda[] for all boxes...
  for(level=0;level<numLevels;level++){   rebuild_lambda(domain,level,a,b);}
  for(level=0;level<numLevels;level++){exchange_boundary(domain,level,__lambda,1,1,1);} // FIX, only necessary if CA version


/*
  // find eigenvalue_max using the power method...
  // probably won't converge, so use slop factor(*1.1) in chebyshev smoother
  if(domain->rank==0){printf("\n");fflush(stdout);}
  for(level=0;level<numLevels;level++){
    int k;
    int bk   = __ee;              // arbitrary... just reusing a grid...
    int Abk = __temp;             // arbitrary... just reusing a grid...
    noise(domain,level,bk,-1,1);  // careful... an initial guess of all 1's gives a*alpha*I+b*beta*(1-1) = {a*alpha}'s
    double eigenvalue_max = 0.0;
    for(k=0;k<10;k++){
      apply_op(domain,level,Abk,bk,a,b); // eigenvalue of D^{-1}A == lambda A bk
      mul_grids(domain,level,Abk,1.0,Abk,__lambda);
      eigenvalue_max = dot(domain,level,bk,Abk)/dot(domain,level,bk,bk);
      double den = sqrt(dot(domain,level,Abk,Abk)); // normalize bk+1 by the magnitude of Abk
      scale_grid(domain,level,bk,1.0/den,Abk); // i.e. bk+1 = Abk / ||Abk||
    }
    if(domain->rank==0){printf("  level=%2d, eigenvalue_max ~= %13.3f\n",level,eigenvalue_max);fflush(stdout);}
    domain->dominant_eigenvalue_of_DinvA[level] = eigenvalue_max;
  }
  // find eigenvalue_min using the power method...
  if(domain->rank==0){printf("\n");fflush(stdout);}
  for(level=0;level<numLevels;level++){
    int k;
    int bk   = __ee;              // arbitrary... just reusing a grid...
    int Abk = __temp;             // arbitrary... just reusing a grid...
    noise(domain,level,bk,-1,1);  // careful... an initial guess of all 1's gives a*alpha*I+b*beta*(1-1) = {a*alpha}'s
    double eigenvalue_min = 0.0;
    for(k=0;k<10;k++){
      apply_op(domain,level,Abk,bk,a,b); // eigenvalue of D^{-1}A == lambda A bk
      mul_grids(domain,level,Abk,1.0,Abk,__lambda);
      add_grids(domain,level,Abk,1.0,Abk,-domain->dominant_eigenvalue_of_DinvA[level],bk); // Abk = (A-ev_max I)bk = Abk - ev_max*bk
      eigenvalue_min = dot(domain,level,bk,Abk)/dot(domain,level,bk,bk);
      double den = sqrt(dot(domain,level,Abk,Abk)); // normalize bk+1 by the magnitude of Abk
      scale_grid(domain,level,bk,1.0/den,Abk); // i.e. bk+1 = Abk / ||Abk||
    }
    eigenvalue_min += domain->dominant_eigenvalue_of_DinvA[level];
    if(domain->rank==0){printf("  level=%2d, eigenvalue_min ~= %13.3f\n",level,eigenvalue_min);fflush(stdout);}
  }
*/


  uint64_t delta = (CycleTime()-_timeStartMGBuild);
  domain->cycles.MGBuild += delta;

  if(domain->rank==0){printf("done\n");fflush(stdout);}
}




//------------------------------------------------------------------------------------------------------------------------------
void MGSolve(domain_type * domain, int u_id, int F_id, double a, double b, double desired_mg_norm){ 
  domain->MGSolves_performed++;
  int level;
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  int e_id = __u;
  int R_id = __f_minus_Av;
  int box,v;
  int numLevels  = domain->numLevels;
  #ifdef __TEST_MG_CONVERGENCE
  int maxVCycles       = 20;
  #else
  int maxVCycles       = 10;
  #endif

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  if(domain->rank==0){printf("MGSolve...                      ");fflush(stdout);}
  uint64_t _timeStartMGSolve = CycleTime();

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // make initial guess for e (=0) and setup the RHS
  #if 1
   zero_grid(domain,0,e_id);                // ee = 0
  scale_grid(domain,0,R_id,1.0,F_id);       // R_id = F_id
  #else
   mul_grids(domain,0,e_id,1.0,F_id,__lambda);  // e_id = F_id*lambda
  scale_grid(domain,0,R_id,1.0,F_id);           // R_id = F_id
  #endif

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // now do v-cycles to calculate the correction...
  uint64_t _timeStartVCycle = CycleTime();
  for(v=0;v<maxVCycles;v++){
    domain->vcycles_performed++;

    // down the v-cycle...
    for(level=0;level<(domain->numLevels-1);level++){
      uint64_t _LevelStart = CycleTime();
      #ifdef __FUSION_RESIDUAL_RESTRICTION
      smooth(domain,level,e_id,R_id,a,b);
      residual_and_restriction(domain,level,e_id,R_id,level+1,R_id,a,b);
      zero_grid(domain,level+1,e_id);
      #else
           smooth(domain,level,e_id,R_id,a,b);
         residual(domain,level,__temp,e_id,R_id,a,b);
      restriction(domain,level,R_id,__temp);
        zero_grid(domain,level+1,e_id);
      #endif
      domain->cycles.Total[level] += (uint64_t)(CycleTime()-_LevelStart);
    } // down
 
  
    // bottom solve...
    uint64_t _timeBottomStart = CycleTime();
    level = domain->numLevels-1;
    IterativeSolver(domain,level,e_id,R_id,a,b,__DEFAULT_BOTTOM_NORM);
    domain->cycles.Total[level] += (uint64_t)(CycleTime()-_timeBottomStart);
  
  
    // back up the v-cycle...
    for(level=(domain->numLevels-2);level>=0;level--){
      uint64_t _LevelStart = CycleTime();
      #ifdef __LINEAR_INTERPOLATION
         interpolation_linear(domain,level,1.0,e_id,e_id);
      #else
       interpolation_constant(domain,level,1.0,e_id,e_id);
      #endif
      smooth(domain,level,e_id,R_id,a,b);
      domain->cycles.Total[level] += (uint64_t)(CycleTime()-_LevelStart);
    } // up


    // now calculate the norm of the residual...
    #if defined(__PRINT_NORM) || defined(__TEST_MG_CONVERGENCE)
      uint64_t _timeStart = CycleTime();
      level = 0;
      residual(domain,level,__temp,e_id,F_id,a,b);
      #if 1
      #warning Using ||D^{-1}(b-Ax)||_{inf} as convergence criteria...
      mul_grids(domain,level,__temp,1.0,__temp,__lambda); /// <<< precondition by D^{-1} ???
      #endif
      double norm_of_residual = norm(domain,level,__temp);
      uint64_t _timeNorm = CycleTime();
      domain->cycles.Total[0] += (uint64_t)(_timeNorm-_timeStart);
      #if defined(__PRINT_NORM)
      if(domain->rank==0){
        if(v==0)printf("\n");
                printf("v-cycle=%2d, norm=%22.20f (%12.6e)\n",v+1,norm_of_residual,norm_of_residual);
      }
      #endif
      #if defined(__TEST_MG_CONVERGENCE)
      if(norm_of_residual<desired_mg_norm)break;
      #endif
    #endif

  } // maxVCycles
  domain->cycles.vcycles += (uint64_t)(CycleTime()-_timeStartVCycle);
  domain->cycles.MGSolve += (uint64_t)(CycleTime()-_timeStartMGSolve);
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  if(domain->rank==0){printf("done\n");fflush(stdout);}
}

