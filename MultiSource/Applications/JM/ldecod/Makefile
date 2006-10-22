LEVEL = ../../../..
PROG     = ldecod
CPPFLAGS = -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64
LDFLAGS  = -lm $(TOOLLINKOPTS)
FP_TOLERANCE = 0.2

RUN_OPTIONS = -i $(PROJ_SRC_DIR)/data/test.264 -o $(PROJ_SRC_DIR)/data/test_dec.yuv -r $(PROJ_SRC_DIR)/data/test_rec.yuv

include ../../../Makefile.multisrc
