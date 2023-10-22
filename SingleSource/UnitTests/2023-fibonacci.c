int fib(int n) {
	int a = 0;
	int b = 1;
	int c = 1;
	while (n != 0) {
		int tmp = c;
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
		while (1) {}
	}
}
