#ifndef BVH_H
#define BVH_H
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

#include "hittable.h"
#include "hittable_list.h"

#include <algorithm>


class bvh_node : public hittable {
  public:
    __host__ __device__ bvh_node(const hittable_list &list, unsigned &rng)
        : bvh_node(list.objects, 0, list.objects.size(), rng) {}

    __host__ __device__ bvh_node(const Vector<SharedPtr<hittable>> &src_objects,
                                 size_t start, size_t end, unsigned &rng) {
      auto objects =
          src_objects; // Create a modifiable array of the source scene objects

      int axis = random_int(0, 2, rng);
      auto comparator = (axis == 0)   ? box_x_compare
                        : (axis == 1) ? box_y_compare
                                      : box_z_compare;

      size_t object_span = end - start;

      if (object_span == 1) {
        left = right = objects[start];
      } else if (object_span == 2) {
        if (comparator(objects[start], objects[start + 1])) {
          left = objects[start];
          right = objects[start + 1];
        } else {
          left = objects[start + 1];
          right = objects[start];
        }
      } else {
        sort(objects.begin() + start, objects.begin() + end, comparator);

        auto mid = start + object_span / 2;
        left = makeShared<bvh_node>(objects, start, mid, rng);
        right = makeShared<bvh_node>(objects, mid, end, rng);
      }

      bbox = aabb(left->bounding_box(), right->bounding_box());
    }

    __host__ __device__ bool hit(const ray &r, interval ray_t, hit_record &rec,
                                 unsigned &rng) const override {
      if (!bbox.hit(r, ray_t))
        return false;

      bool hit_left = left->hit(r, ray_t, rec, rng);
      bool hit_right = right->hit(
          r, interval(ray_t.min, hit_left ? rec.t : ray_t.max), rec, rng);

      return hit_left || hit_right;
    }

    __host__ __device__ aabb bounding_box() const override { return bbox; }

  private:
    SharedPtr<hittable> left;
    SharedPtr<hittable> right;
    aabb bbox;

    __host__ __device__ static bool box_compare(const SharedPtr<hittable> a,
                                                const SharedPtr<hittable> b,
                                                int axis_index) {
      return a->bounding_box().axis(axis_index).min <
             b->bounding_box().axis(axis_index).min;
    }

    __host__ __device__ static bool box_x_compare(const SharedPtr<hittable> a,
                                                  const SharedPtr<hittable> b) {
      return box_compare(a, b, 0);
    }

    __host__ __device__ static bool box_y_compare(const SharedPtr<hittable> a,
                                                  const SharedPtr<hittable> b) {
      return box_compare(a, b, 1);
    }

    __host__ __device__ static bool box_z_compare(const SharedPtr<hittable> a,
                                                  const SharedPtr<hittable> b) {
      return box_compare(a, b, 2);
    }
};


#endif
