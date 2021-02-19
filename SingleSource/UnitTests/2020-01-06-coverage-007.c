#include <stdint.h>
#include <stdio.h>

uint32_t a;
const uint32_t b = -1L, c;
int16_t d;

void e() {
  uint32_t f;
  uint32_t g;
  f = b / a;
  g = f;
  d = g < c;
}

int main() {
  int16_t val_2;
  uint32_t val_1;

  val_1 = 3;
  val_2 = -32767;

  d = val_2;
  a = val_1;
  e();

  printf("a = %i\n", a);
  printf("b = %i\n", b);
  printf("c = %i\n", c);
  printf("d = %i\n", d);

  return 0;
}
