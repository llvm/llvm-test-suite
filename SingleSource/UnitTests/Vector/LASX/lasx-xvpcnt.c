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

  v4u64_op0 = (v4u64){0x005500550055ffab, 0x005500550055ffab,
                      0x005500550055ffab, 0x005500550055ffab};
  __m256i_result = (__m256i){0x0004000400040805, 0x0004000400040805,
                             0x0004000400040805, 0x0004000400040805};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000080000000800, 0x00ff00ff00000007,
                      0xfffcf800fffcf800, 0x00ff00ff00000007};
  __m256i_result = (__m256i){0x0000010000000100, 0x0008000800000003,
                             0x0806050008060500, 0x0008000800000003};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00c100c100c100c1,
                      0x0000000000000000, 0x00c100c100c100c1};
  __m256i_result = (__m256i){0x0000000000000000, 0x0003000300030003,
                             0x0000000000000000, 0x0003000300030003};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffffffffffff,
                      0x0000ffff0000ffff, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0x0000080800000808, 0x0000080808080808,
                             0x0000080800000808, 0x0000080808080808};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000100000001, 0x00000000ffe36780,
                      0x8000000100000001, 0x00000000ffe36780};
  __m256i_result = (__m256i){0x0100000100000001, 0x0000000008050501,
                             0x0100000100000001, 0x0000000008050501};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000015554001c003, 0x0000000000001555,
                      0x000015554001c003, 0x0000000000001555};
  __m256i_result = (__m256i){0x0000030401010202, 0x0000000000000304,
                             0x0000030401010202, 0x0000000000000304};
  __m256i_out = __lasx_xvpcnt_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xb8c7800094400001, 0x639c3fffb5dffffe,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0009000100040001, 0x0008000e000c000f,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000002e2100, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000040002, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007f433c78, 0x0000000000000000,
                      0x000000007f433c78, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000a0008, 0x0000000000000000,
                             0x00000000000a0008, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                      0xffffffffe0000000, 0xffffffffe0000000};
  __m256i_result = (__m256i){0x0010001000030000, 0x0010001000030000,
                             0x0010001000030000, 0x0010001000030000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0x0000000000000000,
                      0xff1cff1cff1cff1c, 0x0000000000000000};
  __m256i_result = (__m256i){0x000b000b000b000b, 0x0000000000000000,
                             0x000b000b000b000b, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x363c0000fff3c000, 0x3380000000000000,
                      0xfff6e00000000000, 0x34000000fff00000};
  __m256i_result = (__m256i){0x0000000800000010, 0x0000000500000000,
                             0x0000001100000000, 0x000000030000000c};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000000000000000,
                             0x0000002000000020, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000020a4ffffbe4f, 0x000000010000685e,
                      0x000020a4ffffbe4f, 0x000000010000685e};
  __m256i_result = (__m256i){0x000000040000001b, 0x0000000100000008,
                             0x000000040000001b, 0x0000000100000008};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fffffffffffffff,
                      0x0000000000000000, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000001f00000020,
                             0x0000000000000000, 0x0000001f00000020};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                      0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_result = (__m256i){0x0000001200000012, 0x0000001200000012,
                             0x0000001200000012, 0x0000001200000012};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000400000004000, 0x0000400000004000,
                      0x0000400000004000, 0x0000400000004000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvpcnt_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1000000000000000, 0x1000000000000000,
                      0x1000000000000000, 0x1000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x8000000080000000,
                      0xffffffffffffffff, 0x8000000080000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000002,
                             0x0000000000000040, 0x0000000000000002};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000000003,
                      0x0000000000010001, 0x0000000000000003};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000002, 0x0000000000000002};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0000, 0xffffffffffffffff,
                      0xffff0000ffff0000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000020, 0x0000000000000040,
                             0x0000000000000020, 0x0000000000000040};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvpcnt_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
