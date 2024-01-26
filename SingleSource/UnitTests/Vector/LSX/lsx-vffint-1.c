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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe82fe0200000000, 0xfe82fe0200000000};
  v2u64_result = (v2u64){0x0000000000000000, 0xc177d01fe0000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x000100010001007c};
  v2u64_result = (v2u64){0x40f0001000000000, 0x40f0001000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100013fa0, 0x0000000000000000};
  v2u64_result = (v2u64){0x40f3fa0000000000, 0x3ff0000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffe0001, 0x0000000000000000};
  v2u64_result = (v2u64){0xc0fffff000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffintl_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001f0a, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffffffffffff, 0x7fffffffffffffff};
  v2u64_result = (v2u64){0xbff0000000000000, 0x41dfffffffc00000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003dbe88077c78c1, 0x0000000000003a24};
  v2u64_result = (v2u64){0x40cd120000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000040, 0x0000000000000040};
  v2u64_result = (v2u64){0x4050000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0082000000000007, 0x0086000000040000};
  v2u64_result = (v2u64){0x4110000000000000, 0x4160c00000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff8000010f800000, 0x0000000000000000};
  v2u64_result = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000003e0000003f, 0x00000000051649b6};
  v2u64_result = (v2u64){0x41945926d8000000, 0x0000000000000000};
  __m128d_out = __lsx_vffinth_d_w((__m128)v2u64_op0);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
