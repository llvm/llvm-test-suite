#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 0x4002

static NOINLINE uint16_t crc_loop(uint16_t crc_initval, uint8_t data) {
  uint16_t crc = crc_initval;

  // This alternate spelling applies the polynomial and carry updates separately.
  // Keeping their conditions distinct allows InstCombine to canonicalize the bit
  // test to 'trunc x16 to i1' before folding the updates into a single select,
  // which HashRecognize must recognize.
  for (uint8_t i = 0; i < 8; ++i) {
    uint8_t x16 = (data & 1) ^ (crc & 1);
    data >>= 1;
    crc = (x16 == 1) ? (crc ^ GENPOLY) : crc;
    crc >>= 1;
    uint8_t carry = x16 == 1; // separate carry needed to force 'trunc to i1' canonicalization.
    if (carry)
      crc |= 0x8000;
  }
  return crc;
}

int main() {
  PRINT_RESULTS(crc_loop);
  return 0;
}
