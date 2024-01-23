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

  v4u64_op0 = (v4u64){0x800080008000b8f1, 0x8000800080008000,
                      0x06f880008000ffff, 0x8000ffff8000ffff};
  __m256i_result = (__m256i){0x800080008000480f, 0x8000800080008000,
                             0xfa08800080000101, 0x8000010180000101};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0101010101010102, 0x0101010101010102,
                             0x0101010201010204, 0x0101010101010102};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xfffffffffffffefd, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010203, 0x0101010101010101};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f00ff007f00ff, 0x007f00ff007f00ff,
                      0x007f00ff007f00ff, 0x007f00ff007f00ff};
  __m256i_result = (__m256i){0x0081000100810001, 0x0081000100810001,
                             0x0081000100810001, 0x0081000100810001};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x43ec0a1b2aba7ed0, 0x223d76f09f37e357,
                      0x3870ca8d013e76a0, 0x223d76f09f3881ff};
  __m256i_result = (__m256i){0xbd14f6e5d6468230, 0xdec38a1061c91da9,
                             0xc8903673ffc28a60, 0xdec38a1061c87f01};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100004300000000, 0x0100010001000100,
                      0x0100004300000000, 0x0100010001000100};
  __m256i_result = (__m256i){0xff0000bd00000000, 0xff00ff00ff00ff00,
                             0xff0000bd00000000, 0xff00ff00ff00ff00};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007fe000007fe0, 0x00007fde00007fd4,
                      0x00007fe000007fe0, 0x00007fde00007fd4};
  __m256i_result = (__m256i){0x0000812000008120, 0x000081220000812c,
                             0x0000812000008120, 0x000081220000812c};
  __m256i_out = __lasx_xvneg_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001fdda7dc4, 0x00000000007e8080,
                      0x00000001fdda7dc4, 0x00000000007e8080};
  __m256i_result = (__m256i){0x0000ffff0226823c, 0x00000000ff827f80,
                             0x0000ffff0226823c, 0x00000000ff827f80};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000010000080040, 0x0000000000080040,
                      0x0000010000080040, 0x0000000000080040};
  __m256i_result = (__m256i){0x0000ff00fff8ffc0, 0x00000000fff8ffc0,
                             0x0000ff00fff8ffc0, 0x00000000fff8ffc0};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010001, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0003ed8800031b38, 0x00735278007cf94c,
                      0x000315ac0000d658, 0x002e4db200000000};
  __m256i_result = (__m256i){0xfffc1278fffce4c8, 0xff8cad88ff8306b4,
                             0xfffcea54ffff29a8, 0xffd1b24e00000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fff0e400, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x00000000000f1c00, 0x0000000000000001,
                             0x0000000000007380, 0x0000000000000001};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000000000000,
                             0x0000000100000001, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000100000000, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000180000001, 0x0000000000000000,
                             0x8000000180000001, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000008000165a, 0x0000ffff8000ffa3,
                      0x000000008000165a, 0x0000ffff8000ffa3};
  __m256i_result = (__m256i){0x000000007fffe9a6, 0xffff00017fff005d,
                             0x000000007fffe9a6, 0xffff00017fff005d};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ffffffffff, 0x0000000000000000,
                      0x000000ffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffff0100000001, 0x0000000000000000,
                             0xffffff0100000001, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000683fe0000000, 0x0000497fe0000080,
                      0x0000683fe0000000, 0x0000497fe0000080};
  __m256i_result = (__m256i){0xffff97c120000000, 0xffffb6811fffff80,
                             0xffff97c120000000, 0xffffb6811fffff80};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfefefefefefefefe, 0xfefefefefdfdfdfd,
                      0xfefefefefefefefe, 0xfefefefefdfdfdfd};
  __m256i_result = (__m256i){0x0101010201010102, 0x0101010202020203,
                             0x0101010201010102, 0x0101010202020203};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000032, 0x0000000000000000,
                      0x0000000000000032, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffce, 0x0000000000000000,
                             0x00000000ffffffce, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  __m256i_result = (__m256i){0x0000800000000000, 0x0000800000000000,
                             0x0000800000000000, 0x0000800000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffff00000001, 0x0000000000000000,
                             0xffffffff00000001, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000f000000000000, 0x0000000000000000,
                      0x000f000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff1000000000000, 0x0000000000000000,
                             0xfff1000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0808080808080808,
                      0x0000000000000000, 0x0808080808080808};
  __m256i_result = (__m256i){0x0000000000000000, 0xf7f7f7f7f7f7f7f8,
                             0x0000000000000000, 0xf7f7f7f7f7f7f7f8};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000002780, 0x0000000000000000,
                      0x0000000000002780, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffd880, 0x0000000000000000,
                             0xffffffffffffd880, 0x0000000000000000};
  __m256i_out = __lasx_xvneg_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
