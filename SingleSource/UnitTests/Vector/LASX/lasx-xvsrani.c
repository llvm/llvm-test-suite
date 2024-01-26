#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0xc5c545c545c545c5, 0xc5c4c5c5c5c5c5c5,
                      0xc5c545c545c545c5, 0xc5c4c5c5c5c5c5c5};
  v4u64_op1 = (v4u64){0xbc8ff0ffffffcff8, 0x000000ff000000f8,
                      0xbc8ff0ffffffcff8, 0x000000ff000000f8};
  __m256i_result = (__m256i){0x00000000fbfffffc, 0xfcfcfcfcfc040404,
                             0x00000000fbfffffc, 0xfcfcfcfcfc040404};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0c0b0a0908070605, 0x14131211100f0e0d,
                      0x0c0b0a0908070605, 0x14131211100f0e0d};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0a09080706050403,
                             0x0000000000000000, 0x0a09080706050403};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffefefffffefe, 0x0000000000000000,
                      0xfffffefefffffefe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fffffefd, 0x00000000ffffffff,
                      0x00000000fffffefd, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x00000000ffffffff,
                             0x0000ffff0000ffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x00000000002a542a, 0x0000000000000000,
                      0x00000000002a542a, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000242, 0xffffffff0000ffff,
                             0x0000000000000242, 0xffffffff0000ffff};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8080808000000000, 0x0000000000000000,
                      0x8080808000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x3f7f7f7eff800000, 0x0000000000000000,
                      0x3f7f7f7eff800000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007efeff00, 0x0000000001010000,
                             0x000000007efeff00, 0x0000000001010000};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x00001fff200007ef, 0x0000000000000000,
                      0x1f001f00000007ef, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000f1003, 0x000000ff000000ff,
                             0x000000000f0f0003, 0x000000ff000000ff};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfc00000000000000, 0x00000000fc38fc38,
                      0xfc00000000000000, 0x00000000fc38fc38};
  __m256i_result = (__m256i){0x0000fefefe000000, 0x0000000000000000,
                             0x0000fefefe000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000400000004, 0x0000000400100013,
                      0x0000000400100014, 0x0000000400100013};
  v4u64_op1 = (v4u64){0x0a0a0a0a00000000, 0x0a0a000000000a0a,
                      0x0a0a0a0a00000000, 0x0a0a000000000a0a};
  __m256i_result = (__m256i){0x4100004141410000, 0x0000020200000000,
                             0x4100004141410000, 0x0000020200000202};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0808080808080808, 0x0808080808080808,
                      0x0808080808080808, 0x0808080808080808};
  v4u64_op1 = (v4u64){0x0808080808080808, 0x0808080808080808,
                      0x0808080808080808, 0x0808080808080808};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000001,
                      0xffffffffffff8000, 0x0000000000000001};
  __m256i_result = (__m256i){0x00000000ffffffc0, 0x0000000000000000,
                             0x00000000ffffffc0, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffffff80,
                             0x0000000000000000, 0x00000000ffffff80};
  __m256i_out = __lasx_xvsrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc237bd65fc892985, 0x0707feb608c9328b,
                      0xc237bd65fc892985, 0x0707feb608c9328b};
  v4u64_op1 = (v4u64){0x333568ce26dcd055, 0x00150015003a402f,
                      0x333568ce26dcd055, 0x00150015003a402f};
  __m256i_result = (__m256i){0x002a0074666a4db9, 0x0e0f1192846ff912,
                             0x002a0074666a4db9, 0x0e0f1192846ff912};
  __m256i_out = __lasx_xvsrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000000000405, 0x8000000001010100,
                      0x8000000000000405, 0x8000000001010100};
  __m256i_result = (__m256i){0xffe00000ffe00000, 0x0000000000000000,
                             0xffe00000ffe00000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000013, 0x0000000000000013,
                      0x0000000000000013, 0x0000000000000013};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000001,
                      0x0000000000000000, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x34);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000900000009, 0x0000000000000000,
                      0x0000000900000009, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x3ff9fffa3ff9fffa, 0x0000000000000000,
                      0x3ff9fffa3ff9fffa, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000007ff3, 0x0000000000000000,
                             0x0000000000007ff3, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000003ffffffff, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xe1e800002f03988d, 0xffffffffffffffff,
                      0xe1e800002f03988d, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xff0f400001781cc4, 0x0000000000000000,
                             0xff0f400001781cc4, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000080,
                      0x0000000000000000, 0x0000000000000080};
  __m256i_result = (__m256i){0x0000000000000080, 0x0000000000000000,
                             0x0000000000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x40);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfffffffefffffffe, 0xfffffffefffffffe,
                      0xfffffffefffffffe, 0xfffffffefffffffe};
  __m256i_result = (__m256i){0xfffffdfffffffdff, 0xffffffffffffffff,
                             0xfffffdfffffffdff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x37);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xff3eff3eff3eff3e,
                      0xffffffffffffffff, 0xff3eff3eff3eff3e};
  __m256i_result = (__m256i){0xffffffffffffff3e, 0x0000000000000000,
                             0xffffffffffffff3e, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x70);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0002000200020008,
                      0x0000000000000000, 0x0002000200020018};
  __m256i_result = (__m256i){0x0040000000000000, 0x0000000000000000,
                             0x00c0000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x01010101010101c9, 0x0101010101010101,
                      0x01010101010101c9, 0x0101010101010101};
  __m256i_result = (__m256i){0x1010101010101010, 0x0000000000000000,
                             0x1010101010101010, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x01010101010101c9, 0x0101010101010101,
                      0x01010101010101c9, 0x0101010101010101};
  v4u64_op1 = (v4u64){0x0000000000000064, 0x0000000000000781,
                      0x0000000000000064, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000003c, 0x0008080808080808,
                             0x0000000000000000, 0x0008080808080808};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x45);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00ff00ff, 0x00f3009500db00ff,
                      0x00ff00ff00ff00ff, 0x00f3009500db00ff};
  __m256i_result = (__m256i){0x0000000000003cc0, 0x0000000000000000,
                             0x0000000000003cc0, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fff8579f, 0x0000000000000000,
                      0x00000000fff8579f, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fff8579f, 0x0000000000000000,
                      0x00000000fff8579f, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000003, 0x0000000000000003,
                             0x0000000000000003, 0x0000000000000003};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000080, 0x0000956a00000000,
                      0x0000000000000080, 0x0000956a00000000};
  __m256i_result = (__m256i){0xb500000000000000, 0x007fffffffffffff,
                             0xb500000000000000, 0x007fffffffffffff};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x29);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x66);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffce, 0x0000000000000000,
                      0x00000000ffffffce, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000040e7, 0x0000000000004000,
                      0x00000000000040e7, 0x0000000000004000};
  __m256i_result = (__m256i){0x0000200000000000, 0x0000000000000000,
                             0x0000200000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x21);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
