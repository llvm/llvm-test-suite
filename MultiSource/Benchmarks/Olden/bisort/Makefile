LEVEL = ../../../../../..

PROG     = bisort
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm

ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 7000000
else
RUN_OPTIONS = 700000
endif
include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc

