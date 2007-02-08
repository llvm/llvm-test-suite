# MultiSource/minisat Makefile

LEVEL = ../../..
PROG = minisat
CPPFLAGS = -D NDEBUG
LDFLAGS = -lz
RUN_OPTIONS = -verbosity=0 short.cnf.gz
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -verbosity=0 long.cnf.gz
endif

include ../../Makefile.multisrc

JIT_OPTS += -load libz.dylib

