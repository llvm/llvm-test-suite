LEVEL = ../../../..

PROG     = consumer-lame
CPPFLAGS = -DHAVEMPGLIB -DLAMEPARSE -DNDEBUG -D__NO_MATH_INLINES -O -DLAMESNDFILE
LDFLAGS  = -lm
RUN_OPTIONS = -S large.wav $(PROJ_SRC_DIR)/output_large.mp3
include $(LEVEL)/MultiSource/Makefile.multisrc
