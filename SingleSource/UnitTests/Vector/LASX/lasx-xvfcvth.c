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

  v4u64_op0 = (v4u64){0xf000000000000000, 0xf001000100010001,
                      0xf000000000000000, 0xf001000100010001};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0xc6000000,
                         0x00000000, 0x00000000, 0x00000000, 0xc6000000};
  __m256_out = __lasx_xvfcvtl_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00010000002fff9e, 0x0000fffeffb9ff9d,
                      0x0002ff80ffb70000, 0xc080ffff0049ffd2};
  v8i32_result = (v8i32){0xfff3c000, 0x363c0000, 0x00000000, 0x33800000,
                         0x00000000, 0xfff6e000, 0xfff00000, 0x34000000};
  __m256_out = __lasx_xvfcvtl_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvtl_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc1d75053f0000000, 0x41dfffffffc00000,
                      0xc1d75053f0000000, 0x41dfffffffc00000};
  v8i32_result = (v8i32){0x00000000, 0xc6000000, 0x420a6000, 0xc03ae000,
                         0x00000000, 0xc6000000, 0x420a6000, 0xc03ae000};
  __m256_out = __lasx_xvfcvtl_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x03802fc000000000, 0x0000000000000000,
                      0x03802fc000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x3df80000, 0x38600000,
                         0x00000000, 0x00000000, 0x3df80000, 0x38600000};
  __m256_out = __lasx_xvfcvtl_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0408010008080808, 0x0404010008080808,
                      0x0408010008080808, 0x0404010008080808};
  v8i32_result = (v8i32){0x39010000, 0x39010000, 0x37800000, 0x38808000,
                         0x39010000, 0x39010000, 0x37800000, 0x38808000};
  __m256_out = __lasx_xvfcvth_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvth_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvth_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000100010001fffe, 0x8000800080008000,
                      0x000100010001fffe, 0x8000800080008000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfcvth_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvth_s_h((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4u64_result = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                         0xffffffffe0000000, 0xffffffffe0000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xff800000, 0x80000000, 0x80000000, 0x80000000,
                      0xff800000, 0x80000000, 0x80000000, 0x80000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0x8000000000000000,
                         0xfff0000000000000, 0x8000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                         0xffffffffe0000000, 0xffffffffe0000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvtl_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000aaaa, 0x0000aaaa, 0x00008bfe, 0x0000aaaa,
                      0x0000aaaa, 0x0000aaaa, 0x00008bfe, 0x0000aaaa};
  v4u64_result = (v4u64){0x37917fc000000000, 0x3795554000000000,
                         0x37917fc000000000, 0x3795554000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff,
                      0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  v4u64_result = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                         0xffffffffe0000000, 0xffffffffe0000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00020006, 0x00000000, 0x00020006, 0x00000000,
                      0x00020006, 0x00000000, 0x00020006, 0x00000000};
  v4u64_result = (v4u64){0x37b0003000000000, 0x0000000000000000,
                         0x37b0003000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfffffff0, 0xfffffff0, 0xfffffff0, 0xfffffff0,
                      0xfffffff0, 0xfffffff0, 0xfffffff0, 0xfffffff0};
  v4u64_result = (v4u64){0xfffffffe00000000, 0xfffffffe00000000,
                         0xfffffffe00000000, 0xfffffffe00000000};
  __m256d_out = __lasx_xvfcvth_d_s((__m256)v8i32_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
