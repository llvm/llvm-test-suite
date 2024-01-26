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

  v4u64_op0 = (v4u64){0x0658f2dc0eb21e3c, 0x31730b5beb7c99f5,
                      0xc5c085372cfabfba, 0x372e9d75e8aab100};
  v8i32_result = (v8i32){0x4d6b21e4, 0x4ccb1e5c, 0xcda41b30, 0x4e45cc2d,
                         0x4e33eaff, 0xce68fdeb, 0xcdbaaa78, 0x4e5cba76};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000008000, 0x000000007fff0000,
                      0x0000000000008000, 0x000000007fff0000};
  v8i32_result = (v8i32){0x47000000, 0x00000000, 0x4efffe00, 0x00000000,
                         0x47000000, 0x00000000, 0x4efffe00, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ff00, 0x0000000000000000,
                      0x000000000000ff00, 0x0000000000000000};
  v8i32_result = (v8i32){0x477f0000, 0x00000000, 0x00000000, 0x00000000,
                         0x477f0000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010001000030000, 0x0010001000030000,
                      0x0010001000030000, 0x0010001000030000};
  v8i32_result = (v8i32){0x48400000, 0x49800080, 0x48400000, 0x49800080,
                         0x48400000, 0x49800080, 0x48400000, 0x49800080};
  __m256_out = __lasx_xvffint_s_w((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xbff0000000000000, 0xbff0000000000000,
                         0xbff0000000000000, 0xbff0000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000001700080, 0x0000000000000000,
                      0x0000000001700080, 0x0000000000000000};
  v4u64_result = (v4u64){0x4177000800000000, 0x0000000000000000,
                         0x4177000800000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xc1f0000000000000, 0xbff0000000000000,
                         0xc1f0000000000000, 0xbff0000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x01fe01fe01fe01fe, 0x01fe01fe01fe01fe,
                      0x01fe01fe01fe01fe, 0x01fe01fe01fe01fe};
  v4u64_result = (v4u64){0x437fe01fe01fe020, 0x437fe01fe01fe020,
                         0x437fe01fe01fe020, 0x437fe01fe01fe020};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x132feea900000000, 0x04e8296f18181818,
                      0x132feea900000000, 0x04e8296f18181818};
  v4u64_result = (v4u64){0x43b32feea9000000, 0x4393a0a5bc606060,
                         0x43b32feea9000000, 0x4393a0a5bc606060};
  __m256d_out = __lasx_xvffint_d_l((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x4f800000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffff884580000000,
                      0x0000000000000000, 0xffffc74180000000};
  v8i32_result = (v8i32){0x00000000, 0xd6ef7500, 0xbf800000, 0xbf800000,
                         0x00000000, 0xd662fa00, 0xbf800000, 0xbf800000};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000005000000020, 0x8000000000000000,
                      0x0000005000000020, 0x8000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                      0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  v8i32_result = (v8i32){0x5b7f00ff, 0x5b7f00ff, 0x52a00000, 0xdf000000,
                         0x5b7f00ff, 0x5b7f00ff, 0x52a00000, 0xdf000000};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0a0a0a0a7f0a0a0a, 0x0a0a0a0a7f0a0a0a,
                      0x0a0a0a0a7f0a0a0a, 0x0a0a0a0a7f0a0a0a};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1,
                         0x00000000, 0x00000000, 0x5d20a0a1, 0x5d20a0a1};
  __m256_out = __lasx_xvffint_s_l((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
