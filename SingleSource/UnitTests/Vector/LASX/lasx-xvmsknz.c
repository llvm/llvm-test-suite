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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0020002000400040, 0x0020002000400040,
                      0x0020002000400040, 0x0020002000400040};
  __m256i_result = (__m256i){0x0000000000005555, 0x0000000000000000,
                             0x0000000000005555, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000300000002, 0x0002000000020000,
                      0x0000000300000002, 0x0002000000020000};
  __m256i_result = (__m256i){0x0000000000004411, 0x0000000000000000,
                             0x0000000000004411, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003f3f00004040, 0x0000000000000000,
                      0x00003f3f00004040, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000033, 0x0000000000000000,
                             0x0000000000000033, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100000100000001, 0x0000000008050501,
                      0x0100000100000001, 0x0000000008050501};
  __m256i_result = (__m256i){0x0000000000000f91, 0x0000000000000000,
                             0x0000000000000f91, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000430207f944, 0x0000000000000000,
                      0x000000430207f944, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000001f, 0x0000000000000000,
                             0x000000000000001f, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0060401900000000, 0x006018000000001a,
                      0x0060401900000000, 0x006018000000001a};
  __m256i_result = (__m256i){0x0000000000006170, 0x0000000000000000,
                             0x0000000000006170, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf2b180c9fc1fefdc, 0x0000000000000200,
                      0xf2b180c9fc1fefdc, 0x0000000000000200};
  __m256i_result = (__m256i){0x00000000000002ff, 0x0000000000000000,
                             0x00000000000002ff, 0x0000000000000000};
  __m256i_out = __lasx_xvmsknz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
