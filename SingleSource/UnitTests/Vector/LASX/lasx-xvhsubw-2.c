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
  v4u64_op1 = (v4u64){0xffffff90ffffff80, 0x0000000000000000,
                      0xffffff90ffffff80, 0x0000000000000000};
  __m256i_result = (__m256i){0xff01ff70ff01ff80, 0x0000000000000000,
                             0xff01ff70ff01ff80, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2,
                      0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2};
  v4u64_op1 = (v4u64){0x0000000000000007, 0x0000000000000000,
                      0x0000000000000007, 0x0000000000000000};
  __m256i_result = (__m256i){0x00c200c200c200bb, 0x00c200c200c200c2,
                             0x00c200c200c200bb, 0x00c200c200c200c2};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000010000000a, 0x0000000a00000000,
                      0x000000010000000a, 0x0000000a00000000};
  v4u64_op1 = (v4u64){0x0000000080008001, 0x0000800000000000,
                      0x0000000080008001, 0x0000800000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x000000000000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000100000000,
                      0x0000000000000000, 0x0000000100000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000100000000,
                      0x0000000000000000, 0x0000000100000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000ffff00000000,
                             0x0000000000000000, 0x0000ffff00000000};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000f90, 0x0000000000000000,
                      0x0000000000000f90, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ff70, 0x0000000000000000,
                             0x000000000000ff70, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000faf3f3f2, 0x00000000f9f9f9f9,
                      0x00000000faf3f3f2, 0x00000000f9f9f9f9};
  v4u64_op1 = (v4u64){0x0000000000ff0057, 0x0000000000ff00bb,
                      0x0000000000ff0057, 0x0000000000ff00bb};
  __m256i_result = (__m256i){0x00000000fffb009c, 0x00000000fffa003e,
                             0x00000000fffb009c, 0x00000000fffa003e};
  __m256i_out = __lasx_xvhsubw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                             0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x6300000000000001, 0x0000000000000000,
                      0x6300000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000003fff, 0x0000000000003fff,
                      0x0000000000003fff, 0x0000000000003fff};
  __m256i_result = (__m256i){0x0000ffff0000c000, 0x00000000ffffc001,
                             0x0000ffff0000c000, 0x00000000ffffc001};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffff9fffffff9, 0x9ffffd8020010001,
                      0xfffffff9fffffff9, 0x9ffffd8020010001};
  v4u64_op1 = (v4u64){0x7ff8000000000000, 0x40f69fe73c26f4ee,
                      0x7ff8000000000000, 0x40f69fe73c26f4ee};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x00000018ffff2b13,
                             0x0000ffff0000ffff, 0x00000018ffff2b13};
  __m256i_out = __lasx_xvhsubw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00800080ffffffff, 0xffffffffffffffff,
                      0x00800080ffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000001e18, 0x000000000000ffe0,
                      0x0000000000001e18, 0x000000000000ffe0};
  __m256i_result = (__m256i){0x00000000007fe268, 0x00000000ffff001f,
                             0x00000000007fe268, 0x00000000ffff001f};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffffe40, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0004000400040004, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffffbfffc, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffff00fffffff0, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffff00, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000055,
                      0x0000000000000000, 0x0000000000000055};
  v4u64_op1 = (v4u64){0xffffffffff295329, 0xfffffffffefefeff,
                      0xffffffffff295329, 0xfffffffffefefeff};
  __m256i_result = (__m256i){0xffffffff00d6acd7, 0xffffffff01010101,
                             0xffffffff00d6acd7, 0xffffffff01010101};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x120e120dedf1edf2, 0x0000000000000000,
                      0x120e120dedf1edf2, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000120e120d, 0x0000000000000000,
                             0x00000000120e120d, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000483800,
                      0x0000000000000000, 0x0000000000483800};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffff00000001, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000cfffffff3, 0x0000000dfffffff1,
                      0x0000000cfffffff3, 0x0000000dfffffff1};
  __m256i_result = (__m256i){0xffffffff0000000d, 0xffffffff0000000f,
                             0xffffffff0000000d, 0xffffffff0000000f};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffb5ff80ffd0ffd8, 0x00010000002fff9e,
                      0xffb7ff80ffd0ffd8, 0x0002ff80ffb70000};
  __m256i_result = (__m256i){0x004a007f002f0028, 0xffffffffffffffff,
                             0x0048007f002f0028, 0xffffffffffffffff};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xdbcbdbcb0000dbcb, 0xdbcbdbcbecececec,
                      0xdbcbdbcb0000dbcb, 0xdbcbdbcbecececec};
  __m256i_result = (__m256i){0x24342434ffff2435, 0xffffffffffffffff,
                             0x24342434ffff2435, 0xffffffffffffffff};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffba8300004fc2, 0xffffba8300004fc2,
                      0xffffba8300004fc2, 0xffffba8300004fc2};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffba8300004fc2, 0x0000000000000000,
                             0xffffba8300004fc2, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffff8000};
  __m256i_result = (__m256i){0x0000000000000001, 0xffffffffffffffff,
                             0xffffffffffff8001, 0xffffffffffffffff};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffefffefffefffe, 0xfffefffefffefffe,
                      0xfffefffefffefffe, 0xfffefffefffefffe};
  v4u64_op1 = (v4u64){0x00003fff00003fff, 0x00003fff00003fff,
                      0x00003fff00003fff, 0x00003fff00003fff};
  __m256i_result = (__m256i){0xfffebffffffebfff, 0x0000000000000000,
                             0xfffebffffffebfff, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff7edfffff7edf, 0xffff7eddffff7ed3,
                      0xffff7edfffff7edf, 0xffff7eddffff7ed3};
  v4u64_op1 = (v4u64){0x00003ff000003ff0, 0x00003fef00003fea,
                      0x00003ff000003ff0, 0x00003fef00003fea};
  __m256i_result = (__m256i){0xffff3eedffff3ee3, 0x0000000000000000,
                             0xffff3eedffff3ee3, 0x0000000000000000};
  __m256i_out = __lasx_xvhsubw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
