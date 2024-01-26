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

  v2u64_op0 = (v2u64){0x0001ffff0001ffff, 0x0001ffff00000000};
  __m128i_result = (__m128i){0x0000ffff0000ffff, 0x0000ffff00000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0000000001000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0x3c600000ff800000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0f180000ffe00000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x407c2ca32cbd0357, 0x21f32eaf5b7a02c8};
  __m128i_result = (__m128i){0x203e16d116de012b, 0x10f917d72d3d01e4};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  __m128i_result = (__m128i){0x01ff000000000000, 0x01ff000000000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ffffffffff, 0x00ffffff00ff00ff};
  __m128i_result = (__m128i){0x00ff00ffffffffff, 0x00ffffff00ff00ff};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0808080808080808, 0x0808080808080808};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7fff7fff7fff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x3fff3fff3fff3fff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0000000200000002};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffe000ffff1fff, 0x0000040400000383};
  __m128i_result = (__m128i){0xffffffc0ffff003f, 0x0000000800000007};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x51cfd7c000000000, 0xf6e91c0000000000};
  __m128i_result = (__m128i){0x0014fff500000000, 0xfffd000700000000};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000200010, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x40c7ee1f38e4c4e8, 0x0aa077b7054c9554};
  __m128i_result = (__m128i){0x0000ffff0000ffff, 0x000000000000ffff};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00f0001000000010, 0x0001000100010001};
  __m128i_result = (__m128i){0x00f0001000000010, 0x0001000100010001};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffff00000000};
  __m128i_out = __lsx_vsrai_h((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_w((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0048137ef886fae0, 0x1268f057137a0267};
  __m128i_result = (__m128i){0x00000001ffffffe2, 0x000000490000004d};
  __m128i_out = __lsx_vsrai_w((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000f, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_w((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_w((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ca354688, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000003, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x2e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x3c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe80ffffffffff02, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffffffffe80, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000049ffffffaa, 0x0000001800000039};
  __m128i_result = (__m128i){0x000000127fffffea, 0x000000060000000e};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x5d7f5d807fea807f};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000002ebf};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000190, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0001000100010058};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000001000100010};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrai_d((__m128)v2u64_op0, 0x3d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
