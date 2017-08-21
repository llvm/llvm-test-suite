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
#include "proto.h"
#include "timer.h"

// This routine splits blocks that are being refined into 8 new blocks,
// copies the data over to the new blocks, and then disconnects the
// original block from the mesh and connects the new blocks to the
// mesh.  The information in old block is also transferred to a parent
// block, which also contains information to identify its children.
void split_blocks(void)
{
   static int side[6][2][2] = { { {0, 2}, {4, 6} }, { {1, 3}, {5, 7} },
                                { {0, 1}, {4, 5} }, { {2, 3}, {6, 7} },
                                { {0, 1}, {2, 3} }, { {4, 5}, {6, 7} } };
   static int off[6] = {1, -1, 2, -2, 4, -4};
   int i, j, k, m, n, o, v, nl, xp, yp, zp, c, c1, other,
       i1, i2, j1, j2, k1, k2, dir, fcase, pe, f, p,
       level, sib[8], offset, d, half_size;
   block *bp, *bp1;
   parent *pp;

   // have to do this by level, else could have a block at a level split and
   // its offspring try to connect to a block at a lower (that will be split)
   for (m = level = 0; level <= cur_max_level; level++) {
      // can not use sorted list here since this routine changes the list
      for (n = 0; n < max_active_block; n++)
         if (blocks[n].number >= 0 && blocks[n].level == level) {
            bp = &blocks[n];
            if (bp->refine == 1) {
               nl = bp->number - block_start[level];
               zp = nl/((p2[level]*npx*init_block_x)*
                        (p2[level]*npy*init_block_y));
               yp = (nl%((p2[level]*npx*init_block_x)*
                         (p2[level]*npy*init_block_y)))/
                    (p2[level]*npx*init_block_x);
               xp = nl%(p2[level]*npx*init_block_x);
               if ((num_active + 8) > max_num_blocks) {
                  printf("ERROR: Need more blocks %d %d on %d\n", num_active, max_num_blocks, my_pe);
                  exit(-1);
               }
               if ((num_active + 8) > local_max_b)
                  local_max_b = num_active + 8;
               del_sorted_list(bp->number, level);
               num_active += 7;
               num_blocks[level]--;
               num_blocks[level+1] += 8;
               for (p = 0; p < max_active_parent; p++)
                  if (parents[p].number < 0)
                     break;
               if (p == max_num_parents) {
                  printf("ERROR: Need more parents\n");
                  exit(-1);
               }
               if (p == max_active_parent)
                  max_active_parent++;
               num_parents++;
               num_refined++;
               pp = &parents[p];
               pp->number = bp->number;
               pp->level = bp->level;
               pp->parent = bp->parent;
               pp->parent_node = bp->parent_node;
               pp->child_number = bp->child_number;
               parents[pp->parent].child[pp->child_number] = -1 - p;
               pp->refine = 0;
               pp->cen[0] = bp->cen[0];
               pp->cen[1] = bp->cen[1];
               pp->cen[2] = bp->cen[2];

               // Define the 8 children
               for (o = 0; o < 8; o++) {
                  for ( ; m < max_num_blocks; m++)
                     if (blocks[m].number < 0)
                        break;
                  if (m == max_num_blocks) {
                     printf("Error: No inactive blocks available %d %d %d\n", m, num_active, max_num_blocks);
                     exit(-1);
                  }
                  if ((m+1) > max_active_block)
                     max_active_block = m+1;
                  bp1 = &blocks[m];
                  sib[o] = m;
                  pp->child[o] = m;
                  pp->child_node[o] = my_pe;
                  bp1->refine = 0;
                  bp1->level = level + 1;
                  bp1->parent = p;
                  bp1->parent_node = my_pe;
                  bp1->child_number = o;
                  i1 = (o%2);
                  j1 = ((o/2)%2);
                  k1 = (o/4);
                  bp1->number = ((2*zp+k1)*(p2[level+1]*npy*init_block_y) +
                                 (2*yp+j1))*(p2[level+1]*npx*init_block_x) +
                                2*xp + i1 + block_start[level+1];
                  add_sorted_list(m, bp1->number, (level+1));
                  bp1->cen[0] = bp->cen[0] +
                                (2*i1 - 1)*p2[num_refine - level - 1];
                  bp1->cen[1] = bp->cen[1] +
                                (2*j1 - 1)*p2[num_refine - level - 1];
                  bp1->cen[2] = bp->cen[2] +
                                (2*k1 - 1)*p2[num_refine - level - 1];
                  half_size = p2[num_refine - level - 1];
                  i1 *= x_block_half;
                  j1 *= y_block_half;
                  k1 *= z_block_half;
                  for (v = 0; v < num_vars; v++)
                     for (i2 = i = 1; i <= x_block_half; i++, i2+=2)
                        for (j2 = j = 1; j <= y_block_half; j++, j2+=2)
                           for (k2 = k = 1; k <= z_block_half; k++, k2+=2)
                              bp1->array[v][i2  ][j2  ][k2  ] =
                              bp1->array[v][i2+1][j2  ][k2  ] =
                              bp1->array[v][i2  ][j2+1][k2  ] =
                              bp1->array[v][i2+1][j2+1][k2  ] =
                              bp1->array[v][i2  ][j2  ][k2+1] =
                              bp1->array[v][i2+1][j2  ][k2+1] =
                              bp1->array[v][i2  ][j2+1][k2+1] =
                              bp1->array[v][i2+1][j2+1][k2+1] =
                                    bp->array[v][i+i1][j+j1][k+k1]/8.0;
               }

               // children all defined - connect children & disconnect parent
               for (c = 0; c < 6; c++) {
                  // deal with internal connections amoung 8 siblings
                  for (i = 0; i < 2; i++)
                     for (j = 0; j < 2; j++) {
                        blocks[sib[side[c][i][j]+off[c]]].nei_level[c] =
                              level + 1;
                        blocks[sib[side[c][i][j]+off[c]]].nei[c][0][0] =
                              sib[side[c][i][j]];
                     }
                  // deal with external connections
                  if (bp->nei_level[c] == -2)  // external boundary
                     for (i = 0; i < 2; i++)
                        for (j = 0; j < 2; j++) {
                           blocks[sib[side[c][i][j]]].nei_level[c] = -2;
                           blocks[sib[side[c][i][j]]].nei[c][0][0] = 0;
                        }
                  else if (bp->nei_level[c] == level-1) { // level less parent
                     if (bp->nei[c][0][0] >= 0) { // error
                        printf("%d ERROR: internal misconnect block %d num %d c %d %d\n",
                               my_pe, n, bp->number, c, bp->nei[c][0][0]);
                        exit(-1);
                     }
                  } else if (bp->nei_level[c] == level) { // paretn level
                     if (bp->nei[c][0][0] >= 0) {
                        other = bp->nei[c][0][0];
                        c1 = (c/2)*2 + (c+1)%2;
                        blocks[other].nei_level[c1] = level + 1;
                        for (i = 0; i < 2; i++)
                           for (j = 0; j < 2; j++) {
                              bp1 = &blocks[sib[side[c][i][j]]];
                              bp1->nei_level[c] = level;
                              bp1->nei[c][0][0] = other;
                              blocks[other].nei[c1][i][j] = sib[side[c][i][j]];
                           }
                     }
                  } else if (bp->nei_level[c] == level+1) { // child level
                     dir = c/2;
                     fcase = (c%2)*10;
                     c1 = (c/2)*2 + (c+1)%2;
                     d = 2*(c%2) - 1;
                     for (k = fcase+6, i = 0; i < 2; i++)
                        for (j = 0; j < 2; j++, k++)
                           if (bp->nei[c][i][j] >= 0) {
                              other = bp->nei[c][i][j];
                              bp1 = &blocks[sib[side[c][i][j]]];
                              bp1->nei_level[c] = level+1;
                              bp1->nei[c][0][0] = other;
                              blocks[other].nei_level[c1] = level + 1;
                              blocks[other].nei[c1][0][0] = sib[side[c][i][j]];
                           }
                  } else {
                     printf("%d ERROR: misconnected b %d %d l %d nei[%d] %d\n",
                            my_pe, n, bp->number, level, c, bp->nei_level[c]);
                     exit(-1);
                  }
               }
               /* children all defined and connected - inactivate block */
               bp->number = -1;
               if (n < m)
                  m = n;
            }
         }
   }
}

// This routine takes blocks that are to be coarsened and recombines them.
// Before this routine can be called, all of the child blocks need to be on
// the same processor as the parent.  A new block is created and the parent
// and child blocks are inactivated.
void consolidate_blocks(void)
{
   static int side[6][2][2] = { { {0, 2}, {4, 6} }, { {1, 3}, {5, 7} },
                                { {0, 1}, {4, 5} }, { {2, 3}, {6, 7} },
                                { {0, 1}, {2, 3} }, { {4, 5}, {6, 7} } };
   int n, p, i, j, k, i1, j1, k1, i2, j2, k2, level, o, v, f, c, offset,
       other, c1, dir, fcase, pe, nl, pos[3], d, in;
   block *bp, *bp1;
   parent *pp;

   if (stencil == 7)  // add to face case when diags are needed
      f = 0;
   else
      f = 1;
   // assume that blocks were moved back to node with parent
   for (level = cur_max_level; level >= 0; level--)
      for (p = 0; p < max_active_parent; p++)
         if ((pp = &parents[p])->number >= 0 && pp->level == level &&
             pp->refine == -1) {
            for (n = 0; n < max_num_blocks; n++)
               if (blocks[n].number < 0)  // found inactive block
                  break;
            if (n == max_num_blocks) {
               printf("Out of free blocks in consolidate_blocks %d\n", my_pe);
               exit(-1);
            } else
               bp = &blocks[n];
            if ((n+1) > max_active_block)
               max_active_block = n+1;
            if ((num_active + 1) > local_max_b)
               local_max_b = num_active + 1;
            num_active -= 7;
            num_reformed++;
            num_blocks[level]++;
            num_blocks[level+1] -= 8;
            bp->number = pp->number;
            pp->number = -1;
            bp->level = pp->level;
            bp->parent = pp->parent;
            bp->parent_node = pp->parent_node;
            bp->child_number = pp->child_number;
            parents[bp->parent].child[bp->child_number] = n;
            add_sorted_list(n, bp->number, level);
            bp->refine = 0;
            bp->cen[0] = pp->cen[0];
            bp->cen[1] = pp->cen[1];
            bp->cen[2] = pp->cen[2];
            // Copy child arrays back to new block.
            for (o = 0; o < 8; o++) {
               bp1 = &blocks[pp->child[o]];
               del_sorted_list(bp1->number, (level+1));
               bp1->number = -1;
               i1 = (o%2)*x_block_half;
               j1 = ((o/2)%2)*y_block_half;
               k1 = (o/4)*z_block_half;
               for (v = 0; v < num_vars; v++)
                  for (i2 = i = 1; i <= x_block_half; i++, i2+=2)
                     for (j2 = j = 1; j <= y_block_half; j++, j2+=2)
                        for (k2 = k = 1; k <= z_block_half; k++, k2+=2)
                           bp->array[v][i+i1][j+j1][k+k1] =
                                 bp1->array[v][i2  ][j2  ][k2  ] +
                                 bp1->array[v][i2+1][j2  ][k2  ] +
                                 bp1->array[v][i2  ][j2+1][k2  ] +
                                 bp1->array[v][i2+1][j2+1][k2  ] +
                                 bp1->array[v][i2  ][j2  ][k2+1] +
                                 bp1->array[v][i2+1][j2  ][k2+1] +
                                 bp1->array[v][i2  ][j2+1][k2+1] +
                                 bp1->array[v][i2+1][j2+1][k2+1];
            }
            // now figure out communication
            for (c = 0; c < 6; c++) {
               other = pp->child[side[c][0][0]]; // first child on this side
               // four options - boundary, level of parent, level of children,
               // and level of children + 1 (that are offnode and unrefining)
               if (blocks[other].nei_level[c] == -2) {
                  // external boundary (only need to check one child)
                  bp->nei_level[c] = -2;
                  bp->nei_refine[c] = 0;
               } else if (blocks[other].nei_level[c] == level) {
                  // same level as parent
                  if (blocks[other].nei[c][0][0] >= 0) {
                     // on node - if it gets consolidated later, it will fix
                     // the connections at that point
                     c1 = (c/2)*2 + (c+1)%2;
                     bp->nei[c][0][0] = blocks[other].nei[c][0][0];
                     bp->nei_level[c] = level;
                     bp->nei_refine[c] = 0;
                     blocks[blocks[other].nei[c][0][0]].nei[c1][0][0] = n;
                     blocks[blocks[other].nei[c][0][0]].nei_level[c1] = level;
                     blocks[blocks[other].nei[c][0][0]].nei_refine[c1] = 0;
                  }
               } else {
                  dir = c/2;
                  fcase = (c%2)*10;
                  offset = p2[num_refine - level - 1];
                  for (k = fcase+6, i = 0; i < 2; i++)
                     for (j = 0; j < 2; j++, k++) {
                        other = pp->child[side[c][i][j]];
                        if (blocks[other].nei[c][0][0] >= 0) {
                           if (blocks[other].nei_level[c] == level+2) {
                              printf("%d ERROR: %d con %d block %d c %d wrong level %d\n",
                                     my_pe, p, n, other, c, level);
                              exit(-1);
                           }
                           c1 = (c/2)*2 + (c+1)%2;
                           bp->nei[c][i][j] = blocks[other].nei[c][0][0];
                           bp->nei_level[c] = level + 1;
                           bp->nei_refine[c] = 0;
                           blocks[blocks[other].nei[c][0][0]].nei[c1][0][0] =
                                 n;
                           blocks[blocks[other].nei[c][0][0]].nei_level[c1] =
                                 level;
                           blocks[blocks[other].nei[c][0][0]].nei_refine[c1] =
                                 0;
                        }
                     }
               }
            }
         }
}

void add_sorted_list(int n, int number, int level)
{
   int i, j;

   for (i = sorted_index[level]; i < sorted_index[level+1]; i++)
      if (number > sorted_list[i].number)
         break;
   for (j = sorted_index[num_refine+1]; j > i; j--) {
      sorted_list[j].number = sorted_list[j-1].number;
      sorted_list[j].n      = sorted_list[j-1].n;
   }
   sorted_list[i].number = number;
   sorted_list[i].n      = n;
   for (i = level+1; i <= (num_refine+1); i++)
      sorted_index[i]++;
}

void del_sorted_list(int number, int level)
{
   int i, j;

   for (i = sorted_index[level]; i < sorted_index[level+1]; i++)
      if (number == sorted_list[i].number)
         break;
   if (number != sorted_list[i].number) {
      printf("ERROR: del_sorted_list on %d - number %d not found\n",
             my_pe, number);
      exit(-1);
   }
   for (j = level+1; j <= (num_refine+1); j++)
      sorted_index[j]--;
   for (j = i; j < sorted_index[num_refine+1]; j++) {
      sorted_list[j].number = sorted_list[j+1].number;
      sorted_list[j].n      = sorted_list[j+1].n;
   }
}

int find_sorted_list(int number, int level)
{
   int i;

   for (i = sorted_index[level]; i < sorted_index[level+1]; i++)
      if (number == sorted_list[i].number)
         return sorted_list[i].n;
   printf("ERROR: find_sorted_list on %d - number %d not found\n",
          my_pe, number);
   exit(-1);
}
