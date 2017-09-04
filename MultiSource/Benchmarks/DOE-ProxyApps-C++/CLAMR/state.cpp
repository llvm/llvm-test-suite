/*
 *  Copyright (c) 2011-2013, Los Alamos National Security, LLC.
 *  All rights Reserved.
 *
 *  Copyright 2011-2012. Los Alamos National Security, LLC. This software was produced 
 *  under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
 *  Laboratory (LANL), which is operated by Los Alamos National Security, LLC 
 *  for the U.S. Department of Energy. The U.S. Government has rights to use, 
 *  reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS 
 *  ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
 *  ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified
 *  to produce derivative works, such modified software should be clearly marked,
 *  so as not to confuse it with the version available from LANL.
 *
 *  Additionally, redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Los Alamos National Security, LLC, Los Alamos 
 *       National Laboratory, LANL, the U.S. Government, nor the names of its 
 *       contributors may be used to endorse or promote products derived from 
 *       this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE LOS ALAMOS NATIONAL SECURITY, LLC AND 
 *  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
 *  NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL
 *  SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  
 *  CLAMR -- LA-CC-11-094
 *  This research code is being developed as part of the 
 *  2011 X Division Summer Workshop for the express purpose
 *  of a collaborative code for development of ideas in
 *  the implementation of AMR codes for Exascale platforms
 *  
 *  AMR implementation of the Wave code previously developed
 *  as a demonstration code for regular grids on Exascale platforms
 *  as part of the Supercomputing Challenge and Los Alamos 
 *  National Laboratory
 *  
 *  Authors: Bob Robey       XCP-2   brobey@lanl.gov
 *           Neal Davis              davis68@lanl.gov, davis68@illinois.edu
 *           David Nicholaeff        dnic@lanl.gov, mtrxknight@aol.com
 *           Dennis Trujillo         dptrujillo@lanl.gov, dptru10@gmail.com
 * 
 */
#include "mesh.h"
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <queue>
#include "state.h"
#include "timer.h"
#ifdef HAVE_MPI
#include <mpi.h>
#endif

#undef DEBUG
//#define DEBUG 0
#define DEBUG_RESTORE_VALS 1
#define TIMING_LEVEL 2

#if defined(MINIMUM_PRECISION)
#define ZERO 0.0f
#define ONE 1.0f
#define HALF 0.5f
#define EPSILON 1.0f-30
#define STATE_EPS        15.0
// calc refine is done in single precision
#define REFINE_GRADIENT  0.10f
#define COARSEN_GRADIENT 0.05f
#define REFINE_HALF 0.5f
#define REFINE_NEG_THOUSAND -1000.0f

#elif defined(MIXED_PRECISION) // intermediate values calculated high precision and stored as floats
#define ZERO 0.0
#define ONE 1.0
#define HALF 0.5
#define EPSILON 1.0e-30
#define STATE_EPS        .02
// calc refine is done in single precision
#define REFINE_GRADIENT  0.10f
#define COARSEN_GRADIENT 0.05f
#define REFINE_HALF 0.5f
#define REFINE_NEG_THOUSAND -1000.0f

#elif defined(FULL_PRECISION)
#define ZERO 0.0
#define ONE 1.0
#define HALF 0.5
#define EPSILON 1.0e-30
#define STATE_EPS        .02
// calc refine is done in single precision
#define REFINE_GRADIENT  0.10
#define COARSEN_GRADIENT 0.05
#define REFINE_HALF 0.5
#define REFINE_NEG_THOUSAND -1000.0

#endif

#ifdef _OPENMP
static bool iversion_flag = false;
#endif

typedef unsigned int uint;

static const char *state_timer_descriptor[STATE_TIMER_SIZE] = {
   "state_timer_apply_BCs",
   "state_timer_set_timestep",
   "state_timer_finite_difference",
   "state_timer_refine_potential",
   "state_timer_calc_mpot",
   "state_timer_rezone_all",
   "state_timer_mass_sum",
   "state_timer_read",
   "state_timer_write"
};

#ifdef HAVE_OPENCL
#include "state_kernel.inc"
#endif

struct esum_type{
   double sum;
   double correction;
};
#ifdef HAVE_MPI
MPI_Datatype MPI_TWO_DOUBLES;
MPI_Op KNUTH_SUM;
int commutative = 1;
void knuth_sum(struct esum_type *in, struct esum_type *inout, int *len, MPI_Datatype *MPI_TWO_DOUBLES);
#endif

int save_ncells;

#define CONSERVED_EQNS

#define SQR(x) ( x*x )
#define MIN3(x,y,z) ( min( min(x,y), z) )

#ifdef HAVE_OPENCL
cl_kernel kernel_set_timestep;
cl_kernel kernel_reduction_min;
cl_kernel kernel_copy_state_data;
cl_kernel kernel_copy_state_ghost_data;
cl_kernel kernel_apply_boundary_conditions;
cl_kernel kernel_apply_boundary_conditions_local;
cl_kernel kernel_apply_boundary_conditions_ghost;
cl_kernel kernel_calc_finite_difference;
cl_kernel kernel_refine_potential;
cl_kernel kernel_reduce_sum_mass_stage1of2;
cl_kernel kernel_reduce_sum_mass_stage2of2;
cl_kernel kernel_reduce_epsum_mass_stage1of2;
cl_kernel kernel_reduce_epsum_mass_stage2of2;
#endif

inline real_t U_halfstep(// XXX Fix the subindices to be more intuitive XXX
        real_t    deltaT,     // Timestep
        real_t    U_i,        // Initial cell's (downwind's) state variable
        real_t    U_n,        // Next cell's    (upwind's)   state variable
        real_t    F_i,        // Initial cell's (downwind's) state variable flux
        real_t    F_n,        // Next cell's    (upwind's)   state variable flux
        real_t    r_i,        // Initial cell's (downwind's) center to face distance
        real_t    r_n,        // Next cell's    (upwind's)   center to face distance
        real_t    A_i,        // Cell's            face surface area
        real_t    A_n,        // Cell's neighbor's face surface area
        real_t    V_i,        // Cell's            volume
        real_t    V_n) {      // Cell's neighbor's volume

   return (( r_i*U_n + r_n*U_i ) / ( r_i + r_n )) 
          - HALF*deltaT*(( F_n*A_n*min(ONE, A_i/A_n) - F_i*A_i*min(ONE, A_n/A_i) )
                    / ( V_n*min(HALF, V_i/V_n) + V_i*min(HALF, V_n/V_i) ));

}

inline real_t U_fullstep(
        real_t    deltaT,
        real_t    dr,
        real_t    U,
        real_t    F_plus,
        real_t    F_minus,
        real_t    G_plus,
        real_t    G_minus) {

   return (U - (deltaT / dr)*(F_plus - F_minus + G_plus - G_minus));

}


inline real_t w_corrector(
        real_t    deltaT,       // Timestep
        real_t    dr,           // Cell's center to face distance
        real_t    U_eigen,      // State variable's eigenvalue (speed)
        real_t    grad_half,    // Centered gradient
        real_t    grad_minus,   // Downwind gradient
        real_t    grad_plus) {  // Upwind gradient

   real_t nu     = HALF * U_eigen * deltaT / dr;
   nu          = nu * (ONE - nu);

   real_t rdenom = ONE / max(SQR(grad_half), EPSILON);
   real_t rplus  = (grad_plus  * grad_half) * rdenom;
   real_t rminus = (grad_minus * grad_half) * rdenom;

   return HALF*nu*(ONE- max(MIN3(ONE, rplus, rminus), ZERO));
}

State::State(Mesh *mesh_in)
{
   for (int i = 0; i < STATE_TIMER_SIZE; i++){
      cpu_timers[i] = 0.0;
   }
   for (int i = 0; i < STATE_TIMER_SIZE; i++){
      gpu_timers[i] = 0L;
   }

   mesh = mesh_in;

#ifdef HAVE_MPI
   int mpi_init;
   MPI_Initialized(&mpi_init);
   if (mpi_init){
      MPI_Type_contiguous(2, MPI_DOUBLE, &MPI_TWO_DOUBLES);
      MPI_Type_commit(&MPI_TWO_DOUBLES);
      MPI_Op_create((MPI_User_function *)knuth_sum, commutative, &KNUTH_SUM);
      // FIXME add fini and set size
      if (mesh->parallel) state_memory.pinit(MPI_COMM_WORLD, 2L * 1024 * 1024 * 1024);
   }
#endif
}

void State::init(int do_gpu_calc)
{
   if (do_gpu_calc) {
#ifdef HAVE_OPENCL
      cl_context context = ezcl_get_context();

      if (mesh->mype == 0) printf("Starting compile of kernels in state\n");
      const char *defines = NULL;
      cl_program program                 = ezcl_create_program_wsource(context, defines, state_kern_source);

      kernel_set_timestep                    = ezcl_create_kernel_wprogram(program, "set_timestep_cl");
      kernel_reduction_min                   = ezcl_create_kernel_wprogram(program, "finish_reduction_min_cl");
      kernel_copy_state_data                 = ezcl_create_kernel_wprogram(program, "copy_state_data_cl");
      kernel_copy_state_ghost_data           = ezcl_create_kernel_wprogram(program, "copy_state_ghost_data_cl");
      kernel_apply_boundary_conditions       = ezcl_create_kernel_wprogram(program, "apply_boundary_conditions_cl");
      kernel_apply_boundary_conditions_local = ezcl_create_kernel_wprogram(program, "apply_boundary_conditions_local_cl");
      kernel_apply_boundary_conditions_ghost = ezcl_create_kernel_wprogram(program, "apply_boundary_conditions_ghost_cl");
      kernel_calc_finite_difference          = ezcl_create_kernel_wprogram(program, "calc_finite_difference_cl");
      kernel_refine_potential                = ezcl_create_kernel_wprogram(program, "refine_potential_cl");
      kernel_reduce_sum_mass_stage1of2       = ezcl_create_kernel_wprogram(program, "reduce_sum_mass_stage1of2_cl");
      kernel_reduce_sum_mass_stage2of2       = ezcl_create_kernel_wprogram(program, "reduce_sum_mass_stage2of2_cl");
      kernel_reduce_epsum_mass_stage1of2     = ezcl_create_kernel_wprogram(program, "reduce_epsum_mass_stage1of2_cl");
      kernel_reduce_epsum_mass_stage2of2     = ezcl_create_kernel_wprogram(program, "reduce_epsum_mass_stage2of2_cl");

      ezcl_program_release(program);
      if (mesh->mype == 0) printf("Finishing compile of kernels in state\n");
#endif
   }

   //printf("\nDEBUG -- Calling state memory memory malloc at line %d\n",__LINE__);
   allocate(mesh->ncells);
   //state_memory.memory_report();
   //printf("DEBUG -- Finished state memory memory malloc at line %d\n\n",__LINE__);

}

void State::allocate(size_t ncells)
{
   int flags = 0;
   flags = RESTART_DATA;
#ifdef HAVE_J7
   if (mesh->parallel) flags = LOAD_BALANCE_MEMORY;
#endif

   H = (state_t *)state_memory.memory_malloc(ncells, sizeof(state_t), "H", flags);
   U = (state_t *)state_memory.memory_malloc(ncells, sizeof(state_t), "U", flags);
   V = (state_t *)state_memory.memory_malloc(ncells, sizeof(state_t), "V", flags);
}

void State::resize(size_t new_ncells){
   size_t current_size = state_memory.get_memory_size(H);
   if (new_ncells > current_size) state_memory.memory_realloc_all(new_ncells);

   //printf("\nDEBUG -- Calling state memory resize at line %d\n",__LINE__);
   //state_memory.memory_report();
   //printf("DEBUG -- Finished state memory resize at line %d\n\n",__LINE__);
}

void State::memory_reset_ptrs(void){
   H = (state_t *)state_memory.get_memory_ptr("H");
   U = (state_t *)state_memory.get_memory_ptr("U");
   V = (state_t *)state_memory.get_memory_ptr("V");

   //printf("\nDEBUG -- Calling state memory reset_ptrs at line %d\n",__LINE__);
   //state_memory.memory_report();
   //printf("DEBUG -- Finished state memory reset_ptrs at line %d\n\n",__LINE__);
}

void State::terminate(void)
{
   state_memory.memory_delete(H);
   state_memory.memory_delete(U);
   state_memory.memory_delete(V);

#ifdef HAVE_OPENCL
   ezcl_device_memory_delete(dev_deltaT);

   gpu_state_memory.memory_delete(dev_H);
   gpu_state_memory.memory_delete(dev_U);
   gpu_state_memory.memory_delete(dev_V);

   ezcl_kernel_release(kernel_set_timestep);
   ezcl_kernel_release(kernel_reduction_min);
   ezcl_kernel_release(kernel_copy_state_data);
   ezcl_kernel_release(kernel_copy_state_ghost_data);
   ezcl_kernel_release(kernel_apply_boundary_conditions);
   ezcl_kernel_release(kernel_apply_boundary_conditions_local);
   ezcl_kernel_release(kernel_apply_boundary_conditions_ghost);
   ezcl_kernel_release(kernel_calc_finite_difference);
   ezcl_kernel_release(kernel_refine_potential);
   ezcl_kernel_release(kernel_reduce_sum_mass_stage1of2);
   ezcl_kernel_release(kernel_reduce_sum_mass_stage2of2);
   ezcl_kernel_release(kernel_reduce_epsum_mass_stage1of2);
   ezcl_kernel_release(kernel_reduce_epsum_mass_stage2of2);
#endif
#ifdef HAVE_MPI
   if (mesh->parallel) state_memory.pfini();
#endif
}

#ifdef HAVE_MPI
void knuth_sum(struct esum_type *in, struct esum_type *inout, int *len, MPI_Datatype *MPI_TWO_DOUBLES)
{
   double u, v, upt, up, vpp;
   u = inout->sum;
   v = in->sum + (in->correction+inout->correction);
   upt = u + v;
   up = upt - v;
   vpp = upt - up;
   inout->sum = upt;
   inout->correction = (u - up) + (v - vpp);

   // Just to block compiler warnings
   if (1==2) printf("DEBUG len %d datatype %lld\n",*len,(long long)(*MPI_TWO_DOUBLES) );
}
#endif

void State::add_boundary_cells(void)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   // This is for a mesh with no boundary cells -- they are added and
   // the mesh sizes increased
   size_t &ncells        = mesh->ncells;
   vector<int>  &index    = mesh->index;
   vector<spatial_t> &x        = mesh->x;
   vector<spatial_t> &dx       = mesh->dx;
   vector<spatial_t> &y        = mesh->y;
   vector<spatial_t> &dy       = mesh->dy;

   int *i        = mesh->i;
   int *j        = mesh->j;
   int *level    = mesh->level;
   int *celltype = mesh->celltype;
   int *nlft     = mesh->nlft;
   int *nrht     = mesh->nrht;
   int *nbot     = mesh->nbot;
   int *ntop     = mesh->ntop;

   vector<int> &lev_ibegin = mesh->lev_ibegin;
   vector<int> &lev_iend   = mesh->lev_iend;
   vector<int> &lev_jbegin = mesh->lev_jbegin;
   vector<int> &lev_jend   = mesh->lev_jend;

   // Pre-count number of cells to add
   int icount = 0;
   for (uint ic=0; ic<ncells; ic++) {
      if (i[ic] == lev_ibegin[level[ic]]) icount++; // Left boundary
      if (i[ic] == lev_iend[level[ic]])   icount++; // Right boundary
      if (j[ic] == lev_jbegin[level[ic]]) icount++; // Bottom boundary
      if (j[ic] == lev_jend[level[ic]])   icount++; // Top boundary
   }
      
   int new_ncells = ncells + icount;
   // Increase the arrays for the new boundary cells
   H=(state_t *)state_memory.memory_realloc(new_ncells, H);
   U=(state_t *)state_memory.memory_realloc(new_ncells, U);
   V=(state_t *)state_memory.memory_realloc(new_ncells, V);
   //printf("\nDEBUG add_boundary cells\n"); 
   //state_memory.memory_report();
   //printf("DEBUG end add_boundary cells\n\n"); 

   mesh->i        =(int *)mesh->mesh_memory.memory_realloc(new_ncells, i);
   mesh->j        =(int *)mesh->mesh_memory.memory_realloc(new_ncells, j);
   mesh->level    =(int *)mesh->mesh_memory.memory_realloc(new_ncells, level);
   mesh->celltype =(int *)mesh->mesh_memory.memory_realloc(new_ncells, celltype);
   mesh->nlft     =(int *)mesh->mesh_memory.memory_realloc(new_ncells, nlft);
   mesh->nrht     =(int *)mesh->mesh_memory.memory_realloc(new_ncells, nrht);
   mesh->nbot     =(int *)mesh->mesh_memory.memory_realloc(new_ncells, nbot);
   mesh->ntop     =(int *)mesh->mesh_memory.memory_realloc(new_ncells, ntop);
   //memory_reset_ptrs();
   i        = mesh->i;
   j        = mesh->j;
   level    = mesh->level;
   celltype = mesh->celltype;
   nlft     = mesh->nlft;
   nrht     = mesh->nrht;
   nbot     = mesh->nbot;
   ntop     = mesh->ntop;

   index.resize(new_ncells);
   x.resize(new_ncells);
   dx.resize(new_ncells);
   y.resize(new_ncells);
   dy.resize(new_ncells);

   for (int nc=ncells; nc<new_ncells; nc++) {
      nlft[nc] = -1;
      nrht[nc] = -1;
      nbot[nc] = -1;
      ntop[nc] = -1;
   }
      
   // In the first pass, set two of the neighbor indices and all
   // the other data to be brought across. Set the inverse of the
   // the velocity to enforce the reflective boundary condition
   uint nc=ncells;
   for (uint ic=0; ic<ncells; ic++) {
      if (i[ic] == lev_ibegin[level[ic]]) {
         nlft[ic] = nc;
         nlft[nc] = nc;
         nrht[nc] = ic;
         i[nc] = lev_ibegin[level[ic]]-1;
         j[nc] = j[ic];
         level[nc] = level[ic];
         dx[nc] = dx[ic];
         dy[nc] = dy[ic];
         x[nc] = x[ic]-dx[ic];
         y[nc] = y[ic];
         H[nc] =  H[ic];
         U[nc] = -U[ic];
         V[nc] =  V[ic];
         nc++;
      }
      if (i[ic] == lev_iend[level[ic]]) {
         nrht[ic] = nc;
         nrht[nc] = nc;
         nlft[nc] = ic;
         i[nc] = lev_iend[level[ic]]+1;
         j[nc] = j[ic];
         level[nc] = level[ic];
         dx[nc] = dx[ic];
         dy[nc] = dy[ic];
         x[nc] = x[ic]+dx[ic];
         y[nc] = y[ic];
         H[nc] =  H[ic];
         U[nc] = -U[ic];
         V[nc] =  V[ic];
         nc++;
      }
      if (j[ic] == lev_jbegin[level[ic]]) {
         nbot[ic] = nc;
         nbot[nc] = nc;
         ntop[nc] = ic;
         i[nc] = i[ic];
         j[nc] = lev_jbegin[level[ic]]-1;
         level[nc] = level[ic];
         dx[nc] = dx[ic];
         dy[nc] = dy[ic];
         x[nc] = x[ic];
         y[nc] = y[ic]-dy[ic];
         H[nc] =  H[ic];
         U[nc] =  U[ic];
         V[nc] = -V[ic];
         nc++;
      }
      if (j[ic] == lev_jend[level[ic]]) {
         ntop[ic] = nc;
         ntop[nc] = nc;
         nbot[nc] = ic;
         i[nc] = i[ic];
         j[nc] = lev_jend[level[ic]]+1;
         level[nc] = level[ic];
         dx[nc] = dx[ic];
         dy[nc] = dy[ic];
         x[nc] = x[ic];
         y[nc] = y[ic]+dy[ic];
         H[nc] =  H[ic];
         U[nc] =  U[ic];
         V[nc] = -V[ic];
         nc++;
      }
   }

   // Now set the other two neighbor indices
   for (int nc=ncells; nc<new_ncells; nc++) {
      if (i[nc] == lev_ibegin[level[nc]]-1) {
         // Need to check if also a bottom boundary cell
         if (j[nc] == lev_jbegin[level[nc]]){
           nbot[nc] = nc;
         } else {
           nbot[nc] = nlft[nbot[nrht[nc]]];
         }
         if (j[nc] == lev_jend[level[nc]]){
           ntop[nc] = nc;
         } else {
           ntop[nc] = nlft[ntop[nrht[nc]]];
         }
      }
      if (i[nc] == lev_iend[level[nc]]+1)   {
         if (level[nc] <= level[nbot[nlft[nc]]]){
            if (j[nc] == lev_jbegin[level[nc]]){
               nbot[nc] = nc;
            } else {
               nbot[nc] = nrht[nbot[nlft[nc]]];
            }
            if (j[nc] == lev_jend[level[nc]]){
               ntop[nc] = nc;
            } else {
               ntop[nc] = nrht[ntop[nlft[nc]]];
            }
         // calculation is a little different if going through a
         // finer zoned region
         } else {
            nbot[nc] = nrht[nrht[nbot[nlft[nc]]]];
            ntop[nc] = nrht[nrht[ntop[nlft[nc]]]];
         }
      }
      if (j[nc] == lev_jbegin[level[nc]]-1) {
         if (i[nc] == lev_ibegin[level[nc]]){
            nlft[nc] = nc;
         } else {
            nlft[nc] = nbot[nlft[ntop[nc]]];
         }
         if (i[nc] == lev_iend[level[nc]]){
            nrht[nc] = nc;
         } else {
            nrht[nc] = nbot[nrht[ntop[nc]]];
         }
      }
      if (j[nc] == lev_jend[level[nc]]+1)   {
         if (level[nc] <= level[nlft[nbot[nc]]]){
            if (i[nc] == lev_ibegin[level[nc]]){
               nlft[nc] = nc;
            } else {
               nlft[nc] = ntop[nlft[nbot[nc]]];
            }
            if (i[nc] == lev_iend[level[nc]]){
               nrht[nc] = nc;
            } else {
               nrht[nc] = ntop[nrht[nbot[nc]]];
            }
         } else {
            nlft[nc] = ntop[ntop[nlft[nbot[nc]]]];
            nrht[nc] = ntop[ntop[nrht[nbot[nc]]]];
         }
      }
   }
   save_ncells = ncells;
   ncells = new_ncells;

   cpu_timers[STATE_TIMER_APPLY_BCS] += cpu_timer_stop(tstart_cpu);
}

void State::apply_boundary_conditions_local(void)
{
   static int *nlft, *nrht, *nbot, *ntop;

   size_t &ncells = mesh->ncells;
   nlft = mesh->nlft;
   nrht = mesh->nrht;
   nbot = mesh->nbot;
   ntop = mesh->ntop;

   // This is for a mesh with boundary cells
   int lowerBound, upperBound;
   mesh->get_bounds(lowerBound, upperBound);
   for (uint ic=lowerBound; ic<upperBound; ic++) {
      if (mesh->is_left_boundary(ic)) {
         int nr = nrht[ic];
         if (nr < (int)ncells) {
            H[ic] =  H[nr];
            U[ic] = -U[nr];
            V[ic] =  V[nr];
         }
      }
      if (mesh->is_right_boundary(ic))  {
         int nl = nlft[ic];
         if (nl < (int)ncells) {
            H[ic] =  H[nl];
            U[ic] = -U[nl];
            V[ic] =  V[nl];
         }
      }
      if (mesh->is_bottom_boundary(ic)) {
         int nt = ntop[ic];
         if (nt < (int)ncells) {
            H[ic] =  H[nt];
            U[ic] =  U[nt];
            V[ic] = -V[nt];
         }
      }
      if (mesh->is_top_boundary(ic)) {
         int nb = nbot[ic];
         if (nb < (int)ncells) {
            H[ic] =  H[nb];
            U[ic] =  U[nb];
            V[ic] = -V[nb];
         }
      }
   }
}

void State::apply_boundary_conditions_ghost(void)
{
   static int *nlft, *nrht, *nbot, *ntop;

   size_t &ncells = mesh->ncells;
   nlft = mesh->nlft;
   nrht = mesh->nrht;
   nbot = mesh->nbot;
   ntop = mesh->ntop;

   // This is for a mesh with boundary cells
   int lowerBound, upperBound; 
   mesh->get_bounds(lowerBound, upperBound);
   for (uint ic=lowerBound; ic<upperBound; ic++) {
      if (mesh->is_left_boundary(ic)) {
         int nr = nrht[ic];
         if (nr >= (int)ncells) {
            H[ic] =  H[nr];
            U[ic] = -U[nr];
            V[ic] =  V[nr];
         }
      }
      if (mesh->is_right_boundary(ic))  {
         int nl = nlft[ic];
         if (nl >= (int)ncells) {
            H[ic] =  H[nl];
            U[ic] = -U[nl];
            V[ic] =  V[nl];
         }
      }
      if (mesh->is_bottom_boundary(ic)) {
         int nt = ntop[ic];
         if (nt >= (int)ncells) {
            H[ic] =  H[nt];
            U[ic] =  U[nt];
            V[ic] = -V[nt];
         }
      }
      if (mesh->is_top_boundary(ic)) {
         int nb = nbot[ic];
         if (nb >= (int)ncells) {
            H[ic] =  H[nb];
            U[ic] =  U[nb];
            V[ic] = -V[nb];
         }
      }
   }
}

void State::apply_boundary_conditions(void)
{
   int *nlft, *nrht, *nbot, *ntop;

   size_t &ncells = mesh->ncells;
   nlft = mesh->nlft;
   nrht = mesh->nrht;
   nbot = mesh->nbot;
   ntop = mesh->ntop;

   // This is for a mesh with boundary cells
   int lowerBound, upperBound;
   mesh->get_bounds(lowerBound, upperBound);
   for (uint ic=lowerBound; ic<upperBound; ic++) {
      if (mesh->is_left_boundary(ic)) {
         int nr = nrht[ic];
         H[ic] =  H[nr];
         U[ic] = -U[nr];
         V[ic] =  V[nr];
      }
      if (mesh->is_right_boundary(ic))  {
         int nl = nlft[ic];
         H[ic] =  H[nl];
         U[ic] = -U[nl];
         V[ic] =  V[nl];
      }
      if (mesh->is_bottom_boundary(ic)) {
         int nt = ntop[ic];
         H[ic] =  H[nt];
         U[ic] =  U[nt];
         V[ic] = -V[nt];
      }
      if (mesh->is_top_boundary(ic)) {
         int nb = nbot[ic];
         H[ic] =  H[nb];
         U[ic] =  U[nb];
         V[ic] = -V[nb];
      }
   }
}

void State::remove_boundary_cells(void)
{
   if(! mesh->have_boundary) {

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
      {
#endif
         size_t &ncells = mesh->ncells;

         // Resize to drop all the boundary cells
         ncells = save_ncells;
         H=(state_t *)state_memory.memory_realloc(save_ncells, H);
         U=(state_t *)state_memory.memory_realloc(save_ncells, U);
         V=(state_t *)state_memory.memory_realloc(save_ncells, V);
         //printf("\nDEBUG remove_boundary cells\n"); 
         //state_memory.memory_report();
         //printf("DEBUG end remove_boundary cells\n\n"); 

         mesh->i        = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->i);
         mesh->j        = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->j);
         mesh->level    = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->level);
         mesh->celltype = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->celltype);
         mesh->nlft     = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->nlft);
         mesh->nrht     = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->nrht);
         mesh->nbot     = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->nbot);
         mesh->ntop     = (int *)mesh->mesh_memory.memory_realloc(save_ncells, mesh->ntop);

         // Reset the neighbors due to the dropped boundary cells
         mesh->index.resize(save_ncells);
         mesh->x.resize(save_ncells);
         mesh->dx.resize(save_ncells);
         mesh->y.resize(save_ncells);
         mesh->dy.resize(save_ncells);
#ifdef _OPENMP
      }
#pragma omp barrier
#endif

      mesh->set_bounds(mesh->ncells);

      int lowerBound, upperBound;
      mesh->get_bounds(lowerBound, upperBound);
      for (uint ic=lowerBound; ic<upperBound; ic++) {
         if (mesh->i[ic] == mesh->lev_ibegin[mesh->level[ic]]) mesh->nlft[ic] = ic;
         if (mesh->i[ic] == mesh->lev_iend[mesh->level[ic]])   mesh->nrht[ic] = ic;
         if (mesh->j[ic] == mesh->lev_jbegin[mesh->level[ic]]) mesh->nbot[ic] = ic;
         if (mesh->j[ic] == mesh->lev_jend[mesh->level[ic]])   mesh->ntop[ic] = ic;
      }

   } // if have_boundary
}

double State::set_timestep(double g, double sigma)
{
   double globalmindeltaT;

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   static double mindeltaT;

   int lowerBounds, upperBounds;
   mesh->set_bounds(mesh->ncells);
   mesh->get_bounds(lowerBounds, upperBounds);

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
      mindeltaT = 1000;
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

   double mymindeltaT = 1000.0; // private for each thread

   for (int ic=lowerBounds; ic<upperBounds; ic++) {
      if (mesh->celltype[ic] == REAL_CELL) {
         int lev = mesh->level[ic];
         double wavespeed = sqrt(g*H[ic]);
         double xspeed = (fabs(U[ic])+wavespeed)/mesh->lev_deltax[lev];
         double yspeed = (fabs(V[ic])+wavespeed)/mesh->lev_deltay[lev];
         double deltaT=sigma/(xspeed+yspeed);
         if (deltaT < mymindeltaT) mymindeltaT = deltaT;
      }
   }

#ifdef _OPENMP
#pragma omp critical
   {
#endif
      if (mymindeltaT < mindeltaT) mindeltaT = mymindeltaT;
#ifdef _OPENMP
   } // End critical region
#pragma omp barrier
#endif

#ifdef _OPENMP
#pragma omp master
   {
#endif


   globalmindeltaT = mindeltaT;
#ifdef HAVE_MPI
      if (mesh->parallel) MPI_Allreduce(&mindeltaT, &globalmindeltaT, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
#endif

      cpu_timers[STATE_TIMER_SET_TIMESTEP] += cpu_timer_stop(tstart_cpu);
#ifdef _OPENMP
   } // End master region
#pragma omp barrier
#endif

   return(globalmindeltaT);
}

#ifdef HAVE_OPENCL
double State::gpu_set_timestep(double sigma)
{
   double deltaT, globalmindeltaT;

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   cl_command_queue command_queue = ezcl_get_command_queue();

   size_t &ncells       = mesh->ncells;
#ifdef HAVE_MPI
   int &parallel        = mesh->parallel;
#endif
   cl_mem &dev_level    = mesh->dev_level;
   cl_mem &dev_celltype = mesh->dev_celltype;
   cl_mem &dev_levdx    = mesh->dev_levdx;
   cl_mem &dev_levdy    = mesh->dev_levdy;

   assert(dev_H);
   assert(dev_U);
   assert(dev_V);
   assert(dev_level);
   assert(dev_celltype);
   assert(dev_levdx);
   assert(dev_levdy);

   size_t local_work_size = 128;
   size_t global_work_size = ((ncells+local_work_size - 1) /local_work_size) * local_work_size;
   size_t block_size     = global_work_size/local_work_size;

   cl_mem dev_redscratch = ezcl_malloc(NULL, const_cast<char *>("dev_redscratch"), &block_size, sizeof(cl_real_t), CL_MEM_READ_WRITE, 0);

      /*
      __kernel void set_timestep_cl(
                       const int       ncells,     // 0  Total number of cells.
                       const real_t    sigma,      // 1
              __global const state_t  *H,          // 2
              __global const state_t  *U,          // 3
              __global const state_t  *V,          // 4
              __global const int      *level,      // 5  Array of level information.
              __global const int      *celltype,   // 6
              __global const real_t   *lev_dx,     // 7
              __global const real_t   *lev_dy,     // 8
              __global       real_t   *redscratch, // 9
              __global       real_t   *deltaT,     // 10
              __local        real_t   *tile)       // 11
      */

   real_t sigma_local = sigma;
   ezcl_set_kernel_arg(kernel_set_timestep,  0, sizeof(cl_int),  (void *)&ncells);
   ezcl_set_kernel_arg(kernel_set_timestep,  1, sizeof(cl_real_t), (void *)&sigma_local);
   ezcl_set_kernel_arg(kernel_set_timestep,  2, sizeof(cl_mem),  (void *)&dev_H);
   ezcl_set_kernel_arg(kernel_set_timestep,  3, sizeof(cl_mem),  (void *)&dev_U);
   ezcl_set_kernel_arg(kernel_set_timestep,  4, sizeof(cl_mem),  (void *)&dev_V);
   ezcl_set_kernel_arg(kernel_set_timestep,  5, sizeof(cl_mem),  (void *)&dev_level);
   ezcl_set_kernel_arg(kernel_set_timestep,  6, sizeof(cl_mem),  (void *)&dev_celltype);
   ezcl_set_kernel_arg(kernel_set_timestep,  7, sizeof(cl_mem),  (void *)&dev_levdx);
   ezcl_set_kernel_arg(kernel_set_timestep,  8, sizeof(cl_mem),  (void *)&dev_levdy);
   ezcl_set_kernel_arg(kernel_set_timestep,  9, sizeof(cl_mem),  (void *)&dev_redscratch);
   ezcl_set_kernel_arg(kernel_set_timestep, 10, sizeof(cl_mem),  (void *)&dev_deltaT);
   ezcl_set_kernel_arg(kernel_set_timestep, 11, local_work_size*sizeof(cl_real_t),  NULL);

   ezcl_enqueue_ndrange_kernel(command_queue, kernel_set_timestep, 1, NULL, &global_work_size, &local_work_size, NULL);

   if (block_size > 1){
         /*
         __kernel void finish_reduction_min_cl(
           const    int      isize,
           __global real_t  *redscratch,
           __global real_t  *deltaT,
           __local  real_t  *tile)
         */
      ezcl_set_kernel_arg(kernel_reduction_min, 0, sizeof(cl_int),  (void *)&block_size);
      ezcl_set_kernel_arg(kernel_reduction_min, 1, sizeof(cl_mem),  (void *)&dev_redscratch);
      ezcl_set_kernel_arg(kernel_reduction_min, 2, sizeof(cl_mem),  (void *)&dev_deltaT);
      ezcl_set_kernel_arg(kernel_reduction_min, 3, local_work_size*sizeof(cl_real_t), NULL);

     ezcl_enqueue_ndrange_kernel(command_queue, kernel_reduction_min, 1, NULL, &local_work_size, &local_work_size, NULL);
   }

   real_t deltaT_local;
   ezcl_enqueue_read_buffer(command_queue, dev_deltaT, CL_TRUE,  0, sizeof(cl_real_t), &deltaT_local, NULL);
   deltaT = deltaT_local;

   globalmindeltaT = deltaT;
#ifdef HAVE_MPI
   if (parallel) MPI_Allreduce(&deltaT, &globalmindeltaT, 1, MPI_DOUBLE, MPI_MIN, MPI_COMM_WORLD);
#endif

   ezcl_device_memory_delete(dev_redscratch);

   gpu_timers[STATE_TIMER_SET_TIMESTEP] += (long)(cpu_timer_stop(tstart_cpu)*1.0e9);

   return(globalmindeltaT);
}
#endif

void State::fill_circle(double  circ_radius,//  Radius of circle in grid units.
                        double  fill_value, //  Circle height for shallow water.
                        double  background) //  Background height for shallow water.
{  
   size_t &ncells = mesh->ncells;
   vector<spatial_t> &x  = mesh->x;
   vector<spatial_t> &dx = mesh->dx;
   vector<spatial_t> &y  = mesh->y;
   vector<spatial_t> &dy = mesh->dy;

   for (uint ic = 0; ic < ncells; ic++)
   {  H[ic] = background;
      U[ic] = V[ic] = 0.0; }
   
   //  Clear the old k-D tree and generate new data (slow but necessary here).
   //KDTree_Destroy(&mesh->tree);
   mesh->kdtree_setup();
   
   int nez;
   vector<int>    ind(ncells);
   vector<double> weight(ncells);
   
#ifdef FULL_PRECISION
   KDTree_QueryCircleInterior_Double(&mesh->tree, &nez, &(ind[0]), circ_radius, ncells,
                                     &x[0], &dx[0],
                                     &y[0], &dy[0]);
#else
   KDTree_QueryCircleInterior_Float(&mesh->tree, &nez, &(ind[0]), circ_radius, ncells,
                                    &x[0], &dx[0],
                                    &y[0], &dy[0]);
#endif
   for (int ic = 0; ic < nez; ++ic)
   {  H[ind[ic]] = fill_value; }
   
#ifdef FULL_PRECISION
   KDTree_QueryCircleIntersectWeighted_Double(&mesh->tree, &nez, &(ind[0]), &(weight[0]),
                              circ_radius, ncells,
                              &x[0], &dx[0],
                              &y[0], &dy[0]);
#else
   KDTree_QueryCircleIntersectWeighted_Float(&mesh->tree, &nez, &(ind[0]), &(weight[0]),
                              circ_radius, ncells,
                              &x[0], &dx[0],
                              &y[0], &dy[0]);
#endif

   for (int ic = 0; ic < nez; ++ic)
   {  H[ind[ic]] = background + (fill_value - background) * weight[ic]; }

   KDTree_Destroy(&mesh->tree);
}

void State::state_reorder(vector<int> iorder)
{
   H = state_memory.memory_reorder(H, &iorder[0]);
   U = state_memory.memory_reorder(U, &iorder[0]);
   V = state_memory.memory_reorder(V, &iorder[0]);
   //printf("\nDEBUG reorder cells\n"); 
   //state_memory.memory_report();
   //printf("DEBUG end reorder cells\n\n"); 
}

void State::rezone_all(int icount, int jcount, vector<int> mpot)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   mesh->rezone_all(icount, jcount, mpot, 1, state_memory);

#ifdef _OPENMP
#pragma omp master
   {
#endif
   memory_reset_ptrs();

   cpu_timers[STATE_TIMER_REZONE_ALL] += cpu_timer_stop(tstart_cpu);
#ifdef _OPENMP
   } // end master region
#endif
}


#ifdef HAVE_OPENCL
void State::gpu_rezone_all(int icount, int jcount, bool localStencil)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   // Just to get rid of compiler warnings
   if (1 == 2) printf("DEBUG -- localStencil is %d\n",localStencil);

   mesh->gpu_rezone_all(icount, jcount, dev_mpot, gpu_state_memory);
   dev_H = (cl_mem)gpu_state_memory.get_memory_ptr("dev_H");
   dev_U = (cl_mem)gpu_state_memory.get_memory_ptr("dev_U");
   dev_V = (cl_mem)gpu_state_memory.get_memory_ptr("dev_V");

   gpu_timers[STATE_TIMER_REZONE_ALL] += (long)(cpu_timer_stop(tstart_cpu)*1.0e9);
}
#endif

//define macro for squaring a number
#define SQ(x) ((x)*(x))
//define macro to find minimum of 3 values
//#define MIN3(a,b,c) (min(min((a),(b)),(c)))

#define HXFLUX(ic)  ( U[ic] )
#define UXFLUX(ic)  ( SQ(U[ic])/H[ic] + ghalf*SQ(H[ic]) )
#define UVFLUX(ic)  ( U[ic]*V[ic]/H[ic] )

#define HXFLUXIC ( Uic )
#define HXFLUXNL ( Ul )
#define HXFLUXNR ( Ur )
#define HXFLUXNB ( Ub )
#define HXFLUXNT ( Ut )

#define UXFLUXIC ( SQ(Uic)/Hic + ghalf*SQ(Hic) )
#define UXFLUXNL ( SQ(Ul)/Hl + ghalf*SQ(Hl) )
#define UXFLUXNR ( SQ(Ur)/Hr + ghalf*SQ(Hr) )
#define UXFLUXNB ( SQ(Ub)/Hb + ghalf*SQ(Hb) )
#define UXFLUXNT ( SQ(Ut)/Ht + ghalf*SQ(Ht) )

#define UVFLUXIC ( Uic*Vic/Hic )
#define UVFLUXNL ( Ul*Vl/Hl )
#define UVFLUXNR ( Ur*Vr/Hr )
#define UVFLUXNB ( Ub*Vb/Hb )
#define UVFLUXNT ( Ut*Vt/Ht )

#define HYFLUX(ic)  ( V[ic] )
#define VUFLUX(ic)  ( V[ic]*U[ic]/H[ic] )
#define VYFLUX(ic)  ( SQ(V[ic])/H[ic] + ghalf*SQ(H[ic]) )

#define HYFLUXIC ( Vic )
#define HYFLUXNL ( Vl )
#define HYFLUXNR ( Vr )
#define HYFLUXNB ( Vb )
#define HYFLUXNT ( Vt )

#define VUFLUXIC  ( Vic*Uic/Hic )
#define VUFLUXNL  ( Vl*Ul/Hl )
#define VUFLUXNR  ( Vr*Ur/Hr )
#define VUFLUXNB  ( Vb*Ub/Hb )
#define VUFLUXNT  ( Vt*Ut/Ht )

#define VYFLUXIC  ( SQ(Vic)/Hic + ghalf*SQ(Hic) )
#define VYFLUXNL  ( SQ(Vl)/Hl + ghalf*SQ(Hl) )
#define VYFLUXNR  ( SQ(Vr)/Hr + ghalf*SQ(Hr) )
#define VYFLUXNB  ( SQ(Vb)/Hb + ghalf*SQ(Hb) )
#define VYFLUXNT  ( SQ(Vt)/Ht + ghalf*SQ(Ht) )


#define HNEWXFLUXMINUS  ( Uxminus )
#define HNEWXFLUXPLUS   ( Uxplus )
#define UNEWXFLUXMINUS  ( SQ(Uxminus)/Hxminus + ghalf*SQ(Hxminus) )
#define UNEWXFLUXPLUS   ( SQ(Uxplus) /Hxplus +  ghalf*SQ(Hxplus)  )
#define UVNEWFLUXMINUS  ( Uxminus*Vxminus/Hxminus )
#define UVNEWFLUXPLUS   ( Uxplus *Vxplus /Hxplus  )

#define HNEWYFLUXMINUS  ( Vyminus )
#define HNEWYFLUXPLUS   ( Vyplus  )
#define VNEWYFLUXMINUS  ( SQ(Vyminus)/Hyminus + ghalf*SQ(Hyminus) )
#define VNEWYFLUXPLUS   ( SQ(Vyplus) /Hyplus  + ghalf*SQ(Hyplus)  )
#define VUNEWFLUXMINUS  ( Vyminus*Uyminus/Hyminus )
#define VUNEWFLUXPLUS   ( Vyplus *Uyplus /Hyplus )

// XXX ADDED XXX
#define HXFLUXNLT ( Ult )
#define HXFLUXNRT ( Urt )
#define UXFLUXNLT ( SQR(Ult)/Hlt + ghalf*SQR(Hlt) )
#define UXFLUXNRT ( SQR(Urt)/Hrt + ghalf*SQR(Hrt) )
#define UVFLUXNLT ( Ult*Vlt/Hlt )
#define UVFLUXNRT ( Urt*Vrt/Hrt )
#define HYFLUXNBR ( Vbr )
#define HYFLUXNTR ( Vtr )
#define VUFLUXNBR  ( Vbr*Ubr/Hbr )
#define VUFLUXNTR  ( Vtr*Utr/Htr )
#define VYFLUXNBR  ( SQR(Vbr)/Hbr + ghalf*SQR(Hbr) )
#define VYFLUXNTR  ( SQR(Vtr)/Htr + ghalf*SQR(Htr) )
#define HNEWXFLUXMINUS2  ( Uxminus2 )
#define HNEWXFLUXPLUS2   ( Uxplus2 )
#define UNEWXFLUXMINUS2  ( SQR(Uxminus2)/Hxminus2 + ghalf*SQR(Hxminus2) )
#define UNEWXFLUXPLUS2   ( SQR(Uxplus2) /Hxplus2 +  ghalf*SQR(Hxplus2)  )
#define UVNEWFLUXMINUS2  ( Uxminus2*Vxminus2/Hxminus2 )
#define UVNEWFLUXPLUS2   ( Uxplus2 *Vxplus2 /Hxplus2  )
#define HNEWYFLUXMINUS2  ( Vyminus2 )
#define HNEWYFLUXPLUS2   ( Vyplus2  )
#define VNEWYFLUXMINUS2  ( SQR(Vyminus2)/Hyminus2 + ghalf*SQR(Hyminus2) )
#define VNEWYFLUXPLUS2   ( SQR(Vyplus2) /Hyplus2  + ghalf*SQR(Hyplus2)  )
#define VUNEWFLUXMINUS2  ( Vyminus2*Uyminus2/Hyminus2 )
#define VUNEWFLUXPLUS2   ( Vyplus2 *Uyplus2 /Hyplus2 )

void State::calc_finite_difference(double deltaT){
   real_t   g     = 9.80;   // gravitational constant
   real_t   ghalf = 0.5*g;

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   size_t ncells     = mesh->ncells;
   size_t &ncells_ghost = mesh->ncells_ghost;
#ifdef _OPENMP
#pragma omp master
#endif
   if (ncells_ghost < ncells) ncells_ghost = ncells;

   //printf("\nDEBUG finite diff\n"); 

#ifdef HAVE_MPI
   // We need to populate the ghost regions since the calc neighbors has just been
   // established for the mesh shortly before
   if (mesh->numpe > 1) {
      apply_boundary_conditions_local();

#ifdef _OPENMP
#pragma omp master
      {
#endif
      H=(state_t *)state_memory.memory_realloc(ncells_ghost, H);
      U=(state_t *)state_memory.memory_realloc(ncells_ghost, U);
      V=(state_t *)state_memory.memory_realloc(ncells_ghost, V);

      L7_Update(&H[0], L7_STATE_T, mesh->cell_handle);
      L7_Update(&U[0], L7_STATE_T, mesh->cell_handle);
      L7_Update(&V[0], L7_STATE_T, mesh->cell_handle);
#ifdef _OPENMP
      }
#pragma omp barrier
#endif

      apply_boundary_conditions_ghost();
   } else {
      apply_boundary_conditions();
   }
#else
   apply_boundary_conditions();
#endif

   static state_t *H_new, *U_new, *V_new;
   int *nlft, *nrht, *nbot, *ntop, *level;

   nlft  = mesh->nlft;
   nrht  = mesh->nrht;
   nbot  = mesh->nbot;
   ntop  = mesh->ntop;
   level = mesh->level;

   vector<real_t> &lev_deltax = mesh->lev_deltax;
   vector<real_t> &lev_deltay = mesh->lev_deltay;

   int flags = 0;
   flags = RESTART_DATA;
#if defined (HAVE_J7)
   if (mesh->parallel) flags = LOAD_BALANCE_MEMORY;
#endif

#ifdef _OPENMP
#pragma omp master
#endif
   {
      H_new = (state_t *)state_memory.memory_malloc(ncells_ghost,
                                                    sizeof(state_t),
                                                    "H_new", flags);
      U_new = (state_t *)state_memory.memory_malloc(ncells_ghost,
                                                    sizeof(state_t),
                                                    "U_new", flags);
      V_new = (state_t *)state_memory.memory_malloc(ncells_ghost,
                                                    sizeof(state_t),
                                                    "V_new", flags);
   }
#ifdef _OPENMP
#pragma omp barrier
#endif

   int lowerBound, upperBound;
   mesh->get_bounds(lowerBound, upperBound);

   for(int gix = lowerBound; gix < upperBound; gix++) {
#if DEBUG >= 3
      printf("%d: DEBUG gix is %d at line %d in file %s\n",mesh->mype,gix,__LINE__,__FILE__);
#endif

      int lvl     = level[gix];
      int nl      = nlft[gix];
      int nr      = nrht[gix];
      int nt      = ntop[gix];
      int nb      = nbot[gix];

      real_t Hic     = H[gix];
      real_t Uic     = U[gix];
      real_t Vic     = V[gix];

#if DEBUG >= 3
      if (nl < 0 || nl >= ncells_ghost ) printf("%d: Problem at file %s line %d with nl %ld\n",mesh->mype,__FILE__,__LINE__,nl);
#endif
      int nll     = nlft[nl];
      real_t Hl      = H[nl];
      real_t Ul      = U[nl];
      real_t Vl      = V[nl];

#if DEBUG >= 3
      if (nr < 0 || nr >= ncells_ghost ) printf("%d: Problem at file %s line %d with nr %ld\n",mesh->mype,__FILE__,__LINE__,nr);
#endif
      int nrr     = nrht[nr];
      real_t Hr      = H[nr];
      real_t Ur      = U[nr];
      real_t Vr      = V[nr];

#if DEBUG >= 3
      if (nt < 0 || nt >= ncells_ghost ) printf("%d: Problem at file %s line %d with nt %ld\n",mesh->mype,__FILE__,__LINE__,nt);
#endif
      int ntt     = ntop[nt];
      real_t Ht      = H[nt];
      real_t Ut      = U[nt];
      real_t Vt      = V[nt];

#if DEBUG >= 3
      if (nb < 0 || nb >= ncells_ghost ) printf("%d: Problem at file %s line %d with nb %ld\n",mesh->mype,__FILE__,__LINE__,nb);
#endif
      int nbb     = nbot[nb];
      real_t Hb      = H[nb];
      real_t Ub      = U[nb];
      real_t Vb      = V[nb];

      int nlt     = ntop[nl];
      int nrt     = ntop[nr];
      int ntr     = nrht[nt];
      int nbr     = nrht[nb];

#if DEBUG >= 3
      if (nll < 0 || nll >= ncells_ghost ) printf("%d: Problem at file %s line %d with nll %ld\n",mesh->mype,__FILE__,__LINE__,nll);
#endif
      real_t Hll     = H[nll];
      real_t Ull     = U[nll];
      //real_t Vll     = V[nll];

#if DEBUG >= 3
      if (nrr < 0 || nrr >= ncells_ghost ) printf("%d: Problem at file %s line %d with nrr %ld\n",mesh->mype,__FILE__,__LINE__,nrr);
#endif
      real_t Hrr     = H[nrr];
      real_t Urr     = U[nrr];
      //real_t Vrr     = V[nrr];

#if DEBUG >= 3
      if (ntt < 0 || ntt >= ncells_ghost ) printf("%d: Problem at file %s line %d with ntt %ld\n",mesh->mype,__FILE__,__LINE__,ntt);
#endif
      real_t Htt     = H[ntt];
      //real_t Utt     = U[ntt];
      real_t Vtt     = V[ntt];

#if DEBUG >= 3
      if (nbb < 0 || nbb >= ncells_ghost ) {printf("%d: Problem at file %s line %d ic %d %d with nbb %ld\n",mesh->mype,__FILE__,__LINE__,gix,gix+mesh->noffset,nbb); sleep(15); }
#endif
      real_t Hbb     = H[nbb];
      //real_t Ubb     = U[nbb];
      real_t Vbb     = V[nbb];

#if DEBUG >= 3
      if (lvl < 0 || lvl >= (int)lev_deltax.size() ) printf("%d: Problem at file %s line %d with lvl %d\n",mesh->mype,__FILE__,__LINE__,lvl);
#endif
      real_t dxic    = lev_deltax[lvl];
      real_t dyic    = lev_deltay[lvl];

      real_t dxl     = lev_deltax[level[nl]];
      real_t dxr     = lev_deltax[level[nr]];

      real_t dyt     = lev_deltay[level[nt]];
      real_t dyb     = lev_deltay[level[nb]];

      real_t drl     = dxl;
      real_t drr     = dxr;
      real_t drt     = dyt;
      real_t drb     = dyb;

      real_t dric    = dxic;

      int nltl = 0;
      real_t Hlt = 0.0, Ult = 0.0, Vlt = 0.0;
      real_t Hll2 = 0.0;
      real_t Ull2 = 0.0;
      if(lvl < level[nl]) {
#if DEBUG >= 3
         if (nlt < 0 || nlt > ncells_ghost ) printf("%d: Problem at file %s line %d with nlt %ld\n",mesh->mype,__FILE__,__LINE__,nlt);
#endif
         Hlt  = H[ ntop[nl] ];
         Ult  = U[ ntop[nl] ];
         Vlt  = V[ ntop[nl] ];
         nltl = nlft[nlt];
#if DEBUG >= 3
         if (nltl < 0 || nltl > ncells_ghost ) printf("%d: Problem at file %s line %d with nltl %ld\n",mesh->mype,__FILE__,__LINE__,nltl);
#endif
         Hll2 = H[nltl];
         Ull2 = U[nltl];
      }

      int nrtr = 0;
      real_t Hrt = 0.0, Urt = 0.0, Vrt = 0.0;
      real_t Hrr2 = 0.0;
      real_t Urr2 = 0.0;
      if(lvl < level[nr]) {
#if DEBUG >= 3
         if (nrt < 0 || nrt > ncells_ghost ) printf("%d: Problem at file %s line %d with nrt %ld\n",mesh->mype,__FILE__,__LINE__,nrt);
#endif
         Hrt  = H[ ntop[nr] ];
         Urt  = U[ ntop[nr] ];
         Vrt  = V[ ntop[nr] ];
         nrtr = nrht[nrt];
#if DEBUG >= 3
         if (nrtr < 0 || nrtr > ncells_ghost ) printf("%d: Problem at file %s line %d with nrtr %ld\n",mesh->mype,__FILE__,__LINE__,nrtr);
#endif
         Hrr2 = H[nrtr];
         Urr2 = U[nrtr];
      }

      int nbrb = 0;
      real_t Hbr = 0.0, Ubr = 0.0, Vbr = 0.0;
      real_t Hbb2 = 0.0;
      real_t Vbb2 = 0.0;
      if(lvl < level[nb]) {
#if DEBUG >= 3
         if (nbr < 0 || nbr > ncells_ghost ) printf("%d: Problem at file %s line %d with nbr %ld\n",mesh->mype,__FILE__,__LINE__,nbr);
#endif
         Hbr  = H[ nrht[nb] ];
         Ubr  = U[ nrht[nb] ];
         Vbr  = V[ nrht[nb] ];
         nbrb = nbot[nbr];
#if DEBUG >= 3
         if (nbrb < 0 || nbrb > ncells_ghost ) {printf("%d: Problem at file %s line %d ic %d %d with nbrb %ld\n",mesh->mype,__FILE__,__LINE__,gix,gix+mesh->noffset,nbrb); sleep(20);}
#endif
         Hbb2 = H[nbrb];
         Vbb2 = V[nbrb];
      }

      int ntrt = 0;
      real_t Htr = 0.0, Utr = 0.0, Vtr = 0.0;
      real_t Htt2 = 0.0;
      real_t Vtt2 = 0.0;
      if(lvl < level[nt]) {
#if DEBUG >= 3
         if (ntr < 0 || ntr > ncells_ghost ) printf("%d: Problem at file %s line %d with ntr %ld\n",mesh->mype,__FILE__,__LINE__,ntr);
#endif
         Htr  = H[ nrht[nt] ];
         Utr  = U[ nrht[nt] ];
         Vtr  = V[ nrht[nt] ];
         ntrt = ntop[ntr];
#if DEBUG >= 3
         if (ntrt < 0 || ntrt > ncells_ghost ) {printf("%d: Problem at file %s line %d ic %d %d with ntrt %ld\n",mesh->mype,__FILE__,__LINE__,gix,gix+mesh->noffset,ntrt); sleep(20); }
#endif
         Htt2 = H[ntrt];
         Vtt2 = V[ntrt];
      }


      real_t Hxminus = U_halfstep(deltaT, Hl, Hic, HXFLUXNL, HXFLUXIC,
                           dxl, dxic, dxl, dxic, SQR(dxl), SQR(dxic));
      real_t Uxminus = U_halfstep(deltaT, Ul, Uic, UXFLUXNL, UXFLUXIC,
                           dxl, dxic, dxl, dxic, SQR(dxl), SQR(dxic));
      real_t Vxminus = U_halfstep(deltaT, Vl, Vic, UVFLUXNL, UVFLUXIC,
                           dxl, dxic, dxl, dxic, SQR(dxl), SQR(dxic));

      real_t Hxplus  = U_halfstep(deltaT, Hic, Hr, HXFLUXIC, HXFLUXNR,
                           dxic, dxr, dxic, dxr, SQR(dxic), SQR(dxr));
      real_t Uxplus  = U_halfstep(deltaT, Uic, Ur, UXFLUXIC, UXFLUXNR,
                           dxic, dxr, dxic, dxr, SQR(dxic), SQR(dxr));
      real_t Vxplus  = U_halfstep(deltaT, Vic, Vr, UVFLUXIC, UVFLUXNR,
                           dxic, dxr, dxic, dxr, SQR(dxic), SQR(dxr));

      real_t Hyminus = U_halfstep(deltaT, Hb, Hic, HYFLUXNB, HYFLUXIC,
                           dyb, dyic, dyb, dyic, SQR(dyb), SQR(dyic));
      real_t Uyminus = U_halfstep(deltaT, Ub, Uic, VUFLUXNB, VUFLUXIC,
                           dyb, dyic, dyb, dyic, SQR(dyb), SQR(dyic));
      real_t Vyminus = U_halfstep(deltaT, Vb, Vic, VYFLUXNB, VYFLUXIC,
                           dyb, dyic, dyb, dyic, SQR(dyb), SQR(dyic));

      real_t Hyplus  = U_halfstep(deltaT, Hic, Ht, HYFLUXIC, HYFLUXNT,
                           dyic, dyt, dyic, dyt, SQR(dyic), SQR(dyt));
      real_t Uyplus  = U_halfstep(deltaT, Uic, Ut, VUFLUXIC, VUFLUXNT,
                           dyic, dyt, dyic, dyt, SQR(dyic), SQR(dyt));
      real_t Vyplus  = U_halfstep(deltaT, Vic, Vt, VYFLUXIC, VYFLUXNT,
                           dyic, dyt, dyic, dyt, SQR(dyic), SQR(dyt));

      real_t Hxfluxminus = HNEWXFLUXMINUS;
      real_t Uxfluxminus = UNEWXFLUXMINUS;
      real_t Vxfluxminus = UVNEWFLUXMINUS;

      real_t Hxfluxplus  = HNEWXFLUXPLUS;
      real_t Uxfluxplus  = UNEWXFLUXPLUS;
      real_t Vxfluxplus  = UVNEWFLUXPLUS;

      real_t Hyfluxminus = HNEWYFLUXMINUS;
      real_t Uyfluxminus = VUNEWFLUXMINUS;
      real_t Vyfluxminus = VNEWYFLUXMINUS;

      real_t Hyfluxplus  = HNEWYFLUXPLUS;
      real_t Uyfluxplus  = VUNEWFLUXPLUS;
      real_t Vyfluxplus  = VNEWYFLUXPLUS;

      real_t Hxminus2 = 0.0;
      real_t Uxminus2 = 0.0;
      real_t Vxminus2 = 0.0;
      if(lvl < level[nl]) {

         Hxminus2 = U_halfstep(deltaT, Hlt, Hic, HXFLUXNLT, HXFLUXIC,
                               drl, dric, drl, dric, SQR(drl), SQR(dric));
         Uxminus2 = U_halfstep(deltaT, Ult, Uic, UXFLUXNLT, UXFLUXIC,
                               drl, dric, drl, dric, SQR(drl), SQR(dric));
         Vxminus2 = U_halfstep(deltaT, Vlt, Vic, UVFLUXNLT, UVFLUXIC,
                               drl, dric, drl, dric, SQR(drl), SQR(dric));

         Hxfluxminus = (Hxfluxminus + HNEWXFLUXMINUS2) * HALF;
         Uxfluxminus = (Uxfluxminus + UNEWXFLUXMINUS2) * HALF;
         Vxfluxminus = (Vxfluxminus + UVNEWFLUXMINUS2) * HALF;

      }

      real_t Hxplus2 = 0.0;
      real_t Uxplus2 = 0.0;
      real_t Vxplus2 = 0.0;
      if(lvl < level[nr]) {

         Hxplus2  = U_halfstep(deltaT, Hic, Hrt, HXFLUXIC, HXFLUXNRT,
                               dric, drr, dric, drr, SQR(dric), SQR(drr));
         Uxplus2  = U_halfstep(deltaT, Uic, Urt, UXFLUXIC, UXFLUXNRT,
                               dric, drr, dric, drr, SQR(dric), SQR(drr));
         Vxplus2  = U_halfstep(deltaT, Vic, Vrt, UVFLUXIC, UVFLUXNRT,
                               dric, drr, dric, drr, SQR(dric), SQR(drr));

         Hxfluxplus  = (Hxfluxplus + HNEWXFLUXPLUS2) * HALF;
         Uxfluxplus  = (Uxfluxplus + UNEWXFLUXPLUS2) * HALF;
         Vxfluxplus  = (Vxfluxplus + UVNEWFLUXPLUS2) * HALF;

      }

      real_t Hyminus2 = 0.0;
      real_t Uyminus2 = 0.0;
      real_t Vyminus2 = 0.0;
      if(lvl < level[nb]) {

         Hyminus2 = U_halfstep(deltaT, Hbr, Hic, HYFLUXNBR, HYFLUXIC,
                               drb, dric, drb, dric, SQR(drb), SQR(dric));
         Uyminus2 = U_halfstep(deltaT, Ubr, Uic, VUFLUXNBR, VUFLUXIC,
                               drb, dric, drb, dric, SQR(drb), SQR(dric));
         Vyminus2 = U_halfstep(deltaT, Vbr, Vic, VYFLUXNBR, VYFLUXIC,
                               drb, dric, drb, dric, SQR(drb), SQR(dric));

         Hyfluxminus = (Hyfluxminus + HNEWYFLUXMINUS2) * HALF;
         Uyfluxminus = (Uyfluxminus + VUNEWFLUXMINUS2) * HALF;
         Vyfluxminus = (Vyfluxminus + VNEWYFLUXMINUS2) * HALF;

      }

      real_t Hyplus2 = 0.0;
      real_t Uyplus2 = 0.0;
      real_t Vyplus2 = 0.0;
      if(lvl < level[nt]) {

         Hyplus2  = U_halfstep(deltaT, Hic, Htr, HYFLUXIC, HYFLUXNTR,
                               dric, drt, dric, drt, SQR(dric), SQR(drt));
         Uyplus2  = U_halfstep(deltaT, Uic, Utr, VUFLUXIC, VUFLUXNTR,
                               dric, drt, dric, drt, SQR(dric), SQR(drt));
         Vyplus2  = U_halfstep(deltaT, Vic, Vtr, VYFLUXIC, VYFLUXNTR,
                               dric, drt, dric, drt, SQR(dric), SQR(drt));

         Hyfluxplus  = (Hyfluxplus + HNEWYFLUXPLUS2) * HALF;
         Uyfluxplus  = (Uyfluxplus + VUNEWFLUXPLUS2) * HALF;
         Vyfluxplus  = (Vyfluxplus + VNEWYFLUXPLUS2) * HALF;

      }

      //if (DEBUG >= 2) {
      // printf("1st pass x direction nz %d nzlower %d nzupper %d %lf %lf %lf %lf %lf %lf\n",
      //    gix, nl, nr,
      //    Hxplus,Hxplus2,Uxplus,Uxplus2,Vxplus,Vxplus2);
      //    //H[cell_upper],H[cell_lower],U[cell_upper],U[cell_lower],V[cell_upper],V[cell_lower]);
      //}

      ////////////////////////////////////////
      /// Artificial Viscosity corrections ///
      ////////////////////////////////////////


      if(level[nl] < level[nll]) {
#if DEBUG >= 3
         size_t nllt = ntop[nll];
         if (nllt < 0 || nllt >= ncells_ghost ) printf("%d: Problem at file %s line %d with nllt %ld\n",mesh->mype,__FILE__,__LINE__,nllt);
#endif
         Hll = (Hll + H[ ntop[nll] ]) * HALF;
         Ull = (Ull + U[ ntop[nll] ]) * HALF;
      }

      real_t Hr2 = Hr;
      real_t Ur2 = Ur;
      if(lvl < level[nr]) {
         Hr2 = (Hr2 + Hrt) * HALF;
         Ur2 = (Ur2 + Urt) * HALF;
      }

      real_t wminusx_H = w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus/Hxminus) + sqrt(g*Hxminus),
                              Hic-Hl, Hl-Hll, Hr2-Hic);

      wminusx_H *= Hic - Hl;

      if(lvl < level[nl]) {
         if(level[nlt] < level[nltl])
            Hll2 = (Hll2 + H[ ntop[nltl] ]) * HALF;
         wminusx_H = ((w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus2/Hxminus2) +
                                  sqrt(g*Hxminus2), Hic-Hlt, Hlt-Hll2, Hr2-Hic) *
                      (Hic - Hlt)) + wminusx_H)*HALF*HALF;
      }


      if(level[nr] < level[nrr]) {
#if DEBUG >= 3
         size_t nrrt = ntop[nrr];
         if (nrrt < 0 || nrrt >= ncells_ghost ) printf("%d: Problem at file %s line %d with nrrt %ld\n",mesh->mype,__FILE__,__LINE__,nrrt);
#endif
         Hrr = (Hrr + H[ ntop[nrr] ]) * HALF;
         Urr = (Urr + U[ ntop[nrr] ]) * HALF;
      }

      real_t Hl2 = Hl;
      real_t Ul2 = Ul;
      if(lvl < level[nl]) {
         Hl2 = (Hl2 + Hlt) * HALF;
         Ul2 = (Ul2 + Ult) * HALF;
      }

      real_t wplusx_H = w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus/Hxplus) + sqrt(g*Hxplus),
                           Hr-Hic, Hic-Hl2, Hrr-Hr);

      wplusx_H *= Hr - Hic;

      if(lvl < level[nr]) {
         if(level[nrt] < level[nrtr])
            Hrr2 = (Hrr2 + H[ ntop[nrtr] ]) * HALF;
         wplusx_H = ((w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus2/Hxplus2) +
                                  sqrt(g*Hxplus2), Hrt-Hic, Hic-Hl2, Hrr2-Hrt) *
                      (Hrt - Hic))+wplusx_H)*HALF*HALF;
      }


      real_t wminusx_U = w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus/Hxminus) + sqrt(g*Hxminus),
                              Uic-Ul, Ul-Ull, Ur2-Uic);

      wminusx_U *= Uic - Ul;

      if(lvl < level[nl]) {
         if(level[nlt] < level[nltl])
            Ull2 = (Ull2 + U[ ntop[nltl] ]) * HALF;
         wminusx_U = ((w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus2/Hxminus2) +
                                  sqrt(g*Hxminus2), Uic-Ult, Ult-Ull2, Ur2-Uic) *
                      (Uic - Ult))+wminusx_U)*HALF*HALF;
      }


      real_t wplusx_U = w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus/Hxplus) + sqrt(g*Hxplus),
                              Ur-Uic, Uic-Ul2, Urr-Ur);

      wplusx_U *= Ur - Uic;

      if(lvl < level[nr]) {
         if(level[nrt] < level[nrtr])
            Urr2 = (Urr2 + U[ ntop[nrtr] ]) * HALF;
         wplusx_U = ((w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus2/Hxplus2) +
                                  sqrt(g*Hxplus2), Urt-Uic, Uic-Ul2, Urr2-Urt) *
                      (Urt - Uic))+wplusx_U)*HALF*HALF;
      }


      if(level[nb] < level[nbb]) {
#if DEBUG >= 3
         size_t nbbr = nrht[nbb];
         if (nbbr < 0 || nbbr >= ncells_ghost ) printf("%d: Problem at file %s line %d gix %d %d with nbbr %ld\n",mesh->mype,__FILE__,__LINE__,gix,gix+mesh->noffset,nbbr);
#endif
         Hbb = (Hbb + H[ nrht[nbb] ]) * HALF;
         Vbb = (Vbb + V[ nrht[nbb] ]) * HALF;
      }

      real_t Ht2 = Ht;
      real_t Vt2 = Vt;
      if(lvl < level[nt]) {
         Ht2 = (Ht2 + Htr) * HALF;
         Vt2 = (Vt2 + Vtr) * HALF;
      }

      real_t wminusy_H = w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus/Hyminus) + sqrt(g*Hyminus),
                              Hic-Hb, Hb-Hbb, Ht2-Hic);

      wminusy_H *= Hic - Hb;

      if(lvl < level[nb]) {
         if(level[nbr] < level[nbrb])
            Hbb2 = (Hbb2 + H[ nrht[nbrb] ]) * HALF;
         wminusy_H = ((w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus2/Hyminus2) +
                                  sqrt(g*Hyminus2), Hic-Hbr, Hbr-Hbb2, Ht2-Hic) *
                      (Hic - Hbr))+wminusy_H)*HALF*HALF;
      }


      if(level[nt] < level[ntt]) {
#if DEBUG >= 3
         size_t nttr = nrht[ntt];
         if (nttr < 0 || nttr >= ncells_ghost ) printf("%d: Problem at file %s line %d with nttr %ld\n",mesh->mype,__FILE__,__LINE__,nttr);
#endif
         Htt = (Htt + H[ nrht[ntt] ]) * HALF;
         Vtt = (Vtt + V[ nrht[ntt] ]) * HALF;
      }

      real_t Hb2 = Hb;
      real_t Vb2 = Vb;
      if(lvl < level[nb]) {
         Hb2 = (Hb2 + Hbr) * HALF;
         Vb2 = (Vb2 + Vbr) * HALF;
      }

      real_t wplusy_H = w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus/Hyplus) + sqrt(g*Hyplus),
                             Ht-Hic, Hic-Hb2, Htt-Ht);

      wplusy_H *= Ht - Hic;

      if(lvl < level[nt]) {
         if(level[ntr] < level[ntrt])
            Htt2 = (Htt2 + H[ nrht[ntrt] ]) * HALF;
         wplusy_H = ((w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus2/Hyplus2) +
                                  sqrt(g*Hyplus2), Htr-Hic, Hic-Hb2, Htt2-Htr) *
                      (Htr - Hic))+wplusy_H)*HALF*HALF;
      }

      real_t wminusy_V = w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus/Hyminus) + sqrt(g*Hyminus),
                              Vic-Vb, Vb-Vbb, Vt2-Vic);

      wminusy_V *= Vic - Vb;

      if(lvl < level[nb]) {
         if(level[nbr] < level[nbrb])
            Vbb2 = (Vbb2 + V[ nrht[nbrb] ]) * HALF;
         wminusy_V = ((w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus2/Hyminus2) +
                                  sqrt(g*Hyminus2), Vic-Vbr, Vbr-Vbb2, Vt2-Vic) *
                      (Vic - Vbr))+wminusy_V)*HALF*HALF;
      }

      real_t wplusy_V = w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus/Hyplus) + sqrt(g*Hyplus),
                           Vt-Vic, Vic-Vb2, Vtt-Vt);

      wplusy_V *= Vt - Vic;

      if(lvl < level[nt]) {
         if(level[ntr] < level[ntrt])
            Vtt2 = (Vtt2 + V[ nrht[ntrt] ]) * HALF;
         wplusy_V = ((w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus2/Hyplus2) +
                                  sqrt(g*Hyplus2), Vtr-Vic, Vic-Vb2, Vtt2-Vtr) *
                      (Vtr - Vic))+wplusy_V)*HALF*HALF;
      }

      H_new[gix] = U_fullstep(deltaT, dxic, Hic,
                       Hxfluxplus, Hxfluxminus, Hyfluxplus, Hyfluxminus)
                  - wminusx_H + wplusx_H - wminusy_H + wplusy_H;
      U_new[gix] = U_fullstep(deltaT, dxic, Uic,
                       Uxfluxplus, Uxfluxminus, Uyfluxplus, Uyfluxminus)
                  - wminusx_U + wplusx_U;
      V_new[gix] = U_fullstep(deltaT, dxic, Vic,
                       Vxfluxplus, Vxfluxminus, Vyfluxplus, Vyfluxminus)
                  - wminusy_V + wplusy_V;

#if DEBUG >= 1
      if (DEBUG >= 1) {
         real_t U_tmp = U_new[gix];
         real_t V_tmp = V_new[gix];
         if (U_tmp == 0.0) U_tmp = 0.0;
         if (V_tmp == 0.0) V_tmp = 0.0;
         printf("DEBUG ic %d H_new %lf U_new %lf V_new %lf\n",gix,H_new[gix],U_tmp,V_tmp);
      }
#endif

/*
      printf("DEBUG ic %d deltaT, %lf dxic, %lf Hic, %lf Hxfluxplus, %lf Hxfluxminus, %lf Hyfluxplus, %lf Hyfluxminus %lf\n",
         gix, deltaT, dxic, Hic, Hxfluxplus, Hxfluxminus, Hyfluxplus, Hyfluxminus);
      printf("DEBUG ic %d wminusx_H %lf wplusx_H %lf wminusy_H %lf wplusy_H %lf\n",gix, wminusx_H, wplusx_H, wminusy_H, wplusy_H);
      printf("DEBUG ic %d deltaT, %lf dxic, %lf Vic, %lf Vxfluxplus, %lf Vxfluxminus, %lf Vyfluxplus, %lf Vyfluxminus %lf\n",
         gix, deltaT, dxic, Vic, Vxfluxplus, Vxfluxminus, Vyfluxplus, Vyfluxminus);
      printf("DEBUG ic %d wminusy_V %lf wplusy_V %lf\n",gix, wminusy_V, wplusy_V);
*/
   } // cell loop

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
      // Replace H with H_new and deallocate H. New memory will have the characteristics
      // of the new memory and the name of the old. Both return and arg1 will be reset to new memory
      H = (state_t *)state_memory.memory_replace(H, H_new);
      U = (state_t *)state_memory.memory_replace(U, U_new);
      V = (state_t *)state_memory.memory_replace(V, V_new);

      //state_memory.memory_report();
      //printf("DEBUG end finite diff\n\n"); 
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

#ifdef _OPENMP
#pragma omp master
#endif
      cpu_timers[STATE_TIMER_FINITE_DIFFERENCE] += cpu_timer_stop(tstart_cpu);
}

void State::calc_finite_difference_via_faces(double deltaT){
   real_t   g     = 9.80;   // gravitational constant
   real_t   ghalf = HALF*g;

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   size_t ncells     = mesh->ncells;
   size_t &ncells_ghost = mesh->ncells_ghost;
#ifdef _OPENMP
#pragma omp master
#endif
   if (ncells_ghost < ncells) ncells_ghost = ncells;

   //printf("\nDEBUG finite diff\n");

#ifdef HAVE_MPI
   // We need to populate the ghost regions since the calc neighbors has just been
   // established for the mesh shortly before
   if (mesh->numpe > 1) {
      apply_boundary_conditions_local();

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master 
      {
#endif
         H=(state_t *)state_memory.memory_realloc(ncells_ghost, H);
         U=(state_t *)state_memory.memory_realloc(ncells_ghost, U);
         V=(state_t *)state_memory.memory_realloc(ncells_ghost, V);

         L7_Update(&H[0], L7_STATE_T, mesh->cell_handle);
         L7_Update(&U[0], L7_STATE_T, mesh->cell_handle);
         L7_Update(&V[0], L7_STATE_T, mesh->cell_handle);
#ifdef _OPENMP
      }
#pragma omp barrier
#endif

      apply_boundary_conditions_ghost();
   } else {
      apply_boundary_conditions();
   }
#else
   apply_boundary_conditions();
#endif

   int *nlft, *nrht, *nbot, *ntop, *level;

   nlft  = mesh->nlft;
   nrht  = mesh->nrht;
   nbot  = mesh->nbot;
   ntop  = mesh->ntop;
   level = mesh->level;

   vector<real_t> &lev_deltax = mesh->lev_deltax;
   vector<real_t> &lev_deltay = mesh->lev_deltay;

   int flags = 0;
   flags = RESTART_DATA;
#if defined (HAVE_J7)
   if (mesh->parallel) flags = LOAD_BALANCE_MEMORY;
#endif

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
   mesh->calc_face_list_wbidirmap();
#ifdef _OPENMP
   }
#endif

   static vector<state_t> Hx, Ux, Vx;

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
   Hx.resize(mesh->nxface);
   Ux.resize(mesh->nxface);
   Vx.resize(mesh->nxface);
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

#ifdef _OPENMP
#pragma omp for 
#endif
   for (int iface = 0; iface < mesh->nxface; iface++){
      int cell_lower = mesh->map_xface2cell_lower[iface];
      int cell_upper = mesh->map_xface2cell_upper[iface];
      int level_lower = level[cell_lower];
      int level_upper = level[cell_upper];
      if (level_lower == level_upper) {
         int lev = level_upper;
         real_t Cxhalf = 0.5*deltaT/mesh->lev_deltax[lev];
         Hx[iface]=HALF*(H[cell_upper]+H[cell_lower]) - Cxhalf*( HXFLUX(cell_upper)-HXFLUX(cell_lower) );
         Ux[iface]=HALF*(U[cell_upper]+U[cell_lower]) - Cxhalf*( UXFLUX(cell_upper)-UXFLUX(cell_lower) );
         Vx[iface]=HALF*(V[cell_upper]+V[cell_lower]) - Cxhalf*( UVFLUX(cell_upper)-UVFLUX(cell_lower) );
      } else {
         real_t dx_lower = mesh->lev_deltax[level[cell_lower]];
         real_t dx_upper = mesh->lev_deltax[level[cell_upper]];

         real_t FA_lower = dx_lower;
         real_t FA_upper = dx_upper;
         real_t FA_lolim = FA_lower*min(ONE, FA_upper/FA_lower);
         real_t FA_uplim = FA_upper*min(ONE, FA_lower/FA_upper);

         real_t CV_lower = SQ(dx_lower);
         real_t CV_upper = SQ(dx_upper);
         real_t CV_lolim = CV_lower*min(HALF, CV_upper/CV_lower);
         real_t CV_uplim = CV_upper*min(HALF, CV_lower/CV_upper);

         // Weighted half-step calculation
         //
         // (dx_lower*H[cell_upper]+dx_upper*H[cell_lower])
         // -----------------------------------------------   -
         //             (dx_lower+dx_upper)
         //
         //                ( (FA_uplim*HXFLUX(cell_upper))-(FA_lolim*HXFLUX(cell_lower)) )
         // 0.5*deltaT  *  ----------------------------------------------------------------
         //                                    (CV_uplim+CV_lolim)
         //

         Hx[iface]=(dx_lower*H[cell_upper]+dx_upper*H[cell_lower])/(dx_lower+dx_upper) -
                   HALF*deltaT*( (FA_uplim*HXFLUX(cell_upper))-(FA_lolim*HXFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);
         Ux[iface]=(dx_lower*U[cell_upper]+dx_upper*U[cell_lower])/(dx_lower+dx_upper) -
                   HALF*deltaT*( (FA_uplim*UXFLUX(cell_upper))-(FA_lolim*UXFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);
         Vx[iface]=(dx_lower*V[cell_upper]+dx_upper*V[cell_lower])/(dx_lower+dx_upper) -
                   HALF*deltaT*( (FA_uplim*UVFLUX(cell_upper))-(FA_lolim*UVFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);
      }
#if DEBUG >= 2
      if (DEBUG >= 2) {
         printf("1st pass x direction iface %d i %d j %d lev %d nzlower %d nzupper %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
            iface, mesh->xface_i[iface], mesh->xface_j[iface], mesh->xface_level[iface],
            mesh->map_xface2cell_lower[iface], mesh->map_xface2cell_upper[iface],
            Hx[iface],Ux[iface],Vx[iface],
            H[cell_upper],H[cell_lower],U[cell_upper],U[cell_lower],V[cell_upper],V[cell_lower]);
      }
#endif
   }
#if DEBUG >= 2
   if (DEBUG >= 2) {
      printf("\n");
   }
#endif

   static vector<state_t> Hy, Uy, Vy;

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
   Hy.resize(mesh->nyface);
   Uy.resize(mesh->nyface);
   Vy.resize(mesh->nyface);
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

#ifdef _OPENMP
#pragma omp for 
#endif
   for (int iface = 0; iface < mesh->nyface; iface++){
      int cell_lower = mesh->map_yface2cell_lower[iface];
      int cell_upper = mesh->map_yface2cell_upper[iface];
      int level_lower = level[cell_lower];
      int level_upper = level[cell_upper];
      if (level_lower == level_upper) {
         int lev = level_upper;
         real_t Cyhalf = 0.5*deltaT/mesh->lev_deltay[lev];
         Hy[iface]=HALF*(H[cell_upper]+H[cell_lower]) - Cyhalf*( HYFLUX(cell_upper)-HYFLUX(cell_lower) );
         Uy[iface]=HALF*(U[cell_upper]+U[cell_lower]) - Cyhalf*( UVFLUX(cell_upper)-UVFLUX(cell_lower) );
         Vy[iface]=HALF*(V[cell_upper]+V[cell_lower]) - Cyhalf*( VYFLUX(cell_upper)-VYFLUX(cell_lower) );
      } else {
         real_t dy_lower = mesh->lev_deltay[level[cell_lower]];
         real_t dy_upper = mesh->lev_deltay[level[cell_upper]];

         real_t FA_lower = dy_lower;
         real_t FA_upper = dy_upper;
         real_t FA_lolim = FA_lower*min(ONE, FA_upper/FA_lower);
         real_t FA_uplim = FA_upper*min(ONE, FA_lower/FA_upper);

         real_t CV_lower = SQ(dy_lower);
         real_t CV_upper = SQ(dy_upper);
         real_t CV_lolim = CV_lower*min(HALF, CV_upper/CV_lower);
         real_t CV_uplim = CV_upper*min(HALF, CV_lower/CV_upper);

         // Weighted half-step calculation
         //
         // (dy_lower*H[cell_upper]+dy_upper*H[cell_lower])
         // -----------------------------------------------   -
         //             (dy_lower+dy_upper)
         //
         //                ( (FA_uplim*HYFLUX(cell_upper))-(FA_lolim*HYFLUX(cell_lower)) )
         // 0.5*deltaT  *  ----------------------------------------------------------------
         //                                    (CV_uplim+CV_lolim)
         //

         Hy[iface]=(dy_lower*H[cell_upper]+dy_upper*H[cell_lower])/(dy_lower+dy_upper) -
                   HALF*deltaT*( (FA_uplim*HYFLUX(cell_upper))-(FA_lolim*HYFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);
         Uy[iface]=(dy_lower*U[cell_upper]+dy_upper*U[cell_lower])/(dy_lower+dy_upper) -
                   HALF*deltaT*( (FA_uplim*UVFLUX(cell_upper))-(FA_lolim*UVFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);
         Vy[iface]=(dy_lower*V[cell_upper]+dy_upper*V[cell_lower])/(dy_lower+dy_upper) -
                   HALF*deltaT*( (FA_uplim*VYFLUX(cell_upper))-(FA_lolim*VYFLUX(cell_lower)) )/
                   (CV_uplim+CV_lolim);

      }

#if DEBUG >= 2
      if (DEBUG >= 2) {
         printf("1st pass y direction iface %d i %d j %d lev %d nzlower %d nzupper %d %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
            iface, mesh->yface_i[iface], mesh->yface_j[iface], mesh->yface_level[iface],
            mesh->map_yface2cell_lower[iface], mesh->map_yface2cell_upper[iface],
            Hy[iface],Uy[iface],Vy[iface],
            H[cell_upper],H[cell_lower],U[cell_upper],U[cell_lower],V[cell_upper],V[cell_lower]);
      }
#endif
   }
#if DEBUG >= 2
   if (DEBUG >= 2) {
      printf("\n");
   }
#endif

   static state_t *H_new, *U_new, *V_new;

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
      H_new = (state_t *)state_memory.memory_malloc(mesh->ncells_ghost, sizeof(state_t), "H_new", flags);
      U_new = (state_t *)state_memory.memory_malloc(mesh->ncells_ghost, sizeof(state_t), "U_new", flags);
      V_new = (state_t *)state_memory.memory_malloc(mesh->ncells_ghost, sizeof(state_t), "V_new", flags);
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

   int lowerBound, upperBound;

   mesh->get_bounds(lowerBound, upperBound);
   for (int ic = lowerBound; ic < upperBound; ic++){

      int lvl     = level[ic];
      int nl      = nlft[ic];
      int nr      = nrht[ic];
      int nt      = ntop[ic];
      int nb      = nbot[ic];

      real_t Hic     = H[ic];
      real_t Uic     = U[ic];
      real_t Vic     = V[ic];

      int nll     = nlft[nl];
      real_t Hl      = H[nl];
      real_t Ul      = U[nl];
      //real_t Vl      = V[nl];

      int nrr     = nrht[nr];
      real_t Hr      = H[nr];
      real_t Ur      = U[nr];
      //real_t Vr      = V[nr];

      int ntt     = ntop[nt];
      real_t Ht      = H[nt];
      //real_t Ut      = U[nt];
      real_t Vt      = V[nt];

      int nbb     = nbot[nb];
      real_t Hb      = H[nb];
      //real_t Ub      = U[nb];
      real_t Vb      = V[nb];

      int nlt     = ntop[nl];
      int nrt     = ntop[nr];
      int ntr     = nrht[nt];
      int nbr     = nrht[nb];

      real_t Hll     = H[nll];
      real_t Ull     = U[nll];
      //real_t Vll     = V[nll];

      real_t Hrr     = H[nrr];
      real_t Urr     = U[nrr];
      //real_t Vrr     = V[nrr];

      real_t Htt     = H[ntt];
      //real_t Utt     = U[ntt];
      real_t Vtt     = V[ntt];

      real_t Hbb     = H[nbb];
      //real_t Ubb     = U[nbb];
      real_t Vbb     = V[nbb];

      real_t dxic    = lev_deltax[lvl];
      //real_t dyic    = lev_deltay[lvl];

      real_t dxl     = lev_deltax[level[nl]];
      real_t dxr     = lev_deltax[level[nr]];

      real_t dyt     = lev_deltay[level[nt]];
      real_t dyb     = lev_deltay[level[nb]];

      //real_t drl     = dxl;
      //real_t drr     = dxr;
      //real_t drt     = dyt;
      //real_t drb     = dyb;

      real_t dric    = dxic;

      int nltl = 0;
      real_t Hlt = 0.0, Ult = 0.0; // Vlt = 0.0;
      real_t Hll2 = 0.0;
      real_t Ull2 = 0.0;
      if(lvl < level[nl]) {
         Hlt  = H[ ntop[nl] ];
         Ult  = U[ ntop[nl] ];
         //Vlt  = V[ ntop[nl] ];

         nltl = nlft[nlt];
         Hll2 = H[nltl];
         Ull2 = U[nltl];
      }

      int nrtr = 0;
      real_t Hrt = 0.0, Urt = 0.0; // Vrt = 0.0;
      real_t Hrr2 = 0.0;
      real_t Urr2 = 0.0;
      if(lvl < level[nr]) {
         Hrt  = H[ ntop[nr] ];
         Urt  = U[ ntop[nr] ];
         //Vrt  = V[ ntop[nr] ];

         nrtr = nrht[nrt];
         Hrr2 = H[nrtr];
         Urr2 = U[nrtr];
      }

      int nbrb = 0;
      real_t Hbr = 0.0, Vbr = 0.0; // Ubr = 0.0
      real_t Hbb2 = 0.0;
      real_t Vbb2 = 0.0;
      if(lvl < level[nb]) {
         Hbr  = H[ nrht[nb] ];
         //Ubr  = U[ nrht[nb] ];
         Vbr  = V[ nrht[nb] ];

         nbrb = nbot[nbr];
         Hbb2 = H[nbrb];
         Vbb2 = V[nbrb];
      }

      int ntrt = 0;
      real_t Htr = 0.0, Vtr = 0.0; // Utr = 0.0
      real_t Htt2 = 0.0;
      real_t Vtt2 = 0.0;
      if(lvl < level[nt]) {
         Htr  = H[ nrht[nt] ];
         //Utr  = U[ nrht[nt] ];
         Vtr  = V[ nrht[nt] ];

         ntrt = ntop[ntr];
         Htt2 = H[ntrt];
         Vtt2 = V[ntrt];
      }

      ////////////////////////////////////////
      /// Artificial Viscosity corrections ///
      ////////////////////////////////////////

      real_t Hxminus = H[ic];
      real_t Uxminus = 0.0;
      real_t Vxminus = 0.0;
      if (mesh->map_xcell2face_left1[ic] >= 0){
         Hxminus  = Hx[mesh->map_xcell2face_left1[ic]];
         Uxminus  = Ux[mesh->map_xcell2face_left1[ic]];
         Vxminus  = Vx[mesh->map_xcell2face_left1[ic]];
      }

      real_t Hxminus2 = 0.0;
      if(lvl < level[nl]) Hxminus2 = H[ic];
      real_t Uxminus2 = 0.0;
      real_t Vxminus2 = 0.0;
      if (mesh->map_xcell2face_left2[ic] >= 0) {
         Hxminus2 = Hx[mesh->map_xcell2face_left2[ic]];
         Uxminus2 = Ux[mesh->map_xcell2face_left2[ic]];
         Vxminus2 = Vx[mesh->map_xcell2face_left2[ic]];
      }

      real_t Hxplus = H[ic];
      real_t Uxplus = 0.0;
      real_t Vxplus = 0.0;
      if (mesh->map_xcell2face_right1[ic] >= 0){
         Hxplus   = Hx[mesh->map_xcell2face_right1[ic]];
         Uxplus   = Ux[mesh->map_xcell2face_right1[ic]];
         Vxplus   = Vx[mesh->map_xcell2face_right1[ic]];
      }

      real_t Hxplus2 = 0.0;
      if(lvl < level[nr]) Hxplus2 = H[ic];
      real_t Uxplus2 = 0.0;
      real_t Vxplus2 = 0.0;
      if (mesh->map_xcell2face_right2[ic] >= 0){
         Hxplus2  = Hx[mesh->map_xcell2face_right2[ic]];
         Uxplus2  = Ux[mesh->map_xcell2face_right2[ic]];
         Vxplus2  = Vx[mesh->map_xcell2face_right2[ic]];
      }

      if(level[nl] < level[nll]) {
         Hll = (Hll + H[ ntop[nll] ]) * HALF;
         Ull = (Ull + U[ ntop[nll] ]) * HALF;
      }

      real_t Hr2 = Hr;
      real_t Ur2 = Ur;
      if(lvl < level[nr]) {
         Hr2 = (Hr2 + Hrt) * HALF;
         Ur2 = (Ur2 + Urt) * HALF;
      }

      real_t wminusx_H = w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus/Hxminus) + sqrt(g*Hxminus),
                              Hic-Hl, Hl-Hll, Hr2-Hic);

      wminusx_H *= Hic - Hl;

      if(lvl < level[nl]) {
         if(level[nlt] < level[nltl])
            Hll2 = (Hll2 + H[ ntop[nltl] ]) * HALF;
         wminusx_H = ((w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus2/Hxminus2) +
                                  sqrt(g*Hxminus2), Hic-Hlt, Hlt-Hll2, Hr2-Hic) *
                      (Hic - Hlt)) + wminusx_H)*HALF*HALF;
      }

      if(level[nr] < level[nrr]) {
         Hrr = (Hrr + H[ ntop[nrr] ]) * HALF;
         Urr = (Urr + U[ ntop[nrr] ]) * HALF;
      }

      real_t Hl2 = Hl;
      real_t Ul2 = Ul;
      if(lvl < level[nl]) {
         Hl2 = (Hl2 + Hlt) * HALF;
         Ul2 = (Ul2 + Ult) * HALF;
      }

      real_t wplusx_H = w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus/Hxplus) + sqrt(g*Hxplus),
                           Hr-Hic, Hic-Hl2, Hrr-Hr);

      wplusx_H *= Hr - Hic;

      if(lvl < level[nr]) {
         if(level[nrt] < level[nrtr])
            Hrr2 = (Hrr2 + H[ ntop[nrtr] ]) * HALF;
         wplusx_H = ((w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus2/Hxplus2) +
                                  sqrt(g*Hxplus2), Hrt-Hic, Hic-Hl2, Hrr2-Hrt) *
                      (Hrt - Hic))+wplusx_H)*HALF*HALF;
      }


      real_t wminusx_U = w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus/Hxminus) + sqrt(g*Hxminus),
                              Uic-Ul, Ul-Ull, Ur2-Uic);

      wminusx_U *= Uic - Ul;

      if(lvl < level[nl]) {
         if(level[nlt] < level[nltl])
            Ull2 = (Ull2 + U[ ntop[nltl] ]) * HALF;
         wminusx_U = ((w_corrector(deltaT, (dric+dxl)*HALF, fabs(Uxminus2/Hxminus2) +
                                  sqrt(g*Hxminus2), Uic-Ult, Ult-Ull2, Ur2-Uic) *
                      (Uic - Ult))+wminusx_U)*HALF*HALF;
      }


      real_t wplusx_U = w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus/Hxplus) + sqrt(g*Hxplus),
                              Ur-Uic, Uic-Ul2, Urr-Ur);

      wplusx_U *= Ur - Uic;

      if(lvl < level[nr]) {
         if(level[nrt] < level[nrtr])
            Urr2 = (Urr2 + U[ ntop[nrtr] ]) * HALF;
         wplusx_U = ((w_corrector(deltaT, (dric+dxr)*HALF, fabs(Uxplus2/Hxplus2) +
                                  sqrt(g*Hxplus2), Urt-Uic, Uic-Ul2, Urr2-Urt) *
                      (Urt - Uic))+wplusx_U)*HALF*HALF;
      }


      if(level[nb] < level[nbb]) {
         Hbb = (Hbb + H[ nrht[nbb] ]) * HALF;
         Vbb = (Vbb + V[ nrht[nbb] ]) * HALF;
      }

      real_t Ht2 = Ht;
      real_t Vt2 = Vt;
      if(lvl < level[nt]) {
         Ht2 = (Ht2 + Htr) * HALF;
         Vt2 = (Vt2 + Vtr) * HALF;
      }

      real_t Hyminus = H[ic];
      real_t Uyminus = 0.0;
      real_t Vyminus = 0.0;
      if (mesh->map_ycell2face_bot1[ic] >= 0){
         Hyminus  = Hy[mesh->map_ycell2face_bot1[ic]];
         Uyminus  = Uy[mesh->map_ycell2face_bot1[ic]];
         Vyminus  = Vy[mesh->map_ycell2face_bot1[ic]];
      }

      real_t Hyminus2 = 0.0;
      if(lvl < level[nb]) Hyminus2 = H[ic];
      real_t Uyminus2 = 0.0;
      real_t Vyminus2 = 0.0;
      if (mesh->map_ycell2face_bot2[ic] >= 0){
         Hyminus2 = Hy[mesh->map_ycell2face_bot2[ic]];
         Uyminus2 = Uy[mesh->map_ycell2face_bot2[ic]];
         Vyminus2 = Vy[mesh->map_ycell2face_bot2[ic]];
      }

      real_t Hyplus = H[ic];
      real_t Uyplus = 0.0;
      real_t Vyplus = 0.0;
      if (mesh->map_ycell2face_top1[ic] >= 0){
         Hyplus   = Hy[mesh->map_ycell2face_top1[ic]];
         Uyplus   = Uy[mesh->map_ycell2face_top1[ic]];
         Vyplus   = Vy[mesh->map_ycell2face_top1[ic]];
      }

      real_t Hyplus2 = 0.0;
      if(lvl < level[nt]) Hyplus2 = H[ic];
      real_t Uyplus2 = 0.0;
      real_t Vyplus2 = 0.0;
      if (mesh->map_ycell2face_top2[ic] >= 0){
         Hyplus2  = Hy[mesh->map_ycell2face_top2[ic]];
         Uyplus2  = Uy[mesh->map_ycell2face_top2[ic]];
         Vyplus2  = Vy[mesh->map_ycell2face_top2[ic]];
      }

      real_t wminusy_H = w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus/Hyminus) + sqrt(g*Hyminus),
                              Hic-Hb, Hb-Hbb, Ht2-Hic);

      wminusy_H *= Hic - Hb;

      if(lvl < level[nb]) {
         if(level[nbr] < level[nbrb])
            Hbb2 = (Hbb2 + H[ nrht[nbrb] ]) * HALF;
         wminusy_H = ((w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus2/Hyminus2) +
                                  sqrt(g*Hyminus2), Hic-Hbr, Hbr-Hbb2, Ht2-Hic) *
                      (Hic - Hbr))+wminusy_H)*HALF*HALF;
      }


      if(level[nt] < level[ntt]) {
         Htt = (Htt + H[ nrht[ntt] ]) * HALF;
         Vtt = (Vtt + V[ nrht[ntt] ]) * HALF;
      }

      real_t Hb2 = Hb;
      real_t Vb2 = Vb;
      if(lvl < level[nb]) {
         Hb2 = (Hb2 + Hbr) * HALF;
         Vb2 = (Vb2 + Vbr) * HALF;
      }

      real_t wplusy_H = w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus/Hyplus) + sqrt(g*Hyplus),
                             Ht-Hic, Hic-Hb2, Htt-Ht);

      wplusy_H *= Ht - Hic;

      if(lvl < level[nt]) {
         if(level[ntr] < level[ntrt])
            Htt2 = (Htt2 + H[ nrht[ntrt] ]) * HALF;
         wplusy_H = ((w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus2/Hyplus2) +
                                  sqrt(g*Hyplus2), Htr-Hic, Hic-Hb2, Htt2-Htr) *
                      (Htr - Hic))+wplusy_H)*HALF*HALF;
      }

      real_t wminusy_V = w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus/Hyminus) + sqrt(g*Hyminus),
                              Vic-Vb, Vb-Vbb, Vt2-Vic);

      wminusy_V *= Vic - Vb;

      if(lvl < level[nb]) {
         if(level[nbr] < level[nbrb])
            Vbb2 = (Vbb2 + V[ nrht[nbrb] ]) * HALF;
         wminusy_V = ((w_corrector(deltaT, (dric+dyb)*HALF, fabs(Vyminus2/Hyminus2) +
                                  sqrt(g*Hyminus2), Vic-Vbr, Vbr-Vbb2, Vt2-Vic) *
                      (Vic - Vbr))+wminusy_V)*HALF*HALF;
      }

      real_t wplusy_V = w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus/Hyplus) + sqrt(g*Hyplus),
                           Vt-Vic, Vic-Vb2, Vtt-Vt);

      wplusy_V *= Vt - Vic;

      if(lvl < level[nt]) {
         if(level[ntr] < level[ntrt])
            Vtt2 = (Vtt2 + V[ nrht[ntrt] ]) * HALF;
         wplusy_V = ((w_corrector(deltaT, (dric+dyt)*HALF, fabs(Vyplus2/Hyplus2) +
                                  sqrt(g*Hyplus2), Vtr-Vic, Vic-Vb2, Vtt2-Vtr) *
                      (Vtr - Vic))+wplusy_V)*HALF*HALF;
      }

      real_t Hxfluxminus = HNEWXFLUXMINUS;
      real_t Uxfluxminus = UNEWXFLUXMINUS;
      real_t Vxfluxminus = UVNEWFLUXMINUS;

      real_t Hxfluxplus  = HNEWXFLUXPLUS;
      real_t Uxfluxplus  = UNEWXFLUXPLUS;
      real_t Vxfluxplus  = UVNEWFLUXPLUS;

      real_t Hyfluxminus = HNEWYFLUXMINUS;
      real_t Uyfluxminus = VUNEWFLUXMINUS;
      real_t Vyfluxminus = VNEWYFLUXMINUS;

      real_t Hyfluxplus  = HNEWYFLUXPLUS;
      real_t Uyfluxplus  = VUNEWFLUXPLUS;
      real_t Vyfluxplus  = VNEWYFLUXPLUS;

      if(lvl < level[nl]) {
         Hxfluxminus = (Hxfluxminus + HNEWXFLUXMINUS2) * HALF;
         Uxfluxminus = (Uxfluxminus + UNEWXFLUXMINUS2) * HALF;
         Vxfluxminus = (Vxfluxminus + UVNEWFLUXMINUS2) * HALF;
      }

      if(lvl < level[nr]) {
         Hxfluxplus  = (Hxfluxplus + HNEWXFLUXPLUS2) * HALF;
         Uxfluxplus  = (Uxfluxplus + UNEWXFLUXPLUS2) * HALF;
         Vxfluxplus  = (Vxfluxplus + UVNEWFLUXPLUS2) * HALF;
      }

      if(lvl < level[nb]) {
         Hyfluxminus = (Hyfluxminus + HNEWYFLUXMINUS2) * HALF;
         Uyfluxminus = (Uyfluxminus + VUNEWFLUXMINUS2) * HALF;
         Vyfluxminus = (Vyfluxminus + VNEWYFLUXMINUS2) * HALF;
      }

      if(lvl < level[nt]) {
         Hyfluxplus  = (Hyfluxplus + HNEWYFLUXPLUS2) * HALF;
         Uyfluxplus  = (Uyfluxplus + VUNEWFLUXPLUS2) * HALF;
         Vyfluxplus  = (Vyfluxplus + VNEWYFLUXPLUS2) * HALF;
      }

      H_new[ic] = U_fullstep(deltaT, dxic, Hic,
                      Hxfluxplus, Hxfluxminus, Hyfluxplus, Hyfluxminus)
                 - wminusx_H + wplusx_H - wminusy_H + wplusy_H;
      U_new[ic] = U_fullstep(deltaT, dxic, Uic,
                      Uxfluxplus, Uxfluxminus, Uyfluxplus, Uyfluxminus)
                 - wminusx_U + wplusx_U;
      V_new[ic] = U_fullstep(deltaT, dxic, Vic,
                      Vxfluxplus, Vxfluxminus, Vyfluxplus, Vyfluxminus)
                 - wminusy_V + wplusy_V;

#if DEBUG >= 1
      if (DEBUG >= 1) {
         real_t U_tmp = U_new[ic];
         real_t V_tmp = V_new[ic];
         if (U_tmp == 0.0) U_tmp = 0.0;
         if (V_tmp == 0.0) V_tmp = 0.0;
         printf("DEBUG ic %d H_new %lf U_new %lf V_new %lf\n",ic,H_new[ic],U_tmp,V_tmp);
      }
#endif

/*
      printf("DEBUG ic %d deltaT, %lf dxic, %lf Hic, %lf Hxfluxplus, %lf Hxfluxminus, %lf Hyfluxplus, %lf Hyfluxminus %lf\n",
         ic, deltaT, dxic, Hic, Hxfluxplus, Hxfluxminus, Hyfluxplus, Hyfluxminus);
      printf("DEBUG ic %d wminusx_H %lf wplusx_H %lf wminusy_H %lf wplusy_H %lf\n",ic, wminusx_H, wplusx_H, wminusy_H, wplusy_H);
      printf("DEBUG ic %d deltaT, %lf dxic, %lf Vic, %lf Vxfluxplus, %lf Vxfluxminus, %lf Vyfluxplus, %lf Vyfluxminus %lf\n",
         ic, deltaT, dxic, Vic, Vxfluxplus, Vxfluxminus, Vyfluxplus, Vyfluxminus);
      printf("DEBUG ic %d wminusy_V %lf wplusy_V %lf\n",ic, wminusy_V, wplusy_V);
*/
   }//end forloop

#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
   {
#endif
      // Replace H with H_new and deallocate H. New memory will have the characteristics
      // of the new memory and the name of the old. Both return and arg1 will be reset to new memory
      H = (state_t *)state_memory.memory_replace(H, H_new);
      U = (state_t *)state_memory.memory_replace(U, U_new);
      V = (state_t *)state_memory.memory_replace(V, V_new);

      //state_memory.memory_report();
      //printf("DEBUG end finite diff\n\n"); 
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

#ifdef _OPENMP
#pragma omp master
#endif
      cpu_timers[STATE_TIMER_FINITE_DIFFERENCE] += cpu_timer_stop(tstart_cpu);
}

#ifdef HAVE_OPENCL
void State::gpu_calc_finite_difference(double deltaT)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   cl_command_queue command_queue = ezcl_get_command_queue();

   //cl_mem dev_ptr = NULL;

   size_t &ncells    = mesh->ncells;
   size_t &ncells_ghost = mesh->ncells_ghost;
   if (ncells_ghost < ncells) ncells_ghost = ncells;
   int &levmx           = mesh->levmx;
   cl_mem &dev_celltype = mesh->dev_celltype;
   cl_mem &dev_nlft     = mesh->dev_nlft;
   cl_mem &dev_nrht     = mesh->dev_nrht;
   cl_mem &dev_nbot     = mesh->dev_nbot;
   cl_mem &dev_ntop     = mesh->dev_ntop;
   cl_mem &dev_level    = mesh->dev_level;
   cl_mem &dev_levdx    = mesh->dev_levdx;
   cl_mem &dev_levdy    = mesh->dev_levdy;

   assert(dev_H);
   assert(dev_U);
   assert(dev_V);
   assert(dev_nlft);
   assert(dev_nrht);
   assert(dev_nbot);
   assert(dev_ntop);
   assert(dev_level);
   assert(dev_levdx);
   assert(dev_levdy);

   cl_mem dev_H_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_H_new"), DEVICE_REGULAR_MEMORY);
   cl_mem dev_U_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_U_new"), DEVICE_REGULAR_MEMORY);
   cl_mem dev_V_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_V_new"), DEVICE_REGULAR_MEMORY);
 
   size_t local_work_size = 128;
   size_t global_work_size = ((ncells+local_work_size - 1) /local_work_size) * local_work_size;

#ifdef HAVE_MPI
   if (mesh->numpe > 1) {
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions_local,   1, NULL, &global_work_size, &local_work_size, NULL);
    
        /*
        __kernel void copy_state_data_cl(
                         const int    isize,         // 0
                __global      state_t *H,            // 1
                __global      state_t *U,            // 2
                __global      state_t *V,            // 3
                __global      state_t *H_new,        // 4
                __global      state_t *U_new,        // 5
                __global      state_t *V_new)        // 6
        */

      ezcl_set_kernel_arg(kernel_copy_state_data, 0, sizeof(cl_int), (void *)&ncells);
      ezcl_set_kernel_arg(kernel_copy_state_data, 1, sizeof(cl_mem), (void *)&dev_H);
      ezcl_set_kernel_arg(kernel_copy_state_data, 2, sizeof(cl_mem), (void *)&dev_U);
      ezcl_set_kernel_arg(kernel_copy_state_data, 3, sizeof(cl_mem), (void *)&dev_V);
      ezcl_set_kernel_arg(kernel_copy_state_data, 4, sizeof(cl_mem), (void *)&dev_H_new);
      ezcl_set_kernel_arg(kernel_copy_state_data, 5, sizeof(cl_mem), (void *)&dev_U_new);
      ezcl_set_kernel_arg(kernel_copy_state_data, 6, sizeof(cl_mem), (void *)&dev_V_new);

      //ezcl_enqueue_ndrange_kernel(command_queue, kernel_copy_state_data,   1, NULL, &global_work_size, &local_work_size, &copy_state_data_event);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_copy_state_data,   1, NULL, &global_work_size, &local_work_size, NULL);

      dev_H = (cl_mem)gpu_state_memory.memory_replace(dev_H, dev_H_new);
      dev_U = (cl_mem)gpu_state_memory.memory_replace(dev_U, dev_U_new);
      dev_V = (cl_mem)gpu_state_memory.memory_replace(dev_V, dev_V_new);

      L7_Dev_Update(dev_H, L7_STATE_T, mesh->cell_handle);
      L7_Dev_Update(dev_U, L7_STATE_T, mesh->cell_handle);
      L7_Dev_Update(dev_V, L7_STATE_T, mesh->cell_handle);

      dev_H_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_H_new"), DEVICE_REGULAR_MEMORY);
      dev_U_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_U_new"), DEVICE_REGULAR_MEMORY);
      dev_V_new = (cl_mem)gpu_state_memory.memory_malloc(ncells_ghost, sizeof(cl_state_t), const_cast<char *>("dev_V_new"), DEVICE_REGULAR_MEMORY);

      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions_ghost,   1, NULL, &global_work_size, &local_work_size, NULL);
   } else {
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions,   1, NULL, &global_work_size, &local_work_size, NULL);
   }
#else
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 0, sizeof(cl_int), &ncells);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 1, sizeof(cl_mem), &dev_celltype);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 2, sizeof(cl_mem), &dev_nlft);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 3, sizeof(cl_mem), &dev_nrht);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 4, sizeof(cl_mem), &dev_ntop);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 5, sizeof(cl_mem), &dev_nbot);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 6, sizeof(cl_mem), &dev_H);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 7, sizeof(cl_mem), &dev_U);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 8, sizeof(cl_mem), &dev_V);
   ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions,   1, NULL, &global_work_size, &local_work_size, NULL);
#endif

     /*
     __kernel void calc_finite_difference_cl(
                      const int     ncells,    // 0  Total number of cells.
                      const int     lvmax,     // 1  Maximum level
             __global       state_t *H,        // 2
             __global       state_t *U,        // 3
             __global       state_t *V,        // 4
             __global       state_t *H_new,    // 5
             __global       state_t *U_new,    // 6
             __global       state_t *V_new,    // 7
             __global const int     *nlft,     // 8  Array of left neighbors.
             __global const int     *nrht,     // 9  Array of right neighbors.
             __global const int     *ntop,     // 10  Array of bottom neighbors.
             __global const int     *nbot,     // 11  Array of top neighbors.
             __global const int     *level,    // 12  Array of level information.
                      const real_t   deltaT,   // 13  Size of time step.
             __global const real_t  *lev_dx,   // 14
             __global const real_t  *lev_dy,   // 15
             __local        state4_t *tile,    // 16  Tile size in state4.
             __local        int8  *itile)      // 17  Tile size in int8.
     */
   cl_event calc_finite_difference_event;

   real_t deltaT_local = deltaT;
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 0, sizeof(cl_int),  (void *)&ncells);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 1, sizeof(cl_int),  (void *)&levmx);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 2, sizeof(cl_mem),  (void *)&dev_H);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 3, sizeof(cl_mem),  (void *)&dev_U);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 4, sizeof(cl_mem),  (void *)&dev_V);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 5, sizeof(cl_mem),  (void *)&dev_H_new);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 6, sizeof(cl_mem),  (void *)&dev_U_new);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 7, sizeof(cl_mem),  (void *)&dev_V_new);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 8, sizeof(cl_mem),  (void *)&dev_nlft);
   ezcl_set_kernel_arg(kernel_calc_finite_difference, 9, sizeof(cl_mem),  (void *)&dev_nrht);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,10, sizeof(cl_mem),  (void *)&dev_ntop);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,11, sizeof(cl_mem),  (void *)&dev_nbot);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,12, sizeof(cl_mem),  (void *)&dev_level);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,13, sizeof(cl_real_t), (void *)&deltaT_local);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,14, sizeof(cl_mem),  (void *)&dev_levdx);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,15, sizeof(cl_mem),  (void *)&dev_levdy);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,16, local_work_size*sizeof(cl_state4_t),    NULL);
   ezcl_set_kernel_arg(kernel_calc_finite_difference,17, local_work_size*sizeof(cl_int8),    NULL);

   ezcl_enqueue_ndrange_kernel(command_queue, kernel_calc_finite_difference,   1, NULL, &global_work_size, &local_work_size, &calc_finite_difference_event);

   ezcl_wait_for_events(1, &calc_finite_difference_event);
   ezcl_event_release(calc_finite_difference_event);

   dev_H = (cl_mem)gpu_state_memory.memory_replace(dev_H, dev_H_new);
   dev_U = (cl_mem)gpu_state_memory.memory_replace(dev_U, dev_U_new);
   dev_V = (cl_mem)gpu_state_memory.memory_replace(dev_V, dev_V_new);

   gpu_timers[STATE_TIMER_FINITE_DIFFERENCE] += (long)(cpu_timer_stop(tstart_cpu)*1.0e9);
}
#endif

void State::symmetry_check(const char *string, vector<int> sym_index, double eps,
                           SIGN_RULE sign_rule, int &flag)
{
   size_t &ncells = mesh->ncells;

   double xsign = 1.0, ysign = 1.0;

   if (sign_rule == DIAG_RULE || sign_rule == X_RULE) {
      xsign = -1.0;
   }

   if (sign_rule == DIAG_RULE || sign_rule == Y_RULE) {
      ysign = -1.0;
   }

   for (uint ic=0; ic<ncells; ic++) {
      /*  Symmetrical check */
      if (fabs(H[ic] - H[sym_index[ic]]) > eps) {
         printf("%s ic %d sym %d H[ic] %lf Hsym %lf diff %lf\n",
                string,ic,sym_index[ic],H[ic],H[sym_index[ic]],fabs(H[ic]-H[sym_index[ic]]));
         flag++;
      }
      if (fabs(U[ic] - xsign*U[sym_index[ic]]) > eps) {
         printf("%s ic %d sym %d U[ic] %lf Usym %lf diff %lf\n",
                string,ic,sym_index[ic],U[ic],U[sym_index[ic]],fabs(U[ic]-xsign*U[sym_index[ic]]));
         flag++;
      }
      if (fabs(V[ic] - ysign*V[sym_index[ic]]) > eps) {
         printf("%s ic %d sym %d V[ic] %lf Vsym %lf diff %lf\n",
                string,ic,sym_index[ic],V[ic],V[sym_index[ic]],fabs(V[ic]-ysign*V[sym_index[ic]]));
         flag++;
      }
   }

}

size_t State::calc_refine_potential(vector<int> &mpot,int &icount, int &jcount)
{
   
  struct timeval tstart_cpu;
#ifdef _OPENMP
#pragma omp parallel 
{
#endif

  struct timeval tstart_lev2;

#ifdef _OPENMP
#pragma omp master
{
#endif
   cpu_timer_start(&tstart_cpu);
   if (TIMING_LEVEL >= 2) cpu_timer_start(&tstart_lev2);
#ifdef _OPENMP
}
#endif

   int *nlft, *nrht, *nbot, *ntop, *level;
   
   size_t ncells = mesh->ncells;
   nlft  = mesh->nlft;
   nrht  = mesh->nrht;
   nbot  = mesh->nbot;
   ntop  = mesh->ntop;
   level = mesh->level;

#ifdef _OPENMP
#pragma omp master
   {
#endif
   icount=0;
   jcount=0;
#ifdef _OPENMP
   }
#pragma omp barrier
#endif

#ifdef HAVE_MPI
   // We need to update the ghost regions and boundary regions for the state
   // variables since they were changed in the finite difference routine. We
   // want to use the updated values for refinement decisions
   if (mesh->numpe > 1) {
      apply_boundary_conditions_local();
#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
{
#endif
      L7_Update(&H[0], L7_STATE_T, mesh->cell_handle);
      L7_Update(&U[0], L7_STATE_T, mesh->cell_handle);
      L7_Update(&V[0], L7_STATE_T, mesh->cell_handle);
#ifdef _OPENMP
}
#pragma omp barrier
#endif
      apply_boundary_conditions_ghost();
   } else {
      apply_boundary_conditions();
   }
#else
   apply_boundary_conditions();
#endif

#ifdef _OPENMP
#pragma omp barrier
#endif
/*****HIGH LEVEL OMP******/

   int lowerBound, upperBound;
   //mesh->set_bounds(ncells);
   mesh->get_bounds(lowerBound,upperBound);
   for (int ic=lowerBound; ic<upperBound; ic++) {

      if (mesh->celltype[ic] != REAL_CELL) continue;

      state_t Hic = H[ic];
      //state_t Uic = U[ic];
      //state_t Vic = V[ic];

      int nl = nlft[ic];
      state_t Hl = H[nl];
      //state_t Ul = U[nl];
      //state_t Vl = V[nl];

      if (level[nl] > level[ic]){
         int nlt = ntop[nl];
         Hl = REFINE_HALF * (Hl + H[nlt]);
      }

      int nr = nrht[ic];
      state_t Hr = H[nr];
      //state_t Ur = U[nr];
      //state_t Vr = V[nr];

      if (level[nr] > level[ic]){
         int nrt = ntop[nr];
         Hr = REFINE_HALF * (Hr + H[nrt]);
      }

      int nb = nbot[ic];
      state_t Hb = H[nb];
      //state_t Ub = U[nb];
      //state_t Vb = V[nb];

      if (level[nb] > level[ic]){
         int nbr = nrht[nb];
         Hb = REFINE_HALF * (Hb + H[nbr]);
      }

      int nt = ntop[ic];
      state_t Ht = H[nt];
      //state_t Ut = U[nt];
      //state_t Vt = V[nt];

      if (level[nt] > level[ic]){
         int ntr = nrht[nt];
         Ht = REFINE_HALF * (Ht + H[ntr]);
      }

      state_t duplus1; //, duplus2;
      state_t duhalf1; //, duhalf2;
      state_t duminus1; //, duminus2;

      duplus1 = Hr-Hic;
      //duplus2 = Ur-Uic;
      duhalf1 = Hic-Hl;
      //duhalf2 = Uic-Ul;

      state_t qmax = REFINE_NEG_THOUSAND;

      state_t qpot = max(fabs(duplus1/Hic), fabs(duhalf1/Hic));
      if (qpot > qmax) qmax = qpot;

      duminus1 = Hic-Hl;
      //duminus2 = Uic-Ul;
      duhalf1 = Hr-Hic;
      //duhalf2 = Ur-Uic;

      qpot = max(fabs(duminus1/Hic), fabs(duhalf1/Hic));
      if (qpot > qmax) qmax = qpot;

      duplus1 = Ht-Hic;
      //duplus2 = Vt-Vic;
      duhalf1 = Hic-Hb;
      //duhalf2 = Vic-Vb;

      qpot = max(fabs(duplus1/Hic), fabs(duhalf1/Hic));
      if (qpot > qmax) qmax = qpot;

      duminus1 = Hic-Hb;
      //duminus2 = Vic-Vb;
      duhalf1 = Ht-Hic;
      //duhalf2 = Vt-Vic;

      qpot = max(fabs(duminus1/Hic), fabs(duhalf1/Hic));
      if (qpot > qmax) qmax = qpot;

      mpot[ic]=0;
      if (qmax > REFINE_GRADIENT && level[ic] < mesh->levmx) {
         mpot[ic]=1;
      } else if (qmax < COARSEN_GRADIENT && level[ic] > 0) {
         mpot[ic] = -1;
      }
      //if (mpot[ic]) printf("DEBUG cpu cell is %d mpot %d\n",ic,mpot[ic]);
   }

#ifdef _OPENMP
#pragma omp master
{
#endif
   if (TIMING_LEVEL >= 2) {
      cpu_timers[STATE_TIMER_CALC_MPOT] += cpu_timer_stop(tstart_lev2);
   }
#ifdef _OPENMP
}
#endif

#ifdef _OPENMP
}
#pragma omp barrier
#endif
   int newcount = mesh->refine_smooth(mpot, icount, jcount);
   //printf("DEBUG -- after refine smooth in file %s line %d icount %d jcount %d newcount %d\n",__FILE__,__LINE__,icount,jcount,newcount);

   cpu_timers[STATE_TIMER_REFINE_POTENTIAL] += cpu_timer_stop(tstart_cpu);

   return(newcount);
}

#ifdef HAVE_OPENCL
size_t State::gpu_calc_refine_potential(int &icount, int &jcount)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   struct timeval tstart_lev2;
   if (TIMING_LEVEL >= 2) cpu_timer_start(&tstart_lev2);

   cl_command_queue command_queue = ezcl_get_command_queue();

   size_t &ncells       = mesh->ncells;
   int &levmx           = mesh->levmx;
   cl_mem &dev_nlft     = mesh->dev_nlft;
   cl_mem &dev_nrht     = mesh->dev_nrht;
   cl_mem &dev_nbot     = mesh->dev_nbot;
   cl_mem &dev_ntop     = mesh->dev_ntop;
   //cl_mem &dev_mpot     = mesh->dev_mpot;
   cl_mem &dev_i        = mesh->dev_i;
   cl_mem &dev_j        = mesh->dev_j;
   cl_mem &dev_level    = mesh->dev_level;
   cl_mem &dev_celltype = mesh->dev_celltype;
   cl_mem &dev_levdx    = mesh->dev_levdx;
   cl_mem &dev_levdy    = mesh->dev_levdy;

   assert(dev_H);
   assert(dev_U);
   assert(dev_V);
   assert(dev_nlft);
   assert(dev_nrht);
   assert(dev_nbot);
   assert(dev_ntop);
   assert(dev_i);
   assert(dev_j);
   assert(dev_level);
   //assert(dev_mpot);
   //assert(dev_ioffset);
   assert(dev_levdx);
   assert(dev_levdy);

   icount = 0;
   jcount = 0;

   size_t local_work_size = 128;
   size_t global_work_size = ((ncells+local_work_size - 1) /local_work_size) * local_work_size;
   size_t block_size = global_work_size/local_work_size;

#ifdef HAVE_MPI
   //size_t nghost_local = mesh->ncells_ghost - ncells;

   if (mesh->numpe > 1) {
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_local, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions_local,   1, NULL, &global_work_size, &local_work_size, NULL);

      L7_Dev_Update(dev_H, L7_STATE_T, mesh->cell_handle);
      L7_Dev_Update(dev_U, L7_STATE_T, mesh->cell_handle);
      L7_Dev_Update(dev_V, L7_STATE_T, mesh->cell_handle);

      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions_ghost, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions_ghost,   1, NULL, &global_work_size, &local_work_size, NULL);
   } else {
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 0, sizeof(cl_int), &ncells);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 1, sizeof(cl_mem), &dev_celltype);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 2, sizeof(cl_mem), &dev_nlft);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 3, sizeof(cl_mem), &dev_nrht);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 4, sizeof(cl_mem), &dev_ntop);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 5, sizeof(cl_mem), &dev_nbot);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 6, sizeof(cl_mem), &dev_H);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 7, sizeof(cl_mem), &dev_U);
      ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 8, sizeof(cl_mem), &dev_V);
      ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions,   1, NULL, &global_work_size, &local_work_size, NULL);
   }
#else
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 0, sizeof(cl_int), &ncells);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 1, sizeof(cl_mem), &dev_celltype);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 2, sizeof(cl_mem), &dev_nlft);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 3, sizeof(cl_mem), &dev_nrht);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 4, sizeof(cl_mem), &dev_ntop);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 5, sizeof(cl_mem), &dev_nbot);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 6, sizeof(cl_mem), &dev_H);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 7, sizeof(cl_mem), &dev_U);
   ezcl_set_kernel_arg(kernel_apply_boundary_conditions, 8, sizeof(cl_mem), &dev_V);
   ezcl_enqueue_ndrange_kernel(command_queue, kernel_apply_boundary_conditions,   1, NULL, &global_work_size, &local_work_size, NULL);
#endif

#ifdef BOUNDS_CHECK
      {
         vector<int> nlft_tmp(mesh->ncells_ghost);
         vector<int> nrht_tmp(mesh->ncells_ghost);
         vector<int> nbot_tmp(mesh->ncells_ghost);
         vector<int> ntop_tmp(mesh->ncells_ghost);
         vector<int> level_tmp(mesh->ncells_ghost);
         vector<state_t> H_tmp(mesh->ncells_ghost);
         ezcl_enqueue_read_buffer(command_queue, dev_nlft,  CL_FALSE, 0, mesh->ncells_ghost*sizeof(cl_int), &nlft_tmp[0],  NULL);
         ezcl_enqueue_read_buffer(command_queue, dev_nrht,  CL_FALSE, 0, mesh->ncells_ghost*sizeof(cl_int), &nrht_tmp[0],  NULL);
         ezcl_enqueue_read_buffer(command_queue, dev_nbot,  CL_FALSE, 0, mesh->ncells_ghost*sizeof(cl_int), &nbot_tmp[0],  NULL);
         ezcl_enqueue_read_buffer(command_queue, dev_ntop,  CL_TRUE,  0, mesh->ncells_ghost*sizeof(cl_int), &ntop_tmp[0],  NULL);
         ezcl_enqueue_read_buffer(command_queue, dev_level, CL_TRUE,  0, mesh->ncells_ghost*sizeof(cl_int), &level_tmp[0], NULL);
         ezcl_enqueue_read_buffer(command_queue, dev_H,     CL_TRUE,  0, mesh->ncells_ghost*sizeof(cl_int), &H_tmp[0],     NULL);
         for (uint ic=0; ic<ncells; ic++){
            int nl = nlft_tmp[ic];
            if (nl<0 || nl>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d nlft %d\n",mesh->mype,__LINE__,ic,nl);
            if (level_tmp[nl] > level_tmp[ic]){
               int ntl = ntop_tmp[nl];
               if (ntl<0 || ntl>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d global %d nlft %d ntop of nlft %d\n",mesh->mype,__LINE__,ic,ic+mesh->noffset,nl,ntl);
            }
            int nr = nrht_tmp[ic];
            if (nr<0 || nr>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d nrht %d\n",mesh->mype,__LINE__,ic,nr);
            if (level_tmp[nr] > level_tmp[ic]){
               int ntr = ntop_tmp[nr];
               if (ntr<0 || ntr>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d ntop of nrht %d\n",mesh->mype,__LINE__,ic,ntr);
            }
            int nb = nbot_tmp[ic];
            if (nb<0 || nb>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d nbot %d\n",mesh->mype,__LINE__,ic,nb);
            if (level_tmp[nb] > level_tmp[ic]){
               int nrb = nrht_tmp[nb];
               if (nrb<0 || nrb>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d nrht of nbot %d\n",mesh->mype,__LINE__,ic,nrb);
            }
            int nt = ntop_tmp[ic];
            if (nt<0 || nt>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d ntop %d\n",mesh->mype,__LINE__,ic,nt);
            if (level_tmp[nt] > level_tmp[ic]){
               int nrt = nrht_tmp[nt];
               if (nrt<0 || nrt>= (int)mesh->ncells_ghost) printf("%d: Warning at line %d cell %d nrht of ntop %d\n",mesh->mype,__LINE__,ic,nrt);
            }
         }
         for (uint ic=0; ic<mesh->ncells_ghost; ic++){
            if (H_tmp[ic] < 1.0) printf("%d: Warning at line %d cell %d H %lf\n",mesh->mype,__LINE__,ic,H_tmp[ic]);
         }
      }
#endif

   size_t result_size = 1;
   cl_mem dev_result     = ezcl_malloc(NULL, const_cast<char *>("dev_result"),     &result_size,        sizeof(cl_int2), CL_MEM_READ_WRITE, 0);
   cl_mem dev_redscratch = ezcl_malloc(NULL, const_cast<char *>("dev_redscratch"), &block_size,         sizeof(cl_int2), CL_MEM_READ_WRITE, 0);

   dev_mpot              = ezcl_malloc(NULL, const_cast<char *>("dev_mpot"),       &mesh->ncells_ghost, sizeof(cl_int),  CL_MEM_READ_WRITE, 0);

     /*
     __kernel void refine_potential
              const int      ncells,     // 0  Total number of cells.
              const int      levmx,      // 1  Maximum level
     __global       state_t *H,          // 2
     __global       state_t *U,          // 3
     __global       state_t *V,          // 4
     __global const int     *nlft,       // 5  Array of left neighbors.
     __global const int     *nrht,       // 6  Array of right neighbors.
     __global const int     *ntop,       // 7  Array of bottom neighbors.
     __global const int     *nbot,       // 8  Array of top neighbors.
     __global const int     *level,      // 9  Array of level information.
     __global const int     *celltype,   // 10  Array of celltype information.
     __global       int     *mpot,       // 11  Array of mesh potential information.
     __global       int2    *redscratch, // 12
     __global const real_t  *lev_dx,     // 13
     __global const real_t  *lev_dy,     // 14
     __global       int2    *result,     // 15
     __local        state_t *tile,       // 16  Tile size in real4.
     __local        int8    *itile)      // 17  Tile size in int8.
     */

   ezcl_set_kernel_arg(kernel_refine_potential, 0, sizeof(cl_int),  (void *)&ncells);
   ezcl_set_kernel_arg(kernel_refine_potential, 1, sizeof(cl_int),  (void *)&levmx);
   ezcl_set_kernel_arg(kernel_refine_potential, 2, sizeof(cl_mem),  (void *)&dev_H);
   ezcl_set_kernel_arg(kernel_refine_potential, 3, sizeof(cl_mem),  (void *)&dev_U);
   ezcl_set_kernel_arg(kernel_refine_potential, 4, sizeof(cl_mem),  (void *)&dev_V);
   ezcl_set_kernel_arg(kernel_refine_potential, 5, sizeof(cl_mem),  (void *)&dev_nlft);
   ezcl_set_kernel_arg(kernel_refine_potential, 6, sizeof(cl_mem),  (void *)&dev_nrht);
   ezcl_set_kernel_arg(kernel_refine_potential, 7, sizeof(cl_mem),  (void *)&dev_ntop);
   ezcl_set_kernel_arg(kernel_refine_potential, 8, sizeof(cl_mem),  (void *)&dev_nbot);
   ezcl_set_kernel_arg(kernel_refine_potential, 9, sizeof(cl_mem),  (void *)&dev_i);
   ezcl_set_kernel_arg(kernel_refine_potential,10, sizeof(cl_mem),  (void *)&dev_j);
   ezcl_set_kernel_arg(kernel_refine_potential,11, sizeof(cl_mem),  (void *)&dev_level);
   ezcl_set_kernel_arg(kernel_refine_potential,12, sizeof(cl_mem),  (void *)&dev_celltype);
   ezcl_set_kernel_arg(kernel_refine_potential,13, sizeof(cl_mem),  (void *)&dev_levdx);
   ezcl_set_kernel_arg(kernel_refine_potential,14, sizeof(cl_mem),  (void *)&dev_levdy);
   ezcl_set_kernel_arg(kernel_refine_potential,15, sizeof(cl_mem),  (void *)&dev_mpot);
   ezcl_set_kernel_arg(kernel_refine_potential,16, sizeof(cl_mem),  (void *)&dev_redscratch);
   ezcl_set_kernel_arg(kernel_refine_potential,17, sizeof(cl_mem),  (void *)&dev_result);
   ezcl_set_kernel_arg(kernel_refine_potential,18, local_work_size*sizeof(cl_state_t),    NULL);
   ezcl_set_kernel_arg(kernel_refine_potential,19, local_work_size*sizeof(cl_int8),    NULL);

   ezcl_enqueue_ndrange_kernel(command_queue, kernel_refine_potential, 1, NULL, &global_work_size, &local_work_size, NULL);

   mesh->gpu_rezone_count2(block_size, local_work_size, dev_redscratch, dev_result);

   int count[2] = {0, 0};
   ezcl_enqueue_read_buffer(command_queue, dev_result, CL_TRUE, 0, sizeof(cl_int2), count, NULL);
   icount  = count[0];
   jcount  = count[1];
   //size_t result = ncells + icount - jcount;

   //int mpot_check[ncells];
   //ezcl_enqueue_read_buffer(command_queue, dev_mpot, CL_TRUE, 0, ncells*sizeof(cl_int), mpot_check, NULL);
   //for (int ic=0; ic<ncells; ic++){
   //   if (mpot_check[ic]) printf("DEBUG -- cell %d mpot %d\n",ic,mpot_check[ic]);
   //}

   //printf("result = %lu after first refine potential icount %d jcount %d\n",result, icount, jcount);
//   int which_smooth = 1;

   ezcl_device_memory_delete(dev_redscratch);
   ezcl_device_memory_delete(dev_result);

   if (TIMING_LEVEL >= 2) {
      gpu_timers[STATE_TIMER_CALC_MPOT] += (long)(cpu_timer_stop(tstart_lev2)*1.0e9);
   }

   int my_result = mesh->gpu_refine_smooth(dev_mpot, icount, jcount);
   //printf("DEBUG gpu calc refine potential %d icount %d jcount %d\n",my_result,icount,jcount);

   gpu_timers[STATE_TIMER_REFINE_POTENTIAL] += (long)(cpu_timer_stop(tstart_cpu)*1.0e9);

   return((size_t)my_result);
}
#endif

double State::mass_sum(int enhanced_precision_sum)
{
   size_t &ncells = mesh->ncells;
   int *celltype = mesh->celltype;
   int *level    = mesh->level;

#ifdef HAVE_MPI
   //int &mype = mesh->mype;
#endif

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   double summer = 0.0;
   double total_sum = 0.0;

   if (enhanced_precision_sum == SUM_KAHAN) {
      //printf("DEBUG -- kahan_sum\n");
      double corrected_next_term, new_sum;
      struct esum_type local;
#ifdef HAVE_MPI
      struct esum_type global;
#endif

      local.sum = 0.0;
      local.correction = 0.0;
      int ic;
      for (ic = 0; ic < (int)ncells; ic++) {
         if (celltype[ic] == REAL_CELL) {
            //  Exclude boundary cells.
            corrected_next_term= H[ic]*mesh->lev_deltax[level[ic]]*mesh->lev_deltay[level[ic]] + local.correction;
            new_sum            = local.sum + local.correction;
            local.correction   = corrected_next_term - (new_sum - local.sum);
            local.sum          = new_sum;
         }
      }

#ifdef HAVE_MPI
      if (mesh->parallel) {
         MPI_Allreduce(&local, &global, 1, MPI_TWO_DOUBLES, KNUTH_SUM, MPI_COMM_WORLD);
         total_sum = global.sum + global.correction;
      } else {
         total_sum = local.sum + local.correction;
      }

//if(mype == 0) printf("MYPE %d: Line %d Iteration %d \t local_sum = %12.6lg, global_sum = %12.6lg\n", mype, __LINE__, mesh->m_ncycle, local.sum, global.sum);

#else
      total_sum = local.sum + local.correction;
#endif

   } else if (enhanced_precision_sum == SUM_REGULAR) {
      //printf("DEBUG -- regular_sum\n");
      for (uint ic=0; ic < ncells; ic++){
         if (celltype[ic] == REAL_CELL) {
            summer += H[ic]*mesh->lev_deltax[level[ic]]*mesh->lev_deltay[level[ic]];
         }
      }
#ifdef HAVE_MPI
      if (mesh->parallel) {
         MPI_Allreduce(&summer, &total_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
      } else {
         total_sum = summer;
      }
#else
      total_sum = summer;
#endif
   }

   cpu_timers[STATE_TIMER_MASS_SUM] += cpu_timer_stop(tstart_cpu);

   return(total_sum);
}

#ifdef HAVE_OPENCL
double State::gpu_mass_sum(int enhanced_precision_sum)
{
   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   cl_command_queue command_queue = ezcl_get_command_queue();

   size_t &ncells       = mesh->ncells;
   cl_mem &dev_levdx    = mesh->dev_levdx;
   cl_mem &dev_levdy    = mesh->dev_levdy;
   cl_mem &dev_celltype = mesh->dev_celltype;
   cl_mem &dev_level    = mesh->dev_level;

   assert(dev_H);
   assert(dev_level);
   assert(dev_levdx);
   assert(dev_levdy);
   assert(dev_celltype);

   size_t one = 1;
   cl_mem dev_mass_sum, dev_redscratch;
   double gpu_mass_sum_total;

   size_t local_work_size = 128;
   size_t global_work_size = ((ncells+local_work_size - 1) /local_work_size) * local_work_size;
   size_t block_size     = global_work_size/local_work_size;

   if (enhanced_precision_sum) {
      dev_mass_sum = ezcl_malloc(NULL, const_cast<char *>("dev_mass_sum"), &one,    sizeof(cl_real2_t), CL_MEM_READ_WRITE, 0);
      dev_redscratch = ezcl_malloc(NULL, const_cast<char *>("dev_redscratch"), &block_size, sizeof(cl_real2_t), CL_MEM_READ_WRITE, 0);

        /*
        __kernel void reduce_sum_cl(
                         const int      isize,      // 0
                __global       state_t *array,      // 1   Array to be reduced.
                __global       int     *level,      // 2
                __global       int     *levdx,      // 3
                __global       int     *levdy,      // 4
                __global       int     *celltype,   // 5
                __global       real_t  *redscratch, // 6   Final result of operation.
                __local        real_t  *tile)       // 7
        */
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 0, sizeof(cl_int), (void *)&ncells);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 1, sizeof(cl_mem), (void *)&dev_H);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 2, sizeof(cl_mem), (void *)&dev_level);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 3, sizeof(cl_mem), (void *)&dev_levdx);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 4, sizeof(cl_mem), (void *)&dev_levdy);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 5, sizeof(cl_mem), (void *)&dev_celltype);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 6, sizeof(cl_mem), (void *)&dev_mass_sum);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 7, sizeof(cl_mem), (void *)&dev_redscratch);
      ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage1of2, 8, local_work_size*sizeof(cl_real2_t), NULL);

      ezcl_enqueue_ndrange_kernel(command_queue, kernel_reduce_epsum_mass_stage1of2, 1, NULL, &global_work_size, &local_work_size, NULL);

      if (block_size > 1) {
           /*
           __kernel void reduce_sum_cl(
                            const int      isize,      // 0
                   __global       int     *redscratch, // 1   Array to be reduced.
                   __local        real_t  *tile)       // 2
           */

         ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage2of2, 0, sizeof(cl_int), (void *)&block_size);
         ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage2of2, 1, sizeof(cl_mem), (void *)&dev_mass_sum);
         ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage2of2, 2, sizeof(cl_mem), (void *)&dev_redscratch);
         ezcl_set_kernel_arg(kernel_reduce_epsum_mass_stage2of2, 3, local_work_size*sizeof(cl_real2_t), NULL);

         ezcl_enqueue_ndrange_kernel(command_queue, kernel_reduce_epsum_mass_stage2of2, 1, NULL, &local_work_size, &local_work_size, NULL);
      }

      struct esum_type local, global;
      real2_t mass_sum;

      ezcl_enqueue_read_buffer(command_queue, dev_mass_sum, CL_TRUE, 0, 1*sizeof(cl_real2_t), &mass_sum, NULL);

      local.sum = mass_sum.s0;
      local.correction = mass_sum.s1;
      global.sum = local.sum;
      global.correction = local.correction;
#ifdef HAVE_MPI
      MPI_Allreduce(&local, &global, 1, MPI_TWO_DOUBLES, KNUTH_SUM, MPI_COMM_WORLD);
#endif
      gpu_mass_sum_total = global.sum + global.correction;
   } else {
      dev_mass_sum = ezcl_malloc(NULL, const_cast<char *>("dev_mass_sum"), &one,    sizeof(cl_real_t), CL_MEM_READ_WRITE, 0);
      dev_redscratch = ezcl_malloc(NULL, const_cast<char *>("dev_redscratch"), &block_size, sizeof(cl_real_t), CL_MEM_READ_WRITE, 0);

        /*
        __kernel void reduce_sum_cl(
                         const int      isize,      // 0
                __global       state_t *array,      // 1   Array to be reduced.
                __global       int     *level,      // 2
                __global       int     *levdx,      // 3
                __global       int     *levdy,      // 4
                __global       int     *celltype,   // 5
                __global       real_t  *redscratch, // 6   Final result of operation.
                __local        real_t  *tile)       // 7
        */
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 0, sizeof(cl_int), (void *)&ncells);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 1, sizeof(cl_mem), (void *)&dev_H);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 2, sizeof(cl_mem), (void *)&dev_level);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 3, sizeof(cl_mem), (void *)&dev_levdx);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 4, sizeof(cl_mem), (void *)&dev_levdy);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 5, sizeof(cl_mem), (void *)&dev_celltype);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 6, sizeof(cl_mem), (void *)&dev_mass_sum);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 7, sizeof(cl_mem), (void *)&dev_redscratch);
      ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage1of2, 8, local_work_size*sizeof(cl_real_t), NULL);

      ezcl_enqueue_ndrange_kernel(command_queue, kernel_reduce_sum_mass_stage1of2, 1, NULL, &global_work_size, &local_work_size, NULL);

      if (block_size > 1) {
           /*
           __kernel void reduce_sum_cl(
                            const int     isize,      // 0
                   __global       int    *redscratch, // 1   Array to be reduced.
                   __local        real_t  *tile)       // 2
           */

         ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage2of2, 0, sizeof(cl_int), (void *)&block_size);
         ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage2of2, 1, sizeof(cl_mem), (void *)&dev_mass_sum);
         ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage2of2, 2, sizeof(cl_mem), (void *)&dev_redscratch);
         ezcl_set_kernel_arg(kernel_reduce_sum_mass_stage2of2, 3, local_work_size*sizeof(cl_real_t), NULL);

         ezcl_enqueue_ndrange_kernel(command_queue, kernel_reduce_sum_mass_stage2of2, 1, NULL, &local_work_size, &local_work_size, NULL);
      }

      double local_sum, global_sum;
      real_t mass_sum;

      ezcl_enqueue_read_buffer(command_queue, dev_mass_sum, CL_TRUE, 0, 1*sizeof(cl_real_t), &mass_sum, NULL);
      
      local_sum = mass_sum;
      global_sum = local_sum;
#ifdef HAVE_MPI
      MPI_Allreduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
#endif
      gpu_mass_sum_total = global_sum;
   }

   ezcl_device_memory_delete(dev_redscratch);
   ezcl_device_memory_delete(dev_mass_sum);

   gpu_timers[STATE_TIMER_MASS_SUM] += (long)(cpu_timer_stop(tstart_cpu)*1.0e9);

   return(gpu_mass_sum_total);
}
#endif

#ifdef HAVE_OPENCL
void State::allocate_device_memory(size_t ncells)
{
   dev_H = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_H"), DEVICE_REGULAR_MEMORY);
   dev_U = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_U"), DEVICE_REGULAR_MEMORY);
   dev_V = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_V"), DEVICE_REGULAR_MEMORY);
}
#endif

void State::resize_old_device_memory(size_t ncells)
{
#ifdef HAVE_OPENCL
   gpu_state_memory.memory_delete(dev_H);
   gpu_state_memory.memory_delete(dev_U);
   gpu_state_memory.memory_delete(dev_V);
   dev_H = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_H"), DEVICE_REGULAR_MEMORY);
   dev_U = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_U"), DEVICE_REGULAR_MEMORY);
   dev_V = (cl_mem)gpu_state_memory.memory_malloc(ncells, sizeof(cl_state_t), const_cast<char *>("dev_V"), DEVICE_REGULAR_MEMORY);
#else
   // Just to block compiler warnings
   if (1 == 2) printf("DEBUG -- ncells is %ld\n",ncells);
#endif
}

#ifdef HAVE_MPI
void State::do_load_balance_local(size_t &numcells){
   mesh->do_load_balance_local(numcells, NULL, state_memory);
   memory_reset_ptrs();
}
#endif
#ifdef HAVE_OPENCL
#ifdef HAVE_MPI
void State::gpu_do_load_balance_local(size_t &numcells){
   if (mesh->gpu_do_load_balance_local(numcells, NULL, gpu_state_memory) ){
      //gpu_state_memory.memory_report();
      dev_H = (cl_mem)gpu_state_memory.get_memory_ptr("dev_H");
      dev_U = (cl_mem)gpu_state_memory.get_memory_ptr("dev_U");
      dev_V = (cl_mem)gpu_state_memory.get_memory_ptr("dev_V");
/*
      if (dev_H == NULL){
         dev_H = (cl_mem)gpu_state_memory.get_memory_ptr("dev_H_new");
         dev_U = (cl_mem)gpu_state_memory.get_memory_ptr("dev_U_new");
         dev_V = (cl_mem)gpu_state_memory.get_memory_ptr("dev_V_new");
      }
      printf("DEBUG memory for proc %d dev_H is %p dev_U is %p dev_V is %p\n",mesh->mype,dev_H,dev_U,dev_V);
*/
   }
}
#endif
#endif

static double reference_time = 0.0;

void State::output_timing_info(int do_cpu_calc, int do_gpu_calc, double total_elapsed_time)
{
   int parallel = mesh->parallel;

   double cpu_time_compute = 0.0;
   double gpu_time_compute = 0.0;

   double cpu_elapsed_time = 0.0;
   double gpu_elapsed_time = 0.0;

   double cpu_mesh_time = 0.0;
   double gpu_mesh_time = 0.0;

   if (do_cpu_calc) {
      cpu_time_compute = get_cpu_timer(STATE_TIMER_SET_TIMESTEP) +
                         get_cpu_timer(STATE_TIMER_FINITE_DIFFERENCE) +
                         get_cpu_timer(STATE_TIMER_REFINE_POTENTIAL) +
                         get_cpu_timer(STATE_TIMER_REZONE_ALL) +
                         mesh->get_cpu_timer(MESH_TIMER_CALC_NEIGHBORS) +
                         mesh->get_cpu_timer(MESH_TIMER_LOAD_BALANCE) +
                         get_cpu_timer(STATE_TIMER_MASS_SUM) +
                         mesh->get_cpu_timer(MESH_TIMER_CALC_SPATIAL_COORDINATES) +
                         mesh->get_cpu_timer(MESH_TIMER_PARTITION);
      cpu_elapsed_time = cpu_time_compute;
      cpu_mesh_time = mesh->get_cpu_timer(MESH_TIMER_CALC_NEIGHBORS) +
                      get_cpu_timer(STATE_TIMER_REZONE_ALL) +
                      mesh->get_cpu_timer(MESH_TIMER_REFINE_SMOOTH) +
                      mesh->get_cpu_timer(MESH_TIMER_LOAD_BALANCE);
   }
   if (do_gpu_calc) {
      gpu_time_compute = get_gpu_timer(STATE_TIMER_APPLY_BCS) +
                         get_gpu_timer(STATE_TIMER_SET_TIMESTEP) +
                         get_gpu_timer(STATE_TIMER_FINITE_DIFFERENCE) +
                         get_gpu_timer(STATE_TIMER_REFINE_POTENTIAL) +
                         get_gpu_timer(STATE_TIMER_REZONE_ALL) +
                         mesh->get_gpu_timer(MESH_TIMER_CALC_NEIGHBORS) +
                         mesh->get_gpu_timer(MESH_TIMER_LOAD_BALANCE) +
                         get_gpu_timer(STATE_TIMER_MASS_SUM) +
                         mesh->get_gpu_timer(MESH_TIMER_CALC_SPATIAL_COORDINATES) +
                         mesh->get_gpu_timer(MESH_TIMER_COUNT_BCS);
      gpu_elapsed_time = get_gpu_timer(STATE_TIMER_WRITE) + gpu_time_compute + get_gpu_timer(STATE_TIMER_READ);
      gpu_mesh_time = mesh->get_gpu_timer(MESH_TIMER_CALC_NEIGHBORS) +
                      get_gpu_timer(STATE_TIMER_REZONE_ALL) +
                      mesh->get_gpu_timer(MESH_TIMER_REFINE_SMOOTH) +
                      mesh->get_gpu_timer(MESH_TIMER_LOAD_BALANCE);
   }

   if (! parallel && do_cpu_calc) reference_time = cpu_elapsed_time;

   double speedup_ratio = 0.0;
   if (reference_time > 0.0){
      if (do_cpu_calc && parallel) speedup_ratio = reference_time/cpu_elapsed_time;
      if (do_gpu_calc) speedup_ratio = reference_time/gpu_elapsed_time;
   }

   if (do_cpu_calc) {
      output_timer_block(MESH_DEVICE_CPU, cpu_elapsed_time, cpu_mesh_time, cpu_time_compute, total_elapsed_time, speedup_ratio);
   }
   if (do_gpu_calc) {
      output_timer_block(MESH_DEVICE_GPU, gpu_elapsed_time, gpu_mesh_time, gpu_time_compute, total_elapsed_time, speedup_ratio);
   }
}

void State::output_timer_block(mesh_device_types device_type, double elapsed_time,
   double mesh_time, double compute_time, double total_elapsed_time, double speedup_ratio)
{
   int mype  = mesh->mype;
   int parallel = mesh->parallel;

   int rank = mype;
   if (! parallel) {
      // We need to get rank info for check routines
#ifdef HAVE_MPI
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif
   }

   if (! parallel && rank) return;

   char device_string[10];
   if (device_type == MESH_DEVICE_CPU) {
      sprintf(device_string,"CPU");
   } else {
      sprintf(device_string,"GPU");
   }

#ifdef TIMING
   if (rank == 0) {
      printf("\n");
      printf("~~~~~~~~~~~~~~~~ Device timing information ~~~~~~~~~~~~~~~~~~\n");
   }

   if (rank == 0 && parallel) {
      printf("\n%3s: Parallel timings\n\n",device_string);
   }

   if (device_type == MESH_DEVICE_GPU) {
      mesh->parallel_output("GPU: Write to device          time was",  get_gpu_timer(STATE_TIMER_WRITE), 0, "s");
      mesh->parallel_output("GPU: Read from device         time was",  get_gpu_timer(STATE_TIMER_READ),  0, "s");
   }

   const char *device_compute_string[2] = {
      "CPU: Device compute           time was",
      "GPU: Device compute           time was"
   };
   mesh->parallel_output(device_compute_string[device_type], compute_time, 0, "s");

   timer_output(STATE_TIMER_SET_TIMESTEP,                  device_type, 1);
   timer_output(STATE_TIMER_FINITE_DIFFERENCE,             device_type, 1);
   timer_output(STATE_TIMER_REFINE_POTENTIAL,              device_type, 1);
   timer_output(STATE_TIMER_CALC_MPOT,                     device_type, 2);
   mesh->timer_output(MESH_TIMER_REFINE_SMOOTH,            device_type, 2);
   timer_output(STATE_TIMER_REZONE_ALL,                    device_type, 1);
   mesh->timer_output(MESH_TIMER_PARTITION,                device_type, 1);
   mesh->timer_output(MESH_TIMER_CALC_NEIGHBORS,           device_type, 1);
   if (mesh->get_calc_neighbor_type() == HASH_TABLE) {
      mesh->timer_output(MESH_TIMER_HASH_SETUP,            device_type, 2);
      mesh->timer_output(MESH_TIMER_HASH_QUERY,            device_type, 2);
      if (parallel) {
         mesh->timer_output(MESH_TIMER_FIND_BOUNDARY,      device_type, 2);
         mesh->timer_output(MESH_TIMER_PUSH_SETUP,         device_type, 2);
         mesh->timer_output(MESH_TIMER_PUSH_BOUNDARY,      device_type, 2);
         mesh->timer_output(MESH_TIMER_LOCAL_LIST,         device_type, 2);
         mesh->timer_output(MESH_TIMER_LAYER1,             device_type, 2);
         mesh->timer_output(MESH_TIMER_LAYER2,             device_type, 2);
         mesh->timer_output(MESH_TIMER_LAYER_LIST,         device_type, 2);
         mesh->timer_output(MESH_TIMER_COPY_MESH_DATA,     device_type, 2);
         mesh->timer_output(MESH_TIMER_FILL_MESH_GHOST,    device_type, 2);
         mesh->timer_output(MESH_TIMER_FILL_NEIGH_GHOST,   device_type, 2);
         mesh->timer_output(MESH_TIMER_SET_CORNER_NEIGH,   device_type, 2);
         mesh->timer_output(MESH_TIMER_NEIGH_ADJUST,       device_type, 2);
         mesh->timer_output(MESH_TIMER_SETUP_COMM,         device_type, 2);
      }
   } else {
      mesh->timer_output(MESH_TIMER_KDTREE_SETUP,          device_type, 2);
      mesh->timer_output(MESH_TIMER_KDTREE_QUERY,          device_type, 2);
   }
   timer_output(STATE_TIMER_MASS_SUM,                      device_type, 1);
   if (parallel) {
      mesh->timer_output(MESH_TIMER_LOAD_BALANCE,          device_type, 1);
   }
   mesh->timer_output(MESH_TIMER_CALC_SPATIAL_COORDINATES, device_type, 1);
   if (! mesh->have_boundary) {
      mesh->timer_output(MESH_TIMER_COUNT_BCS,             device_type, 1);
   }
   if (rank == 0) printf("=============================================================\n");

   const char *profile_string[2] = {
      "Profiling: Total CPU          time was",
      "Profiling: Total GPU          time was"
   };
   mesh->parallel_output(profile_string[device_type], elapsed_time, 0, "s");
   if (elapsed_time > 600.0){
      mesh->parallel_output("                                  or  ", elapsed_time/60.0, 0, "min");
   }

   if (rank == 0) printf("-------------------------------------------------------------\n");
   mesh->parallel_output("Mesh Ops (Neigh+rezone+smooth+balance) ",mesh_time, 0, "s");
   mesh->parallel_output("Mesh Ops Percentage                    ",mesh_time/elapsed_time*100.0, 0, "percent");
   if (rank == 0) printf("=============================================================\n");

   mesh->parallel_output("Profiling: Total              time was",total_elapsed_time, 0, "s");
   if (elapsed_time > 600.0){
      mesh->parallel_output("                                  or  ",total_elapsed_time/60.0, 0, "min");
   }

   if (speedup_ratio > 0.0) {
      mesh->parallel_output("Parallel Speed-up:                    ",speedup_ratio, 0, "Reference Serial CPU");
   }

   if (rank == 0) printf("=============================================================\n");
#endif
}

void State::timer_output(state_timer_category category, mesh_device_types device_type, int timer_level)
{
   int mype = mesh->mype;

   double local_time = 0.0;
   if (device_type == MESH_DEVICE_CPU){
      local_time = get_cpu_timer(category);
   } else {
      local_time = get_gpu_timer(category);
   }

   char string[80] = "/0";

   if (mype == 0) {
      const char *blank="          ";

      const char *device_string[2] = {
         "CPU",
         "GPU"
      };

      sprintf(string,"%3s: %.*s%-30.30s\t", device_string[device_type],
         2*timer_level, blank, state_timer_descriptor[category]);
   }

   mesh->parallel_output(string, local_time, timer_level, "s");
}

#ifdef HAVE_OPENCL
void State::compare_state_gpu_global_to_cpu_global(const char* string, int cycle, uint ncells)
{
   cl_command_queue command_queue = ezcl_get_command_queue();

   vector<state_t>H_check(ncells);
   vector<state_t>U_check(ncells);
   vector<state_t>V_check(ncells);
   ezcl_enqueue_read_buffer(command_queue, dev_H, CL_FALSE, 0, ncells*sizeof(cl_state_t), &H_check[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_U, CL_FALSE, 0, ncells*sizeof(cl_state_t), &U_check[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_V, CL_TRUE,  0, ncells*sizeof(cl_state_t), &V_check[0], NULL);
   for (uint ic = 0; ic < ncells; ic++){
      if (fabs(H[ic]-H_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d H & H_check %d %lf %lf\n",string,cycle,ic,H[ic],H_check[ic]);
      if (fabs(U[ic]-U_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d U & U_check %d %lf %lf\n",string,cycle,ic,U[ic],U_check[ic]);
      if (fabs(V[ic]-V_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d V & V_check %d %lf %lf\n",string,cycle,ic,V[ic],V_check[ic]);
   }
}
#endif

void State::compare_state_cpu_local_to_cpu_global(State *state_global, const char* string, int cycle, uint ncells, uint ncells_global, int *nsizes, int *ndispl)
{
   state_t *H_global = state_global->H;
   state_t *U_global = state_global->U;
   state_t *V_global = state_global->V;

   vector<state_t>H_check(ncells_global);
   vector<state_t>U_check(ncells_global);
   vector<state_t>V_check(ncells_global);
#ifdef HAVE_MPI
   MPI_Allgatherv(&H[0], ncells, MPI_STATE_T, &H_check[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&U[0], ncells, MPI_STATE_T, &U_check[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&V[0], ncells, MPI_STATE_T, &V_check[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
#else
   // Just to block compiler warnings
   if (1 == 2) printf("DEBUG -- ncells %u nsizes %d ndispl %d\n",ncells, nsizes[0],ndispl[0]);
#endif

   for (uint ic = 0; ic < ncells_global; ic++){
      if (fabs(H_global[ic]-H_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d H & H_check %d %lf %lf\n",string,cycle,ic,H_global[ic],H_check[ic]);
      if (fabs(U_global[ic]-U_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d U & U_check %d %lf %lf\n",string,cycle,ic,U_global[ic],U_check[ic]);
      if (fabs(V_global[ic]-V_check[ic]) > STATE_EPS) printf("DEBUG %s at cycle %d V & V_check %d %lf %lf\n",string,cycle,ic,V_global[ic],V_check[ic]);
   }
}

#ifdef HAVE_OPENCL
void State::compare_state_all_to_gpu_local(State *state_global, uint ncells, uint ncells_global, int mype, int ncycle, int *nsizes, int *ndispl)
{
#ifdef HAVE_MPI
   cl_command_queue command_queue = ezcl_get_command_queue();

   state_t *H_global = state_global->H;
   state_t *U_global = state_global->U;
   state_t *V_global = state_global->V;
   cl_mem &dev_H_global = state_global->dev_H;
   cl_mem &dev_U_global = state_global->dev_U;
   cl_mem &dev_V_global = state_global->dev_V;

   // Need to compare dev_H to H, etc
   vector<state_t>H_save(ncells);
   vector<state_t>U_save(ncells);
   vector<state_t>V_save(ncells);
   ezcl_enqueue_read_buffer(command_queue, dev_H, CL_FALSE, 0, ncells*sizeof(cl_state_t), &H_save[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_U, CL_FALSE, 0, ncells*sizeof(cl_state_t), &U_save[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_V, CL_TRUE,  0, ncells*sizeof(cl_state_t), &V_save[0], NULL);
   for (uint ic = 0; ic < ncells; ic++){
      if (fabs(H[ic]-H_save[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 1 at cycle %d H & H_save %d %lf %lf \n",mype,ncycle,ic,H[ic],H_save[ic]);
      if (fabs(U[ic]-U_save[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 1 at cycle %d U & U_save %d %lf %lf \n",mype,ncycle,ic,U[ic],U_save[ic]);
      if (fabs(V[ic]-V_save[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 1 at cycle %d V & V_save %d %lf %lf \n",mype,ncycle,ic,V[ic],V_save[ic]);
   }

   // And compare dev_H gathered to H_global, etc
   vector<state_t>H_save_global(ncells_global);
   vector<state_t>U_save_global(ncells_global);
   vector<state_t>V_save_global(ncells_global);
   MPI_Allgatherv(&H_save[0], nsizes[mype], MPI_STATE_T, &H_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&U_save[0], nsizes[mype], MPI_STATE_T, &U_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&V_save[0], nsizes[mype], MPI_STATE_T, &V_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   if (mype == 0) {
      for (uint ic = 0; ic < ncells_global; ic++){
         if (fabs(H_global[ic]-H_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 2 at cycle %d H_global & H_save_global %d %lf %lf \n",mype,ncycle,ic,H_global[ic],H_save_global[ic]);
         if (fabs(U_global[ic]-U_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 2 at cycle %d U_global & U_save_global %d %lf %lf \n",mype,ncycle,ic,U_global[ic],U_save_global[ic]);
         if (fabs(V_global[ic]-V_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 2 at cycle %d V_global & V_save_global %d %lf %lf \n",mype,ncycle,ic,V_global[ic],V_save_global[ic]);
      }
   }

   // And compare H gathered to H_global, etc
   MPI_Allgatherv(&H[0], nsizes[mype], MPI_STATE_T, &H_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&U[0], nsizes[mype], MPI_STATE_T, &U_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   MPI_Allgatherv(&V[0], nsizes[mype], MPI_STATE_T, &V_save_global[0], &nsizes[0], &ndispl[0], MPI_STATE_T, MPI_COMM_WORLD);
   if (mype == 0) {
      for (uint ic = 0; ic < ncells_global; ic++){
         if (fabs(H_global[ic]-H_save_global[ic]) > STATE_EPS) printf("DEBUG finite_difference 3 at cycle %d H_global & H_save_global %d %lf %lf \n",ncycle,ic,H_global[ic],H_save_global[ic]);
         if (fabs(U_global[ic]-U_save_global[ic]) > STATE_EPS) printf("DEBUG finite_difference 3 at cycle %d U_global & U_save_global %d %lf %lf \n",ncycle,ic,U_global[ic],U_save_global[ic]);
         if (fabs(V_global[ic]-V_save_global[ic]) > STATE_EPS) printf("DEBUG finite_difference 3 at cycle %d V_global & V_save_global %d %lf %lf \n",ncycle,ic,V_global[ic],V_save_global[ic]);
      }
   }

   // Now the global dev_H_global to H_global, etc
   ezcl_enqueue_read_buffer(command_queue, dev_H_global, CL_FALSE, 0, ncells_global*sizeof(cl_state_t), &H_save_global[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_U_global, CL_FALSE, 0, ncells_global*sizeof(cl_state_t), &U_save_global[0], NULL);
   ezcl_enqueue_read_buffer(command_queue, dev_V_global, CL_TRUE,  0, ncells_global*sizeof(cl_state_t), &V_save_global[0], NULL);
   if (mype == 0) {
      for (uint ic = 0; ic < ncells_global; ic++){
         if (fabs(H_global[ic]-H_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 4 at cycle %d H_global & H_save_global %d %lf %lf \n",mype,ncycle,ic,H_global[ic],H_save_global[ic]);
         if (fabs(U_global[ic]-U_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 4 at cycle %d U_global & U_save_global %d %lf %lf \n",mype,ncycle,ic,U_global[ic],U_save_global[ic]);
         if (fabs(V_global[ic]-V_save_global[ic]) > STATE_EPS) printf("%d: DEBUG finite_difference 4 at cycle %d V_global & V_save_global %d %lf %lf \n",mype,ncycle,ic,V_global[ic],V_save_global[ic]);
      }
   }
#else
   // Just to get rid of compiler warnings
   if (1 == 2) printf("%d: DEBUG -- ncells %d ncells_global %d ncycle %d nsizes[0] %d ndispl %d state_global %p\n",
      mype,ncells,ncells_global,ncycle,nsizes[0],ndispl[0],state_global);
#endif
}
#endif

void State::print_object_info(void)
{
   printf(" ---- State object info -----\n");

#ifdef HAVE_OPENCL
   int num_elements, elsize;

   num_elements = ezcl_get_device_mem_nelements(dev_H);
   elsize = ezcl_get_device_mem_elsize(dev_H);
   printf("dev_H       ptr : %p nelements %d elsize %d\n",dev_H,num_elements,elsize);
   num_elements = ezcl_get_device_mem_nelements(dev_U);
   elsize = ezcl_get_device_mem_elsize(dev_U);
   printf("dev_U       ptr : %p nelements %d elsize %d\n",dev_U,num_elements,elsize);
   num_elements = ezcl_get_device_mem_nelements(dev_V);
   elsize = ezcl_get_device_mem_elsize(dev_V);
   printf("dev_V       ptr : %p nelements %d elsize %d\n",dev_V,num_elements,elsize);
   num_elements = ezcl_get_device_mem_nelements(dev_mpot);
   elsize = ezcl_get_device_mem_elsize(dev_mpot);
   printf("dev_mpot    ptr : %p nelements %d elsize %d\n",dev_mpot,num_elements,elsize);
   //num_elements = ezcl_get_device_mem_nelements(dev_ioffset);
   //elsize = ezcl_get_device_mem_elsize(dev_ioffset);
   //printf("dev_ioffset ptr : %p nelements %d elsize %d\n",dev_ioffset,num_elements,elsize);
#endif
   state_memory.memory_report();
   //printf("vector H    ptr : %p nelements %ld elsize %ld\n",&H[0],H.size(),sizeof(H[0]));
   //printf("vector U    ptr : %p nelements %ld elsize %ld\n",&U[0],U.size(),sizeof(U[0]));
   //printf("vector V    ptr : %p nelements %ld elsize %ld\n",&V[0],V.size(),sizeof(V[0]));
}

void State::print(void)
{  //printf("size is %lu %lu %lu %lu %lu\n",index.size(), i.size(), level.size(), nlft.size(), x.size());

   if (mesh->fp == NULL) {
      char filename[10];
      sprintf(filename,"out%1d",mesh->mype);
      mesh->fp=fopen(filename,"w");
   }

   if (mesh->mesh_memory.get_memory_size(mesh->nlft) >= mesh->ncells_ghost){
      fprintf(mesh->fp,"%d:   index global  i     j     lev   nlft  nrht  nbot  ntop \n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
      for (uint ic=mesh->ncells; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
   } else {
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev\n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d  \n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic]);
      }
   }
}

const int CRUX_STATE_VERSION = 102;
const int num_int_vals       = 1;

size_t State::get_checkpoint_size(void)
{
#ifdef FULL_PRECISION
   size_t nsize = mesh->ncells*3*sizeof(double);
#else
   size_t nsize = mesh->ncells*3*sizeof(float);
#endif
   nsize += num_int_vals*sizeof(int);
   nsize += mesh->get_checkpoint_size();
   return(nsize);
}

void State::store_checkpoint(Crux *crux)
{
   // Store mesh data first
   mesh->store_checkpoint(crux);

//#ifndef HAVE_MPI
   // Load up scalar values
   int int_vals[num_int_vals];
   int_vals[0] = CRUX_STATE_VERSION;

   // Add to memory database for storing checkpoint
   state_memory.memory_add(int_vals, (size_t)num_int_vals, 4, "state_int_vals", RESTART_DATA | REPLICATED_DATA);
   state_memory.memory_add(cpu_timers, (size_t)STATE_TIMER_SIZE, 8, "state_cpu_timers", RESTART_DATA);
   state_memory.memory_add(gpu_timers, (size_t)STATE_TIMER_SIZE, 8, "state_gpu_timers", RESTART_DATA);

   crux->store_MallocPlus(state_memory);

   // Remove from database after checkpoint is stored
   state_memory.memory_remove(int_vals);
   state_memory.memory_remove(cpu_timers);
   state_memory.memory_remove(gpu_timers);
//#endif
}

void State::restore_checkpoint(Crux *crux)
{
   int storage;
   // Restore mesh data first
   mesh->restore_checkpoint(crux);
   crux->restore_named_ints("storage", 7, &storage, 1);

   // Create memory for restoring data into
   int int_vals[num_int_vals];

   // allocate is a state method
   allocate(storage);

   // Add to memory database for restoring checkpoint
   state_memory.memory_add(int_vals, (size_t)num_int_vals, 4, "state_int_vals", RESTART_DATA | REPLICATED_DATA);
   state_memory.memory_add(cpu_timers, (size_t)STATE_TIMER_SIZE, 8, "state_cpu_timers", RESTART_DATA);
   state_memory.memory_add(gpu_timers, (size_t)STATE_TIMER_SIZE, 8, "state_gpu_timers", RESTART_DATA);

   // Restore memory database
   crux->restore_MallocPlus(state_memory);

   // Check version number
   if (int_vals[ 0] != CRUX_STATE_VERSION) {
      printf("CRUX version mismatch for state data, version on file is %d, version in code is %d\n",
         int_vals[0], CRUX_STATE_VERSION);
      exit(0);
   }

#ifdef DEBUG_RESTORE_VALS
   if (DEBUG_RESTORE_VALS) {
      printf("\n");
      printf("       === Restored state cpu timers ===\n");
      for (int i = 0; i < STATE_TIMER_SIZE; i++){
         printf("       %-30s %lg\n",state_timer_descriptor[i], cpu_timers[i]);
      }
      printf("       === Restored state cpu timers ===\n");
      printf("\n");
   }
#endif

#ifdef DEBUG_RESTORED_VALS
   if (DEBUG_RESTORED_VALS) {
      printf("\n");
      printf("       === Restored state gpu timers ===\n");
      for (int i = 0; i < STATE_TIMER_SIZE; i++){
         printf("       %-30s %lld\n",state_timer_descriptor[i], gpu_timers[i]);
      }
      printf("       === Restored state gpu_timers ===\n");
      printf("\n");
   }
#endif

   state_memory.memory_remove(int_vals);
   state_memory.memory_remove(cpu_timers);
   state_memory.memory_remove(gpu_timers);
   
   memory_reset_ptrs();
//#endif
}

// Added overloaded print to get mesh information to print in each cycle
// Brian Atkinson (5-29-14)
void State::print(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage)
{  //printf("size is %lu %lu %lu %lu %lu\n",index.size(), i.size(), level.size(), nlft.size(), x.size());

      char filename[40];
      sprintf(filename,"iteration%d",iteration);
      mesh->fp=fopen(filename,"w");

      if(iteration_mass == 0.0){
         fprintf(mesh->fp,"Iteration = %d\t\tSimuation Time = %lf\n", iteration, simTime);
         fprintf(mesh->fp,"mesh->ncells = %lu\t\tmesh->ncells_ghost = %lu\n", mesh->ncells, mesh->ncells_ghost);
         fprintf(mesh->fp,"Initial Mass: %14.12lg\t\tSimulation Time: %lf\n", initial_mass, simTime);
      }
      else{
         double mass_diff = iteration_mass - initial_mass;
         fprintf(mesh->fp,"Iteration = %d\t\tSimuation Time = %lf\n", iteration, simTime);
         fprintf(mesh->fp,"mesh->ncells = %lu\t\tmesh->ncells_ghost = %lu\n", mesh->ncells, mesh->ncells_ghost);
         fprintf(mesh->fp,"Initial Mass: %14.12lg\t\tIteration Mass: %14.12lg\n", initial_mass, iteration_mass);
         fprintf(mesh->fp,"Mass Difference: %12.6lg\t\tMass Difference Percentage: %12.6lg%%\n", mass_diff, mass_diff_percentage);
      }

   if (mesh->mesh_memory.get_memory_size(mesh->nlft) >= mesh->ncells_ghost){
      fprintf(mesh->fp,"%d:   index global  i     j     lev   nlft  nrht  nbot  ntop \n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
      for (uint ic=mesh->ncells; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
   } else {
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev\n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d  \n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic]);
      }
   }
}

void State::print_local(int ncycle)
{  //printf("size is %lu %lu %lu %lu %lu\n",index.size(), i.size(), level.size(), nlft.size(), x.size());

   if (mesh->fp == NULL) {
      char filename[10];
      sprintf(filename,"out%1d",mesh->mype);
      mesh->fp=fopen(filename,"w");
   }

   fprintf(mesh->fp,"DEBUG in print_local ncycle is %d\n",ncycle);
   if (mesh->nlft != NULL){
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev   nlft   nrht   nbot   ntop\n",mesh->mype);
      uint state_size = state_memory.get_memory_size(H);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         if (ic >= state_size){
            fprintf(mesh->fp,"%d: %6d                              %4d  %4d   %4d  %4d  %4d  %4d  %4d\n", mesh->mype,ic, mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
         } else {
            fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d  %4d  %4d  %4d  %4d\n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
         }
      }
   } else {
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev\n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d\n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic]);
      }
   }
}

void State::print_failure_log(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage, bool got_nan){
   char filename[] = {"failure.log"};
   mesh->fp=fopen(filename,"w");

   double mass_diff = iteration_mass - initial_mass;
   if(got_nan){
      fprintf(mesh->fp,"Failed because of nan for H_sum was equal to NAN\n");
   }
   else{
      fprintf(mesh->fp,"Failed because mass difference is outside of accepted percentage\n");
   }
   fprintf(mesh->fp,"Iteration = %d\t\tSimuation Time = %lf\n", iteration, simTime);
   fprintf(mesh->fp,"mesh->ncells = %lu\t\tmesh->ncells_ghost = %lu\n", mesh->ncells, mesh->ncells_ghost);
   fprintf(mesh->fp,"Initial Mass: %14.12lg\t\tIteration Mass: %14.12lg\n", initial_mass, iteration_mass);
   fprintf(mesh->fp,"Mass Difference: %12.6lg\t\tMass Difference Percentage: %12.6lg%%\n", mass_diff, mass_diff_percentage);

   if (mesh->mesh_memory.get_memory_size(mesh->nlft) >= mesh->ncells_ghost){
      fprintf(mesh->fp,"%d:   index global  i     j     lev   nlft  nrht  nbot  ntop \n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
      for (uint ic=mesh->ncells; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
   } else {
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev\n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d  \n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic]);
      }
   }
}

void State::print_rollback_log(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage, int backup_attempt, int num_of_attempts, int error_status){
   char filename[40];
   sprintf(filename, "rollback%d.log",backup_attempt);
   mesh->fp=fopen(filename,"w");

   double mass_diff = iteration_mass - initial_mass;
   if(error_status == STATUS_NAN){
      fprintf(mesh->fp,"Rolling back because of nan for H_sum was equal to NAN\n");
   }
   else{
      fprintf(mesh->fp,"Rolling back because mass difference is outside of accepted percentage\n");
   }
   fprintf(mesh->fp,"Rollback attempt %d of %d ---> Number of attempts left:%d\n", backup_attempt, num_of_attempts, num_of_attempts - backup_attempt);
   fprintf(mesh->fp,"Iteration = %d\t\tSimuation Time = %lf\n", iteration, simTime);
   fprintf(mesh->fp,"mesh->ncells = %lu\t\tmesh->ncells_ghost = %lu\n", mesh->ncells, mesh->ncells_ghost);
   fprintf(mesh->fp,"Initial Mass: %14.12lg\t\tIteration Mass: %14.12lg\n", initial_mass, iteration_mass);
   fprintf(mesh->fp,"Mass Difference: %12.6lg\t\tMass Difference Percentage: %12.6lg%%\n", mass_diff, mass_diff_percentage);

   if (mesh->mesh_memory.get_memory_size(mesh->nlft) >= mesh->ncells_ghost){
      fprintf(mesh->fp,"%d:   index global  i     j     lev   nlft  nrht  nbot  ntop \n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
      for (uint ic=mesh->ncells; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d  %6d %4d  %4d   %4d  %4d  %4d  %4d  %4d \n", mesh->mype,ic, ic+mesh->noffset,mesh->i[ic], mesh->j[ic], mesh->level[ic], mesh->nlft[ic], mesh->nrht[ic], mesh->nbot[ic], mesh->ntop[ic]);
      }
   } else {
      fprintf(mesh->fp,"%d:  index     H        U         V      i     j     lev\n",mesh->mype);
      for (uint ic=0; ic<mesh->ncells_ghost; ic++) {
         fprintf(mesh->fp,"%d: %6d %lf %lf %lf %4d  %4d   %4d  \n", mesh->mype,ic, H[ic], U[ic], V[ic], mesh->i[ic], mesh->j[ic], mesh->level[ic]);
      }
   }
}
