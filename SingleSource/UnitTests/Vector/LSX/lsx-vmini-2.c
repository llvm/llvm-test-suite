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

  v2u64_op0 = (v2u64){0x0000a163000016b0, 0xffff0001ffff0001};
  __m128i_result = (__m128i){0x0000030300000303, 0x0303000103030001};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xd8248069ffe78077, 0x0000000000000000};
  __m128i_result = (__m128i){0x0d0d0d0d0d0d0d0d, 0x0000000000000000};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffff0000, 0x7da9b23a624082fd};
  __m128i_result = (__m128i){0x0000000005050000, 0x0505050505050505};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001300000013, 0x0000001300000013};
  __m128i_result = (__m128i){0x0000000e0000000e, 0x0000000e0000000e};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000001fffdfffdff, 0x000001fffdfffdff};
  __m128i_result = (__m128i){0x0000010101010101, 0x0000010101010101};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000071007600, 0x000000009c007c00};
  __m128i_result = (__m128i){0x0000000009000900, 0x0000000009000900};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  __m128i_result = (__m128i){0x0303030303030303, 0x0303030303030303};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8bff0000a7b80000, 0xd3220000d3f20000};
  __m128i_result = (__m128i){0x0909000009090000, 0x0909000009090000};
  __m128i_out = __lsx_vmini_bu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000083ff0be0, 0x80000000b57ec564};
  __m128i_result = (__m128i){0x0014000000140014, 0x0014000000140014};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000100010001000, 0x1000100010001000};
  __m128i_result = (__m128i){0x0013001300130013, 0x0013001300130013};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000005, 0x0000000000000000};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x27b169bbb8145f50, 0x02b010f881a281a2};
  __m128i_result = (__m128i){0x0002000200020002, 0x0002000200020002};
  __m128i_out = __lsx_vmini_hu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010002000000000, 0x0000040004000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00ff00ff0000007f};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000004};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff8000000000000, 0x7ff8000000000000};
  __m128i_result = (__m128i){0x0000000000000005, 0x0000000000000005};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001fe01fe00, 0x00000003fc00ff00};
  __m128i_result = (__m128i){0x000000000000000a, 0x000000000000000a};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fc000007fc00000, 0x7fc000007fc00000};
  __m128i_result = (__m128i){0x000000000000000b, 0x000000000000000b};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000101010001};
  __m128i_result = (__m128i){0x0000000000000014, 0x0000000000000014};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffefffefffefffe, 0xfffefffefffefffe};
  __m128i_result = (__m128i){0x0000000000000005, 0x0000000000000005};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000084300000e55f, 0x0000d3460001518a};
  __m128i_result = (__m128i){0x0000000000000016, 0x0000000000000016};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5efeb3165bd7653d, 0xffff2356fe165486};
  __m128i_result = (__m128i){0x0000000000000007, 0x0000000000000007};
  __m128i_out = __lsx_vmini_du((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
