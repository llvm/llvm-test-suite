#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2, v2u64_result;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2, v4i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000800000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000800000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3918371635143312, 0x01203f1e3d1c3b1a};
  v2u64_op1 = (v2u64){0x00000af555555555, 0x00000af555555555};
  v2u64_result = (v2u64){0x3918371635143312, 0x01203f1e3d1c3b1a};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000010000000000, 0x0000010000000000};
  v2u64_op1 = (v2u64){0x0000010000000000, 0x0000010000000000};
  v2u64_result = (v2u64){0x0000010000000000, 0x0000010000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x10f8000000000000};
  v2u64_op1 = (v2u64){0x00000000ff800000, 0xfff8ffa2fffdffb0};
  v2u64_result = (v2u64){0x00000000ff800000, 0x10f8000000000000};
  __m128d_out = __lsx_vfmaxa_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000200000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000200000000};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000080000000, 0x0000000100000000};
  v2u64_op1 = (v2u64){0x80000000fff6fc00, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000080000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000080000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000158};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xfffe0004fffe0004, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x002a001a001a000b};
  v2u64_result = (v2u64){0x0000000000000000, 0x002a001a001a000b};
  __m128d_out = __lsx_vfmina_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
