/* For copyright information, see olden_v1.0/COPYRIGHT */

/* make_graph.c - Create a graph to be solved for the electromagnetic
 *                problem in 3 dimensions.
 *
 * By:  Martin C. Carlisle
 * Date: Feb 23, 1994
 *
 */

#define SEED1 793
#define SEED2 39
#define SEED3 17
#define MAKE_GRAPH
#include "em3d.h"
#include "util.h"

#ifdef TORONTO
extern int NumNodes;
int NumMisses;
#endif

#define NUM_H_NODES  n_nodes
#define H_NODE_DEGREE d_nodes
#define H_PERCENT_LOCAL local_p

#define NUM_E_NODES  n_nodes
#define E_NODE_DEGREE d_nodes
#define E_PERCENT_LOCAL local_p
int n_nodes;
int d_nodes;
int local_p;

node_t **make_table(int size, int procname)
{
  node_t **retval;

  retval = (node_t **) ALLOC(procname,size*sizeof(node_t *));
  assert(retval);
  return retval;
}

/* We expect node_table to be a local table of e or h nodes */
void fill_table(node_t **node_table, double *values, int size, int procname)
{
  node_t *cur_node, *prev_node;
  int i;
  
  prev_node = (node_t *) ALLOC(procname,sizeof(node_t));
  node_table[0] = prev_node;
  *values = gen_uniform_double();
  prev_node->value = values++;
  prev_node->from_count = 0;
  
  /* Now we fill the node_table with allocated nodes */
  for (i=1; i<size; i++)
    {
      cur_node = (node_t *) ALLOC(procname,sizeof(node_t));
      *values = gen_uniform_double();
      cur_node->value = values++;
      cur_node->from_count = 0;
      node_table[i] = cur_node;
      prev_node->next = cur_node;
      prev_node = cur_node;
    }
  cur_node->next = NULL;
}

void make_neighbors(node_t *nodelist, node_t **table[], int tablesz,
		    int degree, int percent_local, int id)
{
  node_t *cur_node;
#ifndef TORONTO
  int procname = MyNodeId & IDMASK;
#else
  int procname = 0;
#endif  

  for(cur_node = nodelist; cur_node; cur_node=cur_node->next)
    {
      node_t *other_node;
      int j,k;
      int dest_proc;

      cur_node->to_nodes = (node_t **)
	ALLOC(procname,degree*(sizeof(node_t *)));
  if (!cur_node->to_nodes) {
    chatting("Uncaught malloc error\n");
     Shutdown(0);}
      for (j=0; j<degree; j++) 
	{
	  do 
	    {
	      node_t **local_table;
         int number = gen_number(tablesz);
	      
	      dest_proc = (check_percent(percent_local) ? id :
			   (id + PROCS +
			    4*gen_signed_number(DIST_SPAN)) % PROCS);
	      /* We expect these accesses to be remote */
	      local_table = table[dest_proc];
	      other_node = local_table[number];        /* <------ 4% load miss penalty */
         if (!other_node) {
                 chatting("Error! on dest %d @ %d\n",number,dest_proc);
                 Shutdown(0);
          }
	      for (k=0; k<j; k++)
		if (other_node == cur_node->to_nodes[k]) break;
     if ((((unsigned long long) other_node) >> 7) < 2048)    /* <------ 5% load miss penalty */
       chatting("pre other_node = 0x%x,number = %d,dest = %d\n",
             other_node,number,dest_proc);
	    }
	  while (k<j);
    if (!cur_node || !cur_node->to_nodes) {
      chatting("Error! no to_nodes filed on 0x%x\n",cur_node);
      Shutdown(0);}
	  cur_node->to_nodes[j]=other_node;            /* <------ 6.5% store penalty */
     if ((((unsigned long long) other_node) >> 7) < 2048)
       chatting("post other_node = 0x%x\n",other_node);
#ifndef TORONTO
	  ATOMICINC(&other_node->from_count);
#else
	  ++(other_node->from_count);            /* <----- 12% load miss penalty */
#endif
	}
    }
}

void update_from_coeffs(node_t *nodelist)
{
  node_t *cur_node;
#ifndef TORONTO
  int procname = MyNodeId & IDMASK;
#else
  int procname = 0;
#endif  
  /* Setup coefficient and from_nodes vectors for h nodes */  
  for (cur_node = nodelist; cur_node; cur_node=cur_node->next) 
    {
      int from_count = cur_node->from_count;
      int k;
#ifdef TORONTO
     if (from_count < 1) {
       chatting("Help! no from count (from_count=%d) \n", from_count);
       cur_node->from_values = (double **)
	ALLOC(procname,20 * sizeof(double *));
       cur_node->coeffs = (double *)
	ALLOC(procname,20 * sizeof(double));
       cur_node->from_length = 0;
     }
     else{
       cur_node->from_values = (double **)
	ALLOC(procname,from_count * sizeof(double *));
      cur_node->coeffs = (double *)
	ALLOC(procname,from_count * sizeof(double));
      cur_node->from_length = 0;
     }
#else      
     if (from_count < 1) chatting("Help! no from count (from_count=%d) \n", from_count);
      cur_node->from_values = (double **)
	ALLOC(procname,from_count * sizeof(double *));
      cur_node->coeffs = (double *)
	ALLOC(procname,from_count * sizeof(double));
      cur_node->from_length = 0;
#endif
    }
}

void fill_from_fields(node_t *nodelist, int degree)
{
  node_t *cur_node;
  for(cur_node = nodelist; cur_node; cur_node = cur_node->next)
    {
      int j;

      for (j=0; j<degree; j++)
	{
	  int count,thecount;
	  node_t *other_node = cur_node->to_nodes[j]; /* <---- 6% load miss penalty */
     double **otherlist;
     double *value = cur_node->value;

     if (!other_node) chatting("Help!!\n");
#ifndef TORONTO
	  count=ATOMICINC(&(other_node->from_length));
#else
	   count=(other_node->from_length)++;  /* <----- 30% load miss penalty */
#endif
     otherlist=other_node->from_values;        /* <----- 10% load miss penalty */
     thecount=other_node->from_count;
     if (!otherlist) {
      MIGRPH();
      chatting("node 0x%x list 0x%x count %d\n",other_node,otherlist,thecount);
      otherlist = other_node->from_values;
      Olden_panic("No from list!! 0x%x\n",otherlist);
      UNPHASE();
     }
#ifndef TORONTO
     if (CMMD_self_address() > NumNodes) Olden_panic("yipes!\n");
#endif
	  otherlist[count] = value;                   /* <------ 42% store penalty */
#ifndef TORONTO
     if (CMMD_self_address() > NumNodes) Olden_panic("yipes!\n");
#endif
     other_node->coeffs[count]=gen_uniform_double();   /* <----- 42+6.5% store penalty */
	}
    }
}

void localize_local(node_t *nodelist)
{
  node_t *cur_node;
  NOTEST();
  for(cur_node = nodelist; cur_node; cur_node = cur_node->next)
   {
    cur_node->coeffs = LOCAL(cur_node->coeffs);
    cur_node->from_values =  LOCAL(cur_node->from_values);
    cur_node->value =  LOCAL(cur_node->value);
   }
  RETEST();
}


void make_tables(table_t *table,int groupname)
{
  node_t **h_table,**e_table;
  double *h_values, *e_values;
#ifndef TORONTO
  int procname = MyNodeId & IDMASK;
#else
  int procname = 0;
#endif  
  init_random(SEED1*groupname);
  h_values = (double *) ALLOC(procname,NUM_H_NODES/PROCS*sizeof(double));
  h_table = make_table(NUM_H_NODES/PROCS,procname);
  fill_table(h_table,h_values,NUM_H_NODES/PROCS,procname);
  e_values = (double *) ALLOC(procname,NUM_E_NODES/PROCS*sizeof(double));
  e_table = make_table(NUM_E_NODES/PROCS,procname);
  fill_table(e_table,e_values,NUM_E_NODES/PROCS,procname);

  /* This is done on procname-- we expect table to be remote */
  /* We use remote writes */
  table->e_table[groupname] = e_table;
  table->h_table[groupname] = h_table;
}

void make_all_neighbors(table_t *table,int groupname)
{
  node_t *first_node;
  node_t **local_table;
  node_t ***local_table_array;

  init_random(SEED2*groupname);
  /* We expect table to be remote */
  local_table = table->h_table[groupname];
  local_table_array = table->e_table;
  first_node = local_table[0];
  make_neighbors(first_node,
		 local_table_array,NUM_E_NODES/PROCS,
		 H_NODE_DEGREE,H_PERCENT_LOCAL,groupname);

  local_table = table->e_table[groupname];
  local_table_array = table->h_table;
  first_node = local_table[0];
  make_neighbors(first_node,
		 local_table_array,NUM_H_NODES/PROCS,
		 E_NODE_DEGREE,E_PERCENT_LOCAL,groupname);
}

void update_all_from_coeffs(table_t *table, int groupname)    
{
  node_t **local_table;
  node_t *first_node;

  /* Done by do_all, table not local */
  local_table = table->h_table[groupname];
  /* We expect this to be local */
  first_node = local_table[0];
  update_from_coeffs(first_node);

  local_table = table->e_table[groupname];
  first_node = local_table[0];
  update_from_coeffs(first_node);
}

void fill_all_from_fields(table_t *table, int groupname)
{
  node_t **local_table;
  node_t *first_node;

  init_random(SEED3*groupname);
  local_table = table->h_table[groupname];
  first_node = local_table[0];
  fill_from_fields(first_node,H_NODE_DEGREE);

  local_table = table->e_table[groupname];
  first_node = local_table[0];
  fill_from_fields(first_node,E_NODE_DEGREE);
}

void localize(table_t *table, int groupname)
{
  node_t **local_table;
  node_t *first_node;

  local_table = table->h_table[groupname];
  first_node = local_table[0];
  localize_local(first_node);

  local_table = table->e_table[groupname];
  first_node = local_table[0];
  localize_local(first_node);
}
  
void clear_nummiss(table_t *table, int groupname)
{
  NumMisses = 0;
}

void do_all(table_t *table, int groupname, int nproc,
	    void func(table_t *, int),int groupsize)
{
  int procname = groupname / groupsize;
#ifdef FUTURES
  future_cell_int f_left;

  if (NONLOCAL(procname)) MIGRATE(procname);
#endif

  /*chatting("do all group %d with %d\n",groupname,nproc);*/
  if (nproc > 1)
    {
#ifdef FUTURES      
      FUTURE(table,groupname+nproc/2,nproc/2,func,groupsize,do_all,&f_left);
      do_all(table,groupname,nproc/2,func,groupsize);
      TOUCH(&f_left);
#else
      do_all(table,groupname+nproc/2,nproc/2,func,groupsize);
      do_all(table,groupname,nproc/2,func,groupsize);
#endif      
    }
  else
    {
      func(table,groupname);
    }
}

graph_t *initialize_graph()
{
  table_t *table;
  graph_t *retval;
  int i,j,blocksize;
  int groupsize;

  table = (table_t *) ALLOC(0,sizeof(table_t));
  retval = (graph_t *) ALLOC(0,sizeof(graph_t));


  groupsize = PROCS/NumNodes;



  chatting("making tables \n");
  do_all(table,0,PROCS,make_tables,groupsize);


  /*for (i=0; i<64; i++) {
    node_t **e_table, *n1, *n2, *n3;
    e_table = table->e_table[i];
    n1 = e_table[1];
    n2 = e_table[2];
    n3 = e_table[3];
    chatting("0x%x, [0x%x,0x%x,0x%x...]\n",e_table,n1,n2,n3);
  } */
  /* At this point, for each h node, we give it the appropriate number
     of neighbors as defined by the degree */
  chatting("making neighbors\n");

  do_all(table,0,PROCS,make_all_neighbors,groupsize);

  /* We now create from count and initialize coefficients */
  chatting("updating from and coeffs\n");
  do_all(table,0,PROCS,update_all_from_coeffs,groupsize);

  /* Fill the from fields in the nodes */
  chatting("filling from fields\n");
  do_all(table,0,PROCS,fill_all_from_fields,groupsize);

  chatting("localizing coeffs, from_nodes\n");
  do_all(table,0,PROCS,localize,groupsize);


  blocksize = PROCS/NumNodes;

  chatting("cleanup for return now\n");
  for (i=0; i<NumNodes; i++)
    {
      node_t **local_table;
      node_t *local_node_r;

      local_table = table->e_table[i*blocksize];
      local_node_r = local_table[0];
      retval->e_nodes[i]=local_node_r;
      
      local_table = table->h_table[i*blocksize];
      local_node_r = local_table[0];
      retval->h_nodes[i]=local_node_r;
      
      for (j=1; j<blocksize; j++)
	{
	  node_t *local_node_l;

	  local_table = table->e_table[i*blocksize+j-1];
	  local_node_l = local_table[(NUM_E_NODES/PROCS)-1];
	  local_table = table->e_table[i*blocksize+j];
	  local_node_r = local_table[0];
	  local_node_l->next = local_node_r;

	  local_table = table->h_table[i*blocksize+j-1];
	  local_node_l = local_table[(NUM_H_NODES/PROCS)-1];
	  local_table = table->h_table[i*blocksize+j];
	  local_node_r = local_table[0];
	  local_node_l->next = local_node_r;
	}
    }
  
  chatting("Clearing NumMisses\n");
  do_all(table,0,PROCS,clear_nummiss,groupsize);
  chatting("Returning\n");

  return retval;
}


