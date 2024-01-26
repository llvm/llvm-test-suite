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
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000003fefd, 0x0000000000000000,
                      0xffffffff020afefc, 0xffffffff0001ff02};
  v4u64_op1 = (v4u64){0x0003fffc00060000, 0x0000000000000000,
                      0x0209fefb08140000, 0x000000000000ffff};
  __m256i_result = (__m256i){0x00000000000cfefd, 0x0000000000000000,
                             0xffffffff02a0fefc, 0xffffffff0001ff04};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000007fee, 0x0000000000007fee,
                      0x0000000000007fee, 0x0000000000007fee};
  v4u64_op1 = (v4u64){0x7fefffffffffffff, 0x7fefffffffffffff,
                      0x7fefffffffffffff, 0x7fefffffffffffff};
  __m256i_result = (__m256i){0x000000000000fedd, 0x000000000000fedd,
                             0x000000000000fedd, 0x000000000000fedd};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x805f0000ffffffff, 0x0000000000000001,
                      0x805f0000ffffffff, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x805f0000ffffffff, 0x0000000000000001,
                      0x805f0000ffffffff, 0x0000000000000001};
  __m256i_result = (__m256i){0x80be0000ffffffff, 0x0000000000000080,
                             0x80be0000ffffffff, 0x0000000000000080};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x386000003df80000,
                      0x0000000000000000, 0x386000003df80000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00ca0000fff80000,
                      0x0000000000000000, 0x00ca0000fff80000};
  __m256i_result = (__m256i){0x0000000000000000, 0x381800007af80000,
                             0x0000000000000000, 0x381800007af80000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0607ffff0607, 0xffff0607ffff0607,
                      0xffff0607ffff0607, 0xffff0607ffff0607};
  v4u64_op1 = (v4u64){0x00000000faf3f3f2, 0x00000000f9f9f9f9,
                      0x00000000faf3f3f2, 0x00000000f9f9f9f9};
  __m256i_result = (__m256i){0xffff0607ffffc0c1, 0xffff0607ffff0383,
                             0xffff0607ffffc0c1, 0xffff0607ffff0383};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffefff80, 0x00000000000000b7,
                      0xffffffffffefff80, 0x00000000000000b7};
  v4u64_op1 = (v4u64){0x0000000001fff000, 0x0000000000000000,
                      0x0000000001fff000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffdfff80, 0x00000000000000b7,
                             0xffffffffffdfff80, 0x00000000000000b7};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0001000100800000, 0x0001000100010001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x00ff00ff00000007,
                      0x00000000000000e7, 0x00ff00ff00000007};
  v4u64_op1 = (v4u64){0x000100010001fffa, 0xff02ff020001fffa,
                      0x000000000000ff19, 0xff01ff010000fff9};
  __m256i_result = (__m256i){0x00000000000001c0, 0xc03fc03f000001c0,
                             0x0000000000007380, 0x807f807f00000380};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7f7f7f7f7f7f7f7f,
                      0x7f7f7f7f7f7f7f7f, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7f7f7f7f7f7f7f7f,
                             0x7f7f7f7f7f7f7f7f, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000f0,
                      0x00000000000000f0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000000000f0,
                             0x00000000000000f0, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff457db03f, 0x00000000457db03e,
                      0xffffffff457db03f, 0x00000000457db03e};
  v4u64_op1 = (v4u64){0x0000000f0000000f, 0x0000000f0000000f,
                      0x0000000f0000000f, 0x0000000f0000000f};
  __m256i_result = (__m256i){0xffffffff457d607f, 0x00000000457d607d,
                             0xffffffff457d607f, 0x00000000457d607d};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000403e00004040, 0x000086fe0000403e,
                      0x0000403e00004040, 0x000086fe0000403e};
  v4u64_op1 = (v4u64){0x0000403e00004040, 0x000086fe0000403e,
                      0x0000403e00004040, 0x000086fe0000403e};
  __m256i_result = (__m256i){0x000000f900004040, 0x00001bfa000000f9,
                             0x000000f900004040, 0x00001bfa000000f9};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffff0000,
                      0x0000000000000000, 0x00000000ffff0000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffff0000,
                             0x0000000000000000, 0x00000000ffff0000};
  __m256i_out = __lasx_xvrotr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000003fefd, 0x0000000000000000,
                      0xffffffff020afefc, 0xffffffff0001ff02};
  __m256i_result = (__m256i){0x7fff7ffffffbfffb, 0x0000000000000000,
                             0xfffefffefff7fff7, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x8000000080000000,
                      0xffffffffffffffff, 0x8000000080000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                             0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x07ffffff07ffffff, 0x7fffffff7fffffff,
                      0x07ffffff07ffffff, 0x7fffffff7fffffff};
  v4u64_op1 = (v4u64){0x07ffffff07ffffff, 0x7fffffff7fffffff,
                      0x07ffffff07ffffff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x0ffffffe0ffffffe, 0xfffffffefffffffe,
                             0x0ffffffe0ffffffe, 0xfffffffefffffffe};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffff0001, 0x0000000000000000,
                      0x00000000ffff0001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ff00, 0x0000000000000000,
                      0x000000000000ff00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000007f433c79, 0x0000000000000000,
                      0x000000007f433c79, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000007f8000, 0x0000000000000000,
                             0x00000000007f8000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000010000000001, 0xffffffffffffffff,
                      0x0000000000000001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffffe40, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000fffffe40, 0x00000000ffffffff,
                             0x00000000ffff8c80, 0x00000000ffffffff};
  __m256i_out = __lasx_xvrotr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                      0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001fc0200060047a, 0xffe0047d00e00480,
                      0x001fc0200060047a, 0xffe0047d00e00480};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x001fc0200060047a, 0xffe0047d00e00480,
                             0x001fc0200060047a, 0xffe0047d00e00480};
  __m256i_out = __lasx_xvrotr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7ff8000000000000, 0x7ff8000000000000,
                      0x7ff8000000000000, 0x7ff8000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000000,
                             0x0000000000000040, 0x0000000000000000};
  __m256i_out = __lasx_xvrotr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
