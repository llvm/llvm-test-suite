LEVEL = ..

#
# Include the configuration so that we know whether or not to include SPEC
#
include $(LEVEL)/Makefile.config

#
# Create the list of directories to compile
#
PARALLEL_DIRS := SPEC Povray Namd

ifndef USE_POVRAY
PARALLEL_DIRS := $(filter-out Povray, $(PARALLEL_DIRS))
endif

ifndef USE_NAMD
PARALLEL_DIRS := $(filter-out Namd, $(PARALLEL_DIRS))
endif

# Sparc can't handle Namd: infinite loop, cause unknown
ifeq ($(ARCH),Sparc)
PARALLEL_DIRS := $(filter-out Namd, $(PARALLEL_DIRS))
endif

include Makefile.external
