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

  v4i32_op0 = (v4i32){0x00200001, 0x004200a0, 0x00000000, 0x004200a0};
  v4i32_op1 = (v4i32){0x00200000, 0x004200a0, 0x00000000, 0x004200a0};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00010001, 0x00010001, 0x0001007c, 0x00010001};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x80808080, 0x80808080, 0x80808080, 0x80808080};
  __m128i_result = (__m128i){0x8000800080008000, 0x0000000000000000};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffff0000ffffffff};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffffffc, 0xffffffff, 0xfffffffc, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000103, 0x00000000, 0x00000000, 0x00000001};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcvt_h_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000800000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff29, 0x00000049000000c0};
  v2u64_op1 = (v2u64){0x0000000100000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000002c002400, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x28bf0351ec69b5f2, 0x7ef400ad21fc7081};
  v4i32_result = (v4i32){0x00000000, 0x7f800000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000dc300003ffb, 0x00000dc300003ffb};
  v2u64_op1 = (v2u64){0x7fffffff7fffffff, 0x0000ffff3fbfffff};
  v4i32_result = (v4i32){0x7ffffffb, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa15f3f9e8763c2b9, 0xbba0c07b51230d5c};
  v2u64_op1 = (v2u64){0xa15f3f9e8763c2b9, 0xbba0c07b51230d5c};
  v4i32_result = (v4i32){0x80000000, 0x9d0603db, 0x80000000, 0x9d0603db};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8101010181010101, 0x8101010181010101};
  v4i32_result = (v4i32){0x80000000, 0x80000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffc00000ff800000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v4i32_result = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0xff800000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffdfffe80008000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000ff00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0xffeffff4, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7f8000007f800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x7f800000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000090, 0x0000000000000090};
  v2u64_op1 = (v2u64){0xff70002800be00a0, 0x004eff6200d2ff76};
  v4i32_result = (v4i32){0xff800000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvt_s_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
