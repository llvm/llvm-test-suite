LEVEL = ../../../../../..

PROG     = tsp
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 2048000
else
RUN_OPTIONS = 1024000
endif

include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc

