
//@HEADER
// ************************************************************************
// 
//               HPCCG: Simple Conjugate Gradient Benchmark Code
//                 Copyright (2006) Sandia Corporation
// 
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
// Questions? Contact Michael A. Heroux (maherou@sandia.gov) 
// 
// ************************************************************************
//@HEADER

/////////////////////////////////////////////////////////////////////////

// Routine to dump matrix in row, col, val format for analysis with Matlab
// Writes to mat.dat
// NOTE:  THIS CODE ONLY WORKS ON SINGLE PROCESSOR RUNS
// Read into matlab using:
//   load mat.dat
//   A=spconvert(mat);

// A - known matrix 

/////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include "dump_matlab_matrix.hpp"

int dump_matlab_matrix( HPC_Sparse_Matrix *A, int rank) {
  const int nrow = A->local_nrow;
  int start_row = nrow*rank; // Each processor gets a section of a chimney stack domain

  FILE * handle = 0;
  if (rank==0) 
    handle = fopen("mat0.dat", "w");
  else if (rank==1)
    handle = fopen("mat1.dat", "w");
  else if (rank==2)
    handle = fopen("mat2.dat", "w");
  else if (rank==3)
    handle = fopen("mat3.dat", "w");
  else return(0);

  for (int i=0; i< nrow; i++) {
      const double * const cur_vals = A->ptr_to_vals_in_row[i];
      const int    * const cur_inds = A->ptr_to_inds_in_row[i];
      const int cur_nnz = A->nnz_in_row[i];
      for (int j=0; j< cur_nnz; j++) fprintf(handle, " %d %d %22.16e\n",start_row+i+1,cur_inds[j]+1,cur_vals[j]);
    }

  fclose(handle);
  return(0);
}
