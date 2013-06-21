#include <stdio.h>
void __attribute__((nomips16)) foo32(float x) {
  printf("in foo32: %f \n", x);
}
