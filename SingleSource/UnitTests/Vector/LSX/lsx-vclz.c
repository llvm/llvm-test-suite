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

  v2u64_op0 = (v2u64){0x000b000b010a000b, 0x7f7f000b000b000b};
  __m128i_result = (__m128i){0x0804080407040804, 0x0101080408040804};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x41dfffff00000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0100000008080808};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x6363636363636363};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010101};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7861145d9241a14a, 0x687a8373f249bc44};
  __m128i_result = (__m128i){0x0101030100010001, 0x0101000100010001};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000001fffffffe};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080700000000};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000005};
  __m128i_result = (__m128i){0x0808080808080805, 0x0808080808080805};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0808080808080808, 0x0808080808080808};
  __m128i_out = __lsx_vclz_b((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000ff000000ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010000800100008, 0x0010001000100010};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x02693fe0e7beb077, 0x000000001fc1a568};
  __m128i_result = (__m128i){0x0006000200000000, 0x0010001000030000};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000100010000fe01, 0x000100010000fe7c};
  __m128i_result = (__m128i){0x000f000f00100000, 0x000f000f00100000};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff003000ff00a0, 0x00ff000100ff00fe};
  __m128i_result = (__m128i){0x0008000a00080008, 0x0008000f00080008};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe813f00fe813f00, 0xfe813f00fe813f00};
  __m128i_result = (__m128i){0x0000000200000002, 0x0000000200000002};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0010001000000000, 0x0010001000000000};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010001000100010, 0x0010001000100010};
  __m128i_out = __lsx_vclz_h((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000002000000020};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0x0000000f0000000f, 0x0000000f0000000f};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000008000001e, 0x000000000000001f};
  __m128i_result = (__m128i){0x0000002000000000, 0x000000200000001b};
  __m128i_out = __lsx_vclz_w((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf0bd80bd80bd8000, 0x1ffffffff8001000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000003};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000040, 0x0000000000000040};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000040, 0x0000000000000040};
  __m128i_result = (__m128i){0x0000000000000039, 0x0000000000000039};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000bffffffe};
  __m128i_result = (__m128i){0x0000000000000040, 0x0000000000000020};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0x00000c0c00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000014};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000040, 0x0000000000000040};
  __m128i_out = __lsx_vclz_d((__m128)v2u64_op0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
