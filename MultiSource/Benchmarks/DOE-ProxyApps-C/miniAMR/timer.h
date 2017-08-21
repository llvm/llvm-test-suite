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

double average[128];
double stddev[128];
double minimum[128];
double maximum[128];

double timer_all;

double timer_comm_all;
double timer_comm_dir[3];
double timer_comm_same[3];
double timer_comm_diff[3];
double timer_comm_bc[3];

double timer_calc_all;

double timer_cs_all;
double timer_cs_calc;

double timer_refine_all;
double timer_refine_co;
double timer_refine_mr;
double timer_refine_sb;
double timer_refine_cc;
double timer_cb_all;
double timer_target_all;
double timer_target_rb;
double timer_target_dc;
double timer_target_cb;
double timer_target_ab;
double timer_target_da;
double timer_target_sb;

double timer_plot;

long total_blocks;
int nb_min;
int nb_max;
int nrs;
int nps;
int num_refined;
int num_reformed;
int counter_bc[3];
int counter_same[3];
int counter_diff[3];
int counter_malloc;
double size_malloc;
int counter_malloc_init;
double size_malloc_init;
int total_red;
