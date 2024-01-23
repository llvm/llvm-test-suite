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

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x0, 0x0};
  __lsx_vst((__m128)v2u64_op0, (unsigned long *)&__m128i_result, 0x0);
  check_lsx_out(&v2u64_op0, &__m128i_result, sizeof(__m128i_result), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x0, 0x0};
  __lsx_vstx((__m128)v2u64_op0, (unsigned long *)&__m128i_result, 0x0);
  check_lsx_out(&v2u64_op0, &__m128i_result, sizeof(__m128i_result), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x05, 0x0};
  __m128i_out = (__m128i){0x0, 0x0};
  __lsx_vstelm_b((__m128)v2u64_op0, (unsigned long *)&__m128i_out, 0x0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x5c05, 0x0};
  __m128i_out = (__m128i){0x0, 0x0};
  __lsx_vstelm_h((__m128)v2u64_op0, (unsigned long *)&__m128i_out, 0x0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0xc9d85c05, 0x0};
  __m128i_out = (__m128i){0x0, 0x0};
  __lsx_vstelm_w((__m128)v2u64_op0, (unsigned long *)&__m128i_out, 0x0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x1dcc4255c9d85c05, 0x0};
  __m128i_out = (__m128i){0x0, 0x0};
  __lsx_vstelm_d((__m128)v2u64_op0, (unsigned long *)&__m128i_out, 0x0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
