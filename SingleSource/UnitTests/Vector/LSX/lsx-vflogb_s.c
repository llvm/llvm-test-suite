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

  v4i32_op0 = (v4i32){0x00003004, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xc3080000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0xff800000, 0xff800000, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xffffffff, 0xffffffff, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x01010101, 0x01010101, 0x01010101, 0x01010101};
  v4i32_result = (v4i32){0xc2fa0000, 0xc2fa0000, 0xc2fa0000, 0xc2fa0000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x01ff01ff, 0x01ff01ff, 0x01ff01ff, 0x01ff01ff};
  v4i32_result = (v4i32){0xc2f80000, 0xc2f80000, 0xc2f80000, 0xc2f80000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xd46cdc13, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7fc00000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x000200fe, 0x00fe00fe, 0x000200fe, 0x00fe00fe};
  v4i32_result = (v4i32){0xc3040000, 0xc2fc0000, 0xc3040000, 0xc2fc0000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000100, 0x01010101, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xc30d0000, 0xc2fa0000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000014, 0x00000000, 0x00000014, 0x00000000};
  v4i32_result = (v4i32){0xc3110000, 0xff800000, 0xc3110000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x38bb47d2, 0x4e3e1337, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xc1600000, 0x41e80000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00003ff8, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xc3080000, 0xff800000, 0xff800000, 0xff800000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xf180f1f1, 0xf1f1f1f1, 0xf1f1f1b0, 0xf1f181a2};
  v4i32_result = (v4i32){0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vflogb_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
