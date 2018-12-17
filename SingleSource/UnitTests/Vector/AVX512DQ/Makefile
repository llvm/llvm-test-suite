# SingleSource/UnitTests/Vector/AVX512DQ/Makefile

DIRS = 
LEVEL = ../../../..
CFLAGS += -fms-extensions -march=native -mavx512dq -I${SourceDir}/..
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -march=native -mavx512dq
LCCFLAGS += -march=native -mavx512dq
