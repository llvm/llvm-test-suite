##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 tonto test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_TOLERANCE = 0.006

include ../../Makefile.spec2006
include $(PROJ_SRC_ROOT)/Makefile.FORTRAN

FPPFLAGS += -w -DUSE_PRE_AND_POST_CONDITIONS -DUSE_ERROR_MANAGEMENT \
            -m literal.pm -m tonto.pm

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := stdin
  STDOUT_FILENAME := test.out
else
  RUN_OPTIONS     := stdin
  STDOUT_FILENAME := train.out
endif
