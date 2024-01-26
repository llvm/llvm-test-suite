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
  __m256i_result = (__m256i){0xe9e9e9e9e9e9e9e9, 0xe9e9e9e9e9e9e9e9,
                             0xe9e9e9e9e9e9e9e9, 0xe9e9e9e9e9e9e9e9};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x00ff00ff00000007,
                      0x00000000000000e7, 0x00ff00ff00000007};
  __m256i_result = (__m256i){0xf9f9f9f9f9f9f900, 0xf9f8f9f8f9f9f900,
                             0xf9f9f9f9f9f9f9e0, 0xf9f8f9f8f9f9f900};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x000000000000007f,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xeeeeeeeeeeeeeeee, 0xefefefefefefef6e,
                             0xefefefefefefefef, 0xefefefefefefefef};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x6aeaeaeaeaeaeaea, 0xebebebebebebebeb,
                             0x6aeaeaeaeaeaeaea, 0xebebebebebebebeb};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf6f6f6f6f6f6f6f6, 0xf6f6f6f6f6f6f6f6,
                             0xf6f6f6f6f6f6f6f6, 0xf6f6f6f6f6f6f6f6};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002a54290, 0x0000000000000000,
                      0x0000000002a54290, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000002a54290, 0x0000000000000000,
                             0x0000000002a54290, 0x0000000000000000};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7,
                             0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xefdfefdfefdfefdf, 0xefdfefdf00000000,
                      0xefdfefdfefdfefdf, 0xefdfefdf00000000};
  __m256i_result = (__m256i){0xdbcbdbcbdbcbdbcb, 0xdbcbdbcbecececec,
                             0xdbcbdbcbdbcbdbcb, 0xdbcbdbcbecececec};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0e0d0c0b0e0d0c0b, 0x0e0d0c0b0e0d0c0b,
                      0x0e0d0c0b0e0d0c0b, 0x0e0d0c0b0e0d0c0b};
  __m256i_result = (__m256i){0x0a0908070a090807, 0x0a0908070a090807,
                             0x0a0908070a090807, 0x0a0908070a090807};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9,
                             0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xf2f2f2f2f2f2f2f2, 0xf3f3f3f3f3f3f3f3,
                             0xf2f2f2f2f2f2f2f2, 0xf3f3f3f3f3f3f3f3};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xebebebebebebebeb, 0xebebebebebebebeb,
                             0xebebebebebebebeb, 0xebebebebebebebeb};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xfefefefefdfdfdfd, 0xfefefefefefefefe,
                             0xfefefefefdfdfdfd, 0xfefefefefefefefe};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xe4e4e4e4e4e4e4e4, 0xe4e4e4e4e4e4e4e4,
                             0xe4e4e4e4e4e4e4e4, 0xe4e4e4e4e4e4e4e4};
  __m256i_out = __lasx_xvsubi_bu((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff7fff7fff7fff7, 0xfff7fff7fff7fff7,
                             0xfff7fff7fff7fff7, 0xfff7fff7fff7fff7};
  __m256i_out = __lasx_xvsubi_hu((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fffa2bea2be, 0x0000000022be22be,
                      0x7fff7fffa2bea2be, 0x0000000022be22be};
  __m256i_result = (__m256i){0x7fe07fe0a29fa29f, 0xffe1ffe1229f229f,
                             0x7fe07fe0a29fa29f, 0xffe1ffe1229f229f};
  __m256i_out = __lasx_xvsubi_hu((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffe5ffe5ffe5ffe5, 0xffe5ffe5ffe5ffe5,
                             0xffe5ffe5ffe5ffe5, 0xffe5ffe5ffe5ffe5};
  __m256i_out = __lasx_xvsubi_hu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1,
                             0xfff1fff1fff1fff1, 0xfff1fff1fff1fff1};
  __m256i_out = __lasx_xvsubi_hu((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc,
                             0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m256i_out = __lasx_xvsubi_hu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000004fb, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffefffffffef, 0xffffffefffffffef,
                             0xffffffef000004ea, 0xffffffefffffffef};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffecffffffec, 0xffffffecffffffec,
                             0xffffffecffffffec, 0xffffffecffffffec};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000018,
                      0x0000000000000000, 0x0000000000000018};
  __m256i_result = (__m256i){0xfffffff3fffffff3, 0xfffffff30000000b,
                             0xfffffff3fffffff3, 0xfffffff30000000b};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffff5fffffff5, 0xfffffff5fffffff5,
                             0xfffffff5fffffff5, 0xfffffff5fffffff5};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffe5ffffffe5, 0xffffffe5ffffffe5,
                             0xffffffe5ffffffe5, 0xffffffe5ffffffe5};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffeaffffffea, 0xffffffeaffffffea,
                             0xffffffeaffffffea, 0xffffffeaffffffea};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x5d20a0a15d20a0a1,
                      0x0000000000000000, 0x5d20a0a15d20a0a1};
  __m256i_result = (__m256i){0xffffffe8ffffffe8, 0x5d20a0895d20a089,
                             0xffffffe8ffffffe8, 0x5d20a0895d20a089};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffe8ffffffe8, 0xffffffe8ffffffe8,
                             0xffffffe8ffffffe8, 0xffffffe8ffffffe8};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffcfffffffc, 0xfffffffcfffffffc,
                             0xfffffffcfffffffc, 0xfffffffcfffffffc};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c0df5b41cf, 0xfffeb683007ffd80,
                      0xfffe97c0df5b41cf, 0xfffeb683007ffd80};
  __m256i_result = (__m256i){0xfffe97a1df5b41b0, 0xfffeb664007ffd61,
                             0xfffe97a1df5b41b0, 0xfffeb664007ffd61};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffe7ffffffe7, 0xffffffe7ffffffe7,
                             0xffffffe7ffffffe7, 0xffffffe7ffffffe7};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000400100004001, 0x0000400000003ffb,
                      0x0000400100004001, 0x0000400000003ffb};
  __m256i_result = (__m256i){0x00003ff000003ff0, 0x00003fef00003fea,
                             0x00003ff000003ff0, 0x00003fef00003fea};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffe4ffffffe4, 0xffffffe4ffffffe4,
                             0xffffffe4ffffffe4, 0xffffffe4ffffffe4};
  __m256i_out = __lasx_xvsubi_wu((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000101, 0xfffffffffffffefe,
                      0x0000000000000101, 0xfffffffffffffefe};
  __m256i_result = (__m256i){0x00000000000000fe, 0xfffffffffffffefb,
                             0x00000000000000fe, 0xfffffffffffffefb};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffffc0008001, 0x0000ffffc0008001,
                      0x0000ffffc0008001, 0x0000ffffc0008001};
  __m256i_result = (__m256i){0x0000ffffc0007fe9, 0x0000ffffc0007fe9,
                             0x0000ffffc0007fe9, 0x0000ffffc0007fe9};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffffffff6, 0xfffffffffffffff6,
                             0xfffffffffffffff6, 0xfffffffffffffff6};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffee, 0xffffffffffffffee,
                             0xffffffffffffffee, 0xffffffffffffffee};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffe6, 0xffffffffffffffe6,
                             0xffffffffffffffe6, 0xffffffffffffffe6};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffe1, 0xffffffffffffffe1,
                             0xffffffffffffffe1, 0xffffffffffffffe1};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000100080, 0x0000000000000080,
                      0x0000000000100080, 0x0000000000000080};
  __m256i_result = (__m256i){0x000000000010006d, 0x000000000000006d,
                             0x000000000010006d, 0x000000000000006d};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffee, 0xffffffffffffffef,
                             0xffffffffffffffee, 0xffffffffffffffef};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffffffff4, 0xfffffffffffffff4,
                             0xfffffffffffffff4, 0xfffffffffffffff4};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffed, 0xffffffffffffffed,
                             0xffffffffffffffed, 0xffffffffffffffed};
  __m256i_out = __lasx_xvsubi_du((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
