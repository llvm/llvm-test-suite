##===- test/Programs/Makefile ------------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, building them as neccesary.  This
# makefile also implements 'make report TEST=<x>'.
#
##===----------------------------------------------------------------------===##

LEVEL = ../..
PARALLEL_DIRS = SingleSource MultiSource

include ${LEVEL}/test/Makefile.tests

# Include all makefiles which define tests... These makefiles must define
# test.<testname>.%  given input from Output/%.llvm.bc
#
ifdef TEST
TestMakefile := $(wildcard $(LEVEL)/test/Programs/TEST.$(TEST).Makefile)
ifneq ($(TestMakefile),)
-include $(TestMakefile)
endif
endif

#
# Rules for building a report from 'make report TEST=<x>'
#

report.$(TEST).raw.out: $(REPORT_DEPENDENCIES)
	gmake TEST=$(TEST) 2>&1 | tee $@

report: report.$(TEST).raw.out
	./GenerateReport.pl -html TEST.$(TEST).report < $< > report.$(TEST).html
	./GenerateReport.pl TEST.$(TEST).report < $< | tee report.$(TEST).txt

clean::
	rm -f report.*.raw.out report.*.txt
