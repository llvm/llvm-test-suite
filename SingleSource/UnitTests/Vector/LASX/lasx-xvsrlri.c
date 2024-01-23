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
                      0x0000000000000505, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0002ffff0001, 0xffff0002fffefffe,
                      0xffff0002ff7e8286, 0xffff0002fffefffe};
  __m256i_result = (__m256i){0x0202000002020000, 0x0202000002020202,
                             0x0202000002010101, 0x0202000002020202};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe1616161e1614e60, 0xe1616161e1614e60,
                      0xe1616161e1614e60, 0xe1616161e1614e60};
  __m256i_result = (__m256i){0x0703030307030203, 0x0703030307030203,
                             0x0703030307030203, 0x0703030307030203};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000040000, 0x0000000000000000,
                      0x0000000000040000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000020000, 0x0000000000000000,
                             0x0000000000020000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x0000038000000268,
                      0x7fff7fff7fff7fff, 0x0000038000000268};
  __m256i_result = (__m256i){0x2040204020402040, 0x000001200000011a,
                             0x2040204020402040, 0x000001200000011a};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_result = (__m256i){0xfffffffe00000001, 0xfffffffe00000001,
                             0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000ff0000, 0x0000000000ff0000,
                      0x0000000000ff0000, 0x0000000000ff0000};
  __m256i_result = (__m256i){0x0000000000800000, 0x0000000000800000,
                             0x0000000000800000, 0x0000000000800000};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000800000, 0x7fffffffffbfffff,
                      0x0000000000800000, 0x7fffffffffbfffff};
  __m256i_result = (__m256i){0x0000000000010000, 0x0102020202010202,
                             0x0000000000010000, 0x0102020202010202};
  __m256i_out = __lasx_xvsrlri_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffff7fffffff, 0x7fffffff7fffffff,
                      0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x0010002000100020, 0x0010002000100020,
                             0x0010002000100020, 0x0010002000100020};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0001, 0xffffffffffffffff,
                      0xffff0000ffff0001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0020000000200000, 0x0020002000200020,
                             0x0020000000200000, 0x0020002000200020};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x132feea900000000, 0x04e8296f18181818,
                      0x132feea900000000, 0x04e8296f18181818};
  __m256i_result = (__m256i){0x132feea900000000, 0x04e8296f18181818,
                             0x132feea900000000, 0x04e8296f18181818};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x7fffffffffffffff,
                      0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x0020004000400040, 0x0020004000400040,
                             0x0020004000400040, 0x0020004000400040};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x0000000000000006,
                      0x8000000000000000, 0x0000000000000006};
  __m256i_result = (__m256i){0x0008000000000000, 0x0000000000000000,
                             0x0008000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000080000000, 0x0000000000000000,
                             0x8000000080000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000000000000000,
                             0x0000001000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x01010101d58efe94,
                      0x0101010101010101, 0x0101010183f95466};
  __m256i_result = (__m256i){0x0000101000001010, 0x00001010000d58f0,
                             0x0000101000001010, 0x0000101000083f95};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x0000000000000000,
                      0x0000000000000007, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff81001dff9d003b, 0xff81001dff9dff9e,
                      0xff81001dff9d003b, 0xff81001dff9dff9e};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000001000000010,
                             0x0000001000000010, 0x0000001000000010};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_w((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x33);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff000000, 0xffffffffff000000,
                      0xffffffffff000000, 0xffffffffff000000};
  __m256i_result = (__m256i){0x0000000001000000, 0x0000000001000000,
                             0x0000000001000000, 0x0000000001000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x28);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003f3f87870000, 0x0000000000000000,
                      0x00003f3fc6c68787, 0x0000000000000000};
  __m256i_result = (__m256i){0x00003f3f87870000, 0x0000000000000000,
                             0x00003f3fc6c68787, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000ff,
                      0x0000000000000000, 0x00000000000000ff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000001,
                             0x0000000000000000, 0x0000000000000001};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000e000e000e000e, 0x0000000000000000,
                      0x000e000e000e000e, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000040000000000, 0x0000040000000000,
                             0x0000040000000000, 0x0000040000000000};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffb009c, 0x00000000fffa003e,
                      0x00000000fffb009c, 0x00000000fffa003e};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000002, 0x0000000000000002};
  __m256i_out = __lasx_xvsrlri_d((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
