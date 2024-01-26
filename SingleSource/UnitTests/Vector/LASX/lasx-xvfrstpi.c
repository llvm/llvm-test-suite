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
  __m256i_result = (__m256i){0x1000000000000000, 0x0000000000000000,
                             0x1000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000165e0000480d, 0x0000226200005111,
                      0x0000165e0000480d, 0x0000226200005111};
  v4u64_op1 = (v4u64){0xffd8ffc7ffdaff8a, 0x00000000ffffffff,
                      0xffd8ffc7ffdaff8a, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x000016000000480d, 0x0000226200005111,
                             0x000016000000480d, 0x0000226200005111};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff383efffedf0c, 0xe800c0d8fffeeece,
                      0xffff383efffedf0c, 0xe800c0d8fffeeece};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffff383efffedf0c, 0xe800c000fffeeece,
                             0xffff383efffedf0c, 0xe800c000fffeeece};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff000000000000, 0xff00000000000000,
                      0xffff000000000000, 0xff00000000000000};
  v4u64_op1 = (v4u64){0x80000000ff800000, 0x8000000080000000,
                      0x80000000ff800000, 0x8000000080000000};
  __m256i_result = (__m256i){0xffff000200000000, 0xff00000000000000,
                             0xffff000200000000, 0xff00000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffff00ffffffff, 0x0000000000000000,
                             0xffffff00ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000cfffffff3, 0x0000000dfffffff1,
                      0x0000000cfffffff3, 0x0000000dfffffff1};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffff00,
                             0xffffffffffffffff, 0xffffffffffffff00};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010001, 0x0000000000001000,
                             0x0000000000010001, 0x0000000000001000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  v4u64_op1 = (v4u64){0x0000000000008000, 0x000000007fff0000,
                      0x0000000000008000, 0x000000007fff0000};
  __m256i_result = (__m256i){0xfffffffe00000001, 0xff01fffe00000001,
                             0xfffffffe00000001, 0xff01fffe00000001};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0fffffff10000006, 0x0fffffff10000006,
                      0x0fffffff10000006, 0x0fffffff10000006};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x10ffffff10000006, 0x0fffffff10000006,
                             0x10ffffff10000006, 0x0fffffff10000006};
  __m256i_out = __lasx_xvfrstpi_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x683b8b67e20c8ee5, 0xf41a56e8a20878d7,
                      0x5f6108dc25b8e028, 0x38a966b31be83ee9};
  v4u64_op1 = (v4u64){0x00003f4bffff7130, 0x0000740dffffad17,
                      0x00000475ffff4c51, 0xffffcd42ffffecc0};
  __m256i_result = (__m256i){0x683b8b67e20c0001, 0xf41a56e8a20878d7,
                             0x5f6108dc25b80001, 0x38a966b31be83ee9};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000004fb, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffff0008,
                             0xffffffffffffffff, 0xffffffffffff0008};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffff0008ffffffff,
                             0xffffffffffffffff, 0xffff0008ffffffff};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffc0ffc0ffc0ffc0, 0xffc0ffc0ffc0ffc0,
                      0xffc0ffc0ffc0ffc0, 0xffc0ffc0ffc0ffc0};
  v4u64_op1 = (v4u64){0xffffffff9e9eb09e, 0x00ffffff1e9e9e9e,
                      0xffffffff9e9eb09e, 0x00ffffff1e9e9e9e};
  __m256i_result = (__m256i){0xffc00000ffc0ffc0, 0xffc0ffc0ffc0ffc0,
                             0xffc00000ffc0ffc0, 0xffc0ffc0ffc0ffc0};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffffffffffe, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000000,
                             0x0000000000000008, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7c007c0080008000, 0x00000000ffffffff,
                      0x7c007c0080008000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7c00000880008000, 0x00000000ffffffff,
                             0x7c00000880008000, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x457db03e45a87310, 0x457db03e457db03e,
                      0x457db03e45a87310, 0x457db03e457db03e};
  v4u64_op1 = (v4u64){0x000f000000000000, 0x0000000000000000,
                      0x000f000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x457db03e45a87310, 0x0008b03e457db03e,
                             0x457db03e45a87310, 0x0008b03e457db03e};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000000b, 0x000000000000000b,
                      0x000000000000000b, 0x000000000000000b};
  v4u64_op1 = (v4u64){0x0000002000000020, 0x0000002000000020,
                      0x0000002000000020, 0x0000002000000020};
  __m256i_result = (__m256i){0x000000000000000b, 0x000000000008000b,
                             0x000000000000000b, 0x000000000008000b};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0008000000000000, 0x0000000000000000,
                             0x0008000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfrstpi_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
