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

TIMEOPT = -time-passes -stats -info-output-file=$@.info

# Compilation tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.compile.report.txt): \
Output/%.nightly.compile.report.txt: Output/%.llvm.bc $(LGCCAS)
	@echo '$(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) > $@ 2>&1'
	-if ($(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) > $@ 2>&1)\
	;then \
	  echo "TEST-PASS: compile $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep "Number of bytecode bytes written" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep "Number of instructions" $@.info >> $@;\
	  echo >> $@;\
	else \
	  echo "TEST-FAIL: compile $(RELDIR)/$*" >> $@;\
	fi
	-@rm -f $@.info

# LLC tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.llc.report.txt): \
Output/%.nightly.llc.report.txt: Output/%.llvm.bc $(LLC)
	@echo 'time -p $(LLC) -f $(TIMEOPT) $< -o /dev/null) > $@ 2>&1'
	@-if (time -p $(LLC) -f $(TIMEOPT) $< -o /dev/null) > $@ 2>&1; then \
	  echo "TEST-PASS: llc $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-llc: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-llc: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: llc $(RELDIR)/$*" >> $@;\
	fi
	-@rm -f $@.info

# CBE tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.cbe.report.txt): \
Output/%.nightly.cbe.report.txt: Output/%.llvm.bc $(LDIS)
	-($(MAKE) TIME_RUN=1 Output/$*.diff-cbe) 2>&1 | head -n 100 > $@
	@if test -f Output/$*.diff-cbe; then \
          echo "TEST-RESULT-cbe: YES" >> $@;\
	  echo -n "TEST-RESULT-cbe-time: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
        else  \
	  echo "TEST-FAIL: cbe $(RELDIR)/$*" >> $@;\
        fi


# LLI tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.lli.report.txt): \
Output/%.nightly.lli.report.txt: Output/%.llvm.bc $(LLI)
	-($(MAKE) EXTRA_LLI_OPTS='$(TIMEOPT)' TIME_RUN=1 Output/$*.diff-lli) 2>&1 | head -n 100 > $@
	@if test -e Output/$*.diff-lli; then \
          echo "TEST-PASS: lli $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-lli-time: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-lli-dyninst: " >> $@;\
	  grep "Number of dynamic inst" $@.info >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: lli $(RELDIR)/$*" >> $@;\
	fi
	-@rm -f $@.info

# JIT tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.jit.report.txt): \
Output/%.nightly.jit.report.txt: Output/%.llvm.bc $(LLI)
	-($(MAKE) EXTRA_LLI_OPTS='$(TIMEOPT)' TIME_RUN=1 Output/$*.diff-jit) 2>&1 | head -n 100 > $@
	@if test -f Output/$*.diff-jit; then \
          echo "TEST-PASS: jit $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-jit-time: " >> $@;\
	  grep "^real" $@ >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-comptime: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-machcode: " >> $@;\
	  grep "bytes of machine code compiled" $@.info >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: jit $(RELDIR)/$*" >> $@;\
	fi
	-@rm -f $@.info

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
