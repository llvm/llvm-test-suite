# SingleSource/UnitTests/Vector/Altivec/Makefile
LEVEL = ../../../..

include $(LEVEL)/Makefile.config

DIRS = 

# Needed because of MADDs in stepfft.
FP_TOLERANCE := 0.002

TARGET_FLAGS += -maltivec
# setting TEST_TARGET_FLAGS is needed within the LNT environment.
TEST_TARGET_FLAGS += -maltivec
LCCFLAGS += -maltivec

include $(LEVEL)/SingleSource/Makefile.singlesrc
