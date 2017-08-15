/*
 * Mesh.hh
 *
 *  Created on: Jan 5, 2012
 *      Author: cferenba
 *
 * Copyright (c) 2012, Los Alamos National Security, LLC.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style open-source
 * license; see top-level LICENSE file for full license text.
 */

#ifndef MESH_HH_
#define MESH_HH_

#include <string>
#include <vector>

#include "Vec2.hh"

// forward declarations
class InputFile;
class GenMesh;
class WriteXY;
class ExportGold;


class Mesh {
public:

    // children
    GenMesh* gmesh;
    WriteXY* wxy;
    ExportGold* egold;

    // parameters
    int chunksize;                 // max size for processing chunks
    std::vector<double> subregion; // bounding box for a subregion
                                   // if nonempty, should have 4 entries:
                                   // xmin, xmax, ymin, ymax
    bool writexy;                  // flag:  write .xy file?
    bool writegold;                // flag:  write Ensight file?

    // mesh variables
    // (See documentation for more details on the mesh
    //  data structures...)
    int nump, nume, numz, nums, numc;
                       // number of points, edges, zones,
                       // sides, corners, resp.
    int numsbad;       // number of bad sides (negative volume)
    int* mapsp1;       // maps: side -> points 1 and 2
    int* mapsp2;
    int* mapsz;        // map: side -> zone
    int* mapse;        // map: side -> edge
    int* mapss3;       // map: side -> previous side
    int* mapss4;       // map: side -> next side

    // point-to-corner inverse map is stored as a linked list...
    int* mappcfirst;   // map:  point -> first corner
    int* mapccnext;    // map:  corner -> next corner

    // mpi comm variables
    int nummstrpe;     // number of messages mype sends to master pes
    int numslvpe;      // number of messages mype receives from slave pes
    int numprx;        // number of proxies on mype
    int numslv;        // number of slaves on mype
    int* mapslvpepe;   // map: slave pe -> (global) pe
    int* mapslvpeprx1; // map: slave pe -> first proxy in proxy buffer
    int* mapprxp;      // map: proxy -> corresponding (master) point
    int* slvpenumprx;  // number of proxies for each slave pe
    int* mapmstrpepe;  // map: master pe -> (global) pe
    int* mstrpenumslv; // number of slaves for each master pe
    int* mapmstrpeslv1;// map: master pe -> first slave in slave buffer
    int* mapslvp;      // map: slave -> corresponding (slave) point

    int* znump;        // number of points in zone

    double2* px;       // point coordinates
    double2* ex;       // edge center coordinates
    double2* zx;       // zone center coordinates
    double2* pxp;      // point coords, middle of cycle
    double2* exp;      // edge ctr coords, middle of cycle
    double2* zxp;      // zone ctr coords, middle of cycle
    double2* px0;      // point coords, start of cycle

    double* sarea;     // side area
    double* svol;      // side volume
    double* zarea;     // zone area
    double* zvol;      // zone volume
    double* sareap;    // side area, middle of cycle
    double* svolp;     // side volume, middle of cycle
    double* zareap;    // zone area, middle of cycle
    double* zvolp;     // zone volume, middle of cycle
    double* zvol0;     // zone volume, start of cycle

    double2* ssurfp;   // side surface vector
    double* elen;      // edge length
    double* smf;       // side mass fraction
    double* zdl;       // zone characteristic length

    int numsch;                    // number of side chunks
    std::vector<int> schsfirst;    // start/stop index for side chunks
    std::vector<int> schslast;
    std::vector<int> schzfirst;    // start/stop index for zone chunks
    std::vector<int> schzlast;
    int numpch;                    // number of point chunks
    std::vector<int> pchpfirst;    // start/stop index for point chunks
    std::vector<int> pchplast;
    int numzch;                    // number of zone chunks
    std::vector<int> zchzfirst;    // start/stop index for zone chunks
    std::vector<int> zchzlast;

    Mesh(const InputFile* inp);
    ~Mesh();

    void init();

    // populate mapping arrays
    void initSides(
            const std::vector<int>& cellstart,
            const std::vector<int>& cellsize,
            const std::vector<int>& cellnodes);
    void initEdges();

    // populate chunk information
    void initChunks();

    // populate inverse map
    void initInvMap();

    void initParallel(
            const std::vector<int>& slavemstrpes,
            const std::vector<int>& slavemstrcounts,
            const std::vector<int>& slavepoints,
            const std::vector<int>& masterslvpes,
            const std::vector<int>& masterslvcounts,
            const std::vector<int>& masterpoints);

    // write mesh statistics
    void writeStats();

    // write mesh
    void write(
            const std::string& probname,
            const int cycle,
            const double time,
            const double* zr,
            const double* ze,
            const double* zp);

    // find plane with constant x, y value
    std::vector<int> getXPlane(const double c);
    std::vector<int> getYPlane(const double c);

    // compute chunks for a given plane
    void getPlaneChunks(
            const int numb,
            const int* mapbp,
            std::vector<int>& pchbfirst,
            std::vector<int>& pchblast);

    // compute edge, zone centers
    void calcCtrs(
            const double2* px,
            double2* ex,
            double2* zx,
            const int sfirst,
            const int slast);

    // compute side, corner, zone volumes
    void calcVols(
            const double2* px,
            const double2* zx,
            double* sarea,
            double* svol,
            double* zarea,
            double* zvol,
            const int sfirst,
            const int slast);

    // check to see if previous volume computation had any
    // sides with negative volumes
    void checkBadSides();

    // compute side mass fractions
    void calcSideFracs(
            const double* sarea,
            const double* zarea,
            double* smf,
            const int sfirst,
            const int slast);

    // compute surface vectors for median mesh
    void calcSurfVecs(
            const double2* zx,
            const double2* ex,
            double2* ssurf,
            const int sfirst,
            const int slast);

    // compute edge lengths
    void calcEdgeLen(
            const double2* px,
            double* elen,
            const int sfirst,
            const int slast);

    // compute characteristic lengths
    void calcCharLen(
            const double* sarea,
            double* zdl,
            const int sfirst,
            const int slast);

    // sum corner variables to points (double or double2)
    template <typename T>
    void sumToPoints(
            const T* cvar,
            T* pvar);

    // helper routines for sumToPoints
    template <typename T>
    void sumOnProc(
            const T* cvar,
            T* pvar);
    template <typename T>
    void sumAcrossProcs(T* pvar);
    template <typename T>
    void parallelGather(
            const T* pvar,
            T* prxvar);
    template <typename T>
    void parallelSum(
            T* pvar,
            T* prxvar);
    template <typename T>
    void parallelScatter(
            T* pvar,
            const T* prxvar);

}; // class Mesh



#endif /* MESH_HH_ */
