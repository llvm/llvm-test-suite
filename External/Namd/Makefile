LEVEL = ../..

include $(LEVEL)/Makefile.config

PROG = spec_namd
SourceDir := $(NAMD_ROOT)

CFLAGS += -Wno-deprecated
CPPFLAGS += -Wno-deprecated
LIBS += -lm -lstdc++
LDFLAGS = -lm -lstdc++

RUN_OPTIONS = --iterations 5 --input $(NAMD_ROOT)/apoa1.input
include $(LEVEL)/MultiSource/Makefile.multisrc
