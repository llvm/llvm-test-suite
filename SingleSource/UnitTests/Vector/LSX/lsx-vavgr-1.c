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

  v2u64_op0 = (v2u64){0x0000800000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0040000000000000, 0x0040000000ff00ff};
  __m128i_result = (__m128i){0x0020c00000000000, 0x0020000000000000};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x800000005b4b1b18, 0xb9fe3640e4eb1b18};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffd000000000000};
  __m128i_result = (__m128i){0xc00000002e260e0c, 0xdcfe1b20f2f60e0c};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111113111111121, 0x111110ff11111141};
  v2u64_op1 = (v2u64){0x7bffffffffffffff, 0xfbffffffffffffff};
  __m128i_result = (__m128i){0x4608081808080810, 0x060808ff08080820};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000ff000000ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000010};
  v2u64_op1 = (v2u64){0x000000000000fff0, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000008};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff80000000, 0x000000000000ac26};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000060000000000};
  __m128i_result = (__m128i){0x00000000c0000000, 0x000003000000d613};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffe5, 0xffffffffffffffe5};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffff2, 0xfffffffffffffff2};
  __m128i_out = __lsx_vavgr_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000002a, 0x0000000000000073};
  v2u64_op1 = (v2u64){0x0000000100000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000015, 0x000000000000003a};
  __m128i_out = __lsx_vavgr_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfff8004000000000, 0x0000000000004000};
  __m128i_result = (__m128i){0xfffc002000000000, 0x0000000000002000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffc002000000000, 0x0000000000002000};
  v2u64_op1 = (v2u64){0xfffc002000000000, 0x0000000000002000};
  __m128i_result = (__m128i){0xfffc002000000000, 0x0000000000002000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000ff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000ff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000ff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000007fff0018, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000003fff800c, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0280000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7500000075000000, 0x7500000075000000};
  __m128i_result = (__m128i){0x3bc000003a800000, 0x3a8000003a800000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007d1800007c99, 0xffff800000000000};
  v2u64_op1 = (v2u64){0x0a621b3ebe5e1c02, 0x0a0000001e000000};
  __m128i_result = (__m128i){0x05314c2bdf2f4c4e, 0x04ffc0000f000000};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000002000000000, 0x0000002000000000};
  __m128i_result = (__m128i){0x0000001000000000, 0x0000001000000001};
  __m128i_out = __lsx_vavgr_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffff80000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  __m128i_result = (__m128i){0x3fc000003fc00000, 0x3fc000003fc00000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fffffff7fffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x3fffffffc0000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff00ff00ff00ff00, 0xff00ff00ff00ff00};
  __m128i_result = (__m128i){0xff807f807f807f80, 0xff807f807f807f80};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000002, 0x0000000000000002};
  v2u64_op1 = (v2u64){0x0000000000280000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000140001, 0x0000000000000001};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffff46, 0xfffffffffffffffe};
  v2u64_op1 = (v2u64){0x00fe00fe00fe0045, 0x00fe00fe00fe00fe};
  __m128i_result = (__m128i){0x007f007f007effc6, 0x007f007f007f007e};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  v2u64_op1 = (v2u64){0xfffffffffffffffc, 0xfffffffffffffffc};
  __m128i_result = (__m128i){0xe4423f7b769f8ffe, 0x33f5c2d7d975d7fe};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000003ff8, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff9dff9dff9dff9d, 0x0000000000000000};
  __m128i_result = (__m128i){0xffceffceffcf1fcb, 0x0000000000000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3bc000003a800000, 0x3a8000003a800000};
  v2u64_op1 = (v2u64){0x00fe00fe7fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x1e5f007f5d400000, 0x1d4000001d400000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ff00, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000800000000};
  __m128i_result = (__m128i){0x0000000000007f80, 0x0000000400000000};
  __m128i_out = __lsx_vavgr_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
