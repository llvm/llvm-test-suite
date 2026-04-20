#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <megabytes>\n", argv[0]);
    return 1;
  }

  int mib = atoi(argv[1]);
  size_t bytes = (size_t)mib * 1024 * 1024;
  char *buf = (char *)malloc(bytes);
  if (!buf) {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  /* Touch every byte so the allocation is reflected in RSS.
     Writes through a volatile pointer cannot be optimized away. */
  volatile char *vbuf = (volatile char *)buf;
  for (size_t i = 0; i < bytes; i++)
    vbuf[i] = 1;

  free(buf);
  return 0;
}
