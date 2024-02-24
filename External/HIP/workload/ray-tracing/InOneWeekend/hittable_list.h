#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
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

#include "rtweekend.h"

#include "hittable.h"

#include "Vector.h"
#include <memory>

class hittable_list : public hittable {
public:
  Vector<SharedPtr<hittable>> objects;

  __host__ __device__ hittable_list() {}
  __host__ __device__ hittable_list(SharedPtr<hittable> object) { add(object); }

  __host__ __device__ void clear() { objects.clear(); }

  __host__ __device__ void add(SharedPtr<hittable> object) {
    objects.push_back(object);
  }

  __host__ __device__ bool hit(const ray &r, interval ray_t,
                               hit_record &rec) const override {
    hit_record temp_rec;
    auto hit_anything = false;
    auto closest_so_far = ray_t.max;

    for (unsigned I = 0, E = objects.size(); I != E; ++I) {
      const auto &object = objects[I];
      if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
        hit_anything = true;
        closest_so_far = temp_rec.t;
        rec = temp_rec;
      }
    }

    return hit_anything;
  }
};

#endif
