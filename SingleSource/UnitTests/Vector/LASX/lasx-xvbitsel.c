#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xe9e9e9e9e9e9e9e9, 0x0000000000000000,
                      0xe9e9e9e9e9e9e9e9, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001f001f02c442af, 0x001f001f001f001f,
                      0x001f001f02c442af, 0x001f001f001f001f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00fe01f000000000,
                      0x0000000000000000, 0x00fe01f000000000};
  v4u64_op2 = (v4u64){0xffffffffff295329, 0xfffffffffefefeff,
                      0xffffffffff295329, 0xfffffffffefefeff};
  __m256i_result = (__m256i){0x0000000000c40086, 0x00fe01f000010000,
                             0x0000000000c40086, 0x00fe01f000010000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000505300000000, 0xbe21000100000000,
                      0x0000505300000000, 0xbe21000100000000};
  v4u64_op2 = (v4u64){0xc1d75053f0000000, 0x41dfffffffc00000,
                      0xc1d75053f0000000, 0x41dfffffffc00000};
  __m256i_result = (__m256i){0x00005053000000ff, 0x0001000100000000,
                             0x00005053000000ff, 0x0001000100000000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000040000, 0x0000000000000000,
                      0x0000000000040000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x00000e0000000e00,
                      0xffffffffffffffff, 0x00000e0000000e00};
  __m256i_result = (__m256i){0x0000000000040000, 0x0000000000000000,
                             0x0000000000040000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000000000000, 0x8000000000000000,
                             0x8000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvbitsel_v((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
