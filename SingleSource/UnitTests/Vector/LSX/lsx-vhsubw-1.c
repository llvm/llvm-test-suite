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
  v2u64_op1 = (v2u64){0x00000000fffffc00, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000010000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00007f8000007f80, 0x00007f8000007f80};
  __m128i_result = (__m128i){0x0000008000000080, 0x0000008000000080};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff07effffe, 0xffffffffffffff00};
  __m128i_result = (__m128i){0x0001000100110002, 0x0001000100010000};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffeff400000df4, 0x00000000ffffff01};
  v2u64_op1 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  __m128i_result = (__m128i){0xffff00650001ffb0, 0x0000ff91fffffff5};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000bfffffffe0f6, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000010001000a, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbff0000000000000, 0x41dfffffffc00000};
  v2u64_op1 = (v2u64){0x0101010101010101, 0x0008000000000000};
  __m128i_result = (__m128i){0xffbeffffffffffff, 0x0039ffffffff0000};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x370bdfecffecffec, 0x370bdfecffecffec};
  v2u64_op1 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  __m128i_result = (__m128i){0x0037ffdfffeb007f, 0x0037ffdfffffffff};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  v2u64_op1 = (v2u64){0x4e3e133738bb47d2, 0x0000000000000000};
  __m128i_result = (__m128i){0xfff9ff4a0057000e, 0xff98007a004d0050};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000501ffff0005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0001000600000001, 0x0001000100010001};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020000ffff0001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0001000100000001, 0x0001000100010001};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001effae001effae, 0x0000ffae001effae};
  v2u64_op1 = (v2u64){0x5252525252525252, 0x5252525252525252};
  __m128i_result = (__m128i){0xffaeffadffaeffad, 0xffaeffadffaeffad};
  __m128i_out = __lsx_vhsubw_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000201000000000b, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000fc0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000200000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff01ff01, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00000000ffffff02, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000100000000, 0x0000000100000001};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000100000001, 0x0000000100000001};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000000000ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffff01, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x12755900b653f081, 0x9727b8499727b849};
  v2u64_op1 = (v2u64){0x7d7f13fc7c7ffbf4, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffe79ffffba5f, 0xffff9727ffff9727};
  __m128i_out = __lsx_vhsubw_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000100010, 0x0000000000100010};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vhsubw_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  v2u64_op1 = (v2u64){0x0000100c6ffef10c, 0x00000000000000ff};
  __m128i_result = (__m128i){0xffffffff9001a47e, 0xffffffffffffff70};
  __m128i_out = __lsx_vhsubw_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00000000000000a6, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffff59, 0xffffffffffffffff};
  __m128i_out = __lsx_vhsubw_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000400000004, 0x0000000400000004};
  __m128i_result = (__m128i){0xfffffffffffffffc, 0xfffffffffffffffc};
  __m128i_out = __lsx_vhsubw_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000100000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000001, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0x0000000100000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xcbc2723a4f12a5f8, 0x002affd600000001};
  __m128i_result = (__m128i){0x343d8dc5b0ed5a08, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffff0001ffff9515, 0x00000000ffff53d9};
  __m128i_result = (__m128i){0x0000fffe00006aea, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000455555555, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000003fe0000141e, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffc01ffffebe2, 0xffffffffffffffff};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  v2u64_op1 = (v2u64){0x0000001f0000001f, 0x0000002000000020};
  __m128i_result = (__m128i){0x67eb8590b2ebafe1, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xb4b8122ef4054bb3, 0x56a09e662ab46b31};
  __m128i_result = (__m128i){0x4b47edd10bfab44d, 0x0000000000000000};
  __m128i_out = __lsx_vhsubw_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
