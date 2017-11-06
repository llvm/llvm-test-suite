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
#include <cmath>

extern const float PolyCoefficients4[] = {
  0.263729f, -0.0686285f, 0.00882248f, -0.000592487f, 0.0000164622f
};

extern const float PolyCoefficients5[] = {
  0.269327f, -0.0750978f, 0.0114808f, -0.00109313f, 0.0000605491f,
  -0.00000147177f
};

extern const float PolyCoefficients6[] = {
  0.271431f, -0.0783394f, 0.0133122f, -0.00159485f, 0.000132336f,
  -0.00000663394f, 0.000000147305f
};

// HACC's gravity short-range-force kernel represents the part of the 1/r^2
// gravitational force that is not computed by the long-range grid solver. This
// kernel computes the acceleration of a target particle from all of the other
// particles in the provided interaction lists. It is assumed that the target
// particle has unit mass while the interaction-list can contain pseudo
// particles with larger mass values. Beyond a distance of MaxSep, the
// inter-particle force should be completely accounted for by the long-range
// grid solver (and thus we filter out such interactions here). Closer than
// MaxSep, we directly compute the inter-particle force, subtracting the
// long-range part of the force (as fit to a polynomial of the specified
// degree). A softening length, SofteningLen, is also used, as is standard in
// N-body codes.

template <int PolyOrder, const float (&PolyCoefficients)[PolyOrder+1]>
static void GravityForceKernel(int n, float *RESTRICT x, float *RESTRICT y,
                               float *RESTRICT z, float *RESTRICT mass,
                               float x0, float y0, float z0,
                               float MaxSepSqrd, float SofteningLenSqrd,
                               float &RESTRICT ax, float &RESTRICT ay,
                               float &RESTRICT az) {
  float lax = 0.0f, lay = 0.0f, laz = 0.0f;

// As written below, the mass array is conditionally accessed (i.e. accessed
// only if the interaction is not filtered by the distance checks). This will
// tend to inhibit vectorization on architectures without masked vector loads.
// With OpenMP 4+, we can explicitly inform the compiler that vectorization is
// safe. 
//
// For the test suite: Clang does not report a high-enough version of OpenMP
// to enable the pragma below. Moreover, vectorization is desirable regardless
// of whether OpenMP is enabled (even if Clang's reported version were high
// enough), so we also use the Clang loop pragma to assume vectorization safety.
#if _OPENMP >= 201307
#pragma omp simd reduction(+:lax,lay,laz)
#elif defined(clang)
#pragma clang loop vectorize(assume_safety)
#endif
  for (int i = 0; i < n; ++i) {
    float dx = x[i] - x0, dy = y[i] - y0, dz = z[i] - z0;
    float r2 = dx * dx + dy * dy + dz * dz;

    if (r2 >= MaxSepSqrd || r2 == 0.0f)
      continue;

    float r2s = r2 + SofteningLenSqrd;
    float f = PolyCoefficients[PolyOrder];
    for (int p = 1; p <= PolyOrder; ++p)
      f = PolyCoefficients[PolyOrder-p] + r2*f;

    f = (1.0f / (r2s * std::sqrt(r2s)) - f) * mass[i];

    lax += f * dx;
    lay += f * dy;
    laz += f * dz; 
  }

  ax += lax;
  ay += lay;
  az += laz;
}

void GravityForceKernel4(int n, float *RESTRICT x, float *RESTRICT y,
                         float *RESTRICT z, float *RESTRICT mass,
                         float x0, float y0, float z0,
                         float MaxSepSqrd, float SofteningLenSqrd,
                         float &RESTRICT ax, float &RESTRICT ay,
                         float &RESTRICT az) {
  GravityForceKernel<4, PolyCoefficients4>(n, x, y, z, mass, x0, y0, z0,
                                           MaxSepSqrd, SofteningLenSqrd,
                                           ax, ay, az);
}

void GravityForceKernel5(int n, float *RESTRICT x, float *RESTRICT y,
                         float *RESTRICT z, float *RESTRICT mass,
                         float x0, float y0, float z0,
                         float MaxSepSqrd, float SofteningLenSqrd,
                         float &RESTRICT ax, float &RESTRICT ay,
                         float &RESTRICT az) {
  GravityForceKernel<5, PolyCoefficients5>(n, x, y, z, mass, x0, y0, z0,
                                           MaxSepSqrd, SofteningLenSqrd,
                                           ax, ay, az);
}

void GravityForceKernel6(int n, float *RESTRICT x, float *RESTRICT y,
                         float *RESTRICT z, float *RESTRICT mass,
                         float x0, float y0, float z0,
                         float MaxSepSqrd, float SofteningLenSqrd,
                         float &RESTRICT ax, float &RESTRICT ay,
                         float &RESTRICT az) {
  GravityForceKernel<6, PolyCoefficients6>(n, x, y, z, mass, x0, y0, z0,
                                           MaxSepSqrd, SofteningLenSqrd,
                                           ax, ay, az);
}

