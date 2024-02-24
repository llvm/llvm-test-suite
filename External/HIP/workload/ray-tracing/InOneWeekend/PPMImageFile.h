#pragma once
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "color.h"
// Assuming 'color' is a class or struct already defined
// with overloaded operator+ and a method to output the color data

class PPMImageFile {
private:
  std::string filename;
  int image_width, image_height;
  std::vector<color> data;
  bool IsNormalized;

public:
  PPMImageFile(const std::string &file_name, int width = 0, int height = 0)
      : filename(file_name), image_width(width), image_height(height),
        IsNormalized(false) {
    data.resize(width * height);
  }

  color *getHostPtr() { return data.data(); }

  void setData(color *C) {
    for (int i = 0, e = image_width * image_height; i != e; ++i)
      data[i] = C[i];
  }

  void normalize() {
    for (auto &pixel_color : data) {
      auto r = pixel_color.x();
      auto g = pixel_color.y();
      auto b = pixel_color.z();

      // Apply a linear to gamma transform for gamma 2
      r = linear_to_gamma(r);
      g = linear_to_gamma(g);
      b = linear_to_gamma(b);

      // Write the translated [0,255] value of each color component.
      static const interval intensity(0.000, 0.999);
      pixel_color = color(static_cast<int>(256 * intensity.clamp(r)),
                          static_cast<int>(256 * intensity.clamp(g)),
                          static_cast<int>(256 * intensity.clamp(b)));
    }
    IsNormalized = true;
  }

  bool save() const {
    if (!IsNormalized) {
      std::cerr
          << "Error: Image is not normalized. Saving the unnormalized image."
          << std::endl;
      return false;
    }

    std::ofstream file(filename);

    if (!file) {
      std::cerr << "File could not be opened for writing." << std::endl;
      return false;
    }

    // PPM header
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Write each pixel to the file
    for (const auto &pixel_color : data) {
      file << pixel_color.x() << ' ' << pixel_color.y() << ' '
           << pixel_color.z() << '\n';
    }

    file.close();
    return true;
  }

  bool load() {
    std::ifstream file(filename);

    if (!file) {
      std::cerr << "File could not be opened for reading." << std::endl;
      return false;
    }

    std::string header;
    int max_val;

    // Read the header and check format
    file >> header;
    if (header != "P3") {
      std::cerr << "Unsupported file format." << std::endl;
      return false;
    }

    // Read image dimensions and maximum value
    file >> image_width >> image_height >> max_val;

    // Resize the data vector to hold the image data
    data.resize(image_width * image_height);

    // Read pixel data
    for (auto &pixel_color : data) {
      int r, g, b;
      file >> r >> g >> b;
      pixel_color = color(r, g, b);
    }

    IsNormalized = true; // Assuming the loaded image is already normalized
    file.close();
    return true;
  }
  bool compare(const PPMImageFile &img, double threshold = 1e-3) const {
    if (IsNormalized != img.IsNormalized) {
      std::cerr << "Cannot compare " << filename << " and " << img.filename
                << " because one is normalized and the other is not."
                << std::endl;
      return false;
    }

    if (image_width != img.image_width || image_height != img.image_height) {
      std::cerr << "Images dimensions do not match." << std::endl;
      return false;
    }
    if (IsNormalized) {
      threshold *= 255.0;
    }

    struct Difference {
      double value;
      int x, y;
    };

    std::vector<Difference> topDifferences;
    bool anySignificantDifference = false;

    for (int y = 0; y < image_height; ++y) {
      for (int x = 0; x < image_width; ++x) {
        const color &c1 = data[y * image_width + x];
        const color &c2 = img.data[y * image_width + x];

        double diff =
            std::max({std::abs(c1.x() - c2.x()), std::abs(c1.y() - c2.y()),
                      std::abs(c1.z() - c2.z())});

        if (diff > threshold) {
          anySignificantDifference = true;

          if (topDifferences.size() < 10) {
            topDifferences.push_back({diff, x, y});
            std::sort(topDifferences.begin(), topDifferences.end(),
                      [](const Difference &a, const Difference &b) {
                        return a.value > b.value;
                      });
          }
        }
      }
    }

    if (anySignificantDifference) {
      // Output top differences
      std::cout << "Top Differences between " << filename << " and "
                << img.filename << ":\n";
      for (const auto &diff : topDifferences) {
        std::cout << "Location (" << diff.x << ", " << diff.y << "), "
                  << "Difference: " << diff.value << ", " << filename << ": "
                  << data[diff.y * image_width + diff.x].toString() << ", "
                  << img.filename << ": "
                  << img.data[diff.y * image_width + diff.x].toString() << "\n";
      }
      return false;
    } else {
      std::cout << filename << " and " << img.filename << " are the same.\n";
      return true;
    }
  }
};
