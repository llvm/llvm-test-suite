LEVEL = ../../..
LDFLAGS += -lm -lstdc++
FP_TOLERANCE := 0.001

include $(LEVEL)/Makefile.config

include $(LEVEL)/SingleSource/Makefile.singlesrc

# This test can take more than the default 500s timeout at -O0.
RUNTIMELIMIT:=1200
