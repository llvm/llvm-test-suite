#ifndef CONSTANT_MEDIUM_H
#define CONSTANT_MEDIUM_H
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
#include "material.h"
#include "texture.h"


class constant_medium : public hittable {
  public:
    __host__ __device__ constant_medium(SharedPtr<hittable> b, double d,
                                        SharedPtr<rt_texture> a)
        : boundary(b), neg_inv_density(-1 / d),
          phase_function(makeShared<isotropic>(a)) {}

    __host__ __device__ constant_medium(SharedPtr<hittable> b, double d,
                                        color c)
        : boundary(b), neg_inv_density(-1 / d),
          phase_function(makeShared<isotropic>(c)) {}

    __host__ __device__ bool hit(const ray &r, interval ray_t, hit_record &rec,
                                 unsigned &rng) const override {
      // Print occasional samples when debugging. To enable, set enableDebug
      // true.
#if DEBUG
      const bool enableDebug = false;
      const bool debugging = enableDebug && random_double(rng) < 0.00001;
#endif
      hit_record rec1, rec2;

      if (!boundary->hit(r, interval::universe, rec1, rng))
        return false;

      if (!boundary->hit(r, interval(rec1.t + 0.0001, infinity), rec2, rng))
        return false;

#if DEBUG
      if (debugging)
        std::clog << "\nt_min=" << rec1.t << ", t_max=" << rec2.t << '\n';
#endif
      if (rec1.t < ray_t.min)
        rec1.t = ray_t.min;
      if (rec2.t > ray_t.max)
        rec2.t = ray_t.max;

      if (rec1.t >= rec2.t)
        return false;

      if (rec1.t < 0)
        rec1.t = 0;

      auto ray_length = r.direction().length();
      auto distance_inside_boundary = (rec2.t - rec1.t) * ray_length;
      auto hit_distance = neg_inv_density * log(random_double(rng));

      if (hit_distance > distance_inside_boundary)
        return false;

      rec.t = rec1.t + hit_distance / ray_length;
      rec.p = r.at(rec.t);
#if DEBUG
      if (debugging) {
        std::clog << "hit_distance = " << hit_distance << '\n'
                  << "rec.t = " << rec.t << '\n'
                  << "rec.p = " << rec.p << '\n';
      }
#endif
      rec.normal = vec3(1, 0, 0); // arbitrary
      rec.front_face = true;      // also arbitrary
      rec.mat = phase_function;

      return true;
    }

    __host__ __device__ aabb bounding_box() const override {
      return boundary->bounding_box();
    }

  private:
    SharedPtr<hittable> boundary;
    double neg_inv_density;
    SharedPtr<material> phase_function;
};


#endif
