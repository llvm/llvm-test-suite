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

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffff5f5c, 0xffffffff, 0xffff5f5c, 0xffffffff,
                      0xffff5f5c, 0xffffffff, 0xffff5f5c, 0xffffffff};
  v8i32_op2 = (v8i32){0xff005f0f, 0xff00ff0f, 0x0000000f, 0x0000000f,
                      0xff005f0f, 0xff00ff0f, 0x0000000f, 0x0000000f};
  v8i32_result = (v8i32){0xffff5f5c, 0xffffffff, 0xffff5f5c, 0xffffffff,
                         0xffff5f5c, 0xffffffff, 0xffff5f5c, 0xffffffff};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00060000, 0x0003fffc, 0x00000001, 0x00000000,
                      0x08140000, 0x020afefb, 0x00010000, 0x00010001};
  v8i32_op1 = (v8i32){0x40000010, 0x80000000, 0x40000000, 0x80000000,
                      0x10000010, 0x40000000, 0x40000000, 0x80000000};
  v8i32_op2 = (v8i32){0x00010000, 0x0000ffff, 0x00000000, 0x00000000,
                      0x0001ffff, 0x000000ff, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x800d0002, 0x8000ffff, 0x80000002, 0x80000000,
                         0x8001ffff, 0x828aff0b, 0x80020000, 0x80000000};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xd07dbf01, 0x1f3d2101, 0x1f3d2101, 0x9f1fd080,
                      0xd07dbf01, 0x1f3d2101, 0x1f3d2101, 0x1f3d2101};
  v8i32_op1 = (v8i32){0x9e1423d4, 0x1d949d94, 0x3dd41d95, 0x1de9a03f,
                      0x9e1423d4, 0x1d949d94, 0x9d949d95, 0x1d949d94};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xaf12d5f0, 0x8001b72e, 0x9d9cb530, 0x00024763,
                         0xaf12d5f0, 0x8001b72e, 0x0001b72e, 0x8001b72e};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x7ff80000, 0x3e3b31d4, 0x1f0fdf7f,
                      0x00000000, 0x7ff80000, 0x3e3b31d4, 0x1f0fdf7f};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x7ff80000, 0x80000000, 0x80000000,
                         0x80000000, 0x7ff80000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x80000000, 0x00000000, 0x80000000,
                      0x00000000, 0x80000000, 0x00000000, 0x80000000};
  v8i32_op1 = (v8i32){0x0000ffff, 0x00000000, 0x00000000, 0x00000000,
                      0x0000ffff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000001, 0x00000000, 0x00000001, 0x00000000,
                      0x00000001, 0x00000000, 0x00000001, 0x00000000};
  v8i32_result = (v8i32){0x80000001, 0x80000000, 0x80000001, 0x80000000,
                         0x80000001, 0x80000000, 0x80000001, 0x80000000};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000200, 0x00000000, 0x00000200, 0x00000000,
                      0x00000200, 0x00000000, 0x00000200, 0x00000000};
  v8i32_op2 = (v8i32){0x00000001, 0xffffffe0, 0x00000001, 0xffffffa0,
                      0x00000001, 0xffffffe0, 0x00000001, 0xffffffa0};
  v8i32_result = (v8i32){0x80000001, 0xffffffe0, 0x80000001, 0xffffffa0,
                         0x80000001, 0xffffffe0, 0x80000001, 0xffffffa0};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x68410001, 0x49810081, 0x4843ffe1, 0x49810081,
                      0x68410001, 0x49810081, 0x4843ffe1, 0x49810081};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff,
                      0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff};
  v8i32_op1 = (v8i32){0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683,
                      0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683};
  v8i32_op2 = (v8i32){0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff,
                      0x0000ffff, 0x0000ffff, 0x00002001, 0x00009fff};
  v8i32_result = (v8i32){0x8000ffff, 0xfffe97c0, 0x80002001, 0xfffeb683,
                         0x8000ffff, 0xfffe97c0, 0x80002001, 0xfffeb683};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff,
                      0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff};
  v8i32_op1 = (v8i32){0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02,
                      0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02};
  v8i32_op2 = (v8i32){0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02,
                      0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02};
  v8i32_result = (v8i32){0x7d02fd02, 0x7fffffff, 0x7d02fd02, 0x7fffffff,
                         0x7d02fd02, 0x7fffffff, 0x7d02fd02, 0x7fffffff};
  __m256_out = __lasx_xvfnmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xe651bfff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xbf7f7fff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x6651bfff, 0xf328dfff, 0xffffffff,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0xffffffff, 0xffffffff, 0xffffffff,
                         0x00000000, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x07030200, 0x00020100, 0x00000000,
                      0x00000000, 0x01020400, 0x07070707, 0x00000000};
  v8i32_op1 = (v8i32){0x5c800400, 0x02020080, 0xfeff0000, 0xffffff80,
                      0x01000400, 0x00000000, 0xfefeff00, 0xffffff80};
  v8i32_op2 = (v8i32){0x00000000, 0x6651bfff, 0xf328dfff, 0xffffffff,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x6651bfff, 0xf328dfff, 0xffffffff,
                         0x80000000, 0x80000000, 0x46867f79, 0xffffff80};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xe0000000, 0xffffffff, 0xe0000000, 0xffffffff,
                      0xe0000000, 0xffffffff, 0xe0000000, 0xffffffff};
  v8i32_op1 = (v8i32){0x80000000, 0x80000000, 0x00000000, 0x00000000,
                      0x80000000, 0x80000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0xffffffff, 0x00000000, 0xffffffff,
                         0x80000000, 0xffffffff, 0x00000000, 0xffffffff};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000,
                      0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000};
  v8i32_result = (v8i32){0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000,
                         0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0x80000000, 0x80000000,
                         0x80000000, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0x7fefffff, 0xffffffff, 0x7fefffff,
                      0xffffffff, 0x7fefffff, 0xffffffff, 0x7fefffff};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0x7fefffff, 0xffffffff, 0x7fefffff,
                         0xffffffff, 0x7fefffff, 0xffffffff, 0x7fefffff};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00003f78, 0x00000000, 0xf7f8f7f8, 0x00000000,
                      0x00003f78, 0x00000000, 0xf7f8f7f8, 0x00000000};
  v8i32_op1 = (v8i32){0x00003f78, 0x00000000, 0xf7f8f7f8, 0x00000000,
                      0x00003f78, 0x00000000, 0xf7f8f7f8, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0xff800000, 0x80000000,
                         0x80000000, 0x80000000, 0xff800000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0x80000000, 0x80000000,
                         0xffffffff, 0xffffffff, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000405, 0x00000000, 0x01010100, 0x00000000,
                      0x00000405, 0x00000000, 0x01010100, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000405, 0x00000000, 0x01010100, 0x00000000,
                      0x00000405, 0x00000000, 0x01010100, 0x00000000};
  v8i32_result = (v8i32){0x00000405, 0x80000000, 0x01010100, 0x80000000,
                         0x00000405, 0x80000000, 0x01010100, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000202, 0x00000000, 0x00800080, 0x00000000,
                      0x00000202, 0x00000000, 0x00800080, 0x00000000};
  v8i32_op1 = (v8i32){0xff88ff88, 0x00000000, 0x00000000, 0x00000000,
                      0xff88ff88, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffc8ff88, 0x80000000, 0x80000000, 0x80000000,
                         0xffc8ff88, 0x80000000, 0x80000000, 0x80000000};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0x001fffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0x001fffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0x001fffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0x001fffff};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x7fff0000, 0x7fff8000, 0x00000000, 0x00000000,
                      0x7fff0000, 0x7fff8000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0xffffff10, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffff10, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffff10, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffff10, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfnmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
