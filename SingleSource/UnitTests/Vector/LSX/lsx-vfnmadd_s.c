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

  v4i32_op0 = (v4i32){0xbe6ed565, 0xfffffffe, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x3c90260e, 0x6a1a3fbb, 0x5d04acbb, 0x195f307a};
  v4i32_op2 = (v4i32){0xbe6ed565, 0xfffffffe, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0x3e730941, 0xfffffffe, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xff01ff01, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0xff01ff01, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0x7f01ff01, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  v4i32_op2 = (v4i32){0xff800000, 0x0040007f, 0x003f80b0, 0x00307028};
  v4i32_result = (v4i32){0xffffffff, 0x8040007f, 0xffffffff, 0x80307028};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0x00000001, 0x0000004d, 0x00000049};
  v4i32_op1 = (v4i32){0x00000000, 0x00000001, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000001, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xffffffff, 0x80000001, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00ff0000, 0x00ff0000, 0xffff0000, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000800, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0xfffff800, 0xffffffff};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0xfffff800, 0xffffffff};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00010000, 0x00020000, 0x00010000, 0x00030000};
  v4i32_op1 = (v4i32){0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000};
  v4i32_op2 = (v4i32){0x00010000, 0x00020000, 0x00010000, 0x00030000};
  v4i32_result = (v4i32){0x80020000, 0x80040000, 0x80020000, 0x80060000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000408, 0x00000000, 0x97957687, 0x00000008};
  v4i32_op1 = (v4i32){0x00000408, 0x00000000, 0x97957687, 0x00000008};
  v4i32_op2 = (v4i32){0x04000800, 0x00010001, 0x00010001, 0x00010001};
  v4i32_result = (v4i32){0x84000800, 0x80010001, 0x80010001, 0x80010001};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00010001, 0x0000ffc1, 0x00000007, 0xffc2ffe7};
  v4i32_op1 = (v4i32){0x00010001, 0x0000ffc1, 0x00000007, 0xffc2ffe7};
  v4i32_op2 = (v4i32){0x00000000, 0x00201df0, 0x000ffc2f, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80201df0, 0x800ffc2f, 0xffc2ffe7};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000005, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x80800008, 0x80808080, 0x80808080, 0x80808080};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x31313131, 0x31313131, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x31313131, 0x31313131, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000008, 0x00000000};
  v4i32_result = (v4i32){0xa2f54a1e, 0xa2f54a1e, 0x80000008, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x2e635d65, 0x58bcc201, 0x157ca12e, 0xa486c90f};
  v4i32_op1 = (v4i32){0x79ffa22f, 0x8dc5a4d1, 0xf8760005, 0x6d564875};
  v4i32_op2 = (v4i32){0x5f94ab13, 0x0fa96b88, 0xd2436487, 0xffffffff};
  v4i32_result = (v4i32){0xe8e309ed, 0x2711bad1, 0xd24271c4, 0xffffffff};
  __m128_out = __lsx_vfnmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x01400840, 0x007ffd00, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x01400840, 0x007ffd00, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x7f800000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x80000000, 0x7f800000, 0x80000000, 0x80000000};
  __m128_out = __lsx_vfnmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0xcd636363, 0xcd636363, 0xcd636363, 0xcd636363};
  v4i32_result = (v4i32){0xcd636363, 0xcd636363, 0xcd636363, 0xcd636363};
  __m128_out = __lsx_vfnmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
