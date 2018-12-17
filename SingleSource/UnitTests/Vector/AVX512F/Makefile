# SingleSource/UnitTests/Vector/AVX512F/Makefile

DIRS = 
LEVEL = ../../../..
CFLAGS += -fms-extensions -march=native -mavx512f -I${SourceDir}/..
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -march=native -mavx512f
LCCFLAGS += -march=native -mavx512f
