/**
This file contains some utility functions that Image processing kernels require

Written by Pankaj Kukreja
Indian Institute of Technology Hyderabad
*/

#include "ImageHelper.h"
#include "glibc_compat_rand.h"
#include <cstdlib>
#include <fstream>  // For reading and saving Image
#include <iostream> // For std::cerr

// Initialize a random Image
void initializeRandomImage(int *image, int height, int width) {
  glibc_compat_srand(7);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i * width + j] = glibc_compat_rand() % 256;
    }
  }
}

// Save Image to outputFile
void saveImage(int *image, const char *outputFile, int height, int width) {
  std::ofstream outfile;
  outfile.open(outputFile, std::ios::out | std::ios::trunc);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Just for safety
      if (image[i * width + j] > 255) {
        outfile << 255 << " ";
      } else if (image[i * width + j] < 0) {
        outfile << 0 << " ";
      } else {
        outfile << image[i * width + j] << " ";
      }
    }
    outfile << std::endl;
  }
}

// Initializes a random RGB Image
void initializeRandomColouredImage(int *image, int height, int width) {
  glibc_compat_srand(7);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i * (width * 3) + j * 3 + 0] = glibc_compat_rand() % 256;
      image[i * (width * 3) + j * 3 + 1] = glibc_compat_rand() % 256;
      image[i * (width * 3) + j * 3 + 2] = glibc_compat_rand() % 256;
    }
  }
}

// Read Pixel values of a black n white Image from $inputFile
void initializeImage(int *image, char *inputFile, int height, int width) {
  std::ifstream inFile(inputFile, std::ios::binary);

  if (!inFile) {
    std::cerr << " Can't open file " << inputFile << std::endl;
    exit(1);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      inFile >> image[i * width + j];
    }
  }
  inFile.close();
}

// Read Pixel values of a coloured Image from $inputFile
void initializeColoredImage(int *image, char *inputFile, int height,
                            int width) {
  std::ifstream inFile(inputFile, std::ios::binary);

  if (!inFile) {
    std::cerr << " Can't open file " << inputFile << std::endl;
    exit(1);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      inFile >> image[i * width + j + 0]; // R
      inFile >> image[i * width + j + 1]; // G
      inFile >> image[i * width + j + 2]; // B
    }
  }
  inFile.close();
}
