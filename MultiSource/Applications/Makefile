# MultiSource/Applications Makefile:  Build all subdirectories automatically

LEVEL = ../../../..

include $(LEVEL)/Makefile.config

PARALLEL_DIRS  = Burg aha sgefa siod lambda-0.1.3
ifeq ($(OS),Linux)
PARALLEL_DIRS  += d
endif

include $(LEVEL)/test/Programs/Makefile.programs
