LEVEL = ../../..
LDFLAGS += -lm -lstdc++

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
XCORE_TARGET_NEEDS_MEMORY := 128
# XCore takes ~1.25 hour.
RUNTIMELIMIT:=7200
endif
endif

ifeq ($(ARCH),Mips)
# Mips takes ~20 minutes.
RUNTIMELIMIT:=1200
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc

