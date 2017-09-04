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
#ifndef STATE_H_
#define STATE_H_

#include <list>
#include "MallocPlus.h"
#include "mesh.h"
#include "crux.h"
#ifdef HAVE_OPENCL
#include "ezcl/ezcl.h"
#endif
//#include "l7/l7.h"

#define STATUS_OK        0
#define STATUS_NAN       1
#define STATUS_MASS_LOSS 2

#if !defined(FULL_PRECISION) && !defined(MIXED_PRECISION) && !defined(MINIMUM_PRECISION)
#define FULL_PRECISION
#endif
#ifdef NO_CL_DOUBLE
#undef  FULL_PRECISION
#undef  MIXED_PRECISION
#define MINIMUM_PRECISION
#endif

#if defined(MINIMUM_PRECISION)
   typedef float state_t; // this is for physics state variables ncell in size
   typedef float real_t; // this is used for intermediate calculations
   typedef struct
   {
      float s0;
      float s1;
   }  real2_t;
#define CONSERVATION_EPS    15.0
#ifdef HAVE_OPENCL
   typedef cl_float  cl_state_t; // for gpu physics state variables
   typedef cl_float4 cl_state4_t; // for gpu physics state variables
   typedef cl_float  cl_real_t; // for intermediate gpu physics state variables
   typedef cl_float2 cl_real2_t; // for intermediate gpu physics state variables
   typedef cl_float4 cl_real4_t; // for intermediate gpu physics state variables
#endif
#ifdef HAVE_MPI
   #define MPI_STATE_T MPI_FLOAT // for MPI communication for physics state variables
   #define MPI_REAL_T MPI_FLOAT // for MPI communication for physics state variables
   #define L7_STATE_T L7_FLOAT
   #define L7_REAL_T L7_FLOAT
#endif

#elif defined(MIXED_PRECISION) // intermediate values calculated high precision and stored as floats
   typedef float state_t;
   typedef double real_t;
   typedef struct
   {
      double s0;
      double s1;
   }  real2_t;
#define CONSERVATION_EPS    .02
#ifdef HAVE_OPENCL
   typedef cl_float   cl_state_t;
   typedef cl_float4  cl_state4_t;
   typedef cl_double  cl_real_t; // for intermediate gpu physics state variables
   typedef cl_double2 cl_real2_t; // for intermediate gpu physics state variables
   typedef cl_double4 cl_real4_t; // for intermediate gpu physics state variables
#endif
#ifdef HAVE_MPI
   #define MPI_STATE_T MPI_FLOAT
   #define MPI_REAL_T MPI_DOUBLE
   #define L7_STATE_T L7_FLOAT
   #define L7_REAL_T L7_DOUBLE
#endif

#elif defined(FULL_PRECISION)
   typedef double state_t;
   typedef double real_t;
   typedef struct
   {
      double s0;
      double s1;
   }  real2_t;
#define CONSERVATION_EPS    .02
#ifdef HAVE_OPENCL
   typedef cl_double  cl_state_t;
   typedef cl_double4 cl_state4_t;
   typedef cl_double  cl_real_t; // for intermediate gpu physics state variables
   typedef cl_double2 cl_real2_t; // for intermediate gpu physics state variables
   typedef cl_double4 cl_real4_t; // for intermediate gpu physics state variables
#endif
#ifdef HAVE_MPI
   #define MPI_STATE_T MPI_DOUBLE
   #define MPI_REAL_T MPI_DOUBLE
   #define L7_STATE_T L7_DOUBLE
   #define L7_REAL_T L7_DOUBLE
#endif
#endif

extern "C" void do_calc(void);

enum SUM_TYPE {
   SUM_REGULAR,
   SUM_KAHAN
};


enum SIGN_RULE {
   DIAG_RULE,
   X_RULE,
   Y_RULE,
};

enum state_timers
{
   STATE_TIMER_APPLY_BCS,
   STATE_TIMER_SET_TIMESTEP,
   STATE_TIMER_FINITE_DIFFERENCE,
   STATE_TIMER_REFINE_POTENTIAL,
   STATE_TIMER_CALC_MPOT,
   STATE_TIMER_REZONE_ALL,
   STATE_TIMER_MASS_SUM,
   STATE_TIMER_READ,
   STATE_TIMER_WRITE,
   STATE_TIMER_SIZE
};

typedef enum state_timers   state_timer_category;

using namespace std;

class State {
   
public:
   MallocPlus state_memory;
   MallocPlus gpu_state_memory;
   Mesh *mesh;
   state_t *H;
   state_t *U;
   state_t *V;

#ifdef HAVE_OPENCL
   cl_mem dev_H;
   cl_mem dev_U;
   cl_mem dev_V;

   cl_mem dev_mass_sum;
   cl_mem dev_deltaT;

   cl_event apply_BCs_event;

   cl_mem dev_mpot;
   //cl_mem dev_ioffset;
   cl_mem dev_result;
#endif

   double    cpu_timers[STATE_TIMER_SIZE];
   long long gpu_timers[STATE_TIMER_SIZE];

   // constructor -- allocates state arrays to size ncells
   State(Mesh *mesh_in);

   void init(int do_gpu_calc);
   void terminate(void);

   /* Memory routines for linked list of state arrays */
   void allocate(size_t ncells);
   void allocate_from_backup_file(FILE *fp);
   void allocate_for_rollback(State *state_to_copy);
   void resize(size_t ncells);
   void memory_reset_ptrs(void);
#ifdef HAVE_OPENCL
   void allocate_device_memory(size_t ncells);
#endif
   void resize_old_device_memory(size_t ncells);

   /* Accessor routines */
   double get_cpu_timer(state_timer_category category)  {return(cpu_timers[category]); };
   /* Convert nanoseconds to msecs */
   double get_gpu_timer(state_timer_category category)  {return((double)(gpu_timers[category])*1.0e-9); };

   /* Boundary routines -- not currently used */
   void add_boundary_cells(void);
   void apply_boundary_conditions(void);
   void apply_boundary_conditions_local(void);
   void apply_boundary_conditions_ghost(void);
   void remove_boundary_cells(void);

   /*******************************************************************
   * set_timestep
   *  Input
   *    H, U, V -- from state object
   *    celltype, level, lev_delta
   *  Output
   *    mindeltaT returned
   *******************************************************************/
   double set_timestep(double g, double sigma);
#ifdef HAVE_OPENCL
   double gpu_set_timestep(double sigma);
#endif

   /*******************************************************************
   * calc finite difference
   *      will add ghost region to H, U, V and fill at start of routine
   *   Input
   *      H, U, V -- from state object
   *      nlft, nrht, nbot, ntop, level, celltype -- from mesh object
   *   Output
   *      H, U, V
   *******************************************************************/
   void calc_finite_difference(double deltaT);
   void calc_finite_difference_via_faces(double deltaT);
#ifdef HAVE_OPENCL
   void gpu_calc_finite_difference(double deltaT);
#endif

   /*******************************************************************
   * calc refine potential -- state has responsibility to calc initial
   *      refinement potential array that is then passed to mesh for
   *      smoothing and enforcing refinement ruiles
   *  Input
   *    H, U, V -- from state object
   *  Output
   *    mpot
   *    ioffset
   *    count
   *******************************************************************/
   size_t calc_refine_potential(vector<int> &mpot, int &icount, int &jcount);
#ifdef HAVE_OPENCL
   size_t gpu_calc_refine_potential(int &icount, int &jcount);
#endif

   /*******************************************************************
   * rezone all -- most of call is done in mesh
   *  Input
   *    Mesh and state variables
   *  Output
   *    New mesh and state variables on refined mesh
   *******************************************************************/
   void rezone_all(int icount, int jcount, vector<int> mpot);
#ifdef HAVE_OPENCL
   void gpu_rezone_all(int icount, int jcount, bool localStencil);
#endif

   /*******************************************************************
   * load balance -- most of call is done in mesh, but pointers are
   *    reset to newly allocated state arrays
   *  Input
   *    Mesh and state variables
   *  Output
   *    New mesh and state variables on refined mesh
   *******************************************************************/
#ifdef HAVE_MPI
   void do_load_balance_local(size_t &numcells);
#ifdef HAVE_OPENCL
   void gpu_do_load_balance_local(size_t &numcells);
#endif
#endif

   /*******************************************************************
   * mass sum -- Conservation of mass check
   *  Input
   *    H from state object
   *    Precision type for sum
   *  Output
   *    total mass is returned
   *******************************************************************/
   double mass_sum(int enhanced_precision_sum);
#ifdef HAVE_OPENCL
   double gpu_mass_sum(int enhanced_precision_sum);
#endif
   
   void fill_circle(double circ_radius, double fill_value, double background);
   void state_reorder(vector<int> iorder);

   void symmetry_check(const char *string, vector<int> sym_index, double eps, 
                       SIGN_RULE sign_rule, int &flag);

   void output_timing_info(int do_cpu_calc, int do_gpu_calc, double total_elapsed_time);

   /* state comparison routines */
#ifdef HAVE_OPENCL
   void compare_state_gpu_global_to_cpu_global(const char* string, int cycle, uint ncells);
#endif
   void compare_state_cpu_local_to_cpu_global(State *state_global, const char* string, int cycle, uint ncells, uint ncells_global, int *nsizes, int *ndispl);
#ifdef HAVE_OPENCL
   void compare_state_all_to_gpu_local(State *state_global, uint ncells, uint ncells_global, int mype, int ncycle, int *nsizes, int *ndispl);
#endif

   void output_timer_block(mesh_device_types device_type, double elapsed_time,
      double mesh_time, double compute_time, double total_elapsed_time, double speedup_ratio);

   void timer_output(state_timer_category category, mesh_device_types device_type, int timer_level);

   void print(void);

   size_t get_checkpoint_size(void);
   void store_checkpoint(Crux *crux);
   void restore_checkpoint(Crux *crux);
   //Added to for second print for every interation: Brian Atkinson (5-29-14)
   void print(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage);  
   void print_local(int ncycle);
   void print_failure_log(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage, bool got_nan);
   void print_rollback_log(int iteration, double simTime, double initial_mass, double iteration_mass, double mass_diff_percentage, int backup_attempt, int num_of_attempts, int error_status);

private:
   State(const State&); // To block copy constructor so copies are not made inadvertently

   void print_object_info(void);
};

#endif // ifndef STATE_H_

