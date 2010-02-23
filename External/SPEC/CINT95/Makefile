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
include $(LEVEL)/Makefile.config

ifeq ($(ARCH),x86_64)
PARALLEL_DIRS := $(filter-out 126.gcc, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out 147.vortex, $(PARALLEL_DIRS))
endif

# Include the standard makefiles
include ${LEVEL}/External/Makefile.external

