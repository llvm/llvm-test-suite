##===- Makefile.spec ---------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building SPEC as an external test.
#
##===----------------------------------------------------------------------===##

include $(LEVEL)/Makefile.config

# RUN_TYPE - Either ref, test, or train.  May be specified on the command line.
ifdef LARGE_PROBLEM_SIZE
RUN_TYPE  := train
else
RUN_TYPE  := test
endif

## Information the test should have provided...
ifndef STDOUT_FILENAME
STDOUT_FILENAME := standard.out
endif
ifndef LDFLAGS
LDFLAGS = -lm
endif

# Get the current directory, the name of the benchmark, and the current
# subdirectory of the SPEC directory we are in (ie, CINT2000/164.gzip)
#
CURRENT_DIR := $(shell cd .; pwd)
BENCH_NAME  := $(subst $(shell cd ..   ; pwd),,$(CURRENT_DIR))
SPEC_SUBDIR := $(subst $(shell cd ../..; pwd),,$(CURRENT_DIR))

# Remove any leading /'s from the paths
BENCH_NAME  := $(patsubst /%,%,$(BENCH_NAME))
SPEC_SUBDIR := $(patsubst /%,%,$(SPEC_SUBDIR))

SPEC_BENCH_DIR := $(SPEC_ROOT)/$(SPEC_SUBDIR)

PROG := $(BENCH_NAME)
ifndef Source
Source := $(wildcard $(SPEC_BENCH_DIR)/src/*.c $(SPEC_BENCH_DIR)/src/*.cc)
endif

# Disable the default Output/%.out-* targets...
PROGRAMS_HAVE_CUSTOM_RUN_RULES := 1
SourceDir := $(SPEC_BENCH_DIR)/src/

include $(LEVEL)/test/Programs/MultiSource/Makefile.multisrc

# Do not pass -Wall to compile commands...
LCCFLAGS  := -O2
LCXXFLAGS := -O2

CPPFLAGS += -DSPEC_CPU2000 -I $(SPEC_BENCH_DIR)/src/
SPEC_SANDBOX := $(LLVM_SRC_ROOT)/test/Programs/External/SPEC/Sandbox.sh

# Information about testing the program...
REF_IN_DIR  := $(SPEC_BENCH_DIR)/data/$(RUN_TYPE)/input/
REF_OUT_DIR := $(SPEC_BENCH_DIR)/data/$(RUN_TYPE)/output/
LOCAL_OUTPUTS := $(notdir $(wildcard $(REF_OUT_DIR)/*))


# Specify how to generate output from the SPEC programs.  Basically we just run
# the program in a sandbox (a special directory we create), then we cat all of
# the outputs together.

$(PROGRAMS_TO_TEST:%=Output/%.out-nat): \
Output/%.out-nat: Output/%.native
	$(SPEC_SANDBOX) nat-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/nat-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/nat-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-lli): \
Output/%.out-lli: Output/%.llvm.bc $(LLI)
	$(SPEC_SANDBOX) lli-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  $(LLI) $(LLI_OPTS) ../../$< $(RUN_OPTIONS)
	-(cd Output/lli-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/lli-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-jit): \
Output/%.out-jit: Output/%.llvm.bc $(LLI)
	$(SPEC_SANDBOX) jit-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  $(LLI) $(JIT_OPTS) ../../$< $(RUN_OPTIONS)
	-(cd Output/jit-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/jit-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-llc): \
Output/%.out-llc: Output/%.llc
	$(SPEC_SANDBOX) llc-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/llc-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/llc-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-cbe): \
Output/%.out-cbe: Output/%.cbe
	$(SPEC_SANDBOX) cbe-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/cbe-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/cbe-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.trace-out-llc): \
Output/%.trace-out-llc: Output/%.trace.llc
	$(SPEC_SANDBOX) llc-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/llc-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/llc-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.trace-out-cbe): \
Output/%.trace-out-cbe: Output/%.trace.cbe
	$(SPEC_SANDBOX) cbe-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/cbe-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/cbe-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-tracing): \
Output/%.out-tracing: Output/%.trace
	$(SPEC_SANDBOX) trace-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../../$< $(RUN_OPTIONS)
	-(cd Output/trace-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/trace-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.performance): \
Output/%.performance: Output/%.out-llc Output/%.out-tracing
	-$(TIMESCRIPT) $* Output/$*.out-llc.time Output/$*.out-tracing.time $@

