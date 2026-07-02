#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 33800

static NOINLINE uint32_t crc_loop(uint32_t crc_initval, uint32_t data) {
  uint32_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  CRCLOOP_LE(uint32_t, GENPOLY, crc, data);
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
