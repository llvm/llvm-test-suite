/*
 *  Copyright (c) 2011-2012, Los Alamos National Security, LLC.
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

#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <vector>
//#include "graphics/display.h"
#include "graphics.h"
#include "input.h"
#include "mesh.h"
#include "partition.h"
#include "state.h"
#include "timer.h"
#include "memstats.h"
#include "crux.h"
#include "PowerParser.hh"
#include "MallocPlus.h"
#ifdef HAVE_ITTNOTIFY
#include <ittnotify.h>
#endif

using namespace PP;

#ifdef _OPENMP
#include <omp.h>
#endif

#ifndef DEBUG
#define DEBUG 0
#endif
#undef DEBUG_RESTORE_VALS

#define MIN3(x,y,z) ( min( min(x,y), z) )

static int do_cpu_calc = 1;
static int do_gpu_calc = 0;

typedef unsigned int uint;

static bool do_display_graphics = false;

#ifdef HAVE_GRAPHICS
static double circle_radius=-1.0;
#ifdef FULL_PRECISION
   void (*set_display_cell_coordinates)(double *, double *, double *, double *) = &set_display_cell_coordinates_double;
   void (*set_display_cell_data)(double *) = &set_display_cell_data_double;
#else
   void (*set_display_cell_coordinates)(float *, float *, float *, float *) = &set_display_cell_coordinates_float;
   void (*set_display_cell_data)(float *) = &set_display_cell_data_float;
#endif
#endif

static int view_mode = 0;

#ifdef FULL_PRECISION
#define  SUM_ERROR 2.0e-16
   void (*set_graphics_cell_coordinates)(double *, double *, double *, double *) = &set_graphics_cell_coordinates_double;
   void (*set_graphics_cell_data)(double *) = &set_graphics_cell_data_double;
#else
#define  SUM_ERROR 1.0e-8
   void (*set_graphics_cell_coordinates)(float *, float *, float *, float *) = &set_graphics_cell_coordinates_float;
   void (*set_graphics_cell_data)(float *) = &set_graphics_cell_data_float;
#endif

void store_crux_data(Crux *crux, int ncycle);
void restore_crux_data_bootstrap(Crux *crux, char *restart_file, int rollback_counter);
void restore_crux_data(Crux *crux);

bool        restart,        //  Flag to start from a back up file; init in input.cpp::parseInput().
            verbose,        //  Flag for verbose command-line output; init in input.cpp::parseInput().
            localStencil,   //  Flag for use of local stencil; init in input.cpp::parseInput().
            face_based,     //  Flag for face-based finite difference;
            outline;        //  Flag for drawing outlines of cells; init in input.cpp::parseInput().
int         outputInterval, //  Periodicity of output; init in input.cpp::parseInput().
            crux_type,      //  Type of checkpoint/restart -- CRUX_NONE, CRUX_IN_MEMORY, CRUX_DISK;
                            //  init in input.cpp::parseInput().
            enhanced_precision_sum,//  Flag for enhanced precision sum (default true); init in input.cpp::parseInput().
            lttrace_on,     //  Flag to turn on logical time trace package;
            do_quo_setup,   //  Flag to turn on quo dynamic scheduling policies package;
            levmx,          //  Maximum number of refinement levels; init in input.cpp::parseInput().
            nx,             //  x-resolution of coarse grid; init in input.cpp::parseInput().
            ny,             //  y-resolution of coarse grid; init in input.cpp::parseInput().
            niter,          //  Maximum iterations; init in input.cpp::parseInput().
            graphic_outputInterval, // Periodicity of graphic output that is saved; init in input.cpp::parseInput()
            checkpoint_outputInterval, // Periodicity of checkpoint output that is saved; init in input.cpp::parseInput()
            num_of_rollback_states,// Maximum number of rollback states to maintain; init in input.cpp::parseInput()
            backup_file_num,//  Backup file number to restart simulation from; init in input.cpp::parseInput()
            numpe,          //  
            ndim    = 2;    //  Dimensionality of problem (2 or 3).
double      upper_mass_diff_percentage; //  Flag for the allowed pecentage difference to the total
                                        //  mass per output intervals; init in input.cpp::parseInput().

char *restart_file;

static int it = 0;

enum partition_method initial_order,  //  Initial order of mesh.
                      cycle_reorder;  //  Order of mesh every cycle.
static Mesh        *mesh;           //  Object containing mesh information
static State       *state;          //  Object containing state information corresponding to mesh
static Crux        *crux;           //  Object containing checkpoint/restart information
static PowerParser *parse;          //  Object containing input file parsing

static real_t circ_radius = 0.0;
static int next_cp_cycle = 0;
static int next_graphics_cycle = 0;

//  Set up timing information.
static struct timeval tstart, tstart_cpu, tstart_partmeas;

static double H_sum_initial = 0.0;
static double cpu_time_graphics = 0.0;
static double cpu_time_calcs    = 0.0;
static double cpu_time_partmeas = 0.0;

static int     ncycle  = 0;
static double  simTime = 0.0;
static double  deltaT = 0.0;
char total_sim_time_log[] = {"total_execution_time.log"};
struct timeval total_exec;

static int mype=0;
int main(int argc, char **argv) {

   // Needed for code to compile correctly on the Mac
   int numpe=-1;

   //  Process command-line arguments, if any.
   parseInput(argc, argv);

#ifdef _OPENMP
   int nt = 0;
   int tid = 0;

   nt = omp_get_max_threads();
   tid = omp_get_thread_num();
   if (0 == tid && mype == 0) {
        printf("--- max num openmp threads: %d\n", nt);
   }
#pragma omp parallel firstprivate(nt, tid)
   {
      nt = omp_get_num_threads();
      tid = omp_get_thread_num();

#pragma omp master
      if (mype == 0) {
         printf("--- num openmp threads in parallel region: %d\n", nt);
      }
   }
#endif

   parse = new PowerParser();

   struct timeval tstart_setup;
   cpu_timer_start(&tstart_setup);

   crux = new Crux(crux_type, num_of_rollback_states, restart);

   circ_radius = 6.0;
   //  Scale the circle appropriately for the mesh size.
   circ_radius = circ_radius * (real_t) nx / 128.0;
   int boundary = 1;
   int parallel_in = 0;
   double deltax_in = 1.0;
   double deltay_in = 1.0;

   if (restart){
      restore_crux_data_bootstrap(crux, restart_file, 0);
      mesh  = new Mesh(nx, ny, levmx, ndim, deltax_in, deltay_in, boundary, parallel_in, do_gpu_calc);
      mesh->init(nx, ny, circ_radius, initial_order, do_gpu_calc);

      state = new State(mesh);
      restore_crux_data(crux);
      mesh->proc.resize(mesh->ncells);
      mesh->calc_distribution(numpe);
   } else {
      mesh = new Mesh(nx, ny, levmx, ndim, deltax_in, deltay_in, boundary, parallel_in, do_gpu_calc);
      if (DEBUG) {
         //if (mype == 0) mesh->print();

         char filename[10];
         sprintf(filename,"out%1d",mype);
         mesh->fp=fopen(filename,"w");

         //mesh->print_local();
      }

      mesh->init(nx, ny, circ_radius, initial_order, do_gpu_calc);
      state = new State(mesh);
      state->init(do_gpu_calc);
      mesh->proc.resize(mesh->ncells);
      mesh->calc_distribution(numpe);
      state->fill_circle(circ_radius, 100.0, 7.0);
   }

   size_t &ncells = mesh->ncells;

   if (graphic_outputInterval > niter) next_graphics_cycle = graphic_outputInterval;
   if (checkpoint_outputInterval > niter) next_cp_cycle = checkpoint_outputInterval;


   //  Kahan-type enhanced precision sum implementation.
   double H_sum = state->mass_sum(enhanced_precision_sum);
   if (mype == 0) printf ("Mass of initialized cells equal to %14.12lg\n", H_sum);
   H_sum_initial = H_sum;

   if(upper_mass_diff_percentage < 0){
      upper_mass_diff_percentage = H_sum_initial * SUM_ERROR;
      //printf("Setting sum mass error to %16.8lg\n",upper_mass_diff_percentage);
   }

   double cpu_time_main_setup = cpu_timer_stop(tstart_setup);
   #ifdef TIMING
   mesh->parallel_output("CPU:  setup time               time was",cpu_time_main_setup, 0, "s");
   #endif 

   #ifdef MEMORY
   long long mem_used = memstats_memused();
   if (mem_used > 0) {
      mesh->parallel_output("Memory used      in startup ",mem_used, 0, "kB");
      mesh->parallel_output("Memory peak      in startup ",memstats_mempeak(), 0, "kB");
      mesh->parallel_output("Memory free      at startup ",memstats_memfree(), 0, "kB");
      mesh->parallel_output("Memory available at startup ",memstats_memtotal(), 0, "kB");
   }
   #endif

   if (mype == 0) {
      if (ncycle != 0){
         printf("Iteration %3d timestep %lf Sim Time %lf cells %ld Mass Sum %14.12lg\n",
            ncycle, deltaT, simTime, ncells, H_sum);
      } else {
         printf("Iteration   0 timestep      n/a Sim Time      0.0 cells %ld Mass Sum %14.12lg\n", ncells, H_sum);
      }
   }

   for (int i = 0; i < MESH_COUNTER_SIZE; i++){
      mesh->cpu_counters[i]=0;
   }
   for (int i = 0; i < MESH_TIMER_SIZE; i++){
      mesh->cpu_timers[i]=0.0;
   }

   cpu_timer_start(&tstart_cpu);

#ifdef HAVE_GRAPHICS
   do_display_graphics = true;
   set_display_mysize(ncells);
   set_display_cell_coordinates(&mesh->x[0], &mesh->dx[0], &mesh->y[0], &mesh->dy[0]);
   set_display_cell_data(&state->H[0]);
   set_display_cell_proc(&mesh->proc[0]);

   set_display_window((float)mesh->xmin, (float)mesh->xmax,
                      (float)mesh->ymin, (float)mesh->ymax);
   set_display_outline((int)outline);
   set_display_viewmode(view_mode);
#endif

   if (ncycle == next_graphics_cycle){
      set_graphics_outline(outline);
      set_graphics_window((float)mesh->xmin, (float)mesh->xmax,
                          (float)mesh->ymin, (float)mesh->ymax);
      set_graphics_mysize(ncells);
      set_graphics_cell_coordinates(&mesh->x[0], &mesh->dx[0],
                                    &mesh->y[0], &mesh->dy[0]);
      set_graphics_cell_data(&state->H[0]);
      set_graphics_cell_proc(&mesh->proc[0]);
      set_graphics_viewmode(view_mode);

      if (mype == 0) {
         init_graphics_output();
         set_graphics_cell_proc(&mesh->proc[0]);
         write_graphics_info(0,0,0.0,0,0);
      }
      next_graphics_cycle += graphic_outputInterval;
   }

#ifdef HAVE_GRAPHICS
   set_display_circle_radius(circle_radius);
   init_display(&argc, argv, "Shallow Water");
   draw_scene();
   //if (verbose) sleep(5);
   sleep(2);

   //  Clear superposition of circle on grid output.
   circle_radius = -1.0;
#endif
   cpu_time_graphics += cpu_timer_stop(tstart_cpu);

   //  Set flag to show mesh results rather than domain decomposition.
   view_mode = 1;

   if (ncycle == next_cp_cycle) store_crux_data(crux, ncycle); 

   cpu_timer_start(&tstart);
#ifdef HAVE_GRAPHICS
   set_idle_function(&do_calc);
   start_main_loop();
#else
#ifdef HAVE_ITTNOTIFY
__itt_resume();
__SSC_MARK(0x111);
#endif
   for (it = ncycle; it < 10000000; it++) {
      do_calc();
   }
#ifdef HAVE_ITTNOTIFY
__itt_pause();
__SSC_MARK(0x222);
#endif
#endif
   
   return 0;
}

extern "C" void do_calc(void)
{  double g     = 9.80;
   double sigma = 0.95;
   int icount, jcount;
   static int rollback_attempt = 0;
   static double total_program_time = 0;

   //  Initialize state variables for GPU calculation.
   size_t &ncells    = mesh->ncells;

   vector<int>     mpot;
   
   size_t new_ncells = 0;
   double H_sum = -1.0;

   //  Main loop.
   int endcycle = MIN3(niter, next_cp_cycle, next_graphics_cycle);

   cpu_timer_start(&tstart_cpu);

   for (int nburst = ncycle % outputInterval; nburst < outputInterval && ncycle < endcycle; nburst++, ncycle++) {

#ifdef _OPENMP
#pragma omp parallel
      {
#endif
         //  Calculate the real time step for the current discrete time step.
         double mydeltaT = state->set_timestep(g, sigma); // Private variable to avoid write conflict
#ifdef _OPENMP
#pragma omp barrier
#pragma omp master
         {
#endif
           deltaT = mydeltaT;
           simTime += deltaT;
#ifdef _OPENMP
         }
#endif

         mesh->calc_neighbors(ncells);

         cpu_timer_start(&tstart_partmeas);
         mesh->partition_measure();

#ifdef _OPENMP
#pragma omp master
#endif
         cpu_time_partmeas += cpu_timer_stop(tstart_partmeas);

         // Currently not working -- may need to be earlier?
         //if (do_cpu_calc && ! mesh->have_boundary) {
         //  state->add_boundary_cells(mesh);
         //}

         // Apply BCs is currently done as first part of gpu_finite_difference and so comparison won't work here

         mesh->set_bounds(ncells);

         //  Execute main kernel
         if (face_based) {
            state->calc_finite_difference_via_faces(deltaT);
         } else {
            state->calc_finite_difference(deltaT);
         }

         //  Size of arrays gets reduced to just the real cells in this call for have_boundary = 0
         state->remove_boundary_cells();
#ifdef _OPENMP
      } // end parallel region
#endif

      mpot.resize(ncells);
      new_ncells = state->calc_refine_potential(mpot, icount, jcount);

      //  Resize the mesh, inserting cells where refinement is necessary.

#ifdef _OPENMP
#pragma omp parallel
      {
#endif
      state->rezone_all(icount, jcount, mpot);

      // Clear does not delete mpot, so have to swap with an empty vector to get
      // it to delete the mpot memory. This is all to avoid valgrind from showing
      // it as a reachable memory leak
#ifdef _OPENMP
#pragma omp master
      {
#endif
      //mpot.clear();
      vector<int>().swap(mpot);

      mesh->ncells = new_ncells;
      ncells = new_ncells;
#ifdef _OPENMP
      }
#pragma omp barrier
#endif
      mesh->set_bounds(ncells);

#ifdef _OPENMP
#pragma omp master
      {
#endif
   //cpu_timer_start(&tstart_check);
      mesh->proc.resize(ncells);
      if (icount)
      {  vector<int> index(ncells);
         mesh->partition_cells(numpe, index, cycle_reorder);
         state->state_reorder(index);
         state->memory_reset_ptrs();
      }
   //cpu_time_check += cpu_timer_stop(tstart_check);
#ifdef _OPENMP
      }
#pragma omp barrier
#endif

#ifdef _OPENMP
      } // end parallel region
#endif
      
   } // End burst loop

   cpu_time_calcs += cpu_timer_stop(tstart_cpu);

   H_sum = state->mass_sum(enhanced_precision_sum);

   int error_status = STATUS_OK;

   if (std::isnan(H_sum)) {
      printf("Got a NAN on cycle %d\n",ncycle);
      error_status = STATUS_NAN;
   }

   double percent_mass_diff = fabs(H_sum - H_sum_initial)/H_sum_initial * 100.0;
   if (percent_mass_diff >= upper_mass_diff_percentage) {
      printf("Mass difference outside of acceptable range on cycle %d percent_mass_diff %lg upper limit %lg\n",ncycle,percent_mass_diff, upper_mass_diff_percentage);
      error_status = STATUS_MASS_LOSS;
   }

   if (error_status != STATUS_OK){
      if (crux_type != CRUX_NONE) {

         rollback_attempt++;
         if (rollback_attempt > num_of_rollback_states) {
            printf("Can not recover from error from back up files. Killing program...\n");
            total_program_time = cpu_timer_stop(total_exec);
            FILE *fp = fopen(total_sim_time_log,"w");
            fprintf(fp,"The total execution time of the program before failure was %g seconds\n", total_program_time);
            fclose(fp);
            state->print_failure_log(ncycle, simTime, H_sum_initial, H_sum, percent_mass_diff, true);
            exit(-1);
         }

         if (graphic_outputInterval <= niter){
            mesh->calc_spatial_coordinates(0);
            set_graphics_mysize(ncells);
            set_graphics_viewmode(view_mode);
            set_graphics_cell_coordinates(&mesh->x[0], &mesh->dx[0], &mesh->y[0], &mesh->dy[0]);
            set_graphics_cell_data(&state->H[0]);
            set_graphics_cell_proc(&mesh->proc[0]);
            write_graphics_info(ncycle/graphic_outputInterval,ncycle,simTime,1,rollback_attempt);
         }

         if((ncycle - (rollback_attempt)*checkpoint_outputInterval) < 0){
            printf("Rolling simulation back to to ncycle 0\n");
         }
         else{
            printf("Rolling simulation back to to ncycle %d\n", ncycle - (rollback_attempt*checkpoint_outputInterval));
         }

         state->print_rollback_log(ncycle, simTime, H_sum_initial, H_sum, percent_mass_diff, rollback_attempt, num_of_rollback_states, error_status);

         int rollback_num = crux->get_rollback_number();

         restore_crux_data_bootstrap(crux, NULL, rollback_num);
         mesh->terminate();
         state->terminate();
         restore_crux_data(crux);


      } else {
         printf("failure.log has been created\n");
         state->print_failure_log(ncycle, simTime, H_sum_initial, H_sum, percent_mass_diff, true);
         exit(-1);
      }
   }

   if (mype == 0 && ncycle % outputInterval == 0) {
      printf("Iteration %3d timestep %lf Sim Time %lf cells %ld Mass Sum %14.12lg Mass Change %12.6lg\n",
         ncycle, deltaT, simTime, ncells, H_sum, H_sum - H_sum_initial);
   }

   if (ncycle == next_cp_cycle) store_crux_data(crux, ncycle); 

   cpu_timer_start(&tstart_cpu);

   if(do_display_graphics || ncycle == next_graphics_cycle ||
      (ncycle >= niter && graphic_outputInterval < niter) ){

      mesh->calc_spatial_coordinates(0);
   }

   if(ncycle == next_graphics_cycle){
      set_graphics_mysize(ncells);
      set_graphics_viewmode(view_mode);
      set_graphics_cell_coordinates(&mesh->x[0], &mesh->dx[0], &mesh->y[0], &mesh->dy[0]);
      set_graphics_cell_data(&state->H[0]);
      set_graphics_cell_proc(&mesh->proc[0]);

      write_graphics_info(ncycle/graphic_outputInterval,ncycle,simTime,0,0);
      next_graphics_cycle += graphic_outputInterval;
   }

#ifdef HAVE_GRAPHICS
   if(ncycle % outputInterval == 0){
      if(ncycle != next_graphics_cycle){
         set_display_mysize(ncells);
         set_display_viewmode(view_mode);
         set_display_cell_coordinates(&mesh->x[0], &mesh->dx[0], &mesh->y[0], &mesh->dy[0]);
         set_display_cell_data(&state->H[0]);
         set_display_cell_proc(NULL);
      }
      set_display_circle_radius(circle_radius);
      draw_scene();
   }

#endif

   cpu_time_graphics += cpu_timer_stop(tstart_cpu);

   //  Output final results and timing information.
   if (ncycle >= niter) {
      //free_display();
      
      if(graphic_outputInterval < niter){
         cpu_timer_start(&tstart_cpu);

#ifdef HAVE_GRAPHICS
         set_display_viewmode(view_mode);
         set_display_mysize(ncells);
         set_display_cell_coordinates(&mesh->x[0], &mesh->dx[0], &mesh->y[0], &mesh->dy[0]);
         set_display_cell_data(&state->H[0]);
         set_display_cell_proc(NULL);
#endif

         if (mype == 0) {
            write_graphics_info(ncycle/graphic_outputInterval,ncycle,simTime,0,0);
         }
         next_graphics_cycle += graphic_outputInterval;

         cpu_time_graphics += cpu_timer_stop(tstart_cpu);
      }

      //  Get overall program timing.
      double elapsed_time = cpu_timer_stop(tstart);

      #ifdef MEMORY
      long long mem_used = memstats_memused();
      if (mem_used > 0) {
         printf("Memory used      %lld kB\n",mem_used);
         printf("Memory peak      %lld kB\n",memstats_mempeak());
         printf("Memory free      %lld kB\n",memstats_memfree());
         printf("Memory available %lld kB\n",memstats_memtotal());
      }
      #endif
      state->output_timing_info(do_cpu_calc, do_gpu_calc, elapsed_time);
      #ifdef TIMING
      mesh->parallel_output("CPU:  calc incl part meas     time was",cpu_time_calcs,    0, "s");
      mesh->parallel_output("CPU:  calculation only        time was",cpu_time_calcs-cpu_time_partmeas,    0, "s");
      mesh->parallel_output("CPU:  partition measure       time was",cpu_time_partmeas, 0, "s");
      mesh->parallel_output("CPU:  graphics                time was",cpu_time_graphics, 0, "s");
      //mesh->parallel_output("CPU:  check                   time was",cpu_time_check,    0, "s");
      #endif

      mesh->print_partition_measure();
      mesh->print_calc_neighbor_type();
      mesh->print_partition_type();

      printf("CPU:  rezone frequency                \t %8.4f\tpercent\n",     (double)mesh->get_cpu_counter(MESH_COUNTER_REZONE)/(double)ncycle*100.0 );
      printf("CPU:  calc neigh frequency            \t %8.4f\tpercent\n",     (double)mesh->get_cpu_counter(MESH_COUNTER_CALC_NEIGH)/(double)ncycle*100.0 );
      printf("CPU:  refine_smooth_iter per rezone   \t %8.4f\t\n",            (double)mesh->get_cpu_counter(MESH_COUNTER_REFINE_SMOOTH)/(double)mesh->get_cpu_counter(MESH_COUNTER_REZONE) );

      mesh->terminate();
      state->terminate();

      terminate_graphics_output();

      delete mesh;
      delete state;
      delete crux;
      delete parse;

      total_program_time = cpu_timer_stop(total_exec);
      FILE *fp = fopen(total_sim_time_log,"w");
      fprintf(fp,"The total execution time of the program was %g seconds\n", total_program_time);
      fclose(fp);
      exit(0);
   }  //  Complete final output.

} // end do_calc

const int CRUX_CLAMR_VERSION = 101;
const int num_int_vals       = 15;
const int num_double_vals    =  5;

MallocPlus clamr_bootstrap_memory;

void store_crux_data(Crux *crux, int ncycle)
{
   size_t nsize = num_int_vals*sizeof(int) +
                  num_double_vals*sizeof(double);
   nsize += state->get_checkpoint_size();

   next_cp_cycle += checkpoint_outputInterval;

   int int_vals[num_int_vals];

   int_vals[ 0] = CRUX_CLAMR_VERSION; // Version number
   int_vals[ 1] = nx;
   int_vals[ 2] = ny;
   int_vals[ 3] = levmx;
   int_vals[ 4] = ndim;
   int_vals[ 5] = outputInterval;
   int_vals[ 6] = enhanced_precision_sum;
   int_vals[ 7] = niter;
   int_vals[ 8] = it;
   int_vals[ 9] = ncycle;
   int_vals[10] = crux_type;
   int_vals[11] = graphic_outputInterval;
   int_vals[12] = checkpoint_outputInterval;
   int_vals[13] = next_cp_cycle;
   int_vals[14] = next_graphics_cycle;

   double double_vals[num_double_vals];
   double_vals[ 0] = circ_radius;
   double_vals[ 1] = H_sum_initial;
   double_vals[ 2] = simTime;
   double_vals[ 3] = deltaT;
   double_vals[ 4] = upper_mass_diff_percentage;

   clamr_bootstrap_memory.memory_add(int_vals, size_t(num_int_vals), 4, "bootstrap_int_vals", RESTART_DATA);
   clamr_bootstrap_memory.memory_add(double_vals, size_t(num_double_vals), 8, "bootstrap_double_vals", RESTART_DATA);

   crux->store_begin(nsize, ncycle);

   crux->store_MallocPlus(clamr_bootstrap_memory);

   state->store_checkpoint(crux);

   crux->store_end();

   clamr_bootstrap_memory.memory_remove(int_vals);
   clamr_bootstrap_memory.memory_remove(double_vals);
}

void restore_crux_data_bootstrap(Crux *crux, char *restart_file, int rollback_counter)
{
   crux->restore_begin(restart_file, rollback_counter);

   int int_vals[num_int_vals];

   double double_vals[num_double_vals];

   clamr_bootstrap_memory.memory_add(int_vals, size_t(num_int_vals), 4, "bootstrap_int_vals", RESTART_DATA);
   clamr_bootstrap_memory.memory_add(double_vals, size_t(num_double_vals), 8, "bootstrap_double_vals", RESTART_DATA);

   crux->restore_MallocPlus(clamr_bootstrap_memory);

   if (int_vals[ 0] != CRUX_CLAMR_VERSION) {
      printf("CRUX version mismatch for clamr data, version on file is %d, version in code is %d\n",
         int_vals[0], CRUX_CLAMR_VERSION);
      exit(0);
   }

   nx                        = int_vals[ 1];
   ny                        = int_vals[ 2];
   levmx                     = int_vals[ 3];
   ndim                      = int_vals[ 4];
   outputInterval            = int_vals[ 5];
   enhanced_precision_sum    = int_vals[ 6];
   niter                     = int_vals[ 7];
   it                        = int_vals[ 8];
   ncycle                    = int_vals[ 9];
   crux_type                 = int_vals[10];
   graphic_outputInterval    = int_vals[11];
   checkpoint_outputInterval = int_vals[12];
   next_cp_cycle             = int_vals[13];
   next_graphics_cycle       = int_vals[14];

   circ_radius                = double_vals[ 0];
   H_sum_initial              = double_vals[ 1];
   simTime                    = double_vals[ 2];
   deltaT                     = double_vals[ 3];
   upper_mass_diff_percentage = double_vals[ 4];

   // need to reset crux type, because initialize to none
   // before checkpoint is read
   crux->set_crux_type(crux_type);

   clamr_bootstrap_memory.memory_remove(int_vals);
   clamr_bootstrap_memory.memory_remove(double_vals);

#ifdef DEBUG_RESTORE_VALS
   if (DEBUG_RESTORE_VALS) {
      const char *int_vals_descriptor[num_int_vals] = {
         "CRUX_CLAMR_VERSION",
         "nx",
         "ny",
         "levmx",
         "ndim",
         "outputInterval",
         "enhanced_precision_sum",
         "niter",
         "it",
         "ncycle",
         "crux_type",
         "graphic_outputInterval",
         "checkpoint_outputInterval",
         "next_cp_cycle",
         "next_graphics_cycle"
      };
      printf("\n");
      printf("       === Restored bootstrap int_vals ===\n");
      for (int i = 0; i < num_int_vals; i++){
         printf("       %-30s %d\n",int_vals_descriptor[i], int_vals[i]);
      }
      printf("       === Restored bootstrap int_vals ===\n");
      printf("\n");
   }
#endif

#ifdef DEBUG_RESTORE_VALS
   if (DEBUG_RESTORE_VALS) {
      const char *double_vals_descriptor[num_double_vals] = {
         "circ_radius",
         "H_sum_initial",
         "simTime",
         "deltaT",
         "upper_mass_diff_percentage"
      };
      printf("\n");
      printf("       === Restored bootstrap double_vals ===\n");
      for (int i = 0; i < num_double_vals; i++){
         printf("       %-30s %lg\n",double_vals_descriptor[i], double_vals[i]);
      }
      printf("       === Restored bootstrap double_vals ===\n");
      printf("\n");
   }
#endif
}

void restore_crux_data(Crux *crux)
{
   state->restore_checkpoint(crux);

   crux->restore_end();
}


