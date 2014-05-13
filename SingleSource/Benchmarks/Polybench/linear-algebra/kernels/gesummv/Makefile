LEVEL = ../../../../../..

POLYBENCH_UTILS = SingleSource/Benchmarks/Polybench/utilities 
PROG          = gesummv
CFLAGS        += -I $(PROJ_SRC_ROOT)/$(POLYBENCH_UTILS) -DPOLYBENCH_DUMP_ARRAYS

ifdef SMALL_PROBLEM_SIZE
CFLAGS        += -DSMALL_DATASET
else
ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 256
endif
endif

HASH_PROGRAM_OUTPUT = 1

include $(LEVEL)/SingleSource/Makefile.singlesrc

