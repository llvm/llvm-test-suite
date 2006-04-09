# SingleSource/UnitTests/Makefile
LEVEL = ../..
include $(LEVEL)/Makefile.config

DIRS := SetjmpLongjmp

# llvm-gcc3 does not support any vector tests.
ifneq ($(LLVMGCC_MAJVERS),3)
DIRS += Vector
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc

