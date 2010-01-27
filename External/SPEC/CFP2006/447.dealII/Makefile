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

STDOUT_FILENAME := log

LDFLAGS = -lstdc++ -lm
LIBS    = -lm

include ../../Makefile.spec2006

# For SMALL_PROBLEM_SIZE, we want even fewer cycles. Some targets (ARM Thumb1,
# for example), take a very long time.
ifdef SMALL_PROBLEM_SIZE
  RUN_OPTIONS = 3
else
ifeq ($(RUN_TYPE),test)
  RUN_OPTIONS = 8
else
  RUN_OPTIONS = 10
endif
endif
