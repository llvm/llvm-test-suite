# MultiSource/Applications Makefile:  Build all subdirectories automatically

LEVEL = ../..

include $(LEVEL)/Makefile.common

PARALLEL_DIRS  = Burg aha sgefa siod lambda-0.1.3 d spiff hbd treecc

# All platforms except Darwin should be able to handle hexxagon
ifneq ($(OS),Darwin)
PARALLEL_DIRS += hexxagon
endif

# Obsequi uses Linux-only features; need to fix that
ifeq ($(OS),Linux)
PARALLEL_DIRS += obsequi
endif

# kimwitu++ uses multi-byte chars, not available on sparc/solaris
ifneq ($(OS),SunOS)
PARALLEL_DIRS += kimwitu++
endif

include $(LEVEL)/Makefile.programs
