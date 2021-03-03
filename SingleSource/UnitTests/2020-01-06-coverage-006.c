#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#pragma pack(1)

struct s {
  int : 28;
  unsigned : 17;
  unsigned a : 25;
} b;

volatile int32_t c;
int32_t x;

void d() {
  if (8 < b.a)
    x = c;
}

int main() {
  int32_t val_3;
  int32_t val_2;
  uint32_t val_1;

  val_1 = 2097152;
  val_2 = 0;
  val_3 = 0;

  x = val_3;
  c = val_2;
  b.a = val_1;
  d();

  printf("b.a = %u\n", b.a);
  printf("c = %" PRIi32 "\n", c);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
