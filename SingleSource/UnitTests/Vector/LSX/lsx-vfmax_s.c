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

  v4i32_op0 = (v4i32){0x00000000, 0x0000ffff, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x0000ffff, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x3ef4be3a, 0x460f3b39, 0xb019323f, 0xc2409eda};
  v4i32_result = (v4i32){0x3ef4be3a, 0x460f3b39, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000001, 0x00000000, 0x00000001, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000001, 0x00000000, 0x00000001, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xba6f5543, 0xdffdbffe, 0x7f7f7f7e, 0xfefd7f7f};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x7f7f7f7e, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffffff0, 0xffffffff, 0xff84fff4, 0xff84fff4};
  v4i32_op1 = (v4i32){0xfffffff0, 0xffffffff, 0xff84fff4, 0xff84fff4};
  v4i32_result = (v4i32){0xfffffff0, 0xffffffff, 0xffc4fff4, 0xffc4fff4};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00007fff, 0x00007fff};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00007fff, 0x00007fff};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0xffffffff};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000001, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000001, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x01010001, 0x01010001, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00020000, 0x00000000, 0x00020000, 0x00000000};
  v4i32_result = (v4i32){0x01010001, 0x01010001, 0x00020000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x0000001f, 0x0000001f, 0x00000020, 0x00000020};
  v4i32_result = (v4i32){0x0000001f, 0x0000001f, 0x00000020, 0x00000020};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0xf3040705, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0xf3040705, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0xf3040705, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000004, 0x00000000, 0x00000004, 0x00000000};
  v4i32_op1 = (v4i32){0x00000004, 0x00000000, 0x00000004, 0x00000000};
  v4i32_result = (v4i32){0x00000004, 0x00000000, 0x00000004, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmax_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000fffe, 0x0000ffff, 0x0000ffff, 0x0000ffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffe5, 0xffffffff, 0xffffffe5, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x100f0e0d, 0x11100f0e, 0x1211100f, 0x13121110};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffffff3, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00000088, 0x00000000, 0x00000008, 0x00000000};
  v4i32_result = (v4i32){0x00000088, 0x00000000, 0x00000008, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xadadadad, 0x52525252, 0xadadadad, 0x52525252};
  v4i32_op1 = (v4i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  v4i32_result = (v4i32){0xadadadad, 0x00000000, 0xadadadad, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000ffff, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x0000ffff, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x0000ffff, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmin_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
