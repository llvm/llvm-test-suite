# MultiSource/UnitTests Makefile:  Build all subdirectories automatically

LEVEL = ../..

PARALLEL_DIRS =

# Add special tests for Mips
ifeq ($(ARCH),Mips)
PARALLEL_DIRS += Mips
endif

include $(LEVEL)/Makefile.config
include $(LEVEL)/Makefile.programs
