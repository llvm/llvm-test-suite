#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2, v2u64_result;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2, v4i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fea8ff44, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x2020202020202020, 0x2020202020202020};
  v2u64_result = (v2u64){0x2020202020202020, 0x2020202020202020};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000100010001000, 0x1000100010001000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x1000100010001000, 0x1000100010001000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000000f, 0x0000000000000000};
  v2u64_result = (v2u64){0x000000000000000f, 0x0000000000000000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff0200ffff01ff, 0x0000010100fe0101};
  v2u64_op1 = (v2u64){0x0000ffffffffffff, 0x0000ffffffffffff};
  v2u64_result = (v2u64){0xffff0200ffff01ff, 0x0001010100fe0100};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffffa0204000, 0x7fff0101ffffe000};
  v2u64_op1 = (v2u64){0x7f3bffffa0226021, 0x7f370101ff04ffff};
  v2u64_result = (v2u64){0x7fffffffa0204000, 0x7fff0101ffffe000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00012c8a0000a58a, 0x0000ebd20000714f};
  v2u64_op1 = (v2u64){0x27b1b106b8145f50, 0xf654ad7447e59090};
  v2u64_result = (v2u64){0x27b1b106b8145f50, 0xf654ad7447e59090};
  __m128d_out = __lsx_vfadd_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000ff000000ff, 0x000000ff000000ff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x800000ff000000ff};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000fff80000, 0x00000000fff8fff8};
  v2u64_result = (v2u64){0x80000000fff80000, 0x80000000fff8fff8};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  v2u64_op1 = (v2u64){0x4e0018eceb82c53a, 0xb55ccf30f52a6a68};
  v2u64_result = (v2u64){0xce0018eceb82c53a, 0x355ccf30f52a6a68};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00009b140000917b, 0xffffffff00006c82};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x00009b140000917b, 0xffffffff00006c82};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000083b00000000, 0x0000000100000020};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5237c1bac9eadf55, 0xe93d0bd19ff0c170};
  v2u64_op1 = (v2u64){0xe5017c2ac9ca9fd0, 0xe6d4572c8a5835bc};
  v2u64_result = (v2u64){0x65017c2ac9ca9fd0, 0xe93d0bd19ff07013};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x65017c2ac9ca9fd0, 0xe93d0bd19ff07013};
  v2u64_op1 = (v2u64){0x0000f841000091aa, 0x00008bf700017052};
  v2u64_result = (v2u64){0x65017c2ac9ca9fd0, 0xe93d0bd19ff07013};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001ca02f854, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000001ca02f854, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000004000000002};
  v2u64_op1 = (v2u64){0x0004455501500540, 0x5555410154551515};
  v2u64_result = (v2u64){0x8004455501500540, 0xd555410154551515};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000300a10003, 0x000300037ff000ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000007ff000ff};
  v2u64_result = (v2u64){0x0003000300a10003, 0x0003000300000000};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xb4b8122ef4054bb3, 0x56a09e662ab46b31};
  v2u64_result = (v2u64){0x34b8122ef4054bb3, 0xd6a09e662ab46b31};
  __m128d_out = __lsx_vfsub_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000001300000013, 0x0000001300000013};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000100000001000, 0x0000100000000000};
  v2u64_op1 = (v2u64){0x1000100000001000, 0x0000100000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010001000100010, 0x0010001000100010};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000007000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffab7e71e33848, 0x01533b5e7489ae24};
  v2u64_op1 = (v2u64){0xffffab7e71e33848, 0x01533b5e7489ae24};
  v2u64_result = (v2u64){0xffffab7e71e33848, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfmul_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x7ff8000000000000};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f0200007f020000, 0x7f4000007f040000};
  v2u64_op1 = (v2u64){0xffffffff01018888, 0xfffffffff8f8dada};
  v2u64_result = (v2u64){0xffffffff01018888, 0xfffffffff8f8dada};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000100007f01};
  v2u64_result = (v2u64){0x7ff8000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffefefffffffff};
  v2u64_op1 = (v2u64){0x0400000000000000, 0x0000000000000020};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffefefffffffff};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x7ff8000000000000, 0x7ff8000000000000};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000810000, 0x00000000ff801c9e};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000000000ffff};
  v2u64_result = (v2u64){0x7ff0000000000000, 0x40eff02383e383e4};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xc8847ef6ed3f2000, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000cd630000cd63, 0x0001000000010000};
  v2u64_op1 = (v2u64){0xffff00000000ffff, 0x0000000000000000};
  v2u64_result = (v2u64){0xffff00000000ffff, 0x7ff0000000000000};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x03aa558e1d37b5a1, 0x000aa822a79308f6};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffefffffffe, 0xfffffffefffffffe};
  v2u64_op1 = (v2u64){0xfffefffe011df03e, 0xfffefffefffefffe};
  v2u64_result = (v2u64){0xfffffffefffffffe, 0xfffffffefffffffe};
  __m128d_out = __lsx_vfdiv_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
