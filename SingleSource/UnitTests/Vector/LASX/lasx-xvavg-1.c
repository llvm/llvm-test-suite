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
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  __m256i_result = (__m256i){0x000000000000001f, 0x000000000000001f,
                             0x000000000000001f, 0x000000000000001f};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x00000000fffffffe,
                      0x0000000000000001, 0x00000000fffffffe};
  v4u64_op1 = (v4u64){0x0001ff640001fefd, 0x0001009a000100fd,
                      0x0001ffe20001fefd, 0x000100da000100fd};
  __m256i_result = (__m256i){0x0000ff320000ffff, 0x000000cdff00fffd,
                             0x0000fff10000ffff, 0x000000edff00fffd};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff295329, 0xfffffffffefefeff,
                      0xffffffffff295329, 0xfffffffffefefeff};
  v4u64_op1 = (v4u64){0x0000000000c40086, 0x00fe01f000010000,
                      0x0000000000c40086, 0x00fe01f000010000};
  __m256i_result = (__m256i){0xfffffffffff629d7, 0xfffe00f7ffffffff,
                             0xfffffffffff629d7, 0xfffe00f7ffffffff};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xa020202020206431, 0xa020202020202020,
                      0xa020202020206431, 0xa020202020202020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xd010101010103218, 0xd010101010101010,
                             0xd010101010103218, 0xd010101010101010};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff00000000,
                      0x0000ffff00000000, 0x0000ffff00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000ffff00000000,
                             0x0000ffff00000000, 0x0000ffff00000000};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000800000008, 0x0000000800200027,
                      0x0000000800200028, 0x0000000800200027};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000400000004, 0x0000000400100013,
                             0x0000000400100014, 0x0000000400100013};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefffffffeff, 0xfffffefffffffeff,
                      0xfffffefffffffeff, 0xfffffefffffffeff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvavg_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00010003, 0x0080000200000002,
                      0x0000ffff00010003, 0x0000000200000002};
  v4u64_op1 = (v4u64){0x0000ffff00010002, 0x0080000200000002,
                      0x0000ffff00010002, 0x0000000200000002};
  __m256i_result = (__m256i){0x0000ffff00010002, 0x0080000200000002,
                             0x0000ffff00010002, 0x0000000200000002};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0010001000100010, 0x0010001000100010,
                      0x0010001000100010, 0x0010001000100010};
  __m256i_result = (__m256i){0x0008000800080008, 0x0008000800080008,
                             0x0008000800080008, 0x0008000800080008};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2020202020202020, 0x2020202020202020,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000007,
                      0x0000000000000000, 0x0000000000000007};
  v4u64_op1 = (v4u64){0x2020202020202020, 0x2020202020202020,
                      0x2020202020202020, 0x2020202020202020};
  __m256i_result = (__m256i){0x1010101010101010, 0x1010101010101013,
                             0x1010101010101010, 0x1010101010101013};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000006170, 0x0000000000000000,
                      0x0000000000006170, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000030b8, 0x0000000000000000,
                             0x00000000000030b8, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0202010202020102, 0x0202010202020102,
                      0x0202010202020102, 0x0202010202020102};
  v4u64_op1 = (v4u64){0x0202010202020102, 0x0202010202020102,
                      0x0202010202020102, 0x0202010202020102};
  __m256i_result = (__m256i){0x0202010202020102, 0x0202010202020102,
                             0x0202010202020102, 0x0202010202020102};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000200,
                      0x0000000000000002, 0x0000000000000200};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000100,
                             0x0000000000000001, 0x0000000000000100};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000405, 0x0000000001010100,
                      0x0000000000000405, 0x0000000001010100};
  __m256i_result = (__m256i){0x0000000000000202, 0x0000000000800080,
                             0x0000000000000202, 0x0000000000800080};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000002000000020, 0x0000000000000000,
                      0x0000002000000020, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000000000000000,
                             0x0000001000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0000, 0xffffffffffffffff,
                      0xffff0000ffff0000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000a000a000a000a, 0x000a000a000a000a,
                      0x000a000a000a000a, 0x000a000a000a000a};
  __m256i_result = (__m256i){0x0004000500040005, 0x0004000400040004,
                             0x0004000500040005, 0x0004000400040004};
  __m256i_out = __lasx_xvavg_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0xe3aebaf4df958004, 0x36722a7e66972cd6,
                      0x00d6c1c830160048, 0x8b1414140e0e0e0e};
  __m256i_result = (__m256i){0xf1d75d79efcac002, 0x1b39153f334b966a,
                             0x006b60e4180b0023, 0xc58a0a0a07070706};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00007fff00007fff, 0x00007fff00007fff,
                             0x00007fff00007fff, 0x00007fff00007fff};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffe00000000000,
                      0x0000000000000000, 0xffffe00000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xfffff00000000000,
                             0x0000000000000000, 0xfffff00000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x007fffffffffffff,
                      0xffffffffffffffff, 0x007fffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x003fffffffffffff,
                             0xffffffffffffffff, 0x003fffffffffffff};
  __m256i_out = __lasx_xvavg_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff00000000, 0x0000000000000000,
                      0x0000ffff00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00007fff7fffffff, 0x0000000000000000,
                             0x00007fff7fffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0x00000000ffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0080808000808080, 0x0080808100808080,
                             0x0080808080808080, 0x0080808080808080};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1111111111111111, 0x1111111111111111,
                      0x1111111111111111, 0x1111111111111111};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0888888888888888, 0x0888888888888888,
                             0x0888888888888888, 0x0888888888888888};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fffffff, 0x0000000000000000,
                             0x000000007fffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3e6ce7d9cb7afb62, 0x4010000000000000,
                      0x3e6ce7d9cb7afb62, 0x4010000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1f3673ece5bd7db1, 0x2008000000000000,
                             0x1f3673ece5bd7db1, 0x2008000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000400000003fff, 0x0000000000000000,
                             0x0000400000003fff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000040404000, 0x0000000000000000,
                      0x0000000040404000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000020202000, 0x0000000000000000,
                             0x0000000020202000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000003fc03bbc, 0xfffffffffc01fc01,
                      0x000000003fc03bbc, 0xfffffffffc01fc01};
  __m256i_result = (__m256i){0x000000001fe01dde, 0xfffffffffe00fe00,
                             0x000000001fe01dde, 0xfffffffffe00fe00};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000100080, 0x0000000000000080,
                      0x0000000000100080, 0x0000000000000080};
  __m256i_result = (__m256i){0x0000000000080040, 0x0000000000000040,
                             0x0000000000080040, 0x0000000000000040};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000003, 0x0040000000000003,
                      0x0000000000000003, 0x0040000000000003};
  __m256i_result = (__m256i){0x0000000000000001, 0x0020000000000001,
                             0x0000000000000001, 0x0020000000000001};
  __m256i_out = __lasx_xvavg_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
