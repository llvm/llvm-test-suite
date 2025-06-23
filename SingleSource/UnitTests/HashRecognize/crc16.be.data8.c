#include <stdint.h>
#include <stdlib.h>

#define GENPOLY 4129

static uint16_t CRCTable[256];

static void crc_init(void) {
  uint16_t crc = 0x8000;
  for (unsigned int i = 1; i < 256; i <<= 1) {
    crc = (crc << 1) ^ (crc & 0x8000 ? GENPOLY : 0);
    for (unsigned int j = 0; j < i; j++)
      CRCTable[i + j] = crc ^ CRCTable[j];
  }
}

// This table-lookup should be equivalent to the code emitted when optimizing
// CRC with HashRecognize. This function itself will be untouched by
// HashRecognize.
static uint16_t crc_table(uint16_t crc_initval, uint8_t data) {
  uint16_t crc = crc_initval;

  if (CRCTable[255] == 0)
    crc_init();

  for (size_t i = 0; i < 1; ++i) {
    uint8_t pos = (crc ^ (data << (i << 3))) >> 8;
    crc = (crc << 8) ^ CRCTable[pos];
  }

  return crc;
}

static uint16_t crc_loop(uint16_t crc_initval, uint8_t data) {
  uint16_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 8; ++i) {
    uint16_t xor_crc_data = crc ^ data;
    uint16_t crc_shl = crc << 1;
    crc = (xor_crc_data & 0x8000) ? (crc_shl ^ GENPOLY) : crc_shl;
    data <<= 1;
  }
  return crc;
}

int main() {
  // These are random hand-picked values.
  static const uint16_t crc_initval[8] = {0, 129, 11, 255, 16, 4129, 16384, 1};
  static const uint8_t data[8] = {0, 1, 11, 16, 129, 255, 142, 255};
  for (size_t i = 0; i < 8; ++i) {
    uint16_t actual = crc_loop(crc_initval[i], data[i]);
    uint16_t expected = crc_table(crc_initval[i], data[i]);
    if (actual != expected)
      return 1;
  }
  return 0;
}
