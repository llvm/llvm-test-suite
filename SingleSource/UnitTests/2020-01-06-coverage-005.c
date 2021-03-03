#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t a, c, d;
uint64_t b;
int16_t e;
uint64_t *p;
int16_t *q;
void g();
uint64_t *r;

void h() {
  uint64_t *f = &b;
  r = f;
  *f = 6;
  g();
}

uint64_t *s;
int16_t *t;

void g() {
i : {
  uint64_t *j = &b;
  s = j;
  p = j;
  int16_t *k = &e;
  t = k;
  q = k;
  --*k;
  *j &= c;
}
  for (; d; a = d)
    if (e)
      goto i;
}

int main() {
  int16_t val_10;
  int16_t temp_5;
  int64_t val_9;
  uint64_t temp_4;
  int64_t val_8;
  uint64_t temp_3;
  int16_t val_7;
  int16_t temp_2;
  int64_t val_6;
  uint64_t temp_1;
  int16_t val_5;
  int64_t val_4;
  uint32_t val_3;
  uint32_t val_2;
  uint32_t val_1;

  val_1 = 16777101;
  val_2 = 0xFFFFFFFA;
  val_3 = 0;
  val_4 = 256;
  val_5 = -7;
  val_6 = -9223372032559808512;
  val_7 = 0;
  val_8 = -72318388763361280;
  val_9 = 0;
  val_10 = 0;
  temp_1 = val_6;
  temp_2 = val_7;
  temp_3 = val_8;
  temp_4 = val_9;
  temp_5 = val_10;

  t = &temp_5;
  s = &temp_4;
  r = &temp_3;
  q = &temp_2;
  p = &temp_1;
  e = val_5;
  b = val_4;
  d = val_3;
  c = val_2;
  a = val_1;
  h();
  g();

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu64 "\n", b);
  printf("c = %" PRIu32 "\n", c);
  printf("d = %" PRIu32 "\n", d);
  printf("e = %" PRIi16 "\n", e);

  return 0;
}
