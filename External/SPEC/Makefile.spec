##===- Makefile.spec ---------------------------------------*- Makefile -*-===##
#
# This makefile is a template for building SPEC as an external
# test. It is included by Makefile.spec2000 and Makefile.spec95.
#
##===----------------------------------------------------------------------===##

include $(LEVEL)/Makefile.config

## Information the test should have provided...
ifndef STDOUT_FILENAME
STDOUT_FILENAME := standard.out
endif
LDFLAGS += -lm

# Get the current directory, the name of the benchmark, and the current
# subdirectory of the SPEC directory we are in (ie, CINT2000/164.gzip)
#
CURRENT_DIR := $(shell cd .; pwd)
BENCH_NAME  := $(subst $(shell cd ..   ; pwd),,$(CURRENT_DIR))
SPEC_SUBDIR := $(subst $(shell cd ../..; pwd),,$(CURRENT_DIR))

# Remove any leading /'s from the paths
BENCH_NAME  := $(patsubst /%,%,$(BENCH_NAME))
SPEC_SUBDIR := $(patsubst /%,%,$(SPEC_SUBDIR))

ifndef SPEC_BENCH_DIR
SPEC_BENCH_DIR := $(SPEC_ROOT)/$(SPEC_SUBDIR)
endif

PROG := $(BENCH_NAME)
ifndef Source
Source := $(wildcard $(SPEC_BENCH_DIR)/src/*.c $(SPEC_BENCH_DIR)/src/*.cc)
Source += $(wildcard $(SPEC_BENCH_DIR)/src/*.f)
endif

# Disable the default Output/%.out-* targets...
PROGRAMS_HAVE_CUSTOM_RUN_RULES := 1
SourceDir := $(SPEC_BENCH_DIR)/src/

include $(LEVEL)/MultiSource/Makefile.multisrc

# Do not pass -Wall to compile commands...
LCCFLAGS  := -O3
LCXXFLAGS := -O3

CPPFLAGS += -I $(SPEC_BENCH_DIR)/src/
SPEC_SANDBOX := $(PROGDIR)/External/SPEC/Sandbox.sh

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
                  ../$*.native $(RUN_OPTIONS)
	-(cd Output/nat-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/nat-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-lli): \
Output/%.out-lli: Output/%.llvm.bc $(LLI)
	$(SPEC_SANDBOX) lli-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  $(LLI) $(LLI_OPTS) ../$*.llvm.bc $(RUN_OPTIONS)
	-(cd Output/lli-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/lli-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-jit): \
Output/%.out-jit: Output/%.llvm.bc $(LLI)
	$(SPEC_SANDBOX) jit-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  $(LLI) $(JIT_OPTS) ../$*.llvm.bc $(RUN_OPTIONS)
	-(cd Output/jit-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/jit-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-jit-beta): \
Output/%.out-jit-beta: Output/%.llvm.bc $(LLI)
	$(SPEC_SANDBOX) jit-beta-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  $(LLI) -regalloc=iterativescan $(JIT_OPTS) ../$*.llvm.bc $(RUN_OPTIONS)
	-(cd Output/jit-beta-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/jit-beta-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-llc): \
Output/%.out-llc: Output/%.llc
	$(SPEC_SANDBOX) llc-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../$*.llc $(RUN_OPTIONS)
	-(cd Output/llc-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/llc-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-llc-beta): \
Output/%.out-llc-beta: Output/%.llc-beta
	$(SPEC_SANDBOX) llc-beta-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../$*.llc-beta $(RUN_OPTIONS)
	-(cd Output/llc-beta-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/llc-beta-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

$(PROGRAMS_TO_TEST:%=Output/%.out-cbe): \
Output/%.out-cbe: Output/%.cbe
	$(SPEC_SANDBOX) cbe-$(RUN_TYPE) $@ $(REF_IN_DIR) \
             $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) \
                  ../$*.cbe $(RUN_OPTIONS)
	-(cd Output/cbe-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > $@
	-cp Output/cbe-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time

# Specify stdin, reference output, and command line options for the program...
BUGPOINT_OPTIONS += -input=$(STDIN_FILENAME) -output=../$*.out-nat
BUGPOINT_OPTIONS += -timeout=$(RUNTIMELIMIT)
BUGPOINT_OPTIONS += --tool-args $(LLCFLAGS)
BUGPOINT_ARGS += --args -- $(RUN_OPTIONS)

# Rules to bugpoint the GCCAS, GCCLD, LLC, or LLI commands...
$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-gccas): \
Output/%.bugpoint-gccas: Output/%.noopt-llvm.bc $(LBUGPOINT) \
                         Output/gccas-pass-args Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.noopt-llvm.bc `cat Output/gccas-pass-args` $(OPTPASSES) \
	    $(BUGPOINT_OPTIONS) $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"

$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-gccld): \
Output/%.bugpoint-gccld: Output/%.nogccldopt-llvm.bc $(LBUGPOINT) \
                         Output/gccld-pass-args Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.nogccldopt-llvm.bc `cat Output/gccld-pass-args` $(OPTPASSES) \
	    $(BUGPOINT_OPTIONS) $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"

$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-llc): \
Output/%.bugpoint-llc: Output/%.llvm.bc $(LBUGPOINT) Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.llvm.bc -run-llc $(BUGPOINT_OPTIONS) $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"

$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-llc-beta): \
Output/%.bugpoint-llc-beta: Output/%.llvm.bc $(LBUGPOINT) Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.llvm.bc -run-llc $(BUGPOINT_OPTIONS) \
	    -regalloc=iterativescan $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"

$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-jit): \
Output/%.bugpoint-jit: Output/%.llvm.bc $(LBUGPOINT) Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.llvm.bc -run-jit $(BUGPOINT_OPTIONS) $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"

$(PROGRAMS_TO_TEST:%=Output/%.bugpoint-jit-beta): \
Output/%.bugpoint-jit-beta: Output/%.llvm.bc $(LBUGPOINT) Output/%.out-nat
	$(SPEC_SANDBOX) bugpoint-$(RUN_TYPE) $@ $(REF_IN_DIR) \
	    $(LBUGPOINT) ../$*.llvm.bc -run-jit $(BUGPOINT_OPTIONS) \
	    -regalloc=iterativescan $(BUGPOINT_ARGS)
	@echo "===> Leaving Output/bugpoint-$(RUN_TYPE)"



LIBPROFILESO = $(LLVM_OBJ_ROOT)/Debug/lib/libprofile_rt.so

$(PROGRAMS_TO_TEST:%=Output/%.prof): \
Output/%.prof: Output/%.llvm-prof.bc Output/%.out-nat $(LIBPROFILESO)
	@rm -f $@
	$(SPEC_SANDBOX) profile-$(RUN_TYPE) Output/$*.out-prof $(REF_IN_DIR) \
	  $(RUNSAFELY) $(STDIN_FILENAME) $(STDOUT_FILENAME) $(LLI) $(JIT_OPTS)\
            -fake-argv0 '../$*.llvm.bc' -load $(LIBPROFILESO) ../../$< -llvmprof-output ../../$@ $(RUN_OPTIONS)
	-(cd Output/profile-$(RUN_TYPE); cat $(LOCAL_OUTPUTS)) > Output/$*.out-prof
	-cp Output/profile-$(RUN_TYPE)/$(STDOUT_FILENAME).time $@.time
	-cp Output/profile-$(RUN_TYPE)/llvmprof.out $@
	@cmp -s Output/$*.out-prof Output/$*.out-nat || \
		printf "***\n***\n*** WARNING: Output of profiled program (Output/$*.out-prof)\n*** doesn't match the output of the native program (Output/$*.out-nat)!\n***\n***\n";
