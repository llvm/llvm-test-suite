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
  v2u64_op2 = (v2u64){0xc0c00c01c2cd0009, 0xc0c00000c0c00000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000f7f700f7f700, 0x7f78787f00f7f700};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000400, 0x0000000000000400};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000400, 0x0000000000000400};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x000000000000040d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000080003f80ffff};
  v2u64_op1 = (v2u64){0x0000002000000020, 0x0000002000000020};
  v2u64_op2 = (v2u64){0x3ff0010000000000, 0x3ff0010000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000080003f80ffff};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000000000007b};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xff82ff810081ff81, 0xff81ff82ff810081};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080808, 0x0808080808080808};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffff8000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffff8000};
  v2u64_op2 = (v2u64){0x0000800000000000, 0x0000800000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffff8000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x841f000fc28f801f, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x841f000fc28f801f, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xe593c8c4e593c8c4, 0xff800000ff800000};
  __m128i_result = (__m128i){0x76ecfc8b85ac78db, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000fff3, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op2 = (v2u64){0x000000000000040d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000010400, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100013fa0, 0x00000001ca02f854};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000100013fa0, 0x00000001ca02f854};
  __m128i_result = (__m128i){0x0000000100013fa0, 0x00000001ca02f854};
  __m128i_out = __lsx_vmaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000002b0995850, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x007f800000000000, 0xffffffff80005613};
  v2u64_op2 = (v2u64){0x007f800000000000, 0xffffffff80005613};
  __m128i_result = (__m128i){0xc0000002b0995850, 0xffff00011cf0c569};
  __m128i_out = __lsx_vmaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffff00ffff7e01, 0x000000ffffff81fe};
  v2u64_op2 = (v2u64){0x000000fffe01fd02, 0x0000000000000000};
  __m128i_result = (__m128i){0x00fe00fffe86f901, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfff8004000000000, 0x0000000000004000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xbfffbfffbfffbffe};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0xbfffbfffbfffbffe};
  __m128i_result = (__m128i){0x0000000000000000, 0xbfffbfffbfffbffe};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffd3000000130000, 0xffd3000000130000};
  v2u64_op1 = (v2u64){0xffd3000000130000, 0xffd3000000130000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffd3000000130000, 0xffd3000000130000};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x00000000003dffc2, 0x00000000003dffc2};
  v2u64_op2 = (v2u64){0x00000000003dffc2, 0x00000000003dffc2};
  __m128i_result = (__m128i){0x00000f02e1f80f04, 0x00000f02e1f80f04};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffefffe00000000, 0xfffefffe00000000};
  v2u64_op1 = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  v2u64_op2 = (v2u64){0x6bae051ffed76001, 0x5a57bacbd7e39680};
  __m128i_result = (__m128i){0xffe9454286c0e000, 0xf3eb458161080000};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0051005200510052, 0x0051005200510052};
  v2u64_op2 = (v2u64){0xffaeffaeffaeffae, 0xffaeffaeffaeffae};
  __m128i_result = (__m128i){0xffffe65ecc1be5bc, 0xffffe65ecc1be5bc};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf1f1f1f1865e65a1, 0xf1f1f1f149ed7273};
  v2u64_op1 = (v2u64){0x00000000ffff941d, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xf1f1f1f1865e65a1, 0xf1f1f1f149ed7273};
  __m128i_result = (__m128i){0x78508ad4ec2ffcde, 0xf1f1f1f149ed7273};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffffffffffff, 0x0000ffffffffffff};
  v2u64_op1 = (v2u64){0x0000ffffffffffff, 0x0000ffffffffffff};
  v2u64_op2 = (v2u64){0x0000000e0000000e, 0x000000120000000d};
  __m128i_result = (__m128i){0x0001000dfffffff1, 0x0001000cfffffff2};
  __m128i_out = __lsx_vmaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000001ff000001ff, 0x000001ff000001ff};
  v2u64_op1 = (v2u64){0x000001ff000001ff, 0x000001ff000001ff};
  v2u64_op2 = (v2u64){0x7ffffffeffffffff, 0xff80ffffffffffff};
  __m128i_result = (__m128i){0x7ffffe0100000000, 0x000002fe800000ff};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff00000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x7fffffffffffffff};
  v2u64_op2 = (v2u64){0xff80000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfe80000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000080};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000080};
  __m128i_out = __lsx_vmaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
