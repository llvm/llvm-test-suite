##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 dealII test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

FP_ABSTOLERANCE = 0.0000001

CPPFLAGS += \
        -Ddeal_II_dimension=3     \
        -DBOOST_DISABLE_THREADS   \
        -I$(SPEC_BENCH_DIR)/src/include

include ../../Makefile.spec2006

ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS := 8
else
  RUN_OPTIONS := 10
endif

STDOUT_FILENAME := log

LDFLAGS = -lstdc++ -lm
LIBS    = -lm
