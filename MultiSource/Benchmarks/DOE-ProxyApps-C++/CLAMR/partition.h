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
 * 
 */
#ifndef PARTITION_H
#define PARTITION_H

#include <vector>

#include "input.h"

using namespace std;

enum partition_method {
   ORIGINAL_ORDER,
   HILBERT_SORT,
   HILBERT_PARTITION,
   ZORDER
};

enum partition_measure {
   NO_PARTITION_MEASURE,
   WITH_DUPLICATES,
   WITHOUT_DUPLICATES,
   CVALUE,
   CSTARVALUE
};


void calc_distribution(int numpe, vector<int> &proc);
//void partition_cells(int numpe, vector<int> &proc, Mesh &mesh, enum partition_method method);

typedef void (*maptonorm)( double * , double * , void * );

extern "C" void hsfc2sort(
                const int      N ,     /* IN: Number of points */
                const double * X ,     /* IN: array of X-Coordinates */
                const double * Y ,     /* IN: array of Y-Coordinates */
                const int      ibase ,    /* IN: Stride for Y array */
                int          * Info ,  /* OUT: (1 <= LDInfo) [ HSFC ordering ]
                                  (2 <= LDInfo) [ HSFC index, #1 ]
                                  (3 <= LDInfo) [ HSFC index, #2 ] */
                int            LDInfo /* IN:  Leading dimension of Info */
                );

extern "C" void hsfc2part(
               const int      Level , /* IN: Background grid level of partitioning */
               const int      Limit , /* IN: Number of levels to consider for 'gaps' */
               const int      NPart , /* IN: Target number of partitions */
               const int      N ,     /* IN: Number of points */
               const double * X ,     /* IN: array of X-Coordinates */
               const double * Y ,     /* IN: array of Y-Coordinates */
               const int      ibase ,    /* IN: Base - 0 for C, 1 for Fortran */
                     int    * Info ,  /* IN:  Array of computational weights,
                                 OUT: (1 <= LDInfo) [ Partitioning ]
                                 (2 <= LDInfo) [ Adjusted HSFC ordering ]
                                 (3 <= LDInfo) [ Original HSFC index, #1 ]
                                 (4 <= LDInfo) [ Original HSFC index, #2 ] */
                     int      LDInfo );/* IN:  Leading dimension of Info */


#endif /* PARTITION_H */
