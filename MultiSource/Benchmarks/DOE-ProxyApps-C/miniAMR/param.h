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

max_num_blocks = 500;
target_active = 0;
target_max = 0;
target_min = 0;
num_refine = 5;
uniform_refine = 0;
x_block_size = 10;
y_block_size = 10;
z_block_size = 10;
num_vars = 40;
comm_vars = 0;
init_block_x = 1;
init_block_y = 1;
init_block_z = 1;
reorder = 1;
npx = 1;
npy = 1;
npz = 1;
inbalance = 0;
refine_freq = 5;
report_diffusion = 0;
error_tol = 8;
num_tsteps = 20;
stages_per_ts = 20;
checksum_freq = 5;
stencil = 7;
report_perf = 12;
plot_freq = 0;
num_objects = 0;
lb_opt = 1;
block_change = 0;
code = 0;
permute = 0;
nonblocking = 1;
refine_ghost = 0;
