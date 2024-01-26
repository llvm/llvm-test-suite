#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2, v4u64_result;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2, v8i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0x5980000000000000, 0x0000000000000000,
                      0x5980000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x41d6600000000000,
                         0x0000000000000000, 0x41d6600000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffa2beb040, 0x0000000022beb03f,
                      0x7fffffffa2beb040, 0x0000000022beb03f};
  v4u64_result = (v4u64){0xc1d75053f0000000, 0x41dfffffffc00000,
                         0xc1d75053f0000000, 0x41dfffffffc00000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000001f, 0x0000000000000000,
                      0x000000000000001f, 0x0000000000000000};
  v4u64_result = (v4u64){0x403f000000000000, 0x0000000000000000,
                         0x403f000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00f7000000f70006, 0x0000000000000000,
                      0x00f7000000f70006, 0x0000000000000000};
  v4u64_result = (v4u64){0x416ee000c0000000, 0x416ee00000000000,
                         0x416ee000c0000000, 0x416ee00000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff000000000080, 0x0000000000000000,
                      0x00ff000000000080, 0x0000000000000000};
  v4u64_result = (v4u64){0x4060000000000000, 0x416fe00000000000,
                         0x4060000000000000, 0x416fe00000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fc03bbc, 0xfffffffffc01fc01,
                      0x000000003fc03bbc, 0xfffffffffc01fc01};
  v4u64_result = (v4u64){0x41cfe01dde000000, 0x0000000000000000,
                         0x41cfe01dde000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffintl_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0c16e25eb28d27ea, 0xeeffbeb03ba3e6b0,
                      0x5db4b156e2002a78, 0x0e2d5626ff75cdbc};
  v4u64_result = (v4u64){0x41cdd1f358000000, 0xc1b1004150000000,
                         0xc161464880000000, 0x41ac5aac4c000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000006f0000007f, 0x0000000000000000,
                      0x8000006f0000007f, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe161616161614e60, 0xe161616161616161,
                      0xe161616161614e60, 0xe161616161616161};
  v4u64_result = (v4u64){0x41d8585858400000, 0xc1be9e9e9f000000,
                         0x41d8585858400000, 0xc1be9e9e9f000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff00000000, 0x7fff7fff00000000,
                      0x7fff000000000000, 0x7fff000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x41dfffdfffc00000,
                         0x0000000000000000, 0x41dfffc000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000007f3a40, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffa, 0xfffffffffb79fb74,
                      0xfffffffffffffffa, 0xfffffffffb79fb74};
  v4u64_result = (v4u64){0xc192181230000000, 0xbff0000000000000,
                         0xc192181230000000, 0xbff0000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xbff0000000000000, 0xbff0000000000000,
                         0xbff0000000000000, 0xbff0000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ffffffff00, 0x0000ffff00000000,
                      0x0000000000ff0000, 0x0000ffff00000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x40efffe000000000,
                         0x0000000000000000, 0x40efffe000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x41dffc0000000000,
                         0x0000000000000000, 0x41dffc0000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffe7ffffffe7, 0xffffffe7ffffffe7,
                      0xffffffe7ffffffe7, 0xffffffe7ffffffe7};
  v4u64_result = (v4u64){0xc039000000000000, 0xc039000000000000,
                         0xc039000000000000, 0xc039000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffinth_d_w((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
