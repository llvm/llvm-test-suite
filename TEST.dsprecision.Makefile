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
	@echo >> $@
	@echo -n "BASIC NOMR: " >> $@
	-@grep 'no mod/ref responses' Output/$*.basicaa.out >> $@
	@echo >> $@
	@echo -n "BASIC JUSTREF: " >> $@
	-@grep '[0-9] ref responses' Output/$*.basicaa.out >> $@
	@echo >> $@
	@echo -n "BASIC JUSTMOD: " >> $@
	-@grep 'mod responses' Output/$*.basicaa.out >> $@
	@echo >> $@
	@echo -n "BASIC MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.basicaa.out >> $@
	@echo >> $@
	@
	-($(LOPT) -steens-aa -disable-ds-field-sensitivity -aa-eval \
                           -disable-output $<) > Output/$*.steensfiaa.out 2>&1
	@echo -n "STEENS-FI MA: " >> $@
	-@grep 'may alias responses' Output/$*.steensfiaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FI NOMR: " >> $@
	-@grep 'no mod/ref responses' Output/$*.steensfiaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FI JUSTREF: " >> $@
	-@grep '[0-9] ref responses' Output/$*.steensfiaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FI JUSTMOD: " >> $@
	-@grep 'mod responses' Output/$*.steensfiaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FI MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.steensfiaa.out >> $@
	@echo >> $@
	@
	-($(LOPT) -steens-aa -aa-eval -disable-output $<) > Output/$*.steensfsaa.out 2>&1
	@echo -n "STEENS-FS MA: " >> $@
	-@grep 'may alias responses' Output/$*.steensfsaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FS NOMR: " >> $@
	-@grep 'no mod/ref responses' Output/$*.steensfsaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FS JUSTREF: " >> $@
	-@grep '[0-9] ref responses' Output/$*.steensfsaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FS JUSTMOD: " >> $@
	-@grep 'mod responses' Output/$*.steensfsaa.out >> $@
	@echo >> $@
	@echo -n "STEENS-FS MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.steensfsaa.out >> $@
	@echo >> $@
	@
	-($(LOPT) -anders-aa -aa-eval -disable-output $<) > Output/$*.andersaa.out 2>&1
	@echo -n "ANDERS MA: " >> $@
	-@grep 'may alias responses' Output/$*.andersaa.out >> $@
	@echo >> $@
	@echo -n "ANDERS NOMR: " >> $@
	-@grep 'no mod/ref responses' Output/$*.andersaa.out >> $@
	@echo >> $@
	@echo -n "ANDERS JUSTREF: " >> $@
	-@grep '[0-9] ref responses' Output/$*.andersaa.out >> $@
	@echo >> $@
	@echo -n "ANDERS JUSTMOD: " >> $@
	-@grep 'mod responses' Output/$*.andersaa.out >> $@
	@echo >> $@
	@echo -n "ANDERS MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.andersaa.out >> $@
	@echo >> $@
	@
	-($(LOPT) -ds-aa -aa-eval -disable-output $<) > Output/$*.dsaa.out 2>&1
	@echo -n "DS MA: " >> $@
	-@grep 'may alias responses' Output/$*.dsaa.out >> $@
	@echo >> $@
	@echo -n "DS NOMR: " >> $@
	-@grep 'no mod/ref responses' Output/$*.dsaa.out >> $@
	@echo >> $@
	@echo -n "DS JUSTREF: " >> $@
	-@grep '[0-9] ref responses' Output/$*.dsaa.out >> $@
	@echo >> $@
	@echo -n "DS JUSTMOD: " >> $@
	-@grep 'mod responses' Output/$*.dsaa.out >> $@
	@echo >> $@
	@echo -n "DS MR: " >> $@
	-@grep 'mod & ref responses' Output/$*.dsaa.out >> $@
	@echo >> $@

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

