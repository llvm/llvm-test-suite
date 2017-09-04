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
 *           Other LANL authors
 * 
 */
#include <math.h>
#include "KDTree.h"

#define MALLOC(n,t) ((t*)(malloc(n * sizeof(t))))
#define REALLOC(p,n,t) ((t*)(realloc((void*)p, n * sizeof(t))))
#define FREE(p) { if (p) free(p); }

static void median_sort(TKDTree* t,
                        unsigned int cut_direction, int k, int num, int* idx)
{
   int left, mid, right, a, i, j;
   
   for (left = 0, right = num - 1; (right - left) > 1;) {
      mid = (left + right) / 2;
      SWAP(idx[mid], idx[left + 1], int);
      if(Bounds_CenterAxis(&(t->elements[idx[left + 1]]), cut_direction) >
         Bounds_CenterAxis(&(t->elements[idx[right]]), cut_direction))
         SWAP(idx[left + 1], idx[right], int);
      if(Bounds_CenterAxis(&(t->elements[idx[left]]), cut_direction) >
         Bounds_CenterAxis(&(t->elements[idx[right]]), cut_direction))
         SWAP(idx[left], idx[right], int);
      if(Bounds_CenterAxis(&(t->elements[idx[left + 1]]), cut_direction) >
         Bounds_CenterAxis(&(t->elements[idx[left]]), cut_direction))
         SWAP(idx[left + 1], idx[left], int);
      a = idx[left];
      i = left + 1;
      j = right;
      while (1) {
         for (i++;
              Bounds_CenterAxis(&(t->elements[idx[i]]), cut_direction) <
                Bounds_CenterAxis(&(t->elements[a]), cut_direction);
              i++);
         for (j--;
              Bounds_CenterAxis(&(t->elements[idx[j]]), cut_direction) >
              Bounds_CenterAxis(&(t->elements[a]), cut_direction);
              j--);
         if(j < i)
            break;
         SWAP(idx[i], idx[j], int);
      }
      idx[left] = idx[j];
      idx[j] = a;
      if(j >= k)
         right = j - 1;
      if(j <= k)
         left = i;
   }
   if(((right - left) ==1) &&
      (Bounds_CenterAxis(&(t->elements[idx[right]]), cut_direction) <
       Bounds_CenterAxis(&(t->elements[idx[left]]), cut_direction)))
      SWAP(idx[right], idx[left], int);
}

void KDTree_Initialize(TKDTree* t)
{
   assert(t);
   /* Flush the overall tree extent */
   Bounds_Infinite(&(t->extent));
   /* Allocate the initial memory for tree elements */
   t->elements_num = 0;
   t->elements_allocated = KDTREE_ELEMENT_BLOCKING_SIZE;
   t->elements = MALLOC(t->elements_allocated, TBounds);
   assert(t->elements);
   /* Start without a built tree */
   t->tree_built = false;
   t->tree_size = 0;
   t->tree_safety_boxes = NULL;
   t->tree_link = NULL;
}

void KDTree_Finalize(TKDTree* t)
{
   free(t->elements);
}

void KDTree_Destroy(TKDTree* t)
{
   assert(t);
   /* Flush the overall tree extent */
   Bounds_Infinite(&(t->extent));
   /* Destroy the element list */
   t->elements_num = 0;
   t->elements_allocated = 0;
   FREE(t->elements);
   t->elements = NULL;
   /* Destroy the actual tree */
   t->tree_built = false;
   t->tree_size = 0;
   FREE(t->tree_safety_boxes);
   t->tree_safety_boxes = NULL;
   FREE(t->tree_link);
   t->tree_link = NULL;
}



void KDTree_AddElement(TKDTree* t, TBounds* add)
{
   assert(t && add);
   /* Destroy the current tree if it is built */
   if(t->tree_built) {
      t->tree_built = false;
      t->tree_size = 0;
      FREE(t->tree_safety_boxes);
      t->tree_safety_boxes = NULL;
      FREE(t->tree_link);
      t->tree_link = NULL;
   }
   /* Expand the element array if necessary */
   if(t->elements_num == t->elements_allocated) {
      t->elements_allocated += KDTREE_ELEMENT_BLOCKING_SIZE;
      t->elements = REALLOC(t->elements, t->elements_allocated, TBounds);
      assert(t->elements);
   }
   /* Add the new element to the overall extent and the element list */
   Bounds_AddBounds(&(t->extent), add);
   Bounds_Copy(add, &(t->elements[t->elements_num]));
   t->elements_num++;
}

void KDTree_CreateTree(TKDTree* t)
{
   unsigned int i;
   int next_node, stack_ptr, min, mid, max, parent, cut_direction;
   double width, max_width;
   int* stack;
   int* idx;
   
   assert(t);
   /* If the tree is already built, we don't have to do anything */
   if(t->tree_built)
      return;
   /* If there are no elements in the tree, we don't have to do anything */
   if(t->elements_num > 0) {
      /* Allocate the k-D tree memory */
      t->tree_size = 2 * t->elements_num;
      t->tree_safety_boxes = MALLOC(t->tree_size, TBounds);
      t->tree_link = MALLOC(t->tree_size, int);
      /* Create and initialize temporary arrays */
      next_node = 0;
      stack_ptr = 0;
      stack = MALLOC(3 * t->tree_size, int);
      idx = MALLOC(t->elements_num, int);
      for (i = 0; (int)i <  t->elements_num; i++) {
         idx[i] = i;
      }
      /* Setup the root node of the tree and put it on the stack */
      stack[stack_ptr++] = 0;                   /* Node Number in the Tree */
      stack[stack_ptr++] = 0;                   /* Element Span Minumum */
      stack[stack_ptr++] = t->elements_num - 1; /* Element Span Maximum */
      Bounds_Copy(&(t->extent), &(t->tree_safety_boxes[0]));
      next_node++;
      /* Construct k-D tree by setting up each pair of child nodes */
      while (stack_ptr) {
         /* Pop the top entry off the stack */
         max = stack[--stack_ptr];
         min = stack[--stack_ptr];
         parent = stack[--stack_ptr];
         /* If the current node should be a leaf node, make it one */
         if ((max - min) == 0) {
            Bounds_Copy(&(t->elements[idx[min]]), &(t->tree_safety_boxes[parent]));
            t->tree_link[parent] = - idx[min];
            continue;
         }
         /* Select optimum cutting direction for the parent node's safety box */
         cut_direction = -1;
         max_width = NEGATIVE_INFINITY;
         for (i = 0; i < 2; i++) {
            width = Bounds_WidthAxis(&(t->tree_safety_boxes[parent]), i);
            if(width > max_width) {
               max_width = width;
               cut_direction = i;
            }
         }
         assert(cut_direction >= 0);
         /* Do a median sort of the elements under the parent node. The sort key
            is the center point of the element bounding boxes along the selected
            cutting direction. */
         mid = (min + max) /2;
         median_sort(t, (unsigned int)cut_direction, mid - min, max - min + 1, &(idx[min]));
         /* Give the parent a reference to its two children */
         t->tree_link[parent] = next_node;
         /* Add the "left" child to the tree and the stack */
         stack[stack_ptr++] = next_node;  /* Node Number in the Tree */
         stack[stack_ptr++] = min;        /* Element Span Minimum */
         stack[stack_ptr++] = mid;        /* Element Span Maximum */
         Bounds_Infinite(&(t->tree_safety_boxes[next_node]));
         for (i = min; (int)i <= mid; i++) {
            Bounds_AddBounds(&(t->tree_safety_boxes[next_node]),
                             &(t->elements[idx[i]]));
         }
         next_node++;
         /* Add the "right" child to the tree and the stack */
         stack[stack_ptr++] = next_node;  /* Node Number in the Tree */
         stack[stack_ptr++] = mid + 1;    /* Element Span Minimum */
         stack[stack_ptr++] = max;        /* Element Span Maximum */
         Bounds_Infinite(&(t->tree_safety_boxes[next_node]));
         for (i = min + 1; (int)i <= max; i++) {
            Bounds_AddBounds(&(t->tree_safety_boxes[next_node]),
                             &(t->elements[idx[i]]));
         }
         next_node++;
      }
      /* Destroy the temporary arrays */
      FREE(stack);
      FREE(idx);
   }
   /* Mark the tree "built" */
   t->tree_built = true;
}

void KDTree_QueryBoxIntersect(TKDTree* t,
                              int* result_num, int* result_indicies,
                              TBounds* box)
{
   int stack_ptr, node;
   TBounds sb;
   int* stack;
   
   assert(t && result_num && result_indicies && box);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   /* Allocate the results array */
   *result_num = 0;
   /* Create the temporary stack array */
   stack_ptr = 0;
   stack = MALLOC(t->tree_size, int);
   
   /* Put the root node of the tree onto the stack */
   stack[stack_ptr++] = 0;
   /* Search the k-D tree until the stack is empty */
   
   while (stack_ptr) {
      /* Pop the top entry off the stack */
      node = stack[--stack_ptr];
      /* Check if the query box intersects an epsilon-expanded safety box for
         the current node. */
      Bounds_Copy(&(t->tree_safety_boxes[node]), &sb);
      //Bounds_AddEpsilon(&sb, ENTITY_COINCIDENCE_TOLERANCE);
      /* If the query box doesn't intersect this node's safety box, we are done
         visiting the node and should continue with the next node */
      if(!Bounds_IsOverlappingBounds(&sb, box))
         continue;
      /* If the current node is a leaf node, add it to the collision list. If
         the current node is an interior node, add its children to the stack. */
      if(t->tree_link[node] <= 0) {
         result_indicies[*result_num] = - t->tree_link[node];
         (*result_num)++;
      }
      else {
         stack[stack_ptr++] = t->tree_link[node];
         stack[stack_ptr++] = t->tree_link[node] + 1;
      }
   }
   /* Destroy the temporary stack array */
   FREE(stack);
}

void KDTree_QueryCircleIntersect_Double(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double circ_radius, int ncells, 
                                 double *x, double *dx, double *y, double *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;

   double rad1, rad2, rad3, rad4;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      if ((circ_radius < rad1 && circ_radius > rad2 ) ||
          (circ_radius > rad1 && circ_radius < rad2 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad2 && circ_radius > rad3 ) ||
          (circ_radius > rad2 && circ_radius < rad3 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad3 && circ_radius > rad4 ) ||
          (circ_radius > rad3 && circ_radius < rad4 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad4 && circ_radius > rad1 ) ||
          (circ_radius > rad4 && circ_radius < rad1 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }
   } // for  
   free(ind);
}

void KDTree_QueryCircleIntersect_Float(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double circ_radius, int ncells, 
                                 float *x, float *dx, float *y, float *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;

   double rad1, rad2, rad3, rad4;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      if ((circ_radius < rad1 && circ_radius > rad2 ) ||
          (circ_radius > rad1 && circ_radius < rad2 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad2 && circ_radius > rad3 ) ||
          (circ_radius > rad2 && circ_radius < rad3 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad3 && circ_radius > rad4 ) ||
          (circ_radius > rad3 && circ_radius < rad4 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      } else if ((circ_radius < rad4 && circ_radius > rad1 ) ||
          (circ_radius > rad4 && circ_radius < rad1 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }
   } // for  
   free(ind);
}

void KDTree_QueryCircleIntersectWeighted_Double(TKDTree* t,
                                 int* result_num, int* result_indicies, double *weight,
                                 double circ_radius, int ncells, 
                                 double *x, double *dx, double *y, double *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;
   
   double rad1, rad2, rad3, rad4;
   int cuts_bottom, cuts_top, cuts_left, cuts_right;
   int vertical_half, horizontal_half;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      cuts_bottom=0;
      cuts_top=0;
      cuts_left=0;
      cuts_right=0;
      if ((circ_radius < rad1 && circ_radius > rad2 ) ||
          (circ_radius > rad1 && circ_radius < rad2 ) ) {
         cuts_bottom=1;
      }
      if ((circ_radius < rad2 && circ_radius > rad3 ) ||
          (circ_radius > rad2 && circ_radius < rad3 ) ) {
         cuts_right=1;
      }
      if ((circ_radius < rad3 && circ_radius > rad4 ) ||
          (circ_radius > rad3 && circ_radius < rad4 ) ) {
         cuts_top=1;
      }
      if ((circ_radius < rad4 && circ_radius > rad1 ) ||
          (circ_radius > rad4 && circ_radius < rad1 ) ) {
         cuts_left=1;
      }
      
      horizontal_half=0;
      vertical_half=0;
      if (x[ii]+0.5*dx[ii] > 0.0) horizontal_half = RIGHT_HALF;
      if (y[ii]+0.5*dy[ii] > 0.0) vertical_half   = TOP_HALF;
      
      
      if        (horizontal_half == RIGHT_HALF && vertical_half == TOP_HALF) { /* quadrant 1 */
         weight[*result_num] = (circ_radius - rad1)/(rad3-rad1);
      } else if (horizontal_half == LEFT_HALF  && vertical_half == TOP_HALF) { /* quadrant 2 */
         weight[*result_num] = (circ_radius - rad2)/(rad4-rad2);
      } else if (horizontal_half == LEFT_HALF  && vertical_half == BOTTOM_HALF) { /* quadrant 3 */
         weight[*result_num] = (circ_radius - rad3)/(rad1-rad3);
      } else if (horizontal_half == RIGHT_HALF && vertical_half == BOTTOM_HALF) { /* quadrant 4 */
         weight[*result_num] = (circ_radius - rad4)/(rad2-rad4);
      } else {
         weight[*result_num] = 0.5;
      }
      if (cuts_bottom || cuts_top || cuts_left || cuts_right) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }

   } // for  
   free(ind);
}

void KDTree_QueryCircleIntersectWeighted_Float(TKDTree* t,
                                 int* result_num, int* result_indicies, double *weight,
                                 double circ_radius, int ncells, 
                                 float *x, float *dx, float *y, float *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;
   
   double rad1, rad2, rad3, rad4;
   int cuts_bottom, cuts_top, cuts_left, cuts_right;
   int vertical_half, horizontal_half;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      cuts_bottom=0;
      cuts_top=0;
      cuts_left=0;
      cuts_right=0;
      if ((circ_radius < rad1 && circ_radius > rad2 ) ||
          (circ_radius > rad1 && circ_radius < rad2 ) ) {
         cuts_bottom=1;
      }
      if ((circ_radius < rad2 && circ_radius > rad3 ) ||
          (circ_radius > rad2 && circ_radius < rad3 ) ) {
         cuts_right=1;
      }
      if ((circ_radius < rad3 && circ_radius > rad4 ) ||
          (circ_radius > rad3 && circ_radius < rad4 ) ) {
         cuts_top=1;
      }
      if ((circ_radius < rad4 && circ_radius > rad1 ) ||
          (circ_radius > rad4 && circ_radius < rad1 ) ) {
         cuts_left=1;
      }
      
      horizontal_half=0;
      vertical_half=0;
      if (x[ii]+0.5*dx[ii] > 0.0) horizontal_half = RIGHT_HALF;
      if (y[ii]+0.5*dy[ii] > 0.0) vertical_half   = TOP_HALF;
      
      
      if        (horizontal_half == RIGHT_HALF && vertical_half == TOP_HALF) { /* quadrant 1 */
         weight[*result_num] = (circ_radius - rad1)/(rad3-rad1);
      } else if (horizontal_half == LEFT_HALF  && vertical_half == TOP_HALF) { /* quadrant 2 */
         weight[*result_num] = (circ_radius - rad2)/(rad4-rad2);
      } else if (horizontal_half == LEFT_HALF  && vertical_half == BOTTOM_HALF) { /* quadrant 3 */
         weight[*result_num] = (circ_radius - rad3)/(rad1-rad3);
      } else if (horizontal_half == RIGHT_HALF && vertical_half == BOTTOM_HALF) { /* quadrant 4 */
         weight[*result_num] = (circ_radius - rad4)/(rad2-rad4);
      } else {
         weight[*result_num] = 0.5;
      }
      if (cuts_bottom || cuts_top || cuts_left || cuts_right) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }

   } // for  
   free(ind);
}

void KDTree_QueryCircleInterior_Double(TKDTree* t,
                            int* result_num, int* result_indicies,
                            double circ_radius, int ncells, 
                            double *x, double *dx, double *y, double *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;
   
   double rad1, rad2, rad3, rad4;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      if ((circ_radius > rad1 || circ_radius > rad2 ) ||
          (circ_radius > rad3 || circ_radius > rad4 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }
   } // for  
   free(ind);
}

void KDTree_QueryCircleInterior_Float(TKDTree* t,
                            int* result_num, int* result_indicies,
                            double circ_radius, int ncells, 
                            float *x, float *dx, float *y, float *dy)
{
   assert(t && result_num && result_indicies && circ_radius);
   /* Build the k-D tree if necessary */
   if(!t->tree_built){
      //printf("BUILDING TREE... \n");
      //fflush(stdout);
      KDTree_CreateTree(t);
   }
   
   int nez;
   int *ind=(int *)malloc(ncells*sizeof(int));
   
   TBounds box;
   box.min.x = -circ_radius;
   box.max.x =  circ_radius;
   box.min.y = -circ_radius;
   box.max.y =  circ_radius;
   KDTree_QueryBoxIntersect(t, &nez, ind, &box);
   
   //for (int ic=0; ic<nez; ic++) {
   //   printf("box is ind[%d]=%d\n",ic,ind[ic]);
   //}
   
   /* Allocate the results array */
   *result_num = 0;
   
   double rad1, rad2, rad3, rad4;
   int ii;
   for (int i=0; i<nez; ++i){
      ii = ind[i];
      rad1 = sqrt( pow(x[ii],       2.0) + pow(y[ii],       2.0) );
      rad2 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii],       2.0) );
      rad3 = sqrt( pow(x[ii]+dx[ii],2.0) + pow(y[ii]+dy[ii],2.0) );
      rad4 = sqrt( pow(x[ii]       ,2.0) + pow(y[ii]+dy[ii],2.0) );
      
      if ((circ_radius > rad1 || circ_radius > rad2 ) ||
          (circ_radius > rad3 || circ_radius > rad4 ) ) {
         result_indicies[*result_num] = ind[i];
         (*result_num)++;
      }
   } // for  
   free(ind);
}



