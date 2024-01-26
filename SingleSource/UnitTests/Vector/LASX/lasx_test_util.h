#ifndef LASX_TEST_UTIL_H
#define LASX_TEST_UTIL_H

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

#endif
