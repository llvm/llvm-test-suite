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
  __m128i_result = (__m128i){0x0404040404040404, 0x0404040404040404};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001000100, 0x0000000001000100};
  __m128i_result = (__m128i){0x5a5a5a5a5b5a5b5a, 0x5a5a5a5a5b5a5b5a};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0x5a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xe3e3e3e3e3e3e3e3, 0xe3e3e3e3e3e3e3e3};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0xe3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0020002000200020, 0x0000000000000000};
  __m128i_result = (__m128i){0x9aba9aba9aba9aba, 0x9a9a9a9a9a9a9a9a};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0x9a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x9090909090909090, 0x9090909090909090};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0x90);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000077af9450, 0x00000000b81c8382};
  __m128i_result = (__m128i){0xf1f1f1f1865e65a1, 0xf1f1f1f149ed7273};
  __m128i_out = __lsx_vxori_b((__m128)v2u64_op0, 0xf1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
