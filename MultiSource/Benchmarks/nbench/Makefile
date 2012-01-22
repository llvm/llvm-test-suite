LEVEL = ../../..

PROG     = nbench
CPPFLAGS = -DBASE_ITERATIONS=50
LDFLAGS  =

include	../../Makefile.multisrc

# Always copy NNET.DAT so it's available with SRCDIR != OBJDIR builds.
# FIXME: Hack
$(shell cp -n $(PROJ_SRC_DIR)/NNET.DAT .)
