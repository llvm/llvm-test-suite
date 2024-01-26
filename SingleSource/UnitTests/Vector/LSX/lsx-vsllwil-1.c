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

  v2u64_op0 = (v2u64){0x0020002000200020, 0x0020002000200020};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000e0000000e0, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000fc00, 0x000000000000fc00};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffeb48e03eab7ebe, 0x0000000100000001};
  __m128i_result = (__m128i){0x0f80eac01f80ef80, 0xffc0fac01200f800};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc2fac2fa53e7db29, 0x00000000e7e20468};
  __m128i_result = (__m128i){0x00a6ffceffb60052, 0xff84fff4ff84fff4};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x002e0059003b0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000007600000000, 0x0000005c000000b2};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x2e34594c3b000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x01d8000000000000, 0x017001a002c80260};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_result = (__m128i){0x09e009e009e009e0, 0x09e009e009e009e0};
  __m128i_out = __lsx_vsllwil_h_b((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100000000, 0x0000000001000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000040000000400};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0505000005050505, 0x0000000005050000};
  __m128i_result = (__m128i){0x0028280000282800, 0x0028280000000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0xfffffffffffff800};
  __m128i_result = (__m128i){0xffc0000000000000, 0xffc0000000000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffff00ffffff00, 0xffffff00ffffff00};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf10cf508f904fd01, 0xf10cf508f904fd01};
  __m128i_result = (__m128i){0xfffff208fffffa02, 0xffffe218ffffea10};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1918171615141312, 0x21201f1e1d001b1a};
  __m128i_result = (__m128i){0x0001514000013120, 0x0001918000017160};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffff790a15db63d, 0xfffff60ca7104649};
  __m128i_result = (__m128i){0xfe857400fed8f400, 0xfffffc00ffde4000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1c6c80007fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00fffe00fffffe00, 0x0038d800ff000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fc000007fc00000, 0x7fc000007fc00000};
  __m128i_result = (__m128i){0x00ff800000000000, 0x00ff800000000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_w_h((__m128)v2u64_op0, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001fffe00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000007fff800000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x007fffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff80000000ffff, 0xffff80ff0000ffff};
  __m128i_result = (__m128i){0x000000000001fffe, 0xffffffffffff0000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000104000800, 0x0001000100010001};
  __m128i_result = (__m128i){0x0010002000000000, 0x0000040004000000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000000000007b};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x1e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000100000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000020};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000017fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x003fffffff800000, 0x0000000000800000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x57f160c4a1750eda, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffd0ba876d000, 0x000002bf8b062000};
  __m128i_out = __lsx_vsllwil_d_w((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
