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

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffdfff, 0xffffffff, 0xffffdfff, 0xffffffff};
  v4i32_op1 = (v4i32){0x01ffe200, 0xffffe000, 0xffffffff, 0xffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000fe02, 0x00010002, 0x0000fe7d, 0x00010002};
  v4i32_op1 = (v4i32){0x00000001, 0x00000000, 0x0000007b, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xf15be124, 0x8e8f8626, 0x4c3b3549, 0x1223dabf};
  v4i32_op1 = (v4i32){0x94f902c0, 0x1f5533a6, 0xb6dbecac, 0xfffffacd};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x27001517, 0xfbffffff, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x0000ffff, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffff9515, 0xffff0001, 0xffff53d9, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00010001, 0x00010001, 0x00010001, 0x00010001};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000080, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0078007f, 0x00df020f, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x001ffff9, 0x001e0052, 0x0083ffe5, 0x0037ffd4};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefffeff7f002d06, 0xffffff0c8000c212};
  v2u64_op1 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00f000807000009e, 0x00f0008100800080};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xfffe00029f9f6061, 0xffff0000ffff0000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffc0800000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00067fff0002a207, 0x0000c0010000a186};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sle_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00ff00ff, 0x00ff00ff, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x442403e4, 0x00000004, 0x05452505, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffff00000000};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000101, 0x00000101, 0x00000101, 0x00000101};
  v4i32_op1 = (v4i32){0x00000002, 0x00000002, 0x00000002, 0x00000002};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000cd63, 0x0000cd63, 0x00010000, 0x00010000};
  v4i32_op1 = (v4i32){0xffffd765, 0xffffd765, 0xffffcd63, 0xffffcd63};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffff00ff, 0xffffffff};
  v4i32_op1 = (v4i32){0x0000ffff, 0xffffffff, 0xffff0000, 0xffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff80000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fffffff7fffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3fbf3fbf00007fff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7ff8, 0x000000003fbf3fbf};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc03fc03fc0ff00ff, 0x00000000013ec13e};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00018d8b, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85af0000b000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe03fe3ffe01fa21, 0xfe3bfb01fe3bfe01};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sule_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
