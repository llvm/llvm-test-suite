#ifndef RTW_STB_IMAGE_H
#define RTW_STB_IMAGE_H

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

// Disable strict warnings for this header from the Microsoft Visual C++ compiler.
#ifdef _MSC_VER
    #pragma warning (push, 0)
#endif

#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image.h"

#include "DeviceArray.h"
#include "Map.h"
#include "String.h"
#include <cstdlib>
#include <iostream>

class rtw_image {
  public:
    __host__ __device__ rtw_image() : data(nullptr) {}
    __host__ __device__ rtw_image(int width, int height, unsigned char *data_)
        : data(data_), image_width(width), image_height(height) {
      bytes_per_scanline = image_width * bytes_per_pixel;
    }

    __host__ __device__ rtw_image(const char *image_filename) {
      TexDBTy *pDB;
#if __HIP_DEVICE_COMPILE__
      pDB = DevTexDB;
#else
      pDB = &TexDB;
#endif
      auto Loc = pDB->find(image_filename);
      if (Loc == pDB->end()) {
        printf("texture %s not found. Please pre_load it.\n", image_filename);
        __builtin_trap();
      }
      rtw_image *img = Loc->second.get();
      image_width = img->image_width;
      image_height = img->image_height;
      data = img->data;
      bytes_per_scanline = image_width * bytes_per_pixel;
    }

    static void pre_load(const char *image_filename) {
      // Loads image data from the specified file. If the RTW_IMAGES environment
      // variable is defined, looks only in that directory for the image file.
      // If the image was not found, searches for the specified image file first
      // from the current directory, then in the images/ subdirectory, then the
      // _parent's_ images/ subdirectory, and then _that_ parent, on so on, for
      // six levels up. If the image was not loaded successfully, width() and
      // height() will return 0.

      auto filename = std::string(image_filename);
      auto imagedir = getenv("RTW_IMAGES");

      // Hunt for the image file in some likely locations.
      if (imagedir && load(std::string(imagedir) + "/" + image_filename))
        return;
      if (load(filename))
        return;
      if (load("images/" + filename))
        return;
      if (load("../images/" + filename))
        return;
      if (load("../../images/" + filename))
        return;
      if (load("../../../images/" + filename))
        return;
      if (load("../../../../images/" + filename))
        return;
      if (load("../../../../../images/" + filename))
        return;
      if (load("../../../../../../images/" + filename))
        return;

      std::cerr << "ERROR: Could not load image file '" << image_filename
                << "'.\n";
    }

    __host__ __device__ ~rtw_image() {
      // We preload all textures in a global database and assume the textures
      // persist the whole program.
      // STBI_FREE(data);
    }

    static __global__ void textureLoadKernel(int width, int height,
                                             const char *name,
                                             unsigned char *data_) {
      if (!DevTexDB)
        DevTexDB = new TexDBTy;
      auto Loc = DevTexDB->find(name);
      if (Loc == DevTexDB->end())
        (*DevTexDB)[name] = makeShared<rtw_image>(width, height, data_);
    }
    static bool load(const std::string filename) {
      // Loads image data from the given file name. Returns true if the load
      // succeeded.
      auto n =
          bytes_per_pixel; // Dummy out parameter: original components per pixel
      int width = 0;
      int height = 0;
      unsigned char *data_ =
          stbi_load(filename.c_str(), &width, &height, &n, bytes_per_pixel);
      if (data_ != nullptr) {
        size_t lastSlashPos = filename.find_last_of("/");
        std::string name = filename;
        if (lastSlashPos != std::string::npos)
          name = name.substr(lastSlashPos + 1);
        auto Loc = TexDB.find(name.c_str());
        if (Loc == TexDB.end()) {
          TexDB[name.c_str()] = makeShared<rtw_image>(width, height, data_);
          DeviceArray<char> devName(name.length() + 1, name.c_str());
          DeviceArray<unsigned char> devTexture(width * height * n, data_);

          textureLoadKernel<<<1, 1>>>(width, height, devName.getDevicePtr(),
                                      devTexture.getDevicePtr());
        }
      }
      return data_ != nullptr;
    }

    __host__ __device__ int width() const {
      return (data == nullptr) ? 0 : image_width;
    }
    __host__ __device__ int height() const {
      return (data == nullptr) ? 0 : image_height;
    }

    __host__ __device__ const unsigned char *pixel_data(int x, int y) const {
      // Return the address of the three bytes of the pixel at x,y (or magenta
      // if no data).
      static unsigned char magenta[] = {255, 0, 255};
      if (data == nullptr)
        return magenta;

      x = clamp(x, 0, image_width);
      y = clamp(y, 0, image_height);

      return data + y * bytes_per_scanline + x * bytes_per_pixel;
    }

  private:
    static const int bytes_per_pixel = 3;
    unsigned char *data = nullptr;
    int image_width = 0, image_height = 0;
    int bytes_per_scanline = 0;

    __host__ __device__ static int clamp(int x, int low, int high) {
      // Return the value clamped to the range [low, high).
      if (x < low)
        return low;
      if (x < high)
        return x;
      return high - 1;
    }

    typedef Map<String, SharedPtr<rtw_image>> TexDBTy;
    static TexDBTy TexDB;
    __device__ static TexDBTy *DevTexDB;
};


// Restore MSVC compiler warnings
#ifdef _MSC_VER
    #pragma warning (pop)
#endif


#endif
