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

  v4u64_op0 = (v4u64){0x00ffffffffffffff, 0xffffffffffffffff,
                      0x00ffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x00ffffffffffffff, 0xffffffffffffffff,
                      0x00ffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000010000000, 0x0000000010000000,
                             0x0000000010000000, 0x0000000010000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0010000f0000000f, 0x0020000f0000000f,
                      0x0010000f0000000f, 0x0020000f0000000f};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000fe010000fe01, 0xde00fe0000000000,
                      0x0000fe010000fe01, 0xde00fe0000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xfc00000000000000,
                             0x0000000000000000, 0xfc00000000000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7000700070007000, 0x0000000070007000,
                      0x7000700070007000, 0x7000700070007000};
  v4u64_op1 = (v4u64){0x0000000000000008, 0x0000000000000008,
                      0x0000000000000008, 0x0000000000000008};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000e0e0e0e0e0e,
                             0x0000000000000000, 0x0e0e0e0e0e0e0e0e};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000040000001b, 0x0000000100000008,
                      0x000000040000001b, 0x0000000100000008};
  v4u64_op1 = (v4u64){0xff00000000000000, 0xff00000000000000,
                      0xff00000000000000, 0xff00000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffff00ff800000, 0x41dffbffffffffff,
                      0xffffff00ff800000, 0x41dffbffffffffff};
  __m256i_result = (__m256i){0x7f80ffffff808000, 0x0000000000000000,
                             0x7f80ffffff808000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0a09080706050403,
                      0x0000000000000000, 0x0a09080706050403};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0003000200000000,
                             0x0000000000000000, 0x0003000200000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x8000000080000000, 0x0000000000000000,
                             0x8000000080000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                      0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000ff0fff0fff0f,
                             0x0000000000000000, 0x0000ff0fff0fff0f};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000001e00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0002000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000800,
                      0x0000000000000800, 0x0000000000000800};
  v4u64_op1 = (v4u64){0x00000000000009f0, 0x0000000000000000,
                      0x0000000000000f20, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00001f41ffffbf00,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000400000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000fffff6ff,
                      0x0000000000000000, 0x00000000fffff6ff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x28);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000077843,
                      0x0000000000000000, 0x0000000df93f0000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000003800000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000120e120d, 0x0000000000000000,
                      0x00000000120e120d, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000907,
                             0x0000000000000000, 0x0000000000000907};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x32);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010002000100020, 0x0010002000100020,
                      0x0010002000100020, 0x0010002000100020};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000fffffffe, 0x0000000000000000,
                             0x00000000fffffffe, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00030081bd80f90e, 0x0000000000000000,
                      0x00030006fa05f20e, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000018,
                             0x0000000000000000, 0x0000000000000018};
  __m256i_out = __lasx_xvssrarni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000f0000000f, 0x0000002000000020,
                      0x0000000f0000000f, 0x0000002000000020};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000000,
                             0x0000000000000100, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf5f0bfb8f5d8bfe8, 0xf5f5bfbaf5f5bfbe,
                      0xf5f0bfb8f5d8bfe8, 0xf5f5bfbaf5f5bfbe};
  v4u64_op1 = (v4u64){0xf5f0bfb8f5d8bfe8, 0xf5f5bfbaf5f5bfbe,
                      0xf5f0bfb8f5d8bfe8, 0xf5f5bfbaf5f5bfbe};
  __m256i_result = (__m256i){0xffffffffffff5f5c, 0xffffffffffff5f5c,
                             0xffffffffffff5f5c, 0xffffffffffff5f5c};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010000, 0xffffffffffff0000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x30);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x333568ce26dcd055, 0x00150015003a402f,
                      0x333568ce26dcd055, 0x00150015003a402f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000007d0d0d0,
                      0x0000000000000000, 0x0000000007d0d0d0};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000100000000,
                      0x0000000100000000, 0x0000000100000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fffffffffffffff,
                             0x0000000000000000, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffe00000002, 0xfffffffe00000002,
                      0xfffffffe00000002, 0xfffffffe00000002};
  __m256i_result = (__m256i){0xffffffffffffe000, 0x0000000000000000,
                             0xffffffffffffe000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x54);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000100010001ffff, 0x000100010001ffff,
                      0x000100010001ffff, 0x000100010001ffff};
  v4u64_op1 = (v4u64){0x00007ff000000000, 0x0000000000000000,
                      0x00007ff000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x79);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0001fffe00018069, 0x0001fffe0001fffa,
                      0x0001fffe00018069, 0x0001fffe0001fffa};
  __m256i_result = (__m256i){0x0000000000002000, 0x0000000000000000,
                             0x0000000000002000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x64);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000013, 0x0000000000000013,
                      0x0000000000000013, 0x0000000000000013};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x36);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000700020033, 0x0000000500020002,
                      0x0000000700020033, 0x0000000500020002};
  v4u64_op1 = (v4u64){0x0000000700020033, 0x0000000500020002,
                      0x0000000700020033, 0x0000000500020002};
  __m256i_result = (__m256i){0x1400080008000000, 0x1400080008000000,
                             0x1400080008000000, 0x1400080008000000};
  __m256i_out = __lasx_xvssrarni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x26);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0001010300010102, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000410041};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0016001600160016, 0x0016001600160016,
                      0x0016001600160016, 0x0016001600160016};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8848c848c848c848, 0xc848c848c848c848,
                      0x8848c848c848c848, 0xc848c848c848c848};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000004000000020,
                             0x0000000000000000, 0x0000004000000020};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fff7fff7fff7fff, 0x0000038000000268,
                      0x7fff7fff7fff7fff, 0x0000038000000268};
  __m256i_result = (__m256i){0x0000000001010101, 0x0000000000000000,
                             0x0000000001010101, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x000000000000ffff};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x2000200020002000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8001b72eaf12d5f0, 0x000247639d9cb530,
                      0x8001b72eaf12d5f0, 0x8001b72e0001b72e};
  v4u64_op1 = (v4u64){0xffffffffffceba70, 0x0000000000000000,
                      0xffffffffe056fd9d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0001000000000000,
                             0x0000000000000000, 0x0000000100000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xf7f7f7f7f7f7f7f7,
                      0x0000000000000000, 0xf7f7f7f7f7f7f7f7};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xa1a1a1a1a1a15e5e, 0x0000000000000000,
                      0xa1a1a1a1a1a15e5e, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0xffffffffffffffff,
                      0x8000000080000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x4980008068400000, 0x498000804843ffe0,
                      0x4980008068400000, 0x498000804843ffe0};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x005500550055ffab, 0x005500550055ffab,
                      0x005500550055ffab, 0x005500550055ffab};
  v4u64_op1 = (v4u64){0x005500550055ffab, 0x005500550055ffab,
                      0x005500550055ffab, 0x005500550055ffab};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x8000000000008000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0d0cf2f30d0cf2f3, 0x02407a3c00000000,
                      0x0d0cf2f30d0cf2f3, 0x02407a3c00000000};
  v4u64_op1 = (v4u64){0xefdfefdfefdfefdf, 0xefdfefdf00000000,
                      0xefdfefdfefdfefdf, 0xefdfefdf00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffe1ffe0ffe1ffe0, 0x01ff0020ff1f001f,
                      0xffe1ffe0ffe1ffe0, 0x01ff0020ff1f001f};
  __m256i_result = (__m256i){0x00003fe000000000, 0x0000000000000000,
                             0x00003fe000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00e9a80014ff0000, 0x00b213171dff0606,
                      0x00e9a80014ff0000, 0x00b213171dff0606};
  v4u64_op1 = (v4u64){0xff00000000ffffff, 0xff00000000000000,
                      0xff00000000ffffff, 0xff00000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000400, 0x0400000004000000,
                             0x0000000000000400, 0x0400000004000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0080000000000002,
                      0x000000000000ffff, 0x0080000000000002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x08000000000000f8,
                      0x0000000000000000, 0x08000000000000f8};
  __m256i_result = (__m256i){0x2000000000000000, 0x0200000000000000,
                             0x2000000000000000, 0x0200000000000000};
  __m256i_out = __lasx_xvssrarni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfffffffffffffc00,
                      0xfffffffffffffc00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffffffffffffc00,
                      0xfffffffffffffc00, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000020000000, 0x0000000020000000};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000000000000000,
                      0x0000ffff0000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x73);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000040000ff79, 0x0000000800000098,
                      0x000000040000ffca, 0x0000000800000098};
  v4u64_op1 = (v4u64){0xff04ff00ff00ff00, 0xff00ff00ff00ff00,
                      0xff04ff00ff00ff00, 0xff00ff00ff00ff00};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000008000000a,
                             0x0000000000000000, 0x000000008000000a};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x44);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff000000ff, 0x000000ff000000ff,
                      0x000000ff000000ff, 0x000000ff000000ff};
  v4u64_op1 = (v4u64){0xfffffffffff70156, 0xfffffffffff70156,
                      0xfffffffffff70156, 0xfffffffffff70156};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x74);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x45);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000001de, 0x000000000000001c,
                      0x00000000000001de, 0x000000000000001c};
  v4u64_op1 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_result = (__m256i){0x0000000060000000, 0x0000000000000002,
                             0x0000000060000000, 0x0000000000000002};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x44);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fe900140d85, 0x00003fea0014734d,
                      0x00003fe900140d85, 0x00003fea0014734d};
  v4u64_op1 = (v4u64){0x000000ff0000ff00, 0x000000ff000000ff,
                      0x000000ff0000ff00, 0x000000ff000000ff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrarni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
