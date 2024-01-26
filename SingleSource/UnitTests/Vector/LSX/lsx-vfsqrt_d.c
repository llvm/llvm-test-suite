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

  v2u64_op0 = (v2u64){0x0000000058bcc201, 0xffffffffa486c90f};
  v2u64_result = (v2u64){0x1f52d710bf295626, 0xffffffffa486c90f};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff01ff01, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffff01ff01, 0xffffffffffffffff};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000be00be, 0x0000000000000000};
  v2u64_result = (v2u64){0x1f1b917c9f3d5e05, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001400000000, 0xffffffff00000000};
  v2u64_result = (v2u64){0x1f81e3779b97f4a8, 0xffffffff00000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  v2u64_result = (v2u64){0x7ff8000000000000, 0x7ff8000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001effae001effae, 0x001effae001effae};
  v2u64_result = (v2u64){0x2006454690d3de87, 0x2006454690d3de87};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  v2u64_result = (v2u64){0x7ff8000000000000, 0x7ff8000000000000};
  __m128d_out = __lsx_vfsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff8000000000000, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x7ff8000000000000, 0xffffffffffffffff};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00003f8000000000, 0x00003f8000000000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffa0000, 0x00000000fffa0000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe593c8c4e593c8c4, 0xff800000ff800000};
  v2u64_result = (v2u64){0x9a49e11102834d70, 0x805ffffe01001fe0};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5252dcdcdcdcdcdc, 0x5252525252525252};
  v2u64_result = (v2u64){0x2d8b24b936d1b24d, 0x2d8bf1f8fc7e3f20};
  __m128d_out = __lsx_vfrecip_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff800000ff800000, 0xffffffffffffffff};
  v2u64_result = (v2u64){0x7ff8000000000000, 0xffffffffffffffff};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001ffff0001ffff, 0x0001ffff00000000};
  v2u64_result = (v2u64){0x5ff6a0a40e9da42a, 0x5ff6a0a40ea8f47c};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000f, 0x0000000000000000};
  v2u64_result = (v2u64){0x61608654a2d4f6da, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff0000ffff0000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0xffff0000ffff0000};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7fff7fff7fff, 0x00fe000100cf005f};
  v2u64_result = (v2u64){0x7fff7fff7fff7fff, 0x5f675e96e29a5a60};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128d_out = __lsx_vfrsqrt_d((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
