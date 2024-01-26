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

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v4i32_result = (v4i32){0xffffe000, 0xffffe000, 0xffffe000, 0xffffe000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000a000a000a000a, 0x000a000a000a000a};
  v4i32_result = (v4i32){0x35200000, 0x35200000, 0x35200000, 0x35200000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf0bc9a5278285a4a, 0x62cbf96e4acfaf40};
  v4i32_result = (v4i32){0x43494000, 0x47050000, 0xbb4a4000, 0xc6178000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff00ff00ff00ff00, 0xff00ff00ff00ff00};
  v4i32_result = (v4i32){0xffe00000, 0xffe00000, 0xffe00000, 0xffe00000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  v4i32_result = (v4i32){0xffffe000, 0xffffe000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvtl_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xff00fe7f, 0x0000017f, 0x0f00fe00, 0x00000100};
  v2u64_result = (v2u64){0xc7e01fcfe0000000, 0x3727f00000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000020, 0x00000020, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x36f0000000000000, 0x36f0000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0a092444, 0x00000000, 0xbd994889, 0xffffffff};
  v2u64_result = (v2u64){0x3941248880000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00040004, 0x00040004, 0x00040004, 0x00040004};
  v2u64_result = (v2u64){0x37c0001000000000, 0x37c0001000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x007f7f7f, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x380fdfdfc0000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvtl_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00e0000000e00000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002a55000001, 0x0000002a55005501};
  v4i32_result = (v4i32){0x42a02000, 0x42a00000, 0x36280000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0282800002828282, 0xffffffffcfb799f1};
  v4i32_result = (v4i32){0xbb3e2000, 0xc1f6e000, 0xffffe000, 0xffffe000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000040004000100, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  v4i32_result = (v4i32){0x3be14000, 0x00000000, 0x36de0000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x41dfffff00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0xffffe000, 0x403be000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x80808080ffffffff, 0xfffffffff7fff7ef};
  v4i32_result = (v4i32){0xc6fde000, 0xc6ffe000, 0xffffe000, 0xffffe000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000400000, 0xffe1ffc100000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0xfff82000, 0xfffc2000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4195d926d8018000, 0x0001001001000080};
  v4i32_result = (v4i32){0x37000000, 0x37800000, 0x35800000, 0x33800000};
  __m128_out = __lsx_vfcvth_s_h((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x2f4ef4a8, 0xf436f3f5, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x63636363, 0x63636363, 0x636316bb, 0x63637687};
  v2u64_result = (v2u64){0x446c62d760000000, 0x446c6ed0e0000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x000000ff, 0x000000ff};
  v2u64_result = (v2u64){0x371fe00000000000, 0x371fe00000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v2u64_result = (v2u64){0xffffffffe0000000, 0xffffffffe0000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000c26a, 0x00004e42, 0x000067da, 0x0000b3a6};
  v2u64_result = (v2u64){0x3789f68000000000, 0x379674c000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffff0000, 0x00000000, 0xffffffff, 0x00000000};
  v2u64_result = (v2u64){0xffffffffe0000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfcvth_d_s((__m128)v4i32_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
