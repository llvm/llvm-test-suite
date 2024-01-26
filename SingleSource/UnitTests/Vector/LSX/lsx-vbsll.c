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

  v2u64_op0 = (v2u64){0x00ffffff000000ff, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffff000000ff00, 0x0000000000000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m128i_result = (__m128i){0xff00000000000000, 0xff00ff00ff00ff00};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000800};
  __m128i_result = (__m128i){0x0000000000000000, 0x0008000000000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000a000a000a000a, 0x000a000a000a000a};
  __m128i_result = (__m128i){0x0000000000000000, 0x0a00000000000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0141010101410101, 0x0141010101410101};
  __m128i_result = (__m128i){0x0000000000000000, 0x4101010141010100};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000100000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000158, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000001580000};
  __m128i_out = __lsx_vbsll_v((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
