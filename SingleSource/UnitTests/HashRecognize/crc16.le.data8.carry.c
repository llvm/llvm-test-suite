#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 0x4002

static NOINLINE uint16_t crc_loop(uint16_t crc_initval, uint8_t data) {
  uint16_t crc = crc_initval;

  // This carry-based loop will be optimized by HashRecognize.
  for (uint8_t i = 0; i < 8; ++i) {
    uint8_t x16 = (uint8_t)((data & 1) ^ ((uint8_t)crc & 1));
    data >>= 1;
    uint8_t carry = (x16 == 1) ? 1 : 0;
    crc = (x16 == 1) ? (crc ^ GENPOLY) : crc;
    crc >>= 1;
    if (carry)
      crc |= 0x8000;
  }
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
