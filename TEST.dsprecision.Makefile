##===- TEST.dsprecision.Makefile ---------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, running -aa-eval on them with various
# different aa implementations.
#
##===----------------------------------------------------------------------===##

RELDIR  := $(subst $(PROJ_OBJ_ROOT),,$(PROJ_OBJ_DIR))

# We require the programs to be linked with libdummy
include $(LEVEL)/Makefile.dummylib

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.lib.bc $(LOPT)
	@echo > $@
	-($(LOPT) -basicaa -aa-eval -disable-output $<) > Output/$*.basicaa.out 2>&1
	@echo -n "BASIC MA: " >> $@
	-@grep 'may alias responses' Output/$*.basicaa.out >> $@
	@echo -n "BASIC MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.basicaa.out >> $@
	@
	-($(LOPT) -steens-aa -disable-ds-field-sensitivity -aa-eval \
                           -disable-output $<) > Output/$*.steensfiaa.out 2>&1
	@echo -n "STEENS-FI MA: " >> $@
	-@grep 'may alias responses' Output/$*.steensfiaa.out >> $@
	@echo -n "STEENS-FI MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.steensfiaa.out >> $@
	@
	-($(LOPT) -steens-aa -aa-eval -disable-output $<) > Output/$*.steensfsaa.out 2>&1
	@echo -n "STEENS-FS MA: " >> $@
	-@grep 'may alias responses' Output/$*.steensfsaa.out >> $@
	@echo -n "STEENS-FS MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.steensfsaa.out >> $@
	-($(LOPT) -ds-aa -aa-eval -disable-output $<) > Output/$*.dsaa.out 2>&1
	@echo -n "DS MA: " >> $@
	-@grep 'may alias responses' Output/$*.dsaa.out >> $@
	@echo -n "DS MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.dsaa.out >> $@

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$(RELDIR)/$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

# Define REPORT_DEPENDENCIES so that the report is regenerated if analyze or
# dummylib is updated.
#
REPORT_DEPENDENCIES := $(DUMMYLIB) $(LOPT)

