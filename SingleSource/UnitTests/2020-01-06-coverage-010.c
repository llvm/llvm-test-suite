#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t *a;
int32_t b, d, f;
int8_t c;
volatile int32_t e;
int32_t x;
int8_t *p;
int32_t y;
int32_t z;
int32_t w;

static int32_t j() {
  int32_t h = 5;
  x = h;
  for (; b;) {
    f = 0;
    for (; f <= 9; f++) {
      int32_t *i = &h;
      int8_t *g = &c;
      p = g;
      y = (*i)++ && (*g = 0);
      z = e;
    }
    *a = 0;
  }
  {
    w = d;
    return w;
  };
}

int32_t v;

void k() { v = j(); }

int main() {
  int32_t val_12;
  int32_t val_11;
  int32_t val_10;
  int32_t val_9;
  int8_t val_8;
  int8_t temp_2;
  int32_t val_7;
  int32_t val_6;
  int8_t val_5;
  int32_t val_4;
  int32_t val_3;
  int32_t val_2;
  int32_t val_1;
  int32_t temp_1;

  val_1 = 0;
  val_2 = 0;
  val_3 = 0;
  val_4 = 0;
  val_5 = 0;
  val_6 = 0;
  val_7 = 0;
  val_8 = 5;
  val_9 = 0;
  val_10 = 0;
  val_11 = 0;
  val_12 = 0;
  temp_1 = val_1;
  temp_2 = val_8;

  v = val_12;
  w = val_11;
  z = val_10;
  y = val_9;
  p = &temp_2;
  x = val_7;
  e = val_6;
  c = val_5;
  f = val_4;
  d = val_3;
  b = val_2;
  a = &temp_1;
  k();

  printf("b = %" PRIi32 "\n", b);
  printf("c = %" PRIi8 "\n", c);
  printf("d = %" PRIi32 "\n", d);
  printf("x = %" PRIi32 "\n", x);
  printf("e = %" PRIi32 "\n", e);
  printf("y = %" PRIi32 "\n", y);
  printf("z = %" PRIi32 "\n", z);
  printf("v = %" PRIi32 "\n", v);
  printf("f = %" PRIi32 "\n", f);
  printf("w = %" PRIi32 "\n", w);

  return 0;
}
