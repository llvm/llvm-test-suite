##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 gcc test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include $(LEVEL)/Makefile.config

CPPFLAGS += -DINLINE=__inline__

ifeq ($(TARGET_OS),Darwin)
  CPPFLAGS += -DSPEC_CPU_MACOSX
endif

ifeq ($(ENDIAN),big)
  CPPFLAGS += -DHOST_WORDS_BIG_ENDIAN
endif

HASH_PROGRAM_OUTPUT = 1

include ../../Makefile.spec2006

ifeq ($(RUN_TYPE),test)
ifeq ($(SPEC_VERSION),1.2)
  RUN_OPTIONS      = cccp.in -o -
else
  RUN_OPTIONS      = cccp.i -o -
endif
  STDOUT_FILENAME := cccp.s
else
ifeq ($(SPEC_VERSION),1.2)
  RUN_OPTIONS      = integrate.in -o -
else
  RUN_OPTIONS      = integrate.i -o -
endif
  STDOUT_FILENAME := integrate.s
endif

ifeq ($(TARGET_OS),Darwin)
  LDFLAGS += -Xlinker -stack_size -Xlinker 0x800000
endif
