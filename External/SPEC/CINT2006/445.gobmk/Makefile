##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 gobmk test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

CPPFLAGS += -DHAVE_CONFIG_H

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := --quiet --mode gtp capture.tst
  STDOUT_FILENAME := capture.out
else
  RUN_OPTIONS     := --quiet --mode gtp arb.tst
  STDOUT_FILENAME := arb.out
endif
