/*
 * GenMesh.hh
 *
 *  Created on: Jun 4, 2013
 *      Author: cferenba
 *
 * Copyright (c) 2013, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef GENMESH_HH_
#define GENMESH_HH_

#include <string>
#include <vector>
#include "Vec2.hh"

// forward declarations
class InputFile;


class GenMesh {
public:

    std::string meshtype;       // generated mesh type
    int gnzx, gnzy;             // global number of zones, in x and y
                                // directions
    double lenx, leny;          // length of mesh sides, in x and y
                                // directions
    int numpex, numpey;         // number of PEs to use, in x and y
                                // directions
    int mypex, mypey;           // my PE index, in x and y directions
    int nzx, nzy;               // (local) number of zones, in x and y
                                // directions
    int zxoffset, zyoffset;     // offsets of local zone array into
                                // global, in x and y directions

    GenMesh(const InputFile* inp);
    ~GenMesh();

    void generate(
            std::vector<double2>& pointpos,
            std::vector<int>& zonestart,
            std::vector<int>& zonesize,
            std::vector<int>& zonepoints,
            std::vector<int>& slavemstrpes,
            std::vector<int>& slavemstrcounts,
            std::vector<int>& slavepoints,
            std::vector<int>& masterslvpes,
            std::vector<int>& masterslvcounts,
            std::vector<int>& masterpoints);

    void generateRect(
            std::vector<double2>& pointpos,
            std::vector<int>& zonestart,
            std::vector<int>& zonesize,
            std::vector<int>& zonepoints,
            std::vector<int>& slavemstrpes,
            std::vector<int>& slavemstrcounts,
            std::vector<int>& slavepoints,
            std::vector<int>& masterslvpes,
            std::vector<int>& masterslvcounts,
            std::vector<int>& masterpoints);

    void generatePie(
            std::vector<double2>& pointpos,
            std::vector<int>& zonestart,
            std::vector<int>& zonesize,
            std::vector<int>& zonepoints,
            std::vector<int>& slavemstrpes,
            std::vector<int>& slavemstrcounts,
            std::vector<int>& slavepoints,
            std::vector<int>& masterslvpes,
            std::vector<int>& masterslvcounts,
            std::vector<int>& masterpoints);

    void generateHex(
            std::vector<double2>& pointpos,
            std::vector<int>& zonestart,
            std::vector<int>& zonesize,
            std::vector<int>& zonepoints,
            std::vector<int>& slavemstrpes,
            std::vector<int>& slavemstrcounts,
            std::vector<int>& slavepoints,
            std::vector<int>& masterslvpes,
            std::vector<int>& masterslvcounts,
            std::vector<int>& masterpoints);

    void calcNumPE();

}; // class GenMesh


#endif /* GENMESH_HH_ */
