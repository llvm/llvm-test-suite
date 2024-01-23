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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00003fe00ffe3fe0, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000b5207f80, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00000000b5207f80, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffff208fffffa02, 0xffffe218ffffea10};
  v2u64_op1 = (v2u64){0x0000000000000004, 0x0000000000000004};
  v2u64_op2 = (v2u64){0xfffff208fffffa02, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffff208fffffa02, 0xffffe218ffffea10};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000bd3d00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000bd3d00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000bd3d00000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffff0000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0032000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x2020202020207f7f, 0x2020202020202020};
  __m128i_result = (__m128i){0x00000000ffff0000, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000000a0, 0x00d3012acc56f9bb};
  v2u64_op1 = (v2u64){0x0000000100013fa0, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000100013fa0, 0x0000000120002000};
  __m128i_result = (__m128i){0x0000000000001021, 0x00d3012acc56f9bb};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000014, 0x0002000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0002000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000ffff00000000};
  __m128i_result = (__m128i){0x0000000000000014, 0x0002000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000800000000000, 0x0000800000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xc3818bffe7b7a7b8, 0x4399d3221a29d3f2};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000467fe000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000003ff8, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000003ff8, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000467fef81, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1e801ffc00000000, 0x7fc0000000000000};
  v2u64_op1 = (v2u64){0x0000ff020000fff4, 0x000000000000ffff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x1e801ffc00000000, 0x7fc0000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0x3c600000ff800000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe80000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfe80000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00007f7f00007f7f, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00013fff, 0x00ffffff03ffffff};
  v2u64_op1 = (v2u64){0x0001fffd00000407, 0x000088500000f6a0};
  v2u64_op2 = (v2u64){0x0000e22b0000efa4, 0x0000442900007b4c};
  __m128i_result = (__m128i){0xffffffff00013fff, 0x00ffffff03ffffff};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x685670d37e80682a, 0x14ccc6320176a4d2};
  v2u64_op1 = (v2u64){0x000000007fffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x685670d37e80682a, 0x14ccc6320176a4d2};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xc0411fe800000000, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x7fff7fff7fff7fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x601fbfbeffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffbc19ecca, 0xffffffffc105d1aa};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffff0000ffff43e6, 0xffff0000ffff3efa};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffa7, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  v2u64_op2 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  __m128i_result = (__m128i){0x00006f9100007337, 0x0000930400008a10};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000ffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x001000100010c410, 0x0010001000100010};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffffff02fff4, 0xff02ff1bff02ff23};
  v2u64_op1 = (v2u64){0x0000ffffff02fff4, 0xff02ff1bff02ff23};
  v2u64_op2 = (v2u64){0x1e801ffc7fc00000, 0x7fc000007fc00000};
  __m128i_result = (__m128i){0x00011e80007edff8, 0x7e44bde9b842ff23};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffffffeffffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000100000001, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe0dd268932a5edf9, 0xe0d56a9774f3ea31};
  v2u64_op1 = (v2u64){0xe0dd268932a5edf9, 0xe0d56a9774f3ea31};
  v2u64_op2 = (v2u64){0xd8248069ffe78077, 0x0000000000000000};
  __m128i_result = (__m128i){0xbddaa86803e33c2a, 0xe0d56a9774f3ea31};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0028280000282800, 0x0028280000000000};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x01010000fefe0101, 0x7505853d654185f5};
  __m128i_result = (__m128i){0x012927ffff272800, 0x0028280000000000};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff007f0101017f, 0x00ffff7f00ff00ff};
  v2u64_op1 = (v2u64){0x000000183fffffe5, 0x0000000020000000};
  v2u64_op2 = (v2u64){0x000000000000002a, 0x0000000000000073};
  __m128i_result = (__m128i){0x00ff007f0101017f, 0x00ffff7f00ff00ff};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f8000003f800000, 0x3f8000003f800000};
  v2u64_op1 = (v2u64){0x000000002bfd9461, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x3f8000003f800001, 0x3f8000003f800001};
  __m128i_result = (__m128i){0x3f8000003f800000, 0x3f8000003f800000};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000095896a760000};
  v2u64_op1 = (v2u64){0x006f0efe258ca851, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffff200000000000, 0xffff7fc8ffff8000};
  __m128i_result = (__m128i){0xffffff9ed2e1c000, 0x000015516a768038};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100013fa0, 0x0000000120002000};
  v2u64_op1 = (v2u64){0x0000000000013fa0, 0x2000200000013fa0};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100013fa0, 0x0000000120002000};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080006b00000000, 0x0080008000800080};
  v2u64_op1 = (v2u64){0x001b19b1c9c6da5a, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x001b19b1c9c6da5a, 0x0000000000000000};
  __m128i_result = (__m128i){0x008003496dea0c61, 0x0080008000800080};
  __m128i_out = __lsx_vmaddwod_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
