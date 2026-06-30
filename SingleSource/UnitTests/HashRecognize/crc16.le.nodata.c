#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY -24575

// sample consists of random hand-picked values.
static const unsigned sample[] = {0, 1, 11, 16, 129, 142, 196, 255};

static NOINLINE uint16_t crc_loop(uint16_t crc_initval) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 16; ++i) {
    uint16_t crc_lshr = crc >> 1;
    crc = (crc & 1) ? (crc_lshr ^ GENPOLY) : crc_lshr;
  }
  return crc;
}

int main() {
  PRINT_RESULTS_NODATA(crc_loop, sample);
  return 0;
}
