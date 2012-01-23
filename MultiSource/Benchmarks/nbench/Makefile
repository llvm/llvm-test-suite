LEVEL = ../../..

PROG     = nbench
CPPFLAGS = -DBASE_ITERATIONS=50
LDFLAGS  =

include	../../Makefile.multisrc

# This test can take more than the default 500s timeout at -O0.
RUNTIMELIMIT:=750

# Always copy NNET.DAT so it's available with SRCDIR != OBJDIR builds.
# FIXME: Hack
$(shell cp -n $(PROJ_SRC_DIR)/NNET.DAT .)
