/*
 * ExportGold.hh
 *
 *  Created on: Mar 1, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef EXPORTGOLD_HH_
#define EXPORTGOLD_HH_

#include <string>
#include <vector>

// forward declarations
class Mesh;


class ExportGold {
public:

    Mesh* mesh;

    std::vector<int> tris;         // zone index list for 3-sided zones
    std::vector<int> quads;        // same, for 4-sided zones
    std::vector<int> others;       // same, for n-sided zones, n > 4
    std::vector<int> mapzs;        // map: zone -> first side

    // parallel info, meaningful on PE 0 only:
    std::vector<int> pentris;      // number of tris on each PE
    std::vector<int> penquads;     // same, for quads
    std::vector<int> penothers;    // same, for others
    int gntris, gnquads, gnothers; // total number across all PEs
                                   //     of tris/quads/others

    ExportGold(Mesh* m);
    ~ExportGold();

    void write(
            const std::string& basename,
            const int cycle,
            const double time,
            const double* zr,
            const double* ze,
            const double* zp);

    void writeCaseFile(
            const std::string& basename);

    void writeGeoFile(
            const std::string& basename,
            const int cycle,
            const double time);

    void writeVarFile(
            const std::string& basename,
            const std::string& varname,
            const double* var);

    void sortZones();
};



#endif /* EXPORTGOLD_HH_ */
