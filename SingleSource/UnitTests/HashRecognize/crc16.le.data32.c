#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY -24575

static NOINLINE uint16_t crc_loop(uint16_t crc_initval, uint32_t data) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  CRCLOOP_LE(uint16_t, GENPOLY, crc, data);
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
