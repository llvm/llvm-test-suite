LEVEL = ../../..

PROG     = nbench
CPPFLAGS = -DBASE_ITERATIONS=25
LDFLAGS  =

include	../../Makefile.multisrc

ifeq ($(ARCH),XCore)
# XCore takes ~1 hour.
RUNTIMELIMIT:=7200
else
# This test can take more than the default 500s timeout at -O0.
RUNTIMELIMIT:=750
endif

# Always copy NNET.DAT so it's available with SRCDIR != OBJDIR builds.
# FIXME: Hack
$(shell cp -n $(PROJ_SRC_DIR)/NNET.DAT .)
