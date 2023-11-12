# SingleSource/UnitTests/Matrix/AMXINT8/Makefile

DIRS = 
LEVEL = ../../../..
CFLAGS += -fms-extensions -march=native -mamx-int8 -mamx-bf16 -I${SourceDir}/..
LDFLAGS += -lm

include $(LEVEL)/SingleSource/Makefile.singlesrc

TARGET_FLAGS += -march=native -mamx-int8 -mamx-bf16
LCCFLAGS += -march=native -mamx-int8 -mamx-bf16 
