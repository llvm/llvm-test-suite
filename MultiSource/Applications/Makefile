# MultiSource/Applications Makefile:  Build all subdirectories automatically

LEVEL = ../..

include $(LEVEL)/Makefile.config

PARALLEL_DIRS  = Burg aha sgefa siod lambda-0.1.3 d spiff hbd treecc SPASS

# Obsequi uses Linux-only features; need to fix that
ifeq ($(OS),Linux)
PARALLEL_DIRS += obsequi
endif

# kimwitu++ uses multi-byte chars, not available on sparc/solaris
ifneq ($(OS),SunOS)
PARALLEL_DIRS += kimwitu++
endif

ifeq ($(OS),SunOS)
PARALLEL_DIRS := $(filter-out SPASS, $(PARALLEL_DIRS))
endif

include $(LEVEL)/Makefile.programs
