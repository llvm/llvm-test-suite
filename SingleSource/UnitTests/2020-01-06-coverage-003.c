#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int8_t a;
int32_t x;

void b() { x = (uint64_t)4073709551607 > a || a != 0; }

int main() {
  int32_t val_2;
  int8_t val_1;

  val_1 = -7;
  val_2 = 1695154176;

  x = val_2;
  a = val_1;
  b();

  printf("a = %" PRIi8 "\n", a);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
