# MultiSource/Applications Makefile:  Build all subdirectories automatically

LEVEL = ../..

include $(LEVEL)/Makefile.common

PARALLEL_DIRS  = Burg aha sgefa siod lambda-0.1.3 d spiff hbd treecc
ifeq ($(OS),Linux)
PARALLEL_DIRS += kimwitu++ obsequi hexxagon
endif

include $(LEVEL)/Makefile.programs
