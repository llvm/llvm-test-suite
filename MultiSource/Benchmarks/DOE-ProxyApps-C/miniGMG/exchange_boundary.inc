//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "timer.h"
#include "mg.h"
//------------------------------------------------------------------------------------------------------------------------------
inline void DoBufferCopy(domain_type *domain, int level, int grid_id, int buffer){
  // copy 3D array from read_i,j,k of read[] to write_i,j,k in write[]
  int   dim_i      = domain->bufferCopies[level][buffer].dim.i;
  int   dim_j      = domain->bufferCopies[level][buffer].dim.j;
  int   dim_k      = domain->bufferCopies[level][buffer].dim.k;

  int  read_i      = domain->bufferCopies[level][buffer].read.i;
  int  read_j      = domain->bufferCopies[level][buffer].read.j;
  int  read_k      = domain->bufferCopies[level][buffer].read.k;
  int  read_pencil = domain->bufferCopies[level][buffer].read.pencil;
  int  read_plane  = domain->bufferCopies[level][buffer].read.plane;

  int write_i      = domain->bufferCopies[level][buffer].write.i;
  int write_j      = domain->bufferCopies[level][buffer].write.j;
  int write_k      = domain->bufferCopies[level][buffer].write.k;
  int write_pencil = domain->bufferCopies[level][buffer].write.pencil;
  int write_plane  = domain->bufferCopies[level][buffer].write.plane;

  double * __restrict__  read = domain->bufferCopies[level][buffer].read.ptr;
  double * __restrict__ write = domain->bufferCopies[level][buffer].write.ptr;
  if(domain->bufferCopies[level][buffer].read.box >=0) read = domain->subdomains[ domain->bufferCopies[level][buffer].read.box].levels[level].grids[grid_id];
  if(domain->bufferCopies[level][buffer].write.box>=0)write = domain->subdomains[domain->bufferCopies[level][buffer].write.box].levels[level].grids[grid_id];

  int i,j,k,read_ijk,write_ijk;
  if(dim_i==1){ // be smart and don't have an inner loop from 0 to 1
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
      int  read_ijk = ( read_i) + (j+ read_j)* read_pencil + (k+ read_k)* read_plane;
      int write_ijk = (write_i) + (j+write_j)*write_pencil + (k+write_k)*write_plane;
      write[write_ijk] = read[read_ijk];
    }}
  }else if(dim_i==4){ // be smart and don't have an inner loop from 0 to 4
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
      int  read_ijk = ( read_i) + (j+ read_j)* read_pencil + (k+ read_k)* read_plane;
      int write_ijk = (write_i) + (j+write_j)*write_pencil + (k+write_k)*write_plane;
      write[write_ijk+0] = read[read_ijk+0];
      write[write_ijk+1] = read[read_ijk+1];
      write[write_ijk+2] = read[read_ijk+2];
      write[write_ijk+3] = read[read_ijk+3];
    }}
  }else{
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int  read_ijk = (i+ read_i) + (j+ read_j)* read_pencil + (k+ read_k)* read_plane;
      int write_ijk = (i+write_i) + (j+write_j)*write_pencil + (k+write_k)*write_plane;
      write[write_ijk] = read[read_ijk];
    }}}
  }
}


//------------------------------------------------------------------------------------------------------------------------------
// Exchange boundaries by aggregating into domain buffers
//------------------------------------------------------------------------------------------------------------------------------
void exchange_boundary(domain_type *domain, int level, int grid_id, int exchange_faces, int exchange_edges, int exchange_corners){
  uint64_t _timeCommunicationStart = CycleTime();
  uint64_t _timeStart,_timeEnd;
  int buffer=0;
  int sendBox,recvBox,n;

  int    faces[27] = {0,0,0,0,1,0,0,0,0,  0,1,0,1,0,1,0,1,0,  0,0,0,0,1,0,0,0,0};
  int    edges[27] = {0,1,0,1,0,1,0,1,0,  1,0,1,0,0,0,1,0,1,  0,1,0,1,0,1,0,1,0};
  int  corners[27] = {1,0,1,0,0,0,1,0,1,  0,0,0,0,0,0,0,0,0,  1,0,1,0,0,0,1,0,1};
  int exchange[27] = {0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0};

  for(n=0;n<27;n++){
    if( exchange_faces   )exchange[n] |=   faces[n];
    if( exchange_edges   )exchange[n] |=   edges[n];
    if( exchange_corners )exchange[n] |= corners[n];
  }


  #ifdef __MPI

  // there are up to 27 sends and up to 27 recvs
  // packed lists of message info...
  double *     buffers_packed[54];
  int            sizes_packed[54];
  int            ranks_packed[54];
  int             tags_packed[54];
  MPI_Request requests_packed[54];
  MPI_Status    status_packed[54];
  int nMessages=0;

  int sizes_all[27];
  // precompute the possible sizes of each buffer (n.b. not all are necessarily used)
  int di,dj,dk;
  for(dk=-1;dk<=1;dk++){
  for(dj=-1;dj<=1;dj++){
  for(di=-1;di<=1;di++){
    int n = 13+di+3*dj+9*dk;
    sizes_all[n] = 1;
    if(di==0)sizes_all[n]*=domain->subdomains_per_rank_in.i*domain->subdomains[0].levels[level].dim.i;else sizes_all[n]*=domain->subdomains[0].levels[level].ghosts;
    if(dj==0)sizes_all[n]*=domain->subdomains_per_rank_in.j*domain->subdomains[0].levels[level].dim.j;else sizes_all[n]*=domain->subdomains[0].levels[level].ghosts;
    if(dk==0)sizes_all[n]*=domain->subdomains_per_rank_in.k*domain->subdomains[0].levels[level].dim.k;else sizes_all[n]*=domain->subdomains[0].levels[level].ghosts;
  }}}

  // enumerate a packed list of messages... starting with receives...
  for(n=0;n<27;n++)if(exchange[26-n] && (domain->rank_of_neighbor[26-n] != domain->rank) ){
    buffers_packed[nMessages] =      domain->recv_buffer[26-n];
      sizes_packed[nMessages] =                sizes_all[26-n];
      ranks_packed[nMessages] = domain->rank_of_neighbor[26-n];
       tags_packed[nMessages] = n;
            nMessages++;
  }
  // enumerate a packed list of messages... continuing with sends...
  for(n=0;n<27;n++)if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){
    buffers_packed[nMessages] =      domain->send_buffer[n];
      sizes_packed[nMessages] =                sizes_all[n];
      ranks_packed[nMessages] = domain->rank_of_neighbor[n];
       tags_packed[nMessages] = n;
    nMessages++;
  }

  // loop through packed list of MPI receives and prepost Irecv's...
  _timeStart = CycleTime();
  #ifdef __MPI_THREAD_MULTIPLE
  #pragma omp parallel for schedule(dynamic,1)
  #endif
  for(n=0;n<nMessages/2;n++){
    MPI_Irecv(buffers_packed[n],sizes_packed[n],MPI_DOUBLE,ranks_packed[n],tags_packed[n],MPI_COMM_WORLD,&requests_packed[n]);
  }
  _timeEnd = CycleTime();
  domain->cycles.recv[level] += (_timeEnd-_timeStart);

  // pack MPI send buffers...
  _timeStart = CycleTime();
  #pragma omp parallel for schedule(static,1)
  for(buffer=domain->bufferCopy_Pack_Start;buffer<domain->bufferCopy_Pack_End;buffer++){
    if( (domain->bufferCopies[level][buffer].isFace   && exchange_faces  ) || 
        (domain->bufferCopies[level][buffer].isEdge   && exchange_edges  ) ||
        (domain->bufferCopies[level][buffer].isCorner && exchange_corners) ){
        DoBufferCopy(domain,level,grid_id,buffer);
  }}
  _timeEnd = CycleTime();
  domain->cycles.grid2grid[level] += (_timeEnd-_timeStart);


  // wait for MPI to finish...
  #ifdef __MPI 
  _timeStart = CycleTime();
  MPI_Waitall(nMessages,requests_packed,status_packed);
  _timeEnd = CycleTime();
  domain->cycles.wait[level] += (_timeEnd-_timeStart);
  #endif
  // unpack MPI receive buffers 
  _timeStart = CycleTime();
  #pragma omp parallel for schedule(static,1)
  for(buffer=domain->bufferCopy_Unpack_Start;buffer<domain->bufferCopy_Unpack_End;buffer++){
    if( (domain->bufferCopies[level][buffer].isFace   && exchange_faces  ) || 
        (domain->bufferCopies[level][buffer].isEdge   && exchange_edges  ) ||
        (domain->bufferCopies[level][buffer].isCorner && exchange_corners) ){
          DoBufferCopy(domain,level,grid_id,buffer);
  }}
  _timeEnd = CycleTime();
  domain->cycles.unpack[level] += (_timeEnd-_timeStart);
  #endif
 
 
  domain->cycles.communication[level] += (uint64_t)(CycleTime()-_timeCommunicationStart);
}
