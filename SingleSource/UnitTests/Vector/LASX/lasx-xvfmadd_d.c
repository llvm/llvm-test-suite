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

  v4u64_op0 = (v4u64){0x65fb66c81da8e5ba, 0x0000000000000000,
                      0xe37affb42fc05f69, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xe3aebaf4df958004, 0x36722a7e66972cd6,
                      0x00d6c1c830160048, 0x8b1414140e0e0e0e};
  v4u64_result = (v4u64){0xe3aebaf4df958004, 0x36722a7e66972cd6,
                         0x00d6c1c830160048, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000f3280000dfff, 0xffffffff0000ffff,
                      0x0000468600007f79, 0x0000ffff0000ff80};
  v4u64_op1 = (v4u64){0xff49fe4200000000, 0xfe02fe02fee5fe22,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0049004200000000, 0x00020001ffb6ffe0,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xbf28b0686066be60, 0xffffffff0000ffff,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xc5c5c5c5c5c5c5c5, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007f7f00007fff, 0x0000000000000000,
                      0x00007f7f00000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000f1a40, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000aaaa0000aaaa, 0x0000aaaa00008bfe,
                      0x0000aaaa0000aaaa, 0x0000aaaa00008bfe};
  v4u64_op2 = (v4u64){0x0000aaaa0000aaaa, 0x0000aaaa00008bfe,
                      0x0000aaaa0000aaaa, 0x0000aaaa00008bfe};
  v4u64_result = (v4u64){0x0000aaaa0000aaaa, 0x0000aaaa00008bfe,
                         0x0000aaaa0000aaaa, 0x0000aaaa00008bfe};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0202810102020202, 0x0202020202020202,
                      0x0202810102020202, 0x0202020202020202};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00007fff00000000, 0x0000000000000000,
                      0x00007fff00000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x00007fff00000000, 0x0000000000000000,
                         0x00007fff00000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x007f00ff007f00ff, 0x0000000000000000,
                      0x007f00ff007f00ff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0x000000000000ffff, 0x0000000000000000,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x01fe01ae00ff00ff, 0x00ff010000ff017e,
                      0x01fe01ae00ff00ff, 0x00ff010000ff017e};
  v4u64_op2 = (v4u64){0x0000000100010001, 0x0001000000000000,
                      0x0000000100010001, 0x0001000000000000};
  v4u64_result = (v4u64){0x0000000100010001, 0x0001000000000000,
                         0x0000000100010001, 0x0001000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffba8300004fc2, 0xffffba8300004fc2,
                      0xffffba8300004fc2, 0xffffba8300004fc2};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffba8300004fc2,
                         0xffffffffffffffff, 0xffffba8300004fc2};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0xffffffff00000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffff000000, 0x0000000000000000,
                      0xffffffffff000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffff000000, 0x0000000000000000,
                         0xffffffffff000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fff00003fff, 0x00003fff00003fff,
                      0x00003fff00003fff, 0x00003fff00003fff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xd3d3d3d3d3d3d3d3, 0xd3d3d3d3d3d3d3d3,
                      0xd3d3d3d3d3d3d3d3, 0xd3d3d3d3d3d3d3d3};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmadd_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000fff00000fff, 0x00000fff00000fff,
                      0x00000fff00000fff, 0x00000fff00000fff};
  v4u64_op1 = (v4u64){0x00000fff00000fff, 0x00000fff00000fff,
                      0x00000fff00000fff, 0x00000fff00000fff};
  v4u64_op2 = (v4u64){0xffffffffffff5f5c, 0xffffffffffff5f5c,
                      0xffffffffffff5f5c, 0xffffffffffff5f5c};
  v4u64_result = (v4u64){0xffffffffffff5f5c, 0xffffffffffff5f5c,
                         0xffffffffffff5f5c, 0xffffffffffff5f5c};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fff0e400, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x00000000000f1c00, 0x0000000000000001,
                      0x0000000000007380, 0x0000000000000001};
  v4u64_op2 = (v4u64){0x00000000fff0e400, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  v4u64_result = (v4u64){0x80000000fff0e400, 0x80000000ffffffff,
                         0x80000000ffff8c80, 0x80000000ffffffff};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x0000000000000000,
                      0x0000000000000007, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000001dc, 0x0000000000000000,
                      0x00000000000001dc, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00000000000001dc, 0x0000000000000000,
                      0x00000000000001dc, 0x0000000000000000};
  v4u64_result = (v4u64){0x80000000000001dc, 0x0000000000000000,
                         0x80000000000001dc, 0x0000000000000000};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0404000004040000,
                      0x0101010101010101, 0x0404000004040000};
  v4u64_op1 = (v4u64){0x0057ffa800ceff31, 0x80f900f980780078,
                      0x00faff0500c3ff3c, 0x8011ffee804c004c};
  v4u64_op2 = (v4u64){0x00003fc00000428a, 0xffffc040ffffc09d,
                      0x00003fc00000428a, 0xffffc040ffffc09d};
  v4u64_result = (v4u64){0x80003fc00000428a, 0xffffc040ffffc09d,
                         0x80003fc00000428a, 0xffffc040ffffc09d};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffb2f600006f48, 0x0000000100000001,
                      0xffffb2f600006f48, 0x0000000100000001};
  v4u64_result = (v4u64){0xffffb2f600006f48, 0x8000000100000001,
                         0xffffb2f600006f48, 0x8000000100000001};
  __m256d_out = __lasx_xvfmsub_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
