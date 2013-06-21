# MultiSource Makefile:  Build all subdirectories automatically

LEVEL = ..
PARALLEL_DIRS  := Applications Benchmarks
# For now only Mips uses UnitTests
ifeq ($(ARCH),Mips)
PARALLEL_DIRS += UnitTests
endif

include $(LEVEL)/Makefile.programs

