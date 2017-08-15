/*
 * Parallel.hh
 *
 *  Created on: May 31, 2013
 *      Author: cferenba
 *
 * Copyright (c) 2013, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef PARALLEL_HH_
#define PARALLEL_HH_

#include <stdint.h>

#ifdef USE_MPI
#include "mpi.h"
#endif


// Namespace Parallel provides helper functions and variables for
// running in distributed parallel mode using MPI, or for stubbing
// these out if not using MPI.

namespace Parallel {
    extern int numpe;           // number of MPI PEs in use
                                // (1 if not using MPI)
    extern int mype;            // PE number for my rank
                                // (0 if not using MPI)

    void init();                // initialize MPI
    void final();               // finalize MPI

    void globalMinLoc(double& x, int& xpe);
                                // find minimum over all PEs, and
                                // report which PE had the minimum
    void globalSum(int& x);     // find sum over all PEs - overloaded
    void globalSum(int64_t& x);
    void globalSum(double& x);
    void gather(const int x, int* y);
                                // gather list of ints from all PEs
    void scatter(const int* x, int& y);
                                // gather list of ints from all PEs

    template<typename T>
    void gatherv(               // gather variable-length list
            const T *x, const int numx,
            T* y, const int* numy);
    template<typename T>
    void gathervImpl(           // helper function for gatherv
            const T *x, const int numx,
            T* y, const int* numy);

}  // namespace Parallel


#endif /* PARALLEL_HH_ */
