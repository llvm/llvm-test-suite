#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2, v2u64_result;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2, v4i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4i32_result = (v4i32){0x4b7f00ff, 0x4b7f00ff, 0x4b7f00ff, 0x4b7f00ff};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000004, 0x0000000401000001};
  v4i32_result = (v4i32){0x40800000, 0x47800080, 0x4b800000, 0x40800000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000800000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x47000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x76f424887fffffff, 0x0000000000000001};
  v4i32_result = (v4i32){0x4f000000, 0x4eede849, 0x3f800000, 0x00000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  v4i32_result = (v4i32){0xcedb2c3f, 0xceb95a81, 0x4edd53ea, 0xce23d33d};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x3f800000, 0x00000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000003ff8, 0x0000000000000000};
  v4i32_result = (v4i32){0x467fe000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_w((__m128)v2u64_op0);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x03ff03ff03ff03ff};
  v2u64_result = (v2u64){0x0000000000000000, 0x438ff81ff81ff820};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f8000004f800000, 0x4f8000004f800000};
  v2u64_result = (v2u64){0x43d3e0000013e000, 0x43d3e0000013e000};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xbff0000000000000, 0xbff0000000000000};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfdce8003090b0906, 0x0674c8868a74fc80};
  v2u64_result = (v2u64){0xc3818bffe7b7a7b8, 0x4399d3221a29d3f2};
  __m128d_out = __lsx_vffint_d_l((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff80000000};
  v4i32_result = (v4i32){0x00000000, 0xcf000000, 0x00000000, 0xbf800000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f8000007f800000, 0x7f8000007f800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x5eff0000, 0x5eff0000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000000000e3};
  v2u64_op1 = (v2u64){0x00000000ffff0000, 0xfda9b23a624082fd};
  v4i32_result = (v4i32){0x4f7fff00, 0xdc159371, 0x00000000, 0x43630000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000040, 0x0000000000000040};
  v4i32_result = (v4i32){0x42800000, 0x42800000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000100, 0x0000000000000100};
  v4i32_result = (v4i32){0x43800000, 0x43800000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x001effae001effae, 0x001effae001effae};
  v4i32_result = (v4i32){0x59f7fd70, 0x59f7fd70, 0x00000000, 0x00000000};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x000ef0000000003b, 0x0000000000000000};
  v4i32_result = (v4i32){0x596f0000, 0x00000000, 0x577fff00, 0x577fff00};
  __m128_out = __lsx_vffint_s_l((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
