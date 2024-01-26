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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x40f3fa0000000000, 0x3ff0000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffb4ff, 0xffffffffffffb4ff};
  __m128i_result = (__m128i){0xc00d060000000000, 0xc110000000000000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0101010101010101, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101000101010001, 0x0000000000020000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffff00ffffff00ff, 0x0000000000fe0000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0101010100000000, 0x0101010100000000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xf9796558e39953fd, 0xd3259a2984048c23};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffe79ffffba5f, 0xffff9727ffff9727};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x01010287010146a1, 0x010169d9010169d9};
  __m128i_out = __lsx_vdiv_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000408, 0x0000000897957687};
  v2u64_op1 = (v2u64){0x8001000184000be0, 0x80010001b57fc565};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000080001fffe};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc1000082b0fb585b, 0xffffffff9cf0d77b};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000ff000000ff, 0x000000ff000000ff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x33f5c2d7d975d7fe};
  __m128i_result = (__m128i){0x0000ff010000ff01, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000fd1654860000, 0x0000feff23560000};
  v2u64_op1 = (v2u64){0x41f8e08016161198, 0x6363636363abdf16};
  __m128i_result = (__m128i){0x0000000000030000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000fffc00000000, 0x00003ff000000000};
  v2u64_op1 = (v2u64){0x7ffe800e80000000, 0x00001ff800000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000200000000};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6a1a3fbb3c90260e, 0x195f307a5d04acbb};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x95e5c045c36fd9f2, 0xe6a0cf86a2fb5345};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000100000000, 0x0000000100000001};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0010000000000001, 0x000fffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x370bdfecffecffec, 0x370bdfecffecffec};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa2e3a36463636363, 0xa2e3a36363636363};
  v2u64_op1 = (v2u64){0x0000000700000007, 0x7f80000000000007};
  __m128i_result = (__m128i){0xf2b2ce330e32c50e, 0x000000000e32c50e};
  __m128i_out = __lsx_vdiv_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffff00000001, 0xffffffff00000001};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x52527d7d52527d7d, 0x52527d7d52527d7d};
  v2u64_op1 = (v2u64){0x52527d7d52527d7d, 0x52527d7d52527d7d};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000001};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x8000000080000000, 0x8000000080000000};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x5237c1bac9eadf55, 0xe93d0bd19ff0c170};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003fffff00000000, 0x003fffff00000000};
  v2u64_op1 = (v2u64){0x00000000003dffc2, 0x00000000003dffc2};
  __m128i_result = (__m128i){0x00000001084314a6, 0x00000001084314a6};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000ffef0010000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0101000001000100, 0x0000010000010101};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4280000042800000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0xbd7fffffbd800000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000000ff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x020310edc003023d, 0x30eb022002101b20};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002000000000, 0x0000002000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000000000004ff};
  __m128i_result = (__m128i){0x0000000000000020, 0x000000000667ae56};
  __m128i_out = __lsx_vdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
