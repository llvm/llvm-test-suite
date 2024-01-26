#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2, v4u64_result;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2, v8i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000015, 0x00000000, 0x00005555, 0x00005555,
                      0xfe72e815, 0x000307ff, 0x00005555, 0x00005555};
  v8i32_result = (v8i32){0x00000015, 0x00000000, 0x00005555, 0x00005555,
                         0xfe72e815, 0x000307ff, 0x00005555, 0x00005555};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00040000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
                      0x000c0000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00040000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff,
                         0x000c0000, 0x00ff00ff, 0x00ff00ff, 0x00ff00ff};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfffff800, 0x000007ff, 0x000007ff, 0x000007ff,
                      0xfffff800, 0x000007ff, 0x000007ff, 0x000007ff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff,
                      0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0x00000000, 0x000007ff, 0x000007ff, 0x000007ff,
                         0x00000000, 0x000007ff, 0x000007ff, 0x000007ff};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x1f1f1fff, 0x001f00e0, 0x00000001, 0x00000000,
                      0x1f1f1fff, 0x001f00e0, 0x00000001, 0x00000000};
  v8i32_op1 = (v8i32){0xff800000, 0x80000000, 0x80000000, 0x80000000,
                      0xff800000, 0x80000000, 0x80000000, 0x80000000};
  v8i32_result = (v8i32){0xff800000, 0x001f00e0, 0x00000001, 0x00000000,
                         0xff800000, 0x001f00e0, 0x00000001, 0x00000000};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000001, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000001, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000001, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff,
                      0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff};
  v8i32_op1 = (v8i32){0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683,
                      0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683};
  v8i32_result = (v8i32){0x20010001, 0x0000ffff, 0x9ffffd80, 0x00009fff,
                         0x20010001, 0x0000ffff, 0x9ffffd80, 0x00009fff};
  __m256_out = __lasx_xvfmaxa_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0055ffab, 0xc0650055, 0x00000080, 0x00000170,
                      0x0055ffab, 0xc0650055, 0x00000080, 0x00000170};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffff0000, 0x00000000, 0x00000000, 0x00000000,
                      0xffff0000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe,
                      0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe};
  v8i32_result = (v8i32){0xffff0000, 0x00000000, 0x00000000, 0x00000000,
                         0xffff0000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00c40086, 0x00000000, 0x00010000, 0x00fe01f0,
                      0x00c40086, 0x00000000, 0x00010000, 0x00fe01f0};
  v8i32_op1 = (v8i32){0x02a54287, 0x00000000, 0x82a54290, 0x00000000,
                      0x028aa700, 0x00000000, 0x82a54290, 0x00000000};
  v8i32_result = (v8i32){0x00c40086, 0x00000000, 0x00010000, 0x00000000,
                         0x00c40086, 0x00000000, 0x00010000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000089, 0x00000000, 0x02a54290, 0x00000000,
                      0x0154dc84, 0x00000000, 0x02a54290, 0x00000000};
  v8i32_op1 = (v8i32){0x00000089, 0x00000000, 0x02a54290, 0x00000000,
                      0x0154dc84, 0x00000000, 0x02a54290, 0x00000000};
  v8i32_result = (v8i32){0x00000089, 0x00000000, 0x02a54290, 0x00000000,
                         0x0154dc84, 0x00000000, 0x02a54290, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x04000000, 0x00000000,
                      0x00000000, 0x00000000, 0x04000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00100000, 0x00100000, 0x00100000, 0x00100000,
                      0x00100000, 0x00100000, 0x00100000, 0x00100000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000010, 0x00000000, 0x00000000, 0x00000000,
                      0x00000010, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000080, 0x00000080, 0x00000080, 0x00000080,
                      0x00000080, 0x00000080, 0x00000080, 0x00000080};
  v8i32_op1 = (v8i32){0x00000001, 0x00000001, 0x00000001, 0x00000001,
                      0x00000001, 0x00000001, 0x00000001, 0x00000001};
  v8i32_result = (v8i32){0x00000001, 0x00000001, 0x00000001, 0x00000001,
                         0x00000001, 0x00000001, 0x00000001, 0x00000001};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmina_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
