/* For copyright information, see olden_v1.0/COPYRIGHT */

#include "hash.h"
#ifdef TORONTO
#define MAXPROC 1
#else
#define MAXPROC 32
#endif
#define NULL 0

#ifdef TORONTO
#define chatting printf
#define ALLOC(p, sz) malloc(sz)
#define PLAIN
extern int NumNodes;
#endif

#ifdef FUTURES
#include "future-cell.h"
#endif
#ifndef TORONTO
#include "mem-ref.h"
#endif
#ifdef PLAIN
#define MLOCAL(ptr)
#endif

#ifdef TORONTO
typedef struct vert_st {
  int mindist;
  struct vert_st *next;
  Hash edgehash;
  } *Vertex;
#else
typedef struct vert_st {
  int mindist;
  struct vert_st *next {99};
  Hash edgehash;
  } *Vertex;
#endif

typedef struct graph_st {
  Vertex vlist[MAXPROC];
  } *Graph;

Graph MakeGraph(int numvert, int numproc);








