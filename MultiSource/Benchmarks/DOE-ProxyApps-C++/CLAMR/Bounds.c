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
#include "Bounds.h"

#define MEMCPY(s,d,n,t) {memcpy((void*)d, (void*)s, n * sizeof(t)); }
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void Bounds_Copy(TBounds* src, TBounds* dest) {
   assert(src && dest);
   MEMCPY(src, dest, 1, TBounds);
}

void Bounds_Infinite(TBounds* b){
   assert(b);
   b->min.x = POSITIVE_INFINITY;
   b->min.y = POSITIVE_INFINITY;
   b->max.x = NEGATIVE_INFINITY;
   b->max.y = NEGATIVE_INFINITY;
}

void Bounds_AddBounds(TBounds* b, TBounds* add) {
   assert(b && add);
   b->min.x = MIN(b->min.x, add->min.x);
   b->min.y = MIN(b->min.y, add->min.y);
   b->max.x = MAX(b->max.x, add->max.x);
   b->max.y = MAX(b->max.y, add->max.y);
}

void Bounds_AddEpsilon(TBounds* b, double add) {
   assert(b);
   b->min.x = b->min.x - add;
   b->min.y = b->min.y - add;
   b->max.x = b->max.x + add;
   b->max.y = b->max.y + add;
}

bool Bounds_IsOverlappingBounds(TBounds* b, TBounds* tst) {
   assert(b && tst);
   if((tst->max.x < b->min.x) || (tst->min.x > b->max.x))
      return(false);
   if((tst->max.y < b->min.y) || (tst->min.y > b->max.y))
      return(false);
   return(true);
}

double Bounds_WidthAxis(TBounds* b, unsigned int axis)
{
   double width;
   
   assert(b);
   if(axis == XAXIS)
      width = b->max.x - b->min.x;
   else if(axis == YAXIS)
      width = b->max.y - b->min.y;
   else
      assert(NULL);
   return(width);
}

double Bounds_CenterAxis(TBounds* b, unsigned int axis)
{
   double center;
   
   assert(b);
   if(axis == XAXIS)
      center = (b->min.x + b->max.x) * 0.5;
   else if(axis == YAXIS)
      center = (b->min.y + b->max.y) * 0.5;
   else
      assert(NULL);
   return(center);
}
