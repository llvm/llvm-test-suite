# SingleSource/UnitTests/Vector/SSE/Makefile

DIRS = 
LEVEL = ../../../..
FP_TOLERANCE := 0.016
CPPFLAGS   += -ffp-contract=off -DFMA_DISABLED=1

LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -msse2
LCCFLAGS += -msse2
