##===- TEST.dsgraph.Makefile -------------------------------*- Makefile -*-===##
#
# This recursively traverses the programs, computing DSGraphs for each of the
# programs in the testsuite.
#
##===----------------------------------------------------------------------===##

RELDIR  := $(subst $(PROJ_OBJ_ROOT),,$(PROJ_OBJ_DIR))

# We require the programs to be linked with libdummy
include $(LEVEL)/Makefile.dummylib

# PASS - The dsgraph pass to run: ds, bu, td
PASS := td

ANALYZE_OPTS := -stats -time-passes -only-print-main-ds -dsstats
ANALYZE_OPTS +=  -instcount -disable-verify
MEM := -track-memory -time-passes

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.lib.bc Output/%.LOC.txt $(LOPT)
	@# Gather data
	-($(LOPT) -analyze -$(PASS)datastructure $(ANALYZE_OPTS) $<)> $@.time.1 2>&1
	-($(LOPT) -analyze $(MEM) -$(PASS)datastructure -disable-verify $<)> $@.mem.1 2>&1
	-($(LOPT) -steens-aa -time-passes -disable-output $<) > $@.time.2 2>&1
	-($(LOPT) -steens-aa $(MEM) -disable-output $<) > $@.mem.2 2>&1
	@# Emit data.
	@echo -n "LOC: " > $@
	@cat Output/$*.LOC.txt >> $@
	@echo -n "MEMINSTS: " >> $@
	-@grep 'Number of memory instructions' $@.time.1 >> $@
	@echo -n "FOLDEDNODES: " >> $@
	-@grep 'Number of folded nodes' $@.time.1 >> $@
	@echo -n "TOTALNODES: " >> $@
	-@grep 'Graphs contain.*nodes total' $@.time.1 >> $@
	@echo -n "MAXGRAPHSIZE: " >> $@
	-@grep 'Maximum graph size' $@.time.1 >> $@
	@echo -n "GLOBALSGRAPH: " >> $@
	-@grep 'td.GlobalsGraph.dot' $@.time.1 >> $@
	@echo -n "SCCSIZE: " >> $@
	-@grep 'Maximum SCC Size in Call Graph' $@.time.1 >> $@
	@echo -n "ACCESSES TYPED: " >> $@
	-@grep 'Number of loads/stores which are fully typed' $@.time.1 >> $@
	@echo -n "ACCESSES UNTYPED: " >> $@
	-@grep 'Number of loads/stores which are untyped' $@.time.1 >> $@
	@# Emit timing data.
	@echo -n "TIME: " >> $@
	-@grep '  Local Data Structure' $@.time.1 >> $@
	@echo -n "TIME: " >> $@
	-@grep '  Bottom-up Data Structure' $@.time.1 >> $@
	@echo -n "TIME: " >> $@
	-@grep '  Top-down Data Structure' $@.time.1 >> $@
	@echo -n "TIME: " >> $@
	-@grep '  Steensgaard.s alias analysis' $@.time.2 >> $@
	@# Emit space data.
	@echo -n "MEM: " >> $@
	-@grep '  Local Data Structure' $@.mem.1 >> $@
	@echo -n "MEM: " >> $@
	-@grep '  Bottom-up Data Structure' $@.mem.1 >> $@
	@echo -n "MEM: " >> $@
	-@grep '  Top-down Data Structure' $@.mem.1 >> $@
	@echo -n "MEM: " >> $@
	-@grep '  Steensgaard.s alias analysis' $@.mem.2 >> $@



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

