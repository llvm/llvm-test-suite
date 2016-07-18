#include "halide_buffer.h"
#ifndef FILTER_T_DEFINED
#define FILTER_T_DEFINED
typedef struct filter {
    const char *name;
    int (*fn)(buffer_t *, // float32
              buffer_t *, // float64
              buffer_t *, // int8
              buffer_t *, // uint8
              buffer_t *, // int16
              buffer_t *, // uint16
              buffer_t *, // int32
              buffer_t *, // uint32
              buffer_t *, // int64
              buffer_t *, // uint64
              buffer_t *); // output
} filter;
#endif
#ifdef __cplusplus
extern "C" {
#endif
int test_op(buffer_t *_in_f32_buffer, buffer_t *_in_f64_buffer, buffer_t *_in_i8_buffer, buffer_t *_in_u8_buffer, buffer_t *_in_i16_buffer, buffer_t *_in_u16_buffer, buffer_t *_in_i32_buffer, buffer_t *_in_u32_buffer, buffer_t *_in_i64_buffer, buffer_t *_in_u64_buffer, buffer_t *_out_op_buffer) HALIDE_FUNCTION_ATTRS;
int test_op_argv(void **args) HALIDE_FUNCTION_ATTRS;
extern const struct halide_filter_metadata_t test_op_metadata;

int scalar_test_op(buffer_t *_in_f32_buffer, buffer_t *_in_f64_buffer, buffer_t *_in_i8_buffer, buffer_t *_in_u8_buffer, buffer_t *_in_i16_buffer, buffer_t *_in_u16_buffer, buffer_t *_in_i32_buffer, buffer_t *_in_u32_buffer, buffer_t *_in_i64_buffer, buffer_t *_in_u64_buffer, buffer_t *_out_op_buffer) HALIDE_FUNCTION_ATTRS;
int scalar_test_op_argv(void **args) HALIDE_FUNCTION_ATTRS;
extern const struct halide_filter_metadata_t scalar_test_op_metadata;
#ifdef __cplusplus
}  // extern "C"
#endif

filter filters[] = {
{"test_op", &test_op},
{"scalar_test_op", &scalar_test_op},
{NULL, NULL}};

