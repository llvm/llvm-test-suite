#include <stdint.h>
#include <stdio.h>

struct a {
  int64_t b;
  int64_t c;
} d;

int64_t e;

void f(struct a *g) { d = *g; }

struct a s;

int main() {
  int64_t val_5;
  int64_t val_4;
  int64_t val_3;
  int64_t val_2;
  int64_t val_1;

  val_1 = -7988785259004943837;
  val_2 = -7;
  val_3 = -7;
  val_4 = -7988785259004943837;
  val_5 = -6;

  s.b = val_4;
  s.c = val_5;
  e = val_3;
  d.b = val_1;
  d.c = val_2;
  struct a h = {0, 9};
  s = h;
  e = h.c;
  f(&h);

  printf("d.b = %li\n", d.b);
  printf("d.c = %li\n", d.c);
  printf("s.b = %li\n", s.b);
  printf("s.c = %li\n", s.c);
  printf("e = %li\n", e);

  return 0;
}
