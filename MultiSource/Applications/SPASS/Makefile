LEVEL = ../../..
PROG = SPASS

CPPFLAGS = -DCLOCK_NO_TIMING -fno-strict-aliasing -w
LDFLAGS  = -lm

ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS="$(PROJ_SRC_DIR)/small_problem.dfg"
else
RUN_OPTIONS="$(PROJ_SRC_DIR)/problem.dfg"
endif

HASH_PROGRAM_OUTPUT = 1

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = SPASS
endif
endif

include ../../Makefile.multisrc
