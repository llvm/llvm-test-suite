##===- test/Programs/TEST.dsgraph.Makefile -----------------*- Makefile -*-===##
#
# This recursively traverses the programs, computing DSGraphs for each of the
# programs in the testsuite.
#
##===----------------------------------------------------------------------===##

# PASS - The dsgraph pass to run: ds, bu, td
PASS := td

# DUMMYLIB - The path to the library of stub functions which is used to resolve
# external functions for dsanalysis.
#
DUMMYLIB := $(LEVEL)/test/Libraries/Output/libdummy.bc
DUMMYSRC := $(LEVEL)/test/Libraries/libdummy

# Rebuild dummylib if neccesary...
$(DUMMYLIB) : $(wildcard $(DUMMYSRC)/*.c)
	cd $(DUMMYSRC); $(MAKE)

# LINKED_PROGS - All of the programs linked to libdummy
LINKED_PROGS := $(PROGRAMS_TO_TEST:%=Output/%.lib.bc)

IPO_OPTS := -internalize -funcresolve -globaldce 
$(LINKED_PROGS): Output/%.lib.bc: Output/%.llvm.bc $(DUMMYLIB)
	$(LLINK) $< $(DUMMYLIB) | $(LOPT) $(IPO_OPTS) > $@ 

ANALYZE_OPTS := -stats -time-passes -only-print-main-ds -dsstats -instcount

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.lib.bc $(LANALYZE)
	-(time -p $(LANALYZE) -$(PASS)datastructure $(ANALYZE_OPTS) $<)> $@ 2>&1

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

# Define REPORT_DEPENDENCIES so that the report is regenerated if analyze or
# dummylib is updated.
#
REPORT_DEPENDENCIES := $(DUMMYLIB) $(LANALYZE)
