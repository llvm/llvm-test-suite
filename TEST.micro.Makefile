##===- test/Programs/TEST.micro.Makefile -------------------*- Makefile -*-===##
#
#
##===----------------------------------------------------------------------===##

#JIT_OPTS = -force-interpreter=false -stats -time-passes
CURDIR  := $(shell cd .; pwd)
PROGDIR := $(shell cd $(LEVEL)/test/Programs; pwd)/
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))

TIMEOPT = -time-passes -stats -info-output-file=$(CURDIR)/$@.info
EXTRA_LLI_OPTS = $(TIMEOPT)

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.llvm.bc Output/%.LOC.txt Output/%.out-nat Output/%.out-jit Output/%.llc $(LLI) $(LOPT)
	@echo -n "LOC: " > $@
	-@cat Output/$*.LOC.txt >> $@
	@echo -n "LLC SIZE: " >> $@
	-@wc -c Output/$*.llc >> $@
	@echo >> $@
	@echo -n "NAT TIME: " >> $@
	-@grep real Output/$*.out-nat.time >> $@
	@echo -n "JIT TIME: " >> $@
	-@grep real Output/$*.out-jit.time >> $@
	-@cat Output/$*.out-jit.info >> $@
	$(LOPT) -strip -stats -o /dev/null -f $< >> $@ 2>&1

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$(RELDIR)/$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

# Define REPORT_DEPENDENCIES so that the report is regenerated if lli changes
#
REPORT_DEPENDENCIES := $(LLI) $(LOPT)
