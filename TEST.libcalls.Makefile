##===- TEST.aa.Makefile ------------------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, computing the precision of various
# alias analysis passes on the programs.
#
##===----------------------------------------------------------------------===##

TDIR:=$(patsubst $(PROJ_OBJ_ROOT)/%,%,$(shell pwd))
$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "======= $(TDIR)/$*' Program"
	@cat $<

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt):  \
Output/%.$(TEST).report.txt: Output/%.linked.rbc $(LOPT)
	-$(LOPT) -simplify-libcalls -stats -debug-only=simplify-libcalls \
	         -disable-output $< 2>$@ 
list-calls:
	@$(MAKE) TEST=libcalls | egrep '======|simplify-libcalls -'

.PHONY: list-calls
REPORT_DEPENDENCIES := $(LOPT)
