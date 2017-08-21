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

#include "block.h"
#include "proto.h"
#include "timer.h"

// This file contains routines that determine which blocks are going to
// be refined and which are going to be coarsened.
void refine(int ts)
{
   int i, j, n, in, min_b, max_b, sum_b, num_refine_step, num_split,
       nm_r, nm_c, nm_t;
   double ratio, t1, t2, t3, t4, t5;
   block *bp;

   t4 = 0.0;
   t1 = timer();

   if (ts)
      num_refine_step = block_change;
   else
      num_refine_step = num_refine;

   for (i = 0; i < num_refine_step; i++) {
      for (j = num_refine; j >= 0; j--)
         if (num_blocks[j]) {
            cur_max_level = j;
            break;
      }
      reset_all();
      if (uniform_refine) {
         for (in = 0; in < sorted_index[num_refine+1]; in++) {
            n = sorted_list[in].n;
            bp = &blocks[n];
            if (bp->number >= 0)
               if (bp->level < num_refine)
                  bp->refine = 1;
               else
                  bp->refine = 0;
         }
      } else {
         t2 = timer();
         check_objects();
         timer_refine_co += timer() - t2;
         t4 += timer() - t2;
      }

      t2 = timer();
      num_split = refine_level();
      t5 = timer();
      timer_refine_mr += t5 - t2;
      t4 += t5 - t2;

      t2 = timer();
      split_blocks();
      t5 = timer();
      timer_refine_sb += t5 - t2;
      t4 += t5 - t2;

      t2 = timer();
      consolidate_blocks();
      t5 = timer();
      timer_cb_all += t5 - t2;
      t4 += t5 - t2;
   }

   if (target_active || target_max || target_min) {
      if (!my_pe) {
         for (j = 0; j <= num_refine; j++)
            printf("Number of blocks at level %d before target %d is %d\n",
                   j, ts, num_blocks[j]);
         printf("\n");
      }
      t2 = timer();
      global_active = num_blocks[0];
      for (i = 1; i <= num_refine; i++)
         global_active += num_blocks[i];
      // Will not be able to get to target in all cases, but can get to
      // a range of target +- 3 since can add or subtract in units of
      // 7 blocks.
      if ((target_active && global_active > num_pes*target_active + 3) ||
          (target_max && global_active > num_pes*target_max))
         nm_t += reduce_blocks();
      else if ((target_active && global_active < num_pes*target_active - 3) ||
               (target_min && global_active < num_pes*target_min))
         add_blocks();
      t5 = timer();
      timer_target_all += t5 - t2;
      t4 += t5 - t2;
   }
   t2 = timer();
   if (num_active > local_max_b)
      local_max_b = num_active;
   if (local_max_b > global_max_b)
      global_max_b = local_max_b;
   for (j = 0; j <= num_refine; j++) {
      if (!j)
         global_active = num_blocks[0];
      else
         global_active += num_blocks[j];
      if (!my_pe && report_perf & 8)
         printf("Number of blocks at level %d at timestep %d is %d\n",
                j, ts, num_blocks[j]);
   }
   if (!my_pe && report_perf & 8) printf("\n");
   t4 += timer() - t2;

   t5 = timer();
   timer_refine_cc += t5 - t1 - t4;
}

int refine_level(void)
{
   int level, nei, n, i, j, b, c, c1, change, unrefine, sib, p, in;
   block *bp, *bp1;
   parent *pp;

   /* block states:
    * 1 block should be refined
    * -1 block could be unrefined
    * 0 block at level 0 and can not be unrefined or
    *         at max level and can not be refined
    */

// get list of neighbor blocks (indirect links in from blocks)

   for (level = cur_max_level; level >= 0; level--) {
      /* check for blocks at this level that will refine
         their neighbors at this level can not unrefine
         their neighbors at a lower level must refine
      */
      do {
         change = 0;
         for (in = sorted_index[level]; in < sorted_index[level+1]; in++) {
            n = sorted_list[in].n;
            bp = &blocks[n];
            if (bp->number >= 0 && bp->level == level) {
               if (bp->refine == 1) {
                  if (bp->parent != -1 && bp->parent_node == my_pe) {
                     pp = &parents[bp->parent];
                     if (pp->refine == -1)
                        pp->refine = 0;
                     for (b = 0; b < 8; b++)
                        if (pp->child_node[b] == my_pe && pp->child[b] >= 0)
                           if (blocks[pp->child[b]].refine == -1) {
                              blocks[pp->child[b]].refine = 0;
                              change++;
                           }
                  }
                  for (i = 0; i < 6; i++)
                     /* neighbors in level above taken care of already */
                     /* neighbors in this level can not unrefine */
                     if (bp->nei_level[i] == level) {
                        if ((nei = bp->nei[i][0][0]) >= 0) { /* on core */
                           if (blocks[nei].refine == -1) {
                              blocks[nei].refine = 0;
                              change++;
                              if ((p = blocks[nei].parent) != -1 &&
                                    blocks[nei].parent_node == my_pe) {
                                 if ((pp = &parents[p])->refine == -1)
                                    pp->refine = 0;
                                 for (b = 0; b < 8; b++)
                                    if (pp->child_node[b] == my_pe &&
                                        pp->child[b] >= 0)
                                       if (blocks[pp->child[b]].refine == -1) {
                                          blocks[pp->child[b]].refine = 0;
                                          change++;
                                       }
                              }
                           }
                        }
                     /* neighbors in level below must refine */
                     } else if (bp->nei_level[i] == level-1)
                        if ((nei = bp->nei[i][0][0]) >= 0) {
                           if (blocks[nei].refine != 1) {
                              blocks[nei].refine = 1;
                              change++;
                           }
                        }
               } else if (bp->refine == -1) {
                  // check if block can be unrefined
                  for (i = 0; i < 6; i++)
                     if (bp->nei_level[i] == level+1) {
                        bp->refine = 0;
                        change++;
                        if ((p = bp->parent) != -1 &&
                            bp->parent_node == my_pe) {
                           if ((pp = &parents[p])->refine == -1)
                              pp->refine = 0;
                           for (b = 0; b < 8; b++)
                              if (pp->child_node[b] == my_pe &&
                                  pp->child[b] >= 0 &&
                                  blocks[pp->child[b]].refine == -1)
                                 blocks[pp->child[b]].refine = 0;
                        }
                     }
               }
            }
         }
      } while (change);

      /* Check for blocks at this level that will remain at this level
         their neighbors at a lower level can not unrefine
      */
      do {
         change = 0;
         for (in = sorted_index[level]; in < sorted_index[level+1]; in++) {
            n = sorted_list[in].n;
            bp = &blocks[n];
            if (bp->number >= 0)
               if (bp->level == level && bp->refine == 0)
                  for (c = 0; c < 6; c++)
                     if (bp->nei_level[c] == level-1) {
                        if ((nei = bp->nei[c][0][0]) >= 0) {
                           if (blocks[nei].refine == -1) {
                              blocks[nei].refine = 0;
                              change++;
                              if ((p = blocks[nei].parent) != -1 &&
                                    blocks[nei].parent_node == my_pe)
                                 if ((pp = &parents[p])->refine == -1) {
                                    pp->refine = 0;
                                    for (b = 0; b < 8; b++)
                                       if (pp->child_node[b] == my_pe &&
                                           pp->child[b] >= 0 &&
                                           blocks[pp->child[b]].refine == -1)
                                          blocks[pp->child[b]].refine = 0;
                                 }
                           }
                        }
                     } else if (bp->nei_level[c] == level) {
                        if ((nei = bp->nei[c][0][0]) >= 0)
                           blocks[nei].nei_refine[(c/2)*2+(c+1)%2] = 0;
                     } else if (bp->nei_level[c] == level+1) {
                        c1 = (c/2)*2 + (c+1)%2;
                        for (i = 0; i < 2; i++)
                           for (j = 0; j < 2; j++)
                              if ((nei = bp->nei[c][i][j]) >= 0)
                                 blocks[nei].nei_refine[c1] = 0;
                     }
         }
      } while (change);
   }

   for (i = in = 0; in < sorted_index[num_refine+1]; in++)
     if (blocks[sorted_list[in].n].refine == 1)
        i++;

   return(i);
}

// Reset the neighbor lists on blocks so that matching them against objects
// can set those which can be refined.
void reset_all(void)
{
   int n, c, in;
   block *bp;
   parent *pp;

   for (in = 0; in < sorted_index[num_refine+1]; in++) {
      n = sorted_list[in].n;
      if ((bp= &blocks[n])->number >= 0)
         bp->refine = -1;
   }

   for (n = 0; n < max_active_parent; n++)
      if ((pp = &parents[n])->number >= 0) {
         pp->refine = -1;
         for (c = 0; c < 8; c++)
            if (pp->child[c] < 0)
               pp->refine = 0;
         if (pp->refine == 0)
            for (c = 0; c < 8; c++)
               if (pp->child[c] >= 0)
                  if (blocks[pp->child[c]].refine == -1)
                     blocks[pp->child[c]].refine = 0;
      }
}
