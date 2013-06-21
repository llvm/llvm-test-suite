#include <stdio.h>
extern void foo32(float x);

int __attribute__((mips16)) main() {
  foo32(4.5678);
  printf("main  \n");
  return 0;
}
