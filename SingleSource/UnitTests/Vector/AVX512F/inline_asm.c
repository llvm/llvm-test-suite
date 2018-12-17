/*
 * Exercise a very simple inline asm sequence.
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

__m512d a;
__m512d b;
__m512d c;

void NOINLINE foo() {
  void *pa, *pb;

  pa = &a;
  pb = &b;

  __asm {
        mov         FULL_IREG(ax), [pa]
        mov         FULL_IREG(dx), [pb]
        vmovapd     zmm0, ZMMWORD PTR [FULL_IREG(ax)]
        vaddpd      zmm2, zmm0, ZMMWORD PTR [FULL_IREG(dx)]
        vmovapd     ZMMWORD PTR [FULL_IREG(ax)], zmm2
  }
}

static void NOINLINE init() {
  int i;
  double *pa, *pb, *pc;

  pa = (double *)&a;
  pb = (double *)&b;
  pc = (double *)&c;

  for (i = 0; i < sizeof(a) / sizeof(double); i++) {
    *pa++ = i * i;
    *pb++ = (i + 8) * (i + 8);
    *pc++ = i * i + (i + 8) * (i + 8);
  }
}

int main() {
  init();
  foo();

  if (memcmp(&a, &c, sizeof(a)) != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
