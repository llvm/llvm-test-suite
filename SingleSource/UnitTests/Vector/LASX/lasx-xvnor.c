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

  v4u64_op0 = (v4u64){0x40d74f979f99419f, 0x00000000ffff0000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xbf28b0686066be60, 0xffffffff0000ffff,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000f6ff00000000,
                      0x0000000000000000, 0x0000f6ff00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffff6ff00000000,
                      0x0000000000000000, 0xfffff6ff00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000900ffffffff,
                             0xffffffffffffffff, 0x00000900ffffffff};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0888888888888888, 0x8888888808888888,
                      0x0888888888888888, 0x8888888808888888};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf777777777777777, 0x77777777f7777777,
                             0xf777777777777777, 0x77777777f7777777};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x407b40ff40ff40f1, 0x40ff40ff40ff40ff,
                      0x407b40ff40ff40f1, 0x40ff40ff40ff40ff};
  v4u64_op1 = (v4u64){0x407b40ff40ff40f1, 0x40ff40ff40ff40ff,
                      0x407b40ff40ff40f1, 0x40ff40ff40ff40ff};
  __m256i_result = (__m256i){0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00,
                             0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000033, 0x0000000000000000,
                      0x0000000000000033, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x5fff5fff607f0000, 0x8000420080000000,
                      0x5fff5fff607f0000, 0x8000420080000000};
  __m256i_result = (__m256i){0xa000a0009f80ffcc, 0x7fffbdff7fffffff,
                             0xa000a0009f80ffcc, 0x7fffbdff7fffffff};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x9090909090909090, 0x9090909090909090,
                      0x9090909090909090, 0x9090909090909090};
  v4u64_op1 = (v4u64){0x9090909090909090, 0x9090909090909090,
                      0x9090909090909090, 0x9090909090909090};
  __m256i_result = (__m256i){0x6f6f6f6f6f6f6f6f, 0x6f6f6f6f6f6f6f6f,
                             0x6f6f6f6f6f6f6f6f, 0x6f6f6f6f6f6f6f6f};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000fffcfffcfffc,
                      0x0000000000000000, 0x0000fffcfffcfffc};
  v4u64_op1 = (v4u64){0x0000000000003fff, 0x0000000000003fff,
                      0x0000000000003fff, 0x0000000000003fff};
  __m256i_result = (__m256i){0xffffffffffffc000, 0xffff000300030000,
                             0xffffffffffffc000, 0xffff000300030000};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_result = (__m256i){0x800fffffffffffff, 0x800fffffffffffff,
                             0x800fffffffffffff, 0x800fffffffffffff};
  __m256i_out = __lasx_xvnor_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
