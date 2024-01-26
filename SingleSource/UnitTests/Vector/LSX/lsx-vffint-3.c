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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001600000016, 0x0000001600000016};
  v4i32_result = (v4i32){0x41b00000, 0x41b00000, 0x41b00000, 0x41b00000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v4i32_result = (v4i32){0x4f800000, 0x4f800000, 0x4f800000, 0x4f800000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffff0204, 0x0000442800007b50};
  v4i32_result = (v4i32){0x4f7fff02, 0x4f800000, 0x46f6a000, 0x46885000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_wu((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x625a7312befcb21e, 0x8493941335f5cc0c};
  v2u64_result = (v2u64){0x43d8969cc4afbf2d, 0x43e092728266beba};
  __m128d_out = __lsx_vffint_d_lu((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffint_d_lu((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffint_d_lu((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffint_d_lu((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
