LEVEL = ../../../..

PROG = archie
include $(LEVEL)/MultiSource/Makefile.multisrc

ifeq ($(OS),SunOS)
LDFLAGS += -lsocket -lnsl
endif
