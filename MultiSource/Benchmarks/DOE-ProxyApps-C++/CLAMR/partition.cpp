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
#ifdef HAVE_MPI
#include "mpi.h"
#endif

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <algorithm>
#include "partition.h"
#include "KDTree.h"
#include "mesh.h"
#ifdef HAVE_MPI
#include "s7.h"
#endif
#include "zorder.h"
#include "timer.h"
#include "hsfc.h"

#ifndef DEBUG
#define DEBUG 0
#endif

typedef unsigned int uint;

int measure_type;
int      meas_count                  = 0;
double   meas_sum_average            = 0.0;

extern bool localStencil;
extern int initial_order;
extern int cycle_reorder;

void Mesh::partition_measure(void) 
{
  if (measure_type != NO_PARTITION_MEASURE){

     int ntX     = TILE_SIZE; 
     static double offtile_ratio = 0.0;

     uint num_groups = (ncells + TILE_SIZE - 1)/TILE_SIZE;

     if (measure_type == WITH_DUPLICATES) {
        int i = 0;
#ifdef _OPENMP
#pragma omp for reduction(+:offtile_ratio)
#endif
        for (uint group_id=0; group_id < num_groups; group_id ++){ 
 
           int start_idx = group_id * ntX;
           int end_idx   = (group_id + 1) * ntX; 

           int offtile =0;
           for (uint ic = 0; ic < TILE_SIZE; ic++, i++){ 

              if (i >= ncells) continue;
              //taken from wave_kern_calc.cl 'setup tile' kernel
              if (nlft[i] < start_idx || nlft[i] >= end_idx) offtile++; 
              if (level[nlft[i]] > level[i] &&
                 (ntop[nlft[i]] < start_idx || ntop[nlft[i]] >= end_idx) ) offtile++;
              if (nrht[i] < start_idx || nrht[i] >= end_idx) offtile++; 
              if (level[nrht[i]] > level[i] &&
                 (ntop[nrht[i]] < start_idx || ntop[nrht[i]] >= end_idx) ) offtile++;
              if (nbot[i] < start_idx || nbot[i] >= end_idx) offtile++; 
              if (level[nbot[i]] > level[i] &&
                 (nrht[nbot[i]] < start_idx || nrht[nbot[i]] >= end_idx) ) offtile++;
              if (ntop[i] < start_idx || ntop[i] >= end_idx) offtile++; 
              if (level[ntop[i]] > level[i] &&
                 (nrht[ntop[i]] < start_idx || nrht[ntop[i]] >= end_idx) ) offtile++;
           }
           offtile_ratio += (double)offtile/(double)(TILE_SIZE);
           //printf("DEBUG Ratio of surface area to volume is equal to %d / %d ratio is %lf\n", offtile, TILE_SIZE, (double)offtile/(double)TILE_SIZE);
        }
     } else if (measure_type == WITHOUT_DUPLICATES) {
        int i = 0;
#ifdef _OPENMP
#pragma omp for reduction(+:offtile_ratio)
#endif
        for (uint group_id=0; group_id < num_groups; group_id ++){ 
           list<int> offtile_list;
 
           int start_idx = group_id * ntX;
           int end_idx   = (group_id + 1) * ntX; 

           for (uint ic = 0; ic < TILE_SIZE; ic++, i++){ 

              if (i >= ncells) continue;

              if (nlft[i] < start_idx || nlft[i] >= end_idx) offtile_list.push_back(nlft[i]);
              if (level[nlft[i]] > level[i] &&
                 (ntop[nlft[i]] < start_idx || ntop[nlft[i]] >= end_idx) ) offtile_list.push_back(ntop[nlft[i]]);
              if (nrht[i] < start_idx || nrht[i] >= end_idx) offtile_list.push_back(nrht[i]);
              if (level[nrht[i]] > level[i] &&
                 (ntop[nrht[i]] < start_idx || ntop[nrht[i]] >= end_idx) ) offtile_list.push_back(ntop[nrht[i]]);
              if (nbot[i] < start_idx || nbot[i] >= end_idx) offtile_list.push_back(nbot[i]);
              if (level[nbot[i]] > level[i] &&
                 (nrht[nbot[i]] < start_idx || nrht[nbot[i]] >= end_idx) ) offtile_list.push_back(nrht[nbot[i]]);
              if (ntop[i] < start_idx || ntop[i] >= end_idx) offtile_list.push_back(ntop[i]);
              if (level[ntop[i]] > level[i] &&
                 (nrht[ntop[i]] < start_idx || nrht[ntop[i]] >= end_idx) ) offtile_list.push_back(nrht[ntop[i]]);
           }
           offtile_list.sort();
           offtile_list.unique();
        
           offtile_ratio += (double)offtile_list.size()/(double)(TILE_SIZE);
           //printf("DEBUG Ratio of surface area to volume is equal to %d / %d ratio is %lf\n", offtile, TILE_SIZE, (double)offtile/(double)TILE_SIZE);
        }
     } else if (measure_type == CVALUE) {
        int i = 0;
#ifdef _OPENMP
#pragma omp for reduction(+:offtile_ratio)
#endif
        for (uint group_id=0; group_id < num_groups; group_id ++){ 
           list<int> offtile_list;
 
           int start_idx = group_id * ntX;
           int end_idx   = (group_id + 1) * ntX; 

           for (uint ic = 0; ic < TILE_SIZE; ic++, i++){ 

              if (i >= ncells) continue;

              if (nlft[i] < start_idx || nlft[i] >= end_idx) offtile_list.push_back(nlft[i]);
              if (level[nlft[i]] > level[i] &&
                 (ntop[nlft[i]] < start_idx || ntop[nlft[i]] >= end_idx) ) offtile_list.push_back(ntop[nlft[i]]);
              if (nrht[i] < start_idx || nrht[i] >= end_idx) offtile_list.push_back(nrht[i]);
              if (level[nrht[i]] > level[i] &&
                 (ntop[nrht[i]] < start_idx || ntop[nrht[i]] >= end_idx) ) offtile_list.push_back(ntop[nrht[i]]);
              if (nbot[i] < start_idx || nbot[i] >= end_idx) offtile_list.push_back(nbot[i]);
              if (level[nbot[i]] > level[i] &&
                 (nrht[nbot[i]] < start_idx || nrht[nbot[i]] >= end_idx) ) offtile_list.push_back(nrht[nbot[i]]);
              if (ntop[i] < start_idx || ntop[i] >= end_idx) offtile_list.push_back(ntop[i]);
              if (level[ntop[i]] > level[i] &&
                 (nrht[ntop[i]] < start_idx || nrht[ntop[i]] >= end_idx) ) offtile_list.push_back(nrht[ntop[i]]);
           }
           offtile_list.sort();
           offtile_list.unique();
        
           offtile_ratio += (double)offtile_list.size()/(4*sqrt((double)(TILE_SIZE)));
           //printf("DEBUG Ratio of surface area to volume is equal to %d / %d ratio is %lf\n", offtile, TILE_SIZE, (double)offtile/(double)TILE_SIZE);
        }
     } else if (measure_type == CSTARVALUE) {
        int i = 0;
#ifdef _OPENMP
#pragma omp for reduction(+:offtile_ratio)
#endif
        for (uint group_id=0; group_id < num_groups; group_id ++){ 
           list<int> offtile_list;
           list<int> offtile_cache_lines; // Assumes memory is aligned
           int cache_line_size = 4; // Some could be 8, or more?
 
           int start_idx = group_id * ntX;
           int end_idx   = (group_id + 1) * ntX; 

           for (uint ic = 0; ic < TILE_SIZE; ic++, i++){ 

              if (i >= ncells) continue;

              if (nlft[i] < start_idx || nlft[i] >= end_idx) {
                  offtile_list.push_back(nlft[i]);
                  offtile_cache_lines.push_back(nlft[i]/cache_line_size);
              }
               
              if (level[nlft[i]] > level[i] && (ntop[nlft[i]] < start_idx || ntop[nlft[i]] >= end_idx) ) {
                  offtile_list.push_back(ntop[nlft[i]]);
                  offtile_cache_lines.push_back(ntop[nlft[i]]/cache_line_size);
              }
              if (nrht[i] < start_idx || nrht[i] >= end_idx) {
                  offtile_list.push_back(nrht[i]);
                  offtile_cache_lines.push_back(nrht[i]/cache_line_size);
              }
              if (level[nrht[i]] > level[i] && (ntop[nrht[i]] < start_idx || ntop[nrht[i]] >= end_idx) ) {
                  offtile_list.push_back(ntop[nrht[i]]);
                  offtile_cache_lines.push_back(ntop[nrht[i]]/cache_line_size);
              }
              if (nbot[i] < start_idx || nbot[i] >= end_idx) {
                  offtile_list.push_back(nbot[i]);
                  offtile_cache_lines.push_back(nbot[i]/cache_line_size);
              }
              if (level[nbot[i]] > level[i] && (nrht[nbot[i]] < start_idx || nrht[nbot[i]] >= end_idx) ) {
                  offtile_list.push_back(nrht[nbot[i]]);
                  offtile_cache_lines.push_back(nrht[nbot[i]]/cache_line_size);
              }
              if (ntop[i] < start_idx || ntop[i] >= end_idx) {
                  offtile_list.push_back(ntop[i]);
                  offtile_cache_lines.push_back(ntop[i]/cache_line_size);
              }
              if (level[ntop[i]] > level[i] && (nrht[ntop[i]] < start_idx || nrht[ntop[i]] >= end_idx) ) {
                  offtile_list.push_back(nrht[ntop[i]]);
                  offtile_cache_lines.push_back(nrht[ntop[i]]/cache_line_size);
              }
           }
           offtile_list.sort();
           offtile_list.unique();
           offtile_cache_lines.sort();
           offtile_cache_lines.unique();

           double s_ngeom = (double)(offtile_list.size());
           double q_ngeom = (double)(offtile_cache_lines.size());
           double ngeom = (double)(TILE_SIZE);
           double cover = (double)(cache_line_size);
//            offtile_ratio += (s_ngeom * q_ngeom) / (4*sqrt(ngeom)*2*(1+(ngeom+cache_line_size-1)/cache_line_size));
//            offtile_ratio += (q_ngeom) / (2*sqrt(ngeom)+2*((sqrt(ngeom)+cover-1)/cover));
//            offtile_ratio += (q_ngeom) / ( (8*sqrt(ngeom)+cover-1)/cover );
           ngeom = sqrt(ngeom);
           offtile_ratio += (s_ngeom*q_ngeom*cover) / ( 4 * ngeom * (8*ngeom+cover-1) );
        
           //printf("DEBUG Ratio of surface area to volume is equal to %d / %d ratio is %lf\n", offtile, TILE_SIZE, (double)offtile/(double)TILE_SIZE);
        }
     } 

     // printf("DEBUG Ratio of surface area to volume is equal to %d / %d \n", offtile, ontile);
   
#ifdef _OPENMP
#pragma omp master
     {
#endif
         meas_count ++;
         meas_sum_average  += offtile_ratio/(double)num_groups;
     // printf("DEBUG %d icount %d sum_average %lf\n",__LINE__,icount, sum_average);
#ifdef _OPENMP
     }
#endif
  } // if PARTITION TYPE
}

void Mesh::print_partition_measure()
{
   if (meas_count != 0) {
      if        (measure_type == NO_PARTITION_MEASURE) {
         if (mype == 0) printf("No Partition Measure\n");
      } else if (measure_type == WITH_DUPLICATES) {
         parallel_output("Average surface area to volume ratio  ", meas_sum_average/(double)meas_count, 0, "with duplicates");
      } else if (measure_type == WITHOUT_DUPLICATES) {
         parallel_output("Average surface area to volume ratio  ", meas_sum_average/(double)meas_count, 0, "without duplicates");
      } else if (measure_type == CVALUE) {
         parallel_output("Partition Quality Avg C value     ", meas_sum_average/(double)meas_count, 0, "");
      } else if (measure_type == CSTARVALUE){
         parallel_output("Partition Quality Avg C* value     ", meas_sum_average/(double)meas_count, 0, "");
      }
   }

   if (numpe > 1){
      parallel_output("The MPI surface area to volume ratio ", offtile_ratio_local, 0, "without duplicates");
   }
}

void Mesh::print_partition_type()
{
   if (mype == 0) {
      if (initial_order == ORIGINAL_ORDER) {
         printf("Initial order is naive.");  
      } else if (initial_order == HILBERT_SORT) {
         printf("Initial order is Hilbert sort.");  
      } else if (initial_order == HILBERT_PARTITION) {
         printf("Initial order is Hilbert partitionr.");  
      } else if (initial_order == ZORDER) {
         printf("Initial order is Z order.");  
      }

      if (cycle_reorder == ORIGINAL_ORDER) {
         printf("   No cycle reorder.");  
      } else if (cycle_reorder == HILBERT_SORT) {
         printf("   Cycle reorder is Hilbert sort.");  
      } else if (cycle_reorder == HILBERT_PARTITION) {
         printf("   Cycle reorder is Hilbert partition.");  
      } else if (cycle_reorder == ZORDER) {
         printf("   Cycle reorder is Z order.");  
      }

      if (localStencil) {
         printf("   Local Stencil is on.\n");  
      } else {
         printf("\n");
      }
   }

}
void Mesh::partition_cells(
                    int          numpe,             //  
                    vector<int> &z_order,           //  Resulting index ordering.
                    enum partition_method method)   //  Assigned partitioning method.
{  
   int           *info;      //
   double         iscale,    //
                  jscale;    //
   int            imax,      //  Maximum x-index.
                  jmax;      //  Maximum y-index.
   vector<int>    z_index;   //  Ordered curve from hsfc.
   vector<int>    i_scaled;  //  x-indices normalized to a scale of [0, 1] for hsfc.
   vector<int>    j_scaled;  //  y-indices normalized to a scale of [0, 1] for hsfc.
   vector<double> iunit;     //
   vector<double> junit;     //

   struct timeval tstart_cpu;
   cpu_timer_start(&tstart_cpu);

   //  Initialize ordered curve index.
   z_index.resize(ncells, 0);
   //z_order.resize(ncells, 0);

   if (parallel) {
#ifdef HAVE_MPI
      nsizes.resize(numpe);
      ndispl.resize(numpe);
      MPI_Allgather(&ncells, 1, MPI_INT, &nsizes[0], 1, MPI_INT, MPI_COMM_WORLD);
      ndispl[0]=0;
      for (int ip=1; ip<numpe; ip++){
         ndispl[ip] = ndispl[ip-1] + nsizes[ip-1];
      }
      noffset=0;
      for (int ip=0; ip<mype; ip++){
        noffset += nsizes[ip];
      }
#endif
   } else {
      //   Adjust the number of required work items to the number of cells.
      proc.resize(ncells);
      //   Decompose the domain equitably.
      calc_distribution(numpe);
      noffset = 0;
   }

   
   //  Partition cells according to one of several possible orderings.
   int have_spatial_variables=0;
   switch (method)
   {   case ORIGINAL_ORDER:
         //  Set z_order to the current cell order.
         for (uint ic = 0; ic < ncells; ++ic)
         {   z_order[ic] = ic; }

         cpu_timers[MESH_TIMER_PARTITION] += cpu_timer_stop(tstart_cpu);

         return;
         break;

       case HILBERT_SORT:
         //  Resort the curve by Hilbert order.
         have_spatial_variables = 1;
         if (x.size() < ncells) {
            calc_spatial_coordinates(0);
            have_spatial_variables = 0;
         }
         calc_centerminmax();
         iunit.resize(ncells);
         junit.resize(ncells);

         //   Get the range of values in the x- and y-directions and make the scale square.
         iscale = 1.0 / (xcentermax - xcentermin);
         jscale = 1.0 / (ycentermax - ycentermin);

         //   Scale the indices to a normalized [0, 1] range for hsfc.
         for (uint ic = 0; ic < ncells; ++ic){
             iunit[ic] = (x[ic] + 0.5 * dx[ic] - xcentermin) * iscale;
             junit[ic] = (y[ic] + 0.5 * dy[ic] - ycentermin) * jscale;
         }

         if (have_spatial_variables == 0){
            x.clear();
            dx.clear();
            y.clear();
            dy.clear();
         }

         if (parallel){
#ifdef HAVE_MPI
            info = (int *)malloc(sizeof(int) * 3 * ncells_global);
            vector<double>iunit_global(ncells_global);
            vector<double>junit_global(ncells_global);
            vector<int>z_order_global(ncells_global);

            MPI_Allgatherv(&iunit[0], ncells, MPI_DOUBLE, &iunit_global[0], &nsizes[0], &ndispl[0], MPI_DOUBLE, MPI_COMM_WORLD);
            MPI_Allgatherv(&junit[0], ncells, MPI_DOUBLE, &junit_global[0], &nsizes[0], &ndispl[0], MPI_DOUBLE, MPI_COMM_WORLD);
            //   Sort the mesh into an ordered space-filling curve from hsfc.
            hsfc2sort(ncells_global, &iunit_global[0], &junit_global[0], 0, info, 1);

            //   Copy the cell order information from info into z_order.
            for (uint ic = 0; ic < ncells_global; ++ic)
            {   z_order_global[ic] = info[ic]; }
            free(info);

            //   Order the mesh according to the calculated order (note that z_order is for both curves).
            vector<int> int_global(ncells_global);
            vector<int> int_global_new(ncells_global);

            // gather, reorder and scatter i
            MPI_Allgatherv(&i[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &i[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // gather, reorder and scatter j
            MPI_Allgatherv(&j[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &j[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // gather, reorder and scatter level
            MPI_Allgatherv(&level[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &level[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // It is faster just to recalculate these variables instead of communicating them
            if (mesh_memory.get_memory_size(celltype) >= ncells) {
               calc_celltype(mesh_memory.get_memory_size(celltype));
            }

            if (have_spatial_variables) {
               calc_spatial_coordinates(0);
            }

            if (mesh_memory.get_memory_size(nlft) >= ncells) {
               vector<int> inv_z_order(ncells_global);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  inv_z_order[z_order_global[ic]] = ic;
               }

               MPI_Allgatherv(&nlft[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nlft[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&nrht[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nrht[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&nbot[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nbot[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&ntop[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &ntop[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);
            }

            MPI_Scatterv(&z_order_global[0], &nsizes[0], &ndispl[0], MPI_INT, &z_order[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);
#endif
         } else {
            info = (int *)malloc(sizeof(int) * 3 * ncells);

            //   Sort the mesh into an ordered space-filling curve from hsfc.
            hsfc2sort(ncells, &iunit[0], &junit[0], 0, info, 1);

            //   Copy the cell order information from info into z_order.
            for (uint ic = 0; ic < ncells; ++ic)
            {   z_order[ic] = info[ic]; }
            free(info);

            //   Order the mesh according to the calculated order (note that z_order is for both curves).
            vector<int> int_local(ncells);

            mesh_memory.set_memory_attribute(nlft, 0x100);
            mesh_memory.set_memory_attribute(nrht, 0x100);
            mesh_memory.set_memory_attribute(nbot, 0x100);
            mesh_memory.set_memory_attribute(ntop, 0x100);

            mesh_memory.memory_reorder_all(&z_order[0]);
            memory_reset_ptrs();

            if (x.size() >= ncells) {
               vector<spatial_t> real_local(ncells);

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = x[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  x[ic] = real_local[z_order[ic]];
               }

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = dx[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  dx[ic] = real_local[z_order[ic]];
               }
           
               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = y[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  y[ic] = real_local[z_order[ic]];
               }

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = dy[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  dy[ic] = real_local[z_order[ic]];
               }
            }

         }

         break;

      case ZORDER:
         //  Resort the curve by z-order.
         if (parallel) {
#ifdef HAVE_MPI
            vector<int>i_global(ncells_global);
            vector<int>j_global(ncells_global);
            vector<int>level_global(ncells_global);
            vector<int>z_index_global(ncells_global);
            vector<int>z_order_global(ncells_global);
            MPI_Allgatherv(&i[0], ncells, MPI_REAL, &i_global[0], &nsizes[0], &ndispl[0], MPI_REAL, MPI_COMM_WORLD);
            MPI_Allgatherv(&j[0], ncells, MPI_REAL, &j_global[0], &nsizes[0], &ndispl[0], MPI_REAL, MPI_COMM_WORLD);
            MPI_Allgatherv(&level[0], ncells, MPI_REAL, &level_global[0], &nsizes[0], &ndispl[0], MPI_REAL, MPI_COMM_WORLD);

            i_scaled.resize(ncells_global);
            j_scaled.resize(ncells_global);

            //
            imax = 0;
            jmax = 0;
            for (uint ic = 0; ic < ncells_global; ++ic)
            {   if (i_global[ic] > imax) imax = i_global[ic];
               if (j_global[ic] > jmax) jmax = j_global[ic]; }

            //
            iscale = 16.0 / (double)imax;
            jscale = 16.0 / (double)jmax;

            //
            for (uint ic = 0; ic < ncells_global; ++ic)
            {   i_scaled[ic]=(int) ( (double)i_global[ic]*iscale);
               j_scaled[ic]=(int) ( (double)j_global[ic]*jscale); }

            //
            calc_zorder(ncells_global, &i_scaled[0], &j_scaled[0], &level_global[0], levmx, ibase, &z_index_global[0], &z_order_global[0]);

            //   Order the mesh according to the calculated order (note that z_order is for both curves).
            vector<int> int_global(ncells_global);
            vector<int> int_global_new(ncells_global);

            // gather, reorder and scatter i
            MPI_Allgatherv(&i[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &i[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // gather, reorder and scatter j
            MPI_Allgatherv(&j[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &j[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // gather, reorder and scatter level
            MPI_Allgatherv(&level[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
            for (int ic = 0; ic<(int)ncells_global; ic++){
               int_global_new[ic] = int_global[z_order_global[ic]];
            }
            MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &level[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

            // It is faster just to recalculate these variables instead of communicating them
            if (mesh_memory.get_memory_size(celltype) >= ncells) {
               calc_celltype(mesh_memory.get_memory_size(celltype));
            }

            if (x.size() >= ncells) {
               calc_spatial_coordinates(0);
            }

            if (mesh_memory.get_memory_size(nlft) >= ncells) {
               vector<int> inv_z_order(ncells_global);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  inv_z_order[z_order_global[ic]] = ic;
               }

               MPI_Allgatherv(&nlft[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nlft[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&nrht[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nrht[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&nbot[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &nbot[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);

               MPI_Allgatherv(&ntop[0], ncells, MPI_INT, &int_global[0], &nsizes[0], &ndispl[0], MPI_INT, MPI_COMM_WORLD);
               for (int ic = 0; ic<(int)ncells_global; ic++){
                  int_global_new[ic] = inv_z_order[int_global[z_order_global[ic]]];
               }
               MPI_Scatterv(&int_global_new[0], &nsizes[0], &ndispl[0], MPI_INT, &ntop[0], ncells, MPI_INT, 0, MPI_COMM_WORLD);
            }
            MPI_Scatterv(&z_order_global[0], &nsizes[0], &ndispl[0], MPI_REAL, &z_order[0], ncells, MPI_REAL, 0, MPI_COMM_WORLD);
#endif
         } else {
            i_scaled.resize(ncells);
            j_scaled.resize(ncells);

            //
            imax = 0;
            jmax = 0;
            for (uint ic = 0; ic < ncells; ++ic)
            {   if (i[ic] > imax) imax = i[ic];
               if (j[ic] > jmax) jmax = j[ic]; }

            //
            iscale = 16.0 / (double)imax;
            jscale = 16.0 / (double)jmax;

            //
            for (uint ic = 0; ic < ncells; ++ic)
            {   i_scaled[ic]=(int) ( (double)i[ic]*iscale);
               j_scaled[ic]=(int) ( (double)j[ic]*jscale); }

            //
            calc_zorder(ncells, &i_scaled[0], &j_scaled[0], &level[0], levmx, ibase, &z_index[0], &z_order[0]);

            //   Order the mesh according to the calculated order (note that z_order is for both curves).
            vector<int> int_local(ncells);

            mesh_memory.set_memory_attribute(nlft, 0x100);
            mesh_memory.set_memory_attribute(nrht, 0x100);
            mesh_memory.set_memory_attribute(nbot, 0x100);
            mesh_memory.set_memory_attribute(ntop, 0x100);

            mesh_memory.memory_reorder_all(&z_order[0]);
            memory_reset_ptrs();


            if (x.size() >= ncells) {
               vector<spatial_t> real_local(ncells);

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = x[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  x[ic] = real_local[z_order[ic]];
               }

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = dx[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  dx[ic] = real_local[z_order[ic]];
               }
           
               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = y[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  y[ic] = real_local[z_order[ic]];
               }

               for (int ic = 0; ic<(int)ncells; ic++){
                  real_local[ic] = dy[ic];
               }
               for (int ic = 0; ic<(int)ncells; ic++){
                  dy[ic] = real_local[z_order[ic]];
               }
            }

         }

         break;

      default:
         //  Note that HILBERT_PARTITION is not currently supported due to redundancy with HILBERT_SORT.
         break;
   }
   
   
   //   Output ordered mesh information.
   if (DEBUG)
   {   printf("orig index   i     j     lev    nlft nrht nbot ntop   xlow    xhigh     ylow    yhigh   z index  z order\n");
      for (uint ic=0; ic<ncells; ic++){
         printf(" %6d   %4d  %4d   %4d  %4d %4d %4d %4d ", index[ic], j[ic], i[ic], level[ic], nlft[ic], nrht[ic], nbot[ic], ntop[ic]);
         printf(" %8.2lf %8.2lf %8.2lf %8.2lf", x[ic], x[ic]+dx[ic], y[ic], y[ic]+dy[ic]);
         printf(" %6d    %5d\n", z_index[ic], z_order[ic]); } }

   cpu_timers[MESH_TIMER_PARTITION] += cpu_timer_stop(tstart_cpu);
}

//   The distribution needs to be modified in order to spread out extra cells equitably among the work items.
void Mesh::calc_distribution(int numpe)
{  
   uint lsize = 0;     //
   for (int ip = 0; ip < numpe; ++ip) {
      lsize += proc.size()/numpe;
      if (ip < (int)proc.size()%numpe) lsize++;
      for (int ic = 0; ic < (int)lsize; ic++) {
         proc[ic] = ip;
      }
   }
}

