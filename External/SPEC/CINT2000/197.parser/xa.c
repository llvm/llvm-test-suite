
#include <stdlib.h>

int max_space_in_use = 0;
int space_in_use = 0;

void initialize_memory() {
}

void * xalloc(int size) {
  return malloc(size);
}

void xfree(void *P, int size) {
  free(P);
}
