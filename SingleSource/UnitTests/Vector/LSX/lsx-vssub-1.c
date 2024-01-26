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
  v2u64_op1 = (v2u64){0x0000002000000020, 0x0000002000000020};
  __m128i_result = (__m128i){0xffffffdfffffffe0, 0xffffffdfffffffe0};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000c2f90000bafa, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8000c2fa8000c2fa, 0x0000c2f90000bafa};
  __m128i_result = (__m128i){0x7ffffffe7ffff800, 0xffff3d06ffff4506};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffff3fffffff3, 0xfffffff3fffffff3};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffff3fffffff4, 0xfffffff3fffffff4};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7ef8000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8108000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffaa076aeb, 0x0000000063b2ac27};
  v2u64_op1 = (v2u64){0xffff0001ffff9515, 0x00000000ffff53d9};
  __m128i_result = (__m128i){0x0000fffdaa07d5d6, 0xffffffff63b3584e};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffff81, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000005, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffff7c, 0xffffffffffffffff};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff7cffd6ffc700b0, 0x0000000000000000};
  __m128i_result = (__m128i){0x008300290038ff50, 0x0000000000000000};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000c0dec4d1, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffff3f213b2f, 0x0000000000000000};
  __m128i_out = __lsx_vssub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
