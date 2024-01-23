#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0xfffc45a851c40c18, 0xfff489b693120950};
  __m128i_result = (__m128i){0xe0dd268932a5edf9, 0xe0d56a9774f3ea31};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff88, 0x0000000000000000};
  __m128i_result = (__m128i){0xe5e5e5e5e4e4e46d, 0xe5e5e5e5e5e5e5e5};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000408, 0x0000000897957687};
  __m128i_result = (__m128i){0xf7f7f7f7f7f7fbff, 0xf7f7f7ff8e8c6d7e};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xe6e6e6e6e6e6e6e6, 0xe6e6e6e6e6e6e6e6};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x2e34594c3b000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x171d423524e9e9e9, 0xe9e9e9e9e9e9e9e9};
  __m128i_out = __lsx_vsubi_bu((__m128)v2u64_op0, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffe2ffe2ffe2ffe2, 0xffe2ffe2ffe2ffe2};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x87f82867431a1d08, 0x9795698585057dec};
  __m128i_result = (__m128i){0x87e3285243051cf3, 0x9780697084f07dd7};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000101};
  __m128i_result = (__m128i){0xfffcfffcfffcfffc, 0xfffcfffcfffc00fd};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x371fe00000000000, 0x371fe00000000000};
  __m128i_result = (__m128i){0x370bdfecffecffec, 0x370bdfecffecffec};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x020202020202fe02, 0x0000040600000406};
  __m128i_result = (__m128i){0x01f701f701f7fdf7, 0xfff503fbfff503fb};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffdfffdfffdfffd, 0xfffdfffdfffdfffd};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x803e0000803e0000, 0x803e0000803e0000};
  __m128i_result = (__m128i){0x803bfffd803bfffd, 0x803bfffd803bfffd};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffdfffdfffdfffd, 0xfffdfffdfffdfffd};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffedffedffedffed, 0xffedffedffedffed};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffe4ffe4ffe4ffe4, 0xffe4ffe4ffe4ffe4};
  __m128i_out = __lsx_vsubi_hu((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffefffffffef, 0xffffffefffffffef};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffe6ffffffe6, 0xffffffe6ffffffe6};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffff1fffffff1, 0xfffffff1fffffff1};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffff6fffffff6, 0xfffffff6fffffff6};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffe4ffffffe4, 0xffffffe4ffffffe4};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffe1ffffffe1, 0xffffffe1ffffffe1};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffff1fffffff1, 0xfffffff1fffffff1};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffab7e71e33848, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffab5f71e33829, 0xffffffe1ffffffe1};
  __m128i_out = __lsx_vsubi_wu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0024d8f6a494006a, 0xa8beed87bc3f2be1};
  __m128i_result = (__m128i){0x0024d8f6a494005c, 0xa8beed87bc3f2bd3};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffeb, 0xffffffffffffffeb};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffe1, 0xffffffffffffffe1};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffff7, 0xfffffffffffffff7};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffe5, 0xffffffffffffffe5};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xf2f2e5e5e5e5e5e5};
  __m128i_result = (__m128i){0xfffffffffffffff7, 0xf2f2e5e5e5e5e5dc};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3fffff0000000000, 0x3fffff0000000000};
  __m128i_result = (__m128i){0x3ffffeffffffffe5, 0x3ffffeffffffffe5};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000007b};
  __m128i_result = (__m128i){0xfffffffffffffff5, 0x0000000000000070};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffff0, 0xfffffffffffffff0};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffe6, 0xffffffffffffffe6};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x000100010000fffb, 0x000100010000fffb};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffeb, 0xffffffffffffffeb};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffffa, 0xfffffffffffffffa};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffdfffe80008000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffdfffe80007fe2, 0xffffffffffffffe2};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001a001a001a001a, 0x001a001a001a001a};
  __m128i_result = (__m128i){0x001a001a001a000b, 0x001a001a001a000b};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c0dec4d1, 0x000000000234545b};
  __m128i_result = (__m128i){0x00000000c0dec4ca, 0x0000000002345454};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003b80000000000, 0x0f8d33000f8d3300};
  __m128i_result = (__m128i){0x0003b7fffffffffd, 0x0f8d33000f8d32fd};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubi_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
