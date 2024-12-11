#ifndef AVUTIL_AVCONFIG_H
#define AVUTIL_AVCONFIG_H
#ifdef __BYTE_ORDER__
# if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#  define AV_HAVE_BIGENDIAN 1
# else
#  define AV_HAVE_BIGENDIAN 0
# endif
#elif defined(_WIN32)
# define AV_HAVE_BIGENDIAN 0
#else
# error Unknown endianness.
#endif
#define AV_HAVE_FAST_UNALIGNED 1
#endif /* AVUTIL_AVCONFIG_H */
