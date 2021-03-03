#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t a, b, h;
int16_t c, g;
uint8_t d = 8;
uint8_t *const e = &d;
int32_t *f;

void i() {
  for (; c; c--) {
    g = 0;
    for (; g <= 8; g++) {
      h = ((b & a) ^ a ^ (b & a) ^ b) < b;
      *e ^= h;
      *f = 0;
    }
  }
}

int main() {
  int32_t val_6;
  int32_t temp_1;
  int16_t val_5;
  int16_t val_4;
  uint32_t val_3;
  uint32_t val_2;
  uint32_t val_1;

  val_1 = 0;
  val_2 = 1;
  val_3 = 0xFFFFFFFF;
  val_4 = -32767;
  val_5 = -32767;
  val_6 = -2130706432;
  temp_1 = val_6;

  f = &temp_1;
  g = val_5;
  c = val_4;
  h = val_3;
  b = val_2;
  a = val_1;
  i();

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu32 "\n", b);
  printf("c = %" PRIi16 "\n", c);
  printf("d = %" PRIu8 "\n", d);
  printf("g = %" PRIi16 "\n", g);
  printf("h = %" PRIu32 "\n", h);

  return 0;
}
