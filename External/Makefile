LEVEL = ../../..

#
# Include the configuration so that we know whether or not to include SPEC
#
include ${LEVEL}/Makefile.config

#
# Create the list of directories to compile
#
DIRS := $(sort $(filter-out CVS/, $(wildcard */)))
ifndef USE_SPEC
DIRS := $(filter-out SPEC/, $(DIRS))
endif

include ${LEVEL}/test/Programs/Makefile.programs
