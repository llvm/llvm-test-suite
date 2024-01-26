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

  v4u64_op0 = (v4u64){0x0000000000000001, 0xfffffffffffffffe,
                      0x0000000000000001, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000000000010, 0xffffffffffffffef,
                             0x0000000000000010, 0xffffffffffffffef};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4000000000000000, 0x4000000000000000,
                      0x4000000000000000, 0x4000000000000000};
  __m256i_result = (__m256i){0x8000000000000000, 0x8000000000000000,
                             0x8000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f0000007f0060, 0x0000000000000000,
                      0x007f0000007f0060, 0x0000000000000000};
  __m256i_result = (__m256i){0x00f7000000f70006, 0x0000000000000000,
                             0x00f7000000f70006, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5ef1f90efefaf30d, 0xde91f010000006f9,
                      0x1729c073816edebe, 0xbea2e127c046721f};
  __m256i_result = (__m256i){0x78af877c7d7f86f9, 0x48ef087800007c83,
                             0x948b39e0b7405f6f, 0x515f93f023600fb9};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1010101010101010, 0x1010101010101010,
                      0x0202020202020202, 0x0202020202020202};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d,
                      0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d};
  __m256i_result = (__m256i){0x4343434343434343, 0x4343434343434343,
                             0x4343434343434343, 0x4343434343434343};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  __m256i_result = (__m256i){0xffffffffffffdffd, 0xffffffffffffdffd,
                             0xffffffffffffdffd, 0xffffffffffffdffd};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000008, 0x0000000000000008,
                      0x0000000000000008, 0x0000000000000008};
  __m256i_result = (__m256i){0x0000000000008000, 0x0000000000008000,
                             0x0000000000008000, 0x0000000000008000};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffefffffffeff, 0xfffffefffffffeff,
                      0xfffffefffffffeff, 0xfffffefffffffeff};
  __m256i_result = (__m256i){0xfffffffbfffffffb, 0xfffffffbfffffffb,
                             0xfffffffbfffffffb, 0xfffffffbfffffffb};
  __m256i_out = __lasx_xvrotri_h((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000002a5429, 0x0000000000000000,
                      0x00000000002a5429, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000002a54290, 0x0000000000000000,
                             0x0000000002a54290, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000907,
                      0x0000000000000000, 0x0000000000000907};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000483800,
                             0x0000000000000000, 0x0000000000483800};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff01ff800000007e, 0xff01ff80ff01ff80,
                      0x0000007f0000007f, 0x0000007f0000007f};
  __m256i_result = (__m256i){0xffc07f80003f0000, 0xffc07f80ffc07f80,
                             0x003f8000003f8000, 0x003f8000003f8000};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000f0000000f, 0x0000000f0000000f,
                      0x0000000f0000000f, 0x0000000f0000000f};
  __m256i_result = (__m256i){0x0000f0000000f000, 0x0000f0000000f000,
                             0x0000f0000000f000, 0x0000f0000000f000};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_w((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7f7f7f7f7fff00ff, 0x7f007f7f7f7f7f7f,
                      0x7f7f7f7f7fff00ff, 0x7f7f7f7f7f7f7f7f};
  __m256i_result = (__m256i){0xbfbfbfbfbfff807f, 0xbf803fbfbfbfbfbf,
                             0xbfbfbfbfbfff807f, 0xbfbfbfbfbfbfbfbf};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x24);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffff6f20,
                      0x0000000000000000, 0x00000000ffff6f20};
  __m256i_result = (__m256i){0x0000000000000000, 0xdbc8000000003fff,
                             0x0000000000000000, 0xdbc8000000003fff};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x38);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x35);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x80000000ff800000,
                      0x8000000080000000, 0x80000000ff800000};
  __m256i_result = (__m256i){0x0000040000000400, 0x000007fc00000400,
                             0x0000040000000400, 0x000007fc00000400};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x35);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvrotri_d((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
