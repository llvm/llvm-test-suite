/*
 * QCS.cc
 *
 *  Created on: Feb 21, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "QCS.hh"

#include <algorithm>
#include <cmath>
#include "Memory.hh"
#include "InputFile.hh"
#include "Vec2.hh"
#include "Mesh.hh"
#include "Hydro.hh"

using namespace std;


QCS::QCS(const InputFile* inp, Hydro* h) : hydro(h) {
    qgamma = inp->getDouble("qgamma", 5. / 3.);
    q1 = inp->getDouble("q1", 0.);
    q2 = inp->getDouble("q2", 2.);

}

QCS::~QCS() {}


void QCS::calcForce(
        double2* sf,
        const int sfirst,
        const int slast) {
    int cfirst = sfirst;
    int clast = slast;

    // declare temporary variables
    double* c0area = Memory::alloc<double>(clast - cfirst);
    double* c0evol = Memory::alloc<double>(clast - cfirst);
    double* c0du = Memory::alloc<double>(clast - cfirst);
    double* c0div = Memory::alloc<double>(clast - cfirst);
    double* c0cos = Memory::alloc<double>(clast - cfirst);
    double2* c0qe = Memory::alloc<double2>(2 * (clast - cfirst));

    // [1] Find the right, left, top, bottom  edges to use for the
    //     limiters
    // *** NOT IMPLEMENTED IN PENNANT ***

    // [2] Compute corner divergence and related quantities
    // [2.1] Find the corner divergence
    // [2.2] Compute the cos angle for c
    // [2.3] Find the evolution factor c0evol(c) and the Delta u(c) = du(c)
    // [2.4] Find the weights c0w(c)
    setCornerDiv(c0area, c0div, c0evol, c0du, c0cos, sfirst, slast);

    // [3] Find the limiters Psi(c)
    // *** NOT IMPLEMENTED IN PENNANT ***

    // [4] Compute the Q vector (corner based)
    // [4.1] Compute cmu = (1-psi) . crho . zKUR . c0evol
    // [4.2] Compute the q vector associated with c on edges
    //       e1=[n0,n1], e2=[n1,n2]
    //       c0qe(2,c) = cmu(c).( u(n2)-u(n1) ) / l_{n1->n2}
    //       c0qe(1,c) = cmu(c).( u(n1)-u(n0) ) / l_{n0->n1}
    setQCnForce(c0div, c0du, c0evol, c0qe, sfirst, slast);

    // [5] Compute the Q forces
    setForce(c0area, c0qe, c0cos, sf, sfirst, slast);

    // [6] Set velocity difference to use to compute timestep
    setVelDiff(sfirst, slast);

    Memory::free(c0area);
    Memory::free(c0evol);
    Memory::free(c0du);
    Memory::free(c0div);
    Memory::free(c0cos);
    Memory::free(c0qe);
}


// Routine number [2]  in the full algorithm
//     [2.1] Find the corner divergence
//     [2.2] Compute the cos angle for c
//     [2.3] Find the evolution factor c0evol(c)
//           and the Delta u(c) = du(c)
void QCS::setCornerDiv(
            double* c0area,
            double* c0div,
            double* c0evol,
            double* c0du,
            double* c0cos,
            const int sfirst,
            const int slast) {

    const Mesh* mesh = hydro->mesh;
    const int nums = mesh->nums;
    const int numz = mesh->numz;

    const double2* pu = hydro->pu;
    const double2* px = mesh->pxp;
    const double2* ex = mesh->exp;
    const double2* zx = mesh->zxp;
    const double* elen = mesh->elen;
    const int* znump = mesh->znump;

    int cfirst = sfirst;
    int clast = slast;
    int zfirst = mesh->mapsz[sfirst];
    int zlast = (slast < nums ? mesh->mapsz[slast] : numz);

    double2* z0uc = Memory::alloc<double2>(zlast - zfirst);
    double2 up0, up1, up2, up3;
    double2 xp0, xp1, xp2, xp3;

    // [1] Compute a zone-centered velocity
    fill(&z0uc[0], &z0uc[zlast-zfirst], double2(0., 0.));
    for (int c = cfirst; c < clast; ++c) {
        int p = mesh->mapsp1[c];
        int z = mesh->mapsz[c];
        int z0 = z - zfirst;
        z0uc[z0] += pu[p];
    }

    for (int z = zfirst; z < zlast; ++z) {
        int z0 = z - zfirst;
        z0uc[z0] /= (double) znump[z];
    }

    // [2] Divergence at the corner
    #pragma ivdep
    for (int c = cfirst; c < clast; ++c) {
        int s2 = c;
        int s = mesh->mapss3[s2];
        // Associated zone, corner, point
        int z = mesh->mapsz[s];
        int z0 = z - zfirst;
        int c0 = c - cfirst;
        int p = mesh->mapsp2[s];
        // Points
        int p1 = mesh->mapsp1[s];
        int p2 = mesh->mapsp2[s2];
        // Edges
        int e1 = mesh->mapse[s];
        int e2 = mesh->mapse[s2];

        // Velocities and positions
        // 0 = point p
        up0 = pu[p];
        xp0 = px[p];
        // 1 = edge e2
        up1 = 0.5 * (pu[p] + pu[p2]);
        xp1 = ex[e2];
        // 2 = zone center z
        up2 = z0uc[z0];
        xp2 = zx[z];
        // 3 = edge e1
        up3 = 0.5 * (pu[p1] + pu[p]);
        xp3 = ex[e1];

        // compute 2d cartesian volume of corner
        double cvolume = 0.5 * cross(xp2 - xp0, xp3 - xp1);
        c0area[c0] = cvolume;

        // compute cosine angle
        double2 v1 = xp3 - xp0;
        double2 v2 = xp1 - xp0;
        double de1 = elen[e1];
        double de2 = elen[e2];
        double minelen = min(de1, de2);
        c0cos[c0] = ((minelen < 1.e-12) ?
                0. :
                4. * dot(v1, v2) / (de1 * de2));

        // compute divergence of corner
        c0div[c0] = (cross(up2 - up0, xp3 - xp1) -
                cross(up3 - up1, xp2 - xp0)) /
                (2.0 * cvolume);

        // compute evolution factor
        double2 dxx1 = 0.5 * (xp1 + xp2 - xp0 - xp3);
        double2 dxx2 = 0.5 * (xp2 + xp3 - xp0 - xp1);
        double dx1 = length(dxx1);
        double dx2 = length(dxx2);

        // average corner-centered velocity
        double2 duav = 0.25 * (up0 + up1 + up2 + up3);

        double test1 = abs(dot(dxx1, duav) * dx2);
        double test2 = abs(dot(dxx2, duav) * dx1);
        double num = (test1 > test2 ? dx1 : dx2);
        double den = (test1 > test2 ? dx2 : dx1);
        double r = num / den;
        double evol = sqrt(4.0 * cvolume * r);
        evol = min(evol, 2.0 * minelen);

        // compute delta velocity
        double dv1 = length2(up1 + up2 - up0 - up3);
        double dv2 = length2(up2 + up3 - up0 - up1);
        double du = sqrt(max(dv1, dv2));

        c0evol[c0] = (c0div[c0] < 0.0 ? evol : 0.);
        c0du[c0]   = (c0div[c0] < 0.0 ? du   : 0.);
    }  // for s

    Memory::free(z0uc);
}


// Routine number [4]  in the full algorithm CS2DQforce(...)
void QCS::setQCnForce(
        const double* c0div,
        const double* c0du,
        const double* c0evol,
        double2* c0qe,
        const int sfirst,
        const int slast) {

    const Mesh* mesh = hydro->mesh;

    const double2* pu = hydro->pu;
    const double* zrp = hydro->zrp;
    const double* zss = hydro->zss;
    const double* elen = mesh->elen;

    int cfirst = sfirst;
    int clast = slast;

    double* c0rmu = Memory::alloc<double>(clast - cfirst);

    const double gammap1 = qgamma + 1.0;

    // [4.1] Compute the c0rmu (real Kurapatenko viscous scalar)
    #pragma ivdep
    for (int c = cfirst; c < clast; ++c) {
        int c0 = c - cfirst;
        int z = mesh->mapsz[c];

        // Kurapatenko form of the viscosity
        double ztmp2 = q2 * 0.25 * gammap1 * c0du[c0];
        double ztmp1 = q1 * zss[z];
        double zkur = ztmp2 + sqrt(ztmp2 * ztmp2 + ztmp1 * ztmp1);
        // Compute c0rmu for each corner
        double rmu = zkur * zrp[z] * c0evol[c0];
        c0rmu[c0] = ((c0div[c0] > 0.0) ? 0. : rmu);

    } // for c

    // [4.2] Compute the c0qe for each corner
    #pragma ivdep
    for (int c = cfirst; c < clast; ++c) {
        int s4 = c;
        int s = mesh->mapss3[s4];
        int c0 = c - cfirst;
        int p = mesh->mapsp2[s];
        // Associated point and edge 1
        int p1 = mesh->mapsp1[s];
        int e1 = mesh->mapse[s];
        // Associated point and edge 2
        int p2 = mesh->mapsp2[s4];
        int e2 = mesh->mapse[s4];

        // Compute: c0qe(1,2,3)=edge 1, y component (2nd), 3rd corner
        //          c0qe(2,1,3)=edge 2, x component (1st)
        c0qe[2 * c0]     = c0rmu[c0] * (pu[p] - pu[p1]) / elen[e1];
        c0qe[2 * c0 + 1] = c0rmu[c0] * (pu[p2] - pu[p]) / elen[e2];

    } // for s

    Memory::free(c0rmu);
}


// Routine number [5]  in the full algorithm CS2DQforce(...)
void QCS::setForce(
        const double* c0area,
        const double2* c0qe,
        double* c0cos,
        double2* sfq,
        const int sfirst,
        const int slast) {

    const Mesh* mesh = hydro->mesh;
    const double* elen = mesh->elen;

    int cfirst = sfirst;
    int clast = slast;

    double* c0w = Memory::alloc<double>(clast - cfirst);

    // [5.1] Preparation of extra variables
    #pragma ivdep
    for (int c = cfirst; c < clast; ++c) {
        int c0 = c - cfirst;
        double csin2 = 1.0 - c0cos[c0] * c0cos[c0];
        c0w[c0]   = ((csin2 < 1.e-4) ? 0. : c0area[c0] / csin2);
        c0cos[c0] = ((csin2 < 1.e-4) ? 0. : c0cos[c0]);
    } // for c

    // [5.2] Set-Up the forces on corners
    #pragma ivdep
    for (int s = sfirst; s < slast; ++s) {
        // Associated corners 1 and 2, and edge
        int c1 = s;
        int c10 = c1 - cfirst;
        int c2 = mesh->mapss4[s];
        int c20 = c2 - cfirst;
        int e = mesh->mapse[s];
        // Edge length for c1, c2 contribution to s
        double el = elen[e];

        sfq[s] = (c0w[c10] * (c0qe[2*c10+1] + c0cos[c10] * c0qe[2*c10]) +
                  c0w[c20] * (c0qe[2*c20] + c0cos[c20] * c0qe[2*c20+1]))
            / el;

    } // for s

    Memory::free(c0w);
}


// Routine number [6] in the full algorithm
void QCS::setVelDiff(
        const int sfirst,
        const int slast) {

    const Mesh* mesh = hydro->mesh;
    const int nums = mesh->nums;
    const int numz = mesh->numz;
    int zfirst = mesh->mapsz[sfirst];
    int zlast = (slast < nums ? mesh->mapsz[slast] : numz);
    const double2* px = mesh->pxp;
    const double2* pu = hydro->pu;
    const double* zss = hydro->zss;
    double* zdu = hydro->zdu;
    const double* elen = mesh->elen;

    double* z0tmp = Memory::alloc<double>(zlast - zfirst);

    fill(&z0tmp[0], &z0tmp[zlast-zfirst], 0.);
    for (int s = sfirst; s < slast; ++s) {
        int p1 = mesh->mapsp1[s];
        int p2 = mesh->mapsp2[s];
        int z = mesh->mapsz[s];
        int e = mesh->mapse[s];
        int z0 = z - zfirst;

        double2 dx = px[p2] - px[p1];
        double2 du = pu[p2] - pu[p1];
        double lenx = elen[e];
        double dux = dot(du, dx);
        dux = (lenx > 0. ? abs(dux) / lenx : 0.);

        z0tmp[z0] = max(z0tmp[z0], dux);
    }

    for (int z = zfirst; z < zlast; ++z) {
        int z0 = z - zfirst;
        zdu[z] = q1 * zss[z] + 2. * q2 * z0tmp[z0];
    }

    Memory::free(z0tmp);
}

