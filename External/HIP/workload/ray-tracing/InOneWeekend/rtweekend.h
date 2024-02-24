#ifndef RTWEEKEND_H
#define RTWEEKEND_H
//==============================================================================================
// Originally written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide. This software is distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public
// Domain Dedication along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
//
// The original source code is from
//    https://github.com/RayTracing/raytracing.github.io/tree/release/src/InOneWeekend
//
// Changes to the original code follow the following license.
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

#include "SharedPtr.h"
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Usings

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

__host__ __device__ inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

const unsigned LCG_RAND_MAX = 2147483647; // 2^31-1

__host__ __device__ unsigned lcg_rand(unsigned x) {
  const unsigned a = 1103515245;
  const unsigned c = 12345;
  const unsigned m = LCG_RAND_MAX + 1;

  return (a * x + c) % m;
}

__host__ __device__ inline double random_double(unsigned &rnd) {
  unsigned rnd0 = rnd;
  rnd = lcg_rand(rnd);
  // Returns a random real in [0,1).
  return rnd0 / (RAND_MAX + 1.0);
}

__host__ __device__ inline double random_double(double min, double max,
                                                unsigned &rnd) {
  // Returns a random real in [min,max).
  return min + (max - min) * random_double(rnd);
}

// Common Headers

#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif
