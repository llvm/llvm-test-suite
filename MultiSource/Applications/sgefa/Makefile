LEVEL = ../../..
PROG     = sgefa
LDFLAGS  = -lm
CFLAGS += -Wno-implicit-int

FP_TOLERANCE = 0.0001
ifdef LARGE_PROBLEM_SIZE
CPPFLAGS = -DSCALE=50
else
CPPFLAGS = -DSCALE=40
endif

include	../../Makefile.multisrc
