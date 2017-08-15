/*
 * WriteXY.cc
 *
 *  Created on: Dec 16, 2013
 *      Author: cferenba
 *
 * Copyright (c) 2013, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#include "WriteXY.hh"

#include <fstream>
#include <iomanip>

#include "Parallel.hh"
#include "Mesh.hh"

using namespace std;


WriteXY::WriteXY(Mesh* m) : mesh(m) {}

WriteXY::~WriteXY() {}


void WriteXY::write(
        const string& basename,
        const double* zr,
        const double* ze,
        const double* zp) {

    using Parallel::numpe;
    using Parallel::mype;
    const int numz = mesh->numz;

    int gnumz = numz;
    Parallel::globalSum(gnumz);
    gnumz = (mype == 0 ? gnumz : 0);
    vector<int> penumz(mype == 0 ? numpe : 0);
    Parallel::gather(numz, &penumz[0]);

    vector<double> gzr(gnumz), gze(gnumz), gzp(gnumz);
    Parallel::gatherv(&zr[0], numz, &gzr[0], &penumz[0]);
    Parallel::gatherv(&ze[0], numz, &gze[0], &penumz[0]);
    Parallel::gatherv(&zp[0], numz, &gzp[0], &penumz[0]);

    if (mype == 0) {
        string xyname = basename + ".xy";
        ofstream ofs(xyname.c_str());
        ofs << scientific << setprecision(8);
        ofs << "#  zr" << endl;
        for (int z = 0; z < gnumz; ++z) {
            ofs << setw(5) << (z + 1) << setw(18) << gzr[z] << endl;
        }
        ofs << "#  ze" << endl;
        for (int z = 0; z < gnumz; ++z) {
            ofs << setw(5) << (z + 1) << setw(18) << gze[z] << endl;
        }
        ofs << "#  zp" << endl;
        for (int z = 0; z < gnumz; ++z) {
            ofs << setw(5) << (z + 1) << setw(18) << gzp[z] << endl;
        }
        ofs.close();

    } // if mype

}

