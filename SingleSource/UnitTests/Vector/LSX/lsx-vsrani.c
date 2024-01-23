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

  v2u64_op0 = (v2u64){0x000201000000000b, 0x0000000b0000000b};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0005000501800005};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000009, 0x0000000000000008};
  v2u64_op1 = (v2u64){0xd705c77a7025c899, 0x697eba2bedfa9c82};
  __m128i_result = (__m128i){0x03fdfffcfefe03fe, 0x00000000ffff0000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x40f0001000000000, 0x40f0001000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x1e0200001e020000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x2020202020207fff, 0x2020202020202020};
  __m128i_result = (__m128i){0x01010101010101ff, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x03f21e0114bf19da, 0x00005dcbe7e830c0};
  v2u64_op1 = (v2u64){0x000014bf000019da, 0x000003f200001e01};
  __m128i_result = (__m128i){0x0000000100010001, 0x0005fe0300010101};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8080636380806363, 0x808080e280808080};
  __m128i_result = (__m128i){0x8080808080638063, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000003020302};
  v2u64_op1 = (v2u64){0xffffffffffffff81, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffffe, 0x00000c0c00000000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0100010000000000, 0x0100000001000100};
  v2u64_op1 = (v2u64){0x00ff00ffffffffff, 0x00ffffff00ff00ff};
  __m128i_result = (__m128i){0xffff00ff00ffffff, 0x0000010001000000};
  __m128i_out = __lsx_vsrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x57cb857100001a46, 0x001ffce00016fb41};
  v2u64_op1 = (v2u64){0x7bffffffffffffff, 0xfbffffffffffffff};
  __m128i_result = (__m128i){0xfffeffff001effff, 0x0000000000150000};
  __m128i_out = __lsx_vsrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x003f000000000000, 0xfff082f000000000};
  __m128i_result = (__m128i){0xffff000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  v2u64_op1 = (v2u64){0x1f54e0ab00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000001f50000, 0xfffffb6d01f5f94f};
  __m128i_out = __lsx_vsrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0800080008000800, 0x0800080008000800};
  __m128i_result = (__m128i){0x0040004000400040, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0f07697100000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000076971000};
  __m128i_out = __lsx_vsrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffc, 0xfffffffffffffffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vsrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x110053f401e7cced, 0x5847b72626ce61ef};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x5847b72626ce61ef};
  __m128i_result = (__m128i){0x0005847b00000000, 0x0005847b00011005};
  __m128i_out = __lsx_vsrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x438ff81ff81ff820};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x03ff03ff03ff03ff};
  __m128i_result = (__m128i){0x0000000000000003, 0x0000000000000043};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x78);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000002020202, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000040000};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v2u64_op1 = (v2u64){0xf0bc9a5278285a4a, 0x62cbf96e4acfaf40};
  __m128i_result = (__m128i){0x62cbf96e4acfaf40, 0x00ff00ff00ff00ff};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x40);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000001d, 0x000000000000001d};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x63);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vsrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x58);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
