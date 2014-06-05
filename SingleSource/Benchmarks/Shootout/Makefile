LEVEL = ../../..
LDFLAGS += -lm

ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 256
endif

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += hello
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
