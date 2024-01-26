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

  v4u64_op0 = (v4u64){0x800080008000b8f1, 0x8000800080008000,
                      0xffff80008000ffff, 0x8000ffff8000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0xffff00000000ffff, 0x0000ffff0000ffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x074132a240000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x800080008000b8f1, 0x8000800080008000,
                             0x06f880008000ffff, 0x8000ffff8000ffff};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefe00000000, 0xffffffffffffffff,
                      0xfffffefefffffefe, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000004000000040, 0x0000004000000040,
                      0x0000004000000040, 0x0000004000000040};
  v4u64_op1 = (v4u64){0x00000000000000c0, 0x00000000000000c0,
                      0x00000000000000c0, 0x00000000000000c0};
  v4u64_op2 = (v4u64){0x0000001658166830, 0x0000000000000000,
                      0x00000012481e4950, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000004000000040, 0x0000004000000040,
                             0x0000004000000040, 0x0000004000000040};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                             0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1f60010000080100, 0x0000000000000000,
                      0x1f60010000080100, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x1fa0000000080000, 0x0000000000000000,
                      0x1fa0000000080000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1f60010000080100, 0x0000000000000000,
                             0x1f60010000080100, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffeffed, 0xfffffffffffeffed,
                      0xfffffffffffeffed, 0xfffffffffffeffed};
  v4u64_op1 = (v4u64){0xfffffffffffeffed, 0xfffffffffffeffed,
                      0xfffffffffffeffed, 0xfffffffffffeffed};
  v4u64_op2 = (v4u64){0xc039000000000000, 0xc039000000000000,
                      0xc039000000000000, 0xc039000000000000};
  __m256i_result = (__m256i){0xbf3ffffffffeffed, 0xbf3ffffffffeffed,
                             0xbf3ffffffffeffed, 0xbf3ffffffffeffed};
  __m256i_out = __lasx_xvmaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x3ff0000000000000, 0x0000000000000000,
                      0x3ff0000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x3ff0000000000000, 0x0000000000000000,
                      0x3ff0000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0ff80100ffffffff, 0x0000000000000000,
                             0x0ff80100ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000003ff000003ff,
                      0x0000000000000000, 0x000003ff000003ff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xfffffefe00000000, 0xffffffffffffffff,
                      0xfffffefefffffefe, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x000003ff000003ff,
                             0x0000000000000000, 0x000003ff000003ff};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x363c0000fff3c000, 0x3380000000000000,
                      0xfff6e00000000000, 0x34000000fff00000};
  v4u64_op1 = (v4u64){0xf3317da580000000, 0xffffffffb71c413b,
                      0xfffffffffc1e0049, 0xffffffffb7146213};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x363c0000fff3c000, 0x3380000000000000,
                             0xfff6e00000000000, 0x34000000fff00000};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000010000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                      0xfff0000000000000, 0xfff0000000000000};
  v4u64_op2 = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                      0xfff0000000000000, 0xfff0000000000000};
  __m256i_result = (__m256i){0xffe000ffffffffff, 0xffe000ffffffffff,
                             0xffe000ffffffffff, 0xffe000ffffffffff};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3dc02b400a003400, 0x01c03f8034c03200,
                      0x3dc02b400a003400, 0x01c03f8034c03200};
  v4u64_op1 = (v4u64){0x3dc02b400a003400, 0x01c03f8034c03200,
                      0x3dc02b400a003400, 0x01c03f8034c03200};
  v4u64_op2 = (v4u64){0x07fed3c8f7ad28d0, 0x07fee332883f86b0,
                      0x07fed3c8f7ad28d0, 0x07fee332883f86b0};
  __m256i_result = (__m256i){0x3fadafc013acf600, 0x01ce3c0050d32d40,
                             0x3fadafc013acf600, 0x01ce3c0050d32d40};
  __m256i_out = __lasx_xvmaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffecffffffec, 0xffffffecffffffec,
                      0xffffffecffffffec, 0xffffffecffffffec};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6,
                      0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6};
  __m256i_result = (__m256i){0xffffffecffffffec, 0xffffffecffffffec,
                             0xffffffecffffffec, 0xffffffecffffffec};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x0000000000000000,
                      0x8000000080000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffff00000100,
                      0xfffffffffffffefd, 0xffffffff00000100};
  v4u64_op1 = (v4u64){0x000000007fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xfffffefdfffffefd, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffff00000100,
                             0x7fffff7d80000000, 0xffffffff00000100};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff01fefffeff02, 0x000000000001fefe,
                      0x000001fdfffffe02, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0xffff01fefffeff02, 0x000000000001fefe,
                             0x000001fdfffffe02, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffddffdeffb5ff8d, 0xfffdfffffffdffff,
                      0xffddffdeffb5ff8d, 0xfffdfffffffdffff};
  v4u64_op1 = (v4u64){0x1010100f10100fd4, 0x0000ffffffeeffaf,
                      0x1010100f10100fd4, 0x0000ffffffeeffaf};
  v4u64_op2 = (v4u64){0xffddffdeffb5ff8d, 0xfffdfffffffdffff,
                      0xffddffdeffb5ff8d, 0xfffdfffffffdffff};
  __m256i_result = (__m256i){0x0febedc9bb95dd8f, 0xfffefffcffff0000,
                             0x0febedc9bb95dd8f, 0xfffefffcffff0000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000fe, 0x0000000000000000,
                      0x00000000000000fe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000545400,
                      0x0000000000000000, 0x0000000000545400};
  v4u64_op2 = (v4u64){0x0000000000000000, 0xffff040000000000,
                      0x0000000000000000, 0xffff040000000000};
  __m256i_result = (__m256i){0x00000000000000fe, 0x0000000000000000,
                             0x00000000000000fe, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000002, 0xffffffff00000001,
                      0x0000000000000002, 0xffffffff00000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000002, 0xffffffff00000001,
                      0x0000000000000002, 0xffffffff00000001};
  __m256i_result = (__m256i){0x0000000000000002, 0xffffffff00000001,
                             0x0000000000000002, 0xffffffff00000001};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000180007fe8, 0x000000017bfffff0,
                      0x0000000180007fe8, 0x000000017bfffff0};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffff80007fe9, 0xffffffff7bfffff1,
                             0xffffffff80007fe9, 0xffffffff7bfffff1};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010511c54440437, 0x0000000000000000,
                      0x0010511c54440437, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000103fca1bd, 0xffffffffffffffff,
                      0x0000000103fca1bd, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000103fca1bd, 0xffffffffffffffff,
                      0x0000000103fca1bd, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0010511c54440438, 0xfffffffe00000001,
                             0x0010511c54440438, 0xfffffffe00000001};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x386000003df80000,
                      0x0000000000000000, 0x386000003df80000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x386000003df80000,
                      0x0000000000000000, 0x386000003df80000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0c6a240000000000,
                             0x0000000000000000, 0x0c6a240000000000};
  __m256i_out = __lasx_xvmaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
