##===- test/Programs/TEST.nightly.Makefile -----------------*- Makefile -*-===##
#
# This test is used in conjunction with the llvm/utils/NightlyTest* stuff to
# generate information about program status for the nightly report.
#
##===----------------------------------------------------------------------===##

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(shell cd $(LEVEL)/test/Programs; pwd)/
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))

REPORTS_TO_GEN := compile llc cbe jit
REPORTS_SUFFIX := $(addsuffix .report.txt, $(REPORTS_TO_GEN))

TIMEOPT = -time-passes -stats -info-output-file=$@.info
EXTRA_LLI_OPTS = $(TIMEOPT)

INFO_PREFIX = Output/$*.*-

# Compilation tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.compile.report.txt): \
Output/%.nightly.compile.report.txt: Output/%.llvm.bc $(LGCCAS)
	@echo '$(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) > $@ 2>&1'
	@if ($(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) > $@ 2>&1)\
	;then \
	  echo "TEST-PASS: compile $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep "Number of bytecode bytes written" $@.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-compile: " >> $@;\
	  grep 'Number of instructions$$' $@.info >> $@;\
	  echo >> $@;\
	else \
	  echo "TEST-FAIL: compile $(RELDIR)/$*" >> $@;\
	fi
	-rm -f $@.info

# LLC tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.llc.report.txt): \
Output/%.nightly.llc.report.txt: Output/%.llvm.bc $(LLC)
	@echo 'time -p $(LLC) -f $(TIMEOPT) $< -o /dev/null) > $@ 2>&1'
	@if (time -p $(LLC) -f $(TIMEOPT) $< -o /dev/null) > $@ 2>&1; then \
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
	-rm -f $@.info

# CBE tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.cbe.report.txt): \
Output/%.nightly.cbe.report.txt: Output/%.llvm.bc Output/%.exe-cbe $(LDIS)
	-head -n 100 Output/$*.exe-cbe > $@
	@if test -f Output/$*.exe-cbe; then \
	  echo "TEST-PASS: cbe $(RELDIR)/$*" >> $@;\
          echo "TEST-RESULT-cbe: YES" >> $@;\
	  echo -n "TEST-RESULT-cbe-time: " >> $@;\
	  grep "^real" $(INFO_PREFIX)cbe.time >> $@;\
	  echo >> $@;\
        else  \
	  echo "TEST-FAIL: cbe $(RELDIR)/$*" >> $@;\
        fi

# JIT tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.jit.report.txt): \
Output/%.nightly.jit.report.txt: Output/%.llvm.bc Output/%.exe-jit $(LLI)
	-head -n 100 Output/$*.exe-jit > $@
	@if test -f Output/$*.exe-jit; then \
          echo "TEST-PASS: jit $(RELDIR)/$*" >> $@;\
	  echo -n "TEST-RESULT-jit-time: " >> $@;\
	  grep "^real" $(INFO_PREFIX)jit.time >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-comptime: " >> $@;\
	  grep "Total Execution Time" $(INFO_PREFIX)jit.info >> $@;\
	  echo >> $@;\
	  echo -n "TEST-RESULT-jit-machcode: " >> $@;\
	  grep "bytes of machine code compiled" $(INFO_PREFIX)jit.info >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: jit $(RELDIR)/$*" >> $@;\
	fi
	-rm -f $(INFO_PREFIX)jit.info

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
