#ifndef CAMERA_H
#define CAMERA_H
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

#include "color.h"
#include "hittable.h"
#include "material.h"
#include <fstream>

class camera {
public:
  double aspect_ratio = 1.0;  // Ratio of image width over height
  int image_width = 100;      // Rendered image width in pixel count
  int image_height = 0;       // Rendered image height
  int samples_per_pixel = 10; // Count of random samples for each pixel
  int max_depth = 10;         // Maximum number of ray bounces into scene

  double vfov = 90;                   // Vertical view angle (field of view)
  point3 lookfrom = point3(0, 0, -1); // Point camera is looking from
  point3 lookat = point3(0, 0, 0);    // Point camera is looking at
  vec3 vup = vec3(0, 1, 0);           // Camera-relative "up" direction

  double defocus_angle = 0; // Variation angle of rays through each pixel
  double focus_dist =
      10; // Distance from camera lookfrom point to plane of perfect focus

  // Render the pixel at row i and column j.
  __host__ __device__ void renderOnePixel(int i, int j, const hittable &world,
                                          color *img) {
    unsigned rnd = j * image_width + i;
    color pixel_color(0, 0, 0);
    for (int sample = 0; sample < samples_per_pixel; ++sample) {
      ray r = get_ray(i, j, rnd);
      pixel_color += ray_color(r, max_depth, world, rnd);
    }
    img[j * image_width + i] = pixel_color * (1.0 / samples_per_pixel);
  }

  void render(const hittable &world, color *img) {
    for (int j = 0; j < image_height; ++j) {
      if ((image_height - j) % 100 == 0)
        std::cout << "Scanlines remaining: " << (image_height - j) << '\n'
                  << std::flush;
      for (int i = 0; i < image_width; ++i) {
        renderOnePixel(i, j, world, img);
      }
    }

    std::cout << "Done.\n";
  }

private:
  point3 center;       // Camera center
  point3 pixel00_loc;  // Location of pixel 0, 0
  vec3 pixel_delta_u;  // Offset to pixel to the right
  vec3 pixel_delta_v;  // Offset to pixel below
  vec3 u, v, w;        // Camera frame basis vectors
  vec3 defocus_disk_u; // Defocus disk horizontal radius
  vec3 defocus_disk_v; // Defocus disk vertical radius

public:
  __host__ __device__ void initialize() {
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    center = lookfrom;

    // Determine viewport dimensions.
    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta / 2);
    auto viewport_height = 2 * h * focus_dist;
    auto viewport_width =
        viewport_height * (static_cast<double>(image_width) / image_height);

    // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    // Calculate the vectors across the horizontal and down the vertical
    // viewport edges.
    vec3 viewport_u =
        viewport_width * u; // Vector across viewport horizontal edge
    vec3 viewport_v =
        viewport_height * -v; // Vector down viewport vertical edge

    // Calculate the horizontal and vertical delta vectors to the next pixel.
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left =
        center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Calculate the camera defocus disk basis vectors.
    auto defocus_radius =
        focus_dist * tan(degrees_to_radians(defocus_angle / 2));
    defocus_disk_u = u * defocus_radius;
    defocus_disk_v = v * defocus_radius;
  }

private:
  __host__ __device__ ray get_ray(int i, int j, unsigned &rnd) const {
    // Get a randomly-sampled camera ray for the pixel at location i,j,
    // originating from the camera defocus disk.

    auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    auto pixel_sample = pixel_center + pixel_sample_square(rnd);

    auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample(rnd);
    auto ray_direction = pixel_sample - ray_origin;

    return ray(ray_origin, ray_direction);
  }

  __host__ __device__ vec3 pixel_sample_square(unsigned &rnd) const {
    // Returns a random point in the square surrounding a pixel at the origin.
    auto px = -0.5 + random_double(rnd);
    auto py = -0.5 + random_double(rnd);
    return (px * pixel_delta_u) + (py * pixel_delta_v);
  }

  __host__ __device__ vec3 pixel_sample_disk(double radius,
                                             unsigned &rnd) const {
    // Generate a sample from the disk of given radius around a pixel at the
    // origin.
    auto p = radius * random_in_unit_disk(rnd);
    return (p[0] * pixel_delta_u) + (p[1] * pixel_delta_v);
  }

  __host__ __device__ point3 defocus_disk_sample(unsigned &rnd) const {
    // Returns a random point in the camera defocus disk.
    auto p = random_in_unit_disk(rnd);
    return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
  }

  __host__ __device__ color ray_color(const ray &r, int depth,
                                      const hittable &world,
                                      unsigned &rnd) const {
    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
      return color(0, 0, 0);

    hit_record rec;

    if (world.hit(r, interval(0.001, infinity), rec)) {
      ray scattered;
      color attenuation;
      if (rec.mat->scatter(r, rec, attenuation, scattered, rnd))
        return attenuation * ray_color(scattered, depth - 1, world, rnd);
      return color(0, 0, 0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
  }
};

#endif
