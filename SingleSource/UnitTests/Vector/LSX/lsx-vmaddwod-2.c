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

  v2u64_op0 = (v2u64){0xd8248069ffe78077, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0d0d0d0d0d0d0d0d, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xd8248069ffe78077, 0x0000000000000000};
  __m128i_result = (__m128i){0xe31c86e90cda86f7, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0100400100200e68, 0x00010020fffeffde};
  v2u64_op1 = (v2u64){0x0100400100200e68, 0x00010020fffeffde};
  v2u64_op2 = (v2u64){0x1ff85ffe2ae5d973, 0x0000000000000000};
  __m128i_result = (__m128i){0x011f57c100201a46, 0x00010020fffeffde};
  __m128i_out = __lsx_vmaddwod_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xbafebb00ffd500fe};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0a09080709080706, 0x0c0b0a090b0a0908};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwod_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffc0800000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffffffffc0800000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffc0800000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003dbe88077c78c1, 0x0000000000003a24};
  v2u64_op1 = (v2u64){0x0020002000200020, 0x0000000000000008};
  v2u64_op2 = (v2u64){0x0020002000200020, 0x0000000000000008};
  __m128i_result = (__m128i){0x003dc288077c7cc1, 0x0000000000003a24};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffc0000000000004, 0xffc0000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000455555555, 0x0000000000000000};
  __m128i_result = (__m128i){0xffc0000000000004, 0xffc0000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000000000053a};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000020};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x42a0000042a02001, 0x0000000036280001};
  v2u64_op1 = (v2u64){0x0000005555555554, 0x0000005555555554};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x42a0000042a02001, 0x0000000036280001};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000fe00ff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000ff00fe, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000fe00ff, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffff946b, 0x00000000ffff946c};
  v2u64_op1 = (v2u64){0xffffffffffff730f, 0xffffffff3c992b2e};
  v2u64_op2 = (v2u64){0xffffffffffff946b, 0x00000000ffff946c};
  __m128i_result = (__m128i){0xfffffffdffff946c, 0x00000000ffff946c};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000080000000000, 0x0000080000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000401000};
  __m128i_result = (__m128i){0x0000080000000000, 0x0000080000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff000000ff0000, 0xfffffffffffff800};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00ff000000ff0000, 0xfffffffffffff800};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0002ffff0000ffff, 0x0006ffff0004ffff};
  v2u64_op2 = (v2u64){0xffffffff7f800000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0002fffefffd0001, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7ff8000000000000, 0x7ff8000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c6fde000, 0x00000000ffffe000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xe000e0006080b040, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000c6fde000, 0x00000000ffffe000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x030298a6a1030a49, 0x021b7d24c9678a35};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0a753500950fa306, 0x000000000a752a55};
  v2u64_op1 = (v2u64){0x0000000200000000, 0x0000000100000000};
  v2u64_op2 = (v2u64){0x0a753500950fa306, 0x000000000a752a55};
  __m128i_result = (__m128i){0x0a753500a9fa0d06, 0x000000000a752a55};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_out = __lsx_vmaddwod_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
