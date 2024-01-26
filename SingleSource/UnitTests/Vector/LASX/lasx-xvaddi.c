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

  v4u64_op0 = (v4u64){0xca355ba46a95e31c, 0x44bb2cd3a35c2fd0,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xe75278c187b20039, 0x61d849f0c0794ced,
                             0x1d1d1d1d1d1d1d1d, 0x1d1d1d1d1d1d1d1d};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffe651bfff, 0xffffffffffffffff,
                      0xffffffffbf7f7fff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x1d1d1d1d046fdd1d, 0x1d1d1d1d1d1d1d1d,
                             0x1d1d1d1ddd9d9d1d, 0x1d1d1d1d1d1d1d1d};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1515151515151515, 0x1515151515151515,
                             0x1515151515151515, 0x1515151515151515};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1818181818181818, 0x1818181818181818,
                             0x1818181818181818, 0x1818181818181818};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007fff00000000, 0x0000000000000000,
                      0x00007fff00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0202810102020202, 0x0202020202020202,
                             0x0202810102020202, 0x0202020202020202};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0909090909090909, 0x0909090909090909,
                             0x0909090909090909, 0x0909090909090909};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ffce20, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ffce20, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x151415141514e335, 0x1514151415141514,
                             0x151415141514e335, 0x1514151415141514};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0606060606060606, 0x0606060606060606,
                             0x0606060606060606, 0x0606060606060606};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1212121212121212, 0x1212121212121212,
                             0x1212121212121212, 0x1212121212121212};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001200000012, 0x0000001200000012,
                      0x0000001200000012, 0x0000001200000012};
  __m256i_result = (__m256i){0x1a1a1a2c1a1a1a2c, 0x1a1a1a2c1a1a1a2c,
                             0x1a1a1a2c1a1a1a2c, 0x1a1a1a2c1a1a1a2c};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  __m256i_result = (__m256i){0x1d1d1d1e1d1d1d1e, 0x1d1d1d1e1d1d1d1e,
                             0x1d1d1d1e1d1d1d1e, 0x1d1d1d1e1d1d1d1e};
  __m256i_out = __lasx_xvaddi_bu((__m256)v4u64_op0, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5980000000000000, 0x0000000000000000,
                      0x5980000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5982000200020002, 0x0002000200020002,
                             0x5982000200020002, 0x0002000200020002};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002a54290, 0x0000000000000000,
                      0x0000000002a54290, 0x0000000000000000};
  __m256i_result = (__m256i){0x001f001f02c442af, 0x001f001f001f001f,
                             0x001f001f02c442af, 0x001f001f001f001f};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010001000100010, 0x0010001000100010,
                             0x0010001000100010, 0x0010001000100010};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80938013800d0005, 0x807e80fd80fe0000,
                      0x80938013800d8002, 0x807e80fd80fe80fd};
  __m256i_result = (__m256i){0x80a6802680200018, 0x8091811081110013,
                             0x80a6802680208015, 0x8091811081118110};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8015003f0006001f, 0x0000003f00390035,
                      0x8015003f0006001f, 0x0000003f00390035};
  __m256i_result = (__m256i){0x8020004a0011002a, 0x000b004a00440040,
                             0x8020004a0011002a, 0x000b004a00440040};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0016001600160016, 0x0016001600160016,
                             0x0016001600160016, 0x0016001600160016};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xa1a1a1a15e5e5e5e, 0xa1a1a1a1a1a1a1a1,
                      0xa1a1a1a15e5e5e5e, 0xa1a1a1a1a1a1a1a1};
  __m256i_result = (__m256i){0xa1bfa1bf5e7c5e7c, 0xa1bfa1bfa1bfa1bf,
                             0xa1bfa1bf5e7c5e7c, 0xa1bfa1bfa1bfa1bf};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000100080, 0x0000000000000080,
                      0x0000000000100080, 0x0000000000000080};
  __m256i_result = (__m256i){0x001a001a002a009a, 0x001a001a001a009a,
                             0x001a001a002a009a, 0x001a001a001a009a};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x001c001c001d001d, 0x001c001c001c001c,
                             0x001c001c001c001c, 0x001c001c001c001c};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7200000072000000, 0x7200000072000000,
                      0x7200000072000000, 0x7200000072000000};
  __m256i_result = (__m256i){0x721e001e721e001e, 0x721e001e721e001e,
                             0x721e001e721e001e, 0x721e001e721e001e};
  __m256i_out = __lasx_xvaddi_hu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001900000019, 0x0000001900000019,
                             0x0000001900000019, 0x0000001900000019};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000600000006, 0x0000000600000006,
                             0x0000000600000006, 0x0000000600000006};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000001a0000001a, 0x0000001900000019,
                             0x0000001a0000001a, 0x0000001900000019};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001900000019, 0x0000001900000019,
                             0x0000001900000019, 0x0000001900000019};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001d0000001d, 0x0000001d0000001d,
                             0x0000001d0000001d, 0x0000001d0000001d};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000600000006, 0x0000000600000006,
                             0x0000000600000006, 0x0000000600000006};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000001fffd, 0xffffffffffffffff,
                      0x000000000001fffd, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000700020004, 0x0000000600000006,
                             0x0000000700020004, 0x0000000600000006};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000800000008, 0x0000000800000008,
                             0x0000000800000008, 0x0000000800000008};
  __m256i_out = __lasx_xvaddi_wu((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6d3c2d3aa1c82947, 0x0000883a00000f20,
                      0xf259905a0c126604, 0x000019410000e69a};
  __m256i_result = (__m256i){0x6d3c2d3aa1c82957, 0x0000883a00000f30,
                             0xf259905a0c126614, 0x000019410000e6aa};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000000d, 0x000000000000000d,
                             0x000000000000000d, 0x000000000000000d};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0fff0fff0fff0, 0xfff0fff0ff01ff01,
                      0xfff0fff0fff0fff0, 0xfff0fff0ff01ff01};
  __m256i_result = (__m256i){0xfff0fff0fff10003, 0xfff0fff0ff01ff14,
                             0xfff0fff0fff10003, 0xfff0fff0ff01ff14};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff47b4ffff5879, 0x0000504fffff3271,
                      0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_result = (__m256i){0xffff47b4ffff5879, 0x0000504fffff3271,
                             0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0fffffff0fffffff, 0x0fffffff0fffffff,
                      0x0fffffff0fffffff, 0x0fffffff0fffffff};
  __m256i_result = (__m256i){0x0fffffff10000006, 0x0fffffff10000006,
                             0x0fffffff10000006, 0x0fffffff10000006};
  __m256i_out = __lasx_xvaddi_du((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
