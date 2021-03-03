#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t a, b;

union u {
  uint16_t c;
} d;

static int32_t *e = &b;
int64_t *f;
static int64_t **g = &f;
int64_t x;

int64_t h(int32_t i) {
  {
    x = i && (2036854775807 / a) && i;
    return x;
  };
}

void j() {
  for (; d.c; ++d.c)
    *e = h(**g);
}

int32_t h_call_argument_1;
int64_t y;

int main() {
  int64_t val_7;
  int32_t val_6;
  int64_t val_5;
  int64_t val_4;
  int64_t temp_1;
  uint16_t val_3;
  int32_t val_2;
  int32_t val_1;

  val_1 = 251;
  val_2 = -2113601536;
  val_3 = 12027;
  val_4 = 0;
  val_5 = 70651297207679744;
  val_6 = -7;
  val_7 = 2089739496336261183;
  temp_1 = val_4;

  y = val_7;
  h_call_argument_1 = val_6;
  x = val_5;
  f = &temp_1;
  d.c = val_3;
  b = val_2;
  a = val_1;
  j();
  y = h(h_call_argument_1);

  printf("a = %" PRIi32 "\n", a);
  printf("b = %" PRIi32 "\n", b);
  printf("d.c = %" PRIu16 "\n", d.c);
  printf("y = %" PRIi64 "\n", y);
  printf("h_call_argument_1 = %" PRIi32 "\n", h_call_argument_1);
  printf("x = %" PRIi64 "\n", x);

  return 0;
}
