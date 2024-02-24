#ifndef INTERVAL_H
#define INTERVAL_H
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

class interval {
public:
  double min, max;

  __host__ __device__ interval()
      : min(+infinity), max(-infinity) {} // Default interval is empty

  __host__ __device__ interval(double _min, double _max)
      : min(_min), max(_max) {}

  __host__ __device__ double size() const { return max - min; }

  __host__ __device__ interval expand(double delta) const {
    auto padding = delta / 2;
    return interval(min - padding, max + padding);
  }

  __host__ __device__ bool contains(double x) const {
    return min <= x && x <= max;
  }

  __host__ __device__ bool surrounds(double x) const {
    return min < x && x < max;
  }

  __host__ __device__ double clamp(double x) const {
    if (x < min)
      return min;
    if (x > max)
      return max;
    return x;
  }

  static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif
