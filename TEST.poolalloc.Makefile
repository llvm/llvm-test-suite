##===- test/Programs/TEST.poolalloc.Makefile ---------------*- Makefile -*-===##
#
# Simple tests for pool allocation.
#
# At the moment this doesn't do anything meaningful.  In the future, this should
# do timings to see if we improve performance.
#
##===----------------------------------------------------------------------===##

# PALIB - The path to the runtime library which provides the pool allocator
# itself.
#
PALIB := $(LEVEL)/test/Libraries/Output/libpoolalloc.bc
PASRC := $(LEVEL)/test/Libraries/libdummy

# Rebuild libpoolalloc if neccesary...
$(PALIB) : $(wildcard $(PASRC)/*.c)
	cd $(PASRC); $(MAKE)

# LINKED_PROGS - All of the programs linked to libpoolalloc
LINKED_PROGS := $(PROGRAMS_TO_TEST:%=Output/%.pa.llvm.bc)

IPO_OPTS := -internalize -funcresolve -instcombine -globaldce
$(LINKED_PROGS): Output/%.pa.llvm.bc: Output/%.pa.bc $(PALIB)
	$(LLINK) $< $(PALIB) | $(LOPT) $(IPO_OPTS) > $@ 

# Pool allocation target...

PA_OPTS := -load /localhome/lattner/cvs/llvm/lib/Debug/libpoolalloc.so
$(PROGRAMS_TO_TEST:%=Output/%.pa.bc): Output/%.pa.bc: Output/%.llvm.bc
	$(LOPT) $(PA_OPTS) -poolalloc < $< > $@ || as < /dev/null > $@

$(PROGRAMS_TO_TEST:%=Output/%.$(TEST).report.txt): \
Output/%.$(TEST).report.txt: Output/%.pa.llvm.bc
	echo "good" > $@

test.$(TEST).%: Output/%.$(TEST).report.txt
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$*' Program"
	@echo "---------------------------------------------------------------"
	@cat $<

#.PRECIOUS: Output/%.out-pa Output/%.diff-pa
#Output/%.out-pa: Output/%.llc
#	-$< > $@ 2>&1

#Output/%.diff-pa: Output/%.out-pa Output/%.out-llc
#	@echo "DIFFING pool allocated vs nonpoolallocated output:"
#	diff $< $(<:%-pa=%-llc)
#	@touch $@

#test.poolalloc.%: Output/%.poolalloc32.diff-pa Output/%.poolalloc32.llc \
#                  Output/%.poolalloc16.llc     Output/%.poolalloc32nle.llc \
#                  Output/%.poolalloc16nle.llc  Output/%.native32
#	$(TIMEPROG) 'Normal LLC build...' Output/$*.llc
#	$(TIMEPROG) '32 bit pool alloc NLE...' Output/$*.poolalloc32nle.llc
#	$(TIMEPROG) '32 bit pool allocation...' Output/$*.poolalloc32.llc
#	$(TIMEPROG) '16 bit pool alloc NLE...' Output/$*.poolalloc16nle.llc
#	$(TIMEPROG) '16 bit pool allocation...' Output/$*.poolalloc16.llc
#
#	$(TIMEPROG) 'Native Sun CC 64...' Output/$*.native
#	$(TIMEPROG) 'Native Sun CC 32...' Output/$*.native32
