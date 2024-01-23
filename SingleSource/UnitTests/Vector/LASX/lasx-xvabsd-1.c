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

  v4u64_op0 = (v4u64){0x063f2bb758abc664, 0x4a1c269b8e892a3a,
                      0x1820939b2280fa86, 0x34598d0fd19314cb};
  v4u64_op1 = (v4u64){0x0000288a00003c1c, 0x0000000000000000,
                      0xffffc0fcffffcf83, 0x0000000000000000};
  __m256i_result = (__m256i){0x063f032d58557648, 0x4a1c266572772a3a,
                             0x19212d61237f2b03, 0x3459730f2f6d1435};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1cfd000000000000, 0xfe00000000000000,
                      0x1cfd000000000000, 0xfe00000000000000};
  v4u64_op1 = (v4u64){0x1cfd000000000000, 0xfe00000000000000,
                      0x1cfd000000000000, 0xfe00000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000000007fff7fff,
                      0x0000000000000000, 0x000000007fff7fff};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000007f017f01,
                             0x0000000000000000, 0x000000007f017f01};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000b2673a90896a4, 0x000050504c4c2362,
                      0x000b2673a90896a4, 0x000050504c4c2362};
  v4u64_op1 = (v4u64){0xd0d8eecf383fdf0d, 0x0001000100010001,
                      0xd0d8eecf383fdf0d, 0x0001000100010001};
  __m256i_result = (__m256i){0x303338a48f374969, 0x0001504f4c4b2361,
                             0x303338a48f374969, 0x0001504f4c4b2361};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000002, 0x0000000000000002,
                      0x0000000000000002, 0x0000000000000002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000000002,
                             0x0000000000000002, 0x0000000000000002};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80817fff00810000, 0x807c7fffffffffff,
                      0x80817fff00810000, 0x807c7fffffffffff};
  v4u64_op1 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  __m256i_result = (__m256i){0x80817f01007f0000, 0x80767f0101050101,
                             0x80817f01007f0000, 0x80767f0101050101};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x437fe01fe01fe020,
                      0x0000000000000000, 0x437fe01fe01fe020};
  v4u64_op1 = (v4u64){0x037fe01f001fe020, 0x0000000000000000,
                      0x037fe01f001fe020, 0x0000000000000000};
  __m256i_result = (__m256i){0x037f201f001f2020, 0x437f201f201f2020,
                             0x037f201f001f2020, 0x437f201f201f2020};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1fa0000000080000, 0x0000000000000000,
                      0x1fa0000000080000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000010000000100, 0x0000000000000000,
                      0x0000010000000100, 0x0000000000000000};
  __m256i_result = (__m256i){0x1f60010000080100, 0x0000000000000000,
                             0x1f60010000080100, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0101010101010101,
                             0x0000000000000000, 0x0101010101010101};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000002780, 0x0000000000000000,
                      0x0000000000002780, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_result = (__m256i){0x040f040f040b236d, 0x0000010100020103,
                             0x040f040f040b236d, 0x0000010100020103};
  __m256i_out = __lasx_xvabsd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100010000, 0x0000000100010000,
                      0x0000000100010000, 0x0000000100010000};
  __m256i_result = (__m256i){0x0000000100010080, 0x0000000100010000,
                             0x0000000100010080, 0x0000000100010000};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000073333333, 0x0000000044444443,
                      0x0000000073333333, 0x0000000044444443};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000073333333, 0x0000000044444443,
                             0x0000000073333333, 0x0000000044444443};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000040c100000101, 0x000050fd00000101,
                      0x000040c100000101, 0x000050fd00000101};
  __m256i_result = (__m256i){0x000040c100000101, 0x000050fd00000101,
                             0x000040c100000101, 0x000050fd00000101};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x8000000080000000,
                      0xffffffffffffffff, 0x8000000080000000};
  v4u64_op1 = (v4u64){0xfe0000bcff000100, 0x01ffff4300fffeff,
                      0xfe0000bcff000100, 0x01ffff4300fffeff};
  __m256i_result = (__m256i){0x01ff00bd00ff0101, 0x81ff00bd80ff0101,
                             0x01ff00bd00ff0101, 0x81ff00bd80ff0101};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  v4u64_op1 = (v4u64){0x00003ff000003ff0, 0x00003fef00003fea,
                      0x00003ff000003ff0, 0x00003fef00003fea};
  __m256i_result = (__m256i){0x00003fe900014022, 0x00003fea00013feb,
                             0x00003fe900014022, 0x00003fea00013feb};
  __m256i_out = __lasx_xvabsd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xcc9b89f2f6cef440, 0xffffffffffffffff,
                      0x0cc08723ff900001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3364760e09310bc0, 0x0000000100000001,
                             0x0cc08723006fffff, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000017f0000017f, 0x0000000000010001,
                      0x0000017f0000017d, 0x0000000000010001};
  __m256i_result = (__m256i){0x0000017f0000017f, 0x0000000000010001,
                             0x0000017f0000017d, 0x0000000000010001};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00fe01f000000000,
                      0x0000000000000000, 0x00fe01f000000000};
  v4u64_op1 = (v4u64){0xd6ef750000000000, 0xbf800000bf800000,
                      0xd662fa0000000000, 0xbf800000bf800000};
  __m256i_result = (__m256i){0x29108b0000000000, 0x417e01f040800000,
                             0x299d060000000000, 0x417e01f040800000};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000001700170017, 0x0000000000000017,
                      0x0000001700170017, 0x0000000000000017};
  __m256i_result = (__m256i){0x0000001700170017, 0x0000000000000017,
                             0x0000001700170017, 0x0000000000000017};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffa0078fffa0074, 0xfffefffefffefffe,
                      0xfffa0078fffa0074, 0xfffefffefffefffe};
  v4u64_op1 = (v4u64){0xfffffffffffffffa, 0xfffffffffb79fb74,
                      0xfffffffffffffffa, 0xfffffffffb79fb74};
  __m256i_result = (__m256i){0x0005ff870005ff86, 0x000100010485048a,
                             0x0005ff870005ff86, 0x000100010485048a};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000010001,
                      0x0000000000010001, 0x0000000000010001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010001, 0x0000000000010001,
                             0x0000000000010001, 0x0000000000010001};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000005,
                      0xffffffffffffffff, 0x0000000000000005};
  v4u64_op1 = (v4u64){0x0000400000004000, 0x0000400000004000,
                      0x0000400000004000, 0x0000400000004000};
  __m256i_result = (__m256i){0x0000400100004001, 0x0000400000003ffb,
                             0x0000400100004001, 0x0000400000003ffb};
  __m256i_out = __lasx_xvabsd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffe00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000200000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff00000000, 0x0000000000000000,
                      0x0000ffff00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000000000000000,
                             0x0000ffff00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvabsd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
