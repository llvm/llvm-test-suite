
#include <stdio.h>

void test(int A, int B, int C, int D) {
	printf("%d %d %d %d\n", ~A, ~B, ~C, ~D);
}

void main() {
	test(1, 2, -3, 5);
}
