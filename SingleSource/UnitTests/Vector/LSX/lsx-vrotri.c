#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0xd915e98e2d8df4d1, 0x0d1bffffffffffff};
  __m128i_result = (__m128i){0x9d519ee8d2d84f1d, 0xd0b1ffffffffffff};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  __m128i_result = (__m128i){0x0800000008000000, 0x0800000008000000};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000006f};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000007b};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000001000000010};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000002000000020};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ff02d060, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ff02d060, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x203e16d116de012b, 0x10f917d72d3d01e4};
  __m128i_result = (__m128i){0x101f8b680b6f8095, 0x887c8beb969e00f2};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000003};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000c00};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffeff400000df4, 0x00000000ffffff01};
  __m128i_result = (__m128i){0xffffe9df0000e81b, 0x00000000ffff03fe};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111113111111121, 0x1111113111111141};
  __m128i_result = (__m128i){0x1111311111112111, 0x1111311111114111};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffff000000000000};
  __m128i_result = (__m128i){0xffff000000000000, 0xffff000000000000};
  __m128i_out = __lsx_vrotri_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000800000008, 0x0000000800000008};
  __m128i_result = (__m128i){0x0002000000020000, 0x0002000000020000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x80001b155b4b0000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x80001b155b4b0000, 0xffffffffffffffff};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0xfffffffffffffffe};
  __m128i_result = (__m128i){0xffffffffffefffff, 0xffffffffffefffff};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffc3ffff003e, 0x0000003f0000ffff};
  __m128i_result = (__m128i){0xffffe1ffff801f7f, 0x00001f80007fff80};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x58d6bf1867ace738, 0x27b9331b8e77ead9};
  __m128i_result = (__m128i){0x5afc6163b39ce19e, 0xe4cc6c9edfab6639};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_w((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  __m128i_result = (__m128i){0x00012b15ffff32ba, 0x000000de00003e14};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x35);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0008000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffff800000003, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff0000ffff0000};
  __m128i_result = (__m128i){0x0000000000000000, 0xfff0000ffff0000f};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x2c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vrotri_d((__m128)v2u64_op0, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
