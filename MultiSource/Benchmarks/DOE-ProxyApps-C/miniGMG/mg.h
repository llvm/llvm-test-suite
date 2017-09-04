//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#ifndef MG_H
#define MG_H
#ifdef __MPI
#include <mpi.h>
#endif
#include "box.h"
//------------------------------------------------------------------------------------------------------------------------------
#define MaxLevels 10
//------------------------------------------------------------------------------------------------------------------------------
#define __DEFAULT_BOTTOM_NORM 1e-3
//------------------------------------------------------------------------------------------------------------------------------
#define numSmooths     4
//------------------------------------------------------------------------------------------------------------------------------
#define __BOUNDARY_PERIODIC  0
#define __BOUNDARY_DIRICHLET 1
#define __BOUNDARY_NEUMANN   2
//------------------------------------------------------------------------------------------------------------------------------
typedef struct {
//double scale;										// +1.0 for ghost zone exchanges
//											// -1.0 for dirichlet boundary conditions in finite volume
//											//  0.0 for dirichlet boundary conditions in finite difference
//											// +1.0 for neumann boundary conditions in finite volume or difference
  int isFace,isEdge,isCorner;								// used to bypass certain computations
  struct {int i, j, k;}dim;								// dimensions of the buffer to copy
  struct {int box, i, j, k, pencil, plane;double * __restrict__ ptr;}read,write;	// coordinates in the read grid to extract the buffer, 
  											// and coordinates in the write grid to insert the buffer
  											// if read/write.box<0, then use write/read.ptr, 
  											// otherwise domain->subdomains[.box].levels[level].grids[grid_id]
} bufferCopy_type;
//------------------------------------------------------------------------------------------------------------------------------
typedef struct {
  int rank;							// MPI rank of remote process
  int local_index;						// index in subdomains[] on remote process
  #ifdef __MPI
  struct{int buf;struct{int faces,edges,corners;}offset;}send;	// i.e. calculate offset as faceSize*faces + edgeSize*edges + cornerSize*corners
  struct{int buf;struct{int faces,edges,corners;}offset;}recv;	// i.e. calculate offset as faceSize*faces + edgeSize*edges + cornerSize*corners
  #endif
} neighbor_type;

//------------------------------------------------------------------------------------------------------------------------------
typedef struct {
  struct {int i, j, k;}low;  			// global coordinates of the first (non-ghost) element of subdomain at the finest resolution
  struct {int i, j, k;}dim;  			// subdomain dimensions at finest resolution
  int numLevels;      				// number of levels in MG v-cycle.  1=no restrictions
  int ghosts;                			// ghost zone depth
  neighbor_type neighbors[27];			// MPI rank and local index (on remote process) of each subdomain neighboring this subdomain
  box_type * levels;				// pointer to an array of all coarsenings of this box
} subdomain_type;


//------------------------------------------------------------------------------------------------------------------------------

typedef struct {
  // timing information...
  struct {
    uint64_t        smooth[MaxLevels];
    uint64_t      apply_op[MaxLevels];
    uint64_t      residual[MaxLevels];
    uint64_t   restriction[MaxLevels];
    uint64_t interpolation[MaxLevels];
    uint64_t communication[MaxLevels];
    uint64_t          pack[MaxLevels];
    uint64_t     grid2grid[MaxLevels];
    uint64_t        unpack[MaxLevels];
    uint64_t          recv[MaxLevels];
    uint64_t          send[MaxLevels];
    uint64_t          wait[MaxLevels];
    uint64_t         blas1[MaxLevels];
    uint64_t         blas3[MaxLevels];
    uint64_t   collectives[MaxLevels];
    uint64_t         Total[MaxLevels];
    uint64_t MGBuild; // total time spent building the coefficients...
    uint64_t vcycles; // total time spent in all vcycles (all CycleMG)
    uint64_t MGSolve; // total time spent in MGSolve
  }cycles;
  int vcycles_performed, MGSolves_performed, Krylov_iterations, CAKrylov_formations_of_G;

  int                                   rank_of_neighbor[27]; // = MPI rank of the neighbors of this process's subdomains (presumes rectahedral packing)
  #ifdef __MPI
  double * __restrict__                      send_buffer[27]; // = MPI send buffers (one per neighbor)
  double * __restrict__                      recv_buffer[27]; // = MPI recieve buffer (one per neighbor)
  struct{int faces,edges,corners;}           buffer_size[27]; // = MPI buffer size (one per neighbor) in the units of faces/edges/corners
//int                             buffer_size[MaxLevels][27]; // = MPI buffer size (one per neighbor) in doubles
  #endif

  bufferCopy_type * bufferCopies[MaxLevels];         // array of pointers to list of bufferCopy's that must be performed to realize a boundary exchange
  int bufferCopy_Pack_Start,  bufferCopy_Pack_End;   // index into above list to pack the MPI buffers
  int bufferCopy_Local_Start, bufferCopy_Local_End;  // index into above list to perform a local exchange (hide within waitall)
  int bufferCopy_Unpack_Start,bufferCopy_Unpack_End; // index into above list to unpack the MPI buffers

  // n.b. i=unit stride
  struct {int i, j, k;}dim;				// global dimensions at finest resolution
  struct {int i, j, k;}ranks_in;			// number of MPI ranks in i,j,k
  struct {int i, j, k;}subdomains_per_rank_in;		// number of subdomains in i,j,k
  struct {int i, j, k;}subdomains_in;			// total number of subdomains in i,j,k across the entire domain
  struct {int i, j, k;}boundary_condition;              // domain boundary condition in i,j,k directions (e.g. __BOUNDARY_PERIODIC)
  int rank;						// MPI rank of this process
  int subdomains_per_rank;				// number of subdomains owned by this process
  int numLevels;					// number of levels in MG v-cycle.  1=no restrictions
  int numGrids;						// number of grids (variables)
  int ghosts;						// ghost zone depth
  double h[MaxLevels];					// h at each level
  double dominant_eigenvalue_of_DinvA[MaxLevels];	// (estimate) for the dominant(largest) eigenvalue at each level of the operator D^{-1}A = lambda*helmholtz
  subdomain_type * subdomains;				// pointer to a list of all subdomains owned by this process
} domain_type;

//------------------------------------------------------------------------------------------------------------------------------
 int create_subdomain(subdomain_type * box, 
                      int subdomain_low_i, int subdomain_low_j, int subdomain_low_k,
                      int subdomain_dim_i, int subdomain_dim_j, int subdomain_dim_k,
                      int numGrids, int ghosts, int numLevels);
void destroy_domain(domain_type * domain);
 int create_domain(domain_type * domain,
                   int subdomain_dim_i, int subdomain_dim_j, int subdomain_dim_k,
                   int subdomains_per_rank_in_i, int subdomains_per_rank_in_j, int subdomains_per_rank_in_k,
                   int ranks_in_i, int ranks_in_j, int ranks_in_k,
                   int rank, 
                   int *boundary_conditions,
                   int numGrids, int ghosts, int numLevels);
void      MGBuild(domain_type * domain, double a, double b, double h0);
void      MGSolve(domain_type * domain, int u_id, int F_id, double a, double b, double desired_mg_norm);
void print_timing(domain_type *domain);
//------------------------------------------------------------------------------------------------------------------------------
#endif
