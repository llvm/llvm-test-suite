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
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0000000000080, 0xfff0000000000000,
                      0xfff0000000000080, 0xfff0000000000000};
  __m256i_result = (__m256i){0x0000000000004000, 0x7f80780000000000,
                             0x0000000000004000, 0x7f80780000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffefe00000000, 0xffffffffffffffff,
                      0xfffffefefffffefe, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x03fc03fc03f803f8,
                             0x03fc03fc03f803f8, 0x03fc03fc03f803f8};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x01fe01fe01fe01fe, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff8000000000000, 0x1f0fdf7f3e3b31d4,
                      0x7ff8000000000000, 0x1f0fdf7f3e3b31d4};
  __m256i_result = (__m256i){0x0000000000000000, 0x01fc03e000000000,
                             0x0000000000000000, 0x01fc03e000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00fe01e000000000,
                             0x0000000000000000, 0x00fe01e000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x07fed3c8f7ad28d0, 0x07fee332883f86b0,
                      0x07fed3c8f7ad28d0, 0x07fee332883f86b0};
  __m256i_result = (__m256i){0x3dc02b400a003400, 0x01c03f8034c03200,
                             0x3dc02b400a003400, 0x01c03f8034c03200};
  __m256i_out = __lasx_xvsllwil_hu_bu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00aa000000ac00fe, 0x0000000000000054,
                      0x00aa000000ac00fe, 0x0000000000000054};
  __m256i_result = (__m256i){0x0002b0000003f800, 0x0002a80000000000,
                             0x0002b0000003f800, 0x0002a80000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x41d8585858400000, 0xc1be9e9e9f000000,
                      0x41d8585858400000, 0xc1be9e9e9f000000};
  __m256i_result = (__m256i){0x1610000000000000, 0x1076000016160000,
                             0x1610000000000000, 0x1076000016160000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000ffff0000000d,
                      0x0000000000000000, 0x0000ffff0000000d};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_result = (__m256i){0x0000000000008000, 0x7fff80007fff0000,
                             0x0000000000008000, 0x7fff80007fff0000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_wu_hu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x311d73ad3ec2064a, 0x0000000000000001,
                      0x0000000000007f00, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000fb0819280000, 0x0000c475ceb40000,
                             0x00000001fc000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000ff0000, 0x0000000000000000,
                             0x0000000000ff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  __m256i_result = (__m256i){0x0004040404000000, 0x0004040404000000,
                             0x0004040404000000, 0x0004040404000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000007c8, 0x0000000000000000,
                      0x00000000000007c8, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000007c8, 0x0000000000000000,
                             0x00000000000007c8, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000430207f944, 0x0000000000000000,
                      0x000000430207f944, 0x0000000000000000};
  __m256i_result = (__m256i){0x00040ff288000000, 0x0000000086000000,
                             0x00040ff288000000, 0x0000000086000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000fff000000000, 0x0000000000000000,
                      0x0000fff000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000001ffe00000,
                             0x0000000000000000, 0x00000001ffe00000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80000000ffc8ff88, 0x8000000080000000,
                      0x80000000ffc8ff88, 0x8000000080000000};
  __m256i_result = (__m256i){0x0001ff91ff100000, 0x0001000000000000,
                             0x0001ff91ff100000, 0x0001000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000008c, 0x0000000000000000,
                      0x000000000000008c, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001180000000, 0x0000000000000000,
                             0x0000001180000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsllwil_du_wu((__m256)v4u64_op0, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
