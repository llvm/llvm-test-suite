/*
 * Hydro.hh
 *
 *  Created on: Dec 22, 2011
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef HYDRO_HH_
#define HYDRO_HH_

#include <string>
#include <vector>

#include "Vec2.hh"

// forward declarations
class InputFile;
class Mesh;
class PolyGas;
class TTS;
class QCS;
class HydroBC;


class Hydro {
public:

    // associated mesh object
    Mesh* mesh;

    // children of this object
    PolyGas* pgas;
    TTS* tts;
    QCS* qcs;
    std::vector<HydroBC*> bcs;

    double cfl;                 // Courant number, limits timestep
    double cflv;                // volume change limit for timestep
    double rinit;               // initial density for main mesh
    double einit;               // initial energy for main mesh
    double rinitsub;            // initial density in subregion
    double einitsub;            // initial energy in subregion
    double uinitradial;         // initial velocity in radial direction
    std::vector<double> bcx;    // x values of x-plane fixed boundaries
    std::vector<double> bcy;    // y values of y-plane fixed boundaries

    double dtrec;               // maximum timestep for hydro
    char msgdtrec[80];          // message:  reason for dtrec

    double2* pu;       // point velocity
    double2* pu0;      // point velocity, start of cycle
    double2* pap;      // point acceleration
    double2* pf;       // point force
    double* pmaswt;    // point mass, weighted by 1/r
    double* cmaswt;    // corner contribution to pmaswt

    double* zm;        // zone mass
    double* zr;        // zone density
    double* zrp;       // zone density, middle of cycle
    double* ze;        // zone specific internal energy
                       // (energy per unit mass)
    double* zetot;     // zone total internal energy
    double* zw;        // zone work done in cycle
    double* zwrate;    // zone work rate
    double* zp;        // zone pressure
    double* zss;       // zone sound speed
    double* zdu;       // zone velocity difference

    double2* sfp;      // side force from pressure
    double2* sfq;      // side force from artificial visc.
    double2* sft;      // side force from tts
    double2* cftot;    // corner force, total from all sources

    Hydro(const InputFile* inp, Mesh* m);
    ~Hydro();

    void init();

    void initRadialVel(
            const double vel,
            const int pfirst,
            const int plast);

    void doCycle(const double dt);

    void advPosHalf(
            const double2* px0,
            const double2* pu0,
            const double dt,
            double2* pxp,
            const int pfirst,
            const int plast);

    void advPosFull(
            const double2* px0,
            const double2* pu0,
            const double2* pa,
            const double dt,
            double2* px,
            double2* pu,
            const int pfirst,
            const int plast);

    void calcCrnrMass(
            const double* zr,
            const double* zarea,
            const double* smf,
            double* cmaswt,
            const int sfirst,
            const int slast);

    void sumCrnrForce(
            const double2* sf,
            const double2* sf2,
            const double2* sf3,
            double2* cftot,
            const int sfirst,
            const int slast);

    void calcAccel(
            const double2* pf,
            const double* pmass,
            double2* pa,
            const int pfirst,
            const int plast);

    void calcRho(
            const double* zm,
            const double* zvol,
            double* zr,
            const int zfirst,
            const int zlast);

    void calcWork(
            const double2* sf,
            const double2* sf2,
            const double2* pu0,
            const double2* pu,
            const double2* px0,
            const double dt,
            double* zw,
            double* zetot,
            const int sfirst,
            const int slast);

    void calcWorkRate(
            const double* zvol0,
            const double* zvol,
            const double* zw,
            const double* zp,
            const double dt,
            double* zwrate,
            const int zfirst,
            const int zlast);

    void calcEnergy(
            const double* zetot,
            const double* zm,
            double* ze,
            const int zfirst,
            const int zlast);

    void sumEnergy(
            const double* zetot,
            const double* zarea,
            const double* zvol,
            const double* zm,
            const double* smf,
            const double2* px,
            const double2* pu,
            double& ei,
            double& ek,
            const int zfirst,
            const int zlast,
            const int sfirst,
            const int slast);

    void calcDtCourant(
            const double* zdl,
            double& dtrec,
            char* msgdtrec,
            const int zfirst,
            const int zlast);

    void calcDtVolume(
            const double* zvol,
            const double* zvol0,
            const double dtlast,
            double& dtrec,
            char* msgdtrec,
            const int zfirst,
            const int zlast);

    void calcDtHydro(
            const double* zdl,
            const double* zvol,
            const double* zvol0,
            const double dtlast,
            const int zfirst,
            const int zlast);

    void getDtHydro(
            double& dtnew,
            std::string& msgdtnew);

    void resetDtHydro();

    void writeEnergyCheck();

}; // class Hydro



#endif /* HYDRO_HH_ */
