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
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0400040004000400, 0x0400040004000400};
  v2u64_result = (v2u64){0x0400040004000400, 0x0400040004000400};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01ff01ff01ff01ff, 0x01ff01ff01ff01ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x01ff01ff01ff01ff, 0x01ff01ff01ff01ff};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  v2u64_result = (v2u64){0x000000000000ffff, 0x0000000000000000};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x6363636363636363};
  v2u64_op1 = (v2u64){0xfdfef9ff0efff900, 0x0000000000000001};
  v2u64_result = (v2u64){0x6363636363636363, 0x6363636363636363};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  v2u64_op1 = (v2u64){0xfffffffffffffff7, 0xfffffffffffffff7};
  v2u64_result = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc3818bffe7b7a7b8, 0x4399d3221a29d3f2};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x4399d3221a29d3f2};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xdb8f439722ec502d, 0x17c64aaef639f093};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x17c64aaef639f093};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ff800000, 0x10f881a20ffd02b0};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x00000000ff800000, 0x10f881a20ffd02b0};
  __m128d_out = __lsx_vfmax_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000c000ffffc000, 0x0000006f00001f0a};
  v2u64_op1 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  v2u64_result = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1748c4f9ed1a5870, 0x8000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmin_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
