LEVEL = ../../../..
DIRS := CINT95 CFP2000 CINT2000
include ${LEVEL}/Makefile.config

#
# Remove SPEC95 and SPEC2000 per the user's configuration
#
ifndef USE_SPEC2000
DIRS := $(filter-out CFP2000/, $(DIRS))
DIRS := $(filter-out CINT2000/, $(DIRS))
endif

ifndef USE_SPEC95
DIRS := $(filter-out CINT95/, $(DIRS))
endif

include ${LEVEL}/test/Programs/Makefile.programs
