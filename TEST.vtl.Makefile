##===- test/Programs/TEST.example.Makefile -----------------*- Makefile -*-===##
#
# Example to show a custom test.  This test just prints the size of the bytecode
# file for each program.
#
##===----------------------------------------------------------------------===##

TESTNAME = $*

VTL := /opt/intel/vtune/bin/vtl

#
# Events: These will need to be modified for every different CPU that is used
# (i.e. the Pentium 3 on Cypher has a different set of available events than
# the Pentium 4 on Zion).
#
P4_EVENTS := "-ec en='2nd Level Cache Read Misses' en='2nd-Level Cache Read References'"
P3_EVENTS := "-ec en='L2 Cache Request Misses (highly correlated)'"

EVENTS := $(P3_EVENTS)

#
# Generate events for LLC
#
#$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
#test.$(TEST).%: Output/%.llc
	#@echo "========================================="
	#@echo "Running '$(TEST)' test on '$(TESTNAME)' program"
	#$(VERB) $(VTL) activity $* -d 50 -c sampling -o $(EVENTS) -app $<
	#-$(VERB) $(VTL) run $*
	#-$(VERB) $(VTL) view > $@
	#$(VERB)  $(VTL) delete $* -f

#
# Generate events for CBE
#
$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.cbe
	@echo "========================================="
	@echo "Running '$(TEST)' test on '$(TESTNAME)' program"
	$(VERB) $(VTL) activity $* -d 50 -c sampling -o $(EVENTS) -app $<
	-$(VERB) $(VTL) run $*
	-$(VERB) $(VTL) view > $@
	$(VERB)  $(VTL) delete $* -f


