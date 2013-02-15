LEVEL = ../../../../../..

POLYBENCH_UTILS = SingleSource/Benchmarks/Polybench/utilities 
PROG         = 3mm
CFLAGS       += -I $(PROJ_SRC_ROOT)/$(POLYBENCH_UTILS) -DPOLYBENCH_DUMP_ARRAYS

ifdef SMALL_PROBLEM_SIZE
CFLAGS        += -DSMALL_DATASET
endif

ifeq ($(ARCH),Mips)
RUNTIMELIMIT := 2000
else
RUNTIMELIMIT := 1000
endif

HASH_PROGRAM_OUTPUT = 1

include $(LEVEL)/SingleSource/Makefile.singlesrc

