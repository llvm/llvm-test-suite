LEVEL = ../../../..
PROG     = lencod
CPPFLAGS = -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64
LDFLAGS  = -lm $(TOOLLINKOPTS)
FP_TOLERANCE = 0.025

RUN_OPTIONS = -d $(PROJ_SRC_DIR)/data/encoder.cfg -p InputFile=$(PROJ_SRC_DIR)/data/foreman_part_qcif_444.yuv -p LeakyBucketRateFile=$(PROJ_SRC_DIR)/data/leakybucketrate.cfg -p QmatrixFile=$(PROJ_SRC_DIR)/data/q_matrix.cfg

include ../../../Makefile.multisrc
