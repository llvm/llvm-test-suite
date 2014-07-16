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

# Assume ARMv7 implies NEON.
ifneq ($(CC_UNDER_TEST_TARGET_IS_THUMBV7),)
DIRS += NEON
endif

ifeq ($(ARCH),AArch64)
DIRS += NEON
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

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += build divides sumarray sumarray-dbl
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc


