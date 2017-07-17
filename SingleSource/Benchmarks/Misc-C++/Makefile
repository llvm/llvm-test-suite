LEVEL = ../../..
DIRS := Large
LDFLAGS += -lm -lstdc++
LIBS = -lstdc++
FP_ABSTOLERANCE := 0.01

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
XCORE_TARGET_NEEDS_MEMORY := 128
endif
else
ifeq ($(ARCH),AArch64)
# On AArch64 at -O0 we get very close to 500s and sometimes we go over the
# threshold. Set it to a more comfortable value.
RUNTIMELIMIT := 750
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
