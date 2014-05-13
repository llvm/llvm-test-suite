LEVEL = ../../..
LDFLAGS += -lm -lstdc++
FP_TOLERANCE := 0.001

ifeq ($(ARCH),XCore)
# XCore takes over 2 hours
RUNTIMELIMIT:=10800
else
# This test can take more than the default 500s timeout at -O0.
RUNTIMELIMIT:=1200
endif

include $(LEVEL)/Makefile.config

include $(LEVEL)/SingleSource/Makefile.singlesrc
