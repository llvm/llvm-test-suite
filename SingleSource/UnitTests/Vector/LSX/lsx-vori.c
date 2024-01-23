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
  __m128i_result = (__m128i){0x8282828282828282, 0x8282828282828282};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x82);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01010000fefe0101, 0x7505853d654185f5};
  __m128i_result = (__m128i){0x41414040fefe4141, 0x7545c57d6541c5f5};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x40);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000c2fa8000c2fa, 0x0000c2f90000bafa};
  __m128i_result = (__m128i){0xf474f6fef474f6fe, 0x7474f6fd7474fefe};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x74);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x3d3d3d3d3d3d3d3d, 0x3d3d3d3d3d3d3d3d};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x3d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  __m128i_result = (__m128i){0x5f5f7bfedefb5ada, 0xfffffadffedbfefe};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x5a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xea38e0f75f6e56d1, 0x0d1202e19235e2bc};
  __m128i_result = (__m128i){0xee3ee6f77f6e76f7, 0x2f3626e7b637e6be};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x26);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003c853c843c87e, 0x0003c853c843c87e};
  __m128i_result = (__m128i){0xd6d7ded7ded7defe, 0xd6d7ded7ded7defe};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0xd6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffe0000fffe0000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffff7777ffff7777, 0x7777777777777777};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x77);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x55);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128i_result = (__m128i){0xd454545454545454, 0xd454545454545454};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x54);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x4f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8a8a8a8a8a8a8a8a, 0x8a8a8a8a8a8a8a8a};
  __m128i_out = __lsx_vori_b((__m128)v2u64_op0, 0x8a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
