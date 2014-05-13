LEVEL = ../../../..

PROG     = is
LDFLAGS  = 

ifdef SMALL_PROBLEM_SIZE
CPPFLAGS = -DSMALL_PROBLEM_SIZE
else
ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 512
endif
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

