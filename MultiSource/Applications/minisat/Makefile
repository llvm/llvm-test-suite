# MultiSource/minisat Makefile

LEVEL = ../../..
PROG = minisat
CPPFLAGS = -D NDEBUG
LDFLAGS = -lz -lm
ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = -verbosity=0 $(PROJ_SRC_DIR)/small.cnf.gz
else
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -verbosity=0 $(PROJ_SRC_DIR)/long.cnf.gz
else
RUN_OPTIONS = -verbosity=0 $(PROJ_SRC_DIR)/short.cnf.gz
endif
endif
FP_TOLERANCE = 0.1

include ../../Makefile.multisrc

ifeq ($(OS),Darwin)
SHLIBEXT := .dylib
endif

JIT_OPTS += -load libz$(SHLIBEXT)
