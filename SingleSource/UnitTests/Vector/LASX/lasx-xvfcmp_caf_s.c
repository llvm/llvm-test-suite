#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xff01ff01, 0xff56ff55, 0x00000000, 0x00000000,
                      0xff01ff01, 0xff56ff55, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x0000abff, 0x0000abff, 0x00000000, 0x00000000,
                      0x0000abff, 0x0000abff, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000000a, 0x00000001, 0x00000000, 0x00000000,
                      0x0000000a, 0x00000001, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000040, 0x00000000, 0x00000000, 0x00000000,
                      0x00000040, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1,
                      0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x0003ffff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0xffff8000, 0x00000000, 0xffff8000,
                      0x00000000, 0xffff8000, 0x00000000, 0xffff8000};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff,
                      0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff,
                      0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff,
                      0x1f20607a, 0xe07de080, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000010, 0x00000000,
                      0x00000000, 0x00000000, 0x00000010, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0x00000000, 0x00000000, 0x00000000,
                      0xffffffff, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0xffffffff, 0x00000000, 0xffffffff,
                      0x00000000, 0xffffffff, 0x00000000, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xa5a5a5a5a5a99e03, 0xa5a5a5a5a5a5a5a5,
                      0xa5a5a5a5a5a99e03, 0xa5a5a5a5a5a5a5a5};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000d0005, 0x0000000000000045,
                      0x00000000000d0005, 0x0000000000000045};
  v4u64_op1 = (v4u64){0x00000000000d0005, 0x0000000000000045,
                      0x00000000000d0005, 0x0000000000000045};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x24342434ffff2435, 0xffffffffffffffff,
                      0x24342434ffff2435, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fe000000000, 0x0000000000000000,
                      0x00003fe000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000002,
                      0x0000000000000002, 0x0000000000000002};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000013, 0x0000000000000013,
                      0x0000000000000013, 0x0000000000000013};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97a1df5b41b0, 0xfffeb664007ffd61,
                      0xfffe97a1df5b41b0, 0xfffeb664007ffd61};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_caf_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
