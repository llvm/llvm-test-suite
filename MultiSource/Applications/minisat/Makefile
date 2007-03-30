# MultiSource/minisat Makefile

LEVEL = ../../..
PROG = minisat
CPPFLAGS = -D NDEBUG
LDFLAGS = -lz -lm
RUN_OPTIONS = -verbosity=0 $(PROJ_SRC_DIR)/short.cnf.gz
FP_TOLERANCE = 0.1
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -verbosity=0 $(PROJ_SRC_DIR)/long.cnf.gz
endif

include ../../Makefile.multisrc

ifeq ($(OS),Darwin)
SHLIBEXT := .dylib
endif

JIT_OPTS += -load libz$(SHLIBEXT)
