/*
 *                 Copyright (C) 2017, UChicago Argonne, LLC
 *                            All Rights Reserved
 *
 *           Hardware/Hybrid Cosmology Code (HACC), Version 1.0
 *
 * Salman Habib, Adrian Pope, Hal Finkel, Nicholas Frontiere, Katrin Heitmann,
 *      Vitali Morozov, Jeffrey Emberson, Thomas Uram, Esteban Rangel
 *                        (Argonne National Laboratory)
 *
 *  David Daniel, Patricia Fasel, Chung-Hsing Hsu, Zarija Lukic, James Ahrens
 *                      (Los Alamos National Laboratory)
 *
 *                               George Zagaris
 *                                 (Kitware)
 *
 *                            OPEN SOURCE LICENSE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer. Software changes,
 *      modifications, or derivative works, should be noted with comments and
 *      the author and organization’s name.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the names of UChicago Argonne, LLC or the Department of Energy
 *      nor the names of its contributors may be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 *   4. The software and the end-user documentation included with the
 *      redistribution, if any, must include the following acknowledgment:
 *
 *     "This product includes software produced by UChicago Argonne, LLC under
 *      Contract No. DE-AC02-06CH11357 with the Department of Energy."
 *
 * *****************************************************************************
 *                                DISCLAIMER
 * THE SOFTWARE IS SUPPLIED "AS IS" WITHOUT WARRANTY OF ANY KIND. NEITHER THE
 * UNITED STATES GOVERNMENT, NOR THE UNITED STATES DEPARTMENT OF ENERGY, NOR 
 * UCHICAGO ARGONNE, LLC, NOR ANY OF THEIR EMPLOYEES, MAKES ANY WARRANTY, 
 * EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR RESPONSIBILITY FOR THE
 * ACCURARY, COMPLETENESS, OR USEFULNESS OF ANY INFORMATION, DATA, APPARATUS,
 * PRODUCT, OR PROCESS DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT INFRINGE
 * PRIVATELY OWNED RIGHTS.
 *
 * *****************************************************************************
 */

#include "HACCKernels.h"
#include <ctime>
#include <cstdlib>
#include <limits>
#include <vector>
#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

// This number of iterations, which can be changed via the command line, is set
// so that the benchmark will run for a few seconds per polynomial degree of
// the force kernel on a single core of a modern CPU.
int NumIters = 2000;

// The interaction lists range is size between a few hundred and a few thousand.
int IListMin = 250;
int IListMax = 2250;

// The number of particles to update, which represents the number of particles
// per leaf node of the force evaluation tree in HACC, varies between tends of
// particles to around a hundred particles depending on the platform. These
// numbers represent the high side of the production range.
int PMin = 75;
int PMax = 150;

// The softening length and maximum separation similar to those used in HACC
// high-resolution configurations.
float SofteningLen = 0.1;
float MaxSep = 3.2;

// In this benchmark we offset the positions of the particles being updated
// from the particles in the interaction list so that some of the interactions
// will be filtered for being out of range. 0.1 yields ~5% of interactions
// filtered for being out of range.
float OffsetAdjFrac = 0.1;

// A simple random-number generator, see: https://en.wikipedia.org/wiki/Xorshift
static unsigned int rand32(unsigned int &state) {
  unsigned int x = state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return (state = x);
}

static float randflt(unsigned int &state) {
  return ((float) rand32(state)) / ((float) 0xffffffff);
}

void run(GravityForceKernelFunc GravityForceKernel, const char *Desc) {
#ifndef VERIFICATION_OUTPUT_ONLY
  std::clock_t Start, End;
#endif

  std::cout << "Gravity Short-Range-Force Kernel (" << Desc << "): ";
#ifndef VERIFICATION_OUTPUT_ONLY
  Start = std::clock();
#endif

  float ax, ay, az;

  // We use lastprivate for (ax,ay,az) so that the reported output, which can
  // be used for validation, does not depend on the order in which parallel
  // loop iterations are executed.

  // Because each iteration has a different amount of work, dynamic or guided
  // scheduling is used here. guided gives the implementation more scheduling
  // freedom.
#ifdef _OPENMP
#pragma omp parallel for schedule(guided) lastprivate(ax,ay,az)
#endif
  for (int i = 0; i < NumIters; ++i) {
    // Set the random seed used by each iteration to be a function of the
    // iteration number only. This allows information from any fixed iteration
    // (e.g. first or last) to be used for numerical validation.
    unsigned int seed = i+1;
    ax = ay = az = 0.0f;

    int ILParticleCount = IListMin + rand32(seed) % (IListMax - IListMin);
    int ParticleCount = PMin + rand32(seed) % (PMax - PMin);
    std::vector<float> px(ParticleCount), py(ParticleCount),
                       pz(ParticleCount);
    std::vector<float> x(ILParticleCount), y(ILParticleCount),
                       z(ILParticleCount), mass(ILParticleCount);

    // Fill the particle arrays and the interaction list. The interaction-list
    // particles are offset in the x direction based on OffsetAdjFrac.
    for (int j = 0; j < ParticleCount; ++j) {
      px[j] = randflt(seed)*0.5*MaxSep;
      py[j] = randflt(seed)*0.5*MaxSep;
      pz[j] = randflt(seed)*0.5*MaxSep;
    }

    for (int j = 0; j < ILParticleCount; ++j) {
      x[j] = randflt(seed)*0.5*MaxSep + (0.5+OffsetAdjFrac)*MaxSep;
      y[j] = randflt(seed)*0.5*MaxSep;
      z[j] = randflt(seed)*0.5*MaxSep;
      mass[j] = 1.0f + randflt(seed);
    }


    for (int j = 0; j < ParticleCount; ++j)
      GravityForceKernel(ILParticleCount, &x[0], &y[0], &z[0], &mass[0],
                         px[j], py[j], pz[j], MaxSep*MaxSep,
                         SofteningLen*SofteningLen, ax, ay, az);
  }

#ifndef VERIFICATION_OUTPUT_ONLY
  End = std::clock();
#endif

  std::cout << ax << " " << ay << " " << az;

#ifndef VERIFICATION_OUTPUT_ONLY
  std::cout << ": ";
  std::cout << ((float)(End - Start))/CLOCKS_PER_SEC << " s\n";
#else
  std::cout << "\n";
#endif
}

int main(int argc, char *argv[]) {
#if defined(_OPENMP) && !defined(VERIFICATION_OUTPUT_ONLY)
  std::cout << "Maximum OpenMP Threads: " << omp_get_max_threads() << "\n";
#endif

  if (argc > 1)
    NumIters = atoi(argv[1]);
  std::cout << "Iterations: " << NumIters << "\n";

  run(GravityForceKernel4, "4th Order");
  run(GravityForceKernel5, "5th Order");
  run(GravityForceKernel6, "6th Order");

  return 0;
}

