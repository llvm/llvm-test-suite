LEVEL = ../../..

#
# Include the configuration so that we know whether or not to include SPEC
#
include ${LEVEL}/Makefile.config

#
# Create the list of directories to compile
#
DIRS := Povray SPEC

ifndef USE_POVRAY
DIRS := $(filter-out Povray/, $(DIRS))
endif

include ${LEVEL}/test/Programs/Makefile.programs
