LEVEL = ../../../..
LDFLAGS += -lm -lstdc++
LIBS = -lstdc++
FP_ABSTOLERANCE := 0.01
HASH_PROGRAM_OUTPUT := 1

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = sphereflake
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
