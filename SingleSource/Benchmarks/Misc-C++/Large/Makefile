LEVEL = ../../../..
LDFLAGS += -lm -lstdc++
LIBS = -lstdc++
FP_ABSTOLERANCE := 0.01
HASH_PROGRAM_OUTPUT := 1

ifeq ($(ARCH),XCore)
# XCore diffs output on 3 of the 65536 numbers
PROGRAMS_TO_SKIP := sphereflake
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
