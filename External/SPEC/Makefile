LEVEL = ../..
PARALLEL_DIRS := CFP2000 CINT2000 CINT95
include ${LEVEL}/Makefile.config

#
# Remove SPEC95 and SPEC2000 per the user's configuration
#
ifndef USE_SPEC2000
PARALLEL_DIRS := $(filter-out CFP2000/, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out CINT2000/, $(PARALLEL_DIRS))
endif

ifndef USE_SPEC95
PARALLEL_DIRS := $(filter-out CINT95/, $(PARALLEL_DIRS))
endif

include ${LEVEL}/Makefile.programs
