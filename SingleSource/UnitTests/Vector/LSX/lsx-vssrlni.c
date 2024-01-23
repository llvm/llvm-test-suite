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
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000001fe01, 0x000000000001fe01};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0f0f0f0f00000000, 0x0000000f0000000f};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000001000000, 0x0000080007f80800};
  __m128i_result = (__m128i){0x00047fff00007fff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x342caf9bffff1fff, 0x0c03e17edd781b11};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000040000000400};
  __m128i_result = (__m128i){0x0000000000000000, 0x0c037fff342c7fff};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000a000a000a000a, 0x000a000a000a000a};
  __m128i_result = (__m128i){0x0a000a000a000a00, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000100000001};
  v2u64_op1 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3918371635143312, 0x01203f1e3d1c3b1a};
  v2u64_op1 = (v2u64){0x1918171615141312, 0x21201f1e1d1c1b1a};
  __m128i_result = (__m128i){0x7fff7fff7fff7fff, 0x480f7fff7fff7fff};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000007f41, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000002002};
  v2u64_op1 = (v2u64){0x2221201f1e1d1c1b, 0x2a29282726252423};
  __m128i_result = (__m128i){0x00a8009800880078, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x80006b0080808080, 0x8000807f00000000};
  __m128i_result = (__m128i){0x7fff00007fff7fff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe907b754d7eaa478, 0xc1bdceee242070dc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fff7fff7fff7fff};
  __m128i_out = __lsx_vssrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff80000000};
  __m128i_result = (__m128i){0x0001ffff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffffffff100fffc};
  __m128i_result = (__m128i){0x7fffffff00000000, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x21);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000800080};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffff7, 0xf2f2e5e5e5e5e5dc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x0008000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x41dfffff00000000};
  __m128i_result = (__m128i){0x0000083b00000000, 0x0000000100000020};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x33);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000006302e00, 0x0000000005151515};
  v2u64_op1 = (v2u64){0x7f417f417f027e03, 0x000000000000003f};
  __m128i_result = (__m128i){0x0000000000001fd0, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x03fffffffc010102, 0x03ff0101fc010102};
  v2u64_op1 = (v2u64){0x7fffffff81010102, 0x7fff010181010102};
  __m128i_result = (__m128i){0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000053a4f452, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000053a};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8d8d8d8d8d8cc6c6, 0x000000000000c6c7};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000008};
  __m128i_out = __lsx_vssrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01fc020000fe0100, 0x0000ff0000ff0000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000003fc0003};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x56);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0xfffffffffffff800};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x001fffffffffffff};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x35);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000003, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffbfffffffbf, 0xffffffbfffffffbf};
  __m128i_result = (__m128i){0x00000001ffffff7f, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffdfffcfffdfffc, 0xfffdfffcfffdfffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00004e420000c26a, 0x0000b3a6000067da};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffc00300000220, 0x00000203000010d0};
  v2u64_op1 = (v2u64){0x00000000000000ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x27);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000090900000998, 0x0000f50000000900};
  v2u64_op1 = (v2u64){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0x7fffffffffffffff};
  __m128i_out = __lsx_vssrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x20);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xfffffffff100fffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffffffff100fffc};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffff00000000};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000020, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x685670d27e00682a, 0x14ccc6320076a4d2};
  v2u64_op1 = (v2u64){0x685670d27e00682a, 0x14ccc6320076a4d2};
  __m128i_result = (__m128i){0x0001000100000000, 0x0001000100000000};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000001010101};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff010300ff0103, 0x0000000000000002};
  v2u64_op1 = (v2u64){0x555500adfffc5cab, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0101010100000100, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000007070707};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000100, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000080};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001000010f8, 0x0000000100000001};
  v2u64_op1 = (v2u64){0x00000000ff800000, 0xfff8ffa2fffdffb0};
  __m128i_result = (__m128i){0x0f0f0f0f00000f00, 0x0000000000000001};
  __m128i_out = __lsx_vssrlni_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff870068fff5ffb3, 0x004e005500060031};
  v2u64_op1 = (v2u64){0xff870068fff5ffb3, 0x004e005500060031};
  __m128i_result = (__m128i){0x04e00060ffffffff, 0x04e00060ffffffff};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0xfffffffffffffffe};
  v2u64_op1 = (v2u64){0xfffffffffffffffe, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000202fe02, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000101};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x03aa558ec8546eb6, 0x000aa822a8228222};
  v2u64_op1 = (v2u64){0x001f2f2cab1c732a, 0x001a64b345308091};
  __m128i_result = (__m128i){0x034cffff03e5ffff, 0x0155ffff754affff};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlni_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x52527d7d52527d7d, 0x52527d7d52527d7d};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x10);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080000080800000, 0x8080808000008080};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0001010100010100};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000fff80000, 0x00000000fff8fff8};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x37);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ff000000ff00, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000003fc0, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x22);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1ff85ffe2ae5d973, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x403be000ffffe000};
  __m128i_result = (__m128i){0x00201df000000000, 0x00000000000ffc2f};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x29);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbffffff0ffffc00f, 0xc000000fc0003fff};
  v2u64_op1 = (v2u64){0xffffffc3ffff003e, 0x0000003f0000ffff};
  __m128i_result = (__m128i){0x0000000000ffffff, 0x00c0000000bfffff};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003f0000ffffffff, 0x003f0000ffffffff};
  v2u64_op1 = (v2u64){0x0003000300a10003, 0x000300037ff000ff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x27);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x35);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00005dcbe7e830c0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  __m128i_result = (__m128i){0x000000001fffff59, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x63);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000040, 0x0000000000000040};
  v2u64_op1 = (v2u64){0x0000000000000040, 0x0000000000000040};
  __m128i_result = (__m128i){0x0000000000002000, 0x0000000000002000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x39);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x808080010080007f, 0x800000810000807f};
  v2u64_op1 = (v2u64){0x808080010080007f, 0x800000810000807f};
  __m128i_result = (__m128i){0x0000000020000020, 0x0000000020000020};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x62);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0400400204004002};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000002002};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x2221201f1e1d1c1b, 0x2a29282726252423};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x26);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x45);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7c7c000000007176, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00d5701794027113, 0x0002711350a27112};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrlni_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
