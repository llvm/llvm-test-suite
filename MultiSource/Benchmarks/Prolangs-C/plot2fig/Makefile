LEVEL = ../../../..
include $(LEVEL)/Makefile.config

CFLAGS += -Wno-implicit-function-declaration
CXXFLAGS += -Wno-implicit-function-declaration

# This test uses the deprecated re_comp functions.
ifdef HAVE_RE_COMP
PROG = plot2fig
endif

include $(LEVEL)/MultiSource/Makefile.multisrc

