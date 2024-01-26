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
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ffffffeffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x4080808080808080, 0x0000000000000000};
  __m128i_result = (__m128i){0x7ffffffeffffffff, 0xff80ffffffffffff};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9f4fcfcfcf800000, 0x004fcfcfd01f9f9f};
  v2u64_op1 = (v2u64){0x9f4fcfcfcf800000, 0x004fcfcfd01f9f9f};
  __m128i_result = (__m128i){0x9f4fcfcfcf800000, 0x004f1fcfd01f9f9f};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xda);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x171f0a1f6376441f, 0x6363797c63996399};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x171f0a1f6376441f, 0x6363797c63990099};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x94);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000a092444, 0xffffffffbd994889};
  __m128i_result = (__m128i){0x0000890000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x58);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff0001ffff9515, 0x00000000ffff53d9};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xff000001ffff9515, 0x00000000ffff53d9};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x67);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x80808080806b000b, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x8000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000101010001};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xeef8227b596117b1, 0x75b043c4d17db125};
  v2u64_op1 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  __m128i_result = (__m128i){0xeef8227b4f8017b1, 0x75b043c4d17db125};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x027c027c000027c0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000de32400, 0x0000000000000000};
  __m128i_result = (__m128i){0x027c027c000027c0, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x77);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x35bb8d32b2625c00, 0x01ef013f01e701f8};
  __m128i_result = (__m128i){0x0000000000000000, 0x00008d3200000000};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xea);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe7e5dabf00010001, 0xbbe5560400010001};
  v2u64_op1 = (v2u64){0xe7e5dabf00010001, 0xbbe5560400010001};
  __m128i_result = (__m128i){0xe7e5dabf00010001, 0xe7e5560400010001};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x27);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000014155445, 0xfffffffffc606ec5};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x76);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000024170000, 0x00000000084d12ce};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x56);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe519ab7e71e33848, 0x01533b5e7489ae24};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffab7e71e33848, 0x01533b5e7489ae24};
  __m128i_out = __lsx_vextrins_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xbc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xcf00000000000000, 0xbf8000000000ffff};
  __m128i_result = (__m128i){0x0000ffff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x92);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0200020002000200, 0x0200020002000200};
  __m128i_result = (__m128i){0xffffffff02000200, 0xffffffffffffffff};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x342caf9be55700b5, 0x0c03e17edd781b11};
  v2u64_op1 = (v2u64){0xffffe000ffff1fff, 0x0000040400000383};
  __m128i_result = (__m128i){0x342caf9bffff1fff, 0x0c03e17edd781b11};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xcc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c2bac2c2, 0xfffffffffefefe6a};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000c2bac2c2, 0x00000000fefefe6a};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000a000a000a000a, 0x000a000a000a000a};
  v2u64_op1 = (v2u64){0x0000000a00000009, 0x0000000a0000000a};
  __m128i_result = (__m128i){0x000a000a000a000a, 0x000a000a0000000a};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xaf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff80000001};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x67);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x5237c1bac9eadf55, 0xe93d0bd19ff0c170};
  __m128i_result = (__m128i){0x0000000000000000, 0x5237c1baffffffff};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x71);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000002, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000002};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000100010001};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x24);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc1fc7941bc7e00ff, 0xffff760386bdae46};
  __m128i_result = (__m128i){0x00000000ffff7603, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff2356fe165486, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x000ef0000000003b, 0x3a8000003a800000};
  __m128i_result = (__m128i){0xffff2356fe165486, 0x0000003b0000ffff};
  __m128i_out = __lsx_vextrins_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x70);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000063636363, 0x00000000a16316b0};
  v2u64_op1 = (v2u64){0x6363636363636363, 0x16161616a16316b0};
  __m128i_result = (__m128i){0x16161616a16316b0, 0x00000000a16316b0};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xfffc45a851c40c18, 0xfff489b693120950};
  __m128i_result = (__m128i){0xfffc45a851c40c18, 0xffffffffffffffff};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x48);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xcc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000005d5d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x41);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0bd80bd80bd80000, 0x0bd80bd80bdfffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0bd80bd80bd80000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x41dfbe1f41e0ffff};
  v2u64_op1 = (v2u64){0x0000ffc100010001, 0xffc2ffe000000000};
  __m128i_result = (__m128i){0x0000ffc100010001, 0x41dfbe1f41e0ffff};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xec);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000fea0000fffe};
  v2u64_op1 = (v2u64){0xff0cff78ff96ff14, 0xffffff8607db959f};
  __m128i_result = (__m128i){0xff0cff78ff96ff14, 0x00000fea0000fffe};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4040ffffc0400004, 0x8003000000020000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x8003000000020000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x64);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffff0000ffff0000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0xffff0000ffff0000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x74);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x82);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x8000000000000000};
  v2u64_op1 = (v2u64){0x1748c4f9ed1a5870, 0x975ca6046e2e4889};
  __m128i_result = (__m128i){0x1748c4f9ed1a5870, 0x8000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000024170000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000084d12ce, 0x000aa822a79308f6};
  __m128i_result = (__m128i){0x0000000024170000, 0x00000000084d12ce};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000034, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x117d7f7b093d187f, 0x01017f3c00000148};
  __m128i_result = (__m128i){0x0000000000000034, 0x117d7f7b093d187f};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x70);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vextrins_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
