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

  v4u64_op0 = (v4u64){0x00000000ff00ff00, 0x0000000000000000,
                      0x00000000ff00ff00, 0x0000000000000000};
  __m256i_result = (__m256i){0x01010101fe01fe01, 0x0101010101010101,
                             0x01010101fe01fe01, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000020001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1010101010121011, 0x1010101010101010,
                             0x1010101010101010, 0x1010101010101010};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2020202020202020, 0x2020202020202020,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4040404040404040, 0x4040404040404040,
                             0x4040404040404040, 0x4040404040404040};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff81ff7d, 0xffffffffffffffff,
                      0xffffffffff81ff7d, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7f7f7f7f7f017ffd, 0x7f7f7f7f7f7f7f7f,
                             0x7f7f7f7f7f017ffd, 0x7f7f7f7f7f7f7f7f};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001fc0200060047a, 0xffe0047d00e00480,
                      0x001fc0200060047a, 0xffe0047d00e00480};
  __m256i_result = (__m256i){0x011ec1210161057b, 0xfee1057c01e10581,
                             0x011ec1210161057b, 0xfee1057c01e10581};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe07de0801f20607a, 0xffffffffffffffff,
                      0xe07de0801f20607a, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xe27fe2821d226278, 0xfdfdfdfdfdfdfdfd,
                             0xe27fe2821d226278, 0xfdfdfdfdfdfdfdfd};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000800200028, 0x0000000800200027,
                      0x0000000800200028, 0x0000000800200027};
  __m256i_result = (__m256i){0x0808080008280820, 0x080808000828082f,
                             0x0808080008280820, 0x080808000828082f};
  __m256i_out = __lasx_xvbitrevi_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2000200020002000, 0x2000200020002000,
                             0x2000200020002000, 0x2000200020002000};
  __m256i_out = __lasx_xvbitrevi_h((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0100010001000100, 0x0100010001000100,
                             0x0100010001000100, 0x0100010001000100};
  __m256i_out = __lasx_xvbitrevi_h((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvbitrevi_h((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc039000000000000, 0xc039000000000000,
                      0xc039000000000000, 0xc039000000000000};
  __m256i_result = (__m256i){0xc03b000200020002, 0xc03b000200020002,
                             0xc03b000200020002, 0xc03b000200020002};
  __m256i_out = __lasx_xvbitrevi_h((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff7ff77fff7ff7, 0x0000000800000008,
                             0x7fff7ff77fff7ff7, 0x0000000800000008};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000004000000040, 0x0000004000000040,
                             0x0000004000000040, 0x0000004000000040};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001c4e8ffffffff, 0x0000000000000000,
                      0x0001c4e8ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0081c4e8ff7fffff, 0x0080000000800000,
                             0x0081c4e8ff7fffff, 0x0080000000800000};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000200000002, 0x0000000200000002,
                             0x0000000200000002, 0x0000000200000002};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000800000008, 0x0000000800000008,
                             0x0000000800000008, 0x0000000800000008};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x02000000fdffffff, 0x0200000002000000,
                             0x02000000fdffffff, 0x0200000002000000};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff80007fff0000, 0x0000000000000000,
                      0x7fff80007fff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff81007fff0100, 0x0000010000000100,
                             0x7fff81007fff0100, 0x0000010000000100};
  __m256i_out = __lasx_xvbitrevi_w((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000020000000000, 0x0000020000000000,
                             0x0000020000000000, 0x0000020000000000};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x29);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4000000000000000, 0x4000000000000000,
                             0x4000000000000000, 0x4000000000000000};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x3e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002080100, 0x0000000000000000,
                      0x0000000002080100, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000a080100, 0x0000000008000000,
                             0x000000000a080100, 0x0000000008000000};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000800000000000, 0x0000800000000000,
                             0x0000800000000000, 0x0000800000000000};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x2f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffed, 0xffffffffffffffed,
                      0xffffffffffffffed, 0xffffffffffffffed};
  __m256i_result = (__m256i){0xfffffffffffeffed, 0xfffffffffffeffed,
                             0xfffffffffffeffed, 0xfffffffffffeffed};
  __m256i_out = __lasx_xvbitrevi_d((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
