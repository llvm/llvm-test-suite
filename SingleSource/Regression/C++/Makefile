#                   SingleSource/Regression/C++
#
# This directory contains regression tests for the GCC C++ front-end for LLVM.  
# These tests are C++ source files that are input to GCC and compiled to .ll
# files. After that, the files are assembled and executed by the LLVM backends.
#
LEVEL = ../../..

# Exception Handling support in ARM still flaky
# Re-enable this when support gets better
ifeq ($(ARCH), ARM)
  # Darwin uses SjLj, others are either nothing or EHABI
  # See ARMMCAsmInfo.cpp
  ifeq ($(TARGET_OS), Darwin)
    DIRS=EH
  endif
else
  DIRS=EH
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
