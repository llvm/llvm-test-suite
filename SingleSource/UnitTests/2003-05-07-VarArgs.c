#include <stdio.h>
#include <stdarg.h>

void test(char *fmt, ...) {
  va_list ap, aq;
  int d;
  char c, *s;

  va_start(ap, fmt);

  va_copy(aq, ap);    /* test va_copy */
  va_end(aq);

  while (*fmt)
    switch(*fmt++) {
    case 's':           /* string */
      s = va_arg(ap, char *);
      printf("string %s\n", s);
      break;
    case 'i':           /* int */
      d = va_arg(ap, int);
      printf("int %d\n", d);
      break;
    case 'd':
      printf("double %f\n", va_arg(ap, double));
      break;
    case 'l':
      printf("long long %lld\n", va_arg(ap, long long));
      break;
    case 'c':           /* char */
      /* need a cast here since va_arg only
         takes fully promoted types */
      c = (char) va_arg(ap, int);
      printf("char %c\n", c);
      break;
    }
  va_end(ap);
}

int main() {
  test("ssici", "abc", "def", -123, 'a', 123);

  /* test promotion & 64-bit types */
  test("ddil", 1.0, 2.0f, (short)32764, 12345677823423LL);
  return 0;
}
