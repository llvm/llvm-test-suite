#include <stdio.h>

int main() {
	int Array[10];
	void *Pointer = &Array[0];
	unsigned i;

	for (i = 0; i < 10; ++i) {
		*((int*)Pointer)++ = 1234;
		printf("0x%d\n", (int)Pointer-(int)&Array[0]);
	}
}
