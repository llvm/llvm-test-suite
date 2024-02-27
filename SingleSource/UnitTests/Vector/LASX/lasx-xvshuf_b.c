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

  v4u64_op0 = (v4u64){0x0703020000000000, 0x0000000000020100,
                      0x0102040000000000, 0x0000000007070707};
  v4u64_op1 = (v4u64){0xff49fe4200000000, 0xfe02fe02fee5fe22,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefefffffefe, 0xfffffefefffffefe,
                      0xfffffefefffffcfa, 0xfffffefefffffefe};
  v4u64_op2 = (v4u64){0x3f3f3f383c000000, 0x0000000000000000,
                      0x3f3f3f383f3f3f38, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000fefefe, 0xfefefefefefefefe,
                             0x0000000000000000, 0xfafafafafafafafa};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000600000006, 0x0000000600000006,
                      0x0000000600000006, 0x0000000600000006};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x3f10010000000000,
                      0x0000000000000000, 0x3f10010000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0001000000000000,
                             0x0000000000000000, 0x0001000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000ff0000,
                      0x0000000000000000, 0x0000000000ff0000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000222200002222, 0x0000111111111111,
                      0x0000222200002222, 0x0000111111111111};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffff000000000000,
                             0xffffffffffffffff, 0xffff000000000000};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000003ffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000003ffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000032f1f, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0xffffffffff000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000101, 0x0011001100110011,
                      0x0000000000000001, 0x0011001100110011};
  v4u64_op1 = (v4u64){0x67eee33567eee435, 0xffffffffffffffff,
                      0x67eee33567eee435, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x001f001f00000000,
                      0x0000000000000000, 0x0022002200000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffff00000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0011001100110011, 0x0011001100110011,
                      0x0011001100110011, 0x0011001100110011};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x003f003f003f003f, 0x003f003f003f003f,
                      0x003f003f003f003f, 0x003f003f003f003f};
  v4u64_op1 = (v4u64){0xefdfefdfefdfefdf, 0xefdfefdf00000000,
                      0xefdfefdfefdfefdf, 0xefdfefdf00000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xefdfefdfefdfefdf, 0xefdfefdfefdfefdf,
                             0xefdfefdfefdfefdf, 0xefdfefdfefdfefdf};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0035000000350035, 0x0035000000350035,
                      0x0035000000350035, 0x0035000000350035};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000003,
                      0x0000000000010001, 0x0000000000000003};
  v4u64_op2 = (v4u64){0x7575757575757575, 0x7575757575757575,
                      0x7575757575757575, 0x7575757575757575};
  __m256i_result = (__m256i){0x7575757575757575, 0x7575757575757575,
                             0x7575757575757575, 0x7575757575757575};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fffff800, 0x0000000000000000,
                      0x00000000fffff800, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00000000fffff800, 0x0000000000000000,
                      0x00000000fffff800, 0x0000000000000000};
  __m256i_result = (__m256i){0xf800f800f800f800, 0xf800f800f800f800,
                             0xf800f800f800f800, 0xf800f800f800f800};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000010, 0x000000000000003e,
                      0x0000000000000010, 0x000000000000003e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x000000ffff88ff88, 0x8000000000000000,
                      0x000000ffff88ff88, 0x8000000000000000};
  __m256i_result = (__m256i){0xff88ff88ff88ff88, 0xff88ff88ff880000,
                             0xff88ff88ff88ff88, 0xff88ff88ff880000};
  __m256i_out = __lasx_xvshuf_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000008, 0x0000000100000001,
                      0x0000000100000018, 0x0000000100000011};
  v4u64_op1 = (v4u64){0x98111cca98111cca, 0x98111cca98111cca,
                      0x98111cca98111cca, 0x98111cca98111cca};
  v4u64_op2 = (v4u64){0x0000000101001e18, 0x000000010000ffe1,
                      0x0000000101001e18, 0x000000010000ffe1};
  __m256i_result = (__m256i){0x0000000101001e18, 0x0000000100000001,
                             0x0000000101001e18, 0x0000000100000001};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000310000001f, 0x0000002100000010,
                      0x0000001100000001, 0x000000010000001a};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00000000012e2110, 0x0000000000000001,
                      0x0000000000000002, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000012e2110,
                             0x0000000000000000, 0x0000000000000001};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000c, 0x000000010000001c,
                      0x0000001a00000000, 0x0000002f00000000};
  v4u64_op1 = (v4u64){0x00000000002a542a, 0x0000000000000000,
                      0x00000000002a542a, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000002a542a, 0x00000000002a542a,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000031, 0x0000000100000031,
                      0x0000000100000031, 0x0000000100000031};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000800000007, 0x0000000600000005,
                      0x0000000400000003, 0x0000000200000001};
  v4u64_op1 = (v4u64){0x000000007fc00000, 0x000000007fc00000,
                      0x000000007fc00000, 0x000000007fc00000};
  v4u64_op2 = (v4u64){0x8000000080000000, 0xdfffffffdfffffff,
                      0x8000000080000000, 0xdfffffffdfffffff};
  __m256i_result = (__m256i){0x8000000000000000, 0x7fc0000000000000,
                             0x7fc00000dfffffff, 0xdfffffff80000000};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001000000000, 0x0000000000000000,
                      0x0000002000000030, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff0000ffff0000, 0xffffffffffffffff,
                      0xffff0000ffff0000, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0004000500040005, 0x0004000400040004,
                      0x0004000500040005, 0x0004000400040004};
  __m256i_result = (__m256i){0x0004000500040005, 0x0004000500040005,
                             0x0004000500040005, 0x0004000500040005};
  __m256i_out = __lasx_xvshuf_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x555555ab555555ab, 0x555555ab555555ab,
                      0x555555ab555555ab, 0x555555ab555555ab};
  v4u64_op2 = (v4u64){0x000000007fff7fff, 0x0000000080008000,
                      0x000000007fff7fff, 0x0000000080008000};
  __m256i_result = (__m256i){0x000000007fff7fff, 0x000000007fff7fff,
                             0x000000007fff7fff, 0x000000007fff7fff};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000003, 0x0000000000000002,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000080008001, 0x0000800000000000,
                      0x0000000080008001, 0x0000800000000000};
  v4u64_op2 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000800000000000, 0x0000000080008001,
                             0x0000000000000000, 0x000000000000ffff};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000033, 0x0000000000000022,
                      0x0000000000000011, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000008000, 0x7fff80007fff0000,
                      0x0000000000008000, 0x7fff80007fff0000};
  v4u64_op2 = (v4u64){0x000000ff800000ff, 0x8000800080008000,
                      0x000000ff800000ff, 0x8000800080008000};
  __m256i_result = (__m256i){0x000000ff800000ff, 0x000000ff800000ff,
                             0x000000ff800000ff, 0x000000ff800000ff};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000030, 0x0000000000000020,
                      0x0000000000000010, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000080040, 0x0000000000000040,
                      0x0000000000080040, 0x0000000000000040};
  __m256i_result = (__m256i){0x0000000000080040, 0x0000000000080040,
                             0x0000000000080040, 0x0000000000080040};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003d, 0x000000000000002c,
                      0x000000000000001b, 0x000000000000000a};
  v4u64_op1 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  v4u64_op2 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_result = (__m256i){0xfffeb6839ffffd80, 0xfffe97c020010001,
                             0xfffeb6839ffffd80, 0xfffe97c020010001};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x0000000000000002,
                      0x000000000000001b, 0x000000000000001a};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000010001,
                      0x0000000000010001, 0x0000000000010001};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010001, 0x0000000000010001,
                             0x0000000000010001, 0x0000000000010001};
  __m256i_out = __lasx_xvshuf_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
