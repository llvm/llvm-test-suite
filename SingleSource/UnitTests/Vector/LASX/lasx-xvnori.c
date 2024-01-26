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

  v4u64_op0 = (v4u64){0x8000000080000000, 0x0000000100000001,
                      0x8000000080000000, 0x0000000100000001};
  __m256i_result = (__m256i){0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4,
                             0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x3a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000003373, 0x0000000000000000,
                      0x0000000000007773, 0x0000000000000000};
  __m256i_result = (__m256i){0xbbbbbbbbbbbb8888, 0xbbbbbbbbbbbbbbbb,
                             0xbbbbbbbbbbbb8888, 0xbbbbbbbbbbbbbbbb};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x44);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                             0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xdededededededede, 0xdededededededede,
                             0xdededededededede, 0xdededededededede};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x21);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x33);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x9090909090909090, 0x9090909090909090,
                             0x9090909090909090, 0x9090909090909090};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x6f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0xf7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5858585858585858, 0x5858585858585858,
                             0x5858585858585858, 0x5858585858585858};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0xa7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3d3d3d3d3d3d3d3d, 0x3d3d3d3d3d3d3d3d,
                             0x3d3d3d3d3d3d3d3d, 0x3d3d3d3d3d3d3d3d};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0xc2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000010,
                      0x0000000000000000, 0x0000000000000010};
  __m256i_result = (__m256i){0x9d9d9d9d9d9d9d9d, 0x9d9d9d9d9d9d9d8d,
                             0x9d9d9d9d9d9d9d9d, 0x9d9d9d9d9d9d9d8d};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x62);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a,
                             0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0xd5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000812000008120, 0x000081220000812c,
                      0x0000812000008120, 0x000081220000812c};
  __m256i_result = (__m256i){0xe9e968c9e9e968c9, 0xe9e968c9e9e968c1,
                             0xe9e968c9e9e968c9, 0xe9e968c9e9e968c1};
  __m256i_out = __lasx_xvnori_b((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
