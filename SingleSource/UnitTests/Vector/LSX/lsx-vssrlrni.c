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

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0x8080000080800000, 0x8080808000008080};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000210011084, 0x000000017fff9000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000ffff0000ffff};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001fffff001fffff, 0x001fffff001fffff};
  v2u64_op1 = (v2u64){0x1918171615141312, 0x21201f1e1d1c1b1a};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x10ff10ff10ff10ff};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5252525252525252, 0x5252525252525252};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffff0000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffff000000000000};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000f1384, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000000004ff};
  __m128i_out = __lsx_vssrlrni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000040000};
  __m128i_result = (__m128i){0x0000080000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000d0000000d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000dffff000d, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000007ffff, 0x0000000000070007};
  __m128i_out = __lsx_vssrlrni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000800000000, 0x0000800c00000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x52525252adadadad, 0x52525252adadadad};
  v2u64_op1 = (v2u64){0x800000007fffffff, 0x800000007fffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlrni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffffffe, 0xffffff7ffffffffe};
  v2u64_op1 = (v2u64){0xfcfcfcdcfcfcfcdc, 0xfcfcfcdcfcfcfcdc};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000000010};
  __m128i_out = __lsx_vssrlrni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000080000000, 0x0000000080000000};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fff7fff, 0x7fff7fff7fff7fff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffff0000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000080};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x7fffffffffffffff};
  __m128i_result = (__m128i){0x0000080000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x34);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x29);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x061202bffb141c38, 0xffa6ff91fdd8ef77};
  v2u64_op1 = (v2u64){0x010101fe0101fe87, 0x0101010101010101};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000004000000002};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0xffc0ff80ff800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffff00000000};
  __m128i_out = __lsx_vssrlrni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x56);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x41);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff0000ffff0000, 0xffff0000ffff0000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x43);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffb7005f0070007c, 0x00000000ff81007c};
  v2u64_op1 = (v2u64){0x9a10144000400000, 0xffff80007e028401};
  __m128i_result = (__m128i){0x0000001ffff00010, 0x0000000000000020};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff0100ff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0707f8f803e8157e, 0x0607060700000807};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7ffffffe00000000, 0x7ffffffe00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001f0000001f, 0x0000002000000020};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x4000000040000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x27);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x26);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0103010301020109, 0x0101010400100203};
  v2u64_op1 = (v2u64){0x0000007f00000004, 0x0000000110000001};
  __m128i_result = (__m128i){0x0000200000010000, 0x0202000402020202};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000400, 0x0000000000000400};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffd60001723aa5f8, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x7f7f7f7f7f7f7f7f, 0x000000007f007f7f};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffc0800000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000008080600, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000034, 0x117d7f7b093d187f};
  v2u64_op1 = (v2u64){0xfe1bfe6c03824c60, 0xfe1bfefe00011ee1};
  __m128i_result = (__m128i){0x7f7f017f7f7f7f7f, 0x7f7f7f7f0000001a};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffb3c3ffff51ba, 0xffff3a81ffff89fd};
  __m128i_result = (__m128i){0x0802080408060803, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003e0021009a009a, 0x0000000000760151};
  v2u64_op1 = (v2u64){0x0000003e2427c2ee, 0x00000000246d9755};
  __m128i_result = (__m128i){0x00007f7f00107f7f, 0x00001e5410082727};
  __m128i_out = __lsx_vssrlrni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0001000100000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fff000000000000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000007f0000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0001000100000004, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000001000000, 0x0000000000007f00};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000001f807b89, 0x03574e3b94f2ca31};
  v2u64_op1 = (v2u64){0x0505000005050505, 0x0000000005050000};
  __m128i_result = (__m128i){0x0000001400140014, 0x000d02540000007e};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00005555aaabfffe, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x003fffffff000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000000000ff, 0x00000000000000ab};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00ff000000ff0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000007fff7fff, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x027c027c000027c0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000004f804f80, 0x000000004f804f81};
  __m128i_result = (__m128i){0x0000001400000014, 0x0000000000010000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff9cfebd, 0xffffffffff9cff05};
  v2u64_op1 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000002, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080636380806363, 0x808080e280808080};
  v2u64_op1 = (v2u64){0x8080636380806363, 0x808080e280808080};
  __m128i_result = (__m128i){0x0004000400040004, 0x0004000400040004};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000007fff7fff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc0808000c0808000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000003020302};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x4000400040004000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x10f8000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010000400020004, 0xffff0001ffff8002};
  v2u64_op1 = (v2u64){0xfffc0020ffffffff, 0x00000000ffff20ff};
  __m128i_result = (__m128i){0x0000000007ffe001, 0x07fff80000008000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xb4b8122ef4054bb3, 0x56a09e662ab46b31};
  __m128i_result = (__m128i){0x02b504f305a5c091, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x37);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000d000d000d000d, 0x000d000d000d000d};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000680000006800};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000002, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xf77edf9cffffffff, 0xff7ffffef77fffdd};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003ec0fc0fbfe001, 0x003ef89df07f0000};
  v2u64_op1 = (v2u64){0xfff40408ece0e0de, 0x3ff800ff2fe6c00d};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffa500010003, 0x0000ff960001005b};
  v2u64_op1 = (v2u64){0x00000000fffffffe, 0xffffff7ffffffffe};
  __m128i_result = (__m128i){0x0020000000000000, 0x0000002000000020};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff0000ffff0000, 0xffff00ffffff00ff};
  v2u64_op1 = (v2u64){0x00ff000900ffff98, 0x00ff00ff00ff00ff};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrlrni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1748c4f9ed1a5870, 0x8000000000000000};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3a8000003a800000, 0x0000000056000056};
  v2u64_op1 = (v2u64){0xa03aa03ae3e2e3e2, 0x00000000efffefff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlrni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x75);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
