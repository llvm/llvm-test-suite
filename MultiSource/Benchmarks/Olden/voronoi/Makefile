LEVEL = ../../../../../..

PROG     = voronoi
INCLUDES = defines.h
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 1000000 20 32 7
endif

include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc

