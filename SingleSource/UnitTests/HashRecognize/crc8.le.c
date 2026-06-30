#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 0x1D

// sample consists of random hand-picked values.
static const unsigned sample[] = {0, 1, 11, 16, 129, 142, 196, 255};

static NOINLINE uint8_t crc_loop(uint8_t crc_initval, uint8_t data) {
  uint8_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  CRCLOOP_LE(uint8_t, GENPOLY, crc, data);
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop, sample);
  return 0;
}
