LEVEL = ..

#
# Include the configuration so that we know whether or not to include SPEC
#
include $(LEVEL)/Makefile.common

#
# Create the list of directories to compile
#
PARALLEL_DIRS := SPEC Povray 

ifndef USE_POVRAY
PARALLEL_DIRS := $(filter-out Povray/, $(PARALLEL_DIRS))
endif
