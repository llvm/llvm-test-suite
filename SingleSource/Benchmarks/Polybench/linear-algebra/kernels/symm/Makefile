LEVEL = ../../../../../..

POLYBENCH_UTILS = SingleSource/Benchmarks/Polybench/utilities 
PROG          = symm
CFLAGS        += -I $(PROJ_SRC_ROOT)/$(POLYBENCH_UTILS) -DPOLYBENCH_DUMP_ARRAYS

ifeq ($(ARCH),Mips)
RUNTIMELIMIT := 2000
endif

ifdef SMALL_PROBLEM_SIZE
CFLAGS        += -DSMALL_DATASET
endif

HASH_PROGRAM_OUTPUT = 1

include $(LEVEL)/SingleSource/Makefile.singlesrc

