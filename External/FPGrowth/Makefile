LEVEL = ../..

include $(LEVEL)/Makefile.config

PROG = fpall
SourceDir := $(FPGROWTH_ROOT)

#CFLAGS += -Wno-deprecated
#CPPFLAGS += -Wno-deprecated
LIBS += -lstdc++
LDFLAGS = -lstdc++

RUN_OPTIONS = $(FPGROWTH_ROOT)/mushroom.dat
include $(LEVEL)/MultiSource/Makefile.multisrc
