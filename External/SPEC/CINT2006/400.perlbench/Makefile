##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 400.perlbench
# test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

CPPFLAGS += -DPERL_CORE

ifeq ($(OS),Darwin)
ifeq ($(ARCH),PowerPC)
  CPPFLAGS += -DSPEC_CPU_MACOSX_PPC
else
ifeq ($(ARCH),x86)
  CPPFLAGS += -DSPEC_CPU_MACOSX_IA32
endif
endif
endif

ifeq ($(ENDIAN),little)
  CPPFLAGS += -D__LITTLE_ENDIAN__
else
  CPPFLAGS += -D__BIG_ENDIAN__
endif

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS      = test.pl
  STDOUT_FILENAME := test.out
else
  RUN_OPTIONS      = scrabbl.pl
  STDIN_FILENAME  := scrabbl.in
  STDOUT_FILENAME := scrabbl.out
endif
