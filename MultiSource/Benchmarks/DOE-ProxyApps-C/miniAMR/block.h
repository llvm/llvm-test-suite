// ************************************************************************
//
// miniAMR: stencil computations with boundary exchange and AMR.
//
// Copyright (2014) Sandia Corporation. Under the terms of Contract
// DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government 
// retains certain rights in this software.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
// Questions? Contact Courtenay T. Vaughan (ctvaugh@sandia.gov)
//                    Richard F. Barrett (rfbarre@sandia.gov)
//
// ************************************************************************

typedef struct {
   int number;
   int level;
   int refine;
   int new_proc;
   int parent;       // if original block -1,
                     // else if on node, number in structure
                     // else (-2 - parent->number)
   int parent_node;
   int child_number;
   int nei_refine[6];
   int nei_level[6];  /* 0 to 5 = W, E, S, N, D, U; use -2 for boundary */
   int nei[6][2][2];  /* negative if off processor (-1 - proc) */
   int cen[3];
   double ****array;
} block;
block *blocks;

typedef struct {
   int number;
   int level;
   int parent;      // -1 if original block
   int parent_node;
   int child_number;
   int refine;
   int child[8];    // n if on node, number if not
                    // if negative, then onnode child is a parent (-1 - n)
   int child_node[8];
   int cen[3];
} parent;
parent *parents;

typedef struct {
   int number;     // number of block
   int n;          // position in block array
} sorted_block;
sorted_block *sorted_list;
int *sorted_index;

int my_pe;
int num_pes;

int max_num_blocks;
int target_active;
int target_max;
int target_min;
int num_refine;
int uniform_refine;
int x_block_size, y_block_size, z_block_size;
int num_vars;
int comm_vars;
int init_block_x, init_block_y, init_block_z;
int reorder;
int npx, npy, npz;
int inbalance;
int refine_freq;
int report_diffusion;
int checksum_freq;
int stages_per_ts;
int error_tol;
int num_tsteps;
int stencil;
int report_perf;
int plot_freq;
int lb_opt;
int block_change;
int code;
int permute;
int nonblocking;
int refine_ghost;

int max_num_parents;
int num_parents;
int max_active_parent;
int cur_max_level;
int *num_blocks;
int *block_start;
int num_active;
int max_active_block;
int global_active;
int x_block_half, y_block_half, z_block_half;
double tol;
double *grid_sum;
int *p8, *p2;
int mesh_size[3];
int max_mesh_size;
int *from, *to;
int msg_len[3][4];
int local_max_b;
int global_max_b;

int num_objects;
typedef struct {
   int type;
   int bounce;
   double cen[3];
   double orig_cen[3];
   double move[3];
   double orig_move[3];
   double size[3];
   double orig_size[3];
   double inc[3];
} object;
object *objects;
