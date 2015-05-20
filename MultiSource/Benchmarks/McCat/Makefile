# MultiSource/McCat Makefile:  Build all subdirectories automatically

LEVEL = ../../..
PARALLEL_DIRS  := 01-qbsort 04-bisect 08-main 12-IOtest 17-bintr 03-testtrie 05-eks 09-vor 15-trie 18-imp

ifdef BENCHMARKING_ONLY
PARALLEL_DIRS := $(filter-out 15-trie, $(PARALLEL_DIRS))
endif


include $(LEVEL)/Makefile.programs
