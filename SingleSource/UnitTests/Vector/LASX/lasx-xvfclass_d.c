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

  v4u64_op0 = (v4u64){0x0000017f0000017f, 0x0000000000010001,
                      0x0000017f0000017d, 0x0000000000010001};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000100,
                             0x0000000000000100, 0x0000000000000100};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000002, 0x0000000000000002};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000200, 0x0000000000000200,
                             0x0000000000000200, 0x0000000000000200};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000100,
                             0x0000000000000100, 0x0000000000000100};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00,
                      0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00000000000000, 0xffffff00ffffff00,
                      0xff00000000000000, 0xffffff00ffffff00};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000002,
                             0x0000000000000008, 0x0000000000000002};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000002, 0x0000000000000002};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffff0001, 0x0000000000000000,
                      0x00000000ffff0001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000200,
                             0x0000000000000100, 0x0000000000000200};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000200,
                             0x0000000000000002, 0x0000000000000200};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000100,
                      0x0000000000000001, 0x0000000000000100};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000100,
                             0x0000000000000100, 0x0000000000000100};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000200, 0x0000000000000200,
                             0x0000000000000200, 0x0000000000000200};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffefff80, 0x00000000000000b7,
                      0xffffffffffefff80, 0x00000000000000b7};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000100,
                             0x0000000000000002, 0x0000000000000100};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4040404040404040, 0xffffffffffffffff,
                      0x4040404040404040, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000080, 0x0000000000000002,
                             0x0000000000000080, 0x0000000000000002};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000200, 0x0000000000000200,
                             0x0000000000000200, 0x0000000000000200};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000400000004000, 0x0000400000004000,
                      0x0000400000004000, 0x0000400000004000};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000100,
                             0x0000000000000100, 0x0000000000000100};
  __m256i_out = __lasx_xvfclass_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
