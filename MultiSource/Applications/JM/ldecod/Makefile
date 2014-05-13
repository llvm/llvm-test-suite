LEVEL = ../../../..
PROG     = ldecod
CPPFLAGS = -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64
LDFLAGS  = -lm $(TOOLLINKOPTS)

RUN_OPTIONS = -i $(PROJ_SRC_DIR)/data/test.264 -o Output/test_dec.yuv -r $(PROJ_SRC_DIR)/data/test_rec.yuv

ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 64
endif

include ../../../Makefile.multisrc

clean::
	rm -f dataDec.txt log.dec
