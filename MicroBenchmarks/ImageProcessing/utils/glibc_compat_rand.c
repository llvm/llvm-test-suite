/*===------------ glibc_compat_rand.c - glibc rand emulation --------------===*\
 *
 *                     The LLVM Compiler Infrastructure
 *
 * This file is distributed under the University of Illinois Open Source
 * License. See LICENSE.TXT for details.
 *
\*===----------------------------------------------------------------------===*/

#include "glibc_compat_rand.h"

/**
 * This rand implementation is designed to emulate the implementation of
 * rand/srand in recent versions of glibc. This is used for programs which
 * require this specific rand implementation in order to pass verification
 * tests.
 *
 * For more information, see: http://www.mathstat.dal.ca/~selinger/random/
 **/

#define TABLE_SIZE 344
static unsigned int table[TABLE_SIZE];
static int next;

int glibc_compat_rand(void) {
  /* Calculate the indices i-3 and i-31 in the circular vector. */
  int i3 = (next < 3) ? (TABLE_SIZE + next - 3) : (next - 3);
  int i31 = (next < 31) ? (TABLE_SIZE + next - 31) : (next - 31);

  table[next] = table[i3] + table[i31];
  unsigned int r = table[next] >> 1;

  ++next;
  if (next >= TABLE_SIZE)
    next = 0;

  return r;
}

void glibc_compat_srand(unsigned int seed) {
  if (seed == 0)
    seed = 1;

  table[0] = seed;

  for (int i = 1; i < 31; i++) {
    int r = (16807ll * table[i - 1]) % 2147483647;
    if (r < 0)
      r += 2147483647;

    table[i] = r;
  }

  for (int i = 31; i < 34; i++)
    table[i] = table[i - 31];
  for (int i = 34; i < TABLE_SIZE; i++)
    table[i] = table[i - 31] + table[i - 3];

  next = 0;
}
