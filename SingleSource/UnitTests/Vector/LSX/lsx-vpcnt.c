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

  v2u64_op0 = (v2u64){0x7f80000000000000, 0x7f8000007f800000};
  __m128i_result = (__m128i){0x0701000000000000, 0x0701000007010000};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffff00feff00, 0x807f7f8000ffff00};
  __m128i_result = (__m128i){0x0000080800070800, 0x0107070100080800};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5252525252525252, 0x5252525252525252};
  __m128i_result = (__m128i){0x0303030303030303, 0x0303030303030303};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fe01fe01, 0x00000000fe03fe01};
  __m128i_result = (__m128i){0x0000000007010701, 0x0000000007020701};
  __m128i_out = __lsx_vpcnt_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000100010, 0x0000000000100010};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000000010000, 0x0007000000040000};
  __m128i_result = (__m128i){0x0002000000010000, 0x0003000000010000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x21201f1e19181716};
  __m128i_result = (__m128i){0x0010001000100010, 0x0003000900050007};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe7e5dabf00010001, 0xbbe5560400010001};
  __m128i_result = (__m128i){0x000b000c00010001, 0x000b000500010001};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  __m128i_result = (__m128i){0x0000000800000008, 0x0000000800000008};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0ba00ba00ba011eb, 0x0ba00ba00ba00ba0};
  __m128i_result = (__m128i){0x0000000a0000000d, 0x0000000a0000000a};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe160065422d476da, 0xfff0800080008000};
  __m128i_result = (__m128i){0x0000000b00000010, 0x0000000d00000002};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffff0000ffff0000};
  __m128i_result = (__m128i){0x0000001000000000, 0x0000001000000010};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000010100000101, 0x0000010100000101};
  __m128i_result = (__m128i){0x0000000200000002, 0x0000000200000002};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffc, 0xfffffffffffffffc};
  __m128i_result = (__m128i){0x000000200000001e, 0x000000200000001e};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffff7fffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000001f0000001f, 0x0000002000000020};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7f80000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000800000000};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x27b1b106b8145f50, 0xf654ad7447e59090};
  __m128i_result = (__m128i){0x0000000e0000000e, 0x000000120000000d};
  __m128i_out = __lsx_vpcnt_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ffff, 0xfffffffffefefefe};
  __m128i_result = (__m128i){0x0000000000000010, 0x000000000000003c};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x803f800080000000, 0xe0404041e0404041};
  __m128i_result = (__m128i){0x0000000000000009, 0x000000000000000e};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111111111111111, 0x1111111111111111};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000010};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfbfb47fbfbfb0404, 0xfbfbfb17fbfb38ea};
  __m128i_result = (__m128i){0x0000000000000029, 0x000000000000002f};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffbfc0ffffbfc0, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000032, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000005};
  __m128i_result = (__m128i){0x0000000000000002, 0x0000000000000002};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000040, 0x0000000000000040};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0103000201030002, 0x0000000000020000};
  __m128i_result = (__m128i){0x0000000000000008, 0x0000000000000001};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9c9c9c9c9c9c9c9c, 0x9c9c9c9c9c9c9c9c};
  __m128i_result = (__m128i){0x0000000000000020, 0x0000000000000020};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000008ffffa209, 0x0000000600007fff};
  __m128i_result = (__m128i){0x0000000000000016, 0x0000000000000011};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000467fef81, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000013, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vpcnt_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
