##===- TEST.nightly.Makefile ------------------------------*- Makefile -*--===##
#
# This test is used in conjunction with the llvm/utils/NightlyTest* stuff to
# generate information about program status for the nightly report.
#
##===----------------------------------------------------------------------===##

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(BUILD_SRC_ROOT)
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))
CFLAGS  := -O3

REPORTS_TO_GEN := compile nat
ifndef DISABLE_LLC
REPORTS_TO_GEN +=  llc
endif
ifndef DISABLE_JIT
REPORTS_TO_GEN +=  jit
endif
ifndef DISABLE_CBE
REPORTS_TO_GEN +=  cbe
endif
ifdef ENABLE_LLCBETA
REPORTS_TO_GEN += llc-beta
endif
REPORTS_SUFFIX := $(addsuffix .report.txt, $(REPORTS_TO_GEN))


TIMEOPT = -time-passes -stats -info-output-file=$(CURDIR)/$@.info
EXTRA_LLI_OPTS = $(TIMEOPT)

# Compilation tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.compile.report.txt): \
Output/%.nightly.compile.report.txt: Output/%.llvm.bc $(LGCCAS)
	@echo > $@
	@echo '$(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) >>$@ 2>&1'
	@-if ($(LGCCAS) Output/$*.linked.rll -o /dev/null $(TIMEOPT) >>$@ 2>&1)\
	;then \
	  echo "TEST-PASS: compile $(RELDIR)/$*" >> $@;\
	  printf "TEST-RESULT-compile: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  echo >> $@;\
	  printf "TEST-RESULT-compile: " >> $@;\
	  wc -c $< >> $@;\
	  echo >> $@;\
	else \
	  echo "TEST-FAIL: compile $(RELDIR)/$*" >> $@;\
	fi

# NAT tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.nat.report.txt): \
Output/%.nightly.nat.report.txt: Output/%.out-nat
	@echo > $@
	printf "TEST-RESULT-nat-time: " >> $@
	-grep "^program" Output/$*.out-nat.time >> $@

# LLC tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.llc.report.txt): \
Output/%.nightly.llc.report.txt: Output/%.llvm.bc Output/%.exe-llc $(LLC)
	@echo > $@
	-head -n 100 Output/$*.exe-llc >> $@
	@-if test -f Output/$*.exe-llc; then \
	  echo "TEST-PASS: llc $(RELDIR)/$*" >> $@;\
	  $(LLC) $< -o /dev/null -f $(TIMEOPT) >> $@ 2>&1; \
	  printf "TEST-RESULT-llc: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  printf "TEST-RESULT-llc-time: " >> $@;\
	  grep "^program" Output/$*.out-llc.time >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: llc $(RELDIR)/$*" >> $@;\
	fi

# LLC experimental tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.llc-beta.report.txt): \
Output/%.nightly.llc-beta.report.txt: Output/%.llvm.bc Output/%.exe-llc-beta $(LLC)
	@echo > $@
	-head -n 100 Output/$*.exe-llc-beta >> $@
	@-if test -f Output/$*.exe-llc-beta; then \
	  echo "TEST-PASS: llc-beta $(RELDIR)/$*" >> $@;\
	  $(LLC) $< -o /dev/null -f $(TIMEOPT) >> $@ 2>&1; \
	  printf "TEST-RESULT-llc-beta: " >> $@;\
	  grep "Total Execution Time" $@.info >> $@;\
	  printf "TEST-RESULT-llc-beta-time: " >> $@;\
	  grep "^program" Output/$*.out-llc-beta.time >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: llc-beta $(RELDIR)/$*" >> $@;\
	fi



# CBE tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.cbe.report.txt): \
Output/%.nightly.cbe.report.txt: Output/%.llvm.bc Output/%.exe-cbe $(LDIS)
	@echo > $@
	-head -n 100 Output/$*.exe-cbe >> $@
	@-if test -f Output/$*.exe-cbe; then \
	  echo "TEST-PASS: cbe $(RELDIR)/$*" >> $@;\
	  printf "TEST-RESULT-cbe-time: " >> $@;\
	  grep "^program" Output/$*.out-cbe.time >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: cbe $(RELDIR)/$*" >> $@;\
	fi

# JIT tests
$(PROGRAMS_TO_TEST:%=Output/%.nightly.jit.report.txt): \
Output/%.nightly.jit.report.txt: Output/%.llvm.bc Output/%.exe-jit $(LLI)
	@echo > $@
	-head -n 100 Output/$*.exe-jit >> $@
	@-if test -f Output/$*.exe-jit; then \
	  echo "TEST-PASS: jit $(RELDIR)/$*" >> $@;\
	  printf "TEST-RESULT-jit-time: " >> $@;\
	  grep "^program" Output/$*.out-jit.time >> $@;\
	  echo >> $@;\
	  printf "TEST-RESULT-jit-comptime: " >> $@;\
	  grep "Total Execution Time" Output/$*.out-jit.info >> $@;\
	  echo >> $@;\
	  printf "TEST-RESULT-jit-machcode: " >> $@;\
	  grep "bytes of machine code compiled" Output/$*.out-jit.info >> $@;\
	  echo >> $@;\
	else  \
	  echo "TEST-FAIL: jit $(RELDIR)/$*" >> $@;\
	fi

# Overall tests: just run subordinate tests
$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: $(addprefix Output/%.nightly., $(REPORTS_SUFFIX))
	-cat $(addprefix Output/$*.nightly., $(REPORTS_SUFFIX)) > $@



$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$(RELDIR)/$*' Program"
	@echo "---------------------------------------------------------------"
	@-cat $<

REPORT_DEPENDENCIES := $(LDIS) $(LLI) $(LLC)
