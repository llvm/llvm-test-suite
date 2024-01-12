#ifndef MATERIAL_H
#define MATERIAL_H
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
#include "texture.h"


class material {
  public:
    virtual __host__ __device__ ~material() = default;

    virtual __host__ __device__ color emitted(double u, double v,
                                              const point3 &p) const {
      return color(0, 0, 0);
    }

    virtual __host__ __device__ bool scatter(const ray &r_in,
                                             const hit_record &rec,
                                             color &attenuation, ray &scattered,
                                             unsigned &rnd) const = 0;
};


class lambertian : public material {
  public:
    __host__ __device__ lambertian(const color &a)
        : albedo(makeShared<solid_color>(a)) {}
    __host__ __device__ lambertian(SharedPtr<rt_texture> a) : albedo(a) {}

    virtual __host__ __device__ bool scatter(const ray &r_in,
                                             const hit_record &rec,
                                             color &attenuation, ray &scattered,
                                             unsigned &rnd) const override {
      (void)r_in;
      auto scatter_direction = rec.normal + random_unit_vector(rnd);

      // Catch degenerate scatter direction
      if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

      scattered = ray(rec.p, scatter_direction, r_in.time());
      attenuation = albedo->value(rec.u, rec.v, rec.p);
      return true;
    }

  private:
    SharedPtr<rt_texture> albedo;
};


class metal : public material {
  public:
    __host__ __device__ metal(const color &a, double f)
        : albedo(a), fuzz(f < 1 ? f : 1) {}

    __host__ __device__ bool scatter(const ray &r_in, const hit_record &rec,
                                     color &attenuation, ray &scattered,
                                     unsigned &rnd) const override {
      vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere(rnd), r_in.time());
      attenuation = albedo;
      return (dot(scattered.direction(), rec.normal) > 0);
    }

  private:
    color albedo;
    double fuzz;
};


class dielectric : public material {
  public:
    __host__ __device__ dielectric(double index_of_refraction)
        : ir(index_of_refraction) {}

    __host__ __device__ bool scatter(const ray &r_in, const hit_record &rec,
                                     color &attenuation, ray &scattered,
                                     unsigned &rnd) const override {
      attenuation = color(1.0, 1.0, 1.0);
      double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

      vec3 unit_direction = unit_vector(r_in.direction());
      double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
      double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

      bool cannot_refract = refraction_ratio * sin_theta > 1.0;
      vec3 direction;

      if (cannot_refract ||
          reflectance(cos_theta, refraction_ratio) > random_double(rnd))
        direction = reflect(unit_direction, rec.normal);
      else
        direction = refract(unit_direction, rec.normal, refraction_ratio);

      scattered = ray(rec.p, direction, r_in.time());
      return true;
    }

  private:
    double ir; // Index of Refraction

    static __host__ __device__ double reflectance(double cosine,
                                                  double ref_idx) {
      // Use Schlick's approximation for reflectance.
      auto r0 = (1 - ref_idx) / (1 + ref_idx);
      r0 = r0 * r0;
      return r0 + (1 - r0) * pow((1 - cosine), 5);
    }
};


class diffuse_light : public material {
  public:
    __host__ __device__ diffuse_light(SharedPtr<rt_texture> a) : emit(a) {}
    __host__ __device__ diffuse_light(color c)
        : emit(makeShared<solid_color>(c)) {}

    __host__ __device__ bool scatter(const ray &r_in, const hit_record &rec,
                                     color &attenuation, ray &scattered,
                                     unsigned &rnd) const override {
      return false;
    }

    __host__ __device__ color emitted(double u, double v,
                                      const point3 &p) const override {
      return emit->value(u, v, p);
    }

  private:
    SharedPtr<rt_texture> emit;
};


class isotropic : public material {
  public:
    __host__ __device__ isotropic(color c)
        : albedo(makeShared<solid_color>(c)) {}
    __host__ __device__ isotropic(SharedPtr<rt_texture> a) : albedo(a) {}

    __host__ __device__ bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered, unsigned& rnd)
    const override {
        scattered = ray(rec.p, random_unit_vector(rnd), r_in.time());
        attenuation = albedo->value(rec.u, rec.v, rec.p);
        return true;
    }

  private:
    SharedPtr<rt_texture> albedo;
};


#endif
