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

  v2u64_op0 = (v2u64){0x0000007f00000004, 0x0000000100000001};
  v2u64_op1 = (v2u64){0x0001000100000004, 0x0000000401000001};
  v2u64_op2 = (v2u64){0x00000000003f0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0404040404000404, 0x0404040404040404};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x3f2f1f0f00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00ff00ff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000029, 0x000000000000002f};
  v2u64_op1 = (v2u64){0x000000ff000000ff, 0x000000ff000000ff};
  v2u64_op2 = (v2u64){0x0000000000000029, 0x000000000000002f};
  __m128i_result = (__m128i){0xffffffffffffff00, 0xffffffffffffff00};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7efefefe82010201, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x418181017dfefdff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000005, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffff81, 0xffffffffffffffff};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x52525252adadadad, 0x52525252adadadad};
  v2u64_op2 = (v2u64){0x2000000014131211, 0x2000000004030201};
  __m128i_result = (__m128i){0xadadadadffffffff, 0xadadadad52adadad};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000005};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000005};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000005};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc5c534920000c4ed, 0xbfd10d0d7b6b6b73};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xedededededededed, 0xedededededededed};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000100, 0x0000000202020200};
  v2u64_op1 = (v2u64){0x000000000000ff80, 0x04040403fafafafc};
  v2u64_op2 = (v2u64){0x0807060504030201, 0x00101a1b1c1d1e1f};
  __m128i_result = (__m128i){0xfc000000000000ff, 0x8000020202000000};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  v2u64_op1 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  v2u64_op2 = (v2u64){0x0000000000000001, 0x0000001a0000000b};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000080000000ff};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffd7ff8dffa4ff7a, 0xff6cffb5ff98ff6e};
  v2u64_op1 = (v2u64){0xee297a731e5c5f86, 0x34947b4b11684f92};
  v2u64_op2 = (v2u64){0x1f20000000000000, 0x1f0710301a2b332d};
  __m128i_result = (__m128i){0xff86868686868686, 0xffee7a7a9811ff7b};
  __m128i_out = __lsx_vshuf_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x000000000000000d, 0x0000000000000000};
  __m128i_result = (__m128i){0x000d000d000d000d, 0x000d000d000d000d};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001f002f003f000f, 0x001f002f003f000f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fffffffffffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000300110012, 0x000100040010001f};
  v2u64_op1 = (v2u64){0x000000002bfd9461, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x00007fff00007fff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00007fff00000000};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000300000003, 0x000300030000001f};
  v2u64_op1 = (v2u64){0x0003000300a10003, 0x000300037ff000ff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x000000007ff000ff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000003};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0019000000090000, 0x0019000000090000};
  v2u64_op1 = (v2u64){0x0909000009090000, 0x0909000009090000};
  v2u64_op2 = (v2u64){0x05ad3ba576eae048, 0x002a05a2f059094a};
  __m128i_result = (__m128i){0x0909e0480909e048, 0x0909e0480909e048};
  __m128i_out = __lsx_vshuf_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000029, 0x0000000000000030};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x00000001ffffff29, 0x00000000000000c0};
  __m128i_result = (__m128i){0xffffff2900000001, 0xffffff29ffffff29};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001f, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1f54e0ab00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x010101fe0101fe87, 0x0101010101010101};
  __m128i_result = (__m128i){0x0101fe8700000000, 0x0101fe870101fe87};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001000000000, 0x0000002f0000002f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000020000020, 0x0000000020000020};
  __m128i_result = (__m128i){0x2000002020000020, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002000000003, 0x0000000900000010};
  v2u64_op1 = (v2u64){0x0000001000000010, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x8000000000000103, 0x8000000100000000};
  __m128i_result = (__m128i){0x0000010380000001, 0x8000000000000103};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002000000001, 0x0000001000000007};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000a0000000b, 0x0000001a0000001b};
  v2u64_op1 = (v2u64){0x030298a6a1030a49, 0x021b7d24c9678a35};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000013, 0x0000000000000003};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000011, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x000000002c002400, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffff6080ffff4417, 0xffffb96bffff57c9};
  __m128i_result = (__m128i){0xffffb96bffff57c9, 0xffffb96bffff57c9};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0001000100000000};
  v2u64_op2 = (v2u64){0xffffffff0015172b, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffff0015172b, 0xffffffff0015172b};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000020};
  v2u64_op1 = (v2u64){0xf0003000f0003000, 0x0000000000002000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001a, 0x0000000000000007};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7fff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x030298a6a1030a49, 0x021b7d24c9678a35};
  __m128i_result = (__m128i){0x7fff7fff7fff7fff, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000002};
  v2u64_op1 = (v2u64){0x0000fffe0000fffe, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  __m128i_result = (__m128i){0x7f8000007f800000, 0x0000fffe0000fffe};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000020, 0x0000000000000010};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
