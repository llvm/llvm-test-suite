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
#include <stdio.h>
#include <stdlib.h>
#include "s7.h"

void S7_Sort(
             void *                 array_in,
             const int              nsize,
             const enum S7_Datatype S7_datatype
             )
{
   int n, child, parent, i;

   int qint;
   long qlong;
   long long qlonglong;
   float qfloat;
   double qdouble;

   int
   *int_data_ptr;
   long
   *long_data_ptr;
   long long
   *longlong_data_ptr;
   float
   *float_data_ptr;
   double
   *double_data_ptr;

   // Heapsort

   i=nsize/2;
   n = nsize;

   switch (S7_datatype){
      case S7_INTEGER4:
      case S7_INT:
         int_data_ptr = (int *)array_in;

         for (;;) {
            if (i > 0) {
               qint=int_data_ptr[--i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {
                  break; // End the sort here!
               } // if n
               qint=int_data_ptr[n];
               int_data_ptr[n]=int_data_ptr[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && int_data_ptr[child+1] > int_data_ptr[child]) child++;
               if (int_data_ptr[child] > qint) {
                  int_data_ptr[parent] = int_data_ptr[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break; // Break out of sift while loop
               } // else
            } // while
            int_data_ptr[parent]=qint;
         } // for

         break;

      case S7_LONG:
         long_data_ptr = (long *)array_in;

         for (;;) {
            if (i > 0) {
               qlong=long_data_ptr[--i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {
                  break; // End the sort here!
               } // if n
               qlong=long_data_ptr[n];
               long_data_ptr[n]=long_data_ptr[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && long_data_ptr[child+1] > long_data_ptr[child]) child++;
               if (long_data_ptr[child] > qlong) {
                  long_data_ptr[parent] = long_data_ptr[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break; // Break out of sift while loop
               } // else
            } // while
            long_data_ptr[parent]=qlong;
         } // for

         break;

      case S7_LONG_LONG_INT:
      case S7_INTEGER8:
         longlong_data_ptr = (long long *)array_in;

         for (;;) {
            if (i > 0) {
               qlonglong=longlong_data_ptr[--i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {
                  break; // End the sort here!
               } // if n
               qlonglong=longlong_data_ptr[n];
               longlong_data_ptr[n]=longlong_data_ptr[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && longlong_data_ptr[child+1] > longlong_data_ptr[child]) child++;
               if (longlong_data_ptr[child] > qlonglong) {
                  longlong_data_ptr[parent] = longlong_data_ptr[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break; // Break out of sift while loop
               } // else
            } // while
            longlong_data_ptr[parent]=qlonglong;
         } // for

         break;

      case S7_FLOAT:
      case S7_REAL4:
         float_data_ptr = (float *)array_in;

         for (;;) {
            if (i > 0) {
               qfloat=float_data_ptr[--i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {
                  break; // End the sort here!
               } // if n
               qfloat=float_data_ptr[n];
               float_data_ptr[n]=float_data_ptr[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && float_data_ptr[child+1] > float_data_ptr[child]) child++;
               if (float_data_ptr[child] > qfloat) {
                  float_data_ptr[parent] = float_data_ptr[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break; // Break out of sift while loop
               } // else
            } // while
            float_data_ptr[parent]=qfloat;
         } // for

         break;

      case S7_DOUBLE:
      case S7_REAL8:
         double_data_ptr = (double *)array_in;

         for (;;) {
            if (i > 0) {
               qdouble=double_data_ptr[--i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {
                  break; // End the sort here!
               } // if n
               qdouble=double_data_ptr[n];
               double_data_ptr[n]=double_data_ptr[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && double_data_ptr[child+1] > double_data_ptr[child]) child++;
               if (double_data_ptr[child] > qdouble) {
                  double_data_ptr[parent] = double_data_ptr[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break; // Break out of sift while loop
               } // else
            } // while
            double_data_ptr[parent]=qdouble;
         } // for

         break;

      default:
         printf("Error -- S7_Datatype not supported in S7_Sort\n");
         exit(1);
         break;

   }
}


void S7_Sort_2Arrays(
                     void *                 array_in1,
                     void *                 array_in2,
                     const int              nsize,
                     const enum S7_Datatype S7_datatype
                     )
{
   int n, child, parent, i;

   int qint1, qint2;
   long qlong1, qlong2;
   long long qlonglong1, qlonglong2;
   float qfloat1, qfloat2;
   double qdouble1, qdouble2;

   int
   *int_data_ptr1, *int_data_ptr2;
   long
   *long_data_ptr1, *long_data_ptr2;
   long long
   *longlong_data_ptr1, *longlong_data_ptr2;
   float
   *float_data_ptr1, *float_data_ptr2;
   double
   *double_data_ptr1, *double_data_ptr2;

   // Heapsort

   i=nsize/2;
   n = nsize;

   switch (S7_datatype){
      case S7_INTEGER4:
      case S7_INT:
         int_data_ptr1 = (int *)array_in1;
         int_data_ptr2 = (int *)array_in2;

         for (;;) {
            if (i > 0) {
               qint1=int_data_ptr1[--i];
               qint2=int_data_ptr2[i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return; // End of sort
               } // if n
               qint1=int_data_ptr1[n];
               qint2=int_data_ptr2[n];
               int_data_ptr1[n]=int_data_ptr1[0];
               int_data_ptr2[n]=int_data_ptr2[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && int_data_ptr1[child+1] > int_data_ptr1[child]) child++;
               if (int_data_ptr1[child] > qint1) {
                  int_data_ptr1[parent] = int_data_ptr1[child];
                  int_data_ptr2[parent] = int_data_ptr2[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            int_data_ptr1[parent]=qint1;
            int_data_ptr2[parent]=qint2;
         } // for
         break;

      case S7_LONG:
         long_data_ptr1 = (long *)array_in1;
         long_data_ptr2 = (long *)array_in2;

         for (;;) {
            if (i > 0) {
               qlong1=long_data_ptr1[--i];
               qlong2=long_data_ptr2[i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return; // End of sort
               } // if n
               qlong1=long_data_ptr1[n];
               qlong2=long_data_ptr2[n];
               long_data_ptr1[n]=long_data_ptr1[0];
               long_data_ptr2[n]=long_data_ptr2[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && long_data_ptr1[child+1] > long_data_ptr1[child]) child++;
               if (long_data_ptr1[child] > qlong1) {
                  long_data_ptr1[parent] = long_data_ptr1[child];
                  long_data_ptr2[parent] = long_data_ptr2[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            long_data_ptr1[parent]=qlong1;
            long_data_ptr2[parent]=qlong2;
         } // for
         break;

      case S7_LONG_LONG_INT:
      case S7_INTEGER8:
         longlong_data_ptr1 = (long long *)array_in1;
         longlong_data_ptr2 = (long long *)array_in2;

         for (;;) {
            if (i > 0) {
               qlonglong1=longlong_data_ptr1[--i];
               qlonglong2=longlong_data_ptr2[i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return; // End of sort
               } // if n
               qlonglong1=longlong_data_ptr1[n];
               qlonglong2=longlong_data_ptr2[n];
               longlong_data_ptr1[n]=longlong_data_ptr1[0];
               longlong_data_ptr2[n]=longlong_data_ptr2[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && longlong_data_ptr1[child+1] > longlong_data_ptr1[child]) child++;
               if (longlong_data_ptr1[child] > qlonglong1) {
                  longlong_data_ptr1[parent] = longlong_data_ptr1[child];
                  longlong_data_ptr2[parent] = longlong_data_ptr2[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            longlong_data_ptr1[parent]=qlonglong1;
            longlong_data_ptr2[parent]=qlonglong2;
         } // for
         break;

      case S7_FLOAT:
      case S7_REAL4:
         float_data_ptr1 = (float *)array_in1;
         float_data_ptr2 = (float *)array_in2;

         for (;;) {
            if (i > 0) {
               qfloat1=float_data_ptr1[--i];
               qfloat2=float_data_ptr2[i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return; // End of sort
               } // if n
               qfloat1=float_data_ptr1[n];
               qfloat2=float_data_ptr2[n];
               float_data_ptr1[n]=float_data_ptr1[0];
               float_data_ptr2[n]=float_data_ptr2[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && float_data_ptr1[child+1] > float_data_ptr1[child]) child++;
               if (float_data_ptr1[child] > qfloat1) {
                  float_data_ptr1[parent] = float_data_ptr1[child];
                  float_data_ptr2[parent] = float_data_ptr2[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            float_data_ptr1[parent]=qfloat1;
            float_data_ptr2[parent]=qfloat2;
         } // for
         break;

      case S7_DOUBLE:
      case S7_REAL8:
         double_data_ptr1 = (double *)array_in1;
         double_data_ptr2 = (double *)array_in2;

         for (;;) {
            if (i > 0) {
               qdouble1=double_data_ptr1[--i];
               qdouble2=double_data_ptr2[i];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return; // End of sort
               } // if n
               qdouble1=double_data_ptr1[n];
               qdouble2=double_data_ptr2[n];
               double_data_ptr1[n]=double_data_ptr1[0];
               double_data_ptr2[n]=double_data_ptr2[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && double_data_ptr1[child+1] > double_data_ptr1[child]) child++;
               if (double_data_ptr1[child] > qdouble1) {
                  double_data_ptr1[parent] = double_data_ptr1[child];
                  double_data_ptr2[parent] = double_data_ptr2[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            double_data_ptr1[parent]=qdouble1;
            double_data_ptr2[parent]=qdouble2;
         } // for
         break;

      default:
         printf("Error -- S7_Datatype not supported in S7_Sort\n");
         exit(1);
         break;
   }
}





void S7_Index_Sort(
                   void *                 array_in,
                   const int              nsize,
                   const enum S7_Datatype S7_datatype,
                   int *                  index
                   )
{
   int n, j, child, parent, i;
   int indext;

   int qint;
   long qlong;
   long long qlonglong;
   float qfloat;
   double qdouble;

   int
   *int_data_ptr;
   long
   *long_data_ptr;
   long long
   *longlong_data_ptr;
   float
   *float_data_ptr;
   double
   *double_data_ptr;

   // Heapsort

   // Initialize array with consecutive integers
   for (j=0; j<nsize; j++) index[j]=j;

   i=nsize/2;
   n = nsize;

   switch (S7_datatype){
      case S7_INTEGER4:
      case S7_INT:
         int_data_ptr = (int *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qint=int_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qint=int_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && int_data_ptr[index[child+1]] > int_data_ptr[index[child]]) child++;
               if (int_data_ptr[index[child]] > qint) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_LONG:
         long_data_ptr = (long *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qlong=long_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qlong=long_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && long_data_ptr[index[child+1]] > long_data_ptr[index[child]]) child++;
               if (long_data_ptr[index[child]] > qlong) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_LONG_LONG_INT:
      case S7_INTEGER8:
         longlong_data_ptr = (long long *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qlonglong=longlong_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qlonglong=longlong_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && longlong_data_ptr[index[child+1]] > longlong_data_ptr[index[child]]) child++;
               if (longlong_data_ptr[index[child]] > qlonglong) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_FLOAT:
      case S7_REAL4:
         float_data_ptr = (float *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qfloat=float_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qfloat=float_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && float_data_ptr[index[child+1]] > float_data_ptr[index[child]]) child++;
               if (float_data_ptr[index[child]] > qfloat) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;


      case S7_DOUBLE:
      case S7_REAL8:
         double_data_ptr = (double *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qdouble=double_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qdouble=double_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && double_data_ptr[index[child+1]] > double_data_ptr[index[child]]) child++;
               if (double_data_ptr[index[child]] > qdouble) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      default:
         printf("Error -- S7_Datatype not supported in S7_Index_Sort\n");
         exit(1);
         break;

   }
}

void S7_Indexi8_Sort(
                     void *                 array_in,
                     const int              nsize,
                     const enum S7_Datatype S7_datatype,
                     long *                 index
                     )
{
   int n, j, child, parent, i;
   long indext;

   int qint;
   long qlong;
   long long qlonglong;
   float qfloat;
   double qdouble;

   int
   *int_data_ptr;
   long
   *long_data_ptr;
   long long
   *longlong_data_ptr;
   float
   *float_data_ptr;
   double
   *double_data_ptr;

   // Heapsort

   // Initialize array with consecutive integers
   for (j=0; j<nsize; j++) index[j]=j;

   i=nsize/2;
   n = nsize;

   switch (S7_datatype){
      case S7_INTEGER4:
      case S7_INT:
         int_data_ptr = (int *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qint=int_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qint=int_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && int_data_ptr[index[child+1]] > int_data_ptr[index[child]]) child++;
               if (int_data_ptr[index[child]] > qint) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_LONG:
         long_data_ptr = (long *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qlong=long_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qlong=long_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && long_data_ptr[index[child+1]] > long_data_ptr[index[child]]) child++;
               if (long_data_ptr[index[child]] > qlong) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_LONG_LONG_INT:
      case S7_INTEGER8:
         longlong_data_ptr = (long long *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qlonglong=longlong_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qlonglong=longlong_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && longlong_data_ptr[index[child+1]] > longlong_data_ptr[index[child]]) child++;
               if (longlong_data_ptr[index[child]] > qlonglong) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      case S7_FLOAT:
      case S7_REAL4:
         float_data_ptr = (float *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qfloat=float_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qfloat=float_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && float_data_ptr[index[child+1]] > float_data_ptr[index[child]]) child++;
               if (float_data_ptr[index[child]] > qfloat) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;


      case S7_DOUBLE:
      case S7_REAL8:
         double_data_ptr = (double *)array_in;

         for (;;) {
            if (i > 0) {
               indext=index[--i];
               qdouble=double_data_ptr[indext];
            } // if i > 0
            else {
               n--;
               if (n == 0) {

                  return;
               } // if n
               indext=index[n];
               qdouble=double_data_ptr[indext];
               index[n]=index[0];
            } // else

            parent=i;
            child = i*2 + 1;
            while (child < n) {
               if (child +1 < n && double_data_ptr[index[child+1]] > double_data_ptr[index[child]]) child++;
               if (double_data_ptr[index[child]] > qdouble) {
                  index[parent] = index[child];
                  parent=child;
                  child = parent*2 + 1;
               } // if q
               else {
                  break;
               } // else
            } // while
            index[parent]=indext;
         } // for
         break;

      default:
         printf("Error -- S7_Datatype not supported in S7_Indexi8_Sort\n");
         exit(1);
         break;

   }
}
