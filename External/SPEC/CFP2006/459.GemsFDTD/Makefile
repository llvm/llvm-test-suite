##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 GemsFTDT test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_TOLERANCE    = 1.0e-9
FP_ABSTOLERANCE = 1.0e-10

include ../../Makefile.spec2006
include $(PROJ_SRC_ROOT)/Makefile.FORTRAN

ifeq ($(RUN_TYPE),test)
  STDOUT_FILENAME := test.log
else
  STDOUT_FILENAME := train.log
endif
