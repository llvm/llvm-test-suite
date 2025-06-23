#include "crc_macros.h"
#include <stdint.h>

#define GENPOLY 0x1D

static uint8_t CRCTable[256];

static void crc_init(void) { CRCINIT_LE(uint8_t, CRCTable, GENPOLY); }

// This table-lookup should be equivalent to the code emitted when optimizing
// CRC with HashRecognize. This function itself will be untouched by
// HashRecognize.
static uint8_t crc_table(uint8_t crc_initval, uint16_t data) {
  uint8_t crc = crc_initval;
  CRCTABLE_LE(uint8_t, CRCTable, crc_init, crc, data);
  return crc;
}

static uint8_t crc_loop(uint8_t crc_initval, uint16_t data) {
  uint8_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  CRCLOOP_LE(uint8_t, GENPOLY, crc, data);
  return crc;
}

int main() {
  int res = 0;
  VERIFY_RESULT(crc_table, crc_loop, res);
  return res;
}
