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

#include "block.h"
#include "proto.h"
#include "timer.h"

// This file contains routines that modify the number of blocks so that the
// number is close (+- 3) to the target number of blocks for the problem.
int reduce_blocks()
{
   int l, i, j, p, c, num_comb, comb, num_parents, nm_t;
   double t1, t2, t3;
   parent *pp;

   nm_t = 0;
   t3 = 0.0;
   t1 = timer();

   zero_refine();
   if (target_active)
      num_comb = (global_active - num_pes*target_active + 3)/7;
   else
      num_comb = (global_active - num_pes*target_active)/7;

   for (comb = 0, l = num_refine-1; comb < num_comb; l--) {
      for (p = 0; p < max_active_parent; p++)
         if ((pp = &parents[p])->number >= 0)
            if (pp->level == l)
               num_parents++;

      for (p = 0; p < max_active_parent && comb < num_comb; p++)
         if ((pp = &parents[p])->number >= 0)
            if (pp->level == l) {
               pp->refine = -1;
               comb++;
               for (c = 0; c < 8; c++)
                  if (pp->child_node[c] == my_pe && pp->child[c] >= 0)
                     blocks[pp->child[c]].refine = -1;
            }

      t2 = timer() - t2;
      consolidate_blocks();
      t3 += timer() - t2;
   }
   timer_target_rb += timer() - t1;
   timer_target_dc += timer() - t1 - t3;
   timer_target_cb += t3;

   return(nm_t);
}

void add_blocks()
{
   int l, i, j, n, in, num_split, split;
   double t1, t2, t3;
   block *bp;

   t3 = 0.0;
   t1 = timer();

   if (target_active)
      num_split = (num_pes*target_active + 3 - global_active)/7;
   else
      num_split = (num_pes*target_active - global_active)/7;

   for (split = l = 0; split < num_split; l++) {
      zero_refine();
      for (j = num_refine; j >= 0; j--)
         if (num_blocks[j]) {
            cur_max_level = j;
            break;
      }
      for (in = 0; split < num_split && in < sorted_index[num_refine+1]; in++) {
         n = sorted_list[in].n;
         if ((bp = &blocks[n])->number >= 0)
            if (bp->level == l) {
               bp->refine = 1;
               split++;
            }
      }

      t2 = timer();
      split_blocks();
      t3 += timer() - t2;
   }
   timer_target_ab += timer() - t1;
   timer_target_da += timer() - t1 - t3;
   timer_target_sb += t3;
}

void zero_refine(void)
{
   int n, c, in;
   block *bp;
   parent *pp;

   for (in = 0; in < sorted_index[num_refine+1]; in++) {
      n = sorted_list[in].n;
      if ((bp= &blocks[n])->number >= 0) {
         bp->refine = 0;
         for (c = 0; c < 6; c++)
            if (bp->nei_level[c] >= 0)
               bp->nei_refine[c] = 0;
      }
   }

   for (n = 0; n < max_active_parent; n++)
      if ((pp = &parents[n])->number >= 0)
         pp->refine = 0;
}
