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

// This routine moves the objects that determine the refinement and checks
// the blocks against those objects to determine which blocks will refine.
void move(void)
{
   int i, j;

   for (i = 0; i < num_objects; i++)
      for (j = 0; j < 3; j++) {
         objects[i].cen[j] += objects[i].move[j];
         if (objects[i].bounce)
            if (objects[i].cen[j] >= 1.0) {
               objects[i].cen[j] = 2.0 - objects[i].cen[j];
               objects[i].move[j] = -objects[i].move[j];
            } else if (objects[i].cen[j] <= 0.0) {
               objects[i].cen[j] = 0.0 - objects[i].cen[j];
               objects[i].move[j] = -objects[i].move[j];
            }
         objects[i].size[j] += objects[i].inc[j];
      }
}

void check_objects(void)
{
   int n, sz, in, c;
   double cor[3][2]; /* extent of block */
   block *bp;
   parent *pp;

/* only need to check corners to refine
 *  * if boundary is in block refine if not level max_level block.refine = 1
 *   * else if not level 0 then block.refine = -1  (unrefine)
 *    * types of objects: spheroid, solid spheroid, rectangle, solid rectangle,
 *    * hemispheroid, and solid hemispheroid (in six orientations),
 *    * cylinder, solid cylinder (in three directions)
 *    * (later) diamond, solid diamond */

   for (in = 0; in < sorted_index[num_refine+1]; in++) {
      n = sorted_list[in].n;
      if ((bp = &blocks[n])->number >= 0) {
         sz = p2[num_refine - bp->level]; /* half size of block */
         cor[0][0] = ((double) (bp->cen[0] - sz))/((double) mesh_size[0]);
         cor[0][1] = ((double) (bp->cen[0] + sz))/((double) mesh_size[0]);
         cor[1][0] = ((double) (bp->cen[1] - sz))/((double) mesh_size[1]);
         cor[1][1] = ((double) (bp->cen[1] + sz))/((double) mesh_size[1]);
         cor[2][0] = ((double) (bp->cen[2] - sz))/((double) mesh_size[2]);
         cor[2][1] = ((double) (bp->cen[2] + sz))/((double) mesh_size[2]);
         if (refine_ghost) {
            cor[0][0] -= 2.0*(((double) sz)/((double) x_block_size))/
                         ((double) mesh_size[0]);
            cor[0][1] += 2.0*(((double) sz)/((double) x_block_size))/
                         ((double) mesh_size[0]);
            cor[1][0] -= 2.0*(((double) sz)/((double) y_block_size))/
                         ((double) mesh_size[1]);
            cor[1][1] += 2.0*(((double) sz)/((double) y_block_size))/
                         ((double) mesh_size[1]);
            cor[2][0] -= 2.0*(((double) sz)/((double) z_block_size))/
                         ((double) mesh_size[2]);
            cor[2][1] += 2.0*(((double) sz)/((double) z_block_size))/
                         ((double) mesh_size[2]);
         }
         if (check_block(cor))
            bp->refine = 1;
         else if (refine_ghost && bp->level) {
            /* check if this block would unrefine, but its parent would then
             * refine.  Then leave it alone */
            sz = p2[num_refine - bp->level + 1]; /* half size of parent */
            cor[0][0] -= (((double) sz)/((double) x_block_size))/
                         ((double) mesh_size[0]);
            cor[0][1] += (((double) sz)/((double) x_block_size))/
                         ((double) mesh_size[0]);
            cor[1][0] -= (((double) sz)/((double) y_block_size))/
                         ((double) mesh_size[1]);
            cor[1][1] += (((double) sz)/((double) y_block_size))/
                         ((double) mesh_size[1]);
            cor[2][0] -= (((double) sz)/((double) z_block_size))/
                         ((double) mesh_size[2]);
            cor[2][1] += (((double) sz)/((double) z_block_size))/
                         ((double) mesh_size[2]);
            if (check_block(cor))
               bp->refine = 0;
         }

         /* if at max refinement, then can not refine */
         if ((bp->level == num_refine && bp->refine == 1) || !bp->refine) {
            bp->refine = 0;
            if (bp->parent != -1 && bp->parent_node == my_pe) {
               pp = &parents[bp->parent];
               pp->refine = 0;
               for (c = 0; c < 8; c++)
                  if (pp->child_node[c] == my_pe && pp->child[c] >= 0)
                     if (blocks[pp->child[c]].refine == -1)
                        blocks[pp->child[c]].refine = 0;
            }
         }
         /* if 0 level, we can not unrefine */
         if (!bp->level && bp->refine == -1)
            bp->refine = 0;
      }
   }
}

int check_block(double cor[3][2])
{
   int o, tmp, ca, c1, c2, intersect,
       xc, xv, yc, yv, zc, zv; /* where is center of object to block */
   object *op;

   intersect = 0;
   for (o = 0; o < num_objects; o++) {
      op = &objects[o];
      if (intersect > 0 ||
            op->size[0] < 0.0 || op->size[1] < 0.0 || op->size[2] < 0)
         /* skip since already determined that it will be refined or
          * can not be or object has size less than zero */
         ;
      else if (op->type == 0) {   /* surface of rectangle */
         if (cor[0][1] > (op->cen[0] - op->size[0]) &&
             cor[0][0] < (op->cen[0] + op->size[0])) {
            /* some portion of block intersects with rectangle in x
             * 4 cases - the two that straddle can be treated the same
             * and the two that do not can also be treated the same */
            if ((cor[0][0] < (op->cen[0] - op->size[0]) &&
                 cor[0][1] < (op->cen[0] + op->size[0])) ||
                (cor[0][0] > (op->cen[0] - op->size[0]) &&
                 cor[0][1] > (op->cen[0] + op->size[0]))) {
               /* one of rectangle boundary between block sides */
               if (cor[1][1] > (op->cen[1] - op->size[1]) &&
                   cor[1][0] < (op->cen[1] + op->size[1]) &&
                   cor[2][1] > (op->cen[2] - op->size[2]) &&
                   cor[2][0] < (op->cen[2] + op->size[2]))
                  /* some portion of block intersects rectangle in y,z */
                  intersect = 1;
            } else {
               /* rectangle in block (or vice-versa) in x */
               if (cor[1][1] > (op->cen[1] - op->size[1]) &&
                   cor[1][0] < (op->cen[1] + op->size[1])) {
                  /* some portion of block intersects rectangle in y */
                  if ((cor[1][0] < (op->cen[1] - op->size[1]) &&
                       cor[1][1] < (op->cen[1] + op->size[1])) ||
                      (cor[1][0] > (op->cen[1] - op->size[1]) &&
                       cor[1][1] > (op->cen[1] + op->size[1])))
                      if (cor[2][1] > (op->cen[2] - op->size[2]) &&
                          cor[2][0] < (op->cen[2] + op->size[2]))
                         /* portion of block intersects rectangle in z */
                         intersect = 1;
               } else {
                  /* rectangle in block (or vice-versa) in x and y */
                  if (cor[2][1] > (op->cen[2] - op->size[2]) &&
                      cor[2][0] < (op->cen[2] + op->size[2])) {
                     if ((cor[2][0] < (op->cen[2] - op->size[2]) &&
                          cor[2][1] < (op->cen[2] + op->size[2])) ||
                         (cor[2][0] > (op->cen[2] - op->size[2]) &&
                          cor[2][1] > (op->cen[2] + op->size[2])))
                        /* portion of block intersects rectangle in z */
                        intersect = 1;
                  } /* else case need not be considered */
               }
            }
         }
      } else if (op->type == 1) {   /* solid rectangle */
         if (cor[0][1] > (op->cen[0] - op->size[0]) &&
             cor[0][0] < (op->cen[0] + op->size[0]) &&
             cor[1][1] > (op->cen[1] - op->size[1]) &&
             cor[1][0] < (op->cen[1] + op->size[1]) &&
             cor[2][1] > (op->cen[2] - op->size[2]) &&
             cor[2][0] < (op->cen[2] + op->size[2]))
            intersect = 1;
      } else if (op->type >= 2 && op->type <= 14 && !(op->type%2)) {
         /* boundary of spheroid or hemispheroid */
         /* determine where center is and nearest and furthest
          * verticies and then determine if boundary is between them
          * 1 = (x/a)^2 + (y/b)^2 + (z/c)^2 is boundary */
         tmp = intersect;
         xc = yc = zc = 0;
         if (op->cen[0] < cor[0][0])
            xv = 0;
         else if (op->cen[0] > cor[0][1])
            xv = 1;
         else {
            xc = 1;
            if (op->cen[0] < (cor[0][0] + cor[0][1])/2.0)
               xv = 0;
            else
               xv = 1;
         }
         if (op->cen[1] < cor[1][0])
            yv = 0;
         else if (op->cen[1] > cor[1][1])
            yv = 1;
         else {
            yc = 1;
            if (op->cen[1] < (cor[1][0] + cor[1][1])/2.0)
               yv = 0;
            else
               yv = 1;
         }
         if (op->cen[2] < cor[2][0])
            zv = 0;
         else if (op->cen[2] > cor[2][1])
            zv = 1;
         else {
            zc = 1;
            if (op->cen[2] < (cor[2][0] + cor[2][1])/2.0)
               zv = 0;
            else
               zv = 1;
         }
         if (xc) {
            if (yc) {
               if (zc) {   /* xc, yc, zc */
                  if ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                       ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                       ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                       ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                       ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                       ((cor[2][1-zv] - op->cen[2])/op->size[2]))
                       > 1.0)
                     intersect = 1;
               } else {   /* xc, yc, !zc */
                  if ((fabs(cor[2][zv] - op->cen[2]) < op->size[2]) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               }
            } else {
               if (zc) {   /* xc, !yc, zc */
                  if ((fabs(cor[1][yv] - op->cen[1]) < op->size[1]) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               } else {   /* xc, !yc, !zc */
                  if (((((cor[1][yv] - op->cen[1])/op->size[1])*
                        ((cor[1][yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][zv] - op->cen[2])/op->size[2])*
                        ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               }
            }
         } else {
            if (yc) {
               if (zc) {   /* !xc, yc, zc */
                  if ((fabs(cor[0][xv] - op->cen[0]) < op->size[0]) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               } else {   /* !xc, yc, !zc */
                  if (((((cor[0][xv] - op->cen[0])/op->size[0])*
                        ((cor[0][xv] - op->cen[0])/op->size[0]) +
                        ((cor[2][zv] - op->cen[2])/op->size[2])*
                        ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               }
            } else {
               if (zc) {   /* !xc, !yc, zc */
                  if (((((cor[0][xv] - op->cen[0])/op->size[0])*
                        ((cor[0][xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][yv] - op->cen[1])/op->size[1])*
                        ((cor[1][yv] - op->cen[1])/op->size[1])) < 1.0) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               } else {   /* !xc, !yc, !zc */
                  if (((((cor[0][xv] - op->cen[0])/op->size[0])*
                        ((cor[0][xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][yv] - op->cen[1])/op->size[1])*
                        ((cor[1][yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][zv] - op->cen[2])/op->size[2])*
                        ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0) &&
                      ((((cor[0][1-xv] - op->cen[0])/op->size[0])*
                        ((cor[0][1-xv] - op->cen[0])/op->size[0]) +
                        ((cor[1][1-yv] - op->cen[1])/op->size[1])*
                        ((cor[1][1-yv] - op->cen[1])/op->size[1]) +
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])*
                        ((cor[2][1-zv] - op->cen[2])/op->size[2])) > 1.0))
                     intersect = 1;
               }
            }
         }
         if (op->type != 2 && intersect) {
            /* exclude halfplane of spheroid to make hemispheroid */
            if (op->type == 4 && cor[0][1] < op->cen[0])
               intersect = tmp;
            else if (op->type == 6 && cor[0][0] > op->cen[0])
               intersect = tmp;
            else if (op->type == 8 && cor[1][1] < op->cen[1])
               intersect = tmp;
            else if (op->type == 10 && cor[1][0] > op->cen[1])
               intersect = tmp;
            else if (op->type == 12 && cor[2][1] < op->cen[2])
               intersect = tmp;
            else if (op->type == 14 && cor[2][0] > op->cen[2])
               intersect = tmp;
         }
      } else if (op->type >= 3 && op->type <= 15 && op->type%2) {
         /* solid spheroid or hemispheroid */
         /* determine if center is in block - if so then refine,
          * if not determine nearest vertix and see if that is in
          * - if so refine
          * 1 = (x/a)^2 + (y/b)^2 + (z/c)^2 is boundary */
         tmp = intersect;
         xc = yc = zc = 0;
         if (op->cen[0] < cor[0][0])
            xv = 0;
         else if (op->cen[0] > cor[0][1])
            xv = 1;
         else
            xc = 1;
         if (op->cen[1] < cor[1][0])
            yv = 0;
         else if (op->cen[1] > cor[1][1])
            yv = 1;
         else
            yc = 1;
         if (op->cen[2] < cor[2][0])
            zv = 0;
         else if (op->cen[2] > cor[2][1])
            zv = 1;
         else
            zc = 1;
         if (xc) {
            if (yc) {
               if (zc)   /* xc, yc, zc */
                  intersect = 1;
               else {   /* xc, yc, !zc */
                  if (fabs(cor[2][zv] - op->cen[2]) < op->size[2])
                     intersect = 1;
               }
            } else {
               if (zc) {   /* xc, !yc, zc */
                  if (fabs(cor[1][yv] - op->cen[1]) < op->size[1])
                     intersect = 1;
               } else {   /* xc, !yc, !zc */
                  if ((((cor[1][yv] - op->cen[1])/op->size[1])*
                       ((cor[1][yv] - op->cen[1])/op->size[1]) +
                       ((cor[2][zv] - op->cen[2])/op->size[2])*
                       ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0)
                     intersect = 1;
               }
            }
         } else {
            if (yc) {
               if (zc) {   /* !xc, yc, zc */
                  if (fabs(cor[0][xv] - op->cen[0]) < op->size[0])
                     intersect = 1;
               } else {   /* !xc, yc, !zc */
                  if ((((cor[0][xv] - op->cen[0])/op->size[0])*
                       ((cor[0][xv] - op->cen[0])/op->size[0]) +
                       ((cor[2][zv] - op->cen[2])/op->size[2])*
                       ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0)
                     intersect = 1;
               }
            } else {
               if (zc) {   /* !xc, !yc, zc */
                  if ((((cor[0][xv] - op->cen[0])/op->size[0])*
                       ((cor[0][xv] - op->cen[0])/op->size[0]) +
                       ((cor[1][yv] - op->cen[1])/op->size[1])*
                       ((cor[1][yv] - op->cen[1])/op->size[1])) < 1.0)
                     intersect = 1;
               } else {   /* !xc, !yc, !zc */
                  if ((((cor[0][xv] - op->cen[0])/op->size[0])*
                       ((cor[0][xv] - op->cen[0])/op->size[0]) +
                       ((cor[1][yv] - op->cen[1])/op->size[1])*
                       ((cor[1][yv] - op->cen[1])/op->size[1]) +
                       ((cor[2][zv] - op->cen[2])/op->size[2])*
                       ((cor[2][zv] - op->cen[2])/op->size[2])) < 1.0)
                     intersect = 1;
               }
            }
         }
         if (op->type != 3 && intersect) {
            /* exclude halfplane of spheroid to make hemispheroid */
            if (op->type == 5 && cor[0][1] < op->cen[0])
               intersect = tmp;
            else if (op->type == 7 && cor[0][0] > op->cen[0])
               intersect = tmp;
            else if (op->type == 9 && cor[1][1] < op->cen[1])
               intersect = tmp;
            else if (op->type == 11 && cor[1][0] > op->cen[1])
               intersect = tmp;
            else if (op->type == 13 && cor[2][1] < op->cen[2])
               intersect = tmp;
            else if (op->type == 15 && cor[2][0] > op->cen[2])
               intersect = tmp;
         }
      } else if (op->type == 20 || op->type == 22 || op->type == 24) {
         /* boundary of cylinder, ca is axis of cylinder */
         if (op->type == 20) {
            ca = 0;
            c1 = 1;
            c2 = 2;
         } else if (op->type == 22) {
            ca = 1;
            c1 = 2;
            c2 = 0;
         } else {
            ca = 2;
            c1 = 0;
            c2 = 1;
         }
         if (cor[ca][1] > (op->cen[ca] - op->size[ca]) &&
             cor[ca][0] < (op->cen[ca] + op->size[ca])) {
            /* some part of block between planes that define ends */
            /* use y and z for directions perpendicular to axis */
            yc = zc = 0;
            if (op->cen[c1] < cor[c1][0])
               yv = 0;
            else if (op->cen[c1] > cor[c1][1])
               yv = 1;
            else {
               yc = 1;
               if (op->cen[c1] < (cor[c1][0] + cor[c1][1])/2.0)
                  yv = 0;
               else
                  yv = 1;
            }
            if (op->cen[c2] < cor[c2][0])
               zv = 0;
            else if (op->cen[c2] > cor[c2][1])
               zv = 1;
            else {
               zc = 1;
               if (op->cen[c2] < (cor[c2][0] + cor[c2][1])/2.0)
                  zv = 0;
               else
                  zv = 1;
            }
            if ((cor[0][0] < (op->cen[0] - op->size[0]) &&
                 cor[0][1] < (op->cen[0] + op->size[0])) ||
                (cor[0][0] > (op->cen[0] - op->size[0]) &&
                 cor[0][1] > (op->cen[0] + op->size[0]))) {
               /* block overlaps cylinder ends in aixs dir */
               if (yc) {
                  if (zc) {
                     intersect = 1;
                  } else {
                     if (fabs(cor[c2][zv] - op->cen[c2]) < op->size[c2])
                        intersect = 1;
                  }
               } else {
                  if (zc) {
                     if (fabs(cor[c1][yv] - op->cen[c1]) < op->size[c1])
                        intersect = 1;
                  } else {
                     if ((((cor[c1][yv] - op->cen[c1])/op->size[c1])*
                          ((cor[c1][yv] - op->cen[c1])/op->size[c1]) +
                          ((cor[c2][zv] - op->cen[c2])/op->size[c2])*
                          ((cor[c2][zv] - op->cen[c2])/op->size[c2]))
                           < 1.0)
                        intersect = 1;
                  }
               }
            } else {
               /* block in cylinder or cylinder in block in aixs dir */
               /* in c1 c2 plane need block point in and out of circle */
               if (yc) {
                  if (zc) {
                    if ((((cor[c1][1-yv] - op->cen[c1])/op->size[c1])*
                         ((cor[c1][1-yv] - op->cen[c1])/op->size[c1]) +
                         ((cor[c2][1-zv] - op->cen[c2])/op->size[c2])*
                         ((cor[c2][1-zv] - op->cen[c2])/op->size[c2]))
                         > 1.0)
                        intersect = 1;
                  } else {
                     if ((fabs(cor[c2][zv]-op->cen[c2]) < op->size[c2])&&
                         ((((cor[c1][1-yv] - op->cen[c1])/op->size[c1])*
                           ((cor[c1][1-yv] - op->cen[c1])/op->size[c1]) +
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2])*
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2]))
                           > 1.0))
                        intersect = 1;
                  }
               } else {
                  if (zc) {
                     if ((fabs(cor[c1][yv]-op->cen[c1]) < op->size[c1])&&
                         ((((cor[c1][1-yv] - op->cen[c1])/op->size[c1])*
                           ((cor[c1][1-yv] - op->cen[c1])/op->size[c1]) +
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2])*
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2]))
                           > 1.0))
                        intersect = 1;
                  } else {
                     if (((((cor[c1][yv] - op->cen[c1])/op->size[c1])*
                           ((cor[c1][yv] - op->cen[c1])/op->size[c1]) +
                           ((cor[c2][zv] - op->cen[c2])/op->size[c2])*
                           ((cor[c2][zv] - op->cen[c2])/op->size[c2]))
                           < 1.0) &&
                         ((((cor[c1][1-yv] - op->cen[c1])/op->size[c1])*
                           ((cor[c1][1-yv] - op->cen[c1])/op->size[c1]) +
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2])*
                           ((cor[c2][1-zv] - op->cen[c2])/op->size[c2]))
                           > 1.0))
                        intersect = 1;
                  }
               }
            }
         }
      } else if (op->type == 21 || op->type == 23 || op->type == 25) {
         /* volume of cylinder, ca is axis of cylinder */
         if (op->type == 21) {
            ca = 0;
            c1 = 1;
            c2 = 2;
         } else if (op->type == 23) {
            ca = 1;
            c1 = 2;
            c2 = 0;
         } else {
            ca = 2;
            c1 = 0;
            c2 = 1;
         }
         if (cor[ca][1] > (op->cen[ca] - op->size[ca]) &&
             cor[ca][0] < (op->cen[ca] + op->size[ca])) {
            /* some part of block between planes that define ends */
            /* use y and z for directions perpendicular to axis */
            yc = zc = 0;
            if (op->cen[c1] < cor[c1][0])
               yv = 0;
            else if (op->cen[c1] > cor[c1][1])
               yv = 1;
            else
               yc = 1;
            if (op->cen[c2] < cor[c2][0])
               zv = 0;
            else if (op->cen[c2] > cor[c2][1])
               zv = 1;
            else
               zc = 1;
            if (yc) {
               if (zc) {
                  intersect = 1;
               } else {
                  if (fabs(cor[c2][zv] - op->cen[c2]) < op->size[c2])
                     intersect = 1;
               }
            } else {
               if (zc) {
                  if (fabs(cor[c1][yv] - op->cen[c1]) < op->size[c1])
                     intersect = 1;
               } else {
                  if ((((cor[c1][yv] - op->cen[c1])/op->size[c1])*
                       ((cor[c1][yv] - op->cen[c1])/op->size[c1]) +
                       ((cor[c2][zv] - op->cen[c2])/op->size[c2])*
                       ((cor[c2][zv] - op->cen[c2])/op->size[c2])) < 1.0)
                     intersect = 1;
               }
            }
         }
      } else {
         printf("undefined object %d\n", op->type);
      }
   }
   return(intersect);
}
