LEVEL = ../../..
DIRS := Large
LDFLAGS += -lm -lstdc++
LIBS = -lstdc++
FP_ABSTOLERANCE := 0.01

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
XCORE_TARGET_NEEDS_MEMORY := 128
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
