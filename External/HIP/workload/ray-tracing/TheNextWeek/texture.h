#ifndef TEXTURE_H
#define TEXTURE_H
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

#include "perlin.h"
#include "rtw_stb_image.h"

class rt_texture {
public:
  virtual ~rt_texture() = default;

  virtual __host__ __device__ color value(double u, double v,
                                          const point3 &p) const = 0;
};

class solid_color : public rt_texture {
public:
  __host__ __device__ solid_color(color c) : color_value(c) {}

  __host__ __device__ solid_color(double red, double green, double blue)
      : solid_color(color(red, green, blue)) {}

  __host__ __device__ color value(double u, double v,
                                  const point3 &p) const override {
    return color_value;
  }

private:
  color color_value;
};

class checker_texture : public rt_texture {
public:
  __host__ __device__ checker_texture(double _scale,
                                      SharedPtr<rt_texture> _even,
                                      SharedPtr<rt_texture> _odd)
      : inv_scale(1.0 / _scale), even(_even), odd(_odd) {}

  __host__ __device__ checker_texture(double _scale, color c1, color c2)
      : inv_scale(1.0 / _scale), even(makeShared<solid_color>(c1)),
        odd(makeShared<solid_color>(c2)) {}

  __host__ __device__ color value(double u, double v,
                                  const point3 &p) const override {
    auto xInteger = static_cast<int>(std::floor(inv_scale * p.x()));
    auto yInteger = static_cast<int>(std::floor(inv_scale * p.y()));
    auto zInteger = static_cast<int>(std::floor(inv_scale * p.z()));

    bool isEven = (xInteger + yInteger + zInteger) % 2 == 0;

    return isEven ? even->value(u, v, p) : odd->value(u, v, p);
  }

private:
  double inv_scale;
  SharedPtr<rt_texture> even;
  SharedPtr<rt_texture> odd;
};

class noise_texture : public rt_texture {
public:
  __host__ __device__ noise_texture(unsigned &rng) : noise(rng) {}

  __host__ __device__ noise_texture(double sc, unsigned &rng)
      : noise(rng), scale(sc) {}

  __host__ __device__ color value(double u, double v,
                                  const point3 &p) const override {
    auto s = scale * p;
    return color(1, 1, 1) * 0.5 * (1 + sin(s.z() + 10 * noise.turb(s)));
  }

private:
  perlin noise;
  double scale;
};

class image_texture : public rt_texture {
public:
  __host__ __device__ image_texture(const char *filename) : image(filename) {}

  __host__ __device__ color value(double u, double v,
                                  const point3 &p) const override {
    // If we have no rt_texture data, then return solid cyan as a debugging aid.
    if (image.height() <= 0)
      return color(0, 1, 1);

    // Clamp input rt_texture coordinates to [0,1] x [1,0]
    u = interval(0, 1).clamp(u);
    v = 1.0 - interval(0, 1).clamp(v); // Flip V to image coordinates

    auto i = static_cast<int>(u * image.width());
    auto j = static_cast<int>(v * image.height());
    auto pixel = image.pixel_data(i, j);

    auto color_scale = 1.0 / 255.0;
    return color(color_scale * pixel[0], color_scale * pixel[1],
                 color_scale * pixel[2]);
  }

private:
  rtw_image image;
};

#endif
