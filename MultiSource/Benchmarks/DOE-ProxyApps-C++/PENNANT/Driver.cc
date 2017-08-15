/*
 * Driver.cc
 *
 *  Created on: Jan 23, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "Driver.hh"

#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#ifdef _OPENMP
#include "omp.h"
#endif

#include "Parallel.hh"
#include "InputFile.hh"
#include "Mesh.hh"
#include "Hydro.hh"

using namespace std;


Driver::Driver(const InputFile* inp, const string& pname)
        : probname(pname) {
    using Parallel::numpe;
    using Parallel::mype;

    if (mype == 0) {
        cout << "********************" << endl;
        cout << "Running PENNANT v0.9" << endl;
        cout << "********************" << endl;
        cout << endl;

#ifdef USE_MPI
        cout << "Running on " << numpe << " MPI PE(s)" << endl;
#endif
#ifdef _OPENMP
        cout << "Running on " << omp_get_max_threads() << " thread(s)"
             << endl;
#endif
    }  // if mype == 0

    cstop = inp->getInt("cstop", 999999);
    tstop = inp->getDouble("tstop", 1.e99);
    if (cstop == 999999 && tstop == 1.e99) {
        if (mype == 0)
            cerr << "Must specify either cstop or tstop" << endl;
        exit(1);
    }
    dtmax = inp->getDouble("dtmax", 1.e99);
    dtinit = inp->getDouble("dtinit", 1.e99);
    dtfac = inp->getDouble("dtfac", 1.2);
    dtreport = inp->getInt("dtreport", 10);

    // initialize mesh, hydro
    mesh = new Mesh(inp);
    hydro = new Hydro(inp, mesh);

}

Driver::~Driver() {

    delete hydro;
    delete mesh;

}

void Driver::run() {
    using Parallel::mype;

    time = 0.0;
    cycle = 0;

    // do energy check
    hydro->writeEnergyCheck();

    double tbegin, tlast;
    if (mype == 0) {
        // get starting timestamp
        struct timeval sbegin;
        gettimeofday(&sbegin, NULL);
        tbegin = sbegin.tv_sec + sbegin.tv_usec * 1.e-6;
        tlast = tbegin;
    }

    // main event loop
    while (cycle < cstop && time < tstop) {

        cycle += 1;

        // get timestep
        calcGlobalDt();

        // begin hydro cycle
        hydro->doCycle(dt);

        time += dt;

        if (mype == 0 &&
                (cycle == 1 || cycle % dtreport == 0)) {
            struct timeval scurr;
            gettimeofday(&scurr, NULL);
            double tcurr = scurr.tv_sec + scurr.tv_usec * 1.e-6;
            double tdiff = tcurr - tlast;

            cout << scientific << setprecision(5);
            #ifdef PRINT_TIME
            cout << "End cycle " << setw(6) << cycle
                 << ", time = " << setw(11) << time
                 << ", dt = " << setw(11) << dt
                 << ", wall = " << setw(11) << tdiff << endl;
            #endif
            cout << "dt limiter: " << msgdt << endl;

            tlast = tcurr;
        } // if mype...

    } // while cycle...

    if (mype == 0) {

        // get stopping timestamp
        struct timeval send;
        gettimeofday(&send, NULL);
        double tend = send.tv_sec + send.tv_usec * 1.e-6;
        double runtime = tend - tbegin;

        // write end message
        cout << endl;
        cout << "Run complete" << endl;
        cout << scientific << setprecision(6);
        cout << "cycle = " << setw(6) << cycle
             << ",         cstop = " << setw(6) << cstop << endl;
        cout << "time  = " << setw(14) << time
             << ", tstop = " << setw(14) << tstop << endl;

        cout << endl;
        #ifdef PRINT_TIME
        cout << "************************************" << endl;
        cout << "hydro cycle run time= " << setw(14) << runtime << endl;
        cout << "************************************" << endl;
        #endif

    } // if mype

    // do energy check
    hydro->writeEnergyCheck();

    // do final mesh output
    mesh->write(probname, cycle, time,
            hydro->zr, hydro->ze, hydro->zp);

}


void Driver::calcGlobalDt() {

    using Parallel::mype;

    // Save timestep from last cycle
    dtlast = dt;
    msgdtlast = msgdt;

    // Compute timestep for this cycle
    dt = dtmax;
    msgdt = "Global maximum (dtmax)";

    if (cycle == 1) {
        // compare to initial timestep
        if (dtinit < dt) {
            dt = dtinit;
            msgdt = "Initial timestep";
        }
    } else {
        // compare to factor * previous timestep
        double dtrecover = dtfac * dtlast;
        if (dtrecover < dt) {
            dt = dtrecover;
            if (msgdtlast.substr(0, 8) == "Recovery")
                msgdt = msgdtlast;
            else
                msgdt = "Recovery: " + msgdtlast;
        }
    }

    // compare to time-to-end
    if ((tstop - time) < dt) {
        dt = tstop - time;
        msgdt = "Global (tstop - time)";
    }

    // compare to hydro dt
    hydro->getDtHydro(dt, msgdt);

#ifdef USE_MPI
    int pedt;
    Parallel::globalMinLoc(dt, pedt);

    // if the global min isn't on this PE, get the right message
    if (pedt > 0) {
        const int tagmpi = 300;
        if (mype == pedt) {
            char cmsgdt[80];
            strncpy(cmsgdt, msgdt.c_str(), 80);
            MPI_Send(cmsgdt, 80, MPI_CHAR, 0, tagmpi,
                    MPI_COMM_WORLD);
        }
        else if (mype == 0) {
            char cmsgdt[80];
            MPI_Status status;
            MPI_Recv(cmsgdt, 80, MPI_CHAR, pedt, tagmpi,
                    MPI_COMM_WORLD, &status);
            cmsgdt[79] = '\0';
            msgdt = string(cmsgdt);
        }
    }  // if pedt > 0

    // if timestep was determined by hydro, report which PE
    // caused it
    if (mype == 0 && msgdt.substr(0, 5) == "Hydro") {
        ostringstream oss;
        oss << "PE " << pedt << ", " << msgdt;
        msgdt = oss.str();
    }
#endif

}

