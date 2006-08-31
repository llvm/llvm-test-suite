##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 gcc test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

ifeq ($(OS),Darwin)
  CPPFLAGS += -DSPEC_CPU_MACOSX
endif

ifeq ($(ENDIAN),big)
  CPPFLAGS += -DHOST_WORDS_BIG_ENDIAN
endif

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS = cccp.i -o cccp.s
else
  RUN_OPTIONS = integrate.i -o integrate.s
endif
