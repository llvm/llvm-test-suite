#ifndef __HARRIS_H__
#define __HARRIS_H__

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

// ============================================================================

// This parameter is used to initialize the input image
#define BOX_SIZE 10

/* Comment this to not use google benchmark library */
#define BENCHMARK_LIB

// Image Size
#define HEIGHT 2048
#define WIDTH 2048

// Parameters For harris kernel
#define THRESHOLD 0.1

// ============================================================================

// Initialize a checkboard image
void initCheckboardImage(int height, int width);
// print image to output.txt
void printImage(int height, int width, float img[HEIGHT][WIDTH]);

// harris kernel from polymage_naive.cpp
void harrisKernel(int height, int width, float inputImg[4 + HEIGHT][4 + WIDTH],
                  float outputImg[HEIGHT][WIDTH],
                  float Ix[2 + HEIGHT][2 + WIDTH],
                  float Iy[2 + HEIGHT][2 + WIDTH],
                  float Ixx[2 + HEIGHT][2 + WIDTH],
                  float Ixy[2 + HEIGHT][2 + WIDTH],
                  float Iyy[2 + HEIGHT][2 + WIDTH], float Sxx[HEIGHT][WIDTH],
                  float Sxy[HEIGHT][WIDTH], float Syy[HEIGHT][WIDTH],
                  float det[HEIGHT][WIDTH], float trace[HEIGHT][WIDTH]);

// ============================================================================
#endif
