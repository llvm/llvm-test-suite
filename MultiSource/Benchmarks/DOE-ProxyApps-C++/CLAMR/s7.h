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
#ifndef S7_H_
#define S7_H_

//#define _S7_DEBUG

#ifdef __cplusplus
extern "C"
{
#endif

   /*
    * Some S7 parameters.
    */

#define S7_OK   0 /* Successful return. */

   enum  S7_Datatype
   {
      S7_GENERIC8  = 0,
      S7_BYTE,
      S7_PACKED,

      S7_CHAR,
      S7_INT,
      S7_LONG,
      S7_LONG_LONG_INT,
      S7_FLOAT,
      S7_DOUBLE,

      S7_CHARACTER,
      S7_LOGICAL,
      S7_INTEGER4,
      S7_INTEGER8,
      S7_REAL4,
      S7_REAL8,

      S7_DATATYPE_MIN = S7_GENERIC8,
      S7_DATATYPE_MAX = S7_REAL8
   };


   void S7_Sort(
                void                   *array_in,
                const int              nsize,
                const enum S7_Datatype S7_datatype
                );

   void S7_Sort_2Arrays(
                        void *                 array_in1,
                        void *                 array_in2,
                        const int              nsize,
                        const enum S7_Datatype S7_datatype
                        );

   void S7_Index_Sort(
                      void *                 array_in,
                      const int              nsize,
                      const enum S7_Datatype S7_datatype,
                      int *                  index
                      );

   void S7_Indexi8_Sort(
                        void *                 array_in,
                        const int              nsize,
                        const enum S7_Datatype S7_datatype,
                        long *                 index
                        );


   void S7_Index_sort_real8(const int n,double array_in[],int index[]);
   void S7_Index_sort_int8(const int n,long long iarray_in[], int index[]);
   void S7_Index_sort_int4(const int n, int iarray_in[], int index[]);
   void S7_Index_sort_real8_int8(const int n,double array_in[],long long index[]);

   void S7_Index_sort_int8_int8(const int n,long long iarray_in[], long long index[]);
   void S7_Index_sort_int4_int8(const int n, int iarray_in[], long long index[]);
   void S7_Sort_real8(const int n,double array_in[]);
   void S7_Sort_int8(const int n,long long array_in[]);
   void S7_Sort_int4(const int n,int array_in[]);
   void S7_Sort_real8_real8(const int n,double array_in[],double array_in2[]);
   void S7_Sort_int8_int8(const int n,long long array_in[],long long array_in2[]);
   void S7_Sort_int4_int4(const int n,int array_in[],int array_in2[]);

   /*
    * End prototypes.
    */

   /*
    * remove typesafe linkage if compiling under c++
    */

#ifdef __cplusplus
}
#endif

#endif /* S7_H */
