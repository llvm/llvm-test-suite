#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0202020202020202, 0x0202020202020202,
                             0x0202020202020202, 0x0202020202020202};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1010101010101010, 0x1010101010101010,
                             0x1010101010101010, 0x1010101010101010};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001000000fb, 0x0000000100000013,
                      0x00000001000000fe, 0x0000000100000013};
  __m256i_result = (__m256i){0x80808081808080fb, 0x8080808180808093,
                             0x80808081808080fe, 0x8080808180808093};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2020202020202020, 0x2020202020202020,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000004411, 0x0000000000000000,
                      0x0000000000004411, 0x0000000000000000};
  __m256i_result = (__m256i){0x2020202020206431, 0x2020202020202020,
                             0x2020202020206431, 0x2020202020202020};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4040404040404040, 0x4040404040404040,
                             0x4040404040404040, 0x4040404040404040};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x4040404040404040, 0xffffffffffffffff,
                             0x4040404040404040, 0xffffffffffffffff};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfd02fd02fd02fd02, 0xfd02fd02fd02fd02,
                      0xfd02fd02fd02fd02, 0xfd02fd02fd02fd02};
  __m256i_result = (__m256i){0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12,
                             0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12};
  __m256i_out = __lasx_xvbitseti_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010001000100010, 0x0010001000100010,
                             0x0010001000100010, 0x0010001000100010};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7bbbbbbbf7777778, 0x0000000044444443,
                      0x7bbbbbbbf7777778, 0x0000000044444443};
  __m256i_result = (__m256i){0x7bbbbbbbf7777778, 0x1000100054445443,
                             0x7bbbbbbbf7777778, 0x1000100054445443};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7,
                      0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7};
  __m256i_result = (__m256i){0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7,
                             0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000030b8, 0x0000000000000000,
                      0x00000000000030b8, 0x0000000000000000};
  __m256i_result = (__m256i){0x00020002000230ba, 0x0002000200020002,
                             0x00020002000230ba, 0x0002000200020002};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8100810081008100, 0x0100010001000100,
                             0x8100810081008100, 0x0100010001000100};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000007878, 0x0000000000000000,
                      0x0000000000007878, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010001000107878, 0x0010001000100010,
                             0x0010001000107878, 0x0010001000100010};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffb2f600006f48, 0x0000000100000001,
                      0xffffb2f600006f48, 0x0000000100000001};
  __m256i_result = (__m256i){0xfffff2f640006f48, 0x4000400140004001,
                             0xfffff2f640006f48, 0x4000400140004001};
  __m256i_out = __lasx_xvbitseti_h((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0xfffcf800fffcf800, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000080000000800, 0x0000080000000800,
                             0xfffcf800fffcf800, 0x0000080000000800};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010000000100000, 0x0010000000100000,
                             0x0010000000100000, 0x0010000000100000};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffa0078fffa0074, 0xfffefffefffefffe,
                      0xfffa0078fffa0074, 0xfffefffefffefffe};
  __m256i_result = (__m256i){0xfffa2078fffa2074, 0xfffefffefffefffe,
                             0xfffa2078fffa2074, 0xfffefffefffefffe};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0003030300000100, 0x0003030300000100,
                      0x0003030300000300, 0x0003030300000300};
  __m256i_result = (__m256i){0x0043030300400100, 0x0043030300400100,
                             0x0043030300400300, 0x0043030300400300};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x43ec0a1b2aba7ed0, 0x223d76f09f37e357,
                      0x3870ca8d013e76a0, 0x223d76f09f3881ff};
  __m256i_result = (__m256i){0x43ec0a1b2aba7ed0, 0x223d76f09f37e357,
                             0x3870ca9d013e76b0, 0x223d76f09f3881ff};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffe1ffe0ffe1ffe0, 0x00ff0020ff1f001f,
                      0xffe1ffe0ffe1ffe0, 0x00ff0020ff1f001f};
  __m256i_result = (__m256i){0xffe1ffe0ffe1ffe0, 0x01ff0020ff1f001f,
                             0xffe1ffe0ffe1ffe0, 0x01ff0020ff1f001f};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0002000000020000, 0x0002000000020000,
                             0x0002000000020000, 0x0002000000020000};
  __m256i_out = __lasx_xvbitseti_w((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000800,
                             0xffffffffffffffff, 0x0000000000000800};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007f7f00007fff, 0x0000000000000000,
                      0x00007f7f00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00007f7f00007fff, 0x0000040000000000,
                             0x00007f7f00000000, 0x0000040000000000};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x2a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000800000000, 0x0000000800000000,
                             0x0000000800000000, 0x0000000800000000};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000004000000, 0x0000000004000000,
                             0x0000000004000000, 0x0000000004000000};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000020, 0x0000000000000020,
                             0x0000000000000020, 0x0000000000000020};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000200, 0x0000000000000200,
                             0x0000000000000200, 0x0000000000000200};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffeffebfb7afb62, 0x0000000000000000,
                      0xfffeffebfb7afb62, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffeffebfb7afb62, 0x0000000000000800,
                             0xfffeffebfb7afb62, 0x0000000000000800};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003f780000ff80, 0xf7f8f7f80000fff9,
                      0x00003f780000ff80, 0xf7f8f7f8f800f800};
  __m256i_result = (__m256i){0x00003f784000ff80, 0xf7f8f7f84000fff9,
                             0x00003f784000ff80, 0xf7f8f7f8f800f800};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffefef800, 0x0000000000000000,
                      0xfffffffffefef800, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffefef800, 0x0000008000000000,
                             0xfffffffffefef800, 0x0000008000000000};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvbitseti_d((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
