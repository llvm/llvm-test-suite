# SingleSource/UnitTests/Vector/AVX512BWVL/Makefile

DIRS = 
LEVEL = ../../../..
CFLAGS += -fms-extensions -march=native -mavx512bw -mavx512vl -I${SourceDir}/..
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -march=native -mavx512bw -mavx512vl
LCCFLAGS += -march=native -mavx512bw -mavx512vl
