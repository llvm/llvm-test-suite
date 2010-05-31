LEVEL = ../../../

PROG = paq8p
CPPFLAGS += -DNOASM -DLLVM
LDFLAGS = -lstdc++ -lm
ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = -1 file1.in
else
RUN_OPTIONS = -4 file1.in
endif

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = PAQ8p
endif
endif

include $(LEVEL)/MultiSource/Makefile.multisrc
