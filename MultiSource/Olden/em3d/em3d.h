/* For copyright information, see olden_v1.0/COPYRIGHT */

/* em3d.h - Header file for the electromagnetic problem in 3 dimensions
 *
 * By:  Martin C. Carlisle
 * Date: Feb. 23, 1994
 *
 */

#ifndef EM3D
#define EM3D

void dealwithargs(int argc, char *argv[]);
void printstats(void);
void srand48(long);
long lrand48(void);

#include <stdio.h>
#include <stdlib.h>

#ifdef TORONTO

#define chatting printf
#define PLAIN
#define local

#define ALLOC(pn, sz) malloc(sz)
#endif
extern char * min_ptr;
extern char * max_ptr;
#define Shutdown(signal) exit(signal)
#define MyNodeId 0
#define LOCAL(xxx) xxx
#define MIGRPH()
#define UNPHASE()
#define ISLOCPTR(xxx) 1
#define Olden_panic printf
#define NOTEST()
#define RETEST()
#define MIGRATE(xxx)
#endif

#ifndef TORONTO
#include "mem-ref.h"
#endif

extern int n_nodes; /* number of nodes (E and H) */
extern int d_nodes; /* degree of nodes */
extern int local_p; /* percentage of local edges */
#define DIST_SPAN 1

#ifdef TORONTO
#define PROCS 1
#else
#define PROCS 64
#endif

#define assert(a) if (!a) {printf("Assertion failure\n"); exit(-1);}

#ifndef MAKE_GRAPH
typedef struct node_t {
  local double *value;
  struct node_t *next;
  struct node_t **to_nodes; /* array of nodes pointed to */
  local double **from_values; /* array of ptrs to vals where data comes from */
  local double *coeffs; /* array of coeffs on edges */
  int from_count;
  int from_length;
} node_t;
#else
typedef struct node_t {
  double *value;
  struct node_t *next;
  struct node_t **to_nodes; /* array of nodes pointed to */
  double **from_values; /* array of ptrs to vals where data comes from */
  double *coeffs; /* array of coeffs on edges */
  int from_count;
  int from_length;
} node_t;
#endif

typedef struct graph_t {
  node_t *e_nodes[PROCS];
  node_t *h_nodes[PROCS];
} graph_t;

typedef struct table_t {
  node_t **e_table[PROCS];
  node_t **h_table[PROCS];
} table_t;

/* Perform 1 step for a nodelist */
void compute_nodes(/*node_t *nodelist*/);





















