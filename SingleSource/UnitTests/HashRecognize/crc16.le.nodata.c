#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY -24575

static NOINLINE uint16_t crc_loop(uint16_t crc_initval, unsigned data) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 16; ++i) {
    uint16_t crc_lshr = crc >> 1;
    crc = (crc & 1) ? (crc_lshr ^ GENPOLY) : crc_lshr;
  }
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
