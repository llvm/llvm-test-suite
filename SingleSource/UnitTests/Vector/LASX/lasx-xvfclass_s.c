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

  v8i32_op0 = (v8i32){0x00ffcff8, 0x00ff00f8, 0xffffff08, 0xfffffff8,
                      0x00ffcff8, 0x00ff00f8, 0xffffff08, 0xfffffff8};
  __m256i_result = (__m256i){0x0000008000000080, 0x0000000200000002,
                             0x0000008000000080, 0x0000000200000002};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000200000002, 0x0000000200000002,
                             0x0000000200000002, 0x0000000200000002};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000020000000200, 0x0000020000000200,
                             0x0000020000000200, 0x0000020000000200};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x000000ff, 0x000000ff, 0x00000000, 0x00000000,
                      0x000000ff, 0x000000ff, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000010000000100, 0x0000020000000200,
                             0x0000010000000100, 0x0000020000000200};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb,
                      0xfffffffb, 0xfffffffb, 0xfffffffb, 0xfffffffb};
  __m256i_result = (__m256i){0x0000000200000002, 0x0000000200000002,
                             0x0000000200000002, 0x0000000200000002};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000020000000200, 0x0000020000000200,
                             0x0000020000000200, 0x0000020000000200};
  __m256i_out = __lasx_xvfclass_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
