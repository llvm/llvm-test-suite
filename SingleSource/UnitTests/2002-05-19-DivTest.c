extern int printf(const char *, ...);

void test(int Arg) {
   printf("%d\n", Arg / 2);
}

int main() {
	test(-21);
	test(-22);
	return 0;
}
