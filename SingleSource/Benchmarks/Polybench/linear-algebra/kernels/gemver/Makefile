LEVEL = ../../../../../..

POLYBENCH_UTILS = SingleSource/Benchmarks/Polybench/utilities 
PROG          = gemver
CFLAGS        += -I $(PROJ_SRC_ROOT)/$(POLYBENCH_UTILS) -DPOLYBENCH_DUMP_ARRAYS -DFP_ABSTOLERANCE=1e-5 -ffp-contract=off -DFMA_DISABLED=1
CXXFLAGS      += -ffp-contract=off -DFMA_DISABLED=1

HASH_PROGRAM_OUTPUT = 1

ifeq ($(ARCH),XCore)
XCORE_TARGET_NEEDS_MEMORY := 128
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc

