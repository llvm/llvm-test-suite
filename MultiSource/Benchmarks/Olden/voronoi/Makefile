LEVEL = ../../../..

PROG     = voronoi
INCLUDES = defines.h
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm
FP_TOLERANCE = 0.0001
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 1000000 20 32 7
else
RUN_OPTIONS = 100000 20 32 7
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

