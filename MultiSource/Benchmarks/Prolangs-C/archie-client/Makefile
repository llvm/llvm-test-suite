LEVEL = ../../../..

include $(LEVEL)/Makefile.config

CXXFLAGS += -Wno-implicit-function-declaration
CFLAGS += -Wno-implicit-function-declaration

# This test uses the deprecated re_comp functions.
ifdef HAVE_RE_COMP
PROG = archie
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

ifeq ($(TARGET_OS),SunOS)
LDFLAGS += -lsocket -lnsl
endif
