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

  v2u64_op0 = (v2u64){0xfffffffe00000004, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffff01010105, 0x0101010101010101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000001fffffffe, 0x00000001c00ffffe};
  __m128i_result = (__m128i){0x0101010280808040, 0x0101010201808040};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080808, 0x0808080808080808};
  v2u64_op1 = (v2u64){0x0808080808080808, 0x0808080808080808};
  __m128i_result = (__m128i){0x0909090909090909, 0x0909090909090909};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfefeff04fffd0004, 0xfefbff06fffa0004};
  __m128i_result = (__m128i){0x4040801080200110, 0x4008804080040110};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  v2u64_op1 = (v2u64){0x8000000080000000, 0x8000000080000000};
  __m128i_result = (__m128i){0x8101010181010101, 0x8101010181010101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000020000, 0x0000000000020000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101030101, 0x0101010101030101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000100};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010101};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00feff8000ff80ff, 0xffffff80ffff7e02};
  v2u64_op1 = (v2u64){0x0280000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x04ffff8101ff81ff, 0xffffff81ffff7f03};
  __m128i_out = __lsx_vbitset_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0982e2daf234ed87, 0xf51cf8dad6040188};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0983e2dbf235ed87, 0xf51df8dbd6050189};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000010a000b, 0x0000000000000000};
  __m128i_result = (__m128i){0x0001000104000800, 0x0001000100010001};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffc3639d96, 0xffffffff994cb09c};
  v2u64_op1 = (v2u64){0x34632935195a123c, 0x20de27761210386d};
  __m128i_result = (__m128i){0xffffffffc7639d96, 0xffffffff994db09c};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000100010001};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0003000100010001, 0x0007000000050000};
  __m128i_result = (__m128i){0x0008000200020002, 0x0080000100200001};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x45c0000044800000, 0x4480000044800000};
  v2u64_op1 = (v2u64){0x00fe00fe7fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x45c04000c4808000, 0x4481000144810001};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3bc000003a800000, 0x3a8000003a800000};
  v2u64_op1 = (v2u64){0x00fe00fe7fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x7bc04000ba808000, 0x3a8100013a810001};
  __m128i_out = __lsx_vbitset_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffe000ffffe000, 0xffffe000ffffe000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffe001ffffe001, 0xffffe001ffffe001};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000038335ca2777, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000800800000, 0x0000000100000001};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000001, 0x0000000100000001};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe00fcfffe01fd01, 0xfc01fcfefc02fdf7};
  v2u64_op1 = (v2u64){0x5d5d5d5d5d5d5d55, 0xffffffff00000001};
  __m128i_result = (__m128i){0xfe00fcfffe21fd01, 0xfc01fcfefc02fdf7};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000408, 0x0000000897957687};
  __m128i_result = (__m128i){0x0000000100000100, 0x0000010000000080};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffe0001fffe0001, 0xfffe0001fffe0001};
  __m128i_result = (__m128i){0x0000000200000002, 0x0000000200000002};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000081a83bea, 0x00000000545cab1d};
  v2u64_op1 = (v2u64){0x545cab1d81a83bea, 0x13f9c5b60028a415};
  __m128i_result = (__m128i){0x2000000081a83fea, 0x00400000547cab1d};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000040033, 0x0000000000038003};
  __m128i_result = (__m128i){0x0000000100080000, 0x0000000100000008};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x01500178010000f8, 0x00a600e000a600e0};
  __m128i_result = (__m128i){0x0100000001000000, 0x0000000100000001};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000001, 0xffffffffffffffff};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00004a1e00004a1e, 0x0000000000000008};
  __m128i_result = (__m128i){0x4000000040000000, 0x0000000100000100};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000c90000011197, 0x0000cecd00004657};
  __m128i_result = (__m128i){0x0000000100800000, 0x0000200000800000};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  v2u64_op1 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  __m128i_result = (__m128i){0x7f8000017f800001, 0x7f8000017f800001};
  __m128i_out = __lsx_vbitset_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fff7fc01, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0xffffffff00000000};
  __m128i_result = (__m128i){0x80000000fff7fc01, 0x0000000000000001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f8000003f800000, 0x3f8000003f800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x3f8000003f800001, 0x3f8000003f800001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5779108fdedda7e4, 0xd78cfd70b5f65d76};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x5779108fdedda7e5, 0xd78cfd70b5f65d77};
  __m128i_out = __lsx_vbitset_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
