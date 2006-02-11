LEVEL = ../../../..
PROG     = lencod
CPPFLAGS = -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64
LDFLAGS  = -lm $(TOOLLINKOPTS)

RUN_OPTIONS = -d $(PROJ_SRC_DIR)/data/encoder.cfg -p InputFile=$(PROJ_SRC_DIR)/data/foreman_part_qcif.yuv

include ../../../Makefile.multisrc
