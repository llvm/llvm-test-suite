#pragma once

#ifdef __aarch64__
#define ARCH_AARCH64 1
#define AS_ARCH_LEVEL armv8.6-a+crc
#define HAVE_DOTPROD 1
#define HAVE_I8MM 1
#define HAVE_SVE 1
#define HAVE_SVE2 1
#elif defined(__arm__)
#define ARCH_ARM 1
#elif defined(__i386__) && !defined(NO_X86ASM)
#define ARCH_X86 1
#define ARCH_X86_32 1
#elif defined(__x86_64__) && !defined(NO_X86ASM)
#define ARCH_X86 1
#define ARCH_X86_64 1
#endif

#ifndef ARCH_AARCH64
#define ARCH_AARCH64 0
#endif
#ifndef ARCH_ARM
#define ARCH_ARM 0
#endif
#ifndef ARCH_X86
#define ARCH_X86 0
#endif
#ifndef ARCH_X86_32
#define ARCH_X86_32 0
#endif
#ifndef ARCH_X86_64
#define ARCH_X86_64 0
#endif

#define ARCH_LOONGARCH 0

#define ARCH_LOONGARCH32 0

#define ARCH_LOONGARCH64 0

#define ARCH_PPC64LE 0

#define ARCH_RISCV 0

#define ARCH_RV32 0

#define ARCH_RV64 0


#define CONFIG_16BPC 1

#define CONFIG_8BPC 1

#define CONFIG_LOG 1

#define CONFIG_MACOS_KPERF 0

#ifdef __BYTE_ORDER__
# if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#  define ENDIANNESS_BIG 1
# else
#  define ENDIANNESS_BIG 0
# endif
#elif defined(_WIN32)
# define ENDIANNESS_BIG 0
#else
# error Unknown endianness.
#endif

#define HAVE_ALIGNED_ALLOC 0

#ifdef NO_X86ASM
#define HAVE_ASM 0
#else
#define HAVE_ASM 1
#endif

#define HAVE_AS_ARCHEXT_DOTPROD_DIRECTIVE 0

#define HAVE_AS_ARCHEXT_I8MM_DIRECTIVE 0

#define HAVE_AS_ARCHEXT_SVE2_DIRECTIVE 1

#define HAVE_AS_ARCHEXT_SVE_DIRECTIVE 1

#define HAVE_AS_ARCH_DIRECTIVE 1

#define HAVE_AS_FUNC 0

#define HAVE_C11_GENERIC 1

#ifdef __linux__
#define HAVE_CLOCK_GETTIME 1
#else
#define HAVE_CLOCK_GETTIME 0
#endif

#define HAVE_DLSYM 0

#define HAVE_ELF_AUX_INFO 0

#ifdef __linux__
#define HAVE_GETAUXVAL 1
#else
#define HAVE_GETAUXVAL 0
#endif

#ifdef _WIN32
#define HAVE_IO_H 1
#else
#define HAVE_IO_H 0
#endif

#define HAVE_MEMALIGN 0

#ifdef _WIN32
#define HAVE_POSIX_MEMALIGN 0
#else
#define HAVE_POSIX_MEMALIGN 1
#endif

#ifdef __linux__
#define HAVE_PTHREAD_GETAFFINITY_NP 1
#else
#define HAVE_PTHREAD_GETAFFINITY_NP 0
#endif

#define HAVE_PTHREAD_NP_H 0

#ifdef __linux__
#define HAVE_PTHREAD_SETAFFINITY_NP 1
#else
#define HAVE_PTHREAD_SETAFFINITY_NP 0
#endif

#define HAVE_PTHREAD_SETNAME_NP 1

#define HAVE_PTHREAD_SET_NAME_NP 0

#define HAVE_SYS_TYPES_H 1

#ifdef _WIN32
#define HAVE_UNISTD_H 0
#else
#define HAVE_UNISTD_H 1
#endif

#if !defined(PIC) && (defined(__PIC__) || defined(__pic__))
#define PIC 3
#endif

#if defined(__APPLE__) || (defined(_WIN32) && defined(__i386__))
#define PREFIX 1
#endif

#define TRIM_DSP_FUNCTIONS 0

#ifdef _WIN32
#define UNICODE 1
#define _CRT_DECLARE_NONSTDC_NAMES 1
#define _FILE_OFFSET_BITS 64
#define _UNICODE 1
#endif

#ifdef _MSC_VER
#define fseeko _fseeki64
#define ftello _ftelli64
#endif
