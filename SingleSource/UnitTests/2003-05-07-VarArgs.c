#include <stdio.h>
#include <stdarg.h>

void test(char *fmt, ...) {
  va_list ap;
  int d;
  char c, *p, *s;

  va_start(ap, fmt);
  while (*fmt)
    switch(*fmt++) {
    case 's':           /* string */
      s = va_arg(ap, char *);
      printf("string %s\n", s);
      break;
    case 'd':           /* int */
      d = va_arg(ap, int);
      printf("int %d\n", d);
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
  test("ssdcd", "abc", "def", -123, 'a', 123);
  return 0;
}
