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

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  v2u64_op1 = (v2u64){0x000000020f2300ee, 0x00020002000d0000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0400040004000400};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4026f4ffbc175bff, 0x2ea268972ea2966a};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x5d7f5d807fea807f};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x80808080806b000b, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000c0c0c000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xff86dd83ff9611c3};
  v2u64_op1 = (v2u64){0x000000013ecaadf2, 0x0000000035697d4e};
  __m128i_result = (__m128i){0x00007f7f00007f80, 0xe280e67f00000000};
  __m128i_out = __lsx_vssrarni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0101010100000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000100000001};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000000000f0};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000000000000f0};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffe0001fffe0001, 0xfffe0001fffe0001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000003};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc0fffff000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffe00000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010001000000010, 0x0000001000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000080000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100080000, 0x0000000100000008};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002008300500088, 0x0000000000000008};
  v2u64_op1 = (v2u64){0x0000000000000088, 0x0000000000000008};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000008000000080, 0x0000008000000080};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc1fc0d3bf55c4000, 0xda4643d5301c4000};
  v2u64_op1 = (v2u64){0x01010000fefe0101, 0x7505853d654185f5};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x8000000080000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000010000002b, 0x0000000000000073};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000400000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000065a0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000200000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x9941d155f43a9d08, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000080000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x29);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffff0000ffff, 0x000100fe000100fe};
  v2u64_op1 = (v2u64){0x0000000000002000, 0x0000000000002000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000100000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0400400204004002};
  __m128i_result = (__m128i){0x0000010000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xf9796558e39953fd, 0xd3259a2984048c23};
  __m128i_result = (__m128i){0x8000000080000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x37b951002d81a921, 0x0000100000001000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000071e48cca, 0x0000000075dbe982};
  v2u64_op1 = (v2u64){0x0001000000000000, 0x0001000000000000};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x0ebb7d300e3c9199};
  __m128i_out = __lsx_vssrarni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x79);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x01ff01ff01ff01ff, 0x01ff01ff01ff01ff};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x59);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0029ff96005cff88, 0x001800390049ffaa};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0bef0b880bd80bd8, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0bd80bd80bd80000, 0x0bd80bd80bdfffff};
  __m128i_result = (__m128i){0x000000017b017b01, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x51);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5252525252525252, 0x5252525252525252};
  v2u64_op1 = (v2u64){0x004d004d004d004d, 0x004d004d004d004d};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x06d9090909090909, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x48);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6d339b4f3b439885, 0x0039d21e3229d4e8};
  v2u64_op1 = (v2u64){0x0000000d00000000, 0xfffffff000000000};
  __m128i_result = (__m128i){0xffc0000000000000, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrarni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0020002000200020, 0x0020002000200020};
  v2u64_op1 = (v2u64){0x0fa96b88d9944d42, 0xffffffff60090958};
  __m128i_result = (__m128i){0x00001802041b0013, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0002000000020000, 0x0002000000020000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xf0800320fff1fa20};
  __m128i_result = (__m128i){0x0032000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xea38e0f75f6e56d1, 0x0d1202e19235e2bc};
  v2u64_op1 = (v2u64){0xffffc000ffffc005, 0xffffe500ffffc085};
  __m128i_result = (__m128i){0x0000000000000000, 0xffff00000000ffff};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000004442403e4, 0x0000000005452505};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x03fc03fc03fc03fc};
  __m128i_result = (__m128i){0x0808080800000000, 0x00000b4a00008808};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfff0fffffff09515, 0xfff0fffffff00001};
  v2u64_op1 = (v2u64){0xffff0001ffff9515, 0x00000000ffff53d9};
  __m128i_result = (__m128i){0x000000ff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000bfffffff, 0x000003000000d612};
  v2u64_op1 = (v2u64){0xffff0001ffff9515, 0x00000000ffff53d9};
  __m128i_result = (__m128i){0x0000000500000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000b, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000001};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000020000};
  __m128i_result = (__m128i){0x0000010000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c6c6c6c6, 0x00000000c6c6c6c6};
  v2u64_op1 = (v2u64){0x0014ffe4ff76ffc4, 0x00000001fffeff98};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000016, 0x0000000000000011};
  v2u64_op1 = (v2u64){0x0000000000000016, 0x0000000000000011};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020fbf04581ec0, 0x00060fbf02596848};
  v2u64_op1 = (v2u64){0x01010287010146a1, 0x010169d9010169d9};
  __m128i_result = (__m128i){0x0002000200000001, 0x0000000200000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfff00000ffff0000, 0xff01ffffe41f0000};
  v2u64_op1 = (v2u64){0x0000000100000155, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000002b, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m128i_result = (__m128i){0x0200020002000200, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000fe00ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff02, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000000f, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x03c0038000000380, 0x03c0000000000000};
  __m128i_result = (__m128i){0x0f0000000f000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111113111111121, 0x1111113111111141};
  v2u64_op1 = (v2u64){0x0032000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffff0000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000100000000, 0x0000000100000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff01, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffe1fffffff, 0xfffffffefffffffe};
  v2u64_op1 = (v2u64){0x7fffffff7ffffffb, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000080008, 0x0000000000000002};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7750af4954c29940, 0x1ab6021f72496458};
  v2u64_op1 = (v2u64){0x7750af4954c29940, 0x1ab6021f72496458};
  __m128i_result = (__m128i){0x6ad8ffffffffffff, 0x6ad8ffffffffffff};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x6363636363636363};
  v2u64_op1 = (v2u64){0x1200091212121212, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0002000200020002};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00006f9100007337, 0x0000930400008a10};
  v2u64_op1 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  __m128i_result = (__m128i){0x309d2f342a5d2b34, 0x00250023001c001d};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfee1f6f18800ff7f, 0xff00e400ff00e400};
  v2u64_op1 = (v2u64){0xffff000000000000, 0xffff000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff8000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000001};
  __m128i_out = __lsx_vssrarni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8b8a8a898a8a8909, 0x0c0c8b8a8b8b0b0a};
  v2u64_op1 = (v2u64){0x1615141315141312, 0x1817161517161514};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_out = __lsx_vssrarni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xefd32176ffe100f7, 0xffe080f6efc100f7};
  v2u64_op1 = (v2u64){0xefd32176ffe100f7, 0xffe080f6efc100f7};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01d8000000000000, 0x017001a002c80260};
  v2u64_op1 = (v2u64){0x2e34594c3b000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrarni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000003, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x72);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f417f417f027e03, 0x000000000000003f};
  v2u64_op1 = (v2u64){0x5237c1bac9eadf55, 0xe93d0bd19ff0c170};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x60);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x58);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff0000000000000, 0xffff0000ffff0000};
  v2u64_op1 = (v2u64){0x7ff0000000000000, 0xffff0000ffff0000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x71);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrarni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
