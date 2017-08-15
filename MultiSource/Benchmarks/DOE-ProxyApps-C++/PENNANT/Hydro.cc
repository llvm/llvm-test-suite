/*
 * Hydro.cc
 *
 *  Created on: Dec 22, 2011
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "Hydro.hh"

#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Parallel.hh"
#include "Memory.hh"
#include "InputFile.hh"
#include "Mesh.hh"
#include "PolyGas.hh"
#include "TTS.hh"
#include "QCS.hh"
#include "HydroBC.hh"

using namespace std;


Hydro::Hydro(const InputFile* inp, Mesh* m) : mesh(m) {
    cfl = inp->getDouble("cfl", 0.6);
    cflv = inp->getDouble("cflv", 0.1);
    rinit = inp->getDouble("rinit", 1.);
    einit = inp->getDouble("einit", 0.);
    rinitsub = inp->getDouble("rinitsub", 1.);
    einitsub = inp->getDouble("einitsub", 0.);
    uinitradial = inp->getDouble("uinitradial", 0.);
    bcx = inp->getDoubleList("bcx", vector<double>());
    bcy = inp->getDoubleList("bcy", vector<double>());

    pgas = new PolyGas(inp, this);
    tts = new TTS(inp, this);
    qcs = new QCS(inp, this);

    const double2 vfixx = double2(1., 0.);
    const double2 vfixy = double2(0., 1.);
    for (int i = 0; i < bcx.size(); ++i)
        bcs.push_back(new HydroBC(mesh, vfixx, mesh->getXPlane(bcx[i])));
    for (int i = 0; i < bcy.size(); ++i)
        bcs.push_back(new HydroBC(mesh, vfixy, mesh->getYPlane(bcy[i])));

    init();
}


Hydro::~Hydro() {

    delete tts;
    delete qcs;
    for (int i = 0; i < bcs.size(); ++i) {
        delete bcs[i];
    }
}


void Hydro::init() {

    const int numpch = mesh->numpch;
    const int numzch = mesh->numzch;
    const int nump = mesh->nump;
    const int numz = mesh->numz;
    const int nums = mesh->nums;

    const double2* zx = mesh->zx;
    const double* zvol = mesh->zvol;

    // allocate arrays
    pu = Memory::alloc<double2>(nump);
    pu0 = Memory::alloc<double2>(nump);
    pap = Memory::alloc<double2>(nump);
    pf = Memory::alloc<double2>(nump);
    pmaswt = Memory::alloc<double>(nump);
    cmaswt = Memory::alloc<double>(nums);
    zm = Memory::alloc<double>(numz);
    zr = Memory::alloc<double>(numz);
    zrp = Memory::alloc<double>(numz);
    ze = Memory::alloc<double>(numz);
    zetot = Memory::alloc<double>(numz);
    zw = Memory::alloc<double>(numz);
    zwrate = Memory::alloc<double>(numz);
    zp = Memory::alloc<double>(numz);
    zss = Memory::alloc<double>(numz);
    zdu = Memory::alloc<double>(numz);
    sfp = Memory::alloc<double2>(nums);
    sfq = Memory::alloc<double2>(nums);
    sft = Memory::alloc<double2>(nums);
    cftot = Memory::alloc<double2>(nums);

    // initialize hydro vars
    #pragma omp parallel for schedule(static)
    for (int zch = 0; zch < numzch; ++zch) {
        int zfirst = mesh->zchzfirst[zch];
        int zlast = mesh->zchzlast[zch];

        fill(&zr[zfirst], &zr[zlast], rinit);
        fill(&ze[zfirst], &ze[zlast], einit);
        fill(&zwrate[zfirst], &zwrate[zlast], 0.);

        const vector<double>& subrgn = mesh->subregion;
        if (!subrgn.empty()) {
            const double eps = 1.e-12;
            #pragma ivdep
            for (int z = zfirst; z < zlast; ++z) {
                if (zx[z].x > (subrgn[0] - eps) &&
                    zx[z].x < (subrgn[1] + eps) &&
                    zx[z].y > (subrgn[2] - eps) &&
                    zx[z].y < (subrgn[3] + eps)) {
                    zr[z] = rinitsub;
                    ze[z] = einitsub;
                }
            }
        }

        #pragma ivdep
        for (int z = zfirst; z < zlast; ++z) {
            zm[z] = zr[z] * zvol[z];
            zetot[z] = ze[z] * zm[z];
        }
    }  // for sch

    #pragma omp parallel for schedule(static)
    for (int pch = 0; pch < numpch; ++pch) {
        int pfirst = mesh->pchpfirst[pch];
        int plast = mesh->pchplast[pch];
        if (uinitradial != 0.)
            initRadialVel(uinitradial, pfirst, plast);
        else
            fill(&pu[pfirst], &pu[plast], double2(0., 0.));
    }  // for pch

    resetDtHydro();

}


void Hydro::initRadialVel(
        const double vel,
        const int pfirst,
        const int plast) {
    const double2* px = mesh->px;
    const double eps = 1.e-12;

    #pragma ivdep
    for (int p = pfirst; p < plast; ++p) {
        double pmag = length(px[p]);
        if (pmag > eps)
            pu[p] = vel * px[p] / pmag;
        else
            pu[p] = double2(0., 0.);
    }
}


void Hydro::doCycle(
            const double dt) {

    const int numpch = mesh->numpch;
    const int numsch = mesh->numsch;
    double2* px = mesh->px;
    double2* ex = mesh->ex;
    double2* zx = mesh->zx;
    double* sarea = mesh->sarea;
    double* svol = mesh->svol;
    double* zarea = mesh->zarea;
    double* zvol = mesh->zvol;
    double* sareap = mesh->sareap;
    double* svolp = mesh->svolp;
    double* zareap = mesh->zareap;
    double* zvolp = mesh->zvolp;
    double* zvol0 = mesh->zvol0;
    double2* ssurfp = mesh->ssurfp;
    double* elen = mesh->elen;
    double2* px0 = mesh->px0;
    double2* pxp = mesh->pxp;
    double2* exp = mesh->exp;
    double2* zxp = mesh->zxp;
    double* smf = mesh->smf;
    double* zdl = mesh->zdl;

    // Begin hydro cycle
    #pragma omp parallel for schedule(static)
    for (int pch = 0; pch < numpch; ++pch) {
        int pfirst = mesh->pchpfirst[pch];
        int plast = mesh->pchplast[pch];

        // save off point variable values from previous cycle
        copy(&px[pfirst], &px[plast], &px0[pfirst]);
        copy(&pu[pfirst], &pu[plast], &pu0[pfirst]);

        // ===== Predictor step =====
        // 1. advance mesh to center of time step
        advPosHalf(px0, pu0, dt, pxp, pfirst, plast);
    } // for pch

    #pragma omp parallel for schedule(static)
    for (int sch = 0; sch < numsch; ++sch) {
        int sfirst = mesh->schsfirst[sch];
        int slast = mesh->schslast[sch];
        int zfirst = mesh->schzfirst[sch];
        int zlast = mesh->schzlast[sch];

        // save off zone variable values from previous cycle
        copy(&zvol[zfirst], &zvol[zlast], &zvol0[zfirst]);

        // 1a. compute new mesh geometry
        mesh->calcCtrs(pxp, exp, zxp, sfirst, slast);
        mesh->calcVols(pxp, zxp, sareap, svolp, zareap, zvolp,
                sfirst, slast);
        mesh->calcSurfVecs(zxp, exp, ssurfp, sfirst, slast);
        mesh->calcEdgeLen(pxp, elen, sfirst, slast);
        mesh->calcCharLen(sareap, zdl, sfirst, slast);

        // 2. compute point masses
        calcRho(zm, zvolp, zrp, zfirst, zlast);
        calcCrnrMass(zrp, zareap, smf, cmaswt, sfirst, slast);

        // 3. compute material state (half-advanced)
        pgas->calcStateAtHalf(zr, zvolp, zvol0, ze, zwrate, zm, dt,
                zp, zss, zfirst, zlast);

        // 4. compute forces
        pgas->calcForce(zp, ssurfp, sfp, sfirst, slast);
        tts->calcForce(zareap, zrp, zss, sareap, smf, ssurfp, sft,
                sfirst, slast);
        qcs->calcForce(sfq, sfirst, slast);
        sumCrnrForce(sfp, sfq, sft, cftot, sfirst, slast);
    }  // for sch
    mesh->checkBadSides();

    // sum corner masses, forces to points
    mesh->sumToPoints(cmaswt, pmaswt);
    mesh->sumToPoints(cftot, pf);

    #pragma omp parallel for schedule(static)
    for (int pch = 0; pch < numpch; ++pch) {
        int pfirst = mesh->pchpfirst[pch];
        int plast = mesh->pchplast[pch];

        // 4a. apply boundary conditions
        for (int i = 0; i < bcs.size(); ++i) {
            int bfirst = bcs[i]->pchbfirst[pch];
            int blast = bcs[i]->pchblast[pch];
            bcs[i]->applyFixedBC(pu0, pf, bfirst, blast);
        }

        // 5. compute accelerations
        calcAccel(pf, pmaswt, pap, pfirst, plast);

        // ===== Corrector step =====
        // 6. advance mesh to end of time step
        advPosFull(px0, pu0, pap, dt, px, pu, pfirst, plast);
    }  // for pch

    resetDtHydro();

    #pragma omp parallel for schedule(static)
    for (int sch = 0; sch < numsch; ++sch) {
        int sfirst = mesh->schsfirst[sch];
        int slast = mesh->schslast[sch];
        int zfirst = mesh->schzfirst[sch];
        int zlast = mesh->schzlast[sch];

        // 6a. compute new mesh geometry
        mesh->calcCtrs(px, ex, zx, sfirst, slast);
        mesh->calcVols(px, zx, sarea, svol, zarea, zvol,
                sfirst, slast);

        // 7. compute work
        fill(&zw[zfirst], &zw[zlast], 0.);
        calcWork(sfp, sfq, pu0, pu, pxp, dt, zw, zetot,
                sfirst, slast);
    }  // for sch
    mesh->checkBadSides();

    #pragma omp parallel for schedule(static)
    for (int zch = 0; zch < mesh->numzch; ++zch) {
        int zfirst = mesh->zchzfirst[zch];
        int zlast = mesh->zchzlast[zch];

        // 7a. compute work rate
        calcWorkRate(zvol0, zvol, zw, zp, dt, zwrate, zfirst, zlast);

        // 8. update state variables
        calcEnergy(zetot, zm, ze, zfirst, zlast);
        calcRho(zm, zvol, zr, zfirst, zlast);

        // 9.  compute timestep for next cycle
        calcDtHydro(zdl, zvol, zvol0, dt, zfirst, zlast);
    }  // for zch

}


void Hydro::advPosHalf(
        const double2* px0,
        const double2* pu0,
        const double dt,
        double2* pxp,
        const int pfirst,
        const int plast) {

    double dth = 0.5 * dt;

    #pragma ivdep
    for (int p = pfirst; p < plast; ++p) {
        pxp[p] = px0[p] + pu0[p] * dth;
    }
}


void Hydro::advPosFull(
        const double2* px0,
        const double2* pu0,
        const double2* pa,
        const double dt,
        double2* px,
        double2* pu,
        const int pfirst,
        const int plast) {

    #pragma ivdep
    for (int p = pfirst; p < plast; ++p) {
        pu[p] = pu0[p] + pa[p] * dt;
        px[p] = px0[p] + 0.5 * (pu[p] + pu0[p]) * dt;
    }

}


void Hydro::calcCrnrMass(
        const double* zr,
        const double* zarea,
        const double* smf,
        double* cmaswt,
        const int sfirst,
        const int slast) {

    #pragma ivdep
    for (int s = sfirst; s < slast; ++s) {
        int s3 = mesh->mapss3[s];
        int z = mesh->mapsz[s];

        double m = zr[z] * zarea[z] * 0.5 * (smf[s] + smf[s3]);
        cmaswt[s] = m;
    }
}


void Hydro::sumCrnrForce(
        const double2* sf,
        const double2* sf2,
        const double2* sf3,
        double2* cftot,
        const int sfirst,
        const int slast) {

    #pragma ivdep
    for (int s = sfirst; s < slast; ++s) {
        int s3 = mesh->mapss3[s];

        double2 f = (sf[s] + sf2[s] + sf3[s]) -
                    (sf[s3] + sf2[s3] + sf3[s3]);
        cftot[s] = f;
    }
}


void Hydro::calcAccel(
        const double2* pf,
        const double* pmass,
        double2* pa,
        const int pfirst,
        const int plast) {

    const double fuzz = 1.e-99;

    #pragma ivdep
    for (int p = pfirst; p < plast; ++p) {
        pa[p] = pf[p] / max(pmass[p], fuzz);
    }

}


void Hydro::calcRho(
        const double* zm,
        const double* zvol,
        double* zr,
        const int zfirst,
        const int zlast) {

    #pragma ivdep
    for (int z = zfirst; z < zlast; ++z) {
        zr[z] = zm[z] / zvol[z];
    }

}


void Hydro::calcWork(
        const double2* sf,
        const double2* sf2,
        const double2* pu0,
        const double2* pu,
        const double2* px,
        const double dt,
        double* zw,
        double* zetot,
        const int sfirst,
        const int slast) {

    // Compute the work done by finding, for each element/node pair,
    //   dwork= force * vavg
    // where force is the force of the element on the node
    // and vavg is the average velocity of the node over the time period

    const double dth = 0.5 * dt;

    for (int s = sfirst; s < slast; ++s) {
        int p1 = mesh->mapsp1[s];
        int p2 = mesh->mapsp2[s];
        int z = mesh->mapsz[s];

        double2 sftot = sf[s] + sf2[s];
        double sd1 = dot( sftot, (pu0[p1] + pu[p1]));
        double sd2 = dot(-sftot, (pu0[p2] + pu[p2]));
        double dwork = -dth * (sd1 * px[p1].x + sd2 * px[p2].x);

        zetot[z] += dwork;
        zw[z] += dwork;

    }

}


void Hydro::calcWorkRate(
        const double* zvol0,
        const double* zvol,
        const double* zw,
        const double* zp,
        const double dt,
        double* zwrate,
        const int zfirst,
        const int zlast) {
    double dtinv = 1. / dt;
    #pragma ivdep
    for (int z = zfirst; z < zlast; ++z) {
        double dvol = zvol[z] - zvol0[z];
        zwrate[z] = (zw[z] + zp[z] * dvol) * dtinv;
    }

}


void Hydro::calcEnergy(
        const double* zetot,
        const double* zm,
        double* ze,
        const int zfirst,
        const int zlast) {

    const double fuzz = 1.e-99;
    #pragma ivdep
    for (int z = zfirst; z < zlast; ++z) {
        ze[z] = zetot[z] / (zm[z] + fuzz);
    }

}


void Hydro::sumEnergy(
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
        const int slast) {

    // compute internal energy
    double sumi = 0.; 
    for (int z = zfirst; z < zlast; ++z) {
        sumi += zetot[z];
    }
    // multiply by 2\pi for cylindrical geometry
    ei += sumi * 2 * M_PI;

    // compute kinetic energy
    // in each individual zone:
    // zone ke = zone mass * (volume-weighted average of .5 * u ^ 2)
    //         = zm sum(c in z) [cvol / zvol * .5 * u ^ 2]
    //         = sum(c in z) [zm * cvol / zvol * .5 * u ^ 2]
    double sumk = 0.; 
    for (int s = sfirst; s < slast; ++s) {
        int s3 = mesh->mapss3[s];
        int p1 = mesh->mapsp1[s];
        int z = mesh->mapsz[s];

        double cvol = zarea[z] * px[p1].x * 0.5 * (smf[s] + smf[s3]);
        double cke = zm[z] * cvol / zvol[z] * 0.5 * length2(pu[p1]);
        sumk += cke;
    }
    // multiply by 2\pi for cylindrical geometry
    ek += sumk * 2 * M_PI;

}


void Hydro::calcDtCourant(
        const double* zdl,
        double& dtrec,
        char* msgdtrec,
        const int zfirst,
        const int zlast) {

    const double fuzz = 1.e-99;
    double dtnew = 1.e99;
    int zmin = -1;
    for (int z = zfirst; z < zlast; ++z) {
        double cdu = max(zdu[z], max(zss[z], fuzz));
        double zdthyd = zdl[z] * cfl / cdu;
        zmin = (zdthyd < dtnew ? z : zmin);
        dtnew = (zdthyd < dtnew ? zdthyd : dtnew);
    }

    if (dtnew < dtrec) {
        dtrec = dtnew;
        snprintf(msgdtrec, 80, "Hydro Courant limit for z = %d", zmin);
    }

}


void Hydro::calcDtVolume(
        const double* zvol,
        const double* zvol0,
        const double dtlast,
        double& dtrec,
        char* msgdtrec,
        const int zfirst,
        const int zlast) {

    double dvovmax = 1.e-99;
    int zmax = -1;
    for (int z = zfirst; z < zlast; ++z) {
        double zdvov = abs((zvol[z] - zvol0[z]) / zvol0[z]);
        zmax = (zdvov > dvovmax ? z : zmax);
        dvovmax = (zdvov > dvovmax ? zdvov : dvovmax);
    }
    double dtnew = dtlast * cflv / dvovmax;
    if (dtnew < dtrec) {
        dtrec = dtnew;
        snprintf(msgdtrec, 80, "Hydro dV/V limit for z = %d", zmax);
    }

}


void Hydro::calcDtHydro(
        const double* zdl,
        const double* zvol,
        const double* zvol0,
        const double dtlast,
        const int zfirst,
        const int zlast) {

    double dtchunk = 1.e99;
    char msgdtchunk[80];

    calcDtCourant(zdl, dtchunk, msgdtchunk, zfirst, zlast);
    calcDtVolume(zvol, zvol0, dtlast, dtchunk, msgdtchunk,
            zfirst, zlast);
    if (dtchunk < dtrec) {
        #pragma omp critical
        {
            // redundant test needed to avoid race condition
            if (dtchunk < dtrec) {
                dtrec = dtchunk;
                strncpy(msgdtrec, msgdtchunk, 80);
            }
        }
    }

}


void Hydro::getDtHydro(
        double& dtnew,
        string& msgdtnew) {

    if (dtrec < dtnew) {
        dtnew = dtrec;
        msgdtnew = string(msgdtrec);
    }

}


void Hydro::resetDtHydro() {

    dtrec = 1.e99;
    strcpy(msgdtrec, "Hydro default");

}


void Hydro::writeEnergyCheck() {

    using Parallel::mype;
    
    double ei = 0.;
    double ek = 0.;
    #pragma omp parallel for schedule(static)
    for (int sch = 0; sch < mesh->numsch; ++sch) {
        int sfirst = mesh->schsfirst[sch];
        int slast = mesh->schslast[sch];
        int zfirst = mesh->schzfirst[sch];
        int zlast = mesh->schzlast[sch];

        double eichunk = 0.;
        double ekchunk = 0.;
        sumEnergy(zetot, mesh->zarea, mesh->zvol, zm, mesh->smf,
                mesh->px, pu, eichunk, ekchunk,
                zfirst, zlast, sfirst, slast);
        #pragma omp critical
        {
            ei += eichunk;
            ek += ekchunk;
        }
    }

    Parallel::globalSum(ei);
    Parallel::globalSum(ek);

    if (mype == 0) {
        cout << scientific << setprecision(6);
        cout << "Energy check:  "
             << "total energy  = " << setw(14) << ei + ek << endl;
        cout << "(internal = " << setw(14) << ei
             << ", kinetic = " << setw(14) << ek << ")" << endl;
    }

 }
