#ifndef HITTABLE_H
#define HITTABLE_H
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

#include "aabb.h"


class material;

class hit_record {
  public:
    point3 p;
    vec3 normal;
    SharedPtr<material> mat;
    double t;
    double u;
    double v;
    bool front_face;

    __host__ __device__ void set_face_normal(const ray &r,
                                             const vec3 &outward_normal) {
      // Sets the hit record normal vector.
      // NOTE: the parameter `outward_normal` is assumed to have unit length.

      front_face = dot(r.direction(), outward_normal) < 0;
      normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
  public:
    __host__ __device__ virtual ~hittable() = default;

    __host__ __device__ virtual bool
    hit(const ray &r, interval ray_t, hit_record &rec, unsigned &rng) const = 0;
    __host__ __device__ virtual aabb bounding_box() const = 0;
};


class translate : public hittable {
  public:
    __host__ __device__ translate(SharedPtr<hittable> p,
                                  const vec3 &displacement)
        : object(p), offset(displacement) {
      bbox = object->bounding_box() + offset;
    }

    __host__ __device__ bool hit(const ray &r, interval ray_t, hit_record &rec,
                                 unsigned &rng) const override {
      // Move the ray backwards by the offset
      ray offset_r(r.origin() - offset, r.direction(), r.time());

      // Determine whether an intersection exists along the offset ray (and if
      // so, where)
      if (!object->hit(offset_r, ray_t, rec, rng))
        return false;

      // Move the intersection point forwards by the offset
      rec.p += offset;

      return true;
    }

    __host__ __device__ aabb bounding_box() const override { return bbox; }

  private:
    SharedPtr<hittable> object;
    vec3 offset;
    aabb bbox;
};


class rotate_y : public hittable {
  public:
    __host__ __device__ rotate_y(SharedPtr<hittable> p, double angle)
        : object(p) {
      auto radians = degrees_to_radians(angle);
      sin_theta = sin(radians);
      cos_theta = cos(radians);
      bbox = object->bounding_box();

      point3 min(infinity, infinity, infinity);
      point3 max(-infinity, -infinity, -infinity);

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            auto x = i * bbox.x.max + (1 - i) * bbox.x.min;
            auto y = j * bbox.y.max + (1 - j) * bbox.y.min;
            auto z = k * bbox.z.max + (1 - k) * bbox.z.min;

            auto newx = cos_theta * x + sin_theta * z;
            auto newz = -sin_theta * x + cos_theta * z;

            vec3 tester(newx, y, newz);

            for (int c = 0; c < 3; c++) {
              min[c] = fmin(min[c], tester[c]);
              max[c] = fmax(max[c], tester[c]);
            }
          }
        }
      }

      bbox = aabb(min, max);
    }

    __host__ __device__ bool hit(const ray &r, interval ray_t, hit_record &rec,
                                 unsigned &rng) const override {
      // Change the ray from world space to object space
      auto origin = r.origin();
      auto direction = r.direction();

      origin[0] = cos_theta * r.origin()[0] - sin_theta * r.origin()[2];
      origin[2] = sin_theta * r.origin()[0] + cos_theta * r.origin()[2];

      direction[0] =
          cos_theta * r.direction()[0] - sin_theta * r.direction()[2];
      direction[2] =
          sin_theta * r.direction()[0] + cos_theta * r.direction()[2];

      ray rotated_r(origin, direction, r.time());

      // Determine whether an intersection exists in object space (and if so,
      // where)
      if (!object->hit(rotated_r, ray_t, rec, rng))
        return false;

      // Change the intersection point from object space to world space
      auto p = rec.p;
      p[0] = cos_theta * rec.p[0] + sin_theta * rec.p[2];
      p[2] = -sin_theta * rec.p[0] + cos_theta * rec.p[2];

      // Change the normal from object space to world space
      auto normal = rec.normal;
      normal[0] = cos_theta * rec.normal[0] + sin_theta * rec.normal[2];
      normal[2] = -sin_theta * rec.normal[0] + cos_theta * rec.normal[2];

      rec.p = p;
      rec.normal = normal;

      return true;
    }

    __host__ __device__ aabb bounding_box() const override { return bbox; }

  private:
    SharedPtr<hittable> object;
    double sin_theta;
    double cos_theta;
    aabb bbox;
};

#endif
