/*
 * Parallel.cc
 *
 *  Created on: May 31, 2013
 *      Author: cferenba
 *
 * Copyright (c) 2013, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "Parallel.hh"

#include <vector>
#include <algorithm>
#include <numeric>

#include "Vec2.hh"


namespace Parallel {

#ifdef USE_MPI
// We're running under MPI, so set these to dummy values
// that will be overwritten on MPI_Init.
int numpe = 0;
int mype = -1;
#else
// We're in serial mode, so only 1 PE.
int numpe = 1;
int mype = 0;
#endif


void init() {
#ifdef USE_MPI
    MPI_Init(0, 0);
    MPI_Comm_size(MPI_COMM_WORLD, &numpe);
    MPI_Comm_rank(MPI_COMM_WORLD, &mype);
#endif
}  // init


void final() {
#ifdef USE_MPI
    MPI_Finalize();
#endif
}  // final


void globalMinLoc(double& x, int& xpe) {
    if (numpe == 1) {
        xpe = 0;
        return;
    }
#ifdef USE_MPI
    struct doubleInt {
        double d;
        int i;
    } xdi, ydi;
    xdi.d = x;
    xdi.i = mype;
    MPI_Allreduce(&xdi, &ydi, 1, MPI_DOUBLE_INT, MPI_MINLOC,
            MPI_COMM_WORLD);
    x = ydi.d;
    xpe = ydi.i;
#endif
}


void globalSum(int& x) {
    if (numpe == 1) return;
#ifdef USE_MPI
    int y;
    MPI_Allreduce(&x, &y, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    x = y;
#endif
}


void globalSum(int64_t& x) {
    if (numpe == 1) return;
#ifdef USE_MPI
    int64_t y;
    MPI_Allreduce(&x, &y, 1, MPI_INT64_T, MPI_SUM, MPI_COMM_WORLD);
    x = y;
#endif
}


void globalSum(double& x) {
    if (numpe == 1) return;
#ifdef USE_MPI
    double y;
    MPI_Allreduce(&x, &y, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    x = y;
#endif
}


void gather(int x, int* y) {
    if (numpe == 1) {
        y[0] = x;
        return;
    }
#ifdef USE_MPI
    MPI_Gather(&x, 1, MPI_INT, y, 1, MPI_INT, 0, MPI_COMM_WORLD);
#endif
}


void scatter(const int* x, int& y) {
    if (numpe == 1) {
        y = x[0];
        return;
    }
#ifdef USE_MPI
    MPI_Scatter((void*) x, 1, MPI_INT, &y, 1, MPI_INT, 0, MPI_COMM_WORLD);
#endif
}


template<typename T>
void gathervImpl(
        const T *x, const int numx,
        T* y, const int* numy) {

    if (numpe == 1) {
        std::copy(x, x + numx, y);
        return;
    }
#ifdef USE_MPI
    const int type_size = sizeof(T);
    int sendcount = type_size * numx;
    std::vector<int> recvcount, disp;
    if (mype == 0) {
        recvcount.resize(numpe);
        for (int pe = 0; pe < numpe; ++pe) {
            recvcount[pe] = type_size * numy[pe];
        }
        // exclusive scan isn't available in the standard library,
        // so we use an inclusive scan and displace it by one place
        disp.resize(numpe + 1);
        std::partial_sum(recvcount.begin(), recvcount.end(), &disp[1]);
    } // if mype

    MPI_Gatherv((void*) x, sendcount, MPI_BYTE,
            y, &recvcount[0], &disp[0], MPI_BYTE,
            0, MPI_COMM_WORLD);
#endif

}


template<>
void gatherv(
        const double2 *x, const int numx,
        double2* y, const int* numy) {
    gathervImpl(x, numx, y, numy);
}


template<>
void gatherv(
        const double *x, const int numx,
        double* y, const int* numy) {
    gathervImpl(x, numx, y, numy);
}


template<>
void gatherv(
        const int *x, const int numx,
        int* y, const int* numy) {
    gathervImpl(x, numx, y, numy);
}


}  // namespace Parallel

