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

  v4u64_op0 = (v4u64){0x49d8080067f4f81f, 0x0000000000000000,
                      0x00007ffffffff7ff, 0x0000000000000000};
  __m256i_result = (__m256i){0xd8490849f467f867, 0x0000000000000000,
                             0x00007f00fffff7ff, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0xb7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0xdb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0x95);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffff5ffff4738, 0x00000000ffffb3b4,
                      0xfffffff5ffff4738, 0x00000000ffffb3b4};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0xee);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0x2f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0x6f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_b((__m256)v4u64_op0, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x49d8080067f4f81f, 0x0000000000000000,
                      0x00007ffffffff7ff, 0x0000000000000000};
  __m256i_result = (__m256i){0x080008000800f81f, 0x0000000000000000,
                             0x7fff7fff7ffff7ff, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0xa8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4,
                      0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4};
  __m256i_result = (__m256i){0xc5c545c545c545c5, 0xc5c4c5c5c5c5c5c5,
                             0xc5c545c545c545c5, 0xc5c4c5c5c5c5c5c5};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0x3d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0xf7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0x3a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x00000000ffff0000, 0x00000000ffff0000,
                             0x00000000ffff0000, 0x00000000ffff0000};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0xa7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  __m256i_result = (__m256i){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                             0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0xdc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff8001ffff0001, 0x00000000ffff0020,
                      0xffff8001ffff0001, 0x00000000ffff0020};
  __m256i_result = (__m256i){0xffff8001ffff8001, 0xffff000000000000,
                             0xffff8001ffff8001, 0xffff000000000000};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0x6e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0x9f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_result = (__m256i){0x04f504f104f504f5, 0x0002ffff00020002,
                             0x04f504f104f504f5, 0x0002ffff00020002};
  __m256i_out = __lasx_xvshuf4i_h((__m256)v4u64_op0, 0x65);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1e18000000000000, 0x1e18000000000000,
                      0x1e18000000000000, 0x1e18000000000000};
  __m256i_result = (__m256i){0x1e18000000000000, 0x1e1800001e180000,
                             0x1e18000000000000, 0x1e1800001e180000};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0xfe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0x64);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4,
                      0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4};
  __m256i_result = (__m256i){0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4,
                             0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0xb0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x79f9f9f900f9f900, 0x0000000000f9f900,
                      0x79f9f9f900f9f9e0, 0x0000000000f9f900};
  __m256i_result = (__m256i){0x79f9f9f900000000, 0x00f9f90079f9f9f9,
                             0x79f9f9f900000000, 0x00f9f90079f9f9f9};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0x97);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffd017d00, 0x000000007aff7c00,
                      0xfffffffffd017d00, 0x000000007aff7c00};
  __m256i_result = (__m256i){0xfd017d0000000000, 0x7aff7c0000000000,
                             0xfd017d0000000000, 0x7aff7c0000000000};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0xb3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0,
                      0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0};
  __m256i_result = (__m256i){0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0,
                             0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0x3c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0xf4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff81ff7d, 0xffffffffffffffff,
                      0xffffffffff81ff7d, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffff81ff7d, 0xff81ff7dffffffff,
                             0xffffffffff81ff7d, 0xff81ff7dffffffff};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0x28);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000020ff790020, 0x0000002000000000,
                      0x00000020ff790020, 0x0000002000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000000000000000,
                             0x0000002000000020, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_w((__m256)v4u64_op0, 0xa5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x01010101d58efe94,
                      0x0101010101010101, 0x0101010183f95466};
  __m256i_result = (__m256i){0x01010101d58efe94, 0xffffffffffffffff,
                             0x0101010183f95466, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00001fff00001fff, 0x00001fff00001fff,
                      0x00001fff00001fff, 0x00001fff00001fff};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x00001fff00001fff, 0x00001fff00001fff,
                             0x00001fff00001fff, 0x00001fff00001fff};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000f1002, 0xffffffff80be0000,
                      0x000000000f0f0002, 0xffffffff80be0000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x80000000ff800000,
                      0x8000000080000000, 0x80000000ff800000};
  __m256i_result = (__m256i){0x80000000ff800000, 0x8000000080000000,
                             0x80000000ff800000, 0x8000000080000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xdb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x43ef878780000009, 0x0000000080000009,
                      0x43ef878780000009, 0x0000000080000009};
  __m256i_result = (__m256i){0x43ef878780000009, 0x0000000000000000,
                             0x43ef878780000009, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x36);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff00017fff0000, 0x7fff00017fff0000,
                      0x7fff00017fff0000, 0x7fff00017fff0000};
  v4u64_op1 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_result = (__m256i){0x04f104f104f504ed, 0x0000ffff0002fffd,
                             0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_out = __lasx_xvshuf4i_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
