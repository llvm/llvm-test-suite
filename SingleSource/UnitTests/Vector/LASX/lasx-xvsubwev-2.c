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

  v4u64_op0 = (v4u64){0x0000001700170017, 0x0000000000000017,
                      0x0000001700170017, 0x0000000000000017};
  v4u64_op1 = (v4u64){0x0000001700170017, 0x0000000000000017,
                      0x0000001700170017, 0x0000000000000017};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007f7f00007f7f, 0x00007f7f00007f7f,
                      0x00007f7f00007f7f, 0x00007f7f00007f7f};
  v4u64_op1 = (v4u64){0xffffffff00000001, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xff01ff800000007e, 0xff01ff80ff01ff80,
                             0x0000007f0000007f, 0x0000007f0000007f};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020206431, 0x2020202020202020,
                      0x2020202020206431, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x0043030300400100, 0x0043030300400100,
                      0x0043030300400300, 0x0043030300400300};
  __m256i_result = (__m256i){0xffdd001dffe00031, 0xffdd001dffe00020,
                             0xffdd001dffe00031, 0xffdd001dffe00020};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfffffe20001dfe1f,
                      0x0000000000000000, 0xfffffe20001dfe1f};
  v4u64_op1 = (v4u64){0x001fe020001fe020, 0x000000001ffe2000,
                      0x001fe020001fe020, 0x000000001ffe2000};
  __m256i_result = (__m256i){0xffe1ffe0ffe1ffe0, 0x00ff0020ff1f001f,
                             0xffe1ffe0ffe1ffe0, 0x00ff0020ff1f001f};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffee00ba, 0x0000000000000000,
                      0xffffffffffee00ba, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x80008000fff98000, 0x8000800080008000,
                      0x80008000fff98000, 0x8000800080008000};
  __m256i_result = (__m256i){0x00ff00fffff500ba, 0x0000000000000000,
                             0x00ff00fffff500ba, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000047000000, 0x000000004efffe00,
                      0x0000000047000000, 0x000000004efffe00};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0000ffff00000000,
                      0x000000000000ffff, 0x0000ffff00000000};
  __m256i_result = (__m256i){0x000000000000ff01, 0x0000ff0100ff0000,
                             0x000000000000ff01, 0x0000ff0100ff0000};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                             0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_out = __lasx_xvsubwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfffcfffcfffcfffc,
                      0x0000000000000000, 0xfffcfffcfffcfffc};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000fffc0000fffc,
                             0x0000000000000000, 0x0000fffc0000fffc};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x303338a48f374969, 0x0001504f4c4b2361,
                      0x303338a48f374969, 0x0001504f4c4b2361};
  v4u64_op1 = (v4u64){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                      0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  __m256i_result = (__m256i){0xffff47b4ffff5879, 0x0000504fffff3271,
                             0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0001, 0xffffffffffffffff,
                      0xffff0000ffff0001, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffff0000ffff0001, 0xffffffffffffffff,
                      0xffff0000ffff0001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000f0,
                      0x00000000000000f0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x4000000000000000, 0x4000000000000000,
                      0x4000000000000000, 0x4000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000000000f0,
                             0x00000000000000f0, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000ffff0000ffff,
                             0x0000ffff00000000, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvsubwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  v4u64_op1 = (v4u64){0xfffffffffffffffc, 0xfffffffffffffffc,
                      0xfffffffffffffbf4, 0xfffffffffffffff8};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000308, 0x0000000000000006};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000010100000102, 0x0000000000000000,
                      0x0000010100000102, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000fffffefd, 0x00000000ffffffff,
                             0x00000000fffffefd, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffffe40, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x80000000fff0e400, 0x80000000ffffffff,
                      0x80000000ffff8c80, 0x80000000ffffffff};
  __m256i_result = (__m256i){0x00000000000f1a40, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000003effe1, 0x0000000000000000,
                      0x00000000003effe1, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000003effe1, 0x0000000000000000,
                      0x00000000003effe1, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001fffe00010001, 0x0001fffe0000ffff,
                      0x0001fffe00010001, 0x0001fffe0000ffff};
  v4u64_op1 = (v4u64){0x0001fffe00010001, 0x0001fffe0000ffff,
                      0x0001fffe00010001, 0x0001fffe0000ffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000008, 0x0000000000000000,
                      0x0000000000000008, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000fffffff7, 0x00000000ffffffff,
                             0x00000000fffffff7, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000fffe, 0x000000000000fffe,
                      0x000000000000fffe, 0x000000000000fffe};
  __m256i_result = (__m256i){0xffffffffffff0002, 0xffffffffffff0002,
                             0xffffffffffff0002, 0xffffffffffff0002};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff0000, 0xffffffffffffffff,
                      0xffffffffffff0000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x7fffffffffffffff,
                      0x0000000000000000, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x00000000ffff0000, 0x0000000000000000,
                             0x00000000ffff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x5d20a0a15d20a0a1,
                      0x0000000000000000, 0x5d20a0a15d20a0a1};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffff00ffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000010000000001, 0xffffffffffffffff,
                             0x0000000000000001, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffeffffff00, 0x1c1c1c1c1c1c1c1c,
                      0xfffffffeffffff00, 0x1c1c1c1c1c1c1c1c};
  __m256i_result = (__m256i){0x0000000100000100, 0xffffffffffffffff,
                             0x0000000100000100, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000003, 0x0040000000000003,
                      0x0000000000000003, 0x0040000000000003};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
