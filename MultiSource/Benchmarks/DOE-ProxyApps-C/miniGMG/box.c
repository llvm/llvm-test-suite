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
#include "defines.h"
#include "box.h"
//------------------------------------------------------------------------------------------------------------------------------
int RandomPadding=-1;
//------------------------------------------------------------------------------------------------------------------------------
int create_box(box_type *box, int numGrids, int low_i, int low_j, int low_k, int dim_i, int dim_j, int dim_k, int ghosts){
  uint64_t memory_allocated = 0;
  box->numGrids = numGrids;
  box->low.i = low_i;
  box->low.j = low_j;
  box->low.k = low_k;
  box->dim.i = dim_i;
  box->dim.j = dim_j;
  box->dim.k = dim_k;
  box->dim_with_ghosts.i = dim_i+2*ghosts;
  box->dim_with_ghosts.j = dim_j+2*ghosts;
  box->dim_with_ghosts.k = dim_k+2*ghosts;
  box->ghosts = ghosts;
  box->pencil = (dim_i+2*ghosts);
  box->plane  = (dim_i+2*ghosts)*(dim_j+2*ghosts);

  // nominally the stencil assumes VL is a perfect multiple of $U and unrolls without cleanup.  However, this means you can walk $U-1 beyond the last point you should update and start updating the ghost zone of the next plane.
//int MaxUnrolling =  8; // 2-way SIMD x unroll by 4 =  8/thread
  int MaxUnrolling = 16; // 4-way SIMD x unroll by 4 = 16/thread
//int MaxUnrolling = 32; // 8-way SIMD x unroll by 4 = 32/thread
  int paddingToAvoidStencilCleanup = 0;
  if(box->pencil+1 < (MaxUnrolling-1)){paddingToAvoidStencilCleanup = (MaxUnrolling-1)-(box->pencil+1);} 

// round each plane up to ensure SIMD alignment within each plane (not pencil).  Thus if ijk is aligned, ijkk+/-plane is aligned
//box->plane  =( ((dim_j+2*ghosts)*box->pencil)+paddingToAvoidStencilCleanup+0xF) & ~0xF; // multiple of  128 bytes
  box->plane  =( ((dim_j+2*ghosts)*box->pencil)+paddingToAvoidStencilCleanup+0x7) & ~0x7; // multiple of  64 bytes (required for MIC)
//box->plane  =( ((dim_j+2*ghosts)*box->pencil)+paddingToAvoidStencilCleanup+0x3) & ~0x3; // multiple of  32 bytes (required for AVX/QPX)
//box->plane  =( ((dim_j+2*ghosts)*box->pencil)+paddingToAvoidStencilCleanup+0x1) & ~0x1; // multiple of  16 bytes (required for SSE)
//printf("%2d^2 = %5d -> %5d\n",box->dim_with_ghosts.i,(dim_j+2*ghosts)*box->pencil,box->plane);

  box->volume = (dim_k+2*ghosts)*box->plane;
  //if(dim_i>=32){while( ((box->volume % 2048) != 288) )box->volume+=8;}
  //if(dim_i>=32){while( ((box->volume %  512) !=  72) )box->volume+=8;} // 32KB / 8way / 8bytes / 7 arrays
    if(dim_i>=32){while( ((box->volume %  512) !=  64) )box->volume+=8;} // 32KB / 8way / 8bytes / 8 arrays
  //if(dim_i>=32){while( ((box->volume %  512) !=  40) )box->volume+=8;} // 32KB / 8way / 8bytes / 13 arrays
  //if(dim_i>=32){while( ((box->volume %  256) !=  40) )box->volume+=8;} // 16KB / 8way / 8bytes / 7 arrays
  //if(dim_i>=32){while( ((box->volume %  256) !=  32) )box->volume+=8;} // 16KB / 8way / 8bytes / 8 arrays

  //if(RandomPadding<0){srand(time(NULL));RandomPadding = 8*((int)rand()%128);}
  //if(dim_i>=32){box->volume+=RandomPadding;}


  // allocate pointers to grids and grids themselves
  posix_memalign((void**)&(box->grids),64,box->numGrids*sizeof(double*));  
  memory_allocated += box->numGrids*sizeof(double*);
#if 0
  int g;for(g=0;g<box->numGrids;g++){
    posix_memalign((void**)&(box->grids[g]),64,box->volume*sizeof(double));
    memset(box->grids[g],0,box->volume*sizeof(double));
    memory_allocated += box->volume*sizeof(double);
  }
#else
  double * tmpbuf;
  posix_memalign((void**)&tmpbuf,64,box->volume*box->numGrids*sizeof(double));
  memset(    tmpbuf,0,box->volume*box->numGrids*sizeof(double));
  memory_allocated += box->volume*box->numGrids*sizeof(double);
  int g;for(g=0;g<box->numGrids;g++){
    box->grids[g] = tmpbuf + g*box->volume;
    //printf("box->grids[%2d] = 0x%016llx\n",g,(uint64_t)box->grids[g] & (0x3<<3));
  }
#endif

  // allocate RedBlackMask array for a plane...
  posix_memalign((void**)&(box->RedBlack_64bMask),64,box->plane*sizeof(uint64_t));
                    memset(box->RedBlack_64bMask,  0,box->plane*sizeof(uint64_t));
                                 memory_allocated += box->plane*sizeof(uint64_t);
  posix_memalign((void**)&(box->RedBlack_FP[0]  ),64,box->plane*sizeof(double  ));
                    memset(box->RedBlack_FP[0]  ,  0,box->plane*sizeof(double  ));
                                 memory_allocated += box->plane*sizeof(double  );
  posix_memalign((void**)&(box->RedBlack_FP[1]  ),64,box->plane*sizeof(double  ));
                    memset(box->RedBlack_FP[1]  ,  0,box->plane*sizeof(double  ));
                                 memory_allocated += box->plane*sizeof(double  );

  // initialize red/black... could do ij loop with ((i%pencil)^(j/pencil)&0x1)
  int i,j;
  for(j=0-ghosts;j<box->dim.j+ghosts;j++){
  for(i=0-ghosts;i<box->dim.i+ghosts;i++){
    int ij = (i+ghosts) + (j+ghosts)*box->pencil;
    if((i^j)&0x1)box->RedBlack_64bMask[ij]=~0;else box->RedBlack_64bMask[ij]= 0;
    if((i^j)&0x1)box->RedBlack_FP[0][ij]=1.0;else box->RedBlack_FP[0][ij]=0.0;
    if((i^j)&0x1)box->RedBlack_FP[1][ij]=0.0;else box->RedBlack_FP[1][ij]=1.0;
  }}
  // done...
  return(memory_allocated);
}

void destroy_box(box_type *box){
#if 0
  int g;for(g=0;g<box->numGrids;g++){
    free(box->grids[g]);
  }
#else
  free(box->grids[0]);
#endif
  free(box->grids);
}


