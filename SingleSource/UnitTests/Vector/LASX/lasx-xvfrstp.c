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
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000010, 0x0000000000000000,
                             0x0000000000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffffffffffe, 0xfffffffffffffffe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffff10, 0xfffffffffffffffe,
                             0xffffffffffffff10, 0xfffffffffffffffe};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000010, 0x0000000000000000,
                             0x0000000000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000f0,
                      0x00000000000000f0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfefefefefefefefe, 0xfefefefefefefefe,
                      0xfefefefefefefefe, 0xfefefefefefefefe};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x00000000000000f0,
                      0x00000000000000f0, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000000000f0,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000010, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffe1, 0xffffffffffffffe1,
                      0xffffffffffffffe1, 0xffffffffffffffe1};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffff10, 0xffffffffffffffe1,
                             0xffffffffffffff10, 0xffffffffffffffe1};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x007f007bfffffffb, 0x0000000000000000,
                      0x007f007bfffffffb, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000010000000,
                             0x0000000000000000, 0x0000000010000000};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffe000ffffffffff, 0xffe000ffffffffff,
                      0xffe000ffffffffff, 0xffe000ffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000c040c0,
                      0x0000000000000000, 0x0000000000c040c0};
  v4u64_op2 = (v4u64){0x8000000080000000, 0x00000004843ffdff,
                      0x8000000080000000, 0x00000004843ffdff};
  __m256i_result = (__m256i){0xffe000ffffffff08, 0xffe000ffffffffff,
                             0xffe000ffffffff08, 0xffe000ffffffffff};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0004000500040005, 0x0004000400040004,
                      0x0004000500040005, 0x0004000400040004};
  v4u64_op2 = (v4u64){0x00007fff00000000, 0x00007fff00007fff,
                      0x00007fff00000000, 0x00007fff00007fff};
  __m256i_result = (__m256i){0xffffffffffffff10, 0xffffffffffffffff,
                             0xffffffffffffff10, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrstp_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000007, 0x00ff00ff00000007,
                      0x00000000000000e7, 0x00ff00ff00000007};
  v4u64_op2 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000080000, 0x0000000000000000,
                             0x0000000000000008, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x2020202020202020, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x00007f7f00007fff, 0x0000000000000000,
                      0x00007f7f00000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000007f000000ff, 0x0000000000000000,
                      0x0000007f00340040, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0008010101010101,
                             0x2020202020200008, 0x2020202020202020};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000008, 0x0000ffff0000ffff,
                             0x0000ffff00000008, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x03f7f7f7f7f7f7f7, 0x03f7f7f7f7f7f7f7,
                      0x03f7f7f7f7f7f7f7, 0x03f7f7f7f7f7f7f7};
  v4u64_op2 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000000,
                             0x0000000000000008, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbfbfbfbfbfbfbfbf, 0x0000000000000000,
                      0xbfbfbfbfbfbfbfbf, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x0000000000000000,
                      0x0101010101010101, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xbfbfbfbfbfbfbfbf, 0x0000000000000000,
                      0xbfbfbfbfbfbfbfbf, 0x0000000000000000};
  __m256i_result = (__m256i){0xbfbfbfbfbfbfbfbf, 0x0008000000000000,
                             0xbfbfbfbfbfbfbfbf, 0x0008000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000000,
                             0x0000000000000008, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffb8579f, 0x00000000ffdbbbcf,
                      0x00000000ffb8579f, 0x00000000ffdbbbcf};
  v4u64_op2 = (v4u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc,
                      0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000001,
                             0x0000000000000000, 0x0000000000000001};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000000,
                             0x0000000000000008, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffff0000, 0xffffffffffffffff,
                             0xffffffffffff0000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfrstp_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
