#include <stdio.h>

void print(float X) {
  printf("%f\n", X*2147483647);
  printf("%x\n", X*2147483647);
}

int main() {
  print(1000);

  return 0;
}
