/* For copyright information, see olden_v1.0/COPYRIGHT */

#include "mst.h"

#ifndef TORONTO
#include <cm/cmmd.h>
#endif

typedef struct blue_return {
  Vertex vert;
  int dist;
} BlueReturn;


typedef struct fc_br {
#ifndef TORONTO
  future_cell_impl impl;
#endif
  BlueReturn value;
} future_cell_BlueReturn;


static BlueReturn BlueRule(Vertex inserted, Vertex vlist) 
{
  BlueReturn retval;
  Vertex tmp,prev;
  Hash hash;
  int dist,dist2;
  int count;
  
  if (!vlist) {
    retval.dist = 999999;
    return retval;
  }
  MLOCAL(vlist);
  prev = vlist;
  retval.vert = vlist;
  retval.dist = vlist->mindist;
  hash = vlist->edgehash;
  dist = (int) HashLookup((unsigned int) inserted, hash);
  /*chatting("Found %d at 0x%x for 0x%x\n",dist,inserted,vlist);*/
  if (dist) 
    {
      if (dist<retval.dist) 
        {
          vlist->mindist = dist;
          retval.dist = dist;
        }
    }
  else chatting("Not found\n");
  
  count = 0;
  /* We are guaranteed that inserted is not first in list */
  for (tmp=vlist->next; tmp; prev=tmp,tmp=tmp->next) 
    {
      count++;
      if (tmp==inserted) 
        {
          Vertex next;

          next = tmp->next;
          prev->next = next;
        }
      else 
        {
          hash = tmp->edgehash; /* <------  6% miss in tmp->edgehash */ 
          dist2 = tmp->mindist;
          dist = (int) HashLookup((unsigned int) inserted, hash);
          /*chatting("Found %d at 0x%x for 0x%x\n",dist,inserted,tmp);*/
          if (dist) 
            {
              if (dist<dist2) 
                {
                  tmp->mindist = dist;
                  dist2 = dist;
                }
            }
          else chatting("Not found\n");
          if (dist2<retval.dist) 
            {
              retval.vert = tmp;
              retval.dist = dist2;
            }
        } /* else */
    } /* for */
  /*chatting("Count was %d\n",count);*/
  return retval;
}

          

static Vertex MyVertexList = NULL;

static void SetMyVertexList(Vertex v) {
  MyVertexList = v;
}

static BlueReturn Do_all_BlueRule(Vertex inserted, int nproc, int pn) {
  future_cell_BlueReturn fcleft;
  BlueReturn retright;

  if (nproc > 1) {
#ifdef FUTURES
     RPC(inserted,nproc/2,pn+nproc/2,TO_PTR(pn+nproc/2),
         Do_all_BlueRule,&fcleft);
     /*FUTURE(inserted,nproc/2,pn+nproc/2,Do_all_BlueRule,&fcleft);*/
     retright = Do_all_BlueRule(inserted,nproc/2,pn);
     RTOUCH(&fcleft);
     /*TOUCH(&fcleft);*/
#else
     fcleft.value = Do_all_BlueRule(inserted,nproc/2,pn+nproc/2);
     retright = Do_all_BlueRule(inserted,nproc/2,pn);
#endif

     if (fcleft.value.dist < retright.dist) {
       retright.dist = fcleft.value.dist;
       retright.vert = fcleft.value.vert;
       }
     return retright;
  }
  else {
     if (inserted == MyVertexList)
       MyVertexList = MyVertexList->next;
     return BlueRule(inserted,MyVertexList);
  }
}

static int ComputeMst(Graph graph,int numproc,int numvert) 
{
  Vertex v;
  Vertex inserted,tmp;
  int cost=0,i,dist;
#ifdef FUTURES
      future_cell_int fc[MAXPROC];
#endif

  /* make copy of graph */
  chatting("Compute phase 1\n");
#ifdef FUTURES
  for (i=0; i<numproc; i++) 
    {
      v=graph->vlist[i];
      RPC(v,v,SetMyVertexList,&fc[i]);
    }
  for (i=0; i<numproc; i++)
    {
      TOUCH(&fc[i]);
    }
#endif

  /* Insert first node */
  inserted = graph->vlist[0];
  tmp = inserted->next;
  graph->vlist[0] = tmp;
  MyVertexList = tmp;
  numvert--;

  /* Announce insertion and find next one */
  chatting("Compute phase 2\n");
  while (numvert) 
    {
      BlueReturn br;
      
      br = Do_all_BlueRule(inserted,numproc,0);
      inserted = br.vert;    
      dist = br.dist;
      numvert--;
      cost = cost+dist;
    }
  return cost;
}

int main(int argc, char *argv[]) 
{
  Graph graph;
  int dist;
  int size;
 
#ifdef FUTURES
  SPMDInit();
#else
#ifndef TORONTO
  filestuff();
#endif
#endif

  size = dealwithargs(argc,argv);
  chatting("Making graph of size %d\n",size);

#ifdef TORONTO
  graph = MakeGraph(size,NumNodes);
#else
  graph = MakeGraph(size,__NumNodes);
#endif
  chatting("Graph completed\n");

#ifndef TORONTO
  CMMD_node_timer_clear(0);
  CMMD_node_timer_start(0);
  ClearAllStats();
#endif

  chatting("About to compute mst \n");

#ifdef TORONTO
  dist = ComputeMst(graph,NumNodes,size);
#else
  dist = ComputeMst(graph,__NumNodes,size);
#endif

#ifndef TORONTO
  CMMD_node_timer_stop(0);
#endif

  chatting("MST has cost %d\n",dist);

#ifndef TORONTO
  chatting("Time elapsed = %f seconds\n",CMMD_node_timer_elapsed(0));
#endif

#ifdef FUTURES
  __ShutDown();
#endif
  exit(0);
}












