
#include <stdio.h>

static void func(unsigned i) {
  switch (i) {
  case 8: printf("C\n"); /* fall through. */
  case 0:
  case 3:
  case 2: printf("A\n"); break;
  case 1:
  case 7:
  case 9: printf("B\n"); break;
  default: printf("D\n");
  }
}


void main() {
  unsigned i;
  for (i = 0; i < 10; ++i)
    func(i);
}
