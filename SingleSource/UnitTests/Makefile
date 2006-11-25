# SingleSource/UnitTests/Makefile
LEVEL = ../..
include $(LEVEL)/Makefile.config

DIRS := SetjmpLongjmp

# llvm-gcc3 does not support any vector tests.
ifneq ($(LLVMGCC_MAJVERS),3)

# FIXME: Disable SJLJ tests for now, until EH edges are represented.
DIRS :=

DIRS += Vector
endif

PROGRAM_REQUIRED_TO_EXIT_OK := 1
include $(LEVEL)/SingleSource/Makefile.singlesrc
