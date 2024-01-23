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

  v2u64_op0 = (v2u64){0xfffefffefffffffc, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffefffefffffffc, 0x0000000000000000};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, 4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000958aefff895e, 0x0000006f00002f0a};
  __m128i_result = (__m128i){0xfafa958aeffa89fa, 0xfafafafafafafafa};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, -6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, 1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000adadadad, 0x00000000adadadad};
  __m128i_result = (__m128i){0xfbfbfbfbadadadad, 0xfbfbfbfbadadadad};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, -5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, 12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000100, 0x0000000202020200};
  __m128i_result = (__m128i){0x0000000000000100, 0x0000000202020200};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, 5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xf1f1f1f1f1f1f1f1, 0xf1f1f1f1f1f1f1f1};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, -15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007e1600007d98, 0x0000f50000007500};
  __m128i_result = (__m128i){0x0000090900000998, 0x0000f50000000900};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, 9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ff800000, 0x10f881a20ffd02b0};
  __m128i_result = (__m128i){0xf1f1f1f1f180f1f1, 0xf1f181a2f1f1f1b0};
  __m128i_out = __lsx_vmini_b((__m128)v2u64_op0, -15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, -10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1514131214131211, 0x1716151416151413};
  __m128i_result = (__m128i){0xfff3fff3fff3fff3, 0xfff3fff3fff3fff3};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, -13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefefefefefefefe, 0xfefefefefefefefe};
  __m128i_result = (__m128i){0xfefefefefefefefe, 0xfefefefefefefefe};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, 2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, 3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, 11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_h((__m128)v2u64_op0, 3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000002, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000002, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000900000009, 0x0000000900000009};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffff4fffffff4, 0xfffffff4fffffff4};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, -12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000200010, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000001f, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffff3fffffff3, 0xfffffff3fffffff3};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, -13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_result = (__m128i){0x00000000ffefffef, 0x0000000000000000};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff01fe0400000006, 0x0000000800000000};
  __m128i_result = (__m128i){0xff01fe0400000005, 0x0000000500000000};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffafffffffa, 0xfffffffafffffffa};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, -6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3fbf3fbf00007fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000e0000000e, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000d0000000d, 0x0000000000000000};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080008000800080, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001300000013, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000900000009, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0x8080808080808080, 0x8080808080808080};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, 8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x345002920f3017d6, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffff7fffffff7, 0xfffffff7fffffff7};
  __m128i_out = __lsx_vmini_w((__m128)v2u64_op0, -9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe7a6533b800001b8, 0xb7032c34093d35ab};
  __m128i_result = (__m128i){0x0000000900000009, 0x0000000900000009};
  __m128i_out = __lsx_vmini_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x03574e3a62407e03};
  __m128i_result = (__m128i){0xfffffffffffffff7, 0xfffffffffffffff7};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100100000, 0x1000000010000000};
  __m128i_result = (__m128i){0xfffffffffffffff1, 0xfffffffffffffff1};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000034, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000006, 0x0000000000000000};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000006, 0x0000000000000000};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00a6ffceffb60052, 0xff84fff4ff84fff4};
  __m128i_result = (__m128i){0xfffffffffffffff0, 0xff84fff4ff84fff4};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffff9, 0xfffffffffffffff9};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111113111111100, 0x111110ff11111141};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xaa55556fd5aaaac1, 0x55aa55c3d5aa55c4};
  __m128i_result = (__m128i){0xaa55556fd5aaaac1, 0x000000000000000c};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffff4, 0xfffffffffffffff4};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffffb, 0xfffffffffffffffb};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfcfcfcdcfcfcfcdc, 0xfcfcfcdcfcfcfcdc};
  __m128i_result = (__m128i){0xfcfcfcdcfcfcfcdc, 0xfcfcfcdcfcfcfcdc};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001030103, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffffc, 0xfffffffffffffffc};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00017ea200002000, 0x000085af0000b000};
  __m128i_result = (__m128i){0xfffffffffffffff7, 0xfffffffffffffff7};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffff4, 0xfffffffffffffff4};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, -12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff01e41ffff0ffff, 0xff00e400ff00e400};
  __m128i_result = (__m128i){0xff01e41ffff0ffff, 0xff00e400ff00e400};
  __m128i_out = __lsx_vmini_d((__m128)v2u64_op0, 14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
