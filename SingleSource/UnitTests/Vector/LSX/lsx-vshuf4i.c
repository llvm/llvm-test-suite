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

  v2u64_op0 = (v2u64){0x0000000000000003, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000030000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0xc9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0004007c00fc0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x047c0404fc00fcfc, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x8a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x007fffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xff00ff7f00000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x85);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffd6040188, 0xfffffffff51cf8da};
  __m128i_result = (__m128i){0xffffffff01018888, 0xfffffffff8f8dada};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x50);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xac82aa88a972a36a, 0x007d00c50177ac5b};
  __m128i_result = (__m128i){0xaaacac88a3a9a96a, 0x000000c5ac01015b};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x7c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000a00000009, 0x0000000a0000000a};
  __m128i_result = (__m128i){0x0a0a0a0009090900, 0x0a0a0a000a0a0a00};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000001000100, 0x0000000001000100};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00003f8000000000, 0x00003f8000000000};
  __m128i_result = (__m128i){0x003f800000000000, 0x003f800000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0xd2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x6c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x81);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000dffff000d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000ffffff, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x6b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7fff7fff7fff, 0x5f675e96e29a5a60};
  __m128i_result = (__m128i){0xff7f7fffff7f7fff, 0x965f5e9660e25a60};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x34);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x11100f0e100f0e0d, 0x131211101211100f};
  __m128i_result = (__m128i){0x110e1011100d0f10, 0x13101213120f1112};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0xcb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000431f851f, 0x0000000001000110};
  __m128i_result = (__m128i){0x0000000043431f1f, 0x0000000001011010};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0xf0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  __m128i_result = (__m128i){0xecbbbbc5d5f3f3f3, 0xd1c0c0a5baf8f8d3};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0x7c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000454ffff9573, 0x0000000000000004};
  __m128i_result = (__m128i){0x00000454ffff9573, 0x0000000000000004};
  __m128i_out = __lsx_vshuf4i_b((__m128)v2u64_op0, 0xa4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0xf3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0x2c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0xd2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x007c000d00400000, 0x003f000000000000};
  __m128i_result = (__m128i){0x0000007c00000040, 0x0000003f00000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0x31);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff00000000ffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000ffff00000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0xb9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ffffffe00000000, 0x7ffffffe00000000};
  __m128i_result = (__m128i){0x7fff00007fff0000, 0x7fff00007fff0000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0xcd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffff00000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0x93);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000007f7f7f, 0x0000000000000000};
  __m128i_result = (__m128i){0x007f007f00007f7f, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_h((__m128)v2u64_op0, 0x58);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000010, 0x0000000000000010};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000001000000010};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000080808000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000080808000};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x8b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffdfffdfffdfffd, 0xfffdfffdfffdfffd};
  __m128i_result = (__m128i){0xfffdfffdfffdfffd, 0xfffdfffdfffdfffd};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x7e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefefeeffef7fefe, 0xfefefefdbffefdfe};
  __m128i_result = (__m128i){0xfefefefdfefefeef, 0xfef7fefebffefdfe};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x2d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x002a001a001a000b};
  __m128i_result = (__m128i){0x001a000b00000000, 0x00000000002a001a};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x78);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x98);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000069bb00000001, 0x000010f8000081a2};
  __m128i_result = (__m128i){0x00000001000010f8, 0x0000000100000001};
  __m128i_out = __lsx_vshuf4i_w((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x44);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000fffff800, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x00000000fffff800, 0x00000000fffff800};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001f0a, 0x000000000000006f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000006f};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x36);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffe3d6, 0x00000000ffffda6e};
  v2u64_op1 = (v2u64){0x6f5edf5ada6fe3d7, 0xeeb1e4f4bc3763f3};
  __m128i_result = (__m128i){0xeeb1e4f4bc3763f3, 0x00000000ffffe3d6};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x23);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100200001, 0x0000000100200001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00001fff00001fff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x63b2ac27aa076aeb, 0xce23d33e43d9736c};
  __m128i_result = (__m128i){0x0000000000000000, 0x63b2ac27aa076aeb};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000158, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000158};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xbf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x77eb86788eebaf00, 0x801d5de0000559e0};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x89582bf870006860, 0x89582bf870006860};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vshuf4i_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x94);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
