#include <stdint.h>
#include <stdlib.h>

#define GENPOLY -24575

static uint16_t CRCTable[256];

static void crc_init(void) {
  uint16_t crc = 1;
  for (unsigned int i = 128; i; i >>= 1) {
    crc = (crc >> 1) ^ (crc & 1 ? GENPOLY : 0);
    for (unsigned int j = 0; j < 256; j += 2 * i)
      CRCTable[i + j] = crc ^ CRCTable[j];
  }
}

// This table-lookup should be equivalent to the code emitted when optimizing
// CRC with HashRecognize. This function itself will be untouched by
// HashRecognize.
static uint16_t crc_table(uint16_t crc_initval) {
  uint16_t crc = crc_initval;

  if (CRCTable[255] == 0)
    crc_init();

  for (size_t i = 0; i < 2; ++i) {
    uint16_t pos = crc & 0xFF;
    crc = (crc >> 8) ^ CRCTable[pos];
  }

  return crc;
}

static uint16_t crc_loop(uint16_t crc_initval) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 16; ++i) {
    uint16_t crc_lshr = crc >> 1;
    crc = (crc & 1) ? (crc_lshr ^ GENPOLY) : crc_lshr;
  }
  return crc;
}

int main() {
  // These are random hand-picked values.
  static const uint16_t crc_initval[8] = {0, 1, 11, 16, 129, 255, 4129, 16384};
  for (size_t i = 0; i < 8; ++i) {
    uint16_t actual = crc_loop(crc_initval[i]);
    uint16_t expected = crc_table(crc_initval[i]);
    if (actual != expected)
      return 1;
  }
  return 0;
}
