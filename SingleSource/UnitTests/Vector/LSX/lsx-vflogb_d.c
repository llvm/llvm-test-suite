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

  v2u64_op0 = (v2u64){0x0000000000000002, 0x0000000000000000};
  v2u64_result = (v2u64){0xc090c40000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001000000048, 0xfffffffffffbfffc};
  v2u64_result = (v2u64){0xc090380000000000, 0xfffffffffffbfffc};
  __m128d_out = __lsx_vflogb_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
