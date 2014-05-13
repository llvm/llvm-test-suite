LEVEL = ../../../..

PROG     = InductionVariable-dbl
LDFLAGS  = -lm
CFLAGS += -std=gnu99
RUN_OPTIONS = 9100 14

ifeq ($(ARCH),XCore)
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

