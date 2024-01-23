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

  v4i32_op0 = (v4i32){0x00000005, 0x00010081, 0x7fff8000, 0x00000000};
  __m128i_result = (__m128i){0x0000010000000100, 0x0000020000000002};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfe02fe02, 0xfe02fe02, 0xfe02fe02, 0xfe02fe02};
  __m128i_result = (__m128i){0x0000000800000008, 0x0000000800000008};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x10001000, 0x10001000, 0x7fff000c, 0x0000000c};
  __m128i_result = (__m128i){0x0000008000000080, 0x0000010000000002};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000020000000200, 0x0000020000000200};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000020000000200, 0x0000020000000200};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x09080706, 0x0a090807, 0x0b0a0908, 0x0c0b0a09};
  __m128i_result = (__m128i){0x0000008000000080, 0x0000008000000080};
  __m128i_out = __lsx_vfclass_s((__m128)v4i32_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
