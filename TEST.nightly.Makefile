##===- test/Programs/TEST.nightly.Makefile -----------------*- Makefile -*-===##
#
# This test is used in conjunction with the llvm/utils/NightlyTest* stuff to
# generate information about program status for the nightly report.
#
##===----------------------------------------------------------------------===##

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(shell cd $(LEVEL)/test/Programs; pwd)/
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))

REPORTS_TO_GEN := compile llc cbe lli jit
REPORTS_SUFFIX := $(addsuffix .report.txt, $(REPORTS_TO_GEN))

TIMEOPT  := -time-passes -stats

# Compilation tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.compile.report.txt): \
Output/%.nightly.compile.report.txt: Output/%.llvm.bc $(LGCCAS)
	@echo "<a name='$(RELDIR)/$*:compile'>" > $@
	-$(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) >> $@ 2>&1
	@echo -n "TEST-RESULT-compile: " >> $@
	@-grep "Total Execution Time" $@ >> $@
	@echo >> $@
	@echo -n "TEST-RESULT-compile: " >> $@
	@-grep "Number of bytecode bytes written" $@ >> $@
	@echo >> $@
	@echo -n "TEST-RESULT-compile: " >> $@
	@-grep "Number of instructions" $@ >> $@
	@echo >> $@

# LLC tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.llc.report.txt): \
Output/%.nightly.llc.report.txt: Output/%.llvm.bc $(LLC)
	-(time -p $(LLC) -f $(TIMEOPT) Output/$*.llvm.bc -o /dev/null) > $@ 2>&1
	@echo -n "TEST-RESULT-llc: " >> $@
	@-grep "Total Execution Time" $@ >> $@
	@echo >> $@
	@echo -n "TEST-RESULT-llc: " >> $@
	@-grep "^real" $@ >> $@
	@echo >> $@

# CBE tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.cbe.report.txt): \
Output/%.nightly.cbe.report.txt: Output/%.llvm.bc $(LDIS)
	-(gmake Output/$*.cbe) > $@ 2>&1
	@if test -f Output/$*.cbe; then echo "TEST-RESULT-cbe: YES" >> $@; fi\

# LLI tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.lli.report.txt): \
Output/%.nightly.lli.report.txt: Output/%.llvm.bc Output/%.diff-lli $(LLI)
	@echo > $@  # Make sure something ends up in the file...
	@if test -e Output/$*.diff-lli; then \
	  ($(ULIMIT); time -p $(LLI) -stats $(LLI_OPTS) $< $(RUN_OPTIONS)) >$@ 2>&1;\
          echo "TEST-RESULT-lli-diffmatch: YES" >> $@;\
	  echo -n "TEST-RESULT-lli-time: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-lli-dyninst: " >> $@;\
	  grep "Number of dynamic inst" $@ >> $@;\
	  echo >> $@;\
	fi

# JIT tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.jit.report.txt): \
Output/%.nightly.jit.report.txt: Output/%.llvm.bc Output/%.diff-jit $(LLI)
	@echo > $@  # Make sure something ends up in the file...
	@if test -e Output/$*.diff-jit; then \
	  ($(ULIMIT); time -p $(LLI) $(JIT_OPTS) $(TIMEOPT) $< $(RUN_OPTIONS)) > $@ 2>&1;\
          echo "TEST-RESULT-jit-diffmatch: YES" >> $@;\
	  echo -n "TEST-RESULT-jit-time: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-comptime: " >> $@;\
	  grep "Total Execution Time" $@ >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-machcode: " >> $@;\
	  grep "bytes of machine code compiled" $@ >> $@;\
	  echo >> $@;\
	fi

# Overall tests: just run subordinate tests
$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: $(addprefix Output/%.nightly., $(REPORTS_SUFFIX))
	cat $(addprefix Output/$*.nightly., $(REPORTS_SUFFIX)) > $@



$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$(RELDIR)/$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

REPORT_DEPENDENCIES := $(LDIS) $(LLI) $(LLC)
