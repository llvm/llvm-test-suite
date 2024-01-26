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
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0xe17fe003, 0xffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0x0000ffff, 0xffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00190019, 0x00190819, 0x00190019, 0x00190819};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000001, 0xfe800000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xc6bb97ac, 0x7fffffff, 0x82bb9784, 0x7fffffff};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffff00000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x7f3f0180, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x7fd03f7f, 0xa2321469, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x0202fe02, 0x02020202, 0x00000406, 0x00000406};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xfffffff5, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000014, 0x00000000, 0x00000014, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0xfffc0004, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0xffffffff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xed3f2000, 0xc8847ef6, 0xb2ebb001, 0x67eb85b0};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xe67b8fc0, 0x09b50da6, 0x682de060, 0x0002de46};
  v4i32_op1 = (v4i32){0x24170000, 0x00000000, 0x084d12ce, 0x00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00ffffff, 0x00ffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x54860000, 0x0000fd16, 0x23560000, 0x0000feff};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffff784, 0xfffffffe, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x011ff8bc, 0x00000000, 0xfffffff0, 0x0177fff0};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000000000000, 0x0002000000000000};
  v2u64_op1 = (v2u64){0x00ff00ff00ff00fe, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffe5, 0xffffffffffffffe5};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fff7fff, 0x7fff7fff7fff7fff};
  v2u64_op1 = (v2u64){0x00ff000000ff0000, 0xfffffffffffff800};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fff7ffe7fff3506, 0xfffebd06fffe820c};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7ffffffeffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00007fff00007fff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000029, 0x000000000000002f};
  v2u64_op1 = (v2u64){0x003dbe88077c78c1, 0x0000000000003a24};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001fffe0001fefc, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x0003000100010001, 0x0007000000050000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfcmp_sun_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
