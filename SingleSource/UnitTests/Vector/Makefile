# SingleSource/UnitTests/Vector/Makefile
LEVEL = ../../..

include $(LEVEL)/Makefile.config

DIRS = 

ifeq ($(ARCH),PowerPC)
DIRS += Altivec
endif

ifeq ($(ARCH),x86)
DIRS += SSE
endif
ifeq ($(ARCH),$(filter $(ARCH),x86_64 x86_64h))
DIRS += SSE
endif

ifeq ($(CC_UNDER_TEST_IS_CLANG), 1)

ifeq ($(HAVE_X86_AVX512F_INSTRUCTIONS), 1)
DIRS += AVX512F
endif

ifeq ($(HAVE_X86_AVX512VL_INSTRUCTIONS), 1)
DIRS += AVX512VL
ifeq ($(HAVE_X86_AVX512BW_INSTRUCTIONS), 1)
DIRS += AVX512BWVL
endif
ifeq ($(HAVE_X86_AVX512DQ_INSTRUCTIONS), 1)
DIRS += AVX512DQVL
endif
endif

ifeq ($(HAVE_X86_AVX512BW_INSTRUCTIONS), 1)
DIRS += AVX512BW
endif

ifeq ($(HAVE_X86_AVX512DQ_INSTRUCTIONS), 1)
DIRS += AVX512DQ
endif
endif

# Assume ARMv7 implies NEON.
ifneq ($(CC_UNDER_TEST_TARGET_IS_THUMBV7),)
DIRS += NEON
endif

ifeq ($(ARCH),AArch64)
DIRS += NEON AArch64
endif

ifndef CC_UNDER_TEST_IS_CLANG
# constpool uses clang-only syntax.
PROGRAMS_TO_SKIP := constpool
endif

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc


