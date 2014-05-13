LEVEL = ../../..
CXXFLAGS += -Wno-deprecated
CPPFLAGS += -Wno-deprecated
FP_TOLERANCE := 0.00000001

DIRS=EH

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
XCORE_TARGET_NEEDS_MEMORY := 256
# XCore takes over 2 hour.
RUNTIMELIMIT:=10800
endif
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
