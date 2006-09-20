LEVEL = ../..

include $(LEVEL)/Makefile.config

PROG = hmmcalibrate
SourceDir := $(HMMER_ROOT)

CPPFLAGS = -DSSE2

ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = --fixed 400 --cpu 1 --num 200000 $(HMMER_ROOT)/globin.hmm
else
RUN_OPTIONS = --fixed 400 --cpu 1 --num 80000 $(HMMER_ROOT)/globin.hmm
endif

include $(LEVEL)/MultiSource/Makefile.multisrc
