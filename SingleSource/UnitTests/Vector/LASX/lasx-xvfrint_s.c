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

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrne_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff,
                      0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrintrne_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrintrne_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000001, 0x01010101, 0x01010101, 0x01010101,
                      0x00000001, 0x01010101, 0x01010101, 0x01010101};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrne_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000303, 0x00000000, 0x00000000, 0x00000000,
                      0x00000300, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfffffffe, 0xffffffff, 0xfffffffe, 0xffffffff,
                      0xfffffefc, 0xfffffffe, 0xfffffffe, 0xffffffff};
  __m256i_result = (__m256i){0xfffffffffffffffe, 0xfffffffffffffffe,
                             0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0x0001c4e8, 0x00000000, 0x00000000,
                      0xffffffff, 0x0001c4e8, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x80000000, 0x80000000,
                      0xffffffff, 0xffffffff, 0x80000000, 0x80000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x8000000080000000,
                             0xffffffffffffffff, 0x8000000080000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfc000000, 0xf5fffc00, 0xfc000000, 0xf5fffc00,
                      0xfc000000, 0xf5fffc00, 0xfc000000, 0xf5fffc00};
  __m256i_result = (__m256i){0xf5fffc00fc000000, 0xf5fffc00fc000000,
                             0xf5fffc00fc000000, 0xf5fffc00fc000000};
  __m256i_out = __lasx_xvfrintrz_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xaaaaaaac, 0x55555555, 0x36aaaaac, 0x55555555,
                      0xaaaaaaac, 0x55555555, 0x36aaaaac, 0x55555555};
  __m256i_result = (__m256i){0x5555555580000000, 0x555555553f800000,
                             0x5555555580000000, 0x555555553f800000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0xbb954b00, 0xffff8845,
                      0x00000000, 0x00000000, 0x8a023680, 0xffffc741};
  __m256i_result = (__m256i){0x0000000000000000, 0xffff884580000000,
                             0x0000000000000000, 0xffffc74180000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000,
                      0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00610000, 0x00612000, 0x01610000, 0x00200101,
                      0x00610000, 0x00612000, 0x01610000, 0x00200101};
  __m256i_result = (__m256i){0x3f8000003f800000, 0x3f8000003f800000,
                             0x3f8000003f800000, 0x3f8000003f800000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x01010101, 0xfefefefe, 0x00000000, 0x00000000,
                      0x01010101, 0xfefefefe, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xfefefefe3f800000, 0x0000000000000000,
                             0xfefefefe3f800000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffff00, 0xfffffffe, 0x1c1c1c1c, 0x1c1c1c1c,
                      0xffffff00, 0xfffffffe, 0x1c1c1c1c, 0x1c1c1c1c};
  __m256i_result = (__m256i){0xfffffffeffffff00, 0x3f8000003f800000,
                             0xfffffffeffffff00, 0x3f8000003f800000};
  __m256i_out = __lasx_xvfrintrp_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00080000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000008, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0x0000ffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0x0000ffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0x00000000ffffffff, 0xffffffffffffffff,
                             0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1,
                      0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1};
  __m256i_result = (__m256i){0x0000000000000000, 0x5d20a0a15d20a0a1,
                             0x0000000000000000, 0x5d20a0a15d20a0a1};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x001d001d, 0x00000000,
                      0x00000000, 0x00000000, 0x001d001d, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000033, 0x00000000, 0x00000000, 0x00000000,
                      0x00000033, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000001, 0x00000000, 0x00000000, 0x00000000,
                      0x00000001, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrintrm_s((__m256)v8i32_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffff605a, 0xffffffff, 0xffff5f5c, 0xffffffff,
                      0xffff605a, 0xffffffff, 0xffff5f5c, 0xffffffff};
  v8i32_result = (v8i32){0xffff605a, 0xffffffff, 0xffff5f5c, 0xffffffff,
                         0xffff605a, 0xffffffff, 0xffff5f5c, 0xffffffff};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x45c5c5c5, 0x45c5c5c5, 0xc5c5c5c4, 0xc5c5c5c4,
                      0x45c5c5c5, 0x45c5c5c5, 0xc5c5c5c4, 0xc5c5c5c4};
  v8i32_result = (v8i32){0x45c5c800, 0x45c5c800, 0xc5c5c800, 0xc5c5c800,
                         0x45c5c800, 0x45c5c800, 0xc5c5c800, 0xc5c5c800};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000f221, 0x0000781e, 0xffff6f20, 0x00000000,
                      0x0000f221, 0x0000781e, 0xffff6f20, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0xffff6f20, 0x00000000,
                         0x00000000, 0x00000000, 0xffff6f20, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffff4738, 0xfffffff5, 0xffffb3b4, 0x00000000,
                      0xffff4738, 0xfffffff5, 0xffffb3b4, 0x00000000};
  v8i32_result = (v8i32){0xffff4738, 0xfffffff5, 0xffffb3b4, 0x00000000,
                         0xffff4738, 0xfffffff5, 0xffffb3b4, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00ff0000, 0x00000000, 0x00ff0000, 0x00000000,
                      0x00ff0000, 0x00000000, 0x00ff0000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00014022, 0x00003fe9, 0x00013feb, 0x00003fea,
                      0x00014022, 0x00003fe9, 0x00013feb, 0x00003fea};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfrint_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
