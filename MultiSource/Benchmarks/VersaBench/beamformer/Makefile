LEVEL = ../../../..
LDFLAGS += -lm
CFLAGS += -DFP_ABSTOLERANCE=1e-5

PROG     = beamformer
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -i 400
else 
ifdef SMALL_PROBLEM_SIZE
RUN_OPTIONS = -i 25
else
RUN_OPTIONS = -i 140
endif
endif
HASH_PROGRAM_OUTPUT = 1

include $(LEVEL)/MultiSource/Makefile.multisrc

