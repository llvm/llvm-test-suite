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
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080000000000000, 0x0080000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0080000000000000, 0x0080000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5d5d5d5d5d5d5d55, 0xffffffff00000001};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x5d5d5d005d5d5d55, 0xffffffff00000001};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x2020202020202020, 0x2020202020202020};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x202020202020ff20, 0x2020202020202020};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00020006;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000060000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00020006;
  __m128i_result = (__m128i){0x0000000000000600, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000003, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000003, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000001f1f};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x0000000000000000, 0x00ff000000001f1f};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x04fafa9200000000, 0x04faf60009f5f092};
  int_op1 = 0xffffffff;
  __m128i_result = (__m128i){0x04fafa9200000000, 0x04faf600fff5f092};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_b((__m128)v2u64_op0, int_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  int_op1 = 0x42652524;
  __m128i_result = (__m128i){0xffff2524ffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x00000000ffff0000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x8000000080000000, 0x8000000080000000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0xffffffff;
  __m128i_result = (__m128i){0x00000000ffff0000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001000, 0x0000000000001000};
  int_op1 = 0x7ff00000;
  __m128i_result = (__m128i){0x0000000000001000, 0x0000000000001000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  int_op1 = 0xffffffff;
  __m128i_result = (__m128i){0xffff000000000000, 0xffffffff00000000};
  __m128i_out = __lsx_vinsgr2vr_h((__m128)v2u64_op0, int_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x42652524;
  __m128i_result = (__m128i){0x4265252400000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000210011084, 0x000000017fff9000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000200000000, 0x000000017fff9000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000004};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00fe01fc0005fff4, 0x0000000800000000};
  int_op1 = 0x20202020;
  __m128i_result = (__m128i){0x00fe01fc0005fff4, 0x0000000820202020};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ef8000000000000, 0x7ef8000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x7ef8000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff000000ff};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x0000000000000000, 0x000000ff00000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffff0000, 0x00000000ffffffff};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x000000ffffff0000, 0x00000000ffffffff};
  __m128i_out = __lsx_vinsgr2vr_w((__m128)v2u64_op0, int_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  long_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_d((__m128)v2u64_op0, long_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffbfffffffbf, 0xffffffbfffffffbf};
  long_op1 = 0x0000000000003a24;
  __m128i_result = (__m128i){0x0000000000003a24, 0xffffffbfffffffbf};
  __m128i_out = __lsx_vinsgr2vr_d((__m128)v2u64_op0, long_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0001000100000000};
  long_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0001000100000000};
  __m128i_out = __lsx_vinsgr2vr_d((__m128)v2u64_op0, long_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  long_op1 = 0x0000000000000040;
  __m128i_result = (__m128i){0x0000000000000040, 0x0000000000000000};
  __m128i_out = __lsx_vinsgr2vr_d((__m128)v2u64_op0, long_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
