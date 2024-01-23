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
  __m128i_result = (__m128i){0x0a0a0a0a0a0a0a0a, 0x0a0a0a0a0a0a0a0a};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, -7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000100010001000, 0x1000100010001000};
  __m128i_result = (__m128i){0x1000100010001000, 0x1000100010001000};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, -10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000003be14000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000003bfb4000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, -5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0b0b0b0b0b0b0b0b, 0x0b0b0b0b0b0b0b0b};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007ffffffb, 0x0000000000000000};
  __m128i_result = (__m128i){0x010101017f010101, 0x0101010101010101};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000007f8, 0x00000000000007f8};
  __m128i_result = (__m128i){0x0b0b0b0b0b0b0b0b, 0x0b0b0b0b0b0b0b0b};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000c, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000000c, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, -7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000100010001};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0606060606060606, 0x0606060606060606};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, 6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0fffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0fffffffffffffff};
  __m128i_out = __lsx_vmaxi_b((__m128)v2u64_op0, -16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x027c027c000027c0, 0x0000000000000000};
  __m128i_result = (__m128i){0x027c027c000027c0, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000001fc00000000, 0x0002000000020000};
  __m128i_result = (__m128i){0x000001fc00000000, 0x0002000000020000};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000fff, 0x0000000000000fff};
  __m128i_result = (__m128i){0x0000000000000fff, 0x0000000000000fff};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000a1ff4c, 0x000000007ff000ff};
  __m128i_result = (__m128i){0x0003000300a10003, 0x000300037ff000ff};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, 3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, -2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000002, 0x0000000000000000};
  __m128i_result = (__m128i){0x000b000b000b000b, 0x000b000b000b000b};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0004000400040004, 0x0004000400040004};
  __m128i_out = __lsx_vmaxi_h((__m128)v2u64_op0, 4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020100fedd0c00, 0xfe07e5fefefdddfe};
  __m128i_result = (__m128i){0x000201000000000b, 0x0000000b0000000b};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0000000001000001};
  __m128i_result = (__m128i){0x0001000100000004, 0x0000000401000001};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, -10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001f0a, 0x000000000000006f};
  __m128i_result = (__m128i){0x0000000000001f0a, 0x000000000000006f};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, -12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000007b};
  __m128i_result = (__m128i){0x0000000500000005, 0x000000050000007b};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000400000004, 0x0000000400000004};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001fffff001fffff, 0x001fffff001fffff};
  __m128i_result = (__m128i){0x001fffff001fffff, 0x001fffff001fffff};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, -7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000b0000000b, 0x0000000b0000000b};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000e0000000e, 0x0000000e0000000e};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000020};
  __m128i_result = (__m128i){0x0000000900000009, 0x0000000900000020};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9c9c9c9c9c9c9c9c, 0x9c9c9c9c9c9c9c9c};
  __m128i_result = (__m128i){0x0000000600000006, 0x0000000600000006};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7f80000000000000};
  __m128i_result = (__m128i){0x0000000700000007, 0x7f80000000000007};
  __m128i_out = __lsx_vmaxi_w((__m128)v2u64_op0, 7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000002, 0x0000000000000002};
  __m128i_out = __lsx_vmaxi_d((__m128)v2u64_op0, 2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001000000, 0x0000000000007f00};
  __m128i_result = (__m128i){0x0000000001000000, 0x0000000000007f00};
  __m128i_out = __lsx_vmaxi_d((__m128)v2u64_op0, -4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffc45a851c40c18, 0xfff489b693120950};
  __m128i_result = (__m128i){0x000000000000000a, 0x000000000000000a};
  __m128i_out = __lsx_vmaxi_d((__m128)v2u64_op0, 10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaxi_d((__m128)v2u64_op0, -5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x41f8e880ffffffff, 0x63636b6afe486741};
  __m128i_result = (__m128i){0x41f8e880ffffffff, 0x63636b6afe486741};
  __m128i_out = __lsx_vmaxi_d((__m128)v2u64_op0, -2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
