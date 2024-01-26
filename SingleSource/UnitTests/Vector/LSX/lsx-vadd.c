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
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000201000000000b, 0x0000000b0000000b};
  v2u64_op1 = (v2u64){0x0000000000fc0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0002010000fc000b, 0x0000000b0000000b};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000017fda829, 0x0000000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000001fffe, 0xffffffffffff0000};
  v2u64_op1 = (v2u64){0x7f0000fd7f0000fd, 0x7f7f7f7f00107f04};
  __m128i_result = (__m128i){0x7f0000fd7f01fffb, 0x7e7e7e7eff0f7f04};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf4b6f3f52f4ef4a8, 0x0080000000000000};
  v2u64_op1 = (v2u64){0x6a1a3fbb3c90260e, 0x195f307a5d04acbb};
  __m128i_result = (__m128i){0x5ed032b06bde1ab6, 0x19df307a5d04acbb};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffabbeab55110140, 0x5555001400005111};
  v2u64_op1 = (v2u64){0xffabbeab55110140, 0x5555001400005111};
  __m128i_result = (__m128i){0xfe567c56aa220280, 0xaaaa00280000a222};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0982e2daf234ed87, 0xf51cf8dad6040188};
  __m128i_result = (__m128i){0x0982e2daf234ed87, 0xf51cf8dad6040188};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001ffffffff, 0x000000490000004d};
  v2u64_op1 = (v2u64){0x000000000000002a, 0x0000000000000073};
  __m128i_result = (__m128i){0x00000001ffffff29, 0x00000049000000c0};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fff0000, 0x000000000000bd3d};
  v2u64_op1 = (v2u64){0x0000000d7fff0000, 0x000000000000bd30};
  __m128i_result = (__m128i){0x0000000dfefe0000, 0x0000000000007a6d};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xfffd000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffd000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xfefa000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfefefefefefefefe, 0xfefefefefefefefe};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003c000000022021, 0x0038000000051fff};
  v2u64_op1 = (v2u64){0x7fffffffa0204000, 0x7fff0101ffffe000};
  __m128i_result = (__m128i){0x7f3bffffa0226021, 0x7f370101ff04ffff};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1c2640b9a8e9fb49, 0x1baf8eabd26bc629};
  v2u64_op1 = (v2u64){0x00036dd1c5c15856, 0x0002dab8746acf8e};
  __m128i_result = (__m128i){0x1c29ad8a6daa539f, 0x1bb1686346d595b7};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000003, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfeffffffffffffff, 0xfeffffffffffffff};
  __m128i_result = (__m128i){0xfeffffffffff0002, 0xfeffffffffffffff};
  __m128i_out = __lsx_vadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000008};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000008};
  __m128i_out = __lsx_vadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001ffff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff800000c3080000, 0xff800000ff800000};
  __m128i_result = (__m128i){0xff81ffffc3080000, 0xff800000ff800000};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x004200a000200001, 0x004200a000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x004200a000200001, 0x004200a000000000};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000001f0000001f, 0x0000001f0000001f};
  __m128i_result = (__m128i){0x0000001f0000001f, 0x0000001f0000001f};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ff00ff00ff00ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00ff00ff00ff00ff, 0x0000000000000000};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xdbe332365392c686, 0x0029aeaca57d74e6};
  v2u64_op1 = (v2u64){0x29ca096f235819c2, 0x000056f64adb9464};
  __m128i_result = (__m128i){0x05ad3ba576eae048, 0x002a05a2f059094a};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000000};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000400, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000040d, 0x0000000000000000};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001300000013, 0x0000001300000013};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001300000013, 0x0000001300000013};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000100, 0x0000000100000100};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000001000000ff, 0x0000000100000100};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100010001, 0x0000000300000001};
  v2u64_op1 = (v2u64){0xfffffffffffffffa, 0xfffffffffffffffa};
  __m128i_result = (__m128i){0x000000010000fffb, 0x00000002fffffffb};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001201fe01e9, 0x000000060000000e};
  v2u64_op1 = (v2u64){0x0000001201fe01e9, 0x000000060000000e};
  __m128i_result = (__m128i){0x0000002403fc03d2, 0x0000000c0000001c};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128i_result = (__m128i){0xfff1000100010001, 0xfff1000100010001};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  __m128i_result = (__m128i){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffffffffffffffa, 0xfffffffffffffffa};
  __m128i_result = (__m128i){0xfffffffffffffffa, 0xfffffffffffffffa};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0001001100110068};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0001001100110067};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3789f68000000000, 0x379674c000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x3789f68000000000, 0x379674c000000000};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000002580f01, 0x0000000000555889};
  v2u64_op1 = (v2u64){0x00020fbf02000fbf, 0x00060fbf02040fbf};
  __m128i_result = (__m128i){0x00020fbf04581ec0, 0x00060fbf02596848};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x006938094a013889, 0x0001388928513889};
  v2u64_op1 = (v2u64){0x006938094a013889, 0x0001388928513889};
  __m128i_result = (__m128i){0x00d2701294027112, 0x0002711250a27112};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001effae001effae, 0x001effae001effae};
  v2u64_op1 = (v2u64){0x2006454690d3de87, 0x2006454690d3de87};
  __m128i_result = (__m128i){0x202544f490f2de35, 0x202544f490f2de35};
  __m128i_out = __lsx_vadd_q((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
