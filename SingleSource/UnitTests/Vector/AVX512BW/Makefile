# SingleSource/UnitTests/Vector/AVX512BW/Makefile

DIRS = 
LEVEL = ../../../..
CFLAGS += -fms-extensions -march=native -mavx512bw -I${SourceDir}/..
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -march=native -mavx512bw
LCCFLAGS += -march=native -mavx512bw
