LEVEL = ../../../..
PROG     = ldecod
CPPFLAGS = -D __USE_LARGEFILE64 -D _FILE_OFFSET_BITS=64
LDFLAGS  = -lm $(TOOLLINKOPTS)

RUN_OPTIONS = -i data/test.264 -o data/test_dec.yuv -r data/test_rec.yuv

include ../../../Makefile.multisrc
