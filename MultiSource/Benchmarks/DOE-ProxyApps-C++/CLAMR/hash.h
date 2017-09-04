// Uses LANL Copyright Disclosure C14043/LA-CC-14-003

#ifndef _HASH_H
#define _HASH_H

#ifdef _OPENMP
#include <omp.h>
#endif

#ifdef HAVE_OPENCL
#include "ezcl/ezcl.h"
#endif

enum choose_hash_method
{  METHOD_UNSET = 0,            //  use 0 for no method set
   PERFECT_HASH,                //  perfect hash 1
   LINEAR,                      //  linear hash 2
   QUADRATIC,                   //  quadratic hash 3
   PRIME_JUMP  };               //  prime_jump hash 4

typedef unsigned int uint;
typedef unsigned long ulong;

#ifdef __cplusplus
extern "C"
{
#endif

int *compact_hash_init(int ncells, uint isize, uint jsize, uint report_level);

#ifdef _OPENMP
   int *compact_hash_init_openmp(int ncells, uint isize, uint jsize, uint report_level);
#endif

int get_hash_method(void);
long long get_hash_table_size(void);

void write_hash_perfect(uint ic, ulong hashkey, int *hash);
void write_hash_linear(uint ic, ulong hashkey, int *hash);
void write_hash_linear_report_level_1(uint ic, ulong hashkey, int *hash);
void write_hash_linear_report_level_2(uint ic, ulong hashkey, int *hash);
void write_hash_linear_report_level_3(uint ic, ulong hashkey, int *hash);
void write_hash_quadratic(uint ic, ulong hashkey, int *hash);
void write_hash_quadratic_report_level_1(uint ic, ulong hashkey, int *hash);
void write_hash_quadratic_report_level_2(uint ic, ulong hashkey, int *hash);
void write_hash_quadratic_report_level_3(uint ic, ulong hashkey, int *hash);
void write_hash_primejump(uint ic, ulong hashkey, int *hash);
void write_hash_primejump_report_level_1(uint ic, ulong hashkey, int *hash);
void write_hash_primejump_report_level_2(uint ic, ulong hashkey, int *hash);
void write_hash_primejump_report_level_3(uint ic, ulong hashkey, int *hash);
extern void (*write_hash)(uint ic, ulong hashkey, int *hash); // declared in hash.c

#ifdef _OPENMP
   void write_hash_linear_openmp(uint ic, ulong hashkey, int *hash);
   void write_hash_linear_openmp_report_level_1(uint ic, ulong hashkey, int *hash);
   void write_hash_linear_openmp_report_level_2(uint ic, ulong hashkey, int *hash);
   void write_hash_linear_openmp_report_level_3(uint ic, ulong hashkey, int *hash);
   void write_hash_quadratic_openmp(uint ic, ulong hashkey, int *hash);
   void write_hash_quadratic_openmp_report_level_1(uint ic, ulong hashkey, int *hash);
   void write_hash_quadratic_openmp_report_level_2(uint ic, ulong hashkey, int *hash);
   void write_hash_quadratic_openmp_report_level_3(uint ic, ulong hashkey, int *hash);
   void write_hash_primejump_openmp(uint ic, ulong hashkey, int *hash);
   void write_hash_primejump_openmp_report_level_1(uint ic, ulong hashkey, int *hash);
   void write_hash_primejump_openmp_report_level_2(uint ic, ulong hashkey, int *hash);
   void write_hash_primejump_openmp_report_level_3(uint ic, ulong hashkey, int *hash);
   extern void (*write_hash)(uint ic, ulong hashkey, int *hash); // declared in hash.c
#endif

int read_hash_perfect(ulong hashkey, int *hash);
int read_hash_linear(ulong hashkey, int *hash);
int read_hash_linear_report_level_1(ulong hashkey, int *hash);
int read_hash_linear_report_level_2(ulong hashkey, int *hash);
int read_hash_linear_report_level_3(ulong hashkey, int *hash);
int read_hash_quadratic(ulong hashkey, int *hash);
int read_hash_quadratic_report_level_1(ulong hashkey, int *hash);
int read_hash_quadratic_report_level_2(ulong hashkey, int *hash);
int read_hash_quadratic_report_level_3(ulong hashkey, int *hash);
int read_hash_primejump(ulong hashkey, int *hash);
int read_hash_primejump_report_level_1(ulong hashkey, int *hash);
int read_hash_primejump_report_level_2(ulong hashkey, int *hash);
int read_hash_primejump_report_level_3(ulong hashkey, int *hash);
extern int (*read_hash)(ulong hashkey, int *hash); // declared in hash.c

void compact_hash_delete(int *hash);

void write_hash_collision_report(void);
void read_hash_collision_report(void);
void final_hash_collision_report(void);

const char *get_hash_kernel_source_string(void);
void hash_lib_init(void);
void hash_lib_terminate(void);

#ifdef HAVE_OPENCL
cl_mem gpu_compact_hash_init(ulong ncells, int imaxsize, int jmaxsize, int gpu_hash_method, uint hash_report_level_in,
   ulong *gpu_hash_table_size, ulong *hashsize, cl_mem *dev_hash_header_in);
cl_mem gpu_get_hash_header(void);
void gpu_compact_hash_delete(cl_mem dev_hash, cl_mem dev_hash_header);
#endif
int read_dev_hash(int hash_method, ulong hash_table_size, ulong AA, ulong BB, ulong hashkey, int *hash);

#ifdef __cplusplus
}
#endif


#endif // _HASH_H

