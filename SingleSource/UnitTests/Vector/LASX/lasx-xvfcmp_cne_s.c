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

  v8i32_op0 = (v8i32){0x7fff7fff, 0x00007fff, 0x7fff7fff, 0x7fff01fd,
                      0x7fff7fff, 0x7fff7fff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffff00000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000001,
                      0x00000000, 0x00000000, 0x00000000, 0x00000001};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffff00000000,
                             0x0000000000000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xdededede, 0xdededede, 0xdededede, 0xdededede,
                      0xdededede, 0xdededede, 0xdededede, 0xdededede};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000fff, 0x00001010, 0x00000051, 0x00000000,
                      0x00000fff, 0x00001010, 0x00000051, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000fff, 0x00001010, 0x00000051, 0x00000000,
                      0x00000fff, 0x00001010, 0x00000051, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x0000ffff, 0x00000000, 0x0000ffff,
                      0x00000000, 0x0000ffff, 0x00000000, 0x0000ffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffff00000000, 0xffffffff00000000,
                             0xffffffff00000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x000007c8, 0x00000000, 0x00000000, 0x00000000,
                      0x000007c8, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x80000000, 0x00000000, 0x00000000, 0x00000000,
                      0x80000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000001f, 0x00000000, 0x00000000, 0x00000000,
                      0x0000001f, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x0000001f, 0x00000000, 0x00000000, 0x00000000,
                      0x0000001f, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00090040, 0x0000ff01, 0xfff8ff40, 0x00000000,
                      0x00090040, 0x0000ff01, 0xfff8ff40, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0xff1cff1c, 0xff1cff1c, 0xff1cff1c, 0xff1cff1c,
                      0xff1cff1c, 0xff1cff1c, 0xff1cff1c, 0xff1cff1c};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x01fe000001fe0000, 0x0000000000000000,
                      0x01fe000000ff00ff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010102, 0x0101010101010102,
                      0x0101010201010204, 0x0101010101010102};
  v4u64_op1 = (v4u64){0x0000000000ff00ff, 0x0000000000000000,
                      0x0000000e00ff00ff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff0000ffff, 0xffffffff00000000,
                      0x000000000000ffff, 0xffffffff00000000};
  v4u64_op1 = (v4u64){0xfff90000fff9fff9, 0xfff9fff9fff9fff9,
                      0xfff90000fff9fff9, 0xfff9fff9fff9fff9};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x23a2a121179e951d, 0x0101010127272525,
                      0x23a2a121179e951d, 0x0101010127272525};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000e7, 0x00000000000000ff,
                      0x00000000000000e7, 0x00000000000000ff};
  v4u64_op1 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cne_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00c40086, 0x00000000, 0x00010000, 0x00fe01f0,
                      0x00c40086, 0x00000000, 0x00010000, 0x00fe01f0};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0xffffffffffffffff,
                             0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ffff, 0x00000000, 0x0000ffff, 0x00000000,
                      0x0000ffff, 0x00000000, 0x0000ffff, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0fff0181, 0x0fff0180, 0x00000001, 0x00000001,
                      0x0fff0181, 0x0fff0180, 0x00000001, 0x00000001};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x0003ffff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0xfffffe1f, 0x0000001d, 0xfffffe20, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x5fa00000,
                      0x00000000, 0x00000000, 0x00000000, 0x5fa00000};
  v8i32_op1 = (v8i32){0x00007f95, 0x00000000, 0x00000004, 0x00000000,
                      0x00007f95, 0x00000000, 0x00000004, 0x00000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0xffffffffffffffff,
                             0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00007f7f, 0x00010000, 0x7f010000, 0x00000000,
                      0x00007f7f, 0x00010000, 0x7f010000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x003f00c4, 0x003f00ff, 0x01400200, 0x003f0200,
                      0x003f00c4, 0x003f00ff, 0x01400200, 0x003f0200};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x01010101, 0x00000101,
                      0x00000000, 0x00000000, 0x01010101, 0x00000101};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000f0000000f, 0x0000002000000020,
                      0x0000000f0000000f, 0x0000002000000020};
  v4u64_op1 = (v4u64){0xdff8000000000000, 0xdff8000000000000,
                      0xdff8000000000000, 0xdff8000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000040002, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x000000000000007f,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xc600000000000000,
                      0x0000000000000000, 0xc600000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  v4u64_op1 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffff1fffffff1, 0xfffffff1fffffff1,
                      0xfffffff1fffffff1, 0xfffffff1fffffff1};
  v4u64_op1 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff56ff55ff01ff01, 0x0000000000000000,
                      0xff56ff55ff01ff01, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000800000000000, 0x0000800000000000,
                      0x0000800000000000, 0x0000800000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffff10, 0xffffffffffffffff,
                      0xffffffffffffff10, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0004000500040005, 0x0004000400040004,
                      0x0004000500040005, 0x0004000400040004};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcmp_cune_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
