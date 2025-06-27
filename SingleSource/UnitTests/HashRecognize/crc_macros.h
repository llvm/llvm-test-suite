#include <stdlib.h>

#define BW(ty) (sizeof(ty) * 8)
#define SMIN(ty) (1 << (BW(ty) - 1))

#define CRCINIT_LE(ty, CRCTable, genpoly)                                      \
  {                                                                            \
    ty crc = 1;                                                                \
    for (size_t i = 128; i; i >>= 1) {                                         \
      crc = (crc >> 1) ^ (crc & 1 ? genpoly : 0);                              \
      for (size_t j = 0; j < 256; j += 2 * i)                                  \
        CRCTable[i + j] = crc ^ CRCTable[j];                                   \
    }                                                                          \
  }

#define CRCTABLE_LE(ty, CRCTable, crc_init_fn, crc, data)                      \
  {                                                                            \
    if (CRCTable[255] == 0)                                                    \
      crc_init_fn();                                                           \
    for (size_t i = 0; i < sizeof(data); ++i) {                                \
      uint8_t pos = crc ^ (data >> (i << 3));                                  \
      crc = (BW(ty) == 8 ? 0 : (crc >> 8)) ^ CRCTable[pos];                    \
    }                                                                          \
  }

#define CRCLOOP_LE(ty, genpoly, crc, data)                                     \
  {                                                                            \
    for (size_t i = 0; i < BW(data); ++i) {                                    \
      ty xor_crc_data = crc ^ data;                                            \
      ty crc_lshr = crc >> 1;                                                  \
      crc = (xor_crc_data & 1) ? (crc_lshr ^ genpoly) : crc_lshr;              \
      data >>= 1;                                                              \
    }                                                                          \
  }

#define CRCINIT_BE(ty, CRCTable, genpoly)                                      \
  {                                                                            \
    ty crc = SMIN(ty);                                                         \
    for (size_t i = 1; i < 256; i <<= 1) {                                     \
      crc = (crc << 1) ^ (crc & SMIN(ty) ? genpoly : 0);                       \
      for (size_t j = 0; j < i; j++)                                           \
        CRCTable[i + j] = crc ^ CRCTable[j];                                   \
    }                                                                          \
  }

#define CRCTABLE_BE(ty, CRCTable, crc_init_fn, crc, data)                      \
  {                                                                            \
    if (CRCTable[255] == 0)                                                    \
      crc_init_fn();                                                           \
    for (size_t i = 0; i < sizeof(data); ++i) {                                \
      uint8_t pos = (crc ^ (data << (i << 3))) >> (BW(ty) - 8);                \
      crc = (BW(ty) == 8 ? 0 : (crc << 8)) ^ CRCTable[pos];                    \
    }                                                                          \
  }

#define CRCLOOP_BE(ty, genpoly, crc, data)                                     \
  {                                                                            \
    for (size_t i = 0; i < BW(data); ++i) {                                    \
      ty xor_crc_data = crc ^ data;                                            \
      ty crc_shl = crc << 1;                                                   \
      crc = (xor_crc_data & SMIN(ty)) ? (crc_shl ^ genpoly) : crc_shl;         \
      data <<= 1;                                                              \
    }                                                                          \
  }

// sample consists of random hand-picked values.
#define VERIFY_RESULT(goldfn, actualfn, res)                                   \
  {                                                                            \
    static const unsigned sample[8] = {0, 1, 11, 16, 129, 142, 196, 255};      \
    for (size_t i = 0; i < 8; ++i) {                                           \
      if (goldfn(sample[i], sample[7 - i]) !=                                  \
          actualfn(sample[i], sample[7 - i]))                                  \
        res = 1;                                                               \
    }                                                                          \
  }
