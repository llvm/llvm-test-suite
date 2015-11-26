unsigned long window_size = 0x10000;

unsigned test() {
	return (unsigned)window_size;
}

extern int printf(const char *str, ...);

int main() {
	printf("%d\n", test());
	return 0;
}
