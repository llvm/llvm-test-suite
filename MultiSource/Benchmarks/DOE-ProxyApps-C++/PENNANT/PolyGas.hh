/*
 * PolyGas.hh
 *
 *  Created on: Mar 23, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef POLYGAS_HH_
#define POLYGAS_HH_

#include "Vec2.hh"

// forward declarations
class InputFile;
class Hydro;


class PolyGas {
public:

    // parent hydro object
    Hydro* hydro;

    double gamma;                  // coeff. for ideal gas equation
    double ssmin;                  // minimum sound speed for gas

    PolyGas(const InputFile* inp, Hydro* h);
    ~PolyGas();

    void calcStateAtHalf(
            const double* zr0,
            const double* zvolp,
            const double* zvol0,
            const double* ze,
            const double* zwrate,
            const double* zm,
            const double dt,
            double* zp,
            double* zss,
            const int zfirst,
            const int zlast);

    void calcEOS(
            const double* zr,
            const double* ze,
            double* zp,
            double* z0per,
            double* zss,
            const int zfirst,
            const int zlast);

    void calcForce(
            const double* zp,
            const double2* ssurfp,
            double2* sf,
            const int sfirst,
            const int slast);

};  // class PolyGas


#endif /* POLYGAS_HH_ */
