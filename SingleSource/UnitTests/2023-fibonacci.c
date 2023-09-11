#include <stdint.h>

uint32_t fib(uint32_t n) {
	uint32_t a = 0;
	uint32_t b = 1;
	uint32_t c = 1;
	while (n != 0) {
		uint32_t tmp = c;
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main () {
	if (fib(5) == 8)  {
		return 0;
	} else {
		return 0/0;
	}
}
