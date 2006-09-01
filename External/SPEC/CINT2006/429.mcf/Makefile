##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 mcf test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

RUN_OPTIONS = inp.in

CPPFLAGS += -DWANT_STDC_PROTO

ifeq ($(RUN_TYPE),test)
  STDOUT_FILENAME := test.out
else
  STDOUT_FILENAME := train.out
endif
