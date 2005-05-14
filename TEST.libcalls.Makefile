##===- TEST.libcalls.Makefile -------------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, and runs the -simplify-libcalls pass
# on each *.linked.rbc bytecode file with -stats set so that it is possible to
# determine which libcalls are being optimized in which programs.
# 
# Usage: 
#     make TEST=libcalls summary (short summary)
#     make TEST=libcalls (detailed list with time passes, etc.)
#
##===----------------------------------------------------------------------===##

TDIR:=$(patsubst $(PROJ_OBJ_ROOT)/%,%,$(shell pwd))
$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "======= $(TDIR)/$*' Program"
	@cat $<

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt):  \
Output/%.$(TEST).report.txt: Output/%.linked.rbc $(LOPT) \
	$(PROJ_SRC_ROOT)/TEST.libcalls.Makefile 
	@-$(LOPT) -simplify-libcalls -stats -debug-only=simplify-libcalls \
	         -time-passes -disable-output $< 2>$@ 
summary:
	@$(MAKE) TEST=libcalls | egrep '======|simplify-libcalls -'

.PHONY: summary
REPORT_DEPENDENCIES := $(LOPT)
