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
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7fffffff7fffffff};
  __m128i_result = (__m128i){0x0101010101010101, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000007fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x2020202020207fff, 0x2020202020202020};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xc404040404040404, 0x0404040404040404};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00d2701294027112, 0x0002711250a27112};
  __m128i_result = (__m128i){0x08da781a9c0a791a, 0x080a791a58aa791a};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0303030303030303, 0x0303030303030303};
  __m128i_result = (__m128i){0x1313131313131313, 0x1313131313131313};
  __m128i_out = __lsx_vbitseti_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0020002000200020, 0x0020002000200020};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000c400, 0x0000000000000000};
  __m128i_result = (__m128i){0x001000100010c410, 0x0010001000100010};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  __m128i_result = (__m128i){0x0040004017fda869, 0x0040004000400040};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x1000100010001000, 0x1000100010001000};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0800080008000800, 0x0800080008000800};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x40f3fa0000000000, 0x3ff0000000000000};
  __m128i_result = (__m128i){0x40f3fa8000800080, 0x3ff0008000800080};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x0100010001000101, 0x0100010001000101};
  __m128i_out = __lsx_vbitseti_h((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3b2c8aefd44be966, 0x2e2b34ca59fa4c88};
  __m128i_result = (__m128i){0x3b2c8aefd44be966, 0x3e2b34ca59fa4c88};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0001000000010000, 0x0001000000010000};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0004000000040000, 0x0004000000040000};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000006, 0x0000000000000000};
  __m128i_result = (__m128i){0x8000000080000006, 0x8000000080000000};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000010000003f, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0x000000030000003f, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe5e5e5e5e4e4e46d, 0xe5e5e5e5e5e5e5e5};
  __m128i_result = (__m128i){0xe5e5e5e5e4e4e46d, 0xe5e5e5e5e5e5e5e5};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0100000001000000, 0x0100000001000000};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000008000000080, 0x0000008000000080};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128i_result = (__m128i){0xfff0008000000080, 0xfff0008000000080};
  __m128i_out = __lsx_vbitseti_w((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000ff00ff};
  __m128i_result = (__m128i){0x0040000000000000, 0x0040000000ff00ff};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x36);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8024d8f6a494afcb, 0x54beed87bc3f2be1};
  __m128i_result = (__m128i){0x8064d8f6a494afcb, 0x54feed87bc3f2be1};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x36);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x800000ff000000ff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x800000ff080000ff};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0982e2daf234ed87, 0xf51cf8dad6040188};
  __m128i_result = (__m128i){0x0982eadaf234ed87, 0xf51cf8dad6040188};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x2b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0002000000000000, 0x0002000000000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000080000000000, 0x0000080000000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x2b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100013fa0, 0x0000000100000000};
  __m128i_result = (__m128i){0x0000000900013fa0, 0x0000000900000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x23);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000ffff0000ffff};
  __m128i_result = (__m128i){0x0000040000000000, 0x0000ffff0000ffff};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x2a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000040804000, 0x0000000040804000};
  __m128i_result = (__m128i){0x0000000040a04000, 0x0000000040a04000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f81e3779b97f4a8, 0xffffffff00000000};
  __m128i_result = (__m128i){0x1f81e3779b97f4a8, 0xffffffff02000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000010000000, 0x0000000010000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0001000000000000, 0x0001000000000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000000, 0x0000002000000000};
  __m128i_out = __lsx_vbitseti_d((__m128)v2u64_op0, 0x25);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
