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

  v2u64_op0 = (v2u64){0x000400c600700153, 0x000c0002000c0002};
  v2u64_op1 = (v2u64){0x000400c600700153, 0x000c0002000c0002};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fdfd0404, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x3fffffff3fffffff, 0x3fffffff3fffffff};
  __m128i_result = (__m128i){0x8000800080008000, 0x000000000000fc08};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x3f7477f8ff4e2152, 0xf58df7841423142a};
  __m128i_result = (__m128i){0x3d3e0505101e4008, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000adf0000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000001e00, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0040000000400040, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000020002020};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x1010101010101010, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0xffffffe5c8000000};
  v2u64_op1 = (v2u64){0x99d1ffff0101ff01, 0x91f80badc162a0c4};
  __m128i_result = (__m128i){0x905d0b06cf0008f8, 0x00ff400000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000418200000008e, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000002100047, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff40ff83, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x1010101010101010};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000002408beb26c8, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000706e, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000070, 0x0000000000028c27};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000101080001010, 0x80000b0b80000b0b};
  v2u64_op1 = (v2u64){0xffffefefffffeff0, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000fe00fe, 0x0061006100020002};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000078087f08, 0x0000000078087f08};
  __m128i_result = (__m128i){0x0000e0fc0000e0fc, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000001e0000001e, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000f08, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x2020202020202020, 0x0000000000000002};
  __m128i_out = __lsx_vsrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x0000d688ffffbd95, 0xffff8969ffffd7e2};
  __m128i_result = (__m128i){0xf12dfafc1ad1f7b3, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000001515151500, 0x0000001515151500};
  __m128i_result = (__m128i){0x0001515000015150, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffff7fff};
  v2u64_op1 = (v2u64){0xe2bb5ff00e20aceb, 0xe2bb5ff00e20aceb};
  __m128i_result = (__m128i){0x00e3000e00e3000e, 0x0100010000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1010101010101010, 0x1010101010101010};
  __m128i_result = (__m128i){0x8081808180818081, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808102, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000001010102};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x03fc03fc03fc03fc, 0x001000100010000b};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x04000400ff01ff01};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x1204900f62f72565};
  __m128i_result = (__m128i){0x4901725600000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000400000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000040804080};
  __m128i_result = (__m128i){0x0000020100000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636362, 0x6363636363636362};
  v2u64_op1 = (v2u64){0x6363636363636362, 0x6363636363636362};
  __m128i_result = (__m128i){0x0032003200320032, 0x0032003200320032};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ffdf87f0b0c7f7f, 0xffffffff01010102};
  v2u64_op1 = (v2u64){0x363953e42b56432e, 0xf6b3eb63f6b3f6b3};
  __m128i_result = (__m128i){0x00f700f70036002b, 0x010000010080000b};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000003030103, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000003030103, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000006060, 0x0000000000006060};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000ff00ffffff, 0x000000ff00ff0000};
  v2u64_op1 = (v2u64){0x0000828282828282, 0x8282828282828282};
  __m128i_result = (__m128i){0x0008000800000008, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x41afddcb1c000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xe82f7c27bb0778af, 0xd09e1bd99a2c6eb1};
  __m128i_result = (__m128i){0x000d000a000f000c, 0x0000000000040002};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffafff0fff9ff01, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0000000200000002};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000d800cff8};
  __m128i_out = __lsx_vsrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000fffe, 0x000000010000007f};
  __m128i_result = (__m128i){0x0800000400000800, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfc0203fccbedbba7, 0x2bd5d429e34a1efb};
  v2u64_op1 = (v2u64){0x89fed7c07fdf5d00, 0xc9f66947f077afd0};
  __m128i_result = (__m128i){0xa3f83bd8e03fefaf, 0x14f1a50ffe65f6de};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000010600000106, 0x6ed694e00e0355db};
  __m128i_result = (__m128i){0xe00e035606000001, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbb9013bd049bc9ec, 0xe739e7ade77ae725};
  v2u64_op1 = (v2u64){0x56aca41400000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000041400000, 0x7ade77ae3bd049bd};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080808080c04040, 0x0020202020202020};
  v2u64_op1 = (v2u64){0x0101010001808080, 0x0101010101010101};
  __m128i_result = (__m128i){0x0001010100010101, 0x0000202000008081};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010000000000000, 0xfff0000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00fff00000001000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000001ed68, 0x0000fff800000000};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0x1ff6a09e667f3bd8};
  __m128i_result = (__m128i){0x999fcef600000000, 0x0000000000007b5a};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3802f4fd025800f7, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x91ff40fffff8ff50, 0xc8ff0bffff00ffae};
  __m128i_result = (__m128i){0x0000192000001240, 0x0000200000000700};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x33);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xd9743eb5fb4deb3a, 0xbb7743ca4c78461f};
  v2u64_op1 = (v2u64){0x1b43e8a30a570a63, 0x22445e1ad9c3e4f0};
  __m128i_result = (__m128i){0x45e1ad9c3e8a30a5, 0x743ca4c843eb5fb5};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000300000003, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x6c72a7c856ac865c, 0xed67d6c7ed67ed67};
  __m128i_result = (__m128i){0x0000000700000003, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x33);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00f7000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000005150, 0x0000000000005150};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000000f7000};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x24);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffdff0, 0x00000000ffff8000};
  v2u64_op1 = (v2u64){0x0144329880000000, 0x8000000080000000};
  __m128i_result = (__m128i){0x004000004c400000, 0x007fffc0007ffff0};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000300000ff1, 0x00000002000007d7};
  __m128i_result = (__m128i){0x000007d700000ff1, 0x0000000000000001};
  __m128i_out = __lsx_vsrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x4000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x34);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002000000020, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000200000002000, 0x0000200000002000};
  __m128i_result = (__m128i){0x0000010000000100, 0x0000000000000001};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000000ff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000001000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000800080008000, 0x000000000000fc08};
  v2u64_op1 = (v2u64){0x0000000000000001, 0xffffffffba420000};
  __m128i_result = (__m128i){0xfdd2100000000000, 0x000007e044000400};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f3f3f0e00000000, 0x0000081e003f3f3f};
  v2u64_op1 = (v2u64){0x3f3f3f0e00000000, 0x0000081e003f3f3f};
  __m128i_result = (__m128i){0x00000103c007e7e8, 0x00000103c007e7e8};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x43);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0202ff3f02022212, 0x0202022302023212};
  v2u64_op1 = (v2u64){0x0000ff3f00002010, 0x0000002100003010};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000001};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x79);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000000006ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0037f80000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x69);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff0ffc0001, 0xffffffff0ffd0ffd};
  v2u64_op1 = (v2u64){0xd9743eb5fb4deb3a, 0xbb7743ca4c78461f};
  __m128i_result = (__m128i){0x002eddd0f2931e12, 0x003fffffffc3ff44};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x3f3f3f7fbf3fffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x47);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffa, 0xffffffe8ffff28fc};
  v2u64_op1 = (v2u64){0x00000006ffff81e1, 0x00007fff0000803e};
  __m128i_result = (__m128i){0x000007fff0000804, 0x0ffffffe8ffff290};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x44);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ff0bff76};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x75);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fc000007fc00000, 0xff800000ff800000};
  v2u64_op1 = (v2u64){0xffffff00ffffffff, 0xffffff00ffffffff};
  __m128i_result = (__m128i){0x0000000000001000, 0x0000000000000ff8};
  __m128i_out = __lsx_vsrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x74);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
