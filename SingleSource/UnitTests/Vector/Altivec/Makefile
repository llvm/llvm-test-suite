# SingleSource/UnitTests/Vector/Altivec/Makefile

DIRS = 
LEVEL = ../../../..
include $(LEVEL)/SingleSource/Makefile.singlesrc

# FIXME: CBE doesn't support vectors: PR1126
DISABLE_CBE=1

TARGET_FLAGS += -maltivec
LCCFLAGS += -maltivec
