// ************************************************************************
//
// miniAMR: stencil computations with boundary exchange and AMR.
//
// Copyright (2014) Sandia Corporation. Under the terms of Contract
// DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government 
// retains certain rights in this software.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
// Questions? Contact Courtenay T. Vaughan (ctvaugh@sandia.gov)
//                    Richard F. Barrett (rfbarre@sandia.gov)
//
// ************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "block.h"
#include "timer.h"
#include "proto.h"

int main(int argc, char** argv)
{
   int i, ierr, object_num;
   int params[35];
   double *objs;
#include "param.h"

   my_pe = 0;
   num_pes = 1;

   counter_malloc = 0;
   size_malloc = 0.0;

   /* set initial values */
   for (i = 1; i < argc; i++)
      if (!strcmp(argv[i], "--max_blocks"))
         max_num_blocks = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--target_active"))
         target_active = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--target_max"))
         target_max = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--target_min"))
         target_min = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--num_refine"))
         num_refine = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--block_change"))
         block_change = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--uniform_refine"))
         uniform_refine = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--nx"))
         x_block_size = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--ny"))
         y_block_size = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--nz"))
         z_block_size = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--num_vars"))
         num_vars = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--comm_vars"))
         comm_vars = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--init_x"))
         init_block_x = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--init_y"))
         init_block_y = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--init_z"))
         init_block_z = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--refine_freq"))
         refine_freq = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--report_diffusion"))
         report_diffusion = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--error_tol"))
         error_tol = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--num_tsteps"))
         num_tsteps = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--stages_per_ts"))
         stages_per_ts = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--checksum_freq"))
         checksum_freq = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--stencil"))
         stencil = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--permute"))
         permute = 1;
      else if (!strcmp(argv[i], "--report_perf"))
         report_perf = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--plot_freq"))
         plot_freq = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--code"))
         code = atoi(argv[++i]);
      else if (!strcmp(argv[i], "--refine_ghost"))
         refine_ghost = 1;
      else if (!strcmp(argv[i], "--num_objects")) {
         num_objects = atoi(argv[++i]);
         objects = (object *) ma_malloc(num_objects*sizeof(object),
                                        __FILE__, __LINE__);
         object_num = 0;
      } else if (!strcmp(argv[i], "--object")) {
         if (object_num >= num_objects) {
            printf("object number greater than num_objects\n");
            exit(-1);
         }
         objects[object_num].type = atoi(argv[++i]);
         objects[object_num].bounce = atoi(argv[++i]);
         objects[object_num].cen[0] = atof(argv[++i]);
         objects[object_num].cen[1] = atof(argv[++i]);
         objects[object_num].cen[2] = atof(argv[++i]);
         objects[object_num].move[0] = atof(argv[++i]);
         objects[object_num].move[1] = atof(argv[++i]);
         objects[object_num].move[2] = atof(argv[++i]);
         objects[object_num].size[0] = atof(argv[++i]);
         objects[object_num].size[1] = atof(argv[++i]);
         objects[object_num].size[2] = atof(argv[++i]);
         objects[object_num].inc[0] = atof(argv[++i]);
         objects[object_num].inc[1] = atof(argv[++i]);
         objects[object_num].inc[2] = atof(argv[++i]);
         object_num++;
      } else if (!strcmp(argv[i], "--help")) {
         print_help_message();
         exit(0);
      } else {
         printf("** Error ** Unknown input parameter %s\n", argv[i]);
         print_help_message();
         exit(-1);
      }
   if (check_input())
      exit(-1);

   if (!block_change)
      block_change = num_refine;

   for (object_num = 0; object_num < num_objects; object_num++)
      for (i = 0; i < 3; i++) {
         objects[object_num].orig_cen[i] = objects[object_num].cen[i];
         objects[object_num].orig_move[i] = objects[object_num].move[i];
         objects[object_num].orig_size[i] = objects[object_num].size[i];
      }

   allocate();

   driver();

   profile();

   deallocate();

   exit(0);
}

// =================================== print_help_message ====================

void print_help_message(void)
{
   printf("(Optional) command line input is of the form: \n\n");

   printf("--nx - block size x (even && > 0)\n");
   printf("--ny - block size y (even && > 0)\n");
   printf("--nz - block size z (even && > 0)\n");
   printf("--init_x - initial blocks in x (> 0)\n");
   printf("--init_y - initial blocks in y (> 0)\n");
   printf("--init_z - initial blocks in z (> 0)\n");
   printf("--reorder - ordering of blocks if initial number > 1\n");
   printf("--max_blocks - maximun number of blocks per core\n");
   printf("--num_refine - (>= 0) number of levels of refinement\n");
   printf("--block_change - (>= 0) number of levels a block can change in a timestep\n");
   printf("--uniform_refine - if 1, then grid is uniformly refined\n");
   printf("--refine_freq - frequency (in timesteps) of checking for refinement\n");
   printf("--target_active - (>= 0) target number of blocks per core, none if 0\n");
   printf("--target_max - (>= 0) max number of blocks per core, none if 0\n");
   printf("--target_min - (>= 0) min number of blocks per core, none if 0\n");
   printf("--num_vars - number of variables (> 0)\n");
   printf("--comm_vars - number of vars to communicate together\n");
   printf("--num_tsteps - number of timesteps (> 0)\n");
   printf("--stages_per_ts - number of comm/calc stages per timestep\n");
   printf("--checksum_freq - number of stages between checksums\n");
   printf("--stencil - 7 or 27 point (27 will not work with refinement (except uniform))\n");
   printf("--error_tol - (e^{-error_tol} ; >= 0) \n");
   printf("--report_diffusion - (>= 0) none if 0\n");
   printf("--report_perf - 0, 1, 2\n");
   printf("--refine_freq - frequency (timesteps) of plotting (0 for none)\n");
   printf("--code - closely minic communication of different codes\n");
   printf("         0 minimal sends, 1 send ghosts, 2 send ghosts and process on send\n");
   printf("--permute - altenates directions in communication\n");
   printf("--refine_ghost - use full extent of block (including ghosts) to determine if block is refined\n");
   printf("--num_objects - (>= 0) number of objects to cause refinement\n");
   printf("--object - type, position, movement, size, size rate of change\n");

   printf("All associated settings are integers except for objects\n");
}

// =================================== allocate ==============================

void allocate(void)
{
   int i, j, k, m, n;

   num_blocks = (int *) ma_malloc((num_refine+1)*sizeof(int),
                                  __FILE__, __LINE__);
   num_blocks[0] = num_pes*init_block_x*init_block_y*init_block_z;
   num_blocks[0] = init_block_x*init_block_y*init_block_z;

   blocks = (block *) ma_malloc(max_num_blocks*sizeof(block),
                                __FILE__, __LINE__);

   for (n = 0; n < max_num_blocks; n++) {
      blocks[n].number = -1;
      blocks[n].array = (double ****) ma_malloc(num_vars*sizeof(double ***),
                                                __FILE__, __LINE__);
      for (m = 0; m < num_vars; m++) {
         blocks[n].array[m] = (double ***)
                              ma_malloc((x_block_size+2)*sizeof(double **),
                                        __FILE__, __LINE__);
         for (i = 0; i < x_block_size+2; i++) {
            blocks[n].array[m][i] = (double **)
                                   ma_malloc((y_block_size+2)*sizeof(double *),
                                             __FILE__, __LINE__);
            for (j = 0; j < y_block_size+2; j++)
               blocks[n].array[m][i][j] = (double *)
                                     ma_malloc((z_block_size+2)*sizeof(double),
                                               __FILE__, __LINE__);
         }
      }
   }

   sorted_list = (sorted_block *)ma_malloc(max_num_blocks*sizeof(sorted_block),
                                           __FILE__, __LINE__);
   sorted_index = (int *) ma_malloc((num_refine+2)*sizeof(int),
                                    __FILE__, __LINE__);

   max_num_parents = max_num_blocks;  // Guess at number needed
   parents = (parent *) ma_malloc(max_num_parents*sizeof(parent),
                                  __FILE__, __LINE__);
   for (n = 0; n < max_num_parents; n++)
      parents[n].number = -1;

   grid_sum = (double *)ma_malloc(num_vars*sizeof(double), __FILE__, __LINE__);

   p8 = (int *) ma_malloc((num_refine+2)*sizeof(int), __FILE__, __LINE__);
   p2 = (int *) ma_malloc((num_refine+2)*sizeof(int), __FILE__, __LINE__);
   block_start = (int *) ma_malloc((num_refine+1)*sizeof(int),
                                   __FILE__, __LINE__);
}

// =================================== deallocate ============================

void deallocate(void)
{
   int i, j, m, n;

   for (n = 0; n < max_num_blocks; n++) {
      for (m = 0; m < num_vars; m++) {
         for (i = 0; i < x_block_size+2; i++) {
            for (j = 0; j < y_block_size+2; j++)
               free(blocks[n].array[m][i][j]);
            free(blocks[n].array[m][i]);
         }
         free(blocks[n].array[m]);
      }
      free(blocks[n].array);
   }
   free(blocks);

   free(sorted_list);
   free(sorted_index);

   free(objects);

   free(grid_sum);

   free(p8);
   free(p2);
}

int check_input(void)
{
   int error = 0;

   if (init_block_x < 1 || init_block_y < 1 || init_block_z < 1) {
      printf("initial blocks on processor must be positive\n");
      error = 1;
   }
   if (max_num_blocks < init_block_x*init_block_y*init_block_z) {
      printf("max_num_blocks not large enough\n");
      error = 1;
   }
   if (x_block_size < 1 || y_block_size < 1 || z_block_size < 1) {
      printf("block size must be positive\n");
      error = 1;
   }
   if (((x_block_size/2)*2) != x_block_size) {
      printf("block size in x direction must be even\n");
      error = 1;
   }
   if (((y_block_size/2)*2) != y_block_size) {
      printf("block size in y direction must be even\n");
      error = 1;
   }
   if (((z_block_size/2)*2) != z_block_size) {
      printf("block size in z direction must be even\n");
      error = 1;
   }
   if (target_active && target_max) {
      printf("Only one of target_active and target_max can be used\n");
      error = 1;
   }
   if (target_active && target_min) {
      printf("Only one of target_active and target_min can be used\n");
      error = 1;
   }
   if (target_active < 0 || target_active > max_num_blocks) {
      printf("illegal value for target_active\n");
      error = 1;
   }
   if (target_max < 0 || target_max > max_num_blocks ||
       target_max < target_active) {
      printf("illegal value for target_max\n");
      error = 1;
   }
   if (target_min < 0 || target_min > max_num_blocks ||
       target_min > target_active || target_min > target_max) {
      printf("illegal value for target_min\n");
      error = 1;
   }
   if (num_refine < 0) {
      printf("number of refinement levels must be non-negative\n");
      error = 1;
   }
   if (block_change < 0) {
      printf("number of refinement levels must be non-negative\n");
      error = 1;
   }
   if (num_vars < 1) {
      printf("number of variables must be positive\n");
      error = 1;
   }
   if (num_pes != npx*npy*npz) {
      printf("number of processors used does not match number allocated\n");
      error = 1;
   }
   if (stencil != 7 && stencil != 27) {
      printf("illegal value for stencil\n");
      error = 1;
   }
   if (stencil == 27 && num_refine && !uniform_refine)
      printf("WARNING: 27 point stencil with non-uniform refinement: answers may diverge\n");
   if (comm_vars == 0 || comm_vars > num_vars)
      comm_vars = num_vars;
   if (code < 0 || code > 2) {
      printf("code must be 0, 1, or 2\n");
      error = 1;
   }

   return (error);
}
