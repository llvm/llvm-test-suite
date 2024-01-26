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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0001000001000100, 0x0000000000010100,
                      0x0000000000000000, 0x0001010101010101};
  v4u64_op2 = (v4u64){0xffffffffe651bfff, 0xffffffffffffffff,
                      0xffffffffbf7f7fff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffe651bfff, 0xffffffffffffffff,
                         0xffffffffbf7f7fff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x3ff73ff83ff73ff8,
                      0x0000000000000000, 0x3ff73ff83ff73ff8};
  v4u64_op2 = (v4u64){0x2020202020206431, 0x2020202020202020,
                      0x2020202020206431, 0x2020202020202020};
  v4u64_result = (v4u64){0xa020202020206431, 0xa020202020202020,
                         0xa020202020206431, 0xa020202020202020};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                      0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  v4u64_op2 = (v4u64){0x7f7f7f5c8f374980, 0x0001b0b1b4b5dd9f,
                      0x7f7f7f5c8f374980, 0x0001b0b1b4b5dd9f};
  v4u64_result = (v4u64){0xffffffffffffffff, 0x8001b0b1b4b5dd9f,
                         0xffffffffffffffff, 0x8001b0b1b4b5dd9f};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff21ff21ff21ff21, 0xff21ff21ff21ff21,
                      0xff21ff21ff21ff21, 0xff21ff21ff21ff21};
  v4u64_op1 = (v4u64){0xff21c241ff21c241, 0xff21c241ff21c241,
                      0xff21c241ff21c241, 0xff21c241ff21c241};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x0000000000000040,
                      0x0000000000000007, 0x0000000000000040};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000000000000000,
                      0x0000ffff0000ffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x8000000000000000,
                         0x8000000000000000, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1080108010060002, 0x0000000000000000,
                      0x1080108010060002, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffe4ffffffe4, 0xffffffe4ffffffe4,
                      0xffffffe4ffffffe4, 0xffffffe4ffffffe4};
  v4u64_op2 = (v4u64){0x7fff00017fff0000, 0x7fff00017fff0000,
                      0x7fff00017fff0000, 0x7fff00017fff0000};
  v4u64_result = (v4u64){0x7fff00017fff0000, 0x7fff00017fff0000,
                         0x7fff00017fff0000, 0x7fff00017fff0000};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1716151417161514, 0x1716151417161514,
                      0x1716151417161514, 0x1716151417161514};
  v4u64_op1 = (v4u64){0x0000000000002780, 0x0000000000000000,
                      0x0000000000002780, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000002780, 0x0000000000000000,
                      0x0000000000002780, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000002780, 0x8000000000000000,
                         0x8000000000002780, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0080200000802000,
                      0xffffffffffffffff, 0x0080200000802000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0080200000802000,
                      0xffffffffffffffff, 0x0080200000802000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffffffff, 0x8000000000000000,
                         0xffffffffffffffff, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x8000000000000000,
                         0x8000000000000000, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  v4u64_op1 = (v4u64){0xffffffffffba0c05, 0x0000000000000000,
                      0xffffffffffba0c05, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000483800,
                      0x0000000000000000, 0x0000000000483800};
  v4u64_result = (v4u64){0xffffffffffba0c05, 0x0000000000483800,
                         0xffffffffffba0c05, 0x0000000000483800};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fffffff, 0x0000000000000000,
                      0x000000007fffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x8000000000000000,
                         0x8000000000000000, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000005000000020, 0x0000000000000000,
                      0x0000005000000020, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000005000000020, 0x0000000000000000,
                      0x0000005000000020, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000005000000020, 0x0000000000000000,
                      0x0000005000000020, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000005000000020, 0x8000000000000000,
                         0x0000005000000020, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0008000000000000, 0x0010000000000000,
                      0x0008000000000000, 0x0010000000000000};
  v4u64_result = (v4u64){0x0008000000000000, 0x0010000000000000,
                         0x0008000000000000, 0x0010000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0d0d0d0d0d0d0d0d, 0xff0d0d0d0d0d0d0d,
                      0x0d0d0d0d0d0d0d0d, 0xff0d0d0d0d0d0d0d};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x0000000000000000,
                         0x8000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                      0xffffffffe0000000, 0xffffffffe0000000};
  v4u64_op1 = (v4u64){0xffff800300000000, 0xffff801000000010,
                      0xffff800300000000, 0xffff801000000010};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                         0xffffffffe0000000, 0xffffffffe0000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffce, 0x0000000000000000,
                      0x00000000ffffffce, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000700000000, 0x00000005ffffffff,
                      0x0000000700000000, 0x00000005ffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x8000000000000000,
                         0x8000000000000000, 0x8000000000000000};
  __m256d_out = __lasx_xvfnmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
