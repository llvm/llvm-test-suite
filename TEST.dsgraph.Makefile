##===- test/Programs/TEST.dsgraph.Makefile -----------------*- Makefile -*-===##
#
# This recursively traverses the programs, computing DSGraphs for each of the
# programs in the testsuite.
#
##===----------------------------------------------------------------------===##

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(shell cd $(LEVEL)/test/Programs; pwd)/
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))

# We require the programs to be linked with libdummy
include $(LEVEL)/test/Programs/Makefile.dummylib

# PASS - The dsgraph pass to run: ds, bu, td
PASS := td

ANALYZE_OPTS := -stats -time-passes -only-print-main-ds -dsstats -instcount

MEM := -track-memory

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.lib.bc Output/%.LOC.txt $(LANALYZE) $(LOPT)
	@echo -n "LOC: " > $@
	@cat Output/$*.LOC.txt >> $@
	-(time -p $(LANALYZE) $(MEM) -$(PASS)datastructure $(ANALYZE_OPTS) $<)>> $@ 2>&1
	-($(LOPT) -steens-aa $(MEM) -time-passes > /dev/null < $<) >> $@ 2>&1

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$(RELDIR)/$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

# Define REPORT_DEPENDENCIES so that the report is regenerated if analyze or
# dummylib is updated.
#
REPORT_DEPENDENCIES := $(DUMMYLIB) $(LANALYZE) $(LOPT)

