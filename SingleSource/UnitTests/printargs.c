
int puts(const char *);

void main(int argc, char **argv) {
	int i;
	for (i = 1; i < argc; ++i)
		puts(argv[i]);
}
