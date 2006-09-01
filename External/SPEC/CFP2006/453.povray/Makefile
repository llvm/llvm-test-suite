##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 povray test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

include ../../Makefile.spec2006

ifeq ($(RUN_TYPE),test)
  FP_TOLERANCE     = 0.0002
  RUN_OPTIONS     := SPEC-benchmark-test
  STDOUT_FILENAME := test.out
else
  FP_TOLERANCE     = 0.00005
  RUN_OPTIONS     := SPEC-benchmark-train
  STDOUT_FILENAME := train.out
endif

LDFLAGS = -lstdc++ -lm
LIBS    = -lstdc++ -lm
