##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 calculix test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_TOLERANCE    = 5e-2
FP_ABSTOLERANCE = 1.0e-2

include ../../Makefile.spec2006
include $(PROJ_SRC_ROOT)/Makefile.FORTRAN

CPPFLAGS += -I$(SPEC_BENCH_DIR)/src/SPOOLES

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS     := -i beampic
  STDOUT_FILENAME := beampic.log
else
  RUN_OPTIONS     := -i stairs
  STDOUT_FILENAME := stairs.log
endif
