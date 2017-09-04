/*
 *  Copyright (c) 2011-2014, Los Alamos National Security, LLC.
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

// SKG TODO op realloc (similar to managed)

#undef HAVE_OPENCL

#include "MallocPlus.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#ifdef HAVE_OPENCL
#include "ezcl/ezcl.h"
#endif

#ifndef DEBUG
#define DEBUG 0
#endif
#define WARNING_SUPPRESSION 0

#ifdef HAVE_CL_DOUBLE
#ifdef HAVE_OPENCL
typedef cl_double2  cl_real2;
#endif
#else
#ifdef HAVE_OPENCL
typedef cl_float2   cl_real2;
#endif
#endif

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifndef SWAP_PTR
#define SWAP_PTR(xnew,xold,xtmp) (xtmp=xnew, xnew=xold, xold=xtmp)
#endif

typedef unsigned int uint;
map<void *,malloc_plus_memory_entry*>::iterator it_save, it_end;
map<string, malloc_plus_memory_entry*, cmp_str>::iterator it_save_by_name, it_end_by_name;

#if defined(HAVE_MPI)
void
MallocPlus::pinit(MPI_Comm smComm, std::size_t memPoolSize)
{
#if defined(HAVE_J7)
    try {
        j7 = new J7(smComm, memPoolSize);
    }
    catch(...) {
        std::cerr << "*** pinit failure ***" << std::endl;
        throw;
    }
#else
    // Just to suppress compiler warnings
    if (WARNING_SUPPRESSION) printf("DEBUG memPoolSize = %lu smComm = %p\n",memPoolSize,smComm);
#endif
}

void
MallocPlus::pfini(void)
{
#if defined(HAVE_J7)
    try {
        delete j7;
        j7 = NULL;
    }
    catch(...) {
        std::cerr << "*** pfini failure ***" << std::endl;
        throw;
    }
#endif
}
#endif // if defined(HAVE_MPI)

void *MallocPlus::memory_malloc(size_t nelem, size_t elsize, const char *name, int flags){
   malloc_plus_memory_entry *memory_item = (malloc_plus_memory_entry *)malloc(sizeof(malloc_plus_memory_entry));

   memory_item->mem_nelem    = (size_t *)malloc(1*sizeof(size_t));
   memory_item->mem_nelem[0] = nelem;
   memory_item->mem_ndims    = 1;
   memory_item->mem_elsize   = elsize;
   memory_item->mem_flags    = flags;

   // allocate memory on the accelerator if flag is set
   if ((flags & DEVICE_REGULAR_MEMORY) != 0){
#ifdef HAVE_OPENCL
      cl_context context = ezcl_get_context();
      memory_item->mem_capacity = nelem;
      memory_item->mem_ptr      = ezcl_device_memory_malloc(context, NULL, name, nelem, elsize, CL_MEM_READ_WRITE, 0);
#endif
   }
   // Managed memory allocates extra space and expands as necessary to reduce allocations
   else if ((flags & HOST_MANAGED_MEMORY) != 0){
      memory_item->mem_capacity = 2 * nelem;
      memory_item->mem_ptr      = malloc(2* nelem*elsize);
   }
#ifdef HAVE_J7
   // experimental shared memory allocation
   else if (flags & LOAD_BALANCE_MEMORY) {
      memory_item->mem_capacity = nelem;
      memory_item->mem_ptr      = j7->memAlloc(nelem * elsize);
   }
#endif
   // Just regular memory allocation
   else {
      memory_item->mem_capacity = nelem;
      memory_item->mem_ptr      = malloc(nelem*elsize);
   }

   memory_item->mem_name = strdup(name); // Mallocs memory for copy

   //printf("MALLOC_PLUS_MEMORY_MALLOC: DEBUG -- malloc plus memory pointer for :%s: is %p nelements %ld elsize is %ld flags %d\n",memory_item->mem_name,memory_item->mem_ptr,memory_item->mem_nelem[0],memory_item->mem_elsize,memory_item->mem_flags);

   // Insert entry into dictionary -- two versions, one by name and another by pointer address
   memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(name, memory_item) );
   memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(memory_item->mem_ptr, memory_item) );

   if (DEBUG) printf("MALLOC_PLUS_MEMORY_MALLOC: DEBUG -- malloc plus memory pointer for :%s: is %p nelements %ld elsize is %ld\n",memory_item->mem_name,memory_item->mem_ptr,memory_item->mem_nelem[0],memory_item->mem_elsize);

   // return the pointer for use by the calling routine
   return(memory_item->mem_ptr);
}

void *MallocPlus::memory_realloc(size_t nelem, void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);
   void *mem_ptr=NULL;

   if (it != memory_ptr_dict.end() ){
      // "second" will be the pointer to the memory entry data structure -- the value
      // associated with the key
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REALLOC: DEBUG -- reallocated memory pointer %p\n",memory_item->mem_ptr);

      // memory pointer will probably change, so delete the dictionary entry
      // named dictionary entry does not need to change; the pointer in the data structure
      //    will just be updated, but the pointer to the memory entry data structure
      //    will be the same
      memory_ptr_dict.erase(it);

      if (memory_item->mem_flags & HOST_MANAGED_MEMORY){
         // Check to see if memory needs to be expanded
         if (nelem > memory_item->mem_capacity) {
            // Need to realloc memory. Allocate extra for growth of array.
            mem_ptr=realloc(memory_item->mem_ptr, 2*nelem*memory_item->mem_elsize);
            memory_item->mem_capacity = 2*nelem;
            memory_item->mem_nelem[0] = nelem;
            memory_item->mem_ptr      = mem_ptr;
         } else {
            // Just move size to use more of memory buffer
            memory_item->mem_nelem[0] = nelem;
         }
      }
#ifdef HAVE_J7
      else if (memory_item->mem_flags & LOAD_BALANCE_MEMORY) {
         mem_ptr = j7->memRealloc(memory_item->mem_ptr, nelem * memory_item->mem_elsize);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
      }
#endif
      else {
         mem_ptr=realloc(memory_item->mem_ptr, nelem*memory_item->mem_elsize);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
      }

      // Put the pointer entry back into the dictionary
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(memory_item->mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(mem_ptr);
}

void *MallocPlus::memory_realloc(size_t nelem, const char *name){
   map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(name);
   void *mem_ptr=NULL;

   if (it != memory_name_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REALLOC: DEBUG -- "
                           "reallocated memory pointer %p\n",memory_item->mem_ptr);

      // Need to get the iterator for the pointer entry; the one above is for the name entry
      map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(memory_item->mem_ptr);
      memory_ptr_dict.erase(it);

      if (memory_item->mem_flags & HOST_MANAGED_MEMORY) {
         // Check to see if memory needs to be expanded
         if (nelem > memory_item->mem_capacity) {
            // Need to realloc memory. Allocate extra for growth of array.
            mem_ptr=realloc(memory_item->mem_ptr, 2*nelem*memory_item->mem_elsize);
            memory_item->mem_capacity = 2*nelem;
            memory_item->mem_nelem[0] = nelem;
            memory_item->mem_ptr      = mem_ptr;
         } else {
            // Just move size to use more of memory buffer
            memory_item->mem_nelem[0] = nelem;
         }
      }
#ifdef HAVE_J7
      else if (memory_item->mem_flags & LOAD_BALANCE_MEMORY) {
         mem_ptr = j7->memRealloc(memory_item->mem_ptr, nelem * memory_item->mem_elsize);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
      }
#endif
      else {
         //memory_name_dict.erase(it);
         mem_ptr=realloc(memory_item->mem_ptr, nelem*memory_item->mem_elsize);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
         //memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(name, memory_item) );
      }

      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(memory_item->mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory named %s not found\n",name);
   }

   return(mem_ptr);
}

void *MallocPlus::memory_request(size_t new_capacity, void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);
   void *mem_ptr=NULL;

   if (it != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REQUEST: DEBUG -- reallocated memory pointer %p\n",memory_item->mem_ptr);
      memory_ptr_dict.erase(it);
      mem_ptr=realloc(memory_item->mem_ptr, new_capacity*memory_item->mem_elsize);
      memory_item->mem_capacity = new_capacity;
      memory_item->mem_ptr      = mem_ptr;
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(mem_ptr);
}

// Increases the capacity of the allocated memory, primarily for the managed memory functionality
void *MallocPlus::memory_request(size_t new_capacity, const char *name){
   map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(name);
   void *mem_ptr=NULL;

   if (it != memory_name_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REQUEST: DEBUG -- reallocated memory pointer %p\n",memory_item->mem_ptr);
      map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(memory_item->mem_ptr);
      memory_ptr_dict.erase(it);
      mem_ptr=realloc(memory_item->mem_ptr, new_capacity*memory_item->mem_elsize);
      memory_item->mem_capacity = new_capacity;
      memory_item->mem_ptr      = mem_ptr;
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory named %s not found\n",name);
   }

   return(mem_ptr);
}

void MallocPlus::memory_realloc_all(size_t nelem){
   // Need a copy of the dictionary since we will be modifying while being used
   map <void *, malloc_plus_memory_entry*> memory_ptr_dict_old = memory_ptr_dict;

   // Need iterators to both new and old; new will be modified during the loop
   map<void *, malloc_plus_memory_entry*>::iterator it_old;
   map<void *, malloc_plus_memory_entry*>::iterator it_new;
   void *mem_ptr=NULL;

   for ( it_old=memory_ptr_dict_old.begin(); it_old != memory_ptr_dict_old.end(); it_old++){
      // Get the memory entry for the old dictionary
      malloc_plus_memory_entry *memory_item = it_old->second;

      // Get the iterator to the new dictionary by memory pointer and delete it
      //   since it will probably change
      // The dictionary by name does not need to be updated
      it_new = memory_ptr_dict.find(memory_item->mem_ptr);
      memory_ptr_dict.erase(it_new);

      if (memory_item->mem_flags & HOST_MANAGED_MEMORY) {
         if (nelem > memory_item->mem_capacity) {
            mem_ptr=realloc(memory_item->mem_ptr, nelem*memory_item->mem_elsize);
            if (DEBUG) printf("MALLOC_PLUS_MEMORY_REALLOC_ALL: DEBUG -- reallocated memory pointer %p new pointer %p\n",memory_item->mem_ptr,mem_ptr);
            memory_item->mem_capacity = nelem;
            memory_item->mem_nelem[0] = nelem;
            memory_item->mem_ptr      = mem_ptr;
         } else {
            memory_item->mem_nelem[0] = nelem;
         }
      }
#ifdef HAVE_J7
      else if (it->mem_flags & LOAD_BALANCE_MEMORY) {
         mem_ptr = j7->memRealloc(memory_item->mem_ptr, nelem * memory_item->mem_elsize);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
      }
#endif
      else {
         mem_ptr=realloc(memory_item->mem_ptr, nelem*memory_item->mem_elsize);
         if (DEBUG) printf("MALLOC_PLUS_MEMORY_REALLOC_ALL: DEBUG -- reallocated memory pointer %p new pointer %p\n",memory_item->mem_ptr,mem_ptr);
         memory_item->mem_capacity = nelem;
         memory_item->mem_nelem[0] = nelem;
         memory_item->mem_ptr      = mem_ptr;
      }

      //Insert the entry back into the dictionary
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(mem_ptr, memory_item) );
   }
}

void MallocPlus::memory_request_all(size_t new_capacity){
   map <void *, malloc_plus_memory_entry*> memory_ptr_dict_old = memory_ptr_dict;

   map<void *, malloc_plus_memory_entry*>::iterator it_old;
   map<void *, malloc_plus_memory_entry*>::iterator it_new;

   for ( it_old=memory_ptr_dict_old.begin(); it_old != memory_ptr_dict_old.end(); it_old++){
      malloc_plus_memory_entry *memory_item = it_old->second;

      it_new = memory_ptr_dict.find(memory_item->mem_ptr);
      memory_ptr_dict.erase(it_new);

      void *mem_ptr=realloc(memory_item->mem_ptr, new_capacity*memory_item->mem_elsize);
      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REQUEST_ALL: DEBUG -- reallocated memory pointer %p new pointer %p\n",memory_item->mem_ptr,mem_ptr);
      memory_item->mem_capacity = new_capacity;
      memory_item->mem_ptr      = mem_ptr;

      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(mem_ptr, memory_item) );
   }
}

// This routine is for memory allocated by the host program and added to the database
void *MallocPlus::memory_add(void *malloc_mem_ptr, size_t nelem, size_t elsize, const char *name, int flags){
   malloc_plus_memory_entry *memory_item = (malloc_plus_memory_entry *)malloc(sizeof(malloc_plus_memory_entry));

   memory_item->mem_nelem    = (size_t *)malloc(1*sizeof(size_t));
   memory_item->mem_nelem[0] = nelem;
   memory_item->mem_ndims    = 1;
   memory_item->mem_capacity = nelem;
   memory_item->mem_elsize   = elsize;
   memory_item->mem_flags    = flags;
   memory_item->mem_ptr      = malloc_mem_ptr;
   memory_item->mem_name = strdup(name); // mallocs memory
   memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(name, memory_item) );
   if (DEBUG) printf("MALLOC_PLUS_MEMORY_ADD: DEBUG -- added memory pointer for %s is %p\n",name,malloc_mem_ptr);

   return(malloc_mem_ptr);
}

// This routine is for memory allocated by the host program and added to the database
void *MallocPlus::memory_add(void *malloc_mem_ptr, int ndim, size_t *nelem, size_t elsize, const char *name, int flags){
   malloc_plus_memory_entry *memory_item = (malloc_plus_memory_entry *)malloc(sizeof(malloc_plus_memory_entry));

   memory_item->mem_nelem    = (size_t *)malloc(ndim*sizeof(size_t));
   for (int i=0; i<ndim; i++){
     memory_item->mem_nelem[i] = nelem[i];
   }
   memory_item->mem_ndims    = ndim;
   memory_item->mem_capacity = 0;
   memory_item->mem_elsize   = elsize;
   memory_item->mem_flags    = flags;
   memory_item->mem_ptr      = malloc_mem_ptr;
   memory_item->mem_name = strdup(name); // mallocs memory
   memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(name, memory_item) );
   if (DEBUG) printf("MALLOC_PLUS_MEMORY_ADD: DEBUG -- added memory pointer for %s is %p\n",name,malloc_mem_ptr);

   return(malloc_mem_ptr);
}

double *MallocPlus::memory_reorder(double *malloc_mem_ptr, int *iorder){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;
      double *ptr;

      memory_ptr_dict.erase(it);

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      double *tmp = (double *)malloc(memory_item->mem_nelem[0]*memory_item->mem_elsize);
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (uint ic = 0; ic < memory_item->mem_nelem[0]; ic++){
         tmp[ic] = malloc_mem_ptr[iorder[ic]];
      }
      SWAP_PTR(malloc_mem_ptr, tmp, ptr);
      free(tmp);
      memory_item->mem_ptr = malloc_mem_ptr;

      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(malloc_mem_ptr);
}

float *MallocPlus::memory_reorder(float *malloc_mem_ptr, int *iorder){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;
      float *ptr;

      memory_ptr_dict.erase(it);

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      float *tmp = (float *)malloc(memory_item->mem_nelem[0]*memory_item->mem_elsize);
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (uint ic = 0; ic < memory_item->mem_nelem[0]; ic++){
         tmp[ic] = malloc_mem_ptr[iorder[ic]];
      }
      SWAP_PTR(malloc_mem_ptr, tmp, ptr);
      free(tmp);
      memory_item->mem_ptr = malloc_mem_ptr;

      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(malloc_mem_ptr);
}

int *MallocPlus::memory_reorder(int *malloc_mem_ptr, int *iorder){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;
      int *ptr;

      memory_ptr_dict.erase(it);

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      int *tmp = (int *)malloc(memory_item->mem_nelem[0]*memory_item->mem_elsize);
#ifdef _OPENMP
#pragma omp parallel for
#endif
      for (uint ic = 0; ic < memory_item->mem_nelem[0]; ic++){
         tmp[ic] = malloc_mem_ptr[iorder[ic]];
      }
      SWAP_PTR(malloc_mem_ptr, tmp, ptr);
      free(tmp);
      memory_item->mem_ptr = malloc_mem_ptr;

      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(malloc_mem_ptr);
}

int *MallocPlus::memory_reorder_indexarray(int *malloc_mem_ptr, int *iorder, int *inv_iorder){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item = it->second;
      int *ptr;

      if (DEBUG) printf("Found memory_item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      memory_ptr_dict.erase(it);
      int *tmp = (int *)malloc(memory_item->mem_nelem[0]*memory_item->mem_elsize);
      for (uint ic = 0; ic < memory_item->mem_nelem[0]; ic++){
         tmp[ic] = inv_iorder[malloc_mem_ptr[iorder[ic]]];
      }
      SWAP_PTR(malloc_mem_ptr, tmp, ptr);
      free(tmp);
      memory_item->mem_ptr = malloc_mem_ptr;
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(malloc_mem_ptr);
}

void MallocPlus::memory_reorder_all(int *iorder){
   map <void *, malloc_plus_memory_entry*> memory_ptr_dict_old = memory_ptr_dict;
   map <void *, malloc_plus_memory_entry*>::iterator it_old;
   vector<int> inv_iorder;

   for ( it_old=memory_ptr_dict_old.begin(); it_old != memory_ptr_dict_old.end(); it_old++){
      malloc_plus_memory_entry *memory_item_old = it_old->second;

      map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(memory_item_old->mem_ptr);
      malloc_plus_memory_entry *memory_item = it_old->second;
      memory_ptr_dict.erase(it);

      if (memory_item_old->mem_flags & 0x100) {
         if (inv_iorder.size() < memory_item_old->mem_nelem[0]) {
            inv_iorder.resize(memory_item_old->mem_nelem[0]);
            for (int ic = 0; ic < (int)memory_item_old->mem_nelem[0]; ic++){
               inv_iorder[iorder[ic]] = ic;
            }
         }
         int *ptr;
         int *malloc_mem_ptr = (int *)memory_item_old->mem_ptr;
         int *tmp = (int *)malloc(memory_item_old->mem_nelem[0]*memory_item_old->mem_elsize);
         for (uint ic = 0; ic < memory_item_old->mem_nelem[0]; ic++){
            tmp[ic] = inv_iorder[malloc_mem_ptr[iorder[ic]]];
         }
         memory_replace(malloc_mem_ptr, tmp);
         SWAP_PTR(malloc_mem_ptr, tmp, ptr);
         free(tmp);
         memory_item->mem_ptr = malloc_mem_ptr;
         memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
      } else if (memory_item_old->mem_elsize == 8){
         double *ptr;
         double *malloc_mem_ptr = (double *)memory_item_old->mem_ptr;
         double *tmp = (double *)malloc(memory_item_old->mem_nelem[0]*memory_item_old->mem_elsize);

         for (uint ic = 0; ic < memory_item_old->mem_nelem[0]; ic++){
            tmp[ic] = malloc_mem_ptr[iorder[ic]];
         }

         SWAP_PTR(malloc_mem_ptr, tmp, ptr);
         free(tmp);
         memory_item->mem_ptr = malloc_mem_ptr;
         memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
      } else {
         float *ptr;
         float *malloc_mem_ptr = (float *)memory_item_old->mem_ptr;
         float *tmp = (float *)malloc(memory_item_old->mem_nelem[0]*memory_item_old->mem_elsize);
         for (uint ic = 0; ic < memory_item_old->mem_nelem[0]; ic++){
            tmp[ic] = malloc_mem_ptr[iorder[ic]];
         }
         memory_replace(malloc_mem_ptr, tmp);
         SWAP_PTR(malloc_mem_ptr, tmp, ptr);
         free(tmp);
         memory_item->mem_ptr = malloc_mem_ptr;
         memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr, memory_item) );
      }

   }

   inv_iorder.clear();
}

void MallocPlus::memory_report(void){
   map<void *, malloc_plus_memory_entry*>::iterator it_ptr;

   for ( it_ptr=memory_ptr_dict.begin(); it_ptr != memory_ptr_dict.end(); it_ptr++){
      malloc_plus_memory_entry *memory_item = it_ptr->second;

      printf("MallocPlus ptr  %p: name %10s ptr %p dims %lu nelem (",
            it_ptr->first,memory_item->mem_name,memory_item->mem_ptr,memory_item->mem_ndims);

      char nelemstring[80];
      char *str_ptr = nelemstring;
      str_ptr += sprintf(str_ptr,"%lu", memory_item->mem_nelem[0]);
      for (uint i = 1; i < memory_item->mem_ndims; i++){
         str_ptr += sprintf(str_ptr,", %lu", memory_item->mem_nelem[i]);
      }
      printf("%12s",nelemstring);

      printf(") elsize %lu flags %d capacity %lu\n",
            memory_item->mem_elsize,memory_item->mem_flags,memory_item->mem_capacity);
   }

   map<string, malloc_plus_memory_entry*>::iterator it_name;

   for ( it_name=memory_name_dict.begin(); it_name != memory_name_dict.end(); it_name++){
      malloc_plus_memory_entry *memory_item = it_name->second;

      printf("MallocPlus name %14s: name %10s ptr %p dims %lu nelem (",
            it_name->first.c_str(),memory_item->mem_name,memory_item->mem_ptr,memory_item->mem_ndims);

      char nelemstring[80];
      char *str_ptr = nelemstring;
      str_ptr += sprintf(str_ptr,"%lu", memory_item->mem_nelem[0]);
      for (uint i = 1; i < memory_item->mem_ndims; i++){
         str_ptr += sprintf(str_ptr,", %lu", memory_item->mem_nelem[i]);
      }
      printf("%12s",nelemstring);

      printf(") elsize %lu flags %d capacity %lu\n",
            memory_item->mem_elsize,memory_item->mem_flags,memory_item->mem_capacity);
   }
}

void *MallocPlus::memory_delete(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p\n",memory_item->mem_ptr);

      if ((memory_item->mem_flags & DEVICE_REGULAR_MEMORY) != 0){
#ifdef HAVE_OPENCL
         //printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p\n",memory_item->mem_ptr);
         ezcl_device_memory_delete(memory_item->mem_ptr);
#endif
      }
#ifdef HAVE_J7
      else if (memory_item->mem_flags & LOAD_BALANCE_MEMORY) {
         j7->memFree(memory_item->mem_ptr);
      }
#endif
      else {
         free(memory_item->mem_ptr);
      }

      memory_ptr_dict.erase(it);
      // Need to delete the entry in the name dictionary. This is done in a separate scope
      // so the iterator "it" is isolated for this use
      {
         map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(memory_item->mem_name);
         memory_name_dict.erase(it);
      }

      free(memory_item->mem_nelem);
      free(memory_item->mem_name);
      free(memory_item);
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }

   return(NULL);
}

void *MallocPlus::memory_delete(const char *name){
   map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(name);

   if (it != memory_name_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p\n",memory_item->mem_ptr);
      if ((memory_item->mem_flags & DEVICE_REGULAR_MEMORY) != 0){
#ifdef HAVE_OPENCL
         ezcl_device_memory_delete(memory_item->mem_ptr);
#endif
      }
#ifdef HAVE_J7
      else if (memory_item->mem_flags & LOAD_BALANCE_MEMORY) {
         j7->memFree(memory_item->mem_ptr);
      }
#endif
      else {
         free(memory_item->mem_ptr);
      }

      memory_name_dict.erase(it);
      {
         map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(memory_item->mem_ptr);
         memory_ptr_dict.erase(it);
      }

      free(memory_item->mem_nelem);
      free(memory_item->mem_name);
      free(memory_item);
   } else {
      if (DEBUG) printf("Warning -- memory named %s not found\n",name);
   }

   return(NULL);
}

void MallocPlus::memory_delete_all(void){
   map <void *, malloc_plus_memory_entry*> memory_ptr_dict_old = memory_ptr_dict;
   map <void *, malloc_plus_memory_entry*>::iterator it;

   for ( it=memory_ptr_dict_old.begin(); it != memory_ptr_dict_old.end(); it++){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);

      if ((memory_item->mem_flags & DEVICE_REGULAR_MEMORY) != 0){
#ifdef HAVE_OPENCL
         ezcl_device_memory_delete(memory_item->mem_ptr);
#endif
      } else {
         free(memory_item->mem_ptr);
      }

      free(memory_item->mem_nelem);
      free(memory_item->mem_name);
      free(memory_item);
   }

   memory_ptr_dict.clear();
   memory_name_dict.clear();
}

// For memory that was allocated by the host and added to the database with the
// memory_add function. This is the corresponding routine to delete the dictionary entry.
// The memory itself is not freed.
void MallocPlus::memory_remove(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p\n",memory_item->mem_ptr);
      memory_ptr_dict.erase(it);
      {
         map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(memory_item->mem_name);
         memory_name_dict.erase(it);
      }
      free(memory_item->mem_nelem);
      free(memory_item->mem_name);
      free(memory_item);
   } else {
      if (DEBUG) printf("Warning -- memory pointer %p not found\n",malloc_mem_ptr);
   }
}

void MallocPlus::memory_remove(const char *name){
   map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(name);

   if (it != memory_name_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("MALLOC_PLUS_MEMORY_REMOVE: DEBUG -- removed memory pointer %p\n",memory_item->mem_ptr);
      memory_name_dict.erase(it);
      {
         map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(memory_item->mem_ptr);
         memory_ptr_dict.erase(it);
      }
      free(memory_item->mem_nelem);
      free(memory_item->mem_name);
      free(memory_item);
   } else {
      if (DEBUG) printf("Warning -- memory named %s not found\n",name);
   }
}

void *MallocPlus::memory_begin(void){
   it_save = memory_ptr_dict.begin();
   malloc_plus_memory_entry *memory_item = it_save->second;
   return(memory_item->mem_ptr);
}

void *MallocPlus::memory_next(void){
   map <void *, malloc_plus_memory_entry*>::iterator it;

   it_save++;
   it = it_save;

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_ptr);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
      return(NULL);
   }
}

void *MallocPlus::memory_by_name_begin(void){
   it_save_by_name = memory_name_dict.begin();
   malloc_plus_memory_entry *memory_item = it_save->second;
   return(memory_item->mem_ptr);
}

void *MallocPlus::memory_by_name_next(void){
   map<string, malloc_plus_memory_entry*, cmp_str>::iterator it_by_name;

   it_save_by_name++;
   it_by_name = it_save_by_name;

   if (it_by_name != memory_name_dict.end()){
      malloc_plus_memory_entry *memory_item = it_by_name->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_ptr);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
      return(NULL);
   }
}

malloc_plus_memory_entry* MallocPlus::memory_entry_begin(void){
   it_save = memory_ptr_dict.begin();
   malloc_plus_memory_entry *memory_item = it_save->second;
   return(memory_item);
}

malloc_plus_memory_entry* MallocPlus::memory_entry_next(void){
   it_save++;
   if (it_save == memory_ptr_dict.end()) return(NULL);
   malloc_plus_memory_entry *memory_item = it_save->second;
   if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
   return(memory_item);
}

malloc_plus_memory_entry* MallocPlus::memory_entry_end(void){
   return(NULL);
}

malloc_plus_memory_entry* MallocPlus::memory_entry_by_name_begin(void){
   it_save_by_name = memory_name_dict.begin();
   malloc_plus_memory_entry *memory_item = it_save_by_name->second;
   return(memory_item);
}

malloc_plus_memory_entry* MallocPlus::memory_entry_by_name_next(void){
   it_save_by_name++;
   if (it_save_by_name == memory_name_dict.end()) return(NULL);
   malloc_plus_memory_entry *memory_item = it_save_by_name->second;
   if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
   return(memory_item);
}

malloc_plus_memory_entry* MallocPlus::memory_entry_by_name_end(void){
   return(NULL);
}

size_t MallocPlus::get_memory_size(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_nelem[0]);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(0);
}

int MallocPlus::get_memory_elemsize(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_elsize);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(0);
}

int MallocPlus::get_memory_flags(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s attribute %d\n",memory_item->mem_ptr,memory_item->mem_name,memory_item->mem_flags);
      return(memory_item->mem_flags);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(0);
}

size_t MallocPlus::get_memory_capacity(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_capacity);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(0);
}

const char * MallocPlus::get_memory_name(void *malloc_mem_ptr){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_name);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(NULL);
}

void *MallocPlus::memory_replace(void *malloc_mem_ptr_old, void * const malloc_mem_ptr_new){
   map <void *, malloc_plus_memory_entry*>::iterator it_old = memory_ptr_dict.find(malloc_mem_ptr_old);
   map <void *, malloc_plus_memory_entry*>::iterator it_new = memory_ptr_dict.find(malloc_mem_ptr_new);

   if (it_old != memory_ptr_dict.end() && it_new != memory_ptr_dict.end() ){
      malloc_plus_memory_entry *memory_item_old = it_old->second;
      malloc_plus_memory_entry *memory_item_new = it_new->second;

      // erase the entries in the pointer dictionary
      memory_ptr_dict.erase(it_new);
      memory_ptr_dict.erase(it_old);
      // get the iterators for the named dictionary
      map <string, malloc_plus_memory_entry*>::iterator it_old = memory_name_dict.find(memory_item_old->mem_name);
      map <string, malloc_plus_memory_entry*>::iterator it_new = memory_name_dict.find(memory_item_new->mem_name);
      memory_name_dict.erase(it_new);
      memory_name_dict.erase(it_old);

      if (DEBUG) printf("Found memory item ptr_old %p name %s ptr_new %p name %s\n",memory_item_old->mem_ptr,memory_item_old->mem_name,memory_item_new->mem_ptr,memory_item_new->mem_name);

      if ((memory_item_old->mem_flags & DEVICE_REGULAR_MEMORY) != 0){
#ifdef HAVE_OPENCL
         if (DEBUG) printf("Deleting device memory name %s pointer %p\n",memory_item_old->mem_name,memory_item_old->mem_ptr);
         ezcl_device_memory_replace(&memory_item_old->mem_ptr, &memory_item_new->mem_ptr);
#endif
      }
#ifdef HAVE_J7
      else if (memory_item->mem_flags & LOAD_BALANCE_MEMORY) {
         j7->memFree(memory_item_old->mem_ptr);
         memory_item_old->mem_ptr      = memory_item_new->mem_ptr;
      }
#endif
      else {
         free(memory_item_old->mem_ptr);
         memory_item_old->mem_ptr      = memory_item_new->mem_ptr;
      }

      memory_item_old->mem_nelem[0] = memory_item_new->mem_nelem[0];
      memory_item_old->mem_capacity = memory_item_new->mem_capacity;
      memory_item_old->mem_elsize   = memory_item_new->mem_elsize;
      memory_item_old->mem_flags    = memory_item_new->mem_flags;
      malloc_mem_ptr_old = (void *)malloc_mem_ptr_new;
      free(memory_item_new->mem_nelem);
      free(memory_item_new->mem_name);
      free(memory_item_new);
      
      memory_ptr_dict.insert(std::pair<void*, malloc_plus_memory_entry*>(malloc_mem_ptr_old, memory_item_old) );
      memory_name_dict.insert(std::pair<const char*, malloc_plus_memory_entry*>(memory_item_old->mem_name, memory_item_old) );

      return(memory_item_old->mem_ptr);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(NULL);
}

void MallocPlus::memory_swap(int **malloc_mem_ptr_old, int **malloc_mem_ptr_new){
   map <void *, malloc_plus_memory_entry*>::iterator it_old = memory_ptr_dict.find(*malloc_mem_ptr_old);
   map <void *, malloc_plus_memory_entry*>::iterator it_new = memory_ptr_dict.find(*malloc_mem_ptr_new);

   if (it_old != memory_ptr_dict.end() && it_new != memory_ptr_dict.end() ){
      // Swap the memory entries during the retrieval
      malloc_plus_memory_entry *memory_item_new = it_old->second;
      malloc_plus_memory_entry *memory_item_old = it_new->second;

      if (DEBUG) printf("Found memory item ptr_old %p name %s ptr_new %p name %s\n",memory_item_old->mem_ptr,memory_item_old->mem_name,memory_item_new->mem_ptr,memory_item_new->mem_name);

      const char *mem_name_tmp;
                  mem_name_tmp  = memory_item_old->mem_name;
      memory_item_old->mem_name = memory_item_new->mem_name;
      memory_item_new->mem_name = (char *)mem_name_tmp;

      // Delete the ptr entries
      memory_ptr_dict.erase(it_old);
      memory_ptr_dict.erase(it_new);

      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_old->mem_ptr, memory_item_old) );
      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_new->mem_ptr, memory_item_new) );

      // Delete the named entries
      map <string, malloc_plus_memory_entry*>::iterator it_name_old = memory_name_dict.find(memory_item_old->mem_name);
      map <string, malloc_plus_memory_entry*>::iterator it_name_new = memory_name_dict.find(memory_item_new->mem_name);
      memory_name_dict.erase(it_name_old);
      memory_name_dict.erase(it_name_new);

      memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(memory_item_old->mem_name, memory_item_old) );
      memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(memory_item_new->mem_name, memory_item_new) );

      // memory items have been swapped, so return the new pointers
      *malloc_mem_ptr_old = (int *)memory_item_old->mem_ptr;
      *malloc_mem_ptr_new = (int *)memory_item_new->mem_ptr;
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
}

void MallocPlus::memory_swap(float **malloc_mem_ptr_old, float **malloc_mem_ptr_new){
   map <void *, malloc_plus_memory_entry*>::iterator it_old = memory_ptr_dict.find(*malloc_mem_ptr_old);
   map <void *, malloc_plus_memory_entry*>::iterator it_new = memory_ptr_dict.find(*malloc_mem_ptr_new);

   if (it_old != memory_ptr_dict.end() && it_new != memory_ptr_dict.end() ){
      // Swap the memory entries during the retrieval
      malloc_plus_memory_entry *memory_item_new = it_old->second;
      malloc_plus_memory_entry *memory_item_old = it_new->second;

      if (DEBUG) printf("Found memory item ptr_old %p name %s ptr_new %p name %s\n",memory_item_old->mem_ptr,memory_item_old->mem_name,memory_item_new->mem_ptr,memory_item_new->mem_name);

      const char *mem_name_tmp;
                  mem_name_tmp  = memory_item_old->mem_name;
      memory_item_old->mem_name = memory_item_new->mem_name;
      memory_item_new->mem_name = (char *)mem_name_tmp;

      // Delete the ptr entries
      memory_ptr_dict.erase(it_old);
      memory_ptr_dict.erase(it_new);

      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_old->mem_ptr, memory_item_old) );
      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_new->mem_ptr, memory_item_new) );

      // Delete the named entries
      map <string, malloc_plus_memory_entry*>::iterator it_old = memory_name_dict.find(memory_item_old->mem_name);
      map <string, malloc_plus_memory_entry*>::iterator it_new = memory_name_dict.find(memory_item_new->mem_name);
      memory_name_dict.erase(it_old);
      memory_name_dict.erase(it_new);

      memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(memory_item_old->mem_name, memory_item_old) );
      memory_name_dict.insert(std::pair<string, malloc_plus_memory_entry*>(memory_item_new->mem_name, memory_item_new) );

      // memory items have been swapped, so return the new pointers
      *malloc_mem_ptr_old = (float *)memory_item_old->mem_ptr;
      *malloc_mem_ptr_new = (float *)memory_item_new->mem_ptr;
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
}

void MallocPlus::memory_swap(double **malloc_mem_ptr_old, double **malloc_mem_ptr_new){
   map <void *, malloc_plus_memory_entry*>::iterator it_old = memory_ptr_dict.find(*malloc_mem_ptr_old);
   map <void *, malloc_plus_memory_entry*>::iterator it_new = memory_ptr_dict.find(*malloc_mem_ptr_new);

   if (it_old != memory_ptr_dict.end() && it_new != memory_ptr_dict.end() ){
      // Swap the memory entries during the retrieval
      malloc_plus_memory_entry *memory_item_new = it_old->second;
      malloc_plus_memory_entry *memory_item_old = it_new->second;

      if (DEBUG) printf("Found memory item ptr_old %p name %s ptr_new %p name %s\n",memory_item_old->mem_ptr,memory_item_old->mem_name,memory_item_new->mem_ptr,memory_item_new->mem_name);

      const char *mem_name_tmp;
                  mem_name_tmp  = memory_item_old->mem_name;
      memory_item_old->mem_name = memory_item_new->mem_name;
      memory_item_new->mem_name = (char *)mem_name_tmp;

      // Delete the ptr entries
      memory_ptr_dict.erase(it_old);
      memory_ptr_dict.erase(it_new);

      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_old->mem_ptr, memory_item_old) );
      memory_ptr_dict.insert(std::pair<void *, malloc_plus_memory_entry*>(memory_item_new->mem_ptr, memory_item_new) );

      // Delete the named entries
      map <string, malloc_plus_memory_entry*>::iterator it_old = memory_name_dict.find(memory_item_old->mem_name);
      map <string, malloc_plus_memory_entry*>::iterator it_new = memory_name_dict.find(memory_item_new->mem_name);
      memory_name_dict.erase(it_old);
      memory_name_dict.erase(it_new);

      memory_name_dict.insert(std::pair<char const *, malloc_plus_memory_entry*>(memory_item_old->mem_name, memory_item_old) );
      memory_name_dict.insert(std::pair<char const *, malloc_plus_memory_entry*>(memory_item_new->mem_name, memory_item_new) );

      // memory items have been swapped, so return the new pointers
      *malloc_mem_ptr_old = (double *)memory_item_old->mem_ptr;
      *malloc_mem_ptr_new = (double *)memory_item_new->mem_ptr;
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
}

// This duplicates memory for a variable and makes a new dictionary entry for the new variable
void *MallocPlus::memory_duplicate(void *malloc_mem_ptr, const char *addname){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);
   void *mem_ptr_dup;

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      // The memory_malloc will add the database entry
      mem_ptr_dup = memory_malloc(memory_item->mem_nelem[0], memory_item->mem_elsize, addname, memory_item->mem_flags);
      return(mem_ptr_dup);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(NULL);
}

void *MallocPlus::get_memory_ptr(const char *name){
   map <string, malloc_plus_memory_entry*>::iterator it = memory_name_dict.find(name);

   if (it != memory_name_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s\n",memory_item->mem_ptr,memory_item->mem_name);
      return(memory_item->mem_ptr);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
   return(NULL);
}

bool MallocPlus::check_memory_attribute(void *malloc_mem_ptr, int attribute){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s attribute %d\n",memory_item->mem_ptr,memory_item->mem_name,memory_item->mem_flags);
      bool bvalue = false;
      if (memory_item->mem_flags & attribute) bvalue = true;

      return bvalue;
   } else {
      printf("Error -- memory not found\n");
      exit(1);
   }
}

void MallocPlus::set_memory_attribute(void *malloc_mem_ptr, int attribute){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s attribute %d\n",memory_item->mem_ptr,memory_item->mem_name,memory_item->mem_flags);
      memory_item->mem_flags |= attribute;
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
}

void MallocPlus::clear_memory_attribute(void *malloc_mem_ptr, int attribute){
   map <void *, malloc_plus_memory_entry*>::iterator it = memory_ptr_dict.find(malloc_mem_ptr);

   if (it != memory_ptr_dict.end()){
      malloc_plus_memory_entry *memory_item = it->second;

      if (DEBUG) printf("Found memory item ptr %p name %s attribute %d\n",memory_item->mem_ptr,memory_item->mem_name,memory_item->mem_flags);
      memory_item->mem_flags &= ~attribute;
      if (DEBUG) printf("Found memory item ptr %p name %s attribute %d\n",memory_item->mem_ptr,memory_item->mem_name,memory_item->mem_flags);
   } else {
      if (DEBUG) printf("Warning -- memory not found\n");
   }
}

extern "C" {
   MallocPlus *MallocPlus_new(){
     return new MallocPlus;
   }

   void MallocPlus_memory_report(MallocPlus *mem_object) {
      mem_object->memory_report();
   }

   void MallocPlus_memory_add(MallocPlus *mem_object, void *dbleptr, size_t nelem,
       size_t elsize, char *name, unsigned long long flags){
//   printf("DEBUG -- nelem %lu elsize %lu\n", nelem, elsize);
     mem_object->memory_add(dbleptr, nelem, elsize, name,
       (unsigned long long)flags);
   }
   void MallocPlus_memory_add_nD(MallocPlus *mem_object, void *dbleptr, int ndim, size_t *nelem,
       size_t elsize, char *name, unsigned long long flags){
//   printf("DEBUG -- ndim %d nelem[0] %lu elsize %lu\n",ndim, nelem[0], elsize);
     mem_object->memory_add(dbleptr, ndim, nelem, elsize, name,
       (unsigned long long)flags);
   }
}
