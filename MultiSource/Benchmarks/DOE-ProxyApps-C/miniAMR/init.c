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
#include <math.h>

#include "block.h"
#include "proto.h"

#ifndef NO_GLIBC_COMPAT_RAND
#include "glibc_compat_rand.h"

#define rand glibc_compat_rand
#define srand glibc_compat_srand
#endif


// Initialize the problem and setup initial blocks.
void init(void)
{
   int n, var, i, j, k, l, m, o, size, dir, i1, i2, j1, j2, k1, k2, ib, jb, kb;
   int start[num_pes], pos[3][num_pes], pos1[npx][npy][npz], set,
       num, npx1, npy1, npz1, pes, fact, fac[25], nfac, f;
   block *bp;

   tol = pow(10.0, ((double) -error_tol));

   p2[0] = p8[0] = 1;
   for (i = 0; i < (num_refine+1); i++) {
      p8[i+1] = p8[i]*8;
      p2[i+1] = p2[i]*2;
      sorted_index[i] = 0;
   }
   sorted_index[num_refine+1] = 0;
   block_start[0] = 0;
   local_max_b = global_max_b =  init_block_x*init_block_y*init_block_z;
   num = num_pes*global_max_b;
   for (i = 1; i <= num_refine; i++) {
      block_start[i] = block_start[i-1] + num;
      num *= 8;
      num_blocks[i] = 0;
   }

   x_block_half = x_block_size/2;
   y_block_half = y_block_size/2;
   z_block_half = z_block_size/2;

   max_active_block = init_block_x*init_block_y*init_block_z;
   num_active = max_active_block;
   global_active = num_active*num_pes;
   num_parents = max_active_parent = 0;
   size = p2[num_refine+1];  /* block size is p2[num_refine+1-level]
                              * smallest block is size p2[1], so can find
                              * its center */
   mesh_size[0] = npx*init_block_x*size;
   mesh_size[1] = npy*init_block_y*size;
   mesh_size[2] = npz*init_block_z*size;

   for (o = n = k = 0; k < init_block_z; k++)
      for (j = 0; j < init_block_y; j++)
         for (i = 0; i < init_block_x; i++, n++) {
            bp = &blocks[o];
            bp->level = 0;
            bp->number = n;
            bp->parent = -1;
            bp->cen[0] = i*size + size/2;
            bp->cen[1] = j*size + size/2;
            bp->cen[2] = k*size + size/2;
            add_sorted_list(o, n, 0);
            for (var = 0; var < num_vars; var++)
               for (ib = 1; ib <= x_block_size; ib++)
                  for (jb = 1; jb <= y_block_size; jb++)
                     for (kb = 1; kb <= z_block_size; kb++)
                        bp->array[var][ib][jb][kb] =
                                       ((double) rand())/((double) RAND_MAX);
            if (i == 0) { /* 0 boundary */
               bp->nei_level[0] = -2;
               bp->nei[0][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[0] = 0;
               bp->nei[0][0][0] = o - 1;
            }
            bp->nei_refine[0] = 0;
            if (i == (init_block_x - 1)) {
               bp->nei_level[1] = -2;
               bp->nei[1][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[1] = 0;
               bp->nei[1][0][0] = o + 1;
            }
            bp->nei_refine[1] = 0;
            if (j == 0) {
               bp->nei_level[2] = -2;
               bp->nei[2][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[2] = 0;
               bp->nei[2][0][0] = o - init_block_x;
            }
            bp->nei_refine[2] = 0;
            if (j == (init_block_y - 1)) {
               bp->nei_level[3] = -2;
               bp->nei[3][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[3] = 0;
               bp->nei[3][0][0] = o + init_block_x;
            }
            bp->nei_refine[3] = 0;
            if (k == 0) {
               bp->nei_level[4] = -2;
               bp->nei[4][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[4] = 0;
               bp->nei[4][0][0] = o - init_block_x*init_block_y;
            }
            bp->nei_refine[4] = 0;
            if (k == (init_block_z - 1)) {
               bp->nei_level[5] = -2;
               bp->nei[5][0][0] = 0;
            } else {          /* neighbor on core */
               bp->nei_level[5] = 0;
               bp->nei[5][0][0] = o + init_block_x*init_block_y;
            }
            bp->nei_refine[5] = 0;
            o++;
         }

   for (var = 0; var < num_vars; var++)
      grid_sum[var] = check_sum(var);
}
