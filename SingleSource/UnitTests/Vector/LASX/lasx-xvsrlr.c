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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000007fffffff,
                      0x0000000000000000, 0x000000007fffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000000007fffffff,
                      0x0000000000000000, 0x000000007fffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000001020202,
                             0x0000000000000000, 0x0000000001020202};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7c00000880008000, 0x00000000ffffffff,
                      0x7c00000880008000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0100000001000100, 0x00000000ffffffff,
                             0x0100000001000100, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x7fff7fff7fff7fff, 0x0000038000000268,
                      0x7fff7fff7fff7fff, 0x0000038000000268};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000001,
                             0x0000000000000000, 0x0000000000000001};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ff01, 0x0000ff0100ff0000,
                      0x000000000000ff01, 0x0000ff0100ff0000};
  v4u64_op1 = (v4u64){0xffffffffff010ff0, 0x0000000000000000,
                      0xffffffffff010ff0, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000201, 0x0000ff0100ff0000,
                             0x0000000000000201, 0x0000ff0100ff0000};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000800400010006d, 0x0000000000000000,
                      0x000800400010006d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffc00040, 0x0000000000000000,
                      0xffffffffffc00040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_result = (__m256i){0x1080108010060002, 0x0000000000000000,
                             0x1080108010060002, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x40d74f979f99419f, 0x00000000ffff0000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x40d74f979f99419f, 0x00000000ffff0000,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x0000ffff00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7ff0000000000000, 0x7ff0000000000000,
                             0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f007f0081007f, 0x009f00f8007e00f0,
                      0x007f007f0081007f, 0x009f00f8007e00f0};
  v4u64_op1 = (v4u64){0x0e459089665f40f3, 0x1189ce8000fa14ed,
                      0x00a21ef3246995f3, 0x0ea85f60984a8555};
  __m256i_result = (__m256i){0x0004000000000010, 0x000000f800000000,
                             0x0020001000000010, 0x000100f800000008};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fc00000428a, 0xffffc040ffffc09d,
                      0x00003fc00000428a, 0xffffc040ffffc09d};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0xffffc040ffffc09d,
                             0x0000000000000001, 0xffffc040ffffc09d};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f7f7f7f7f7f7f, 0x7f7f000000000000,
                      0x007f7f7f7f7f7f7f, 0x7f7f000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000100010001, 0x0001000000000000,
                             0x0000000100010001, 0x0001000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x80000000ff800000,
                      0x8000000080000000, 0x80000000ff800000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x000000000000ffff,
                             0x000000000000ffff, 0x000000000000ffff};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000064, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000064, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000200000008, 0x0000000000000000,
                      0x0000000200000008, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000200000008, 0x0000000000000000,
                             0x0000000200000008, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000430207f944, 0x0000000000000000,
                      0x000000430207f944, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000ffffff80,
                      0x0000000000000000, 0x00000000ffffff80};
  __m256i_result = (__m256i){0x000000430207f944, 0x0000000000000000,
                             0x000000430207f944, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000007f0000,
                      0x0000000000000000, 0x00000000007f0000};
  v4u64_op1 = (v4u64){0x000000000010006d, 0x0000000000080040,
                      0x000000000010006d, 0x0000000000080040};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  v4u64_op1 = (v4u64){0x0000000000000080, 0x0000000000000002,
                      0x0000000000000080, 0x0000000000000002};
  __m256i_result = (__m256i){0xff1cff1cff1cff1c, 0xff1cff1cff1c3fc7,
                             0xff1cff1cff1cff1c, 0xff1cff1cff1c3fc7};
  __m256i_out = __lasx_xvsrlr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff8080000000000, 0x0000000000000000,
                      0x0000080000000000, 0xfff8080000004000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000200000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000200000000};
  __m256i_out = __lasx_xvsrlr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvsrlr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000ffff0000ffff,
                      0x0000000000000000, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000ffff0000ffff,
                             0x0000000000000000, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvsrlr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000200000002, 0x0000000200000002,
                      0x0000000200000002, 0x0000000200000002};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000f0f0f0f0f0f0,
                      0x0000000000000000, 0x0000f0f0f0f0f0f0};
  v4u64_op1 = (v4u64){0xff01ff01ff01f010, 0xff01ff01ff01f010,
                      0xff01ff01ff01f010, 0xff01ff01ff01f010};
  __m256i_result = (__m256i){0x0000000000000000, 0x000078780000f0f1,
                             0x0000000000000000, 0x000078780000f0f1};
  __m256i_out = __lasx_xvsrlr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0000000000080, 0xfff0000000000000,
                      0xfff0000000000080, 0xfff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff0000000000080, 0xfff0000000000000,
                             0xfff0000000000080, 0xfff0000000000000};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x6300000000000000,
                      0x0000000000000000, 0x6300000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x6300000000000000,
                             0x0000000000000000, 0x6300000000000000};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00003ddd80007bbb, 0x0000000000002222,
                      0x00003ddd80007bbb, 0x0000000000002222};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffff800000000000, 0xffff800000000000,
                             0xffff800000000000, 0xffff800000000000};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffff1fffffff1, 0xfffffff1fffffff1,
                      0xfffffff1fffffff1, 0xfffffff1fffffff1};
  v4u64_op1 = (v4u64){0xfffffff1fffffff1, 0xfffffff1fffffff1,
                      0xfffffff1fffffff1, 0xfffffff1fffffff1};
  __m256i_result = (__m256i){0x0000000000008000, 0x0000000000008000,
                             0x0000000000008000, 0x0000000000008000};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf2b180c9fc1fefdc, 0xffffffff01fb0408,
                      0xf2b180c9fc1fefdc, 0xffffffff01fb0408};
  v4u64_op1 = (v4u64){0xffffffffffefff80, 0x00000000000000b7,
                      0xffffffffffefff80, 0x00000000000000b7};
  __m256i_result = (__m256i){0xf2b180c9fc1fefdc, 0x0000000000000200,
                             0xf2b180c9fc1fefdc, 0x0000000000000200};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b,
                      0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b};
  v4u64_op1 = (v4u64){0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b,
                      0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b};
  __m256i_result = (__m256i){0x00000000000d6d6d, 0x00000000000d6d6d,
                             0x00000000000d6d6d, 0x00000000000d6d6d};
  __m256i_out = __lasx_xvsrlr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
