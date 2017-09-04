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
 * 
 *  Implements a 2-dimensional k-D tree. One begins to use the k-D tree by
 *  adding the bounding box of geometric "elements" to the tree structure
 *  through a call to "KDTreeAddElement". Every element should be of the same
 *  type, but could be a single point, a line segment, triangles, etc. Once
 *  all the element bounding boxes have been added, the user of the structure
 *  may make queries against the tree. The actual tree is constructed lazily
 *  when an actual query occurs on the structure.
 *
 *  This version only has one query -- intersection of a box with the elements
 *  and a set of "candidate" elements are returned. The candidates are identified
 *  by an index number (0, ...) signifying the order in which the element was
 *  added to the tree. It is up to the calling code to do additional processing
 *  based on the type of element being used to determine "real" intersections.
 *
 *  The process of actually building the tree takes "n log n" time. Queries 
 *  take "log n" time.
 *
 */

#ifndef _KDTree_
#define _KDTree_

#ifdef __cplusplus
extern "C"
{
#endif
  

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "Globals.h"
#include "Bounds.h"
   
#define LEFT_HALF   0
#define RIGHT_HALF  1
#define BOTTOM_HALF 0
#define TOP_HALF    1   

typedef struct {
   TBounds extent;
   int elements_num, elements_allocated;
   TBounds* elements;
   bool tree_built;
   int tree_size;
   TBounds* tree_safety_boxes;
   int * tree_link;
} TKDTree;

extern void KDTree_Initialize(TKDTree *t);
extern void KDTree_Finalize(TKDTree *t);
extern void KDTree_Destroy(TKDTree* t);
extern void KDTree_AddElement(TKDTree* t, TBounds* add);
extern void KDTree_CreateTree(TKDTree* t);
extern void KDTree_QueryBoxIntersect(TKDTree* t,
                                     int* result_num, int* result_indicies,
                                     TBounds* box);

void KDTree_QueryCircleIntersect_Double(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double radius, int ncells, 
                                 double *x, double *dx, double *y, double *dy);
void KDTree_QueryCircleIntersect_Float(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double radius, int ncells, 
                                 float *x, float *dx, float *y, float *dy);

void KDTree_QueryCircleIntersectWeighted_Double(TKDTree* t,
                                 int* result_num, int* result_indicies, double *weight,
                                 double circ_radius, int ncells, 
                                 double *x, double *dx, double *y, double *dy);
void KDTree_QueryCircleIntersectWeighted_Float(TKDTree* t,
                                 int* result_num, int* result_indicies, double *weight,
                                 double circ_radius, int ncells, 
                                 float *x, float *dx, float *y, float *dy);

void KDTree_QueryCircleInterior_Double(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double circ_radius, int ncells, 
                                 double *x, double *dx, double *y, double *dy);
void KDTree_QueryCircleInterior_Float(TKDTree* t,
                                 int* result_num, int* result_indicies,
                                 double circ_radius, int ncells, 
                                 float *x, float *dx, float *y, float *dy);
   
#ifdef __cplusplus
}
#endif

#endif
