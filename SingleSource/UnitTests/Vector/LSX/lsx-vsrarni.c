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

  v2u64_op0 = (v2u64){0x0000001300000013, 0x0000001300000013};
  v2u64_op1 = (v2u64){0x0000000e0000000e, 0x0000000e0000000e};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xecec006c00000000, 0xecec006c00000000};
  v2u64_op1 = (v2u64){0xffff007f00000000, 0xffff007f00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000008fc4ef7b4, 0x000000043c5ea7b6};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000fea0000fffe};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000003e, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00fe00fe000200fe, 0x00fe00fe000200fe};
  __m128i_result = (__m128i){0xfefe02fefefe02fe, 0x000000000000003e};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000016, 0x0000000000000016};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000004, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ff020000fff4, 0x000000000000ffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ff020000fff4, 0x000000000000ffff};
  v2u64_op1 = (v2u64){0x1e801ffc00000000, 0x7fc0000000000000};
  __m128i_result = (__m128i){0x0000000001000000, 0x0000080007f80800};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xff8000002f4ef4a8, 0xff80000000000000};
  __m128i_result = (__m128i){0x000000000000f4a8, 0xffffffffffffffff};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000800000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000ffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000800000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000003f0080ffc0, 0x000000ffa7f8ff81};
  v2u64_op1 = (v2u64){0x0000a7f87fffff81, 0x000000007fff00ff};
  __m128i_result = (__m128i){0x0000004000000040, 0x0000ffd400000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003f800000000000, 0x003f800000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000080003f80ffff};
  __m128i_result = (__m128i){0x000001fc00000000, 0x0002000000020000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x479f64b03373df61, 0x09e8e9012fded7fd};
  v2u64_op1 = (v2u64){0x04c004d6040004c6, 0x04c0044a0400043a};
  __m128i_result = (__m128i){0x00890087009b0099, 0x1d20db00ec967bec};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000f0000000f, 0x0000000f0000000f};
  v2u64_op1 = (v2u64){0x0000000f0000000f, 0x0000000f0000000f};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ff010000ff01, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xcd636363cd636363, 0xcd636363cd636363};
  v2u64_op1 = (v2u64){0xcd636363cd636363, 0xcd636363cd636363};
  __m128i_result = (__m128i){0xf359f359f359f359, 0xf359f359f359f359};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000800ecedee68, 0x00000807bf0a1f80};
  v2u64_op1 = (v2u64){0x0005847b00000000, 0x0005840100000005};
  __m128i_result = (__m128i){0x0058000000580000, 0x0001f0a20001cedf};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x274f4f0648145f50, 0x0a545374471b7070};
  v2u64_op1 = (v2u64){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_result = (__m128i){0x9e9f9e9f9e9f9e9f, 0xa8a736e19e9e28bf};
  __m128i_out = __lsx_vsrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0086018c01360164, 0x00100184017e0032};
  v2u64_op1 = (v2u64){0xfffffff33c4b1e67, 0x00000001fffffffe};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000800c0004300c};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x4101010141010100};
  v2u64_op1 = (v2u64){0x00000000000001ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0020808100000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x29);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x24);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000332ae5d97330, 0x0000001ff85ffdc0};
  __m128i_result = (__m128i){0x1ff85ffe2ae5d973, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000080800000808, 0x0000080800000808};
  __m128i_result = (__m128i){0x8080000180800001, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000000010000000, 0x0000200000002000};
  v2u64_op1 = (v2u64){0x0103000201030002, 0x0000000000020000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x26);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffb1fb1000000000};
  v2u64_op1 = (v2u64){0x0b73e427f7cfcb88, 0xf2c97aaa7d8fa270};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ff0000ff0000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000000001e5};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x5000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x66);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x64);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x028c026bfff027af, 0x001ffff0003ffff0};
  __m128i_result = (__m128i){0xffffc00a3009b000, 0x00000003fc03fc00};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff80010001, 0xffffffff80010001};
  v2u64_op1 = (v2u64){0x0bd80bd80bd80000, 0x0bd80bd80bdfffff};
  __m128i_result = (__m128i){0xf0bd80bd80bd8000, 0x1ffffffff8001000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x48);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000d46cdc13, 0x00000000dfa6e0c6};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x64);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffc000400000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00003fff00010000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffab7e71e33848, 0x01533b5e7489ae24};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xce9135c49ffff570};
  __m128i_out = __lsx_vsrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x23);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
