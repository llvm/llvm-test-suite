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

DIRS += SignlessTypes Threads

# Only test Obj-C on darwin/x86 for time being.
ifeq ($(ARCH),x86)
ifeq ($(OS),Darwin)
DIRS += ObjC ObjC++
endif
endif

PROGRAM_REQUIRED_TO_EXIT_OK := 1
include $(LEVEL)/SingleSource/Makefile.singlesrc
