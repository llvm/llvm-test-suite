LEVEL = ../../..

include $(LEVEL)/Makefile.config

ifeq ($(ENDIAN),little)
CFLAGS += -DTARGET_RT_LITTLE_ENDIAN=1
CXXFLAGS += -DTARGET_RT_LITTLE_ENDIAN=1
else
CFLAGS += -DTARGET_RT_BIG_ENDIAN=1
CXXFLAGS += -DTARGET_RT_BIG_ENDIAN=1
endif

PROG = alacconvert

Sources = \
EndianPortable.c \
ALACBitUtilities.c \
ALACDecoder.cpp \
ALACEncoder.cpp \
ag_dec.c \
ag_enc.c \
dp_dec.c \
dp_enc.c \
matrix_dec.c \
matrix_enc.c \
main.cpp \
CAFFileALAC.cpp \

STDIN_FILENAME = $(PROJ_SRC_DIR)/tune.wav
RUN_OPTIONS=- -

include $(LEVEL)/Multisource/Makefile.multisrc
