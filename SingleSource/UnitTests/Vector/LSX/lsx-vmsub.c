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
  v2u64_op1 = (v2u64){0xfeffffffffff0002, 0xfeffffffffffffff};
  v2u64_op2 = (v2u64){0x8024d8f6a494afcb, 0x54beed87bc3f2be1};
  __m128i_result = (__m128i){0x0024d8f6a494006a, 0xa8beed87bc3f2be1};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0001000100000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff000000ff0000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffffffffffff800};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00ff000000ff0000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001400000000, 0x0000001400000014};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000053a4f452, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001400000000, 0x0000001400000014};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa1e7b475d925730f, 0xb327b9363c99d32e};
  v2u64_op1 = (v2u64){0x00000000ff800000, 0x00000000003f80b0};
  v2u64_op2 = (v2u64){0x00007f8000007f80, 0x00007f8000007f80};
  __m128i_result = (__m128i){0xa1e7b475d925730f, 0xb327b9363c992b2e};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0x0000000000000000, 0x7ffe7ffe7ffe7ffe};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffc3ffff003e, 0x0000003f0000ffff};
  v2u64_op2 = (v2u64){0xffffffc3ffff003e, 0x0000003f0000ffff};
  __m128i_result = (__m128i){0xfffff177fffff0fc, 0x0000f07f0000ffff};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000010000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000010000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000010000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x002584710016cc56, 0x0021b761002c593c};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000001e03, 0x0000000000000000};
  __m128i_result = (__m128i){0x002584710016ea59, 0x0021b761002c593c};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000290, 0x0000000000000290};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ffff0000ffff, 0x0000ffff00000000};
  v2u64_op2 = (v2u64){0x0000ffff0000ffff, 0x0000ffff00000000};
  __m128i_result = (__m128i){0x0001ffff0001ffff, 0x0001ffff00000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000200010, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xfffffff0ffe04000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000001fc0000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000200010, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000200010, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x040004000400040d, 0x0400040004000400};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x040004000400040d, 0x0400040004000400};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc7e01fcfe0000000, 0x3727f00000000000};
  v2u64_op1 = (v2u64){0x39201f7120000040, 0x3727112c00000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x00007fff00007fff};
  __m128i_result = (__m128i){0xc7e01fcfe0000000, 0xe5b9012c00000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffff0204, 0xffffffff00000004};
  v2u64_op1 = (v2u64){0x0000e22b0000efa4, 0x0000442900007b4c};
  v2u64_op2 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffff0204, 0x0000442800007b50};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffefffffffe, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000029, 0x000000000000002f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x003dbe88077c78c1, 0x0000000000003a24};
  __m128i_result = (__m128i){0x0000000000000029, 0x000000000000002f};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x7fff7fff7fff7fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8f8f8f8f8f8f8f8f, 0x8f8f8f8f8f8f8f8f};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff913bfffffffd, 0x00680486ffffffda};
  v2u64_op1 = (v2u64){0xffff913bfffffffd, 0x00680486ffffffda};
  v2u64_op2 = (v2u64){0x000000003ddc5dac, 0x0000000000000000};
  __m128i_result = (__m128i){0xffff913bb9951901, 0x00680486ffffffda};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000001f0000001f, 0x0000002000000020};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0000000100000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x0002000400000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0003000500000001, 0x0000000100000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0004000400040004, 0x0004000400040004};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0004000400040004, 0x0004000400040004};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xfe03fe3ffe01fa21, 0xfe3bfb01fe3bfe01};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000fc0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000200020002, 0x0002000200020002};
  v2u64_op1 = (v2u64){0x000a000a000a000a, 0x000a000a000a000a};
  v2u64_op2 = (v2u64){0xe0c0c0c0d1c7d1c6, 0x000000004c7f4c7f};
  __m128i_result = (__m128i){0x4d6814ef9c77ce46, 0x061006100613030c};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000002bfd9461, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x00000000ffffff00, 0x0000000000000f00};
  __m128i_result = (__m128i){0x000000002bfd9461, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f8000007f800000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7f8000007f800000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xff0000007f800000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0fff0fff0fff0fff, 0x0fff0fff0fff0fff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0fff0fff0fff0fff, 0x0fff0fff0fff0fff};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffbfffefffc9510, 0xfffbfffefffc9510};
  v2u64_op1 = (v2u64){0x0a09080709080706, 0x0c0b0a090b0a0908};
  v2u64_op2 = (v2u64){0xfffbfffefffc9510, 0xfffbfffefffc9510};
  __m128i_result = (__m128i){0x62fb9272df7da6b0, 0x29c251319c3a5c90};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x800000007fffffff, 0x800000007fffffff};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x59f7fd8759f7fd87, 0x0000001700000017};
  v2u64_op1 = (v2u64){0x001effae001effae, 0x0000ffae001effae};
  v2u64_op2 = (v2u64){0x59f7fd8759f7fd87, 0x0000001700000017};
  __m128i_result = (__m128i){0x96198318780e32c5, 0xfd200ed2fd370775};
  __m128i_out = __lsx_vmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
