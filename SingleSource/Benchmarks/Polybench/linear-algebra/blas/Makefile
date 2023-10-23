# SingleSource/Polybench/linear-algebra
# Makefile:  Build all subdirectories automatically

LEVEL = ../../../../..
PARALLEL_DIRS = gemm gemver gesummv symm syr2k syrk trmm

ifdef BENCHMARKING_ONLY
PARALLEL_DIRS := $(filter-out gemm, $(PARALLEL_DIRS))
endif

include $(LEVEL)/Makefile.config
include $(LEVEL)/Makefile.programs

