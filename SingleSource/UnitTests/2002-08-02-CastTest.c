#include <stdio.h>

unsigned test(unsigned X) {
  return (unsigned char)X;
}

void main() {
	printf("%d\n", test(123456));
}

