##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 GemsFTDT test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_TOLERANCE    = 1e-10
FP_ABSTOLERANCE = 1e-9

include ../../Makefile.spec2006
include $(PROJ_SRC_ROOT)/Makefile.FORTRAN

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := test.in
  STDOUT_FILENAME := test.log
else
  RUN_OPTIONS     := train.in
  STDOUT_FILENAME := train.log
endif
