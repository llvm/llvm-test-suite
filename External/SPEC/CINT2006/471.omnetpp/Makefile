##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 omnetpp test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_ABSTOLERANCE = 0.000001
FP_TOLERANCE    = 0.00001

CPPFLAGS += -DNDEBUG=1                            \
            -I$(SPEC_BENCH_DIR)/src/omnet_include \
            -I$(SPEC_BENCH_DIR)/src/libs/envir

include ../../Makefile.spec2006

RUN_OPTIONS = omnetpp.ini

ifeq ($(RUN_TYPE),test)
  STDOUT_FILENAME := test.out
else
  STDOUT_FILENAME := train.out
endif
