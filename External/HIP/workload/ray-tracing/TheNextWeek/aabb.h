#ifndef AABB_H
#define AABB_H
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
//    https://github.com/RayTracing/raytracing.github.io/tree/release/src/TheNextWeek
//
// Changes to the original code follow the following license.
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

#include "rtweekend.h"
#include <algorithm>
#include <type_traits>

class aabb {
  public:
    interval x, y, z;

    // The default AABB is empty, since intervals are empty by default.
    __host__ __device__ aabb() {}

    __host__ __device__ aabb(const interval &ix, const interval &iy,
                             const interval &iz)
        : x(ix), y(iy), z(iz) {}

    __host__ __device__ aabb(const point3 &a, const point3 &b) {
      x = interval(fmin(a[0], b[0]), fmax(a[0], b[0]));
      y = interval(fmin(a[1], b[1]), fmax(a[1], b[1]));
      z = interval(fmin(a[2], b[2]), fmax(a[2], b[2]));
    }

    __host__ __device__ aabb(const aabb &box0, const aabb &box1) {
      x = interval(box0.x, box1.x);
      y = interval(box0.y, box1.y);
      z = interval(box0.z, box1.z);
    }

    __host__ __device__ aabb pad() {
      double delta = 0.0001;
      interval new_x = (x.size() >= delta) ? x : x.expand(delta);
      interval new_y = (y.size() >= delta) ? y : y.expand(delta);
      interval new_z = (z.size() >= delta) ? z : z.expand(delta);

      return aabb(new_x, new_y, new_z);
    }

    __host__ __device__ const interval &axis(int n) const {
      if (n == 1)
        return y;
      if (n == 2)
        return z;
      return x;
    }

    __host__ __device__ bool hit(const ray &r, interval ray_t) const {
      for (int a = 0; a < 3; a++) {
        auto invD = 1 / r.direction()[a];
        auto orig = r.origin()[a];

        auto t0 = (axis(a).min - orig) * invD;
        auto t1 = (axis(a).max - orig) * invD;

        if (invD < 0)
          rt_swap(t0, t1);

        if (t0 > ray_t.min)
          ray_t.min = t0;
        if (t1 < ray_t.max)
          ray_t.max = t1;

        if (ray_t.max <= ray_t.min)
          return false;
      }
      return true;
    }
};

__host__ __device__ aabb operator+(const aabb &bbox, const vec3 &offset) {
  return aabb(bbox.x + offset.x(), bbox.y + offset.y(), bbox.z + offset.z());
}

__host__ __device__ aabb operator+(const vec3 &offset, const aabb &bbox) {
  return bbox + offset;
}

#endif
