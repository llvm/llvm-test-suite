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

#include <stdio.h>
#include <math.h>

#include "block.h"
#include "proto.h"
#include "timer.h"

// Profiling output.
void profile(void)
{
   int i;
   double total_gflops, gflops_rank, total_fp_ops, total_fp_adds,
          total_fp_divs;
   object *op;
   char *version = "1.0 provisional";
   FILE *fp;

   calculate_results();
   total_fp_divs = ((double) total_blocks)*((double) x_block_size)*
                   ((double) y_block_size)*((double) z_block_size);
   if (stencil == 7)
      total_fp_adds = 6*total_fp_divs;
   else
      total_fp_adds = 26*total_fp_divs;
   total_fp_ops = total_fp_divs + total_fp_adds;
   total_gflops = total_fp_ops/(average[38]*1024.0*1024.0*1024.0);
   gflops_rank = total_gflops/((double) num_pes);

   if (!my_pe) {
      if (report_perf & 1) {
         fp = fopen("results.yaml", "w");
         fprintf(fp, "code: miniAMR\n");
         fprintf(fp, "version: %s\n", version);
         fprintf(fp, "ranks: %d\n", num_pes);
         fprintf(fp, "init_block_x: %d\n", init_block_x);
         fprintf(fp, "init_block_y: %d\n", init_block_y);
         fprintf(fp, "init_block_z: %d\n", init_block_z);
         fprintf(fp, "x_block_size: %d\n", x_block_size);
         fprintf(fp, "y_block_size: %d\n", y_block_size);
         fprintf(fp, "z_block_size: %d\n", z_block_size);
         fprintf(fp, "permute: %d\n", permute);
         fprintf(fp, "max_blocks_allowed: %d\n", max_num_blocks);
         fprintf(fp, "code: %d\n", code);
         fprintf(fp, "num_refine: %d\n", num_refine);
         fprintf(fp, "block_change: %d\n", block_change);
         fprintf(fp, "refine_ghost: %d\n", refine_ghost);
         fprintf(fp, "uniform_refine: %d\n", uniform_refine);
         fprintf(fp, "num_objects: %d\n", num_objects);
         for (i = 0; i < num_objects; i++) {
            op = &objects[i];
            fprintf(fp, "obj%dtype: %d\n", i, op->type);
            fprintf(fp, "obj%dbounce: %d\n", i, op->bounce);
            fprintf(fp, "obj%dcenter_x: %lf\n", i, op->cen[0]);
            fprintf(fp, "obj%dcenter_y: %lf\n", i, op->cen[1]);
            fprintf(fp, "obj%dcenter_z: %lf\n", i, op->cen[2]);
            fprintf(fp, "obj%dmove_x: %lf\n", i, op->move[0]);
            fprintf(fp, "obj%dmove_y: %lf\n", i, op->move[1]);
            fprintf(fp, "obj%dmove_z: %lf\n", i, op->move[2]);
            fprintf(fp, "obj%dsize_x: %lf\n", i, op->size[0]);
            fprintf(fp, "obj%dsize_y: %lf\n", i, op->size[1]);
            fprintf(fp, "obj%dsize_z: %lf\n", i, op->size[2]);
            fprintf(fp, "obj%dinc_x: %lf\n", i, op->inc[0]);
            fprintf(fp, "obj%dinc_y: %lf\n", i, op->inc[1]);
            fprintf(fp, "obj%dinc_z: %lf\n", i, op->inc[2]);
         }
         fprintf(fp, "num_tsteps: %d\n", num_tsteps);
         fprintf(fp, "stages_per_timestep: %d\n", stages_per_ts);
         fprintf(fp, "checksum_freq: %d\n", checksum_freq);
         fprintf(fp, "refine_freq: %d\n", refine_freq);
         fprintf(fp, "plot_freq: %d\n", plot_freq);
         fprintf(fp, "num_vars: %d\n", num_vars);
         fprintf(fp, "stencil: %d\n", stencil);
         fprintf(fp, "comm_vars: %d\n", comm_vars);
         fprintf(fp, "error_tol: %d\n", error_tol);

         fprintf(fp, "total_time: %lf\n", average[0]);
         fprintf(fp, "memory_used: %lf\n", average[111]);
         fprintf(fp, "compute_time: %lf\n", average[38]);
         fprintf(fp, "total_gflops: %lf\n", total_gflops);
         fprintf(fp, "ave_gflops: %lf\n", gflops_rank);

         fprintf(fp, "total_comm: %lf\n", average[37]);
         fprintf(fp, "   total_exch_same: %lf\n", average[5]);
         fprintf(fp, "   total_exch_diff: %lf\n", average[6]);
         fprintf(fp, "   total_apply_bc: %lf\n", average[7]);
         fprintf(fp, "   total_face_exch_same: %lf\n", average[75]);
         fprintf(fp, "   total_face_exch_diff: %lf\n", average[76]);
         fprintf(fp, "   total_face_bc_apply: %lf\n", average[74]);

         fprintf(fp, "   x_comm: %lf\n", average[10]);
         fprintf(fp, "      x_exch_same: %lf\n", average[14]);
         fprintf(fp, "      x_exch_diff: %lf\n", average[15]);
         fprintf(fp, "      x_apply_bc: %lf\n", average[16]);
         fprintf(fp, "      x_face_exch_same: %lf\n", average[84]);
         fprintf(fp, "      x_face_exch_diff: %lf\n", average[85]);
         fprintf(fp, "      x_face_bc_apply: %lf\n", average[83]);

         fprintf(fp, "   y_comm: %lf\n", average[19]);
         fprintf(fp, "      y_exch_same: %lf\n", average[23]);
         fprintf(fp, "      y_exch_diff: %lf\n", average[24]);
         fprintf(fp, "      y_apply_bc: %lf\n", average[25]);
         fprintf(fp, "      y_face_exch_same: %lf\n", average[93]);
         fprintf(fp, "      y_face_exch_diff: %lf\n", average[94]);
         fprintf(fp, "      y_face_bc_apply: %lf\n", average[92]);

         fprintf(fp, "   z_comm: %lf\n", average[28]);
         fprintf(fp, "      z_exch_same: %lf\n", average[32]);
         fprintf(fp, "      z_exch_diff: %lf\n", average[33]);
         fprintf(fp, "      z_apply_bc: %lf\n", average[34]);
         fprintf(fp, "      z_face_exch_same: %lf\n", average[102]);
         fprintf(fp, "      z_face_exch_diff: %lf\n", average[103]);
         fprintf(fp, "      z_face_bc_apply: %lf\n", average[101]);

         fprintf(fp, "gridsum_time: %lf\n", average[39]);
         fprintf(fp, "   gridsum_calc: %lf\n", average[41]);

         fprintf(fp, "refine_time: %lf\n", average[42]);
         fprintf(fp, "   total_blocks_ts: %lf\n",
                ((double) total_blocks)/((double) (num_tsteps*stages_per_ts)));
         fprintf(fp, "   total_blocks_ts_min: %d\n", nb_min);
         fprintf(fp, "   total_blocks_ts_max: %d\n", nb_max);
         fprintf(fp, "   blocks_split: %lf\n", average[104]);
         fprintf(fp, "   blocks_reformed: %lf\n", average[105]);
         fprintf(fp, "   time_compare_obj: %lf\n", average[43]);
         fprintf(fp, "   time_mark_refine: %lf\n", average[44]);
         fprintf(fp, "   time_split_block: %lf\n", average[46]);
         fprintf(fp, "   time_total_coarsen: %lf\n", average[47]);
         fprintf(fp, "   time_misc: %lf\n", average[45]);

         fprintf(fp, "plot_time: %lf\n", average[67]);

         fclose(fp);
      }

      if (report_perf & 2) {
         fp = fopen("results.txt", "w");

         fprintf(fp, "\n ================ Start report ===================\n\n");
         fprintf(fp, "          Mantevo miniAMR\n");
         fprintf(fp, "          version %s\n\n", version);

         fprintf(fp, "serial run on 1 rank\n");
         fprintf(fp, "initial blocks per rank %d x %d x %d\n", init_block_x,
                init_block_y, init_block_z);
         fprintf(fp, "block size %d x %d x %d\n", x_block_size, y_block_size,
                z_block_size);
         if (permute)
            fprintf(fp, "Order of exchanges permuted\n");
         fprintf(fp, "Maximum number of blocks per rank is %d\n",
                 max_num_blocks);
         if (target_active)
            fprintf(fp, "Target number of blocks per rank is %d\n",
                    target_active);
         if (target_max)
            fprintf(fp, "Target max number of blocks per rank is %d\n",
                    target_max);
         if (target_min)
            fprintf(fp, "Target min number of blocks per rank is %d\n",
                    target_min);
         if (code)
            fprintf(fp, "Code set to code %d\n", code);
         fprintf(fp, "Number of levels of refinement is %d\n", num_refine);
         fprintf(fp, "Blocks can change by %d levels per refinement step\n",
            block_change);
         if (refine_ghost)
            fprintf(fp, "Ghost cells will be used determine is block is refined\n");
         if (uniform_refine)
            fprintf(fp, "\nBlocks will be uniformly refined\n");
         else {
            fprintf(fp, "\nBlocks will be refined by %d objects\n\n", num_objects);
            for (i = 0; i < num_objects; i++) {
               op = &objects[i];
               if (op->type == 0)
                  fprintf(fp, "Object %d is the surface of a rectangle\n", i);
               else if (op->type == 1)
                  fprintf(fp, "Object %d is the volume of a rectangle\n", i);
               else if (op->type == 2)
                  fprintf(fp, "Object %d is the surface of a spheroid\n", i);
               else if (op->type == 3)
                  fprintf(fp, "Object %d is the volume of a spheroid\n", i);
               else if (op->type == 4)
                  fprintf(fp, "Object %d is the surface of x+ hemispheroid\n", i);
               else if (op->type == 5)
                  fprintf(fp, "Object %d is the volume of x+ hemispheroid\n", i);
               else if (op->type == 6)
                  fprintf(fp, "Object %d is the surface of x- hemispheroid\n", i);
               else if (op->type == 7)
                  fprintf(fp, "Object %d is the volume of x- hemispheroid\n", i);
               else if (op->type == 8)
                  fprintf(fp, "Object %d is the surface of y+ hemispheroid\n", i);
               else if (op->type == 9)
                  fprintf(fp, "Object %d is the volume of y+ hemispheroid\n", i);
               else if (op->type == 10)
                  fprintf(fp, "Object %d is the surface of y- hemispheroid\n", i);
               else if (op->type == 11)
                  fprintf(fp, "Object %d is the volume of y- hemispheroid\n", i);
               else if (op->type == 12)
                  fprintf(fp, "Object %d is the surface of z+ hemispheroid\n", i);
               else if (op->type == 13)
                  fprintf(fp, "Object %d is the volume of z+ hemispheroid\n", i);
               else if (op->type == 14)
                  fprintf(fp, "Object %d is the surface of z- hemispheroid\n", i);
               else if (op->type == 15)
                  fprintf(fp, "Object %d is the volume of z- hemispheroid\n", i);
               else if (op->type == 20)
                  fprintf(fp, "Object %d is the surface of x axis cylinder\n", i);
               else if (op->type == 21)
                  fprintf(fp, "Object %d is the volune of x axis cylinder\n", i);
               else if (op->type == 22)
                  fprintf(fp, "Object %d is the surface of y axis cylinder\n", i);
               else if (op->type == 23)
                  fprintf(fp, "Object %d is the volune of y axis cylinder\n", i);
               else if (op->type == 24)
                  fprintf(fp, "Object %d is the surface of z axis cylinder\n", i);
               else if (op->type == 25)
                  fprintf(fp, "Object %d is the volune of z axis cylinder\n", i);
               if (op->bounce == 0)
                  fprintf(fp, "Oject may leave mesh\n");
               else
                  fprintf(fp, "Oject center will bounce off of walls\n");
               fprintf(fp, "Center starting at %lf %lf %lf\n",
                      op->orig_cen[0], op->orig_cen[1], op->orig_cen[2]);
               fprintf(fp, "Center end at %lf %lf %lf\n",
                      op->cen[0], op->cen[1], op->cen[2]);
               fprintf(fp, "Moving at %lf %lf %lf per timestep\n",
                      op->orig_move[0], op->orig_move[1], op->orig_move[2]);
               fprintf(fp, "   Rate relative to smallest cell size %lf %lf %lf\n",
                      op->orig_move[0]*((double) (mesh_size[0]*x_block_size)),
                      op->orig_move[1]*((double) (mesh_size[1]*y_block_size)),
                      op->orig_move[2]*((double) (mesh_size[2]*z_block_size)));
               fprintf(fp, "Initial size %lf %lf %lf\n",
                      op->orig_size[0], op->orig_size[1], op->orig_size[2]);
               fprintf(fp, "Final size %lf %lf %lf\n",
                      op->size[0], op->size[1], op->size[2]);
               fprintf(fp, "Size increasing %lf %lf %lf per timestep\n",
                      op->inc[0], op->inc[1], op->inc[2]);
               fprintf(fp, "   Rate relative to smallest cell size %lf %lf %lf\n\n",
                      op->inc[0]*((double) (mesh_size[0]*x_block_size)),
                      op->inc[1]*((double) (mesh_size[1]*y_block_size)),
                      op->inc[2]*((double) (mesh_size[2]*z_block_size)));
            }
         }
         fprintf(fp, "\nNumber of timesteps is %d\n", num_tsteps);
         fprintf(fp, "Communicaion/computation stages per timestep is %d\n",
                stages_per_ts);
         fprintf(fp, "Will perform checksums every %d stages\n", checksum_freq);
         fprintf(fp, "Will refine every %d timesteps\n", refine_freq);
         if (plot_freq)
            fprintf(fp, "Will plot results every %d timesteps\n", plot_freq);
         else
            fprintf(fp, "Will not plot results\n");
         fprintf(fp, "Calculate on %d variables with %d point stencil\n",
                num_vars, stencil);
         fprintf(fp, "Communicate %d variables at a time\n", comm_vars);
         fprintf(fp, "Error tolorance for variable sums is 10^(-%d)\n", error_tol);

         fprintf(fp, "\nTotal time for test: (sec): %lf\n\n", average[0]);

         fprintf(fp, "\nNumber of malloc calls: %lf\n", average[110]);
         fprintf(fp, "\nAmount malloced: %lf\n", average[111]);

         fprintf(fp, "---------------------------------------------\n");
         fprintf(fp, "          Computational Performance\n");
         fprintf(fp, "---------------------------------------------\n\n");
         fprintf(fp, "     Time: ave, stddev, min, max (sec): %lf\n\n",
                average[38]);
         fprintf(fp, "     total GFLOPS:             %lf\n", total_gflops);
         fprintf(fp, "     Average GFLOPS per rank:  %lf\n\n", gflops_rank);
         fprintf(fp, "     Total floating point ops: %lf\n\n", total_fp_ops);
         fprintf(fp, "        Adds:                  %lf\n", total_fp_adds);
         fprintf(fp, "        Divides:               %lf\n\n", total_fp_divs);

         fprintf(fp, "---------------------------------------------\n");
         fprintf(fp, "           Interblock communication\n");
         fprintf(fp, "---------------------------------------------\n\n");
         fprintf(fp, "     Time: ave, stddev, min, max (sec): %lf\n\n",
                average[37]);
         for (i = 0; i < 4; i++) {
            if (i == 0)
               fprintf(fp, "\nTotal communication:\n\n");
            else if (i == 1)
               fprintf(fp, "\nX direction communication statistics:\n\n");
            else if (i == 2)
               fprintf(fp, "\nY direction communication statistics:\n\n");
            else
               fprintf(fp, "\nZ direction communication statistics:\n\n");
            fprintf(fp, "                              average    stddev  minimum  maximum\n");
            fprintf(fp, "     Total time             : %lf\n", average[1+9*i]);
            fprintf(fp, "     Exchange same level    : %lf\n", average[5+9*i]);
            fprintf(fp, "     Exchange diff level    : %lf\n", average[6+9*i]);
            fprintf(fp, "     Apply BC               : %lf\n", average[7+9*i]);

            fprintf(fp, "     Faces exchanged same   : %lf\n", average[75+9*i]);
            fprintf(fp, "     Faces exchanged diff   : %lf\n", average[76+9*i]);
            fprintf(fp, "     Faces with BC applied  : %lf\n", average[74+9*i]);
         }

         fprintf(fp, "\n---------------------------------------------\n");
         fprintf(fp, "             Gridsum performance\n");
         fprintf(fp, "---------------------------------------------\n\n");
         fprintf(fp, "     Time: ave, stddev, min, max (sec): %lf\n\n",
                average[39]);
         fprintf(fp, "        calc: ave, stddev, min, max (sec): %lf\n\n",
                average[41]);
         fprintf(fp, "     total number:             %d\n", total_red);
         fprintf(fp, "     number per timestep:      %d\n\n", num_vars);

         fprintf(fp, "---------------------------------------------\n");
         fprintf(fp, "               Mesh Refinement\n");
         fprintf(fp, "---------------------------------------------\n\n");
         fprintf(fp, "     Time: ave, stddev, min, max (sec): %lf\n\n",
                average[42]);
         fprintf(fp, "     Number of refinement steps: %d\n\n", nrs);
         fprintf(fp, "     Total blocks           : %ld\n", total_blocks);
         fprintf(fp, "     Blocks/timestep ave, min, max : %lf %d %d\n",
                ((double) total_blocks)/((double) (num_tsteps*stages_per_ts)),
                nb_min, nb_max);
         fprintf(fp, "     Max blocks on a processor at any time: %d\n",
                global_max_b);
         fprintf(fp, "     total blocks split     : %lf\n", average[104]);
         fprintf(fp, "     total blocks reformed  : %lf\n\n", average[105]);

         fprintf(fp, "     Time:\n");
         fprintf(fp, "        compare objects     : %lf\n", average[43]);
         fprintf(fp, "        mark refine/coarsen : %lf\n", average[44]);
         fprintf(fp, "        split blocks        : %lf\n", average[46]);
         fprintf(fp, "        total coarsen blocks: %lf\n", average[47]);
         fprintf(fp, "        misc time           : %lf\n", average[45]);
         if (target_active) {
            fprintf(fp, "        total target active : %lf\n", average[52]);
            fprintf(fp, "          reduce blocks     : %lf\n", average[53]);
            fprintf(fp, "            decide and comm : %lf\n", average[54]);
            fprintf(fp, "            coarsen blocks  : %lf\n", average[58]);
            fprintf(fp, "          add blocks        : %lf\n", average[59]);
            fprintf(fp, "            decide and comm : %lf\n", average[60]);
            fprintf(fp, "            split blocks    : %lf\n", average[61]);
         }

         fprintf(fp, "---------------------------------------------\n");
         fprintf(fp, "                   Plot\n");
         fprintf(fp, "---------------------------------------------\n\n");
         fprintf(fp, "     Time: ave, stddev, min, max (sec): %lf\n\n",
                average[67]);
         fprintf(fp, "     Number of plot steps: %d\n", nps);
         fprintf(fp, "\n ================== End report ===================\n");

         fclose(fp);
      }

      if (report_perf & 4) {
         printf("\n ================ Start report ===================\n\n");
         printf("          Mantevo miniAMR\n");
         printf("          version %s\n\n", version);

         printf("serial run on 1 rank\n");
         printf("initial blocks per rank %d x %d x %d\n", init_block_x,
                init_block_y, init_block_z);
         printf("block size %d x %d x %d\n", x_block_size, y_block_size,
                z_block_size);
         if (permute)
            printf("Order of exchanges permuted\n");
         printf("Maximum number of blocks per rank is %d\n", max_num_blocks);
         if (target_active)
            printf("Target number of blocks per rank is %d\n", target_active);
         if (target_max)
            printf("Target max number of blocks per rank is %d\n", target_max);
         if (target_min)
            printf("Target min number of blocks per rank is %d\n", target_min);
         if (code)
            printf("Code set to code %d\n", code);
         printf("Number of levels of refinement is %d\n", num_refine);
         printf("Blocks can change by %d levels per refinement step\n",
            block_change);
         if (refine_ghost)
            printf("Ghost cells will be used determine is block is refined\n");
         if (uniform_refine)
            printf("\nBlocks will be uniformly refined\n");
         else {
            printf("\nBlocks will be refined by %d objects\n\n", num_objects);
            for (i = 0; i < num_objects; i++) {
               op = &objects[i];
               if (op->type == 0)
                  printf("Object %d is the surface of a rectangle\n", i);
               else if (op->type == 1)
                  printf("Object %d is the volume of a rectangle\n", i);
               else if (op->type == 2)
                  printf("Object %d is the surface of a spheroid\n", i);
               else if (op->type == 3)
                  printf("Object %d is the volume of a spheroid\n", i);
               else if (op->type == 4)
                  printf("Object %d is the surface of x+ hemispheroid\n", i);
               else if (op->type == 5)
                  printf("Object %d is the volume of x+ hemispheroid\n", i);
               else if (op->type == 6)
                  printf("Object %d is the surface of x- hemispheroid\n", i);
               else if (op->type == 7)
                  printf("Object %d is the volume of x- hemispheroid\n", i);
               else if (op->type == 8)
                  printf("Object %d is the surface of y+ hemispheroid\n", i);
               else if (op->type == 9)
                  printf("Object %d is the volume of y+ hemispheroid\n", i);
               else if (op->type == 10)
                  printf("Object %d is the surface of y- hemispheroid\n", i);
               else if (op->type == 11)
                  printf("Object %d is the volume of y- hemispheroid\n", i);
               else if (op->type == 12)
                  printf("Object %d is the surface of z+ hemispheroid\n", i);
               else if (op->type == 13)
                  printf("Object %d is the volume of z+ hemispheroid\n", i);
               else if (op->type == 14)
                  printf("Object %d is the surface of z- hemispheroid\n", i);
               else if (op->type == 15)
                  printf("Object %d is the volume of z- hemispheroid\n", i);
               else if (op->type == 20)
                  printf("Object %d is the surface of x axis cylinder\n", i);
               else if (op->type == 21)
                  printf("Object %d is the volune of x axis cylinder\n", i);
               else if (op->type == 22)
                  printf("Object %d is the surface of y axis cylinder\n", i);
               else if (op->type == 23)
                  printf("Object %d is the volune of y axis cylinder\n", i);
               else if (op->type == 24)
                  printf("Object %d is the surface of z axis cylinder\n", i);
               else if (op->type == 25)
                  printf("Object %d is the volune of z axis cylinder\n", i);
               if (op->bounce == 0)
                  printf("Oject may leave mesh\n");
               else
                  printf("Oject center will bounce off of walls\n");
               printf("Center starting at %lf %lf %lf\n",
                      op->orig_cen[0], op->orig_cen[1], op->orig_cen[2]);
               printf("Center end at %lf %lf %lf\n",
                      op->cen[0], op->cen[1], op->cen[2]);
               printf("Moving at %lf %lf %lf per timestep\n",
                      op->orig_move[0], op->orig_move[1], op->orig_move[2]);
               printf("   Rate relative to smallest cell size %lf %lf %lf\n",
                      op->orig_move[0]*((double) (mesh_size[0]*x_block_size)),
                      op->orig_move[1]*((double) (mesh_size[1]*y_block_size)),
                      op->orig_move[2]*((double) (mesh_size[2]*z_block_size)));
               printf("Initial size %lf %lf %lf\n",
                      op->orig_size[0], op->orig_size[1], op->orig_size[2]);
               printf("Final size %lf %lf %lf\n",
                      op->size[0], op->size[1], op->size[2]);
               printf("Size increasing %lf %lf %lf per timestep\n",
                      op->inc[0], op->inc[1], op->inc[2]);
               printf("   Rate relative to smallest cell size %lf %lf %lf\n\n",
                      op->inc[0]*((double) (mesh_size[0]*x_block_size)),
                      op->inc[1]*((double) (mesh_size[1]*y_block_size)),
                      op->inc[2]*((double) (mesh_size[2]*z_block_size)));
            }
         }
         printf("\nNumber of timesteps is %d\n", num_tsteps);
         printf("Communicaion/computation stages per timestep is %d\n",
                stages_per_ts);
         printf("Will perform checksums every %d stages\n", checksum_freq);
         printf("Will refine every %d timesteps\n", refine_freq);
         if (plot_freq)
            printf("Will plot results every %d timesteps\n", plot_freq);
         else
            printf("Will not plot results\n");
         printf("Calculate on %d variables with %d point stencil\n",
                num_vars, stencil);
         printf("Communicate %d variables at a time\n", comm_vars);
         printf("Error tolorance for variable sums is 10^(-%d)\n", error_tol);
/*
         printf("\nTotal time for test (sec): %lf\n\n", average[0]);

         printf("\nNumber of malloc calls: %lf\n", average[110]);
         printf("\nAmount malloced: %lf\n", average[111]);

         printf("---------------------------------------------\n");
         printf("          Computational Performance\n");
         printf("---------------------------------------------\n\n");
         printf("     Time: ave, stddev, min, max (sec): %lf\n\n", average[38]);
         printf("     total GFLOPS:             %lf\n", total_gflops);
         printf("     Average GFLOPS per rank:  %lf\n\n", gflops_rank);
         printf("     Total floating point ops: %lf\n\n", total_fp_ops);
         printf("        Adds:                  %lf\n", total_fp_adds);
         printf("        Divides:               %lf\n\n", total_fp_divs);

         printf("---------------------------------------------\n");
         printf("           Interblock communication\n");
         printf("---------------------------------------------\n\n");
         printf("     Time: ave, stddev, min, max (sec): %lf\n\n", average[37]);
         for (i = 0; i < 4; i++) {
            if (i == 0)
               printf("\nTotal communication:\n\n");
            else if (i == 1)
               printf("\nX direction communication statistics:\n\n");
            else if (i == 2)
               printf("\nY direction communication statistics:\n\n");
            else
               printf("\nZ direction communication statistics:\n\n");
            printf("     Total time             : %lf\n", average[1+9*i]);
            printf("     Exchange same level    : %lf\n", average[5+9*i]);
            printf("     Exchange diff level    : %lf\n", average[6+9*i]);
            printf("     Apply BC               : %lf\n", average[7+9*i]);

            printf("     Faces exchanged same   : %lf\n", average[75+9*i]);
            printf("     Faces exchanged diff   : %lf\n", average[76+9*i]);
            printf("     Faces with BC applied  : %lf\n", average[74+9*i]);
         }

         printf("\n---------------------------------------------\n");
         printf("             Gridsum performance\n");
         printf("---------------------------------------------\n\n");
         printf("     Time: ave, stddev, min, max (sec): %lf\n\n", average[39]);
         printf("        calc: ave, stddev, min, max (sec): %lf\n\n",
                average[41]);
         printf("     total number:             %d\n", total_red);
         printf("     number per timestep:      %d\n\n", num_vars);

         printf("---------------------------------------------\n");
         printf("               Mesh Refinement\n");
         printf("---------------------------------------------\n\n");
         printf("     Time: ave, stddev, min, max (sec): %lf\n\n", average[42]);
         printf("     Number of refinement steps: %d\n\n", nrs);
         printf("     Total blocks           : %ld\n", total_blocks);
         printf("     Blocks/timestep ave, min, max : %lf %d %d\n",
                ((double) total_blocks)/((double) (num_tsteps*stages_per_ts)),
                nb_min, nb_max);
         printf("     Max blocks on a processor at any time: %d\n",
                global_max_b);
         printf("     total blocks split     : %lf\n", average[104]);
         printf("     total blocks reformed  : %lf\n\n", average[105]);

         printf("     Time:\n");
         printf("        compare objects     : %lf\n", average[43]);
         printf("        mark refine/coarsen : %lf\n", average[44]);
         printf("        split blocks        : %lf\n", average[46]);
         printf("        total coarsen blocks: %lf\n", average[47]);
         printf("        misc time           : %lf\n", average[45]);
         if (target_active) {
            printf("        total target active : %lf\n", average[52]);
            printf("          reduce blocks     : %lf\n", average[53]);
            printf("            decide and comm : %lf\n", average[54]);
            printf("            coarsen blocks  : %lf\n", average[58]);
            printf("          add blocks        : %lf\n", average[59]);
            printf("            decide and comm : %lf\n", average[60]);
            printf("            split blocks    : %lf\n", average[61]);
         }

         printf("---------------------------------------------\n");
         printf("                   Plot\n");
         printf("---------------------------------------------\n\n");
         printf("     Time: ave, stddev, min, max (sec): %lf\n\n", average[67]);
         printf("     Number of plot steps: %d\n", nps);
         printf("\n ================== End report ===================\n");
*/
      }
   }
}

void calculate_results(void)
{
   double results[128];
   int i;

   results[0] = timer_all;
   for (i = 0; i < 9; i++)
      results[i+1] = 0.0;
   for (i = 0; i < 3; i++) {
      results[1] += results[10+9*i] = timer_comm_dir[i];
      results[5] += results[14+9*i] = timer_comm_same[i];
      results[6] += results[15+9*i] = timer_comm_diff[i];
      results[7] += results[16+9*i] = timer_comm_bc[i];
   }
   results[37] = timer_comm_all;
   results[38] = timer_calc_all;
   results[39] = timer_cs_all;
   results[41] = timer_cs_calc;
   results[42] = timer_refine_all;
   results[43] = timer_refine_co;
   results[44] = timer_refine_mr;
   results[45] = timer_refine_cc;
   results[46] = timer_refine_sb;
   results[47] = timer_cb_all;
   results[52] = timer_target_all;
   results[53] = timer_target_rb;
   results[54] = timer_target_dc;
   results[58] = timer_target_cb;
   results[59] = timer_target_ab;
   results[60] = timer_target_da;
   results[61] = timer_target_sb;
   results[67] = timer_plot;
   for (i = 0; i < 9; i++)
      results[68+i] = 0.0;
   for (i = 0; i < 3; i++) {
      results[74] += results[83+9*i] = (double) counter_bc[i];
      results[75] += results[84+9*i] = (double) counter_same[i];
      results[76] += results[85+9*i] = (double) counter_diff[i];
   }
   results[104] = (double) num_refined;
   results[105] = (double) num_reformed;
   results[110] = (double) counter_malloc;
   results[111] = size_malloc;
   results[112] = (double) counter_malloc_init;
   results[113] = size_malloc_init;
   results[114] = (double) (counter_malloc - counter_malloc_init);
   results[115] = size_malloc - size_malloc_init;

   for (i = 0; i < 128; i++)
      average[i] = results[i];
}

void init_profile(void)
{
   int i;

   timer_all = 0.0;

   timer_comm_all = 0.0;
   for (i = 0; i < 3; i++) {
      timer_comm_dir[i] = 0.0;
      timer_comm_same[i] = 0.0;
      timer_comm_diff[i] = 0.0;
      timer_comm_bc[i] = 0.0;
   }

   timer_calc_all = 0.0;

   timer_cs_all = 0.0;
   timer_cs_calc = 0.0;

   timer_refine_all = 0.0;
   timer_refine_co = 0.0;
   timer_refine_mr = 0.0;
   timer_refine_cc = 0.0;
   timer_refine_sb = 0.0;
   timer_cb_all = 0.0;
   timer_target_all = 0.0;
   timer_target_rb = 0.0;
   timer_target_dc = 0.0;
   timer_target_cb = 0.0;
   timer_target_ab = 0.0;
   timer_target_da = 0.0;
   timer_target_sb = 0.0;

   timer_plot = 0.0;

   total_blocks = 0;
   nrs = 0;
   nps = 0;
   num_refined = 0;
   num_reformed = 0;
   for (i = 0; i < 3; i++) {
      counter_bc[i] = 0;
      counter_same[i] = 0;
      counter_diff[i] = 0;
   }
   total_red = 0;
}
