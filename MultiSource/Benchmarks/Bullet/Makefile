LEVEL = ../../../
PROG = bullet
CPPFLAGS += -I$(PROJ_SRC_DIR)/include -DNO_TIME
LDFLAGS = -lstdc++ -lm

ifeq ($(ARCH),XCore)
# Use default RUNTIMELIMIT for the XCore.
XCORE_TARGET_NEEDS_MEMORY := 64
else
# This test can take more than the default 500s timeout on Thumb1.
# It also takes longer on Mips64r6 with MSA when running under qemu.
RUNTIMELIMIT:=1500
endif

include $(LEVEL)/Makefile.config

include ../../Makefile.multisrc
