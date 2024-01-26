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
  __m128i_result = (__m128i){0x0202020202020202, 0x0202020202020202};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe86ce7eb5e9ce950, 0x0000000000000000};
  __m128i_result = (__m128i){0xec68e3ef5a98ed54, 0x0404040404040404};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0xefefefefefefefef, 0x1010101010101010};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4040404040404040, 0x4040404040404040};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000010000000000, 0x0000010000000000};
  __m128i_result = (__m128i){0x0404050404040404, 0x0404050404040404};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xbfbfbfbfbfbfbfbf, 0xbfbfbfbfbfbfbfbf};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x181b2541ffffffff, 0x441ba9fcffffffff};
  __m128i_result = (__m128i){0x1c1f2145fbfbfbfb, 0x401fadf8fbfbfbfb};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8080808080808080, 0x8080808080808080};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefefeeffef7feff, 0xfefefefdbffefdfe};
  __m128i_result = (__m128i){0xfcfcfcedfcf5fcfd, 0xfcfcfcffbdfcfffc};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x030298a6a1030a49, 0x021b7d24c9678a35};
  __m128i_result = (__m128i){0x01009aa4a301084b, 0x00197f26cb658837};
  __m128i_out = __lsx_vbitrevi_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4000400040004000, 0x4000400040004000};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001008100000005, 0x000000007fff8000};
  __m128i_result = (__m128i){0x0801088108000805, 0x0800080077ff8800};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0400040004000400, 0x0400040004000400};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff02, 0x0000000000000000};
  __m128i_result = (__m128i){0x04000400fbfffb02, 0x0400040004000400};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000d, 0x0000000000000000};
  __m128i_result = (__m128i){0x040004000400040d, 0x0400040004000400};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0040004000400040, 0x0040004000400040};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1918171615141312, 0x21201f1e1d1c1b1a};
  __m128i_result = (__m128i){0x3918371635143312, 0x01203f1e3d1c3b1a};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x61608654a2d4f6da, 0x7ff0000000000000};
  __m128i_result = (__m128i){0xe160065422d476da, 0xfff0800080008000};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x37c0001000000000, 0x37c0001000000000};
  __m128i_result = (__m128i){0x77c0401040004000, 0x77c0401040004000};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x1000100010001000, 0x1000100010001000};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x2000200020002000, 0x2000200020002000};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x34b8122ef4054bb3, 0xd6a09e662ab46b31};
  __m128i_result = (__m128i){0x34f8126ef4454bf3, 0xd6e09e262af46b71};
  __m128i_out = __lsx_vbitrevi_h((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000003004, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000400000007004, 0x0000400000004000};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000001, 0x0000000100000001};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000200010, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000400000204010, 0x0000400000004000};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010000000100000, 0x0010000000100000};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x77c03fd640003fc6, 0x77c0404a4000403a};
  __m128i_result = (__m128i){0x75c03fd642003fc6, 0x75c0404a4200403a};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00000100fffffeff, 0xfffffefffffffeff};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0xffffefff00001000, 0xffffefff00001000};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000010000000100, 0x0000010000000100};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000002580f01, 0x0000000000555889};
  __m128i_result = (__m128i){0x0010000002480f01, 0x0010000000455889};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000007fffffff};
  __m128i_result = (__m128i){0x4000000040000000, 0x400000003fffffff};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffff7fffffff7f, 0xffffff7fffffff7f};
  __m128i_out = __lsx_vbitrevi_w((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfeffffffffffffff, 0xfeffffffffffffff};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000004f804f80, 0x000000004f804f81};
  __m128i_result = (__m128i){0x000000004fc04f80, 0x000000004fc04f81};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080808, 0x0808080808080808};
  __m128i_result = (__m128i){0x0808080808280808, 0x0808080808280808};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000040000000, 0x0000000040000000};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000020000, 0x0000000000020000};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000100, 0x0000000000000100};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000200000000, 0x0000000200000000};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000002000, 0x0000000000002000};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000008};
  __m128i_result = (__m128i){0x0000000000200000, 0x0000000000200008};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020fbf00000fbf, 0x00060fbf00040fbf};
  __m128i_result = (__m128i){0x00020fbf02000fbf, 0x00060fbf02040fbf};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000c6c58000c6b2, 0x0000c6c60000c6c6};
  __m128i_result = (__m128i){0x8000c6c78000c6b2, 0x0000c6c40000c6c6};
  __m128i_out = __lsx_vbitrevi_d((__m128)v2u64_op0, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
