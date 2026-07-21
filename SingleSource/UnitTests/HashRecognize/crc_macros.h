#include <stdlib.h>
#include <stdio.h>

#define NOINLINE __attribute__((noinline))

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define BW(ty) (sizeof(ty) * 8)
#define SMIN(ty) (1 << (BW(ty) - 1))

#define CRCLOOP_LE(ty, genpoly, crc, data)                                     \
  {                                                                            \
    for (size_t i = 0; i < BW(data); ++i) {                                    \
      ty xor_crc_data = crc ^ data;                                            \
      ty crc_lshr = crc >> 1;                                                  \
      crc = (xor_crc_data & 1) ? (crc_lshr ^ genpoly) : crc_lshr;              \
      data >>= 1;                                                              \
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
#define PRINT_RESULTS(fn)                                                      \
  {                                                                            \
    static const unsigned sample[] = {0, 1, 11, 16, 129, 142, 196, 255};       \
    for (size_t i = 0; i < LEN(sample); ++i)                                   \
      printf("%u\n", (unsigned)fn(sample[i], sample[LEN(sample) - 1 - i]));    \
  }
