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
    int (*fn)(buffer_t *, // uint8
              buffer_t *); // uint32
} filter;
#endif

#ifdef __cplusplus
extern "C" {
#endif
int vector_widen(buffer_t *_in_u8_buffer, buffer_t *widen_buffer) HALIDE_FUNCTION_ATTRS;
int vector_widen_argv(void **args) HALIDE_FUNCTION_ATTRS;
extern const struct halide_filter_metadata_t vector_widen_metadata;
#ifdef __cplusplus
}  // extern "C"
#endif

filter filters[] = {
{"vector_widen", &vector_widen},
{NULL, NULL}};


