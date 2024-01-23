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

  v2u64_op0 = (v2u64){0x00000000ffff0000, 0x00000000ffff0000};
  __m128i_result = (__m128i){0xcccccccc0000cccc, 0xcccccccc0000cccc};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0x33);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0xa6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3e035e51522f0799, 0x0000000000000000};
  __m128i_result = (__m128i){0x8090808280909002, 0x9292929292929292};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0x6d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00201df000000000, 0x00000000000ffc2f};
  __m128i_result = (__m128i){0x3818200838383838, 0x3838383838300010};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0xc7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x2020202020207f7f, 0x2020202020202020};
  __m128i_result = (__m128i){0x5d5d5d5d5d5d0000, 0x5d5d5d5d5d5d5d5d};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0xa2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8080808080808080, 0x8080808080808080};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0x7f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0x1313131313131313, 0x1313131313131313};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0xec);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x9d9d9d9d9d9d9d9d, 0x9d9d9d9d9d9d9d9d};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0x62);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00365c60317ff930, 0x00f525682ffd27f2};
  __m128i_result = (__m128i){0xe5c1a185c48004c5, 0xe500c085c000c005};
  __m128i_out = __lsx_vnori_b((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
