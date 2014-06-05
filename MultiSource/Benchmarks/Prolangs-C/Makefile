LEVEL = ../../..
PARALLEL_DIRS  := TimberWolfMC agrep allroots archie-client assembler bison \
      cdecl compiler fixoutput football gnugo loader \
      plot2fig simulator unix-smail unix-tbl

# Get the $(ARCH) setting
include $(LEVEL)/Makefile.config

# Disable bison due to insane running times of bison.native
ifeq ($(ARCH), Sparc)
PARALLEL_DIRS := $(filter-out bison, $(PARALLEL_DIRS))
endif

# Disable until disk space eating bug can be fixed
ifeq ($(ARCH), Alpha)
PARALLEL_DIRS := $(filter-out bison, $(PARALLEL_DIRS))
endif

ifeq ($(ARCH),XCore)
# xcore does not support sockets or forking (popen)
PARALLEL_DIRS := $(filter-out archie-client, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out unix-smail, $(PARALLEL_DIRS))
endif

ifdef BENCHMARKING_ONLY
PARALLEL_DIRS := $(filter-out allroots, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out archie-client, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out assembler, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out compiler, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out fixoutput, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out football, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out plot2fig, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out simulator, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out TimberWolfMC, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out unix-smail, $(PARALLEL_DIRS))
PARALLEL_DIRS := $(filter-out unix-tbl, $(PARALLEL_DIRS))
endif

include $(LEVEL)/Makefile.programs
