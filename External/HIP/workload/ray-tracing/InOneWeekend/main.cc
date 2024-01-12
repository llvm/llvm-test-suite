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
// Changes to the original code follows the following license.
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

#include "hip/hip_runtime.h"
#include "rtweekend.h"

#include "DeviceArray.h"
#include "PPMImageFile.h"
#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"
#include <chrono>

#define BLKDIM_X 16
#define BLKDIM_Y 16

__device__ hittable_list *dev_world;
__device__ camera *dev_cam;

__host__ __device__ void init(hittable_list **pWorld, camera **pCam) {
  *pWorld = new hittable_list;
  hittable_list &world = **pWorld;

  auto ground_material = makeShared<lambertian>(color(0.5, 0.5, 0.5));
  world.add(makeShared<sphere>(point3(0, -1000, 0), 1000, ground_material));

  unsigned rnd = 0;
  for (int a = -11; a < 11; a++) {
    for (int b = -11; b < 11; b++) {
      auto choose_mat = random_double(rnd);
      point3 center(a + 0.9 * random_double(rnd), 0.2,
                    b + 0.9 * random_double(rnd));

      if ((center - point3(4, 0.2, 0)).length() > 0.9) {
        SharedPtr<material> sphere_material;

        if (choose_mat < 0.8) {
          // diffuse
          auto albedo = color::random(rnd) * color::random(rnd);
          sphere_material = makeShared<lambertian>(albedo);
          world.add(makeShared<sphere>(center, 0.2, sphere_material));
        } else if (choose_mat < 0.95) {
          // metal
          auto albedo = color::random(0.5, 1, rnd);
          auto fuzz = random_double(0, 0.5, rnd);
          sphere_material = makeShared<metal>(albedo, fuzz);
          world.add(makeShared<sphere>(center, 0.2, sphere_material));
        } else {
          // glass
          sphere_material = makeShared<dielectric>(1.5);
          world.add(makeShared<sphere>(center, 0.2, sphere_material));
        }
      }
    }
  }

  auto material1 = makeShared<dielectric>(1.5);
  world.add(makeShared<sphere>(point3(0, 1, 0), 1.0, material1));

  auto material2 = makeShared<lambertian>(color(0.4, 0.2, 0.1));
  world.add(makeShared<sphere>(point3(-4, 1, 0), 1.0, material2));

  auto material3 = makeShared<metal>(color(0.7, 0.6, 0.5), 0.0);
  world.add(makeShared<sphere>(point3(4, 1, 0), 1.0, material3));

  *pCam = new camera;
  camera &cam = **pCam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 1200;
  cam.samples_per_pixel = 10;
  cam.max_depth = 20;

  cam.vfov = 20;
  cam.lookfrom = point3(13, 2, 3);
  cam.lookat = point3(0, 0, 0);
  cam.vup = vec3(0, 1, 0);

  cam.defocus_angle = 0.6;
  cam.focus_dist = 10.0;

  cam.initialize();
}

__global__ void initKernel() { init(&dev_world, &dev_cam); }

__launch_bounds__(BLKDIM_X *BLKDIM_Y) __global__
    void renderKernel(color *image) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  int j = blockIdx.y * blockDim.y + threadIdx.y;
  if (i < dev_cam->image_width && j < dev_cam->image_height)
    dev_cam->renderOnePixel(i, j, *dev_world, image);
}

int main(int argc, char *argv[]) {
  bool output_time = false;
  bool compare_cpu = false;

  // Process command line arguments
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-t") == 0) {
      output_time = true;
    } else if (strcmp(argv[i], "-c") == 0) {
      compare_cpu = true;
    }
  }

  hittable_list *world;
  camera *cam;
  init(&world, &cam);

  const int grid_x = std::ceil((float)cam->image_width / BLKDIM_X);
  const int grid_y = std::ceil((float)cam->image_height / BLKDIM_Y);
  printf("image width = %d height = %d\n", cam->image_width, cam->image_height);
  printf("block size = (%d, %d) grid size = (%d, %d)\n", BLKDIM_X, BLKDIM_Y,
         grid_x, grid_y);

  PPMImageFile ref_image("ref.ppm");
  ref_image.load();

  // Render by CPU.
  PPMImageFile cpu_image("cpu.ppm", cam->image_width, cam->image_height);
  std::chrono::duration<double, std::milli> cpu_duration;
  if (compare_cpu) {
    printf("Start rendering by CPU.\n");
    auto start_cpu = std::chrono::high_resolution_clock::now();
    cam->render(*world, cpu_image.getHostPtr());
    auto end_cpu = std::chrono::high_resolution_clock::now();
    cpu_duration = end_cpu - start_cpu;
    cpu_image.normalize();
    cpu_image.save();
    cpu_image.compare(ref_image);
  }

  PPMImageFile gpu_image("gpu.ppm", cam->image_width, cam->image_height);
  DeviceArray<color> gpu_image_data(cam->image_width * cam->image_height);
  // Need to set stack size since there is recursive function.
  checkHIP(hipDeviceSetLimit(hipLimitStackSize, 8192));
  initKernel<<<1, 1>>>();
  checkHIP(hipDeviceSynchronize());

  // Render by GPU and measure time.
  printf("Start rendering by GPU.\n");
  hipEvent_t start_gpu, stop_gpu;
  checkHIP(hipEventCreate(&start_gpu));
  checkHIP(hipEventCreate(&stop_gpu));
  checkHIP(hipEventRecord(start_gpu));
  renderKernel<<<dim3(grid_x, grid_y), dim3(BLKDIM_X, BLKDIM_Y)>>>(
      gpu_image_data.getDevicePtr());
  checkHIP(hipEventRecord(stop_gpu));
  checkHIP(hipEventSynchronize(stop_gpu));
  float gpu_duration_ms = 0;
  checkHIP(hipEventElapsedTime(&gpu_duration_ms, start_gpu, stop_gpu));
  checkHIP(hipEventDestroy(start_gpu));
  checkHIP(hipEventDestroy(stop_gpu));
  printf("Done.\n");

  checkHIP(hipDeviceSynchronize());
  gpu_image_data.toHost();
  checkHIP(hipDeviceSynchronize());
  gpu_image.setData(gpu_image_data.getHostPtr());
  gpu_image.normalize();
  gpu_image.save();
  if (compare_cpu)
    gpu_image.compare(cpu_image);
  gpu_image.compare(ref_image);

  // Conditionally output timing information
  if (output_time) {
    int total_pixels = cam->image_width * cam->image_height;
    if (compare_cpu) {
      double cpu_time_per_pixel = cpu_duration.count() / total_pixels;
      printf("CPU Time per Pixel: %f ms\n", cpu_time_per_pixel);
    }
    double gpu_time_per_pixel = gpu_duration_ms / total_pixels;
    printf("GPU Time per Pixel: %f ms\n", gpu_time_per_pixel);
  }
}
