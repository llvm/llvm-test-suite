LEVEL = ../../../..

include $(LEVEL)/Makefile.config

PROG = povray

SourceDir = $(POVRAY_ROOT)/source

CPPFLAGS += -I$(POVRAY_ROOT)/source/unix -I$(BUILD_SRC_ROOT)/runtime/libpng -DPREFIX=\"$(BUILD_OBJ_DIR)\" -DSYSCONFDIR=\"$(POVRAY_ROOT)\" -DPOV_LIB_DIR=\"$(BUILD_OBJ_DIR)/lib\" -IOutput/src -UHAVE_LIBVGA
LIBS += -lz -lpng
LDFLAGS += -L$(BUILD_OBJ_ROOT)/lib/$(CONFIGURATION) -lz -lpng

RUN_OPTIONS = -I$(POVRAY_ROOT)/scenes/advanced/chess2.pov -L$(POVRAY_ROOT)/include -GA$<.junk -O-
include ../../MultiSource/Makefile.multisrc
