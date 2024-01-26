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
  v2u64_op1 = (v2u64){0xc77c47cdc0f16549, 0x8a228acac14e440a};
  v2u64_op2 = (v2u64){0x2711bad1e8e309ed, 0xffffffffd24271c4};
  v2u64_result = (v2u64){0x2711bad1e8e309ed, 0xffffffffd24271c4};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffe000ffff1fff, 0x0000040400000383};
  v2u64_op1 = (v2u64){0xffffe000ffff1fff, 0x0000040400000383};
  v2u64_op2 = (v2u64){0x0001000100000000, 0x0000000001000001};
  v2u64_result = (v2u64){0xffffe000ffff1fff, 0x0000000001000001};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ff800000, 0x00000000003f80b0};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080200000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000401000};
  v2u64_op2 = (v2u64){0x0000080000000000, 0x0000080000000000};
  v2u64_result = (v2u64){0x0000080000000000, 0x0000080000000000};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000001e, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7fff7fff7fff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x3fff3fff3fff3fff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xfff8000000000000, 0xfffb00fdfdf7ffff};
  v2u64_result = (v2u64){0xfff8000000000000, 0xfffb00fdfdf7ffff};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000000000000, 0x8000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000009000900, 0x0000000009000900};
  v2u64_result = (v2u64){0x0000000009000900, 0x0000000009000900};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xdd3b8b02563b2d7b, 0x9c83e21a22001818};
  v2u64_op1 = (v2u64){0x7f7f7f007f7f7f00, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x7f7f7f007f7f7f00, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff01e41ffff0ffff, 0xff00e400ff00e400};
  v2u64_op1 = (v2u64){0x5555000154100155, 0x5555000054100000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vfmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000010, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000010, 0x0000000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe00fcfffe01fd01, 0xfc01fcfefc02fdf7};
  v2u64_op1 = (v2u64){0xfe00fd1400010000, 0xfc01fd1300000001};
  v2u64_op2 = (v2u64){0xfe00fcfffe01fd01, 0xfc01fcfefc02fdf7};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000bd3d00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00fffe00fffffe00, 0x0038d800ff000000};
  v2u64_op2 = (v2u64){0x8080800000800080, 0x8000008000008080};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x0000008000008080};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ff80ff00ff80ff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000900000009, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000007ff000ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffffffe, 0xffffff7ffffffffe};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0xffffff7ffffffffe};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  v2u64_op2 = (v2u64){0x0000000000000103, 0x0000000100000000};
  v2u64_result = (v2u64){0x8000000000000103, 0x8000000100000000};
  __m128d_out = __lsx_vfmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
