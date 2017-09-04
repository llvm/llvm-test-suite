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

#include <sys/types.h>
#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>
#include "genmalloc.h"

#ifndef DEBUG
#define DEBUG 0
#endif

double ***gentrimatrix_double_p(int knum, int jnum, int inum, const char *file, const int line);
int ***gentrimatrix_int_p(int knum, int jnum, int inum, const char *file, const int line);

SLIST_HEAD(slist_genmalloc_memory_head, genmalloc_memory_entry) genmalloc_memory_head = SLIST_HEAD_INITIALIZER(genmalloc_memory_head);
struct slist_genmalloc_memory_head *genmalloc_memory_headp;
struct genmalloc_memory_entry {
   void *mem_ptr;
   size_t mem_size;
   SLIST_ENTRY(genmalloc_memory_entry) genmalloc_memory_entries;
} *genmalloc_memory_item;

void *genvector_p(int inum, size_t elsize, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   void *out;
   size_t mem_size;

   mem_size = inum*elsize;
   out      = (void *)calloc((size_t)inum, elsize);
   genmalloc_memory_add(out, mem_size);

   return (out);
}

void genvectorfree_p(void *var, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   genmalloc_memory_remove(var);
}

void **genmatrix_p(int jnum, int inum, size_t elsize, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   void **out;
   size_t mem_size;
  
   mem_size = jnum*sizeof(void *);
   out      = (void **)malloc(mem_size);
   genmalloc_memory_add(out, mem_size);
  
   mem_size = jnum*inum*elsize;
   out[0]    = (void *)calloc((size_t)jnum*(size_t)inum, elsize);
   genmalloc_memory_add(out[0], mem_size);
  
   for (int i = 1; i < jnum; i++) {
      out[i] = out[i-1] + inum*elsize;
   }
  
   return (out);
}

void genmatrixfree_p(void **var, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   genmalloc_memory_remove(var[0]);
   genmalloc_memory_remove(var);
}

void ***gentrimatrix_p(int knum, int jnum, int inum, size_t elsize, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   void ***out = NULL;
   if (elsize == 8) {
      out = (void ***)gentrimatrix_double_p(knum, jnum, inum, file, line);
   } else if (elsize == 4) {
      out = (void ***)gentrimatrix_int_p(knum, jnum, inum, file, line);
   } else {
      printf("Error -- element size not supported in genmalloc for call at %s line %d\n",file,line);
   }

   return(out);
}

double ***gentrimatrix_double_p(int knum, int jnum, int inum, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   double ***out;
   size_t mem_size;
   const size_t elsize = 8;

   mem_size  = knum*sizeof(void **);
   out       = (double ***)malloc(mem_size);
   genmalloc_memory_add(out, mem_size);

   mem_size  = knum*jnum*sizeof(void *);
   out[0]    = (double **) malloc(mem_size);
   genmalloc_memory_add(out[0], mem_size);

   size_t nelems = knum*jnum*inum;
   mem_size  = nelems*elsize;
   out[0][0] = (void *)calloc(nelems, elsize);
   genmalloc_memory_add(out[0][0], mem_size);

   for (int k = 0; k < knum; k++)
   {
      if (k > 0)
      {
         out[k] = out[k-1] + jnum;
         out[k][0] = out[k-1][0] + (jnum*inum);
      }

      for (int j = 1; j < jnum; j++)
      {
         out[k][j] = out[k][j-1] + inum;
      }
   }

   return (out);
}

int ***gentrimatrix_int_p(int knum, int jnum, int inum, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   int ***out;
   size_t mem_size;
   const size_t elsize = 4;

   mem_size  = knum*sizeof(void **);
   out       = (int ***)malloc(mem_size);
   genmalloc_memory_add(out, mem_size);

   mem_size  = knum*jnum*sizeof(void *);
   out[0]    = (int **) malloc(mem_size);
   genmalloc_memory_add(out[0], mem_size);

   size_t nelems = knum*jnum*inum;
   mem_size  = nelems*elsize;
   out[0][0] = (void *)calloc(nelems, elsize);
   genmalloc_memory_add(out[0][0], mem_size);

   for (int k = 0; k < knum; k++)
   {
      if (k > 0)
      {
         out[k] = out[k-1] + jnum;
         out[k][0] = out[k-1][0] + (jnum*inum);
      }

      for (int j = 1; j < jnum; j++)
      {
         out[k][j] = out[k][j-1] + inum;
      }
   }

   return (out);
}

void gentrimatrixfree_p(void ***var, const char *file, const int line)
{
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   genmalloc_memory_remove(var[0][0]);
   genmalloc_memory_remove(var[0]);
   genmalloc_memory_remove(var);
}

void *genmalloc_memory_add_p(void *malloc_mem_ptr, size_t size, const char *file, const int line){
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   if (SLIST_EMPTY(&genmalloc_memory_head)) SLIST_INIT(&genmalloc_memory_head);

   genmalloc_memory_item = malloc(sizeof(struct genmalloc_memory_entry));
   genmalloc_memory_item->mem_ptr = malloc_mem_ptr;
   genmalloc_memory_item->mem_size = size;
   if (DEBUG) printf("GENMALLOC_MEMORY_ADD: DEBUG -- malloc memory pointer is %p called from file %s line %d\n",malloc_mem_ptr,file,line);

   SLIST_INSERT_HEAD(&genmalloc_memory_head, genmalloc_memory_item, genmalloc_memory_entries);

   return(malloc_mem_ptr);
}

void genmalloc_memory_remove_p(void *malloc_mem_ptr, const char *file, const int line){
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   SLIST_FOREACH(genmalloc_memory_item, &genmalloc_memory_head, genmalloc_memory_entries){
      if (genmalloc_memory_item->mem_ptr == malloc_mem_ptr) {
         if (DEBUG) printf("GENMALLOC_MEMORY_REMOVE: DEBUG -- freeing malloc memory pointer %p called from file %s line %d\n",malloc_mem_ptr,file,line);
         free(malloc_mem_ptr);
         SLIST_REMOVE(&genmalloc_memory_head, genmalloc_memory_item, genmalloc_memory_entry, genmalloc_memory_entries);
         free(genmalloc_memory_item);
         break;
      }
   }
}

void genmem_free_all_p(const char *file, const int line){
   // Just to get rid of warning
   if (1 == 2) printf("Warning file %s line %d\n", file, line);

   while (!SLIST_EMPTY(&genmalloc_memory_head)) {
      genmalloc_memory_item = SLIST_FIRST(&genmalloc_memory_head);
      if (DEBUG) printf("GENMEM_FREE_ALL: DEBUG -- freeing genmalloc memory %p called from file %s line %d\n",genmalloc_memory_item->mem_ptr,file,line);
      free(genmalloc_memory_item->mem_ptr);
      SLIST_REMOVE_HEAD(&genmalloc_memory_head, genmalloc_memory_entries);
      free(genmalloc_memory_item);
   }
}

