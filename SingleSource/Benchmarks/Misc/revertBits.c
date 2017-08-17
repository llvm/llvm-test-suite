/*
 * A performance regression test for bit reverse. The bit reverse algorithm on
 * PPC was O(N) and had lots of dependency between contiguous instructions. We
 * replace it with a faster O(lgN) algorithm in the following two patches:
 * https://reviews.llvm.org/D33572
 * https://reviews.llvm.org/D34908
 * This test case tests both the 32-bit and 64-bit bit reverse to ensure the
 * new implementation is functionally correct and has a better performance.
 */
#include <stdio.h>
#define NUM 0x1000000
int __attribute__((noinline)) ReverseBits32(int n) {
  n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1);
  n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2);
  n = ((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4);
  return ((n & 0xff000000u) >> 24) | ((n & 0x00ff0000u) >> 8) |
         ((n & 0x0000ff00u) << 8) | ((n & 0x000000ffu) << 24);
}

long long __attribute__((noinline)) ReverseBits64(long long n) {
  n = ((n >> 1) & 0x5555555555555555L) | ((n & 0x5555555555555555L) << 1);
  n = ((n >> 2) & 0x3333333333333333L) | ((n & 0x3333333333333333L) << 2);
  n = ((n >> 4) & 0x0F0F0F0F0F0F0F0FL) | ((n & 0x0F0F0F0F0F0F0F0FL) << 4);
  return ((n & 0xFF00000000000000L) >> 56) |
         ((n & 0x00FF000000000000L) >> 40) |
         ((n & 0x0000FF0000000000L) >> 24) |
         ((n & 0x000000FF00000000L) >> 8)  |
         ((n & 0x00000000000000FFL) << 56) |
         ((n & 0x000000000000FF00L) << 40) |
         ((n & 0x0000000000FF0000L) << 24) |
         ((n & 0x00000000FF000000L) << 8);
}

int main (void) {
  unsigned long long sum = 0;

// Check for compilers that don't support __has_builtin
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

// Check for compilers that support __has_builtin but not __builtin_bitreverse*
#if (!__has_builtin(__builtin_bitreverse32) ||\
     !__has_builtin(__builtin_bitreverse64))
  printf("Sum1 = 0, Sum2 = feff800000800000\n");
  return 0;
#else

  for (int i = 0; i < NUM; ++i) {
    sum += ReverseBits32(__builtin_bitreverse32(i));
    sum -= ReverseBits64(__builtin_bitreverse64(i));
  }
  printf("Sum1 = %llx, ", sum);

  for (int i = 0; i < NUM; ++i) {
    sum -= ReverseBits64(ReverseBits64(0x100000000 + i));
  }
  printf("Sum2 = %llx\n", sum);

  return 0;
#endif
}
