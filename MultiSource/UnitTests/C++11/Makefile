# MultiSource/UnitTests/C++11 Makefile:  Build all subdirectories automatically

LEVEL = ../../..

PARALLEL_DIRS := frame_layout
CPPFLAGS += -std=c++11

ifneq (,$(findstring mips16,$(MIPSARCH)))
  PARALLEL_DIRS := $(filter-out frame_layout, $(PARALLEL_DIRS))
endif

include $(LEVEL)/Makefile.config
include $(LEVEL)/Makefile.programs
