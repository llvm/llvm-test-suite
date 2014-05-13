LEVEL = ../../../..

PROG     = tsp
CPPFLAGS = -DTORONTO
LDFLAGS  = -lm
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = 2048000
else
ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = 102400
else
RUN_OPTIONS = 1024000
ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 64
endif
endif
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

