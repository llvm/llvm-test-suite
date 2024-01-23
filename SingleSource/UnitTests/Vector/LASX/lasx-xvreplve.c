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
  int_op1 = 0x000000000000ffff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000000000ffff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000012e2110, 0x0000000000000001,
                      0x0000000000000002, 0x0000000000000001};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x1010101010101010, 0x1010101010101010,
                             0x0202020202020202, 0x0202020202020202};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000003f0000, 0x0000000000000000,
                      0x00000000003f0000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffff7fffff, 0x0000000000000000,
                      0x7fffffffff7fffff, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffff00ffffffff, 0x0000000000000000,
                      0xffffff00ffffffff, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00000000000000ff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000003fff, 0x0000000000003fff,
                      0x0000000000003fff, 0x0000000000003fff};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000040, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x4040404040404040, 0x4040404040404040,
                             0x4040404040404040, 0x4040404040404040};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000404, 0x0000000001010101,
                      0x0000000000000404, 0x0000000001010101};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0404040404040404, 0x0404040404040404,
                             0x0404040404040404, 0x0404040404040404};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000200000002, 0x0000000200000002,
                      0x0000000200000002, 0x0000000200000002};
  int_op1 = 0xffffffff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_b((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x3c4c0a5c;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  int_op1 = 0x0000000000000400;
__m256i_result = (__m256i){0x003f003f003f003f, 0x003f003f003f003f,
                             0x003f003f003f003f, 0x003f003f003f003f};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000400;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ffffff00ffff, 0xff00d5007f00ffff,
                      0xff00ffffff00ffff, 0xff00d5007f00ffff};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc192181230000000, 0xbff0000000000000,
                      0xc192181230000000, 0xbff0000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fefffffffffffff,
                      0x0000000000000000, 0x7fefffffffffffff};
  int_op1 = 0x00000000ffffffff;
__m256i_result = (__m256i){0x7fef7fef7fef7fef, 0x7fef7fef7fef7fef,
                             0x7fef7fef7fef7fef, 0x7fef7fef7fef7fef};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                      0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f010700c70106, 0x0000000000000000,
                      0x007f010700c70106, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0106010601060106, 0x0106010601060106,
                             0x0106010601060106, 0x0106010601060106};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_h((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x003f003f003f003f, 0x003f003f003f003f,
                      0x003f003f003f003f, 0x003f003f003f003f};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x003f003f003f003f, 0x003f003f003f003f,
                             0x003f003f003f003f, 0x003f003f003f003f};
  __m256i_out = __lasx_xvreplve_w((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_w((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000020202020, 0x0000000020202020,
                      0x0000000020202020, 0x0000000020202020};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x2020202020202020, 0x2020202020202020,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvreplve_w((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvreplve_w((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000fe, 0xfffffffffffffefb,
                      0x00000000000000fe, 0xfffffffffffffefb};
  int_op1 = 0x0000000059815d00;
__m256i_result = (__m256i){0x00000000000000fe, 0x00000000000000fe,
                             0x00000000000000fe, 0x00000000000000fe};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x555555ab555555ab, 0x555555ab555555ab,
                      0x555555ab555555ab, 0x555555ab555555ab};
  int_op1 = 0x000000000000ffff;
__m256i_result = (__m256i){0x555555ab555555ab, 0x555555ab555555ab,
                             0x555555ab555555ab, 0x555555ab555555ab};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe161616161614e60, 0xe161616161616161,
                      0xe161616161614e60, 0xe161616161616161};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xe161616161614e60, 0xe161616161614e60,
                             0xe161616161614e60, 0xe161616161614e60};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000080,
                      0x0000000000000080, 0x0000000000000080};
  int_op1 = 0x00000000000000ac;
__m256i_result = (__m256i){0x0000000000000080, 0x0000000000000080,
                             0x0000000000000080, 0x0000000000000080};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0xffffffff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000ff00ff, 0x0000000000000000,
                      0x0000000000ff00ff, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000ff00ff, 0x0000000000ff00ff,
                             0x0000000000ff00ff, 0x0000000000ff00ff};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000202, 0x0000000000800080,
                      0x0000000000000202, 0x0000000000800080};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000202, 0x0000000000000202,
                             0x0000000000000202, 0x0000000000000202};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000003ddc5dac;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvreplve_d((__m256)v4u64_op0, int_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
