LEVEL = ../../../..

PROG     = telecomm-CRC32
LDFLAGS  = -lm
RUN_OPTIONS = $(PROJ_SRC_DIR)/large.pcm

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = telecomm-CRC32
endif
endif

include $(LEVEL)/MultiSource/Makefile.multisrc
