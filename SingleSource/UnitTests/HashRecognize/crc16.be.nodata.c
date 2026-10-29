#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 4129

static NOINLINE uint16_t crc_loop(uint16_t crc_initval, unsigned data) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 16; ++i) {
    uint16_t crc_shl = crc << 1;
    crc = (crc & 0x8000) ? (crc_shl ^ GENPOLY) : crc_shl;
  }
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
