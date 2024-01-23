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

  v2u64_op0 = (v2u64){0x00000000007f7f02, 0x0000000000000000};
  __m128i_result = (__m128i){0x00003f803f800100, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0014000100000000};
  __m128i_result = (__m128i){0x7f807f807f807f80, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001030103, 0x0000000000000000};
  __m128i_result = (__m128i){0x0020006000200060, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080805, 0x0808080808080805};
  __m128i_result = (__m128i){0x0020002000200014, 0x0020002000200020};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001fffe0001fffe, 0x0000ffff0000ffff};
  __m128i_result = (__m128i){0x0000000201fe01fc, 0x0000000201fe01fc};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff1aff6d02834d70, 0xff1affff01001fe0};
  __m128i_result = (__m128i){0x0100418026803800, 0x7f800d007f803680};
  __m128i_out = __lsx_vsllwil_hu_bu((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3b2c8aefd44be966, 0x3e2b34ca59fa4c88};
  __m128i_result = (__m128i){0x001a8960001d2cc0, 0x0007658000115de0};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffff000000ff00, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000ff00, 0x0000ffff0000ff00};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x020202020202fe02, 0x0000040600000406};
  __m128i_result = (__m128i){0x002020000fe02000, 0x0020200000202000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x000000001ffffffe};
  __m128i_result = (__m128i){0x0000000000000002, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3131313131313131, 0x0000000000000000};
  __m128i_result = (__m128i){0x0313100003131000, 0x0313100003131000};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000900000009, 0x0000000900000009};
  __m128i_result = (__m128i){0x0000000000000090, 0x0000000000000090};
  __m128i_out = __lsx_vsllwil_wu_hu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000020000007d, 0x0000000200000002};
  __m128i_result = (__m128i){0x000000001f400000, 0x0000000000800000};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000005};
  __m128i_result = (__m128i){0x0000000000280000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000fef01000e27ca, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001c4f940000, 0x0000001fde020000};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000ffffffff00, 0x000000ffffffff00};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffff81010102, 0x7fff010181010102};
  __m128i_result = (__m128i){0x0000102020204000, 0x00000fffffffe000};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000800000000000, 0x0000800000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000008000};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x39c51f389c0d6112, 0x8d78336c83652b86};
  __m128i_result = (__m128i){0x00000004e06b0890, 0x00000001ce28f9c0};
  __m128i_out = __lsx_vsllwil_du_wu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
