##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 libquantum test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

ifeq ($(OS),Darwin)
  CPPFLAGS += -DSPEC_CPU_MACOSX
endif

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := 33 5
  STDOUT_FILENAME := test.out
else
  RUN_OPTIONS     := 143 25
  STDOUT_FILENAME := train.out
endif
