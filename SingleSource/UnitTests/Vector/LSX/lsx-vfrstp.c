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
  v2u64_op1 = (v2u64){0x0404038383838404, 0x0404038383838404};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x03ff03ff03ff03ff};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000200010, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000200010, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000000};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000000};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000003f803f4, 0x0e7ffffc01fffffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000003f803f4, 0x0e7ffffc01fffffc};
  __m128i_result = (__m128i){0x0000001003f803f4, 0x0e7ffffc01fffffc};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000800};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000800};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000020000007d, 0x0000000200000002};
  v2u64_op1 = (v2u64){0x0000586100015567, 0x0000746400016388};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000020000007d, 0x0800000200000002};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  v2u64_op2 = (v2u64){0x61608654a2d4f6da, 0x7ff0000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000ff08ffff};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000aaaa};
  v2u64_op1 = (v2u64){0x0000000081a83bea, 0x00000000545cab1d};
  v2u64_op2 = (v2u64){0x00d3007c014e00bd, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000aaaa};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000bc2000007e10, 0x0000400080003fff};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000bc2000007e04, 0x0000400080003fff};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0a753500950fa306, 0x000000000a752a55};
  v2u64_op1 = (v2u64){0x14ea6a002a406a00, 0xffffffff14eb54ab};
  v2u64_op2 = (v2u64){0x00007fff7fff8000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0a753500950fa306, 0x000000000a752a55};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0010001000100010, 0x0010001000100010};
  v2u64_op2 = (v2u64){0x0000000000000155, 0x0000000000000000};
  __m128i_result = (__m128i){0xffff100000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfrstp_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020100fedd0c00, 0xfe07e5fefefdddfe};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0005000501800005};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00020100fedd0008, 0xfe07e5fefefdddfe};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000010, 0x0000000000000010};
  __m128i_result = (__m128i){0xffffffffffff0008, 0xffffffffffffffff};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x36fbdfdcffdcffdc, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x1f1f1f27332b9f00, 0x1f1f1f1f1f1f1f00};
  __m128i_result = (__m128i){0x36fbdfdcffdc0008, 0x0000000000000000};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x37c0001000000000, 0x37c0001000000000};
  v2u64_op1 = (v2u64){0x0000003a0000003a, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x37c0001000000008, 0x37c0001000000000};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8080808080800008, 0x8080808080808080};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f1f1f1f1f1f1f1f, 0x1f1f1f1f1f1f1f1f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x1f1f1f1f1f1f1f1f, 0x1f1f1f1f1f1f1f1f};
  __m128i_result = (__m128i){0x1f1f1f1f1f1f1f1f, 0x00081f1f1f1f1f1f};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x27b169bbb8145f50, 0x02b010f881a281a2};
  v2u64_op1 = (v2u64){0x27b169bbb8145f50, 0x02b010f881a281a2};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x27b169bbb8140001, 0x02b010f881a281a2};
  __m128i_out = __lsx_vfrstp_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
