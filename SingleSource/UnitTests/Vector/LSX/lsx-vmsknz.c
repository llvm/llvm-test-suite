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

  v2u64_op0 = (v2u64){0x0000000210011084, 0x000000017fff9000};
  __m128i_result = (__m128i){0x0000000000001e1f, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9c9c9c9c63636363, 0x9c9c9c9c9c9c9c9c};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x009500b10113009c, 0x009500b10113009c};
  __m128i_result = (__m128i){0x0000000000005d5d, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffff000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000000000fe, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010000000000001, 0x000fffffffffffff};
  __m128i_result = (__m128i){0x0000000000007f41, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0014001400140000, 0x0000000000ff00ff};
  __m128i_result = (__m128i){0x0000000000000554, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x202544f490f2de35, 0x202544f490f2de35};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6adeb5dfcb000000, 0x00000a74aa8a55ab};
  __m128i_result = (__m128i){0x0000000000003ff8, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x317fce80317fce80};
  __m128i_result = (__m128i){0x000000000000ff00, 0x0000000000000000};
  __m128i_out = __lsx_vmsknz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
