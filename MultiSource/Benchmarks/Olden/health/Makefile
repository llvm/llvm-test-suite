LEVEL = ../../../..

PROG     = health
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm

FP_TOLERANCE = 0.001

ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 10 40 1
else
RUN_OPTIONS = 9 20 1
endif
include $(LEVEL)/MultiSource/Makefile.multisrc

