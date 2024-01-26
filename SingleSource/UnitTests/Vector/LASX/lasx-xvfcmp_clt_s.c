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

  v8i32_op0 = (v8i32){0x00000000, 0xff49fe42, 0xfee5fe22, 0xfe02fe02,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x0000dfff, 0x0000f328, 0x0000ffff, 0xffffffff,
                      0x00007f79, 0x00004686, 0x0000ff80, 0x0000ffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x01000000,
                      0x00000000, 0x00000000, 0x00000000, 0x01000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffff00000000,
                             0x0000000000000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000002, 0x00000007, 0xfffffffd, 0xffffffa4,
                      0x00000104, 0x00000815, 0xfffffdf8, 0xffff80cb};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffff0000, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x87870000, 0x00003f3f, 0x00000000, 0x00000000,
                      0xc6c68787, 0x00003f3f, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000002, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffff00000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x0101ffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0x0101ffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x01000100, 0x01000100, 0x01000100, 0x01000100,
                      0x01000100, 0x01000100, 0x01000100, 0x01000100};
  v8i32_op1 = (v8i32){0x7fc00000, 0x62d2acee, 0x7f800000, 0x7f800000,
                      0x7fc00000, 0x62d2acee, 0x7f800000, 0x7f800000};
  __m256i_result = (__m256i){0xffffffff00000000, 0xffffffffffffffff,
                             0xffffffff00000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ff01, 0x00000000, 0x00ff0000, 0x0000ff01,
                      0x0000ff01, 0x00000000, 0x00ff0000, 0x0000ff01};
  v8i32_op1 = (v8i32){0x00000808, 0x00000808, 0x00000000, 0x00000000,
                      0x00000808, 0x00000808, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffff00000000, 0x0000000000000000,
                             0xffffffff00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x80ffffff, 0x7efefefe, 0x00000000, 0x00000000,
                      0x80ffffff, 0x7efefefe, 0xffff8000, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0000000000000000,
                      0x0001000100010001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x000000000000007f,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x0000383fffffdf0d, 0xf800d0d8ffffeecf,
                      0x0000383fffffdf0d, 0xf800d0d8ffffeecf};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fefffffffffffff, 0x7fefffffffffffff,
                      0x7fefffffffffffff, 0x7fefffffffffffff};
  v4u64_op1 = (v4u64){0x7fefffffffffffff, 0x7fefffffffffffff,
                      0x7fefffffffffffff, 0x7fefffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001ffffe00200000, 0x0000000000000000,
                      0x001ffffe00200000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_clt_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00001680, 0x00002282, 0x0001fe9c, 0x0001ffe8,
                      0x00007bb6, 0x00007168, 0x0000040e, 0x0001ffaa};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfefefeab, 0x55555501, 0x01010101, 0x00000000,
                      0xfefefeab, 0x55555501, 0x01010101, 0x00000000};
  v8i32_op1 = (v8i32){0x000000fe, 0xffffff02, 0xfffffefb, 0x00000105,
                      0x000000fe, 0xffffff02, 0xfffffefb, 0x00000105};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000080, 0x00000000, 0x00000000, 0x00000000,
                      0x00000080, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0xffffffff, 0xffffffff, 0x00000000,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0xffffffff00000000, 0x00000000ffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000fc7c, 0x00000000, 0x0000ffce, 0x00000000,
                      0x0000fc7c, 0x00000000, 0x0000ffce, 0x00000000};
  v8i32_op1 = (v8i32){0xe7e7e7e7, 0xe7e7e7e7, 0xe7e7e7e7, 0xe7e7e7e7,
                      0xe7e7e7e7, 0xe7e7e7e7, 0xe7e7e7e7, 0xe7e7e7e7};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000,
                      0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000,
                      0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x0007a861, 0xffffffff, 0xffffffff, 0xffffffff,
                      0x0007a861, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0xffffffff, 0x00000000, 0xffffffff,
                      0x00000000, 0xffffffff, 0x00000000, 0xffffffff};
  v8i32_op1 = (v8i32){0x00100010, 0x00100010, 0x00100010, 0x00000000,
                      0x00100010, 0x00100010, 0x00100010, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000001, 0x01010101, 0x01010101, 0x01010101,
                      0x00000001, 0x01010101, 0x01010101, 0x01010101};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x01e001e0, 0x000001e0,
                      0x00000000, 0x00000000, 0x01e001e0, 0x000001e0};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffffffff,
                             0x0000000000000000, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cult_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101000001010000, 0x0008000001010000,
                      0x2020000020200000, 0x2020000020200000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff00000000,
                      0x0000ffff00000000, 0x0000ffff00000000};
  v4u64_op1 = (v4u64){0x0000ffff00000000, 0x0000ffff00000000,
                      0x0000ffff00000000, 0x0000ffff00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0xffffffff00000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff1000000000000, 0x0000000000000000,
                      0xfff1000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfffefffefffefffe, 0xfffefffefffefffe,
                      0xfffefffefffefffe, 0xfffefffefffefffe};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cult_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
