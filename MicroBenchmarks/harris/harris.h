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
#define HEIGHT 2050
#define WIDTH  2050

// Parameters For harris kernel
#define THRESHOLD 0.1 

// ============================================================================

// Initialize a checkboard image
void initCheckboardImage(int height, int width); 
// print image to output.txt
void printImage(int height, int width, float img[(2 + HEIGHT)][2 + WIDTH]);

// harris kernel from polymage_naive.cpp
void harrisKernel(int height 
                  , int width 
                  , float inputImg[2 + HEIGHT][2 + WIDTH] 
                  , float outputImg[(2 + HEIGHT)][2 + WIDTH] 
                  , float Ix [(2 + HEIGHT)][2 + WIDTH] 
                  , float Iy [(2 + HEIGHT)][2 + WIDTH] 
                  , float Ixx [(2 + HEIGHT)][2 + WIDTH] 
                  , float Ixy [(2 + HEIGHT)][2 + WIDTH] 
                  , float Iyy [(2 + HEIGHT)][2 + WIDTH] 
                  , float Sxx [(2 + HEIGHT)][2 + WIDTH] 
                  , float Sxy [(2 + HEIGHT)][2 + WIDTH] 
                  , float Syy [(2 + HEIGHT)][2 + WIDTH] 
                  , float det [(2 + HEIGHT)][2 + WIDTH] 
                  , float trace [(2 + HEIGHT)][2 + WIDTH]);

// ============================================================================
#endif
