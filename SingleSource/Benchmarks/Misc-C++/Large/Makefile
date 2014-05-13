LEVEL = ../../../..
LDFLAGS += -lm -lstdc++
LIBS = -lstdc++
FP_ABSTOLERANCE := 0.01
HASH_PROGRAM_OUTPUT := 1

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
