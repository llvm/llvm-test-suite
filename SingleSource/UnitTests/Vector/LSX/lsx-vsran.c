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

  v2u64_op0 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x007fffff00000000};
  __m128i_result = (__m128i){0x0000fffe0001fffe, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000000000201, 0x0303020102020001};
  v2u64_op1 = (v2u64){0xd82480697f678077, 0x0000000000000000};
  __m128i_result = (__m128i){0x0301020100000004, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffff02, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000ff02, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffefffeff00feff, 0x3c5fffffff7fffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfff0ff8006f0f950, 0x00000100f8100002};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000000002bb, 0x00000000000000bf};
  __m128i_result = (__m128i){0x000000000000ffff, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000718ea657431b, 0x0000000021e79364};
  v2u64_op1 = (v2u64){0xfefffffffeffe3d7, 0xfefffffffeffda6f};
  __m128i_result = (__m128i){0x000000ff0000ff86, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000000000000, 0x8000000000000001};
  v2u64_op1 = (v2u64){0x0101fe8700000000, 0x0101fe870101fe87};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_b_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000f0080000f800, 0x0000e0180000e810};
  v2u64_op1 = (v2u64){0x0000f0080000f800, 0x0000e0180000e810};
  __m128i_result = (__m128i){0x0000000000f0f800, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x7fff7fff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffff7a53, 0x0000000000001f0a};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffffffffffffff0, 0xfffffffffffffff0};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000800000000000, 0x0000800000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001e0052001ffff9, 0x0037ffd40083ffe5};
  v2u64_op1 = (v2u64){0x001effae001effae, 0x001effae001effae};
  __m128i_result = (__m128i){0x00df020f0078007f, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x06d9090909090909, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x6d339b4f3b439885, 0x0039d21e3229d4e8};
  __m128i_result = (__m128i){0x000000000db24848, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff80000000};
  v2u64_op1 = (v2u64){0xfe03fe3ffe01fa21, 0xfe3bfb01fe3bfe01};
  __m128i_result = (__m128i){0xffff000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_h_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000001, 0x0000000100089bde};
  v2u64_op1 = (v2u64){0x0001000104000800, 0x0001000100010001};
  __m128i_result = (__m128i){0x80044def00000001, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x353c8cc4b1ec5b09, 0x0101010101010101};
  v2u64_op1 = (v2u64){0xcbc2723a4f12a5f8, 0x002affd600000001};
  __m128i_result = (__m128i){0x8080808000000035, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003fffff00000000, 0x003fffff00000000};
  v2u64_op1 = (v2u64){0x003fffff00000000, 0x003fffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000001000000ff, 0x0000000100000100};
  v2u64_op1 = (v2u64){0x00ff80ff00ff80ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000010000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffe8081000000000, 0x7ff000ff6220c0c1};
  v2u64_op1 = (v2u64){0xffe8081000000000, 0x7ff000ff6220c0c1};
  __m128i_result = (__m128i){0xb110606000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff76ffd8ffe6ffaa, 0xff80ffa2fff0ff74};
  v2u64_op1 = (v2u64){0xffffffffbc19ecca, 0xffffffffc105d1aa};
  __m128i_result = (__m128i){0xffffe03ff63ff9bf, 0x0000000000000000};
  __m128i_out = __lsx_vsran_w_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
