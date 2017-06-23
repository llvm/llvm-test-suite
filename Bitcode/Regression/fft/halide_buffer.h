#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#ifndef HALIDE_ATTRIBUTE_ALIGN
  #ifdef _MSC_VER
    #define HALIDE_ATTRIBUTE_ALIGN(x) __declspec(align(x))
  #else
    #define HALIDE_ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
  #endif
#endif
#ifndef BUFFER_T_DEFINED
#define BUFFER_T_DEFINED
#include <stdbool.h>
#include <stdint.h>
typedef struct buffer_t {
    uint64_t dev;
    uint8_t* host;
    int32_t extent[4];
    int32_t stride[4];
    int32_t min[4];
    int32_t elem_size;
    HALIDE_ATTRIBUTE_ALIGN(1) bool host_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) bool dev_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t _padding[10 - sizeof(void *)];
} buffer_t;
#endif
struct halide_filter_metadata_t;
#ifndef HALIDE_FUNCTION_ATTRS
#define HALIDE_FUNCTION_ATTRS
#endif
#ifndef FILTER_T_DEFINED
#define FILTER_T_DEFINED
typedef struct filter {
    const char *name;
    int (*fn)(buffer_t *,
              buffer_t *,
              buffer_t *);
} filter;
#endif

//int FftConvolve8x8xCHalide(struct halide_buffer_t *_input_buffer, struct halide_buffer_t *_kernel_buffer, struct halide_buffer_t *_result_buffer) HALIDE_FUNCTION_ATTRS;
//int FftConvolve8x8xCHalide_argv(void **args) HALIDE_FUNCTION_ATTRS;
//const struct halide_filter_metadata_t *FftConvolve64x64xRHalide_metadata() HALIDE_FUNCTION_ATTRS;

int FftConvolve8x8xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve8x8xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve8x8xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve8x8xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve16x16xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve16x16xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve16x16xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve16x16xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve32x32xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve32x32xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve32x32xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve32x32xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve64x64xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve64x64xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve64x64xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve64x64xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve128x128xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve128x128xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve128x128xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve128x128xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve256x256xCHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve256x256xCZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve256x256xRHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;
int FftConvolve256x256xRZHalide(struct buffer_t *_input, struct buffer_t *_kernel, struct buffer_t *_result) HALIDE_FUNCTION_ATTRS;

filter filters[] = {
  {"FftConvolve8x8xCHalide",&FftConvolve8x8xCHalide},
  {"FftConvolve8x8xCZHalide",&FftConvolve8x8xCZHalide},
  {"FftConvolve8x8xRHalide",&FftConvolve8x8xRHalide},
  {"FftConvolve8x8xRZHalide",&FftConvolve8x8xRZHalide},
  {"FftConvolve16x16xCHalide",&FftConvolve16x16xCHalide},
  {"FftConvolve16x16xCZHalide",&FftConvolve16x16xCZHalide},
  {"FftConvolve16x16xRHalide",&FftConvolve16x16xRHalide},
  {"FftConvolve16x16xRZHalide",&FftConvolve16x16xRZHalide},
  {"FftConvolve32x32xCHalide",&FftConvolve32x32xCHalide},
  {"FftConvolve32x32xCZHalide",&FftConvolve32x32xCZHalide},
  {"FftConvolve32x32xRHalide",&FftConvolve32x32xRHalide},
  {"FftConvolve32x32xRZHalide",&FftConvolve32x32xRZHalide},
  {"FftConvolve64x64xCHalide",&FftConvolve64x64xCHalide},
  {"FftConvolve64x64xCZHalide",&FftConvolve64x64xCZHalide},
  {"FftConvolve64x64xRHalide",&FftConvolve64x64xRHalide},
  {"FftConvolve64x64xRZHalide",&FftConvolve64x64xRZHalide},
  {"FftConvolve128x128xCHalide",&FftConvolve128x128xCHalide},
  {"FftConvolve128x128xCZHalide",&FftConvolve128x128xCZHalide},
  {"FftConvolve128x128xRHalide",&FftConvolve128x128xRHalide},
  {"FftConvolve128x128xRZHalide",&FftConvolve128x128xRZHalide},
  {"FftConvolve256x256xCHalide",&FftConvolve256x256xCHalide},
  {"FftConvolve256x256xCZHalide",&FftConvolve256x256xCZHalide},
  {"FftConvolve256x256xRHalide",&FftConvolve256x256xRHalide},
  {"FftConvolve256x256xRZHalide",&FftConvolve256x256xRZHalide},
  {NULL, NULL}};

