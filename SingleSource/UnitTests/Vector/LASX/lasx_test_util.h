#ifndef LASX_TEST_UTIL_H
#define LASX_TEST_UTIL_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

__attribute__((noinline)) void check_lasx_out(void *expected, void *got,
                                              int len, const char *fname,
                                              int line) {
  int i = 0;
  int num = MIN(len, 32);
  if (memcmp(expected, got, num) != 0) {
    printf("%s:%d: \n", fname, line);
    printf("0x");
    for (i = 0; i < num; i++) {
      printf(" %02x", ((char *)expected)[i] & 0xff);
    }
    printf(" != \n");
    printf("0x");
    for (i = 0; i < num; i++) {
      printf(" %02x", ((char *)got)[i] & 0xff);
    }
    printf("\n");
  }
}

// Used for comparing floating-point results when the result is NAN, but the
// bitwise comparison with the expected NAN differs.
__attribute__((noinline)) void check_lasx_fp_out(_Bool IsDouble, void *expected,
                                                 void *got, int len,
                                                 const char *fname, int line) {
  // num of elements
  int N = IsDouble == 1 ? 8 : 4;
  for (int i = 0; i < 32; i += N) {
    if (!memcmp(expected + i, got + i, N))
      continue;
    if (IsDouble && isnan(*(double *)(expected + i)) &&
        isnan(*(double *)(got + i)))
      continue;
    if (!IsDouble && isnan(*(float *)(expected + i)) &&
        isnan(*(float *)(got + i)))
      continue;
    check_lasx_out(expected, got, len, fname, line);
    return;
  }
}

#endif
