
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

// Routine to compute the update of a vector with the sum of two 
// scaled vectors where:

// w = alpha*x + beta*y

// n - number of vector elements (on this processor)

// x, y - input vectors

// alpha, beta - scalars applied to x and y respectively.

// w - output vector.

/////////////////////////////////////////////////////////////////////////

#include "waxpby.hpp"

int waxpby (const int n, const double alpha, const double * const x, 
	    const double beta, const double * const y, 
		     double * const w)
{  
  if (alpha==1.0) {
#ifdef USING_OMP
#pragma omp parallel for
#endif
    for (int i=0; i<n; i++) w[i] = x[i] + beta * y[i];
  }
  else if(beta==1.0) {
#ifdef USING_OMP
#pragma omp parallel for
#endif
    for (int i=0; i<n; i++) w[i] = alpha * x[i] + y[i];
  }
  else {
#ifdef USING_OMP
#pragma omp parallel for
#endif
    for (int i=0; i<n; i++) w[i] = alpha * x[i] + beta * y[i];
  }

  return(0);
}
