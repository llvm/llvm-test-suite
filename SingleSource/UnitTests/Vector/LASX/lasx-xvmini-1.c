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

  v4u64_op0 = (v4u64){0xfbe0b866962b96d0, 0x14187a7822b653c0,
                      0x44a4330e2c7116c0, 0xf96d674800000000};
  __m256i_result = (__m256i){0xfbe0b80c960c96d0, 0x0c0c0c0c0cb60cc0,
                             0x0ca40c0c0c0c0cc0, 0xf90c0c0c00000000};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff1bfca0011bfcb, 0x0010bfc80010bf52,
                      0xfff1bfca0011bfcb, 0x0010bfc80010bf52};
  __m256i_result = (__m256i){0xf5f1bfcaf5f5bfcb, 0xf5f5bfc8f5f5bff5,
                             0xf5f1bfcaf5f5bfcb, 0xf5f5bfc8f5f5bff5};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, -11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8,
                             0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, -8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000aaabffff, 0x00000000aaabffff,
                      0x00000000aaabffff, 0x00000000aaabffff};
  __m256i_result = (__m256i){0x00000000aaabffff, 0x00000000aaabffff,
                             0x00000000aaabffff, 0x00000000aaabffff};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000b84b0000a787, 0xffff47b4ffff5878,
                      0x0000b84b0000a787, 0xffff47b4ffff5878};
  __m256i_result = (__m256i){0x0000b8070000a787, 0xffff07b4ffff0707,
                             0x0000b8070000a787, 0xffff07b4ffff0707};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                             0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, -9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf3f3f3f3f3f3f3f3, 0xf3f3f3f3f3f3f3f3,
                             0xf3f3f3f3f3f3f3f3, 0xf3f3f3f3f3f3f3f3};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, -13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9,
                             0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, -7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc30e0000ff800000, 0xff800000ff800000,
                      0xc30e0000ff800000, 0xff800000ff800000};
  __m256i_result = (__m256i){0xc3030000ff800000, 0xff800000ff800000,
                             0xc3030000ff800000, 0xff800000ff800000};
  __m256i_out = __lasx_xvmini_b((__m256)v4u64_op0, 3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6,
                             0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, -10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0383634303836343, 0x1fffffff1fffffff,
                      0x0383634303836343, 0x1fffffff1fffffff};
  __m256i_result = (__m256i){0x0002000200020002, 0x0002ffff0002ffff,
                             0x0002000200020002, 0x0002ffff0002ffff};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, 2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000f93b0000017b, 0x0000f7bc0001f7bd,
                      0x0000f93b0000017c, 0x0000f7bc0001f7bd};
  __m256i_result = (__m256i){0xfff2f93bfff2fff2, 0xfff2f7bcfff2f7bd,
                             0xfff2f93bfff2fff2, 0xfff2f7bcfff2f7bd};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, -14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, 6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, 13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff9fff9fff9fff9, 0xfff9fff9fff9fff9,
                             0xfff9fff9fff9fff9, 0xfff9fff9fff9fff9};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, -7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff3fff3fff3fff3, 0xfff3fff3fff3fff3,
                             0xfff3fff3fff3fff3, 0xfff3fff3fff3fff3};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, -13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfff2fff2fff2fff2, 0xfff2fff2fff2fff2,
                             0xfff2fff2fff2fff2, 0xfff2fff2fff2fff2};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, -14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_h((__m256)v4u64_op0, 11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x555555ab555555ab, 0x555555ab555555ab,
                      0x555555ab555555ab, 0x555555ab555555ab};
  __m256i_result = (__m256i){0x0000000400000004, 0x0000000400000004,
                             0x0000000400000004, 0x0000000400000004};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, 4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fff0e400, 0x00000000ffffffff,
                      0x00000000ffff8c80, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x00000000fff0e400, 0x00000000ffffffff,
                             0x00000000ffff8c80, 0x00000000ffffffff};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, 12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000001000000010,
                             0x0000000000000000, 0x0000001000000010};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000100000,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfffffff2fffffff2, 0xfffffff2fffffff2,
                             0xfffffff2fffffff2, 0xfffffff2fffffff2};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, -14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100010001, 0x0001000000000000,
                      0x0000000100010001, 0x0001000000000000};
  __m256i_result = (__m256i){0x000000010000000a, 0x0000000a00000000,
                             0x000000010000000a, 0x0000000a00000000};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, 10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffff8fffffff8, 0xfffffff8fffffff8,
                             0xfffffff8fffffff8, 0xfffffff8fffffff8};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, -8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000001e0000001e, 0x0000001e0000001e,
                             0x0000001e0000001e, 0x0000001e0000001e};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000020006, 0x0000000000020006,
                      0x0000000000020006, 0x0000000000020006};
  __m256i_result = (__m256i){0x000000000000000c, 0x000000000000000c,
                             0x000000000000000c, 0x000000000000000c};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fe000000000, 0x0000000000000000,
                      0x00003fe000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001400000000, 0x0000000000000000,
                             0x0000001400000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000017, 0x0000000000000000,
                             0x0000000000000017, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffff7fffffff7, 0xfffffff7fffffff7,
                             0xfffffff7fffffff7, 0xfffffff7fffffff7};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, -9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, 4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffff0fffffff0, 0xfffffff0fffffff0,
                             0xfffffff0fffffff0, 0xfffffff0fffffff0};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, -16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000ffffffffffff,
                      0x0000000000000000, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmini_w((__m256)v4u64_op0, -1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001fffc7ff1, 0x00000001fffc8027,
                      0x00000001fffc7ff1, 0x00000001fffc8027};
  __m256i_result = (__m256i){0x0000000100000014, 0x0000000100000014,
                             0x0000000100000014, 0x0000000100000014};
  __m256i_out = __lasx_xvmini_wu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, 11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6300000000000000, 0x327f010101010102,
                      0x6300000000000000, 0x327f010101010102};
  __m256i_result = (__m256i){0xfffffffffffffff4, 0xfffffffffffffff4,
                             0xfffffffffffffff4, 0xfffffffffffffff4};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, -12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000900000009, 0x0000000900000009,
                      0x0000000900000009, 0x0000000900000009};
  __m256i_result = (__m256i){0x0000000000000009, 0x0000000000000009,
                             0x0000000000000009, 0x0000000000000009};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, 9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, 13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, -1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ff007f007f00, 0xff00ff00ff00ff00,
                      0xff00ff007f007f00, 0xff00ff00ff00ff00};
  __m256i_result = (__m256i){0xff00ff007f007f00, 0xff00ff00ff00ff00,
                             0xff00ff007f007f00, 0xff00ff00ff00ff00};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, -5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffffffff,
                      0x0000000000000000, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000000000000c,
                             0x0000000000000000, 0x000000000000000c};
  __m256i_out = __lasx_xvmini_d((__m256)v4u64_op0, 12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
