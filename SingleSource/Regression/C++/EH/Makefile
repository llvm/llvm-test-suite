LEVEL = ../../../..
REQUIRES_EH_SUPPORT = 1

# Temporarily skip inlined_cleanup on ARM/Darwin.  Radar 8411222
include $(LEVEL)/Makefile.config
ifeq ($(ARCH),ARM)
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := inlined_cleanup
endif
endif

CFLAGS += -std=c99
LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
