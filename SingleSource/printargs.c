#include <stdio.h>

int puts(const char *);

void main(int argc, char **argv) {
	int i;
	printf("#Args = %d. They are:\n", argc-1);
	for (i = 1; i < argc; ++i)
		puts(argv[i]);
}
