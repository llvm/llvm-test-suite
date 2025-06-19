#include <stdint.h>
#include <stdlib.h>

#define GENPOLY 33800

static uint32_t CRCTable[256];

static void crc_init(void) {
  uint32_t crc = 0x80000000;
  for (unsigned int i = 1; i < 256; i <<= 1) {
    crc = (crc << 1) ^ (crc & 0x80000000 ? GENPOLY : 0);
    for (unsigned int j = 0; j < i; j++)
      CRCTable[i + j] = crc ^ CRCTable[j];
  }
}

// This table-lookup should be equivalent to the code emitted when optimizing
// CRC with HashRecognize. This function itself will be untouched by
// HashRecognize.
static uint32_t crc_table(uint32_t crc_initval, uint32_t data) {
  uint32_t crc = crc_initval;

  if (CRCTable[255] == 0)
    crc_init();

  for (size_t i = 0; i < 4; ++i) {
    uint8_t pos = (crc ^ (data << (i << 3))) >> 24;
    crc = (crc << 8) ^ CRCTable[pos];
  }

  return crc;
}

static uint32_t crc_loop(uint32_t crc_initval, uint32_t data) {
  uint32_t crc = crc_initval;

  // This loop will be optimized by HashRecognize.
  for (size_t i = 0; i < 32; ++i) {
    uint32_t xor_crc_data = crc ^ data;
    uint32_t crc_shl = crc << 1;
    crc = (xor_crc_data & 0x80000000) ? (crc_shl ^ GENPOLY) : crc_shl;
    data <<= 1;
  }
  return crc;
}

int main() {
  // These are random hand-picked values.
  static const uint32_t crc_initval[8] = {0, 129, 11, 255, 16, 4129, 16384, 1};
  static const uint32_t data[8] = {0, 1, 11, 16, 129, 255, 4129, 16384};
  for (size_t i = 0; i < 8; ++i) {
    uint32_t actual = crc_loop(crc_initval[i], data[i]);
    uint32_t expected = crc_table(crc_initval[i], data[i]);
    if (actual != expected)
      return 1;
  }
  return 0;
}
