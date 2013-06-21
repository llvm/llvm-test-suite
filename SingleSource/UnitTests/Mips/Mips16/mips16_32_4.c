#include <stdio.h>

void __attribute__((mips16)) foo (void) {
  printf("in foo: mips16\n");
}
void __attribute__((nomips16)) nofoo (void) {
  printf("in foo: mips32\n");
}

int __attribute__((mips16)) main() {
  foo();
  nofoo();
  printf("in main: mips16\n");
}


