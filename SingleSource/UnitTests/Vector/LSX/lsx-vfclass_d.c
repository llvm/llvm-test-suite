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

  v2u64_op0 = (v2u64){0x0001ffff0001ffff, 0x0001ffff0001ffff};
  __m128i_result = (__m128i){0x0000000000000100, 0x0000000000000100};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000002, 0x0000000000000002};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff00000000000000, 0xff00ff00ff00ff00};
  __m128i_result = (__m128i){0x0000000000000008, 0x0000000000000008};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x685670d37e80682a, 0x14ccc6320176a4d2};
  __m128i_result = (__m128i){0x0000000000000080, 0x0000000000000080};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vfclass_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
