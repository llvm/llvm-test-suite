/* Companion file for bind-c-value.f90. Each function checks the contents of a
   derived type that was passed by value from Fortran, so a mismatch means the
   argument was not passed according to the ABI. */

#include <stdlib.h>

typedef struct { char a[16]; } t16;
typedef struct { char a[17]; } t17;
typedef struct { char a[128]; } t128;

static void check_contents(const char *a, int n) {
  int i;

  for (i = 0; i < n; i++)
    if (a[i] != (char)(i % 127 + 1))
      abort();
}

void check_t16(t16 x) { check_contents(x.a, 16); }

void check_t17(t17 x) { check_contents(x.a, 17); }

void check_t128(t128 x) { check_contents(x.a, 128); }

/* A derived type that is passed as a pointer to a copy still uses an argument
   register, so i and j must arrive in the registers that follow it. */

void check_mixed(void *p, int i, t128 x, int j) {
  if (p != NULL || i != 11 || j != 22)
    abort();
  check_contents(x.a, 128);
}
