# This directory contains testcases that use the TestRunner script to check to 
# see if they succeed.

LEVEL = ../../../..
DISABLE_DIFFS = 1

include $(LEVEL)/test/Programs/SingleSource/Makefile.singlesrc

LIBS += -lsupc++
LDFLAGS += -lm

LLI_RUN  := $(addsuffix .run-lli, $(PREFIXED_PROGRAMS_TO_TEST))
JIT_RUN  := $(addsuffix .run-jit, $(PREFIXED_PROGRAMS_TO_TEST))
LLC_RUN  := $(addsuffix .run-llc, $(PREFIXED_PROGRAMS_TO_TEST))
CBE_RUN  := $(addsuffix .run-cbe, $(PREFIXED_PROGRAMS_TO_TEST))
.PRECIOUS: $(LLI_RUN) $(JIT_RUN) $(LLC_RUN) $(CBE_RUN)

ifndef DISABLE_LLC_DIFFS
all:: $(LLC_RUN)
endif

ifndef DISABLE_CBE_DIFFS
all:: $(CBE_RUN)
endif

ifdef TARGET_HAS_JIT
ifndef DISABLE_JIT
all:: $(JIT_RUN)
endif
endif

ifdef ENABLE_LLI
all:: $(LLI_RUN)
endif

$(PROGRAMS_TO_TEST:%=Output/%.run-lli): \
Output/%.run-lli: Output/%.llvm.bc $(LLI)
	-$(TESTRUNR) $(SourceDir)/$(filter $*.%, $(Source)) "$(LLI) $(LLI_OPTS) $<" $@

$(PROGRAMS_TO_TEST:%=Output/%.run-jit): \
Output/%.run-jit: Output/%.llvm.bc $(LLI)
	-$(TESTRUNR) $(SourceDir)/$(filter $*.%, $(Source)) "$(LLI) $(JIT_OPTS) $<" $@

$(PROGRAMS_TO_TEST:%=Output/%.run-llc): \
Output/%.run-llc: Output/%.llc
	-$(TESTRUNR) $(SourceDir)/$(filter $*.%, $(Source)) "$< $(RUN_OPTIONS)" $@

$(PROGRAMS_TO_TEST:%=Output/%.run-cbe): \
Output/%.run-cbe: Output/%.cbe
	-$(TESTRUNR) $(SourceDir)/$(filter $*.%, $(Source)) "$< $(RUN_OPTIONS)" $@


$(PROGRAMS_TO_TEST:%=Output/%.exe-lli): \
Output/%.exe-lli: Output/%.run-lli
	-cp $< $@

$(PROGRAMS_TO_TEST:%=Output/%.exe-jit): \
Output/%.exe-jit: Output/%.run-jit
	-cp $< $@

$(PROGRAMS_TO_TEST:%=Output/%.exe-llc): \
Output/%.exe-llc: Output/%.run-llc
	-cp $< $@

$(PROGRAMS_TO_TEST:%=Output/%.exe-cbe): \
Output/%.exe-cbe: Output/%.run-cbe
	-cp $< $@
