# SingleSource/UnitTests/ObjC/Makefile
LEVEL = ../../..
include $(LEVEL)/Makefile.config

DISABLE_JIT := 1
DIRS :=

LDFLAGS += -lobjc -framework Foundation
PROGRAM_REQUIRED_TO_EXIT_OK := 1
include $(LEVEL)/SingleSource/Makefile.singlesrc
