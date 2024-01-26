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
  v2u64_op2 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fffffff00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x7fffffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x7e00fe0000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080808, 0x0808080808080808};
  v2u64_op1 = (v2u64){0xfffffffc0000fdfc, 0xfffffffbffffff85};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3941248880000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x3941248880000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x40f3fa0000000000, 0x3ff0000000000000};
  __m128i_result = (__m128i){0x76f4248880000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x000035ed0000e000, 0x0000e36400005253};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0080008000800080, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4000000040000000, 0x400000003fffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000007fffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4000000040000000, 0x400000003fffffff};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x78508ad4ec2ffcde, 0xf1f1f1f149ed7273};
  v2u64_op1 = (v2u64){0x00000000ffdfdc0d, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x00000000ffdfdc0d, 0x0000000000000000};
  __m128i_result = (__m128i){0x78508ad4ae70fd87, 0xf1f1f1f149ed7273};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000003b, 0x0000440efffff000};
  v2u64_op1 = (v2u64){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v2u64_op2 = (v2u64){0x4400000000000000, 0x440ef000440ef000};
  __m128i_result = (__m128i){0x000000000000003b, 0x0000440efffff000};
  __m128i_out = __lsx_vmaddwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00201df000000000, 0x00000000000ffc2f};
  v2u64_op1 = (v2u64){0x0000ffc100010001, 0xffc2ffe700000007};
  v2u64_op2 = (v2u64){0x011f57c100201a46, 0x00010020fffeffde};
  __m128i_result = (__m128i){0x57cb857100001a46, 0x001ffce00016fb41};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff0000ffff0000};
  v2u64_op1 = (v2u64){0x7ff0000000000000, 0xffff0000ffff0000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0xffff0000ffff0000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffff0000ffff0000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000800000000000, 0x0000800000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7c7c9c0000007176, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x00ff000000001f1f};
  __m128i_result = (__m128i){0x7c7c9c0000007176, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc5c53492f25acbf2, 0xbfd10d0d7b6b6b73};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xff000000001f1f00};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xc5c53492f25acbf2, 0xbfd10d0d7b6b6b73};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xd73691661e5b68b4, 0x34947b4b11684f92};
  v2u64_op1 = (v2u64){0x000016f303dff6d2, 0x000016f303dff6d2};
  v2u64_op2 = (v2u64){0x7fffffff00000001, 0x0000000000000000};
  __m128i_result = (__m128i){0xee297a731e5c5f86, 0x34947b4b11684f92};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0000ffffffffffff};
  v2u64_op1 = (v2u64){0x00000000011ff8bc, 0x0177fff0fffffff0};
  v2u64_op2 = (v2u64){0xffffffff008ff820, 0x00bbfff7fffffff7};
  __m128i_result = (__m128i){0x00010001f1153780, 0xffe8008fffe7008f};
  __m128i_out = __lsx_vmaddwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000100000021, 0x0000000100000001};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010002};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010002};
  v2u64_op2 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0x0001808201018081, 0x0001808281820102};
  __m128i_out = __lsx_vmaddwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffff0200ffff01ff, 0x0000010100fe0101};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7f8000007f800000, 0x0000000100000001};
  v2u64_op2 = (v2u64){0x00ffff0000000000, 0x00ffff0000000000};
  __m128i_result = (__m128i){0x8000000000000000, 0x007f7f80807f7f80};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000020302030, 0x0000000020302030};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x7fffffff7fffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x3fffffffc0000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000006e17bfd8, 0x000000006e17bfd8};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffff0100000001, 0xffffff0100000001};
  __m128i_result = (__m128i){0x000000006e17bfd8, 0x000000006e17bfd8};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0001000100000000};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0xfffffffffffffffe};
  v2u64_op2 = (v2u64){0xfffffffffffffffe, 0xfffffffffffffffe};
  __m128i_result = (__m128i){0x0000000000000004, 0x00010000fffffffc};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000080000000, 0x000000008000e2e3};
  v2u64_op1 = (v2u64){0x0000000080000000, 0x000000008000e2e3};
  v2u64_op2 = (v2u64){0x00ff00ff00ff00ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x807f808000000000, 0x0000000080806362};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffa, 0xfffffffffffffffa};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffffa, 0xfffffffffffffffa};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8101010181010101, 0x8101010181010101};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000101010001};
  v2u64_op1 = (v2u64){0x0000000000000014, 0x0000000000000014};
  v2u64_op2 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0x0000ffed00010001, 0x0001000101010015};
  __m128i_out = __lsx_vmaddwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
