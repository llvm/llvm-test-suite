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
#include <stdlib.h>

#include "block.h"
#include "timer.h"
#include "proto.h"

// The routines in this file are used in the communication of ghost values
// between blocks, both on processor and off processor.

// Main communication routine that sends and recieves ghost values between
// blocks on different processors and directos blocks on the same processor
// to exchange their ghost values.
void comm(int start, int num_comm, int stage)
{
   int i, j, k, l, m, n, dir, o, in, which, offset, type;
   int permutations[6][3] = { {0, 1, 2}, {1, 2, 0}, {2, 0, 1},
                              {0, 2, 1}, {1, 0, 2}, {2, 1, 0} };
   double t1, t2, t3, t4;
   block *bp;

   for (o = 0; o < 3; o++) {
      if (permute)
         dir = permutations[stage%6][o];
      else
         dir = o;
      type = dir;
      t1 = timer();

      // While values are being sent over the mesh, go through and direct
      // blocks to exchange ghost values with other blocks that are on
      // processor.  Also apply boundary conditions for boundary of domain.
      for (in = 0; in < sorted_index[num_refine+1]; in++) {
         n = sorted_list[in].n;
         bp = &blocks[n];
         if (bp->number >= 0)
            for (l = dir*2; l < (dir*2 + 2); l++) {
               if (bp->nei_level[l] == bp->level) {
                  t2 = timer();
                  if ((m = bp->nei[l][0][0]) > n) {
                     on_proc_comm(n, m, l, start, num_comm);
                     counter_same[dir] += 2;
                  }
                  timer_comm_same[dir] += timer() - t2;
               } else if (bp->nei_level[l] == (bp->level+1)) {
                  t2 = timer();
                  for (i = 0; i < 2; i++)
                     for (j = 0; j < 2; j++)
                        if ((m = bp->nei[l][i][j]) > n) {
                           on_proc_comm_diff(n, m, l, i, j, start, num_comm);
                           counter_diff[dir] += 2;
                        }
                  timer_comm_diff[dir] += timer() - t2;
               } else if (bp->nei_level[l] == (bp->level-1)) {
                  t2 = timer();
                  if ((m = bp->nei[l][0][0]) > n) {
                     k = dir*2 + 1 - l%2;
                     for (i = 0; i < 2; i++)
                        for (j = 0; j < 2; j++)
                           if (blocks[m].nei[k][i][j] == n) {
                              on_proc_comm_diff(m, n, k, i, j, start, num_comm);
                              counter_diff[dir] += 2;
                           }
                  }
                  timer_comm_diff[dir] += timer() - t2;
               } else if (bp->nei_level[l] == -2) {
                  t2 = timer();
                  apply_bc(l, bp, start, num_comm);
                  counter_bc[dir]++;
                  timer_comm_bc[dir] += timer() - t2;
               } else {
                  printf("ERROR: misconnected block\n");
                  exit(-1);
               }
            }
      }
      timer_comm_dir[dir] += timer() - t1;
   }
}

// Routine that does on processor communication between two blocks that
// are at the same level of refinement.
void on_proc_comm(int n, int n1, int l, int start, int num_comm)
{
   int i, j, k, m;
   int is, ie, js, je;
   block *bp, *bp1;

   /* Determine direction and then exchange data across the face
   */
   if (!code) {
      if ((l/2) == 0) {         /* West, East */
         if ((l%2) == 0) {      /* West */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* East */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         for (m = start; m < start+num_comm; m++)
            for (j = 1; j <= y_block_size; j++)
               for (k = 1; k <= z_block_size; k++) {
                  bp1->array[m][x_block_size+1][j][k] = bp->array[m][1][j][k];
                  bp->array[m][0][j][k] = bp1->array[m][x_block_size][j][k];
               }
      } else if ((l/2) == 1) {  /* South, North */
         if ((l%2) == 0) {      /* South */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* North */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         if (stencil == 7) {
           is = 1;
           ie = x_block_size;
         } else {
           is = 0;
           ie = x_block_size + 1;
         }
         for (m = start; m < start+num_comm; m++)
            for (i = is; i <= ie; i++)
               for (k = 1; k <= z_block_size; k++) {
                  bp1->array[m][i][y_block_size+1][k] = bp->array[m][i][1][k];
                  bp->array[m][i][0][k] = bp1->array[m][i][y_block_size][k];
               }
      } else if ((l/2) == 2) {  /* Down, Up */
         if ((l%2) == 0) {      /* Down */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* Up */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         if (stencil == 7) {
           is = 1;
           ie = x_block_size;
           js = 1;
           je = y_block_size;
         } else {
           is = 0;
           ie = x_block_size + 1;
           js = 0;
           je = y_block_size + 1;
         }
         for (m = start; m < start+num_comm; m++)
            for (i = is; i <= ie; i++)
               for (j = js; j <= je; j++) {
                  bp1->array[m][i][j][z_block_size+1] = bp->array[m][i][j][1];
                  bp->array[m][i][j][0] = bp1->array[m][i][j][z_block_size];
               }
      }
   } else {  /* set all ghosts */
      if ((l/2) == 0) {         /* West, East */
         if ((l%2) == 0) {      /* West */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* East */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         for (m = start; m < start+num_comm; m++)
            for (j = 0; j <= y_block_size+1; j++)
               for (k = 0; k <= z_block_size+1; k++) {
                  bp1->array[m][x_block_size+1][j][k] = bp->array[m][1][j][k];
                  bp->array[m][0][j][k] = bp1->array[m][x_block_size][j][k];
               }
      } else if ((l/2) == 1) {  /* South, North */
         if ((l%2) == 0) {      /* South */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* North */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         for (m = start; m < start+num_comm; m++)
            for (i = 0; i <= x_block_size+1; i++)
               for (k = 0; k <= z_block_size+1; k++) {
                  bp1->array[m][i][y_block_size+1][k] = bp->array[m][i][1][k];
                  bp->array[m][i][0][k] = bp1->array[m][i][y_block_size][k];
               }
      } else if ((l/2) == 2) {  /* Down, Up */
         if ((l%2) == 0) {      /* Down */
            bp = &blocks[n];
            bp1 = &blocks[n1];
         } else {               /* Up */
            bp1 = &blocks[n];
            bp = &blocks[n1];
         }
         for (m = start; m < start+num_comm; m++)
            for (i = 0; i <= x_block_size+1; i++)
               for (j = 0; j <= y_block_size+1; j++) {
                  bp1->array[m][i][j][z_block_size+1] = bp->array[m][i][j][1];
                  bp->array[m][i][j][0] = bp1->array[m][i][j][z_block_size];
               }
      }
   }
}

// Routine that does on processor communication between two blocks that are
// at different levels of refinement.  The order of the blocks that are
// being input determine which block is at a higher level of refinement.
void on_proc_comm_diff(int n, int n1, int l, int iq, int jq,
                       int start, int num_comm)
{
   int i, j, k, m;
   int i0, i1, i2, i3, j0, j1, j2, j3, k0, k1, k2, k3;
   block *bp, *bp1;

   bp = &blocks[n];
   bp1 = &blocks[n1];

   /* (iq, jq) quarter face on block n to whole face on block n1
   */
   if (!code) {
      /* only have to communicate ghost values - bp is level, bp1 is level+1 -
       * in 2 to 1 case get 0..block_half from one proc and
       *                block_half+1..block_size+1 from another
       * in 1 to 2 case get 0..block_size+1 from 0..block_half+1 or
       *                block_half..block_size+1 with averages
       */
      if ((l/2) == 0) {
         if (l == 0) {             /* West */
            i0 = 0;
            i1 = 1;
            i2 = x_block_size + 1;
            i3 = x_block_size;
         } else {                  /* East */
            i0 = x_block_size + 1;
            i1 = x_block_size;
            i2 = 0;
            i3 = 1;
         }
         j1 = jq*y_block_half;
         k1 = iq*z_block_half;
         for (m = start; m < start+num_comm; m++)
            for (j = 1; j <= y_block_half; j++)
               for (k = 1; k <= z_block_half; k++) {
                  bp1->array[m][i2][2*j-1][2*k-1] =
                  bp1->array[m][i2][2*j-1][2*k  ] =
                  bp1->array[m][i2][2*j  ][2*k-1] =
                  bp1->array[m][i2][2*j  ][2*k  ] =
                                             bp->array[m][i1][j+j1][k+k1]/4.0;
                  bp->array[m][i0][j+j1][k+k1] =
                                             bp1->array[m][i3][2*j-1][2*k-1] +
                                             bp1->array[m][i3][2*j-1][2*k  ] +
                                             bp1->array[m][i3][2*j  ][2*k-1] +
                                             bp1->array[m][i3][2*j  ][2*k  ];
               }
      } else if ((l/2) == 1) {
         if (l == 2) {             /* South */
            j0 = 0;
            j1 = 1;
            j2 = y_block_size + 1;
            j3 = y_block_size;
         } else {                  /* North */
            j0 = y_block_size + 1;
            j1 = y_block_size;
            j2 = 0;
            j3 = 1;
         }
         i1 = jq*x_block_half;
         k1 = iq*z_block_half;
         for (m = start; m < start+num_comm; m++)
            for (i = 1; i <= x_block_half; i++)
               for (k = 1; k <= z_block_half; k++) {
                  bp1->array[m][2*i-1][j2][2*k-1] =
                  bp1->array[m][2*i-1][j2][2*k  ] =
                  bp1->array[m][2*i  ][j2][2*k-1] =
                  bp1->array[m][2*i  ][j2][2*k  ] =
                                             bp->array[m][i+i1][j1][k+k1]/4.0;
                  bp->array[m][i+i1][j0][k+k1] =
                                             bp1->array[m][2*i-1][j3][2*k-1] +
                                             bp1->array[m][2*i-1][j3][2*k  ] +
                                             bp1->array[m][2*i  ][j3][2*k-1] +
                                             bp1->array[m][2*i  ][j3][2*k  ];
               }
      } else if ((l/2) == 2) {
         if (l == 4) {             /* Down */
            k0 = 0;
            k1 = 1;
            k2 = z_block_size + 1;
            k3 = z_block_size;
         } else {                  /* Up */
            k0 = z_block_size + 1;
            k1 = z_block_size;
            k2 = 0;
            k3 = 1;
         }
         i1 = jq*x_block_half;
         j1 = iq*y_block_half;
         for (m = start; m < start+num_comm; m++)
            for (i = 1; i <= x_block_half; i++)
               for (j = 1; j <= y_block_half; j++) {
                  bp1->array[m][2*i-1][2*j-1][k2] =
                  bp1->array[m][2*i-1][2*j  ][k2] =
                  bp1->array[m][2*i  ][2*j-1][k2] =
                  bp1->array[m][2*i  ][2*j  ][k2] =
                                              bp->array[m][i+i1][j+j1][k1]/4.0;
                  bp->array[m][i+i1][j+j1][k0] =
                                              bp1->array[m][2*i-1][2*j-1][k3] +
                                              bp1->array[m][2*i-1][2*j  ][k3] +
                                              bp1->array[m][2*i  ][2*j-1][k3] +
                                              bp1->array[m][2*i  ][2*j  ][k3];
               }
      }
   } else {  /* transfer ghosts */
      if ((l/2) == 0) {
         if (l == 0) {             /* West */
            i0 = 0;
            i1 = 1;
            i2 = x_block_size + 1;
            i3 = x_block_size;
         } else {                  /* East */
            i0 = x_block_size + 1;
            i1 = x_block_size;
            i2 = 0;
            i3 = 1;
         }
         j1 = jq*y_block_half;
         k1 = iq*z_block_half;
         j2 = y_block_size + 1;
         j3 = y_block_half + 1;
         k2 = z_block_size + 1;
         k3 = z_block_half + 1;
         for (m = start; m < start+num_comm; m++) {
            bp1->array[m][i2][0][0] = bp->array[m][i1][j1][k1]/4.0;
            for (k = 1; k <= z_block_half; k++)
               bp1->array[m][i2][0][2*k-1] =
               bp1->array[m][i2][0][2*k  ] = bp->array[m][i1][j1][k+k1]/4.0;
            bp1->array[m][i2][0][k2] = bp->array[m][i1][j1][k3+k1]/4.0;
            if (jq == 0) {
               if (iq == 0)
                  bp->array[m][i0][0][0 ] = bp1->array[m][i3][0][0 ];
               else
                  bp->array[m][i0][0][k2] = bp1->array[m][i3][0][k2];
               for (k = 1; k <= z_block_half; k++)
                  bp->array[m][i0][0][k+k1] = (bp1->array[m][i3][0][2*k-1] +
                                               bp1->array[m][i3][0][2*k  ]);
            }
            for (j = 1; j <= y_block_half; j++) {
               bp1->array[m][i2][2*j-1][0] =
               bp1->array[m][i2][2*j  ][0] = bp->array[m][i1][j+j1][k1]/4.0;
               if (iq == 0)
                  bp->array[m][i0][j+j1][0 ] = (bp1->array[m][i3][2*j-1][0 ] +
                                                bp1->array[m][i3][2*j  ][0 ]);
               else
                  bp->array[m][i0][j+j1][k2] = (bp1->array[m][i3][2*j-1][k2] +
                                                bp1->array[m][i3][2*j  ][k2]);
               for (k = 1; k <= z_block_half; k++) {
                  bp1->array[m][i2][2*j-1][2*k-1] =
                  bp1->array[m][i2][2*j-1][2*k  ] =
                  bp1->array[m][i2][2*j  ][2*k-1] =
                  bp1->array[m][i2][2*j  ][2*k  ] =
                                             bp->array[m][i1][j+j1][k+k1]/4.0;
                  bp->array[m][i0][j+j1][k+k1] =
                                             bp1->array[m][i3][2*j-1][2*k-1] +
                                             bp1->array[m][i3][2*j-1][2*k  ] +
                                             bp1->array[m][i3][2*j  ][2*k-1] +
                                             bp1->array[m][i3][2*j  ][2*k  ];
               }
               bp1->array[m][i2][2*j-1][k2] =
               bp1->array[m][i2][2*j  ][k2] = bp->array[m][i1][j+j1][k3+k1]/4.0;
            }
            bp1->array[m][i2][j2][0] = bp->array[m][i1][j3+j1][k1]/4.0;
            for (k = 1; k <= z_block_half; k++)
               bp1->array[m][i2][j2][2*k-1] =
               bp1->array[m][i2][j2][2*k  ] = bp->array[m][i1][j3+j1][k+k1]/4.0;
            bp1->array[m][i2][j2][k2] = bp->array[m][i1][j3+j1][k3+k1]/4.0;
            if (jq == 1) {
               if (iq == 0)
                  bp->array[m][i0][j2][0 ] = bp1->array[m][i3][j2][0 ];
               else
                  bp->array[m][i0][j2][k2] = bp1->array[m][i3][j2][k2];
               for (k = 1; k <= z_block_half; k++)
                  bp->array[m][i0][j2][k+k1] = (bp1->array[m][i3][j2][2*k-1] +
                                                bp1->array[m][i3][j2][2*k  ]);
            }
         }
      } else if ((l/2) == 1) {
         if (l == 2) {             /* South */
            j0 = 0;
            j1 = 1;
            j2 = y_block_size + 1;
            j3 = y_block_size;
         } else {                  /* North */
            j0 = y_block_size + 1;
            j1 = y_block_size;
            j2 = 0;
            j3 = 1;
         }
         i1 = jq*x_block_half;
         k1 = iq*z_block_half;
         i2 = x_block_size + 1;
         i3 = x_block_half + 1;
         k2 = z_block_size + 1;
         k3 = z_block_half + 1;
         for (m = start; m < start+num_comm; m++) {
            bp1->array[m][0][j2][0 ] = bp->array[m][i1][j1][k1]/4.0;
            for (k = 1; k <= z_block_half; k++)
               bp1->array[m][0][j2][2*k-1] =
               bp1->array[m][0][j2][2*k  ] = bp->array[m][i1][j1][k+k1]/4.0;
            bp1->array[m][0][j2][k2] = bp->array[m][i1][j1][k3+k1]/4.0;
            if (jq == 0) {
               if (iq == 0)
                  bp->array[m][0][j0][0 ] = bp1->array[m][0][j3][0 ];
               else
                  bp->array[m][0][j0][k2] = bp1->array[m][0][j3][k2];
               for (k = 1; k <= z_block_half; k++)
                  bp->array[m][0][j0][k+k1] = (bp1->array[m][0][j3][2*k-1] +
                                               bp1->array[m][0][j3][2*k  ]);
            }
            for (i = 1; i <= x_block_half; i++) {
               bp1->array[m][2*i-1][j2][0] =
               bp1->array[m][2*i  ][j2][0] = bp->array[m][i+i1][j1][k1]/4.0;
               if (iq == 0)
                  bp->array[m][i+i1][j0][0 ] = (bp1->array[m][2*i-1][j3][0 ] +
                                                bp1->array[m][2*i  ][j3][0 ]);
               else
                  bp->array[m][i+i1][j0][k2] = (bp1->array[m][2*i-1][j3][k2] +
                                                bp1->array[m][2*i  ][j3][k2]);
               for (k = 1; k <= z_block_half; k++) {
                  bp1->array[m][2*i-1][j2][2*k-1] =
                  bp1->array[m][2*i-1][j2][2*k  ] =
                  bp1->array[m][2*i  ][j2][2*k-1] =
                  bp1->array[m][2*i  ][j2][2*k  ] =
                                             bp->array[m][i+i1][j1][k+k1]/4.0;
                  bp->array[m][i+i1][j0][k+k1] =
                                             bp1->array[m][2*i-1][j3][2*k-1] +
                                             bp1->array[m][2*i-1][j3][2*k  ] +
                                             bp1->array[m][2*i  ][j3][2*k-1] +
                                             bp1->array[m][2*i  ][j3][2*k  ];
               }
               bp1->array[m][2*i-1][j2][k2] =
               bp1->array[m][2*i  ][j2][k2] = bp->array[m][i+i1][j1][k3+k1]/4.0;
            }
            bp1->array[m][i2][j2][0 ] = bp->array[m][i3+i1][j1][k1]/4.0;
            for (k = 1; k <= z_block_half; k++)
               bp1->array[m][i2][j2][2*k-1] =
               bp1->array[m][i2][j2][2*k  ] = bp->array[m][i3+i1][j1][k+k1]/4.0;
            bp1->array[m][i2][j2][k2] = bp->array[m][i3+i1][j1][k3+k1]/4.0;
            if (jq == 1) {
               if (iq == 0)
                  bp->array[m][i2][j0][0 ] = bp1->array[m][i2][j3][0 ];
               else
                  bp->array[m][i2][j0][k2] = bp1->array[m][i2][j3][k2];
               for (k = 1; k <= z_block_half; k++)
                  bp->array[m][i2][j0][k+k1] = (bp1->array[m][i2][j3][2*k-1] +
                                                bp1->array[m][i2][j3][2*k  ]);
            }
         }
      } else if ((l/2) == 2) {
         if (l == 4) {             /* Down */
            k0 = 0;
            k1 = 1;
            k2 = z_block_size + 1;
            k3 = z_block_size;
         } else {                  /* Up */
            k0 = z_block_size + 1;
            k1 = z_block_size;
            k2 = 0;
            k3 = 1;
         }
         i1 = jq*x_block_half;
         j1 = iq*y_block_half;
         i2 = x_block_size + 1;
         i3 = x_block_half + 1;
         j2 = y_block_size + 1;
         j3 = y_block_half + 1;
         for (m = start; m < start+num_comm; m++) {
            bp1->array[m][0][0 ][k2] = bp->array[m][i1][j1][k1]/4.0;
            for (j = 1; j <= y_block_half; j++)
               bp1->array[m][0][2*j-1][k2] =
               bp1->array[m][0][2*j  ][k2] = bp->array[m][i1][j+j1][k1]/4.0;
            bp1->array[m][0][j2][k2] = bp->array[m][i1][j3+j1][k1]/4.0;
            if (jq == 0) {
               if (iq == 0)
                  bp->array[m][0][0 ][k0] = bp1->array[m][0][0 ][k3];
               else
                  bp->array[m][0][j2][k0] = bp1->array[m][0][j2][k3];
               for (j = 1; j <= y_block_half; j++)
                  bp->array[m][0][j+j1][k0] = (bp1->array[m][0][2*j-1][k3] +
                                               bp1->array[m][0][2*j  ][k3]);
            }
            for (i = 1; i <= x_block_half; i++) {
               bp1->array[m][2*i-1][0][k2] =
               bp1->array[m][2*i  ][0][k2] = bp->array[m][i+i1][j1][k1]/4.0;
               if (iq == 0)
                  bp->array[m][i+i1][0][k0] = (bp1->array[m][2*i-1][0][k3] +
                                               bp1->array[m][2*i  ][0][k3]);
               else
                  bp->array[m][i+i1][j2][k0] = (bp1->array[m][2*i-1][j2][k3] +
                                                bp1->array[m][2*i  ][j2][k3]);
               for (j = 1; j <= y_block_half; j++) {
                  bp1->array[m][2*i-1][2*j-1][k2] =
                  bp1->array[m][2*i-1][2*j  ][k2] =
                  bp1->array[m][2*i  ][2*j-1][k2] =
                  bp1->array[m][2*i  ][2*j  ][k2] =
                                              bp->array[m][i+i1][j+j1][k1]/4.0;
                  bp->array[m][i+i1][j+j1][k0] =
                                              bp1->array[m][2*i-1][2*j-1][k3] +
                                              bp1->array[m][2*i-1][2*j  ][k3] +
                                              bp1->array[m][2*i  ][2*j-1][k3] +
                                              bp1->array[m][2*i  ][2*j  ][k3];
               }
               bp1->array[m][2*i-1][j2][k2] =
               bp1->array[m][2*i  ][j2][k2] = bp->array[m][i+i1][j3+j1][k1]/4.0;
            }
            bp1->array[m][i2][0 ][k2] = bp->array[m][i3+i1][j1][k1]/4.0;
            for (j = 1; j <= y_block_half; j++)
               bp1->array[m][i2][2*j-1][k2] =
               bp1->array[m][i2][2*j  ][k2] = bp->array[m][i3+i1][j+j1][k1]/4.0;
            bp1->array[m][i2][j2][k2] = bp->array[m][i3+i1][j3+j1][k1]/4.0;
            if (jq == 1) {
               if (iq == 0)
                  bp->array[m][i2][0 ][k0] = bp1->array[m][i2][0 ][k3];
               else
                  bp->array[m][i2][j2][k0] = bp1->array[m][i2][j2][k3];
               for (j = 1; j <= y_block_half; j++)
                  bp->array[m][i2][j+j1][k0] = (bp1->array[m][i2][2*j-1][k3] +
                                                bp1->array[m][i2][2*j  ][k3]);
            }
         }
      }
   }
}

// Apply reflective boundary conditions to a face of a block.
void apply_bc(int l, block *bp, int start, int num_comm)
{
   int var, i, j, k, f, t;

   t = 0;
   f = 1;
   if (!code && stencil == 7)
      switch (l) {
         case 1: t = x_block_size + 1;
                 f = x_block_size;
         case 0: for (var = start; var < start+num_comm; var++)
                    for (j = 1; j <= y_block_size; j++)
                       for (k = 1; k <= z_block_size; k++)
                          bp->array[var][t][j][k] = bp->array[var][f][j][k];
                 break;
         case 3: t = y_block_size + 1;
                 f = y_block_size;
         case 2: for (var = start; var < start+num_comm; var++)
                    for (i = 1; i <= x_block_size; i++)
                       for (k = 1; k <= z_block_size; k++)
                          bp->array[var][i][t][k] = bp->array[var][i][f][k];
                 break;
         case 5: t = z_block_size + 1;
                 f = z_block_size;
         case 4: for (var = start; var < start+num_comm; var++)
                    for (i = 1; i <= x_block_size; i++)
                       for (j = 1; j <= y_block_size; j++)
                          bp->array[var][i][j][t] = bp->array[var][i][j][f];
                 break;
      }
   else
      switch (l) {
         case 1: t = x_block_size + 1;
                 f = x_block_size;
         case 0: for (var = start; var < start+num_comm; var++)
                    for (j = 0; j <= y_block_size+1; j++)
                       for (k = 0; k <= z_block_size+1; k++)
                          bp->array[var][t][j][k] = bp->array[var][f][j][k];
                 break;
         case 3: t = y_block_size + 1;
                 f = y_block_size;
         case 2: for (var = start; var < start+num_comm; var++)
                    for (i = 0; i <= x_block_size+1; i++)
                       for (k = 0; k <= z_block_size+1; k++)
                          bp->array[var][i][t][k] = bp->array[var][i][f][k];
                 break;
         case 5: t = z_block_size + 1;
                 f = z_block_size;
         case 4: for (var = start; var < start+num_comm; var++)
                    for (i = 0; i <= x_block_size+1; i++)
                       for (j = 0; j <= y_block_size+1; j++)
                          bp->array[var][i][j][t] = bp->array[var][i][j][f];
                 break;
      }
}
