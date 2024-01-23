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
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfefefefefefefefe, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffff730f, 0xffffffff3c992b2e};
  __m128i_result = (__m128i){0xffffffffffff730f, 0xffffffff3c992b2e};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00007fff00007fff};
  v2u64_op1 = (v2u64){0x000000002bfd9461, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000002bfd9461, 0x00007fff00007fff};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001021, 0x00d3012acc56f9bb};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000001021, 0x00d3012acc56f9bb};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001000, 0x0000000000001000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000001000, 0x0000000000001000};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x80808080806b000b, 0x0000000000000000};
  __m128i_result = (__m128i){0x80808080806b000b, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff01ff01, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0x3c600000ff800000};
  __m128i_result = (__m128i){0xfffefffeff00feff, 0x3c5fffffff7fffff};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ff00ff00ff00ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00ff00ff00ff00ff, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x40f3fa0000000000, 0x3ff0000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x40f3fa0000000000, 0x3ff0000000000000};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000008900000009, 0x0000008a0000008a};
  v2u64_op1 = (v2u64){0x6363636363636363, 0x63637687636316bb};
  __m128i_result = (__m128i){0x636363ec6363636c, 0x6363771163631745};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000004, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000004, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000080000000, 0x0000000080000000};
  __m128i_result = (__m128i){0x0000000080000000, 0x0000000080000000};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c2bac2c2, 0xfffffffffefefe6a};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000001fffffffe};
  __m128i_result = (__m128i){0x00000000c2bac2c2, 0x00000000fefefe68};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x027c027c000027c0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_result = (__m128i){0x028c026bfff027af, 0x001ffff0003ffff0};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000000010000, 0x0007000000040000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0003000000010000, 0x0007000000040000};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f8000003f800000, 0x3f8000003f800000};
  v2u64_op1 = (v2u64){0x3fffff0000000000, 0x3fffff0000000000};
  __m128i_result = (__m128i){0x7f7fff003f800000, 0x7f7fff003f800000};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00fe01fc0005fff4, 0x0000000820202020};
  v2u64_op1 = (v2u64){0x003dbe88077c78c1, 0x0000000000003a24};
  __m128i_result = (__m128i){0x013bc084078278b5, 0x0000000820205a44};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000140001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000140001, 0x0000000000000001};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000100000001};
  __m128i_result = (__m128i){0xc8847ef6ed3f2000, 0x67eb85b0b2ebb001};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x14eb6a002a406a00, 0x0000000014eb54ab};
  __m128i_result = (__m128i){0x14ea6a002a406a00, 0xffffffff14eb54ab};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000004, 0x0000000000000004};
  v2u64_op1 = (v2u64){0xce9035c49ffff570, 0x0000000000000000};
  __m128i_result = (__m128i){0xce9035c49ffff574, 0x0000000000000004};
  __m128i_out = __lsx_vsadd_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
