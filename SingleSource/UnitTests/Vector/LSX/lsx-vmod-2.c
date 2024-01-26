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

  v2u64_op0 = (v2u64){0x6363636363636363, 0x16161616a16316b0};
  v2u64_op1 = (v2u64){0x6363636363636363, 0x16161616a16316b0};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  v2u64_op1 = (v2u64){0x5a5a5a5a5b5a5b5a, 0x5a5a5a5a5b5a5b5a};
  __m128i_result = (__m128i){0x00000001494b494a, 0x00000001494b494a};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffeb, 0xffffffffffffffeb};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x68bcf93435ed25ed, 0x7f801fa06451ef11};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffdd9999da, 0x0000000022666621};
  v2u64_op1 = (v2u64){0x7f0000fd7f0000fd, 0x7f7f7f7f00107f04};
  __m128i_result = (__m128i){0x01ff00085e9900ab, 0x0000000000066621};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fff0000, 0x000000000000bd3d};
  v2u64_op1 = (v2u64){0xefffdffff0009d3d, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000007fff0000, 0x000000000000bd3d};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000004870ba0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x6b769e690fa1e119, 0x478b478b38031779};
  __m128i_result = (__m128i){0x0000000004870ba0, 0x0000000000000000};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x2006454690d3de87, 0x2006454690d3de87};
  v2u64_op1 = (v2u64){0x2006454690d3de87, 0x2006454690d3de87};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000200020002, 0x0002000200020002};
  v2u64_op1 = (v2u64){0x27b169bbb8145f50, 0x02b010f881a281a2};
  __m128i_result = (__m128i){0x0002000200020002, 0x0002000200020002};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff100000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0010001000100010, 0x0010001000100010};
  __m128i_result = (__m128i){0x000f000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000100000001, 0x0000000100000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000fffe0000fffe, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffff00ffffff00, 0xffffff00ffffff00};
  __m128i_result = (__m128i){0x0000fffe0000fffe, 0x0000000000000000};
  __m128i_out = __lsx_vmod_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8000000080000000, 0x8000000080000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000200, 0x0000000000000200};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffff0000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000101fd01fe, 0x0001000100010001};
  v2u64_op1 = (v2u64){0xff80ff8080008000, 0xff80ff80ff80ff80};
  __m128i_result = (__m128i){0x0001000101fd01fe, 0x0001000100010001};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000000a0, 0xffffffffcafff8ff};
  v2u64_op1 = (v2u64){0xfffeffff0035ff8f, 0xff2cfed4fea8ff44};
  __m128i_result = (__m128i){0x00000000000000a0, 0x00d3012acc56f9bb};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x37c0001000000000, 0x37c0001000000000};
  v2u64_op1 = (v2u64){0x0004000400040004, 0x0004000400040004};
  __m128i_result = (__m128i){0x0003c853c843c844, 0x0003c853c843c844};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000003ddc5dac, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfcfcfcdcfcfcfcdc, 0xfcfcfcdcfcfcfcdc};
  __m128i_result = (__m128i){0x000000003ddc5dac, 0x0000000000000000};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffefffff784, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00000001000010f8, 0x10f8000100000001};
  __m128i_result = (__m128i){0x00000000011ff8bc, 0x0177fff0fffffff0};
  __m128i_out = __lsx_vmod_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
