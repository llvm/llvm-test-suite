/*
 * Driver.hh
 *
 *  Created on: Jan 23, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef DRIVER_HH_
#define DRIVER_HH_

#include <string>

// forward declarations
class InputFile;
class Mesh;
class Hydro;


class Driver {
public:

    // children of this object
    Mesh *mesh;
    Hydro *hydro;

    std::string probname;          // problem name
    double time;                   // simulation time
    int cycle;                     // simulation cycle number
    double tstop;                  // simulation stop time
    int cstop;                     // simulation stop cycle
    double dtmax;                  // maximum timestep size
    double dtinit;                 // initial timestep size
    double dtfac;                  // factor limiting timestep growth
    int dtreport;                  // frequency for timestep reports
    double dt;                     // current timestep
    double dtlast;                 // previous timestep
    std::string msgdt;             // dt limiter message
    std::string msgdtlast;         // previous dt limiter message

    Driver(const InputFile* inp, const std::string& pname);
    ~Driver();

    void run();
    void calcGlobalDt();

};  // class Driver


#endif /* DRIVER_HH_ */
