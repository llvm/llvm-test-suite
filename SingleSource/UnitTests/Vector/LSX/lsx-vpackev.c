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
  v2u64_op1 = (v2u64){0x0000ffff0000ffff, 0x0000ffff00000000};
  __m128i_result = (__m128i){0x000000ff000000ff, 0x000000ff00000000};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x203e16d116de012b, 0x10f917d72d3d01e4};
  __m128i_result = (__m128i){0x003e00d100de002b, 0x00f900d7003d00e4};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000010000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x100f0e0d0f0e0d0c, 0x1211100f11100f0e};
  v2u64_op1 = (v2u64){0x0000002000000020, 0x0000002000000020};
  __m128i_result = (__m128i){0x0f000d200e000c20, 0x11000f2010000e20};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001fffffffe, 0x00000001c00ffffe};
  v2u64_op1 = (v2u64){0x00007f7f00007f7f, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000017fff00fe7f, 0x000001000f00fe00};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000016fff9d3d, 0x00000000f0009d3c};
  v2u64_op1 = (v2u64){0xfffff0016fff8d3d, 0xfffff000f0008d3c};
  __m128i_result = (__m128i){0x00ff0101ffff3d3d, 0x00ff000000003c3c};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffefffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffefffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffefefffffffff};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002fffefffd0001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1202120212021202, 0x1202120212021202};
  __m128i_result = (__m128i){0x0202fe02fd020102, 0x0002000200020002};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0004000400040004, 0x0004000400040004};
  v2u64_op1 = (v2u64){0x77c03fd640003fc6, 0x77c0404a4000403a};
  __m128i_result = (__m128i){0x04c004d6040004c6, 0x04c0044a0400043a};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe593c8c4e593c8c4, 0xff800000ff800000};
  v2u64_op1 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  __m128i_result = (__m128i){0x9380c4009380c400, 0x8080000080800000};
  __m128i_out = __lsx_vpackev_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xf8f8f008f8f8f800, 0xf8f8e018f8f8e810};
  __m128i_result = (__m128i){0x0000f0080000f800, 0x0000e0180000e810};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7ffe7ffe7ffe7ffe};
  __m128i_result = (__m128i){0x0000000000000000, 0x00007ffe00007ffe};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa36aca4435b8b8e1, 0x5a6f5c53ebed3faa};
  v2u64_op1 = (v2u64){0xa36aca4435b8b8e1, 0x5a6f5c53ebed3faa};
  __m128i_result = (__m128i){0xca44ca44b8e1b8e1, 0x5c535c533faa3faa};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000006362ffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000d0000000d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000dffff000d, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0000000200000002};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0000000200000002};
  __m128i_result = (__m128i){0x0002000200020002, 0x0002000200020002};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000208000002080, 0x0000208000002080};
  v2u64_op1 = (v2u64){0x0000208000002080, 0x0000208000002080};
  __m128i_result = (__m128i){0x2080208020802080, 0x2080208020802080};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000000b, 0x000000000000000b};
  __m128i_result = (__m128i){0x000000000000000b, 0x000000000000000b};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001b, 0x000000000000001b};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000001b0000, 0x00000000001b0000};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffff0000ffff0000, 0xffff0000ffff0000};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00d2701294027112, 0x0002711250a27112};
  __m128i_result = (__m128i){0xffff7012ffff7112, 0xffff7112ffff7112};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf8e1a03affffe3e2, 0x00000000000eefff};
  v2u64_op1 = (v2u64){0xf8e1a03affffe3e2, 0x00000000000eefff};
  __m128i_result = (__m128i){0xa03aa03ae3e2e3e2, 0x00000000efffefff};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x27b169bbb8140001, 0x02b010f881a281a2};
  __m128i_result = (__m128i){0x000069bb00000001, 0x000010f8000081a2};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ffff0000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc2f9bafac2fac2fa, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xe3b1cc6953e7db29, 0xbdf077eee7e20468};
  __m128i_result = (__m128i){0xc2fac2fa53e7db29, 0x00000000e7e20468};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001f0000001f, 0x0000002000000020};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001f00000000, 0x0000002000000000};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080005eff600001, 0xffc2007aff230027};
  v2u64_op1 = (v2u64){0x117d7f7b093d187f, 0x01017f3c00000148};
  __m128i_result = (__m128i){0xff600001093d187f, 0xff23002700000148};
  __m128i_out = __lsx_vpackev_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00001802041b0013, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00001802041b0013};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff80000000000000, 0xff80000000000000};
  v2u64_op1 = (v2u64){0xf4b6f3f52f4ef4a8, 0x0080000000000000};
  __m128i_result = (__m128i){0xf4b6f3f52f4ef4a8, 0xff80000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffff00000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xe3e3e3e3e3e3e3e3, 0xe3e3e3e3e3e3e3e3};
  __m128i_result = (__m128i){0xe3e3e3e3e3e3e3e3, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f8000003f800000, 0x3f8000003f800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x3f8000003f800000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffff0000ffff0000};
  v2u64_op1 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  __m128i_result = (__m128i){0x0000958affff995d, 0xffff000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000100010001};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000100013fa0, 0x00000001ca02f854};
  __m128i_result = (__m128i){0x0000000100013fa0, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000010000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000002002};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000010000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000053a};
  v2u64_op1 = (v2u64){0xfffc000400000000, 0xfff9000000000000};
  __m128i_result = (__m128i){0xfffc000400000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x020310d0c0030220, 0x30eb020302101b03};
  v2u64_op1 = (v2u64){0x020310d0c0030220, 0x30eb020302101b03};
  __m128i_result = (__m128i){0x020310d0c0030220, 0x020310d0c0030220};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpackev_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
