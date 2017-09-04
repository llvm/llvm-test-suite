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
#include <math.h>
#include "s7.h"
#include "zorder.h"

#define DEBUG 0

void calc_zorder(int size, int *i, int *j, int *level, int levmx, int ibase, int *z_index, int *z_order)
{   unsigned long long ibit,   //   Bitwise representation of x-index.
                       jbit;   //   Bitwise representation of y-index.

   //   Convert the indices to a bitwise representation.
   int ic;
   for (ic = 0; ic < size; ic++)
   {  if (level[ic] < 0) continue;
      ibit = index_to_bit(i[ic], level[ic], levmx, ibase);
      jbit = index_to_bit(j[ic], level[ic], levmx, ibase);
      z_index[ic] = twobit_to_index(ibit, jbit);
      z_order[ic] = ic; }

   //   Sort the z-ordered indices.
   S7_Index_Sort(z_index, size, S7_INT, z_order);

   //   Output ordered mesh information.
   if (DEBUG)
   {   printf("orig index   i     j     lev     ibit       jbit       ijbit      z index  z order\n");
      for (ic=0; ic<size; ic++){
         printf(" %6d   %4d  %4d   %4d   ",ic+1, j[ic], i[ic], level[ic]);
         printbits(index_to_bit(j[ic], level[ic], levmx, ibase));
         printf("   ");
         printbits(index_to_bit(i[ic], level[ic], levmx, ibase));
         printf("   ");
         printbits( index_to_bit(i[ic], level[ic], levmx, ibase)
               | (index_to_bit(j[ic], level[ic], levmx, ibase)
               << 1));
         printf("   %6d     %5d\n",z_index[ic], z_order[ic]); } } }

unsigned long long index_to_bit(unsigned long long index,
                        int lev,
                        int levmx,
                        int ibase)
{   static const unsigned long long B[] =
      {0x55555555,  /* 01010101010101010101010101010101 */
       0x33333333,  /* 00110011001100110011001100110011 */
       0x0F0F0F0F,  /* 00001111000011110000111100001111 */
       0x00FF00FF,  /* 00000000111111110000000011111111 */
       0x0000FFFF}; /* 00000000000000001111111111111111 */
   static const unsigned long long S[] = {1, 2, 4, 8, 16};

   //   Convert the index to a bit representation.
   unsigned long long ii, ibit;
   ii = index - ibase;
   if (lev < levmx)
   {   ii = ii * pow((double)2, (double)(levmx - lev)); }
   ibit = ii;
   ibit = (ibit | (ibit << S[3])) & B[3];
   ibit = (ibit | (ibit << S[2])) & B[2];
   ibit = (ibit | (ibit << S[1])) & B[1];
   ibit = (ibit | (ibit << S[0])) & B[0];

   return (ibit); }

unsigned long long twobit_to_index(unsigned long long ibit,
                           unsigned long long jbit)
{   unsigned long long ijbit;
   return (ijbit = ibit | (jbit << 1)); }

//   Print n as a binary number.
void printbits(int n)
{  
   int i, step;

   if (0 == n)
   {   //   For simplicity's sake, treat 0 as a special case.
      printf("00000000");
      return; }

   i      =  1 << (sizeof(n) * 8 - 1);
   step   = -1;   //   Only print the relevant digits.
   step  >>=  8;   //   Print in groups of four.
   while (step >= n)
   {   i    >>= 8;
      step >>= 8; }

   //   At this point, i is the smallest power of two larger or equal to n.
   while (i > 0)
   {   if (n & i)
         printf("1");
      else
         printf("0");
      i >>= 1; } }

