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

  v2u64_op0 = (v2u64){0x0000000000020002, 0x0000000000020002};
  __m128i_result = (__m128i){0x0303030303030303, 0x0303030303030303};
  __m128i_out = __lsx_vmaxi_bu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x1111111111111111, 0x1111111111111111};
  __m128i_out = __lsx_vmaxi_bu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x1111111111111111, 0x1111111111111111};
  __m128i_out = __lsx_vmaxi_bu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0a0a0a0a0a0a0a0a, 0x0a0a0a0a0a0a0a0a};
  __m128i_out = __lsx_vmaxi_bu((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0011001100110011, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0f000d200e000c20, 0x11000f2010000e20};
  __m128i_result = (__m128i){0x0f000d200e000c20, 0x11000f2010000e20};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_result = (__m128i){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0005000500050005, 0x0005000500050005};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000020000020, 0x0000000020000020};
  __m128i_result = (__m128i){0x001d001d20000020, 0x001d001d20000020};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00003fff00010000};
  __m128i_result = (__m128i){0x0012001200120012, 0x00123fff00120012};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x001a001a001a001a, 0x001a001a001a001a};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x001e001e001e001e, 0x001e001e001e001e};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x001d001d001d001d, 0x001d001d001d001d};
  __m128i_out = __lsx_vmaxi_hu((__m128)v2u64_op0, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000800000008, 0x0000000800000008};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001600000016, 0x0000001600000016};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  __m128i_result = (__m128i){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x37c0001000000000, 0x37c0001000000000};
  __m128i_result = (__m128i){0x37c0001000000001, 0x37c0001000000001};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010001000100010, 0x0010001000100010};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vmaxi_wu((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xcf00000000000000, 0xbf8000000000ffff};
  __m128i_result = (__m128i){0xcf00000000000000, 0xbf8000000000ffff};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000011, 0x0000000000000011};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000001c, 0x000000000000001c};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000000d, 0x000000000000000d};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000000b, 0x000000000000000b};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x43d3e0000013e000, 0x43d3e0000013e000};
  __m128i_result = (__m128i){0x43d3e0000013e000, 0x43d3e0000013e000};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x000100010001007c};
  __m128i_result = (__m128i){0x0001000100010001, 0x000100010001007c};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000001d, 0x000000000000001d};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000001b, 0x000000000000001b};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000004, 0x0000000000000004};
  __m128i_out = __lsx_vmaxi_du((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
