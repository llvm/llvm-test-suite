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
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xefdfefdfefdfefdf, 0xefdfefdf00000000,
                      0xefdfefdfefdfefdf, 0xefdfefdf00000000};
  __m256i_result = (__m256i){0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d00000000,
                             0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d00000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x1b1b1b1b1b1b1b1b, 0x1b1b1b1b1b1b1b1b,
                             0x1b1b1b1b1b1b1b1b, 0x1b1b1b1b1b1b1b1b};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  __m256i_result = (__m256i){0x1e1e1e0000000000, 0x1e1e1e0000000000,
                             0x1e1e1e0000000000, 0x1e1e1e0000000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6040190d00000000, 0x6018000000000cd1,
                      0x6040190d00000000, 0x6018000000000cd1};
  __m256i_result = (__m256i){0x0a0a0a0a00000000, 0x0a0a000000000a0a,
                             0x0a0a0a0a00000000, 0x0a0a000000000a0a};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000800400010006d, 0x0000000000000000,
                      0x000800400010006d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0008001c0010001c, 0x0000000000000000,
                             0x0008001c0010001c, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_bu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_hu((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4000000000000000, 0x0000000000000000,
                      0x4000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0007000000000000, 0x0000000000000000,
                             0x0007000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_hu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003ddd80007bbb, 0x0000000000002222,
                      0x00003ddd80007bbb, 0x0000000000002222};
  __m256i_result = (__m256i){0x0000001700170017, 0x0000000000000017,
                             0x0000001700170017, 0x0000000000000017};
  __m256i_out = __lasx_xvmini_hu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_hu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_hu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000af100001455, 0xffffffe400000707,
                      0x00000af100001455, 0xffffffe400000707};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffff61010380,
                      0xffffffff00000000, 0xffffffff61010380};
  __m256i_result = (__m256i){0x0000000000000006, 0x0000000000000006,
                             0x0000000000000006, 0x0000000000000006};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_du((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
