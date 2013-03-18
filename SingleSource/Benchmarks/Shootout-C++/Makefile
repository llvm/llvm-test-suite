LEVEL = ../../..
CXXFLAGS += -Wno-deprecated
CPPFLAGS += -Wno-deprecated
FP_TOLERANCE := 0.00000001

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
