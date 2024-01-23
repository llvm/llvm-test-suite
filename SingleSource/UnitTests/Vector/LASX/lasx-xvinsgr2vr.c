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

  v4u64_op0 = (v4u64){0x0202020201010000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0xeef14fe8;
__m256i_result = (__m256i){0x0202020201010000, 0x0000000000000000,
                             0x00000000eef14fe8, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x012e2110012e2110, 0x0000000000000000,
                      0x0000000200000000, 0x0000000000000000};
  int_op1 = 0x00000000000000ac;
__m256i_result = (__m256i){0x012e2110012e2110, 0x00000000000000ac,
                             0x0000000200000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff800000ff800000, 0xff800000ff800000,
                      0xff800000ff800000, 0xff800000ff800000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xff80000000000000, 0xff800000ff800000,
                             0xff800000ff800000, 0xff800000ff800000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff0000ff, 0x00000000000000ff,
                      0xffffffffff0000ff, 0x00000000000000ff};
  int_op1 = 0x00000000000000ff;
__m256i_result = (__m256i){0xffffffffff0000ff, 0x000000ff000000ff,
                             0xffffffffff0000ff, 0x00000000000000ff};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff383efffedf0c, 0xe800c000fffeeece,
                      0xffff383efffedf0c, 0xe800c000fffeeece};
  int_op1 = 0x00000000000000ff;
__m256i_result = (__m256i){0xffff383efffedf0c, 0xe800c000fffeeece,
                             0xffff383e000000ff, 0xe800c000fffeeece};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x4040404040404040, 0x0000000040404040,
                             0x4040404040404040, 0x4040404040404040};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffff7fffffff7, 0xfffffff7fffffff7,
                      0xfffffff7fffffff7, 0xfffffff7fffffff7};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xfffffff7fffffff7, 0xfffffff700000000,
                             0xfffffff7fffffff7, 0xfffffff7fffffff7};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000d6d6d, 0x0000000000000000,
                      0x00000000000d6d6d, 0x0000000000000000};
  int_op1 = 0x00000000090b0906;
__m256i_result = (__m256i){0x00000000000d6d6d, 0x0000000000000000,
                             0x00000000090b0906, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000000000001e;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000001e00000000};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfefefefefefefefe, 0x0005000500050005,
                      0xfefefefefefefefe, 0x0005000500050005};
  int_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0xfefefefefefefefe, 0x0000000000050005,
                             0xfefefefefefefefe, 0x0005000500050005};
  __m256i_out = __lasx_xvinsgr2vr_w((__m256)v4u64_op0, int_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf19998668e5f4b84, 0x36722a7e66972cd6,
                      0x146014141414146e, 0x8b1414140e0e0e0e};
  long_op1 = 0x0000007942652524;
__m256i_result = (__m256i){0xf19998668e5f4b84, 0x36722a7e66972cd6,
                             0x0000007942652524, 0x8b1414140e0e0e0e};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x8000000000000000,
                             0x8000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0020000000200000, 0x0020002000200020,
                      0x0020000000200000, 0x0020002000200020};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0020002000200020,
                             0x0020000000200000, 0x0020002000200020};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000048, 0x0000000000000000,
                      0x0000000000000048, 0x0000000000000000};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000048, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_op1 = 0x00000000000000ff;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x00000000000000ff, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_op1 = 0x0000000000000000;
__m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvinsgr2vr_d((__m256)v4u64_op0, long_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
