LEVEL = ../../../..

PROG = dixie
#STDIN_FILENAME = $(SourceDir)/testset
include $(LEVEL)/MultiSource/Makefile.multisrc
ifeq ($(OS),SunOS)
LDFLAGS+=-lsocket -lnsl
endif

