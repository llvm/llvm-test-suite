LEVEL = ../../../../..
PROG     = sgefa
LDFLAGS  = -lm

ifdef LARGE_PROBLEM_SIZE
CPPFLAGS = -DSCALE=50
else
CPPFLAGS = -DSCALE=30
endif

# This program is adversely effected by the underlying precision of the machine
PROGRAM_IS_NONDETERMINISTIC = 1

include	../../Makefile.multisrc
