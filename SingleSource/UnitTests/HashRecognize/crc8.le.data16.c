#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 0x1D

static NOINLINE uint8_t crc_loop(uint8_t crc_initval, uint16_t data) {
  uint8_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  CRCLOOP_LE(uint8_t, GENPOLY, crc, data);
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
