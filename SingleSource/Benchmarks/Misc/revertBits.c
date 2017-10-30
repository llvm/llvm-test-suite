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
#include <stdlib.h>

#define NUM 0x1000000

unsigned __attribute__((noinline)) ReverseBits32(unsigned n) {
  n = ((n >> 1) & 0x55555555u) | ((n & 0x55555555u) << 1);
  n = ((n >> 2) & 0x33333333u) | ((n & 0x33333333u) << 2);
  n = ((n >> 4) & 0x0F0F0F0Fu) | ((n & 0x0F0F0F0Fu) << 4);
  return ((n & 0xff000000u) >> 24) | ((n & 0x00ff0000u) >> 8) |
         ((n & 0x0000ff00u) << 8) | ((n & 0x000000ffu) << 24);
}

unsigned long long __attribute__((noinline)) ReverseBits64(unsigned long long n) {
  n = ((n >> 1) & 0x5555555555555555ull) | ((n & 0x5555555555555555ull) << 1);
  n = ((n >> 2) & 0x3333333333333333ull) | ((n & 0x3333333333333333ull) << 2);
  n = ((n >> 4) & 0x0F0F0F0F0F0F0F0Full) | ((n & 0x0F0F0F0F0F0F0F0Full) << 4);
  return ((n & 0xFF00000000000000ull) >> 56) |
         ((n & 0x00FF000000000000ull) >> 40) |
         ((n & 0x0000FF0000000000ull) >> 24) |
         ((n & 0x000000FF00000000ull) >> 8)  |
         ((n & 0x00000000000000FFull) << 56) |
         ((n & 0x000000000000FF00ull) << 40) |
         ((n & 0x0000000000FF0000ull) << 24) |
         ((n & 0x00000000FF000000ull) << 8);
}

int main (void) {
  unsigned long long sum32 = 0, sum64 = 0;
  unsigned int rev32 = strtoll("0x12345678", NULL, 16);
  unsigned long long rev64 = strtoll("0x0123456789012345", NULL, 16);

// Check for compilers that don't support __has_builtin
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

// Check for compilers that support __has_builtin but not __builtin_bitreverse*
#if (!__has_builtin(__builtin_bitreverse32) ||\
     !__has_builtin(__builtin_bitreverse64))
  printf("0x%x -> 0x%x\n", rev32, ReverseBits32(rev32));
  printf("0x%llx -> 0x%llx\n", rev64, ReverseBits64(rev64));
  return 0;
#else

  for (int i = 0; i < NUM; ++i) {
    sum32 += ReverseBits32(i);
    sum64 += ReverseBits64(i);
  }
  for (int i = 0; i < NUM; ++i) {
    sum32 -= __builtin_bitreverse32(i);
    sum64 -= __builtin_bitreverse64(i);
  }
  printf("0x%x -> 0x%x\n", rev32, __builtin_bitreverse32(rev32));
  printf("0x%llx -> 0x%llx\n", rev64, __builtin_bitreverse64(rev64));
  return sum32 == 0 && sum64 == 0 ? 0 : 1;
#endif
}
