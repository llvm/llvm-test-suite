LEVEL = ../../../..

PROG     = CrystalMk
 
LIBS += -lm
LDFLAGS += -lm

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
endif
endif

include	../../../Makefile.multisrc
