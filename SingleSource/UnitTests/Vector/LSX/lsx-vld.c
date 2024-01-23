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
  __m128i_result = (__m128i){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_out = __lsx_vld((unsigned long *)&v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_out = __lsx_vldx((unsigned long *)&v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0xc3c3c3c3c3c3c3c3, 0xc3c3c3c3c3c3c3c3};
  __m128i_out = __lsx_vldrepl_b((unsigned long *)&v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0xc31ac31ac31ac31a, 0xc31ac31ac31ac31a};
  __m128i_out = __lsx_vldrepl_h((unsigned long *)&v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x47a5c31a47a5c31a, 0x47a5c31a47a5c31a};
  __m128i_out = __lsx_vldrepl_w((unsigned long *)&v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3ab7a3fc47a5c31a, 0x1dcc4255c9d85c05};
  __m128i_result = (__m128i){0x3ab7a3fc47a5c31a, 0x3ab7a3fc47a5c31a};
  __m128i_out = __lsx_vldrepl_d((unsigned long *)&v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
