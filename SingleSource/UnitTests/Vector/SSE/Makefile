# SingleSource/UnitTests/Vector/SSE/Makefile

DIRS = 
LEVEL = ../../../..
FP_TOLERANCE := 0.016

### FIXME: We have disabled CBE here because it doesn't grok the vector
### FIXME: instructions yet. 
DISABLE_CBE := 1
include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -msse2
LCCFLAGS += -msse2
