LEVEL = ../../../..

PROG     = automotive-basicmath
LDFLAGS  = -lm
FP_TOLERANCE :=  0.00000000001
HASH_PROGRAM_OUTPUT = 1

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = automative-basicmath
endif
endif

include $(LEVEL)/MultiSource/Makefile.multisrc
