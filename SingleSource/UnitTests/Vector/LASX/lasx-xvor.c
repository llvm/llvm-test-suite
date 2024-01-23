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

  v4u64_op0 = (v4u64){0x00007fff7fff7fff, 0x7fff01fd7fff7fff,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00007fff7fff7fff, 0x7fff01fd7fff7fff,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00007fff7fff7fff, 0x7fff01fd7fff7fff,
                             0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000005e02, 0x0000000000000000,
                      0x0000000000005e02, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000005e02, 0x0000000000000000,
                             0x0000000000005e02, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000089, 0x0000000002a54290,
                      0x000000000154dc84, 0x0000000002a54290};
  __m256i_result = (__m256i){0x0000000000000089, 0x0000000002a54290,
                             0x000000000154dc84, 0x0000000002a54290};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x7fefffffffffffff, 0x7fefffffffffffff,
                      0x7fefffffffffffff, 0x7fefffffffffffff};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                      0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  v4u64_op1 = (v4u64){0x0000001e0007ffff, 0x0000001e0007ffff,
                      0x0000001e0007ffff, 0x0000001e0007ffff};
  __m256i_result = (__m256i){0x7fff7fff7fffffff, 0x7fe37fff001fffff,
                             0x7fff7fff7fffffff, 0x7fe37fff001fffff};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x003f60041f636003, 0x0000000000000000,
                      0x003f60041f636003, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x003f60041f636003, 0x0000000000000000,
                      0x003f60041f636003, 0x0000000000000000};
  __m256i_result = (__m256i){0x003f60041f636003, 0x0000000000000000,
                             0x003f60041f636003, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1,
                      0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1};
  __m256i_result = (__m256i){0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1,
                             0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000200,
                             0x0000000000000100, 0x0000000000000200};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000000,
                      0x0000000000000100, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000000,
                             0x0000000000000100, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                             0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff800000ff, 0x8000800080008000,
                      0x000000ff800000ff, 0x8000800080008000};
  v4u64_op1 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  __m256i_result = (__m256i){0x800080ff800080ff, 0x8000800080008000,
                             0x800080ff800080ff, 0x8000800080008000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fff80007fff0000, 0x0000000000000000,
                      0x7fff80007fff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff80007fff0000, 0x0000000000000000,
                             0x7fff80007fff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
