/*
 *  Copyright (c) 2011-2013, Los Alamos National Security, LLC.
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
 * 
 */
#ifndef MALLOCPLUS_H_
#define MALLOCPLUS_H_

#include <map>
#include <string>
#include <string.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#define HOST_REGULAR_MEMORY     0x00000
#define HOST_MANAGED_MEMORY     0x00001
#define DEVICE_REGULAR_MEMORY   0x00002
#define INDEX_ARRAY_MEMORY      0x00004
#define LOAD_BALANCE_MEMORY     0x00008
#define RESTART_DATA            0x00010
#define REPLICATED_DATA         0x00020
#define DISTRIBUTED_INT_DATA    0x00040
#define DISTRIBUTED_DOUBLE_DATA 0x00080

#if defined(HAVE_MPI)
#include "mpi.h"
#if defined(HAVE_J7)
#include "j7/j7.h"
#endif
#endif

using namespace std;

/****************************************************************//**
 * \brief
 * Memory entry with fields for each entry in database
 *******************************************************************/
struct malloc_plus_memory_entry {
   void   *mem_ptr;       //!< memory pointer for entry
   size_t  mem_capacity;  //!< allocated capacity for memory buffer
                          //!< this may be larger than the number of
                          //!< elements and is used to internally handle
                          //!< memory resizing
   size_t *mem_nelem;     //!< number of elements
   size_t  mem_ndims;     //!< number of dimensions
   size_t  mem_elsize;    //!< element size for type of data
   int     mem_flags;     //!< flags for special handling
   char   *mem_name;      //!< name of memory entry
};

struct cmp_str
{
   bool operator()(const string &a, const string &b)
   {
      return a.compare(b) < 0;
   }
};

/****************************************************************//**
 * MallocPlus class
 *    Provide an enhanced memory allocation package with database
 *    of allocations, sizes and contiguous memory allocations for
 *    multi-dimensional arrays
 *******************************************************************/
class MallocPlus {
//protected:
public:
   map<string, malloc_plus_memory_entry*> memory_name_dict; //!< Dictionary entries by name
   map<void*, malloc_plus_memory_entry*> memory_ptr_dict; //!< Dictionary entries by pointer

#if defined(HAVE_MPI) && defined(HAVE_J7)
private:
   J7 *j7;
#endif
   
public:
   // if we have MPI support enable these routines. they only really do anything
   // if we also have j7 support, but that's okay; we don't want ifdefs all
   // over.
#if defined(HAVE_MPI)
   // parallel initialization routine
   void pinit(MPI_Comm smComm, std::size_t memPoolSize);
   // parallel finalization routine
   void pfini(void);
#endif

/****************************************************************//**
 * \brief
 * Allocates memory for a 1D array and put entry in database
 *
 * **Parameters**
 * * size_t nelem -- number of elements in array
 * * size_t elsize -- element size in bytes
 * * const char *name -- name of array
 * * int flags -- flags for special handling, default is 0
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_malloc(ncells, sizeof(double),
 *                       "Density");
 *******************************************************************/
   void *memory_malloc(size_t nelem, size_t elsize, const char *name, int flags=0);

/****************************************************************//**
 * \brief
 * Duplicate memory and add new entry into database
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer to duplicate
 * * const char *addname -- new name for variable
 *
 * Typical Usage
 *
 *     double *new_density = my_mem->memory_duplicate(density, "Density_new");
 *******************************************************************/
   void *memory_duplicate(void *malloc_mem_ptr, const char *addname);

/****************************************************************//**
 * \brief
 * Reallocates memory for memory pointer in database
 *
 * **Parameters**
 * * size_t nelem -- number of elements for new allocation
 * * void *malloc_mem_ptr -- memory pointer to duplicate
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_realloc(new_ncells, density);
 *******************************************************************/
   void *memory_realloc(size_t nelem, void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Reallocates memory for named entry in database
 *
 * **Parameters**
 * * size_t nelem -- number of elements for new allocation
 * * const char *name -- named entry to duplicate
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_realloc(new_ncells, "Density");
 *******************************************************************/
   void *memory_realloc(size_t nelem, const char *name);

/****************************************************************//**
 * \brief
 * Request memory buffer capacity reallocation for memory pointer in database.
 * This only changes the capacity for managed memory and does not change
 * the current number of elements registered for the array.
 *
 * **Parameters**
 * * size_t capacity -- capacity in number of elements for reallocation
 * * void *malloc_mem_ptr -- memory pointer to reallocate more capacity
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_request(new_capacity, density);
 *******************************************************************/
   void *memory_request(size_t new_capacity, void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Request memory buffer capacity reallocation for named entry in database.
 * This only changes the capacity for managed memory and does not change
 * the current number of elements registered for the array.
 *
 * **Parameters**
 * * size_t capacity -- capacity in number of elements for reallocation
 * * const char *name -- named entry in database
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_request(new_capacity, "Density");
 *******************************************************************/
   void *memory_request(size_t new_capacity, const char *name);

/****************************************************************//**
 * \brief
 * Reallocates memory for all arrays in the database. Element size stays
 * the same.
 *
 * **Parameters**
 * * size_t nelem -- number of elements for new allocation
 *
 * Typical Usage
 *
 *     my_mem->memory_realloc_all(new_ncells);
 *******************************************************************/
   void memory_realloc_all(size_t nelem);

/****************************************************************//**
 * \brief
 * Requests capacity reallocation for all arrays in the database. Element
 * size and number of elements stays the same. The maximum memory
 * capacity is increased.
 *
 * **Parameters**
 * * size_t capacity -- number of elements for new allocation
 *
 * Typical Usage
 *
 *     my_mem->memory_realloc_all(new_capacity);
 *******************************************************************/
   void memory_request_all(size_t new_capacity);

/****************************************************************//**
 * \brief
 * Replaces a database entry with another database entry, effectively
 * renaming the entry and deallocating the memory for the old entry
 * and removing the other database entry. Both the return and the 
 * first argument old memory pointer gets reset to the new memory
 * location.
 *
 * **Parameters**
 * * void *malloc_mem_ptr_old -- memory pointer to entry to replace
 * * void * const malloc_mem_ptr_new -- memory pointer to entry to
 *       put in place of old memory
 *
 * Typical Usage
 *
 *     double *density_new = (double *)my_mem->memory_malloc(new_ncells,
 *                           sizeof(double), "Density_new");
 *       ... lots of calculations of density_new from density (old) ...
 *     density = (double *)my_mem->memory_replace(density, density_new);
 *******************************************************************/
   void *memory_replace(void *malloc_mem_ptr_old, void * const malloc_mem_ptr_new);

/****************************************************************//**
 * \brief
 * Swaps a database entry with another database entry, effectively
 * renaming both entries. The new pointers are returned in the
 * two arguments.
 *
 * **Parameters**
 * * void *malloc_mem_ptr_old -- memory pointer to swap
 * * void *malloc_mem_ptr_new -- memory pointer to swap
 *
 * Typical Usage
 *
 *     int *level_old = (int *)my_mem->memory_malloc(new_ncells,
 *                           sizeof(int), "level_old");
 *     level = (int *)my_mem->memory_swap(&level, &level_old);
 *       ... lots of calculations of level from level_new ...
 *     my_mem->memory_delete(level_old);
 *******************************************************************/
   void memory_swap(int **malloc_mem_ptr_old, int **malloc_mem_ptr_new);

/****************************************************************//**
 * \brief
 * Swaps a database entry with another database entry, effectively
 * renaming both entries. The new pointers are returned in the
 * two arguments.
 *
 * **Parameters**
 * * void *malloc_mem_ptr_old -- memory pointer to swap
 * * void *malloc_mem_ptr_new -- memory pointer to swap
 *
 * Typical Usage
 *
 *     float *density_old = (float *)my_mem->memory_malloc(new_ncells,
 *                           sizeof(float), "Density_old");
 *     density = (float *)my_mem->memory_swap(&density, &density_old);
 *       ... lots of calculations of density from density_new ...
 *     my_mem->memory_delete(density_old);
 *******************************************************************/
   void memory_swap(float **malloc_mem_ptr_old, float **malloc_mem_ptr_new);

/****************************************************************//**
 * \brief
 * Swaps a database entry with another database entry, effectively
 * renaming both entries. The new pointers are returned in the
 * two arguments.
 *
 * **Parameters**
 * * void *malloc_mem_ptr_old -- memory pointer to swap
 * * void *malloc_mem_ptr_new -- memory pointer to swap
 *
 * Typical Usage
 *
 *     double *density_old = (double *)my_mem->memory_malloc(new_ncells,
 *                           sizeof(double), "Density_old");
 *     density = (double *)my_mem->memory_swap(&density, &density_old);
 *       ... lots of calculations of density from density_new ...
 *     my_mem->memory_delete(density_old);
 *******************************************************************/
   void memory_swap(double **malloc_mem_ptr_old, double **malloc_mem_ptr_new);

/****************************************************************//**
 * \brief
 * Adds an entry for an already allocated array into the database
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer to add
 * * size_t nelem -- number of elements in array
 * * size_t elsize -- element size in bytes
 * * const char *name -- name of array
 * * int flags -- flags for special handling, default is 0
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_add(density, ncells, sizeof(double),
 *                       "Density");
 *******************************************************************/
   void *memory_add(void *malloc_mem_ptr, size_t nelem, size_t elsize,
      const char *name, int flags=0);

   void *memory_add(void *malloc_mem_ptr, int ndim, size_t *nelem, size_t elsize,
      const char *name, int flags=0);

/****************************************************************//**
 * \brief
 * Reorders all of the arrays in the database by the indices in the
 * iorder array. The reorder does the following:
 *     tmp[ic] = density[iorder[ic]];
 *     SWAP_PTR(tmp, density);
 * Note that the pointer value will change during the operation and
 * will be returned in the return value.
 *
 * **Parameters**
 * * double *malloc_mem_ptr -- memory pointer to entry to reorder
 * * int *iorder -- index array for reordering
 *
 * Typical Usage
 *
 *     double *density = my_mem->memory_reorder_all(density, iorder);
 *******************************************************************/
   double *memory_reorder(double *malloc_mem_ptr, int *iorder);

/****************************************************************//**
 * \brief
 * Reorders all of the arrays in the database by the indices in the
 * iorder array. The reorder does the following:
 *     tmp[ic] = density[iorder[ic]];
 *     SWAP_PTR(tmp, density);
 * Note that the pointer value will change during the operation and
 * will be returned in the return value.
 *
 * **Parameters**
 * * float *malloc_mem_ptr -- memory pointer to entry to reorder
 * * int *iorder -- index array for reordering
 *
 * Typical Usage
 *
 *     float *density = my_mem->memory_reorder_all(density, iorder);
 *******************************************************************/
   float *memory_reorder(float *malloc_mem_ptr, int *iorder);

/****************************************************************//**
 * \brief
 * Reorders all of the arrays in the database by the indices in the
 * iorder array. The reorder does the following:
 *     tmp[ic] = level[iorder[ic]];
 *     SWAP_PTR(tmp, level);
 * Note that the pointer value will change during the operation and
 * will be returned in the return value.
 *
 * **Parameters**
 * * int *malloc_mem_ptr -- memory pointer to entry to reorder
 * * int *iorder -- index array for reordering
 *
 * Typical Usage
 *
 *     int *level = my_mem->memory_reorder_all(level, iorder);
 *******************************************************************/
   int *memory_reorder(int *malloc_mem_ptr, int *iorder);

/****************************************************************//**
 * \brief
 * Reorders an index array in the database by the indices in the
 * iorder array and reindexes the array by the inverse order given
 * by inv_iorder. The reorder does the following:
 *     tmp[ic] = inv_iorder[level[iorder[ic]]];
 *     SWAP_PTR(tmp, level);
 * Note that the pointer value will change during the operation and
 * will be returned in the return value.
 *
 * **Parameters**
 * * int *malloc_mem_ptr -- memory pointer to entry to reorder
 * * int *iorder -- index array for reordering
 * * int *inv_order -- inverse index array for reordering
 *
 * Typical Usage
 *
 *     int *level = my_mem->memory_reorder_all(level, iorder, inv_iorder);
 *******************************************************************/
   int *memory_reorder_indexarray(int *malloc_mem_ptr, int *iorder, int *inv_iorder);

/****************************************************************//**
 * \brief
 * Reorders all of the arrays in the database by the indices in the
 * iorder array. The reorder does the following:
 *     tmp[ic] = density[iorder[ic]];
 *     SWAP_PTR(tmp, density);
 * Note that the pointer value will change during the operation and
 * must be retrieved from the database.
 *
 * **Parameters**
 * * int *iorder -- index array for reordering
 *
 * Typical Usage
 *
 *     my_mem->memory_reorder_all(iorder);
 *******************************************************************/
   void memory_reorder_all(int *iorder);

/****************************************************************//**
 * \brief
 * Prints out a report of all the arrays in the database.
 *
 * Typical Usage
 *
 *     my_mem->memory_report();
 *******************************************************************/
   void memory_report(void);

/****************************************************************//**
 * \brief
 * Deallocates memory for a memory pointer in the database and removes the
 * entry from the database.
 *
 * Typical Usage
 *
 *     my_mem->memory_delete(density);
 *******************************************************************/
   void *memory_delete(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Deallocates memory for a named entry in the database and removes the
 * entry from the database.
 *
 * Typical Usage
 *
 *     my_mem->memory_delete("Density");
 *******************************************************************/
   void *memory_delete(const char *name);

/****************************************************************//**
 * \brief
 * Deallocates memory for all arrays in the database.
 *
 * Typical Usage
 *
 *     my_mem->memory_delete_all();
 *******************************************************************/
   void memory_delete_all(void);

/****************************************************************//**
 * \brief
 * Removes the entry for a memory pointer from the database. (This does
 * not delete the memory).
 *
 * Typical Usage
 *
 *     my_mem->memory_delete(density);
 *******************************************************************/
   void memory_remove(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Removes the entry for a named entry from the database. (This does
 * not delete the memory).
 *
 * Typical Usage
 *
 *     my_mem->memory_delete("Density");
 *******************************************************************/
   void memory_remove(const char *name);

/****************************************************************//**
 * \brief
 * Gets initial memory pointer from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     for (void *mem_ptr = my_mem.memory_begin(); mem_ptr!=NULL;
 *          mem_ptr = my_mem.memory_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   void *memory_begin(void);

/****************************************************************//**
 * \brief
 * Gets next memory pointer from database for iterating over the
 * entries and processing each. Note that their is an implied caching
 * of the current memory pointer in MallocPlus.
 *
 * Typical Usage
 *
 *     for (void *mem_ptr = my_mem.memory_begin(); mem_ptr!=NULL;
 *          mem_ptr = my_mem.memory_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   void *memory_next(void);

/****************************************************************//**
 * \brief
 * Gets initial memory pointer from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     for (void *mem_ptr = my_mem.memory_by_name_begin(); mem_ptr!=NULL;
 *          mem_ptr = my_mem.memory_by_name_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   void *memory_by_name_begin(void);

/****************************************************************//**
 * \brief
 * Gets next memory pointer from database for iterating over the
 * entries and processing each. Note that their is an implied caching
 * of the current memory pointer in MallocPlus.
 *
 * Typical Usage
 *
 *     for (void *mem_ptr = my_mem.memory_by_name_begin(); mem_ptr!=NULL;
 *          mem_ptr = my_mem.memory_by_name_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   void *memory_by_name_next(void);

/****************************************************************//**
 * \brief
 * Gets initial memory entry from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry memory_item;
 *     for (memory_item = my_mem.memory_entry_begin(); 
 *          memory_item != my_mem.memory_entry_end();
 *          memory_item = my_mem.memory_entry_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_begin(void);

/****************************************************************//**
 * \brief
 * Gets next memory entry from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry memory_item;
 *     for (memory_item = my_mem.memory_entry_begin(); 
 *          memory_item != my_mem.memory_entry_end();
 *          memory_item = my_mem.memory_entry_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_next(void);

/****************************************************************//**
 * \brief
 * Gets initial memory iterator from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry *memory_item;
 *     for (memory_item = my_mem.memory_entry_begin(); 
 *          memory_item != my_mem.memory_entry_end();
 *          memory_item = my_mem.memory_entry_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_end(void);

/****************************************************************//**
 * \brief
 * Gets initial memory entry from name database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry memory_item;
 *     for (memory_item = my_mem.memory_entry_by_name_begin(); 
 *          memory_item != my_mem.memory_entry_by_name_end();
 *          memory_item = my_mem.memory_entry_by_name_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_by_name_begin(void);

/****************************************************************//**
 * \brief
 * Gets next memory entry from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry memory_item;
 *     for (memory_item = my_mem.memory_entry_by_name_begin(); 
 *          memory_item != my_mem.memory_entry_by_name_end();
 *          memory_item = my_mem.memory_entry_by_name_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_by_name_next(void);

/****************************************************************//**
 * \brief
 * Gets initial memory iterator from database for iterating over the
 * entries and processing each.
 *
 * Typical Usage
 *
 *     malloc_plus_memory_entry *memory_item;
 *     for (memory_item = my_mem.memory_entry_by_name_begin(); 
 *          memory_item != my_mem.memory_entry_by_name_end();
 *          memory_item = my_mem.memory_entry_by_name_next() ){
 *        ... process entries ...
 *     }
 *******************************************************************/
   malloc_plus_memory_entry *memory_entry_by_name_end(void);

/****************************************************************//**
 * \brief
 * Get number of elements for a memory pointer in the database.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer for entry in the database
 * 
 * Typical Usage
 *
 *     size_t nsize = my_mem->get_memory_size(density);
 *******************************************************************/
   size_t get_memory_size(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Get the memory capacity in number of elements for a memory pointer
 * in the database. Memory capacity is the overallocated size of the
 * array in schemes where memory is managed internally to reduce
 * the number of reallocations.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer for entry in the database
 * 
 * Typical Usage
 *
 *     size_t var_capacity = my_mem->get_memory_capacity(density);
 *******************************************************************/
   size_t get_memory_capacity(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Get the element size for a memory pointer in the database.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer for entry in the database
 * 
 * Typical Usage
 *
 *     int elsize = my_mem->get_memory_elemsize(density);
 *******************************************************************/
   int get_memory_elemsize(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Get name for a memory pointer in the database.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer for entry in the database
 * 
 * Typical Usage
 *
 *     const char *var_name = my_mem->get_memory_name(density);
 *******************************************************************/
   const char *get_memory_name(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Get memory pointer for a named entry from the database.
 *
 * **Parameters**
 * * const char *name -- name of entry in the database
 * 
 * Typical Usage
 *
 *     density = my_mem->get_memory_ptr("Density");
 *******************************************************************/
   void *get_memory_ptr(const char *name);

/****************************************************************//**
 * \brief
 * Set a memory attribute for a memory pointer in the database.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer of entry in the database
 * * int attribute -- flag to set for entry
 *
 * Typical Usage
 *
 *     my_mem->set_memory_attribute(density, HOST_MANAGED_MEMORY);
 *******************************************************************/
   void set_memory_attribute(void *malloc_mem_ptr, int attribute);

/****************************************************************//**
 * \brief
 * Clear memory attribute for a memory pointer in the database.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer of entry in the database
 * * int attribute -- flag to clear for entry
 *
 * Typical Usage
 *
 *     my_mem->clear_memory_attribute(density, HOST_MANAGED_MEMORY);
 *******************************************************************/
   void clear_memory_attribute(void *malloc_mem_ptr, int attribute);

/****************************************************************//**
 * \brief
 * Get memory attributes for a memory pointer in the database. Returns
 * the flag field.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer of entry in the database
 *
 * Typical Usage
 *
 *     int flag = my_mem->get_memory_attribute(density);
 *******************************************************************/
   int  get_memory_flags(void *malloc_mem_ptr);

/****************************************************************//**
 * \brief
 * Checks the setting for a memory attribute for a memory pointer in
 * the database. Returns true for set and false for unset.
 *
 * **Parameters**
 * * void *malloc_mem_ptr -- memory pointer of entry in the database
 * * int attribute -- flag to check setting for entry
 *
 * Typical Usage
 *
 *     bool flag = my_mem->check_memory_attribute(density, HOST_MANAGED_MEMORY);
 *******************************************************************/
   bool  check_memory_attribute(void *malloc_mem_ptr, int attribute);
};

extern "C" {
  MallocPlus *MallocPlus_new();
           
  void MallocPlus_memory_report(MallocPlus *mem_object);

  void MallocPlus_memory_add(MallocPlus *mem_object, void *dbleptr,
    size_t nelem, size_t elsize, char *name, unsigned long long flags);
  void MallocPlus_memory_add_nD(MallocPlus *mem_object, void *dbleptr,
    int ndim, size_t *nelem, size_t elsize, char *name, unsigned long long flags);
}

#endif // ifndef MALLOCPLUS_H_

