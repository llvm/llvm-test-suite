/* For copyright information, see olden_v1.0/COPYRIGHT */

#include "em3d.h"
#include "make_graph.h"

#ifndef TORONTO
#include <cm/cmmd.h>
#endif

#ifdef TORONTO
extern int NumNodes;
#endif

int DebugFlag;

void print_graph(graph_t *graph, int id) 
{
  node_t *cur_node;
  cur_node=graph->e_nodes[id];

  for(; cur_node; cur_node=cur_node->next)
    {
      chatting("E: value %f, from_count %d\n",cur_node->value,
	       cur_node->from_count);
    }
  cur_node=graph->h_nodes[id];
  for(; cur_node; cur_node=cur_node->next)
    {
      chatting("H: value %f, from_count %d\n",cur_node->value,
	       cur_node->from_count);
    }
}

extern int nonlocals;

#ifndef PLAIN
void do_all_compute(graph_t *graph, int myid, int nproc)
{
  future_cell_int fleft;

  if (NONLOCAL(myid)) MIGRATE(myid);
  if (nproc>1) {
    FUTURE(graph,myid+nproc/2,nproc/2,do_all_compute,&fleft);
    do_all_compute(graph,myid,nproc/2);
    TOUCH(&fleft);
  }
  else
  {
    node_t *nodelist;

    nodelist=graph->e_nodes[myid];
    compute_nodes(nodelist);
    nodelist=graph->h_nodes[myid];
    compute_nodes(nodelist);
  }
}
#endif
int main(int argc, char *argv[])
{
  int i;
  graph_t *graph;

#ifndef PLAIN
  SPMDInit(argc,argv);
#else
#ifndef TORONTO
  filestuff();
#endif
  dealwithargs(argc,argv);
#endif
  chatting("Hello world--Doing em3d with args %d %d %d %d\n",
    n_nodes,d_nodes,local_p,NumNodes);
  graph=initialize_graph();
  if (DebugFlag) 
    for(i=0; i<NumNodes;i++)
      { MIGRATE(i);
        print_graph(graph,i);
      }

#ifndef PLAIN
  MIGRATE(0);
#endif
#ifndef TORONTO
  ClearAllStats();

  CMMD_node_timer_clear(0);
  CMMD_node_timer_start(0);
#endif
#ifndef PLAIN
  do_all_compute(graph,0,NumNodes);
#else
  compute_nodes(graph->e_nodes[0]);
  compute_nodes(graph->h_nodes[0]);
#endif
#ifndef TORONTO
  CMMD_node_timer_stop(0);
#endif
  chatting("nonlocals = %d\n",nonlocals);
#ifndef TORONTO
  chatting("Completed a computation phase %f\n",CMMD_node_timer_elapsed(0));
#endif
  printstats();
/*****
  for(i=0; i<NumNodes;i++)
  { MIGRATE(i);
  print_graph(graph,i);
  }
*****/
#ifndef TORONTO
  MIGRATE(0);
#endif
#ifndef PLAIN
  __ShutDown(0);
#endif
  
}
