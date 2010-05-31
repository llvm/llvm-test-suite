# SingleSource/UnitTests/ObjC/Makefile
LEVEL = ../../..
include $(LEVEL)/Makefile.config

DISABLE_JIT := 1
DIRS :=

LDFLAGS += -lobjc -framework Foundation
PROGRAM_REQUIRED_TO_EXIT_OK := 1

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = exceptions print-class-info
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
