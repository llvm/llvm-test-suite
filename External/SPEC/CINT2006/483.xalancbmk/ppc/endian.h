// Workaround for the benchmark trying to include <ppc/endian.h> on OS X.
// This file is not available anymore for some time, anyway we just need the 3
// endian defines.
#define __BYTE_ORDER__ __BYTE_ORDER
#define __ORDER_LITTLE_ENDIAN__ __LITTLE_ENDIAN
#define __ORDER_BIT_ENDIAN__ __BIG_ENDIAN
