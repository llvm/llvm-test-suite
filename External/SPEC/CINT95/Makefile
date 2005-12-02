LEVEL = ../../..
PARALLEL_DIRS := \
  099.go \
  124.m88ksim \
  126.gcc \
  129.compress \
  130.li \
  132.ijpeg \
  134.perl \
  147.vortex

# Get the $(ARCH) setting
include ${LEVEL}/Makefile.config

ifeq ($(ARCH), Alpha)
PARALLEL_DIRS := $(filter-out 134.perl, $(PARALLEL_DIRS))
endif

# Include the standard makefiles
include ${LEVEL}/External/Makefile.external

