LEVEL = ../../../
PROG = bullet
CPPFLAGS += -I$(PROJ_SRC_DIR)/include -DNO_TIME
LDFLAGS = -lstdc++ -lm

ifeq ($(ARCH),XCore)
# Use default RUNTIMELIMIT for the XCore.
XCORE_TARGET_NEEDS_MEMORY := 64
else
# This test can take more than the default 500s timeout on Thumb1
RUNTIMELIMIT:=1000
endif

include $(LEVEL)/Makefile.config

include ../../Makefile.multisrc
