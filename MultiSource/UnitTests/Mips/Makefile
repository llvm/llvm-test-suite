# MultiSource/UnitTests/Mips Makefile:  Build all subdirectories automatically

LEVEL = ../../..

PARALLEL_DIRS :=

# Add special tests for Mips
ifneq (,$(findstring mips16,$(MIPSARCH)))
PARALLEL_DIRS += Mips16
endif

include $(LEVEL)/Makefile.config
include $(LEVEL)/Makefile.programs
