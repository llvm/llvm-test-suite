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

  v4i32_op0 = (v4i32){0xfedd0c00, 0x00020100, 0xfefdddfe, 0xfe07e5fe};
  v4i32_result = (v4i32){0x7fc00000, 0x1e801ffc, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xff00ff00, 0xff00ff00, 0xff00ff00, 0xff00ff00};
  v4i32_result = (v4i32){0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x76208329, 0xbc84cf6f, 0x137e54af, 0x8c7fc73a};
  v4i32_result = (v4i32){0x5acab5a5, 0x7fc00000, 0x297f29fe, 0x7fc00000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffba5f, 0xfffffe79, 0xffff9727, 0xffff9727};
  v4i32_result = (v4i32){0xffffba5f, 0xfffffe79, 0xffff9727, 0xffff9727};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000003, 0x00000003, 0x00000002, 0x00000002};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x51cfd7c0, 0x00000000, 0xf6e91c00};
  v4i32_result = (v4i32){0x7f800000, 0x2d1da85b, 0x7f800000, 0x880c91b8};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffffffa, 0xfffffffa, 0xfffffffa, 0xfffffffa};
  v4i32_result = (v4i32){0xfffffffa, 0xfffffffa, 0xfffffffa, 0xfffffffa};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffff0001, 0xffff0001, 0xffff0001, 0xffff0001};
  v4i32_result = (v4i32){0xffff0001, 0xffff0001, 0xffff0001, 0xffff0001};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0a000000, 0x0a000000, 0x0a000000, 0x0a000000};
  v4i32_result = (v4i32){0x75000000, 0x75000000, 0x75000000, 0x75000000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrecip_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfff80000, 0x00000000, 0xfff8fff8, 0x00000000};
  v4i32_result = (v4i32){0xfff80000, 0x7f800000, 0xfff8fff8, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x9f3d5e05, 0x1f1b917c, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7fc00000, 0x4fa432d6, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xb880eb98, 0x12835580, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0x7fc00000, 0x55fcbad1, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x03e8157e, 0x0707f8f8, 0x00000807, 0x06070607};
  v4i32_result = (v4i32){0x5d3e1e1d, 0x5bafa1dd, 0x61ff9049, 0x5c303f97};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffe01ff, 0xfffbfffe, 0xfffa01ff, 0xfff7fffe};
  v4i32_result = (v4i32){0xfffe01ff, 0xfffbfffe, 0xfffa01ff, 0xfff7fffe};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x44000000, 0x00000000, 0x45000000};
  v4i32_result = (v4i32){0x7f800000, 0x3d3504f3, 0x7f800000, 0x3cb504f3};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00020002, 0x00020001, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x607fff80, 0x607fffc0, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfrsqrt_s((__m128)v4i32_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
