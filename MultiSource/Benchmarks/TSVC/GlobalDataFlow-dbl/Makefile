LEVEL = ../../../..

PROG     = GlobalDataFlow-dbl
LDFLAGS  = -lm
CFLAGS += -std=gnu99
RUN_OPTIONS = 3450 14

ifeq ($(ARCH),XCore)
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

