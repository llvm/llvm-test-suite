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
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000040404240, 0x0000000040404040,
                      0x0000000040404240, 0x0000000040404040};
  v4u64_op1 = (v4u64){0x0000000040404240, 0x0000000040404040,
                      0x0000000040404240, 0x0000000040404040};
  __m256i_result = (__m256i){0x00007f7f00007f7f, 0x00007f7f00007f7f,
                             0x00007f7f00007f7f, 0x00007f7f00007f7f};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fff7fff, 0x000000007fff7fff,
                      0x000000007fff7fff, 0x000000007fff7fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00007f7f00007f7f,
                             0x0000000000000000, 0x00007f7f00007f7f};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff56ff55ff01ff01, 0x0000000000000000,
                      0xff56ff55ff01ff01, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007f7f7f7f, 0x0000000000000000,
                             0x000000007f7f7f7f, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xa90896a400000000,
                      0x0000000000000000, 0xa90896a400000000};
  v4u64_op1 = (v4u64){0xffff47b4ffff5879, 0x0000504fffff3271,
                      0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_result = (__m256i){0x007f7f7f7f7f7f7f, 0x7f7f000000000000,
                             0x007f7f7f7f7f7f7f, 0x7f7f000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x00001fff200007ef, 0x0000000000000000,
                      0x1f001f00000007ef, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000030400, 0x0000001f0000001f,
                             0x0000000003030000, 0x0000001f0000001f};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff81001dff9d003b, 0xff81001dff9dff9e,
                      0xff81001dff9d003b, 0xff81001dff9dff9e};
  v4u64_op1 = (v4u64){0x0002000200010002, 0x0002000200010002,
                      0x0002000200010002, 0x0002000200010002};
  __m256i_result = (__m256i){0x0202010202020102, 0x7f1d7f7f7f1d7f3b,
                             0x0202010202020102, 0x7f1d7f7f7f1d7f3b};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000cfffffff3, 0x0000000dfffffff1,
                      0x0000000cfffffff3, 0x0000000dfffffff1};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00003f3f00003f3f,
                             0x0000000000000000, 0x00003f3f00003f3f};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3f28306860663e60, 0x7f7f7f7f00007f7f,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x40d74f979f99419f, 0x00000000ffff0000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00007fff7fff7fff, 0x7fff01fd7fff7fff,
                             0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100044411, 0x0001000100010001,
                      0x00010001000c4411, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x0000002800000010, 0x0000000000000000,
                      0x0000002800000010, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0002000200020008,
                             0x0000000000000000, 0x0002000200020018};
  __m256i_out = __lasx_xvssrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0018001800180018, 0x0018001800180018,
                      0x0018001800180018, 0x0018001800180018};
  __m256i_result = (__m256i){0x3000300030003000, 0x0000000000000000,
                             0x3000300030003000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000e3ab0001352b, 0x0000000000000001,
                      0x0000e3ab0001352b, 0x0000000000000001};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0x7fff00007fff0000, 0x0000000038ea4d4a,
                             0x7fff00007fff0000, 0x0000000038ea4d4a};
  __m256i_out = __lasx_xvssrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_result = (__m256i){0x0383634303836343, 0x1fffffff1fffffff,
                             0x0383634303836343, 0x1fffffff1fffffff};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000003f0, 0x0000000000000000,
                      0x00000000000003f0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x30);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000fe000000ffe0, 0x0000fffc0000fee0,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffff900000003, 0x0000000000000002,
                      0xfffffff900000003, 0x0000000000000002};
  __m256i_result = (__m256i){0x000000007fffffff, 0x7ffe00007f000000,
                             0x000000007fffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffffffffffe, 0xfffffffffffffffe};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffffffffffe, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x00003fff00003fff, 0x00003fff00003fff,
                             0x00003fff00003fff, 0x00003fff00003fff};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x32);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff80017fff, 0x0000000000000000,
                      0xffffffff80017fff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fffffff, 0x000000007fffffff,
                             0x000000007fffffff, 0x000000007fffffff};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfffffebeeaaeeeeb, 0xfffffebeeaaefafb,
                      0xfffffebeeaaeeeeb, 0xfffffebeeaaefafb};
  __m256i_result = (__m256i){0x7fffffff7fffffff, 0x7fffffff7fffffff,
                             0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fefffffffffffff,
                      0x0000000000000000, 0x7fefffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x03ffffff03ffffff, 0x01ffbfff00000000,
                             0x03ffffff03ffffff, 0x01ffbfff00000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x26);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x01fe01fe01fe01fe, 0x01fe01fe01fe01fe,
                      0x01fe01fe01fe01fe, 0x01fe01fe01fe01fe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fffffff7fffffff,
                             0x0000000000000000, 0x7fffffff7fffffff};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000080c000c080, 0x4000c08000000080,
                      0x00000080c000c080, 0x4000c08000000080};
  v4u64_op1 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000004000, 0x0000200000000000,
                             0x0000000000004000, 0x0000200000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x31);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000010006d, 0x0000000000080040,
                      0x000000000010006d, 0x0000000000080040};
  __m256i_result = (__m256i){0x0000004000000080, 0x0000000000000000,
                             0x0000004000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000118, 0x0000000000000000,
                      0x0000000000000118, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001000000, 0x0000000001000000,
                      0x0000000001000000, 0x0000000001000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x0000000000000000,
                             0x7fffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000002,
                      0x0000000000000000, 0x0000000000000002};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000800000, 0x0000000002000000,
                             0x0000000000800000, 0x0000000002000000};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x28);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x61);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000a800b000a800b, 0x0003800400038004,
                      0x000a800b000a800b, 0x0003800400038004};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000e0010000e,
                             0x0000000000000000, 0x0000000e0010000e};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000598,
                      0x0000000000000000, 0x0000000000000598};
  __m256i_result = (__m256i){0x0000000002cc0000, 0x7fffffffffffffff,
                             0x0000000002cc0000, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x31);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000a400ff004f, 0x000000010000005e,
                      0x000000a400ff004f, 0x000000010000005e};
  v4u64_op1 = (v4u64){0x000000a400ff004f, 0x000000010000005e,
                      0x000000a400ff004f, 0x000000010000005e};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x001fffffffe00011,
                      0x7fffffffffffffff, 0x001fffffffe00011};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x7fffffffffffffff,
                      0x0000000000000000, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf777777777777777, 0x77777777f7777777,
                      0xf777777777777777, 0x77777777f7777777};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000040000000, 0x0000ffffffffffff,
                      0x00000000c0000000, 0x0000ffffffffffff};
  v4u64_op1 = (v4u64){0x0000000040000000, 0x0000ffffffffffff,
                      0x00000000c0000000, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0x0003030300000100, 0x0003030300000100,
                             0x0003030300000300, 0x0003030300000300};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80000000ff810011, 0x0000000000000000,
                      0x80000000ff810011, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff8180ffff8181, 0x0000000100000001,
                      0xffff8180ffff8181, 0x0000000100000001};
  __m256i_result = (__m256i){0x00000000ff81ff81, 0x000000008000ff00,
                             0x00000000ff81ff81, 0x000000008000ff00};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007000008e700000, 0x0000000000000000,
                      0x007000008e700000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8e8e8e8e8f00ffff, 0x7171717171010101,
                      0x8e8e8e8e8f00ffff, 0x7171717171010101};
  __m256i_result = (__m256i){0xe2e2e202ffffffff, 0x000000000000ff00,
                             0xe2e2e202ffffffff, 0x000000000000ff00};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0707070707070707,
                             0x0000000000000000, 0x0707070707070707};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000101, 0x0000000000000000,
                      0x0000000000000101, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x0000000000000000,
                      0x0101010101010101, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000010000005e, 0x0000000000000000,
                      0x000000010000005e, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000030000fff3, 0x0000000000000000,
                      0x0000bf6e0000c916, 0x0000000800000004};
  v4u64_op1 = (v4u64){0xfffff8d9ffa7103d, 0x0000000000000000,
                      0xff8f0842ff29211e, 0x001175f10e4330e8};
  __m256i_result = (__m256i){0x0000000000ff00ff, 0x0000000000000000,
                             0x0000000e00ff00ff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffff00000000,
                      0x0000000000000000, 0xffffffff00000000};
  v4u64_op1 = (v4u64){0x6aeaeaeaeaeaeaea, 0xebebebebebebebeb,
                      0x6aeaeaeaeaeaeaea, 0xebebebebebebebeb};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffff000000000000,
                             0xffffffffffffffff, 0xffff000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000000007fffffff, 0x7ffe00007f000000,
                      0x000000007fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffff0000ffff, 0xffffffff00000000,
                             0x000000000000ffff, 0xffffffff00000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f00ff00000000, 0x0000000000000000,
                      0x007f000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0007fff8000ffff0, 0x0000000000000000,
                      0x0007fff8000ffff0, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000030007, 0x00000000003f0000,
                             0x0000000000030007, 0x00000000003f0000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x001f001f001f001f, 0x0000000000000000,
                             0x001f001f001f001f, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8800c800c800c801, 0xc800c800c800c800,
                      0x8800c800c800c801, 0xc800c800c800c800};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xe07de0801f20607a, 0xffffffffffffffff,
                      0xe07de0801f20607a, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x01ff01ff01c0003e, 0x0000000000000000,
                             0x01ff01ff01c0003e, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff80fffffffffffe, 0x007efffefffefffe,
                      0xff80fffffffffffe, 0x007efffefffefffe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x0000000000000000,
                      0x8000000080000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffffffff,
                             0x0000000000000000, 0x00000000ffffffff};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0036003200360032, 0x0036003200360032,
                      0x0036003200360032, 0x0036003200360032};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000004000, 0x7f80780000000000,
                      0x0000000000004000, 0x7f80780000000000};
  __m256i_result = (__m256i){0xffffffff00001000, 0x0000000000000000,
                             0xffffffff00001000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ff24, 0x0000000000000000,
                      0x000000000000ff24, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000003, 0x0000000000000000,
                             0x0000000000000003, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x38);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x35);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffe0ffe0ffe0ffe0, 0xffe0ffe0ffe0ffe0,
                      0xffe0ffe0ffe0ffe0, 0xffe0ffe0ffe0ffe0};
  v4u64_op1 = (v4u64){0x1e18000000000000, 0x1e1800001e180000,
                      0x1e18000000000000, 0x1e1800001e180000};
  __m256i_result = (__m256i){0x0000000000001e18, 0x000000000000ffe0,
                             0x0000000000001e18, 0x000000000000ffe0};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x70);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000401000000, 0x0000000401000000,
                      0x0000000401000000, 0x0000000401000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x68);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe0801f41e0800168, 0x0000000000000000,
                      0xe17cec8fe08008ac, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xb2c0b341807f8006, 0xb2c0b341807f8006,
                      0x9240f24a84b18025, 0x9240f24a84b18025};
  __m256i_result = (__m256i){0x0000001658166830, 0x0000000000000000,
                             0x00000012481e4950, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7f807f007f7f817f, 0x000000007f7f817f,
                      0x7f807f007f7f817f, 0x000000007f7f817f};
  v4u64_op1 = (v4u64){0x3fc03f803fc040c0, 0x4ffc3f783fc040c0,
                      0x3fc03f803fc040c0, 0x4ffc3f783fc040c0};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0003fbfc0bfbfc03,
                             0xffffffffffffffff, 0x0003fbfc0bfbfc03};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  v4u64_op1 = (v4u64){0x000000007fffffff, 0x000000007fffffff,
                      0x000000007fffffff, 0x000000007fffffff};
  __m256i_result = (__m256i){0xfffffffe00000000, 0xffffffffffffffff,
                             0xfffffffe00000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000100, 0x0000000000000100,
                      0x0000000000000100, 0x0000000000000100};
  __m256i_result = (__m256i){0x0200000000000000, 0x0000000000000000,
                             0x0200000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
