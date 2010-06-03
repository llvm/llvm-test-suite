# SingleSource/UnitTests/ObjC/Makefile
LEVEL = ../../..
include $(LEVEL)/Makefile.config

DISABLE_JIT := 1
DIRS :=

LDFLAGS += -lobjc -framework Foundation
PROGRAM_REQUIRED_TO_EXIT_OK := 1

ifneq ($(ARCH),x86)
PROGRAMS_TO_SKIP += print-class-info-x86-32
endif
ifneq ($(ARCH),x86_64)
PROGRAMS_TO_SKIP += print-class-info-x86-64
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
